#pragma once
#include <opencv2/opencv.hpp>
#include <Windows.h>
#include <wingdi.h>
#include <string>

class ScreenHandler
{
public:
	ScreenHandler() = default;

    cv::Mat captureScreenshot(float screenScaling) {
        int screen_width = GetSystemMetrics(SM_CXSCREEN) * screenScaling;
        int screen_height = GetSystemMetrics(SM_CYSCREEN) * screenScaling;

        HDC hdcScreen = GetDC(NULL);
        HDC hdcMem = CreateCompatibleDC(hdcScreen);

        HBITMAP hBitmap = CreateCompatibleBitmap(hdcScreen, screen_width, screen_height);
        HBITMAP hBitmapOld = (HBITMAP)SelectObject(hdcMem, hBitmap);

        BitBlt(hdcMem, 0, 0, screen_width, screen_height, hdcScreen, 0, 0, SRCCOPY);

        cv::Mat screenshot(screen_height, screen_width, CV_8UC4);
        GetBitmapBits(hBitmap, screen_width * screen_height * 4, screenshot.data);

        SelectObject(hdcMem, hBitmapOld);
        DeleteObject(hBitmap);
        DeleteDC(hdcMem);
        ReleaseDC(NULL, hdcScreen);

        cvtColor(screenshot, screenshot, cv::COLOR_BGRA2BGR);

        return screenshot;
    }

    cv::Point findImageInScreen(const std::string& path, float screenScaling)
    {
        cv::Mat sourceImage = captureScreenshot(screenScaling);

        if (sourceImage.empty()) {
            return cv::Point(-1, -1);
        }

        cv::Mat templateImage = cv::imread(path);

        if (templateImage.empty()) {
            return cv::Point(-1, -1);
        }

        return findImage(sourceImage, templateImage);
    }

    cv::Point findImage(const cv::Mat& source, const cv::Mat& templateImage) {
        cv::Mat result;
        matchTemplate(source, templateImage, result, cv::TM_CCOEFF_NORMED);

        double minVal, maxVal;
        cv::Point minLoc, maxLoc;
        minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

        double threshold = 0.9;
        if (maxVal >= threshold) {
            int centerX = maxLoc.x + templateImage.cols / 2;
            int centerY = maxLoc.y + templateImage.rows / 2;

            return cv::Point(centerX, centerY);
        }
        else {
            return cv::Point(-1, -1);
        }
    }

private:

    
};