#include "config.h"
#include "TextStyle/TextStyle.h"
#include "Drawer/Drawer.h"
#include "Drawer/Sprite.h"
#include "Frame/Frame.h"

using std::string;
using namespace stl;

double framerate = FRAMERATE;
string frameBuffer[HEIGHT][WIDTH];
Frame frame(framerate);

int main() {
    int width = WIDTH;
    int height = HEIGHT;
    int centerX = (int)(width / 2);
    int centerY = (int)(height / 2);
    frame.reset(width, height, frameBuffer);

    int z = SCREEN_Z;

    while (true) {

        Drawer::SetCube(frameBuffer, 30, Point(50, 50, z, "  ", RGB(255, 255, 0), BG_RGB));

        /*Drawer::SetPolygon(frameBuffer, Point(50, 60, z), Point(60, 45, z), Point(70, 60, z));*/

        z++;

        Drawer::SetLine(frameBuffer, Point(0, 0, "  ", RGB(90, 13, 172), BG_RGB), Point(width-1, 0, "  ", RGB(90, 13, 172), BG_RGB));
        Drawer::SetLine(frameBuffer, Point(width-1, 0, "  ", RGB(90, 13, 172), BG_RGB), Point(width-1, height-1, "  ", RGB(90, 13, 172), BG_RGB));
        Drawer::SetLine(frameBuffer, Point(width-1, height-1, "  ", RGB(90, 13, 172), BG_RGB), Point(0, height-1, "  ", RGB(90, 13, 172), BG_RGB));
        Drawer::SetLine(frameBuffer, Point(0, height-1, "  ", RGB(90, 13, 172), BG_RGB), Point(0, 0, "  ", RGB(90, 13, 172), BG_RGB));

        frame.presentFrame(width, height, frameBuffer);
        frame.updateFrame(width, height, frameBuffer);
    }

    return 0;
}


