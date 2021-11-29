#include <iostream>
#include <fstream>

using namespace std;


int fileSize(const char *add){
    ifstream mySource;
    mySource.open(add, ios_base::binary);
    mySource.seekg(0,ios_base::end);
    int size = mySource.tellg();
    mySource.close();
    return size;
}

int getRowAmount(char *buffer, int fileLen) {
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

int getMaxRowLen(char *buffer, int fileLen) {
    string row = "";
    int len = 0;
    int maxLen = 0;
    for (int i = 0; i < fileLen; i++) {
        string symbol;
        symbol = buffer[i];
        row += buffer[i];
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

string **generateSpriteArr(char *buffer, int width, int fileLen) {
    string **sprite = new string * [getRowAmount(buffer, fileLen)];
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
            row += buffer[i];
        }
    }
    return sprite;
}

void show(string **sprite, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << sprite[i][j];
        }
        cout << endl;
    }
}

int main() {
    ifstream file;
    int fileLen = fileSize((char*)"./file.txt");

    char* buffer = new char[fileLen+1];

    file.open("./file.txt");
    file.read(buffer, fileLen);

    int width = getMaxRowLen(buffer, fileLen);
    int height = getRowAmount(buffer, fileLen);

    string **sprite = generateSpriteArr(buffer, width, fileLen);

    show(sprite, width, height);

    return 0;
}
