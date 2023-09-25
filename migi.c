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

//necessary header files
#include <stdio.h>
#include <windows.h>
#include <windef.h>
#include <winuser.h>

/*
This function will take the left and right click buttons on
the mouse and swap their functionality.  So the left button 
will no have the functionality of right clicking, and vice versa 
with the other button.
*/
void swapMouseButtonClicks(){
    BOOL result;
    result = SystemParametersInfoW(SPI_SETMOUSEBUTTONSWAP, TRUE, NULL, 0);
}

/*
This function will reset the left and right click buttons back
to their original default where the left click button conducts
the standard left click functionality and the same for the right
click.
*/
void resetMouseButtonClicks(){
    BOOL result;
    result = SystemParametersInfoW(SPI_SETMOUSEBUTTONSWAP, FALSE, NULL, 0);
}

/*
This function will set the mouse senstivity to the max level which
is represented by a numerical value of 20.
*/
void increaseMouseSpeed(){
    BOOL result;
    int mouseSpeed;
    result = SystemParametersInfoW(SPI_GETMOUSESPEED, 0, &mouseSpeed, 0);
    
    if(mouseSpeed != 20) {
        mouseSpeed = 20;
    }

    result = SystemParametersInfoW(SPI_SETMOUSESPEED, 0, mouseSpeed, 0);
}

/*
This function will set the mouse senetivity to the default value which
is represented by a numerical value of 10.
*/
void resetMouseSpeed(){
    BOOL result;
    int mouseSpeed;
    result = SystemParametersInfoW(SPI_GETMOUSESPEED, 0, &mouseSpeed, 0);
    
    if(mouseSpeed != 10) {
        mouseSpeed = 10;
    }

    result = SystemParametersInfoW(SPI_SETMOUSESPEED, 0, mouseSpeed, 0);
}

/*
This function will set the mouse sensitivity to the lowest possible value which
is represented by a numerical value of 1.
*/
void decreaseMouseSpeed(){
    BOOL result;
    int mouseSpeed;
    result = SystemParametersInfoW(SPI_GETMOUSESPEED, 0, &mouseSpeed, 0);
    
    if(mouseSpeed != 1) {
        mouseSpeed = 1;
    }

    result = SystemParametersInfoW(SPI_SETMOUSESPEED, 0, mouseSpeed, 0);
}

/*
This function will switch the x coordinate and the y coordinate of the mouse
based on the current position it is at. 
*/
void mouseDirectionReversal(){
    BOOL result;
    LPPOINT point;
    result = GetCursorPos(point);
    int curXPos = point->x;
    int curYPos = point->y;
    result = SetCursorPos(curYPos, curXPos);
}

int main(int argc, char * argv []){
    
    char * functionality = argv[1]; //command line argument

    //decrease command to decrease the mouse sensitiviity
    if(strcmp(functionality, "decrease") == 0){
        decreaseMouseSpeed();
    }

    //increase command to increase the mouse sensitivity
    else if(strcmp(functionality, "increase") == 0){
        increaseMouseSpeed();
    }

    //resetspeed command to reset the mouse senstivity to default
    else if(strcmp(functionality, "resetspeed") == 0){
        resetMouseSpeed();
    }

    //swap command to swap the two mouse buttons
    else if(strcmp(functionality, "swap") == 0){
        swapMouseButtonClicks();
    }

    //resetbuttons command to switch the two mouse buttons back to default functionality
    else if(strcmp(functionality, "resetbuttons") == 0){
        resetMouseButtonClicks();
    }

    //reverse command to switch the x and y coordinates of the mouse position to move it across the screen
    else if(strcmp(functionality, "reverse") == 0){
        mouseDirectionReversal();
    }

    else{
        return -1;
    }


    return 0;
}
