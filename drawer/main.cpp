#include "header.h"
#include "TextStyle/TextStyle.h"
#include "Drawer/Drawer.h"
#include "Drawer/Sprite.h"
#include "Frame/Frame.h"

using std::string;
using namespace stl;

double framerate = 10.0;
string frameBuffer[HEIGHT][WIDTH];
Frame frame(framerate);

int getMaxWidth(Sprite *animatedSprite, int animationFrameAmount) {
    int width = 0;
    int maxWidth = 0;

    for (int i = 0; i < animationFrameAmount; i++) {
        width = animatedSprite[i].getWidth();
        if (width > maxWidth)
            maxWidth = width;
    }
    return maxWidth;
}

Sprite *getAnimatedSprite(int x0, int y0, int animationFrameAmount, string *paths) {
    Sprite *animatedSprite = new Sprite [animationFrameAmount];
    for (int i = 0; i < animationFrameAmount; i++) {
        Sprite spriteFrame(x0, y0, paths[i]);
        animatedSprite[i] = spriteFrame;
    }
    return animatedSprite;
}

int main() {
    int width = WIDTH;
    int height = HEIGHT;
    int centerX = (int)(width / 2);
    int centerY = (int)(height / 2);
    frame.reset(width, height, frameBuffer);

    int x0 = 0;
    int y0 = 2;

    string imgPath = "./fuga/";
    string path = imgPath + "file.txt";
    Sprite sprite(x0, y0, path);

    int animationFrameCounter = 0;
    int animationFrameAmount = 6;
    string paths[animationFrameAmount] = {
                        imgPath + "file.txt",
                        imgPath + "file1.txt",
                        imgPath + "file2.txt",
                        imgPath + "file3.txt",
                        imgPath + "file4.txt",
                        imgPath + "file5.txt"
                      };

    Sprite *animatedSprite = getAnimatedSprite(x0, y0, animationFrameAmount, paths);

    Sprite spriteBody (x0, y0, imgPath + "body.txt");
    Sprite spriteMouth(x0, y0, imgPath + "mouth.txt");
    Sprite spriteEyes (x0, y0, imgPath + "eyes.txt");
    Sprite spriteWater(x0, y0, imgPath + "water.txt");

    string eaglePath = "./eagle/";
    Sprite eagle(x0, y0, eaglePath + "eagle.txt");

    Sprite eagleBody (x0, y0, eaglePath + "body.txt");
    Sprite eagleBeak (x0, y0, eaglePath + "beak.txt");
    Sprite eagleEyes1(x0, y0, eaglePath + "eyes1.txt");
    Sprite eagleEyes2(x0, y0, eaglePath + "eyes2.txt");


    while (true) {
        /* Point, Line, Rectangle, Circle */
        /*
        Drawer::SetLine(frameBuffer, Point(0, 0,       "  ", RGB(255, 0, 0), BG_RGB), Point(width-1, height-1, "  ", RGB(0, 0, 255), BG_RGB));
        Drawer::SetLine(frameBuffer, Point(width-1, 0, "  ", RGB(255, 0, 0), BG_RGB), Point(0, height-1,       "  ", RGB(0, 0, 255), BG_RGB));

        Drawer::SetLine(frameBuffer, Point(0, centerY, "  ", RGB(0, 150, 255), BG_RGB), Point(width-1, centerY, "  ", RGB(0, 150, 255), BG_RGB));
        Drawer::SetLine(frameBuffer, Point(centerX, 0, "  ", RGB(0, 150, 255), BG_RGB), Point(centerX, height-1, "  ", RGB(0, 150, 255), BG_RGB));


        Drawer::SetRectangle(frameBuffer, Point(centerX, centerY, "  ", RGB(0, 150, 255), BG_RGB), 15, 10);

        Drawer::SetPoint(frameBuffer, centerX, centerY, "  ", RGB(255, 0, 0), BG_RGB);

        Drawer::SetCircle(frameBuffer, Point(centerX, centerY, "  ", RGB(100, 255, 0), BG_RGB), height/2-1);
        */

        /* Polygon */
        /*
        Drawer::SetPolygon(frameBuffer, Point(10, 80, "  ", RGB(200, 0, 0), BG_RGB), Point(40, 10, "  ", RGB(100, 0, 0), BG_RGB), Point(90, 80, "  ", RGB(50, 0, 0), BG_RGB));

        Drawer::SetPoint(frameBuffer, 10, 80, "  ", RGB(255, 0, 0), BG_RGB);
        Drawer::SetPoint(frameBuffer, 40, 10, "  ", RGB(0, 255, 0), BG_RGB);
        Drawer::SetPoint(frameBuffer, 90, 80, "  ", RGB(0, 0, 255), BG_RGB);
        */
        /* Sprite */
        /*
        Drawer::SetSprite(
                          frameBuffer,
                          sprite.getX0(), sprite.getY0(), sprite.getWidth(), sprite.getHeight(),
                          sprite.getSprite()
                         );*/


        /* Sprite Move */
        /*
        Drawer::SetSprite(
                          frameBuffer,
                          sprite.getX0(), sprite.getY0(), sprite.getWidth(), sprite.getHeight(),
                          sprite.getSprite()
                         );
        x0++;

        if (x0 >= width-sprite.getWidth()) {
            x0 = 0;
        }
        sprite.setX0(x0);
        */
        /* Sprite animate */
        /*
        Drawer::SetSprite(
                          animatedSprite[animationFrameCounter].getX0(),
                          animatedSprite[animationFrameCounter].getY0(),
                          animatedSprite[animationFrameCounter].getWidth(),
                          animatedSprite[animationFrameCounter].getHeight(),
                          animatedSprite[animationFrameCounter].getSprite(), frameBuffer
                         );
        if (animationFrameCounter != animationFrameAmount-1) {
            animationFrameCounter++;
        } else {
            animationFrameCounter = 0;
        }
        */
        /* Sprite animate and move */
        /*
        Drawer::SetSprite(
                          animatedSprite[animationFrameCounter].getX0(),
                          animatedSprite[animationFrameCounter].getY0(),
                          animatedSprite[animationFrameCounter].getWidth(),
                          animatedSprite[animationFrameCounter].getHeight(),
                          animatedSprite[animationFrameCounter].getSprite(), frameBuffer
                         );

        if (animationFrameCounter < animationFrameAmount-1) {
            animationFrameCounter++;
        } else {
            animationFrameCounter = 0;
        }

        if (x0 < width-getMaxWidth(animatedSprite, animationFrameAmount)) {
            x0++;
        } else {
            x0 = 0;
        }
        animatedSprite[animationFrameCounter].setX0(x0);
        */

        /* Sprite Colored */
        /*
        Drawer::SetColorSprite(
                                frameBuffer,
                                sprite.getX0(), sprite.getY0(), spriteBody.getWidth(), spriteBody.getHeight(),
                                spriteBody.getSprite(), sprite.getSprite(), RGB(200, 200, 0), FG_RGB
                              );
        Drawer::SetColorSprite(
                               frameBuffer,
                               sprite.getX0(), spriteMouth.getY0(), spriteMouth.getWidth(), spriteMouth.getHeight(),
                               spriteMouth.getSprite(), sprite.getSprite(), RGB(200, 0, 0), FG_RGB
                              );
        Drawer::SetColorSprite(
                                frameBuffer,
                                sprite.getX0(), sprite.getY0(), spriteEyes.getWidth(), spriteEyes.getHeight(),
                                spriteEyes.getSprite(), sprite.getSprite(), RGB(100, 100, 100), FG_RGB
                              );
        Drawer::SetColorSprite(
                                frameBuffer,
                                sprite.getX0(), sprite.getY0(), spriteWater.getWidth(), spriteWater.getHeight(),
                                spriteWater.getSprite(), sprite.getSprite(), RGB(100, 100, 200), FG_RGB
                              );
        */

        Drawer::SetLine(frameBuffer, Point(0, 0, "  ", RGB(90, 13, 172), BG_RGB), Point(width-1, 0, "  ", RGB(90, 13, 172), BG_RGB));
        Drawer::SetLine(frameBuffer, Point(width-1, 0, "  ", RGB(90, 13, 172), BG_RGB), Point(width-1, height-1, "  ", RGB(90, 13, 172), BG_RGB));
        Drawer::SetLine(frameBuffer, Point(width-1, height-1, "  ", RGB(90, 13, 172), BG_RGB), Point(0, height-1, "  ", RGB(90, 13, 172), BG_RGB));
        Drawer::SetLine(frameBuffer, Point(0, height-1, "  ", RGB(90, 13, 172), BG_RGB), Point(0, 0, "  ", RGB(90, 13, 172), BG_RGB));

        frame.presentFrame(width, height, frameBuffer);
        frame.updateFrame(width, height, frameBuffer);
    }

    return 0;
}


