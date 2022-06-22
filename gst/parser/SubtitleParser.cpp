#include "SubtitleParser.h"
using namespace SubtitleParser;

clc_Result Parser::Parse(const clc::String& doc, timedText::SubtitlesFormat format, bool isDisplayOnlyForced)
{
	auto parser = timedText::SubtitlesParserFactory::createParser(format, this->pool);

	auto ret = parser->parse(doc, defaultTrackId);
	if(ret != CLC_SUCCESS)
		return CLC_FAIL;

	this->pool.setCurrentTrackIndex(defaultTrackId);
	this->scenesHandler = std::make_unique<SubtitleParserUtils::ScenesHandler>(pool);
	this->scenesHandler->setDisplayOnlyForced(isDisplayOnlyForced);
	return this->scenesHandler->createScenes();
}