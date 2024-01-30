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

	void playEasyStandart()
	{
		waitForMiliSeconds(5000);
	}

private:
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