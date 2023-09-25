/*
　 　　　　,| 　 　 　 　 　.|
　　　　　 || 　 　 　 　 　||
　　　　　 || 　　 /(・) 　 ||
　　 　 　 |.|　　 | |　　　| |
　　　　　|　|　 /　|　　/| .|　　　|￣￣￣￣￣￣￣￣ |
　　　　　|　| 　| __| 　/ |　|　 ＜　Yo Wassup!    |
　　　　　| |＼/　　l_/ /| .|　　　|________________|
　 　 　　 ||＼　　　 ／ '||
　　 　　　|　/） 　 （　 　|
　　　　　　(_/　　　＼
　　　　　 （＿／＼＿）
*/

#include <stdio.h>
#include <windows.h>
#include <windef.h>
#include <winuser.h>

void swapMouseButtonClicks(){
    BOOL result;
    result = SystemParametersInfoW(SPI_SETMOUSEBUTTONSWAP, TRUE, NULL, 0);
}

void resetMouseButtonClicks(){
    BOOL result;
    result = SystemParametersInfoW(SPI_SETMOUSEBUTTONSWAP, FALSE, NULL, 0);
}

void increaseMouseSpeed(){
    BOOL result;
    int mouseSpeed;
    result = SystemParametersInfoW(SPI_GETMOUSESPEED, 0, &mouseSpeed, 0);
    
    if(mouseSpeed != 20) {
        mouseSpeed = 20;
    }

    result = SystemParametersInfoW(SPI_SETMOUSESPEED, 0, mouseSpeed, 0);
}

void resetMouseSpeed(){
    BOOL result;
    int mouseSpeed;
    result = SystemParametersInfoW(SPI_GETMOUSESPEED, 0, &mouseSpeed, 0);
    
    if(mouseSpeed != 10) {
        mouseSpeed = 10;
    }

    result = SystemParametersInfoW(SPI_SETMOUSESPEED, 0, mouseSpeed, 0);
}

void decreaseMouseSpeed(){
    BOOL result;
    int mouseSpeed;
    result = SystemParametersInfoW(SPI_GETMOUSESPEED, 0, &mouseSpeed, 0);
    
    if(mouseSpeed != 1) {
        mouseSpeed = 1;
    }

    result = SystemParametersInfoW(SPI_SETMOUSESPEED, 0, mouseSpeed, 0);
}

void mouseDirectionReversal(){
    BOOL result;
    LPPOINT point;
    result = GetCursorPos(point);
    int curXPos = point->x;
    int curYPos = point->y;
    result = SetCursorPos(curYPos, curXPos);
}

int main(int argc, char * argv []){
    
    char * functionality = argv[1];

    if(strcmp(functionality, "decrease") == 0){
        decreaseMouseSpeed();
    }

    else if(strcmp(functionality, "increase") == 0){
        increaseMouseSpeed();
    }

    else if(strcmp(functionality, "resetspeed") == 0){
        resetMouseSpeed();
    }

    else if(strcmp(functionality, "swap") == 0){
        swapMouseButtonClicks();
    }

    else if(strcmp(functionality, "resetbuttons") == 0){
        resetMouseButtonClicks();
    }

    else if(strcmp(functionality, "reverse") == 0){
        mouseDirectionReversal();
    }

    else{
        return -1;
    }


    return 0;
}