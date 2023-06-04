#include<graphics.h>
#include<windows.h>
HWND CreateImageButton(LPCSTR filePath, double xPosInch, double yPosInch, double widthInch, double heightInch, int buttonId) {
    HWND hwndButton;

    // Load the image from file path
    HBITMAP hImage = (HBITMAP)LoadImage(NULL, filePath, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

    if(hImage == NULL) {
        MessageBox(consoleWindow, "Could not load image!", "Error", MB_OK | MB_ICONEXCLAMATION);
    }

    // Create the button
    hwndButton = CreateWindow(
        "BUTTON",  // Predefined class; Unicode assumed 
        "",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_BITMAP,  // Styles 
        PixelsX(xPosInch),         // x position 
        PixelsY(yPosInch),         // y position 
        PixelsX(widthInch),        // Button width
        PixelsY(heightInch),       // Button height
        graphicsWindow,            // Parent window
        (HMENU)buttonId,           // Button ID
        (HINSTANCE)GetModuleHandle(NULL), 
        NULL);      // Pointer not needed.

    if (hwndButton == NULL) {
        MessageBox(consoleWindow, "Could not create button!", "Error", MB_OK | MB_ICONEXCLAMATION);
    }

    // Set the image on the button
    SendMessage(hwndButton, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hImage);
  
    return hwndButton;
}
