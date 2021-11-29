#include "../header.h"
#if defined _WIN32
    #include "windows.h"
#elif defined (__LINUX__) || defined (__gnu_linux__) || defined (__linux__)
    #include <unistd.h>
#endif
#include "Frame.h"

using std::string;

Frame::Frame(double framerate) {
    this->framerate = framerate;
}

double Frame::getFramerate() { return this->framerate; }

void Frame::setFramerate(double framerate) { this->framerate = framerate; }

void Frame::setFrameBuffer(int x, int y, string value, string (&frameBuffer)[HEIGHT][WIDTH]) {
    frameBuffer[y][x] = value;
}

void Frame::delay(double time) {
    #if defined _WIN32
        Sleep(time * 1000);
    #elif defined (__LINUX__) || defined (__gnu_linux__) || defined (__linux__)
        usleep(time * 1000000);
    #endif
}

void Frame::clear() {
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined (__gnu_linux__) || defined (__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

void Frame::presentFrame(int width, int height, string (&frameBuffer)[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            std::cout << frameBuffer[y][x];
        }
        std::cout << std::endl;
    }
}

void Frame::reset(int width, int height, string (&frameBuffer)[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            frameBuffer[y][x] = "  ";
        }
    }
}

void Frame::updateFrame(int width, int height, string (&frameBuffer)[HEIGHT][WIDTH]) {
    delay(1 / getFramerate());
    reset(width, height, frameBuffer);
    clear();
}
