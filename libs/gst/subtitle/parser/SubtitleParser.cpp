#include "SubtitleParser.h"
using namespace SubtitleParser;

clc_Result Parser::Parse(const clc::String& doc, bool forcedOnly)
{
	//naive guess format
	clc::Result ret = CLC_NOT_INITIALIZED;
	for(const auto format : supportedSubtitlesTypes) {
		auto parser = timedText::SubtitlesParserFactory::createParser(format, this->pool);
		ret = parser->parse(doc, defaultTrackId);
		if(ret == CLC_SUCCESS) { 
			break; 
		}
		pool.restart();
	}
	
	if(ret != CLC_SUCCESS) {
		return CLC_FAIL;
	}

	this->pool.setCurrentTrackIndex(defaultTrackId);
	this->sceneHandler = std::make_unique<SubtitleParserUtils::SceneHandler>(pool);
	this->sceneHandler->setForcedOnly(forcedOnly);
	return this->sceneHandler->createScenes();
}