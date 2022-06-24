#include <gst/gst.h>
#include <SubtitlesParserFactory.h>
#include "SubtitleParserUtils.h"
#include <gst/subtitle/subtitle.h>

namespace SubtitleParser
{
	static const size_t defaultTrackId = 0;

	class Parser
	{
	public:		
		clc_Result Parse(const clc::String& doc, timedText::SubtitlesFormat format, bool isDisplayOnlyForced = false);

		std::vector<GstBuffer*> getSubtitleList() { return sceneHandler->getScenesBuffersList(); }

	private:
		timedText::SubtitlesPool pool;
		std::unique_ptr<SubtitleParserUtils::SceneHandler> sceneHandler;
	};
};