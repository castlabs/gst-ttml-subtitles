#include "SubtitleParserUtils.h"

#include <gst/gst.h>
#include <gst/subtitle/subtitle.h>

namespace SubtitleParser
{
	using timedText::SubtitlesFormat;
	static const size_t defaultTrackId = 0;
	static const std::vector<SubtitlesFormat> supportedSubtitlesTypes = { SubtitlesFormat::WebVTT , SubtitlesFormat::TTML };

	class Parser
	{
	public:		
		clc_Result Parse(const clc::String& doc, bool forcedOnly = false);

		std::vector<GstBuffer*> getSubtitles() { return sceneHandler->getSceneBuffers(); }

	private:
		timedText::SubtitlesPool pool;
		std::unique_ptr<SubtitleParserUtils::SceneHandler> sceneHandler;
	};
};