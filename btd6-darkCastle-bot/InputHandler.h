#pragma once
#include <Windows.h>

class InputHandler
{
public:
	InputHandler() = default;

    void pressKey(char key) {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = VkKeyScanA(key); // Convert char to virtual key code
        input.ki.dwFlags = 0;  // Key press
        input.ki.time = 0;
        input.ki.dwExtraInfo = 0;

        SendInput(1, &input, sizeof(INPUT));

        // Simulate releasing the key
        input.ki.dwFlags = KEYEVENTF_KEYUP;  // Key release
        SendInput(1, &input, sizeof(INPUT));
    }

    void pressKey(int vkCode) {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = vkCode;  // Virtual key code for the Windows key
        input.ki.dwFlags = 0;  // Key press
        input.ki.time = 0;
        input.ki.dwExtraInfo = 0;

        SendInput(1, &input, sizeof(INPUT));

        // Simulate releasing the key
        input.ki.dwFlags = KEYEVENTF_KEYUP;  // Key release
        SendInput(1, &input, sizeof(INPUT));
    }

    void pressMouseLeft() {
        // Simulate a left mouse button press
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);

        // Simulate a left mouse button release
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    }

    void moveMouse(int x, int y)
    {
        SetCursorPos(x, y);
    }
private:
};