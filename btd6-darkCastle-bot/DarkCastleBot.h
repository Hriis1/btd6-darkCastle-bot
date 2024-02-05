#pragma once

#include <iostream>
#include <chrono>
#include <thread>

#include "InputHandler.h"
#include "ScreenHandler.h"


class DaskCastleBot
{
public:
	DaskCastleBot()
		: _inputHandler(), _screenHandler()
	{

	}

	void playEasyDeflation()
	{
		//Open the minimised btd 6
		if (!mouseToImageOnScreen("Images/btd_6_minimised_icon.png", 1.5f))
		{
			std::cout << "Could not find btd6 minimised icon!" << std::endl;
			return;
		}
		_inputHandler.pressMouseLeft();


		//Main loop
		bool farmFlag = true;
		while (farmFlag)
		{
			//Wit for 0.5 secs
			waitForMiliSeconds(500);

			//Open the maps
			if (!mouseToImageOnScreen("Images/btd6_main_loby_play_button.png", 1.5f))
			{
				std::cout << "Could not find btd6_main_loby_play_button icon!" << std::endl;
				continue;
			}
			_inputHandler.pressMouseLeft();

			//Stop farming
			farmFlag = false;
		}

		//_inputHandler.pressMouseLeft();

		//waitForMiliSeconds(5000);
	}

	void playEasyStandart()
	{
		//Open the minimised btd 6
		if (!mouseToImageOnScreen("Images/btd_6_minimised_icon.png", 1.5f))
		{
			std::cout << "Could not find btd6 minimised icon!" << std::endl;
			return;
		}
		_inputHandler.pressMouseLeft();


		//Main loop
		bool farmFlag = true;
		while (farmFlag)
		{
			//Wit for 0.5 secs
			waitForMiliSeconds(500);

			//Open the maps
			if (!mouseToImageOnScreen("Images/btd6_main_loby_play_button.png", 1.5f))
			{
				std::cout << "Could not find btd6_main_loby_play_button icon!" << std::endl;
				continue;
			}
			_inputHandler.pressMouseLeft();

			//Stop farming
			farmFlag = false;
		}
		
		//_inputHandler.pressMouseLeft();

		//waitForMiliSeconds(5000);
	}

private:
	bool mouseToImageOnScreen(const std::string& path, float screenScaling)
	{
		cv::Point currImgCoords = _screenHandler.findImageInScreen(path, screenScaling);

		if (currImgCoords.x >= 0)
		{
			_inputHandler.moveMouse(currImgCoords.x, currImgCoords.y, screenScaling);
			return true;
		}

		return false;

	}

	void waitForMiliSeconds(int miliSeconds)
	{
		std::chrono::milliseconds duration(miliSeconds);

		// Make the program sleep for the specified duration
		std::cout << "Waiting for " << miliSeconds << " milliseconds..." << std::endl;
		std::this_thread::sleep_for(duration);
		std::cout << "Finished waiting!" << std::endl;
	}

private:
	InputHandler _inputHandler;
	ScreenHandler _screenHandler;
};