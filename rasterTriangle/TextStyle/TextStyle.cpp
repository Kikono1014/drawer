#include <iostream>
#include "TextStyle.h"
using std::string;
using namespace stl;
string Text::setStyle(string text, TextStyle fgcolor, TextStyle bgcolor, TextStyle style) {
    return "\033[" + std::to_string(style) + ";" + std::to_string(fgcolor) + ";" + std::to_string(bgcolor) + "m" + text + "\033[0m";
}



