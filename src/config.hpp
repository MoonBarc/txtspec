#include <string>
#include "helpers.hpp"
using namespace std;

/*
    Central configuration file for
     txtspec.
    Modify carefully!
*/

string LINE = "";

namespace Config
{
    /**
     * Config values
     */
    const string PAGE_INDICATOR = "[ page % ]";
    const int LINE_LENGTH = 36;
    const char TITLE_CHAR = '-';
    const int PAGE_LENGTH = 24;
    const bool PAGE_PADDING = true;

    /**
     * Utility functions
     */
    void createLines() {
        for (int i = 0; i < LINE_LENGTH; i++)
        {
            LINE.append("-");
        };
        LINE.append("\n");
    }

    string generatePageIndicator(int page) {
        string generated = PAGE_INDICATOR;
        replace(generated, "%", to_string(page));
        generated.append("");
        return generated;
    }

    string getLine() {
        return LINE;
    }

    string getPadding(bool doubleNewline) {
        string ifPadding = "";
        if(doubleNewline) {
            ifPadding = "\n";
        }
        if(PAGE_PADDING) {
            ifPadding.append("\n");
        }
        return ifPadding;
    }
}
