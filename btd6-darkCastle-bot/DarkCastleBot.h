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

	}

private:
	void waitForMiliSeconds(int miliSeconds)
	{

	}

private:
	InputHandler _inputHandler;
	ScreenHandler _screenHandler;
};