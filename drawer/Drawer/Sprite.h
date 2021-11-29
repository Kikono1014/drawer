#ifndef SPRITE
#define SPRITE
using std::string;
class Sprite {
private:
    int x0;
    int y0;
    string path;
    int fileLen;
    char* buffer;
    int width;
    int height;

    int getFileSize();

    int getMaxRowLen();

    int getRowAmount();

public:
    Sprite();
    Sprite (int x0, int y0, string path);

    int    getX0();
    int    getY0();
    int    getWidth();
    int    getHeight();
    string getPath();

    void setX0  (int x0);
    void setY0  (int y0);
    void setPath(string path);
    void setWidth();
    void setHeight();

    string **generateSpriteArr();

    string **getSprite();

};
#endif
