#include <Windows.h>
#include <string>

#include "InputHandler.h"
#include "ScreenHandler.h"

int main() {

    InputHandler inputHandler;
    ScreenHandler screenHandler;

    cv::Point imageCenterCoords = screenHandler.findImageInScreen("Images/test1.png", 1.5f);

    if(imageCenterCoords.x >= 0)
        inputHandler.moveMouse(imageCenterCoords.x, imageCenterCoords.y);
   

    return 0;
}
