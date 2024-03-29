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
		if (!openBtd6())
		{
			return;
		}

		//Main loop
		bool farmFlag = true;
		while (farmFlag)
		{
			waitForMiliSeconds(500);

			//Open dark castle map
			if (!openDarkCastleFromMenu())
			{
				return;
			}

			//Go into deflation difficulty
			if (openDeflationDifficulty())
			{
				return;
			}
			

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

	bool openBtd6()
	{
		
		if (!mouseToImageOnScreen("Images/btd_6_minimised_icon.png", 1.5f))
		{
			std::cout << "Could not find btd6 minimised icon!" << std::endl;
			return false;
		}
		_inputHandler.pressMouseLeft();

		return true;
	}

	bool openDarkCastleFromMenu()
	{
		//Open the maps
		if (!mouseToImageOnScreen("Images/btd6_main_loby_play_button.png", 1.5f))
		{
			std::cout << "Could not find btd6_main_loby_play_button icon!" << std::endl;
			return false;
		}
		_inputHandler.pressMouseLeft();

		waitForMiliSeconds(500);

		//Go to expert category
		if (!mouseToImageOnScreen("Images/expert_section_btn.png", 1.5f))
		{
			std::cout << "Could not find expert_section_btn icon!" << std::endl;
			return false;
		}
		_inputHandler.pressMouseLeft();

		waitForMiliSeconds(500);

		//Find and click the dark castle map
		while (true)
		{
			if (mouseToImageOnScreen("Images/darkCastle_map_btn.png", 1.5f))
			{
				std::cout << "Dark castle found" << std::endl;
				_inputHandler.pressMouseLeft();
				break;
			}

			if (!mouseToImageOnScreen("Images/expert_section_btn.png", 1.5f))
			{
				std::cout << "Could not find expert_section_btn icon!" << std::endl;
				return false;
			}
			_inputHandler.pressMouseLeft();
			waitForMiliSeconds(500);
		}
		waitForMiliSeconds(500);
		

		return true;
	}

	bool openDeflationDifficulty()
	{
		if (!mouseToImageOnScreen("Images/easy_difficulty_btn.png", 1.5f))
		{
			std::cout << "Could not find easy_difficulty_btn icon!" << std::endl;
			return false;
		}
		_inputHandler.pressMouseLeft();
		waitForMiliSeconds(500);
		if (!mouseToImageOnScreen("Images/deflation_difficulty_btn.png", 1.5f))
		{
			std::cout << "Could not find deflation_difficulty_btn icon!" << std::endl;
			return false;
		}
		_inputHandler.pressMouseLeft();

		//Wait for the loading to click to remove the tip
		waitForMiliSeconds(8000);
		_inputHandler.pressMouseLeft();

		return true;
	}

private:
	InputHandler _inputHandler;
	ScreenHandler _screenHandler;
};