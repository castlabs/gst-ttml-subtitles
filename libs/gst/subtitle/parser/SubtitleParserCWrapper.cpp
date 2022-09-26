#include "SubtitleParserCWrapper.h"
#include "SubtitleParser.h"

extern "C"
{
	CParser* create_subs_parser() {
		SubtitleParser::Parser* ttmlParser = new SubtitleParser::Parser();
		return reinterpret_cast<CParser*>(ttmlParser);
	}

	bool parse_subs(CParser* c_parser, char* doc, bool forced_only) {
		SubtitleParser::Parser* parser = reinterpret_cast<SubtitleParser::Parser*>(c_parser);
		if (parser->Parse(doc, forced_only) == CLC_FAIL) {
			return false;
		}
		return true;
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

	void destroy_subs_parser(CParser* c_parser) {
		SubtitleParser::Parser* parser = reinterpret_cast<SubtitleParser::Parser*>(c_parser);
		delete parser;
	}
}