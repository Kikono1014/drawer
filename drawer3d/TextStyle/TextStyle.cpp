#include <iostream>
#include <math.h>
#include "TextStyle.h"
using std::string;
using namespace stl;

RGB::RGB () {
    this->r = 255;
    this->g = 255;
    this->b = 255;
}
RGB::RGB (unsigned char r, unsigned char g, unsigned char b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

string Text::setStyle(string text, TextStyle fgcolor, TextStyle bgcolor, TextStyle style) {
    return "\033[" + std::to_string(style) + ";" + std::to_string(fgcolor) + ";" + std::to_string(bgcolor) + "m" + text + "\033[0m";
}

string Text::setRGB(string text, RGB color, TextStyle type, TextStyle style) {
    return "\033[" + std::to_string(style) + ";" + std::to_string(type) + ";2;" + std::to_string((int)color.r) + ";" + std::to_string((int)color.g) + ";" + std::to_string((int)color.b) + "m" + text + "\033[0m";
}
