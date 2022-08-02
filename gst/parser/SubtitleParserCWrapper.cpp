#include "SubtitleParserCWrapper.h"
#include "SubtitleParser.h"

extern "C"
{
	CParser* parse_ttml(char* doc, bool forced_only) {
		SubtitleParser::Parser* ttmlParser = new SubtitleParser::Parser();
		if (ttmlParser->Parse(doc, timedText::SubtitlesFormat::TTML, forced_only) == CLC_FAIL) {
			return NULL;
		}
		return reinterpret_cast<CParser*>(ttmlParser);
	}

	GList* get_subtitles(CParser* c_parser) {
		SubtitleParser::Parser* parser = reinterpret_cast<SubtitleParser::Parser*>(c_parser);
		auto subtitles = parser->getSubtitles();
		GList* ret = NULL;

		for (auto subtitle : subtitles) {
			ret = g_list_append(ret, gst_buffer_ref(subtitle));
		}
		
		return ret;
	}
}