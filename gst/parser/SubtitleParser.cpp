#include "SubtitleParser.h"
using namespace SubtitleParser;

clc_Result Parser::Parse(const clc::String& doc, timedText::SubtitlesFormat format, bool isDisplayOnlyForced)
{
	auto parser = timedText::SubtitlesParserFactory::createParser(format, this->pool);

	auto ret = parser->parse(doc, defaultTrackId);
	if(ret != CLC_SUCCESS)
		return CLC_FAIL;

	this->pool.setCurrentTrackIndex(defaultTrackId);
	this->sceneHandler = std::make_unique<SubtitleParserUtils::SceneHandler>(pool);
	this->sceneHandler->setDisplayOnlyForced(isDisplayOnlyForced);
	return this->sceneHandler->createScenes();
}