#include <iostream>
#include <windows.h>
#include <string>

using namespace std;
const int MAX_HEIGHT=20;
const int MIN_HEIGHT=0;
const unsigned int REDRAW_SPEED = 100;
const char TITLE[] = {"Drawing sample"};
const string SYMBOL = "   ";
const string MOVING_TEXT = "Hello world!";
//global variables
bool moveDown = true;
int position = 0;

void draw(){
    string textPrefix="";
    for(int i = 0; i < position; i++){
        cout << endl;
        textPrefix += SYMBOL;
    }

    if(position == MAX_HEIGHT){
        moveDown = false;
    } else if(position == MIN_HEIGHT){
        moveDown = true;
    }
    if(moveDown){
        position++;
    } else {
        position--;
    }

    cout << textPrefix << MOVING_TEXT << endl;
}

void redrawSpeed(){
    Sleep(REDRAW_SPEED);
}

void clearScreen(){
    system("cls");
}


int main()
{
    SetConsoleTitle( TEXT(TITLE));
    while(true){
        draw();
        redrawSpeed();
        clearScreen();
    }

    return 0;
}
