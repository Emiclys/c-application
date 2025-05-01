#pragma once

struct Application
{
	static String name;
	static String version;

	static bool isRunning;
	static int returnCode;

	static void Quit()
	{
		isRunning = false;
	}
};

bool Application::isRunning = true;
int Application::returnCode = 0;
