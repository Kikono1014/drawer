#include <iostream>
#include <fstream>
#include "Sprite.h"
using std::string;

int Sprite::getFileSize(){
    std::ifstream mySource;
    mySource.open(path, std::ios_base::binary);
    mySource.seekg(0, std::ios_base::end);
    int size = mySource.tellg();
    mySource.close();
    return size;
}

int Sprite::getMaxRowLen() {
    string row = "";
    int len = 0;
    int maxLen = 0;
    for (int i = 0; i < fileLen; i++) {
        string symbol;
        symbol = buffer[i];
        row += symbol;
        if (symbol == "\n") {
            len = row.length();
            if (len > maxLen) {
                maxLen = len;
            }
            row = "";
        }
    }
    return maxLen;
}

int Sprite::getRowAmount() {
    int counter = 0;
    for (int i = 0; i < fileLen; i++) {
        string a;
        a = buffer[i];
        if (a == "\n") {
            counter++;
        }
    }
    return counter;
}

Sprite::Sprite() {}
Sprite::Sprite (int x0, int y0, string path) {
    this->x0 = x0;
    this->y0 = y0;
    this->path = path;
    this->fileLen = getFileSize();
    this->buffer = new char[fileLen+1];
}

int    Sprite::getX0()    { return x0; }
int    Sprite::getY0()    { return y0; }
int    Sprite::getWidth() { return width; }
int    Sprite::getHeight(){ return height; }
string Sprite::getPath()  { return path; }

void Sprite::setX0  (int x0)      { this->x0 = x0; }
void Sprite::setY0  (int y0)      { this->y0 = y0; }
void Sprite::setPath(string path) { this->path = path; }
void Sprite::setWidth() { width = getMaxRowLen(); }
void Sprite::setHeight(){ height = getRowAmount(); }

string **Sprite::generateSpriteArr() {
    string **sprite = new string * [getRowAmount()];
    string row = "";

    int k = 0;
    for (int i = 0; i < fileLen; i++) {
        string symbol;
        symbol = buffer[i];

        if (symbol == "\n") {
            sprite[k] = new string [width];
            for (int j = 0; j < width; j++) {
                if (j < row.length()) {
                    sprite[k][j] = row[j];
                } else {
                    sprite[k][j] = " ";
                }
            }
            row = "";
            k++;
        } else {
            row += symbol;

        }
    }
    return sprite;
}

string **Sprite::getSprite() {
    setWidth();
    setHeight();
    std::ifstream file;
    file.open(path);
    file.read(buffer, fileLen);
    string **sprite = generateSpriteArr();
    return sprite;
}
