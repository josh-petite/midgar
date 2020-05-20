#pragma once

#include <stdio.h>

#ifdef MG_PLATFORM_WINDOWS

extern Midgar::Application* Midgar::CreateApplication();

int main(int argc, char** argv)
{
	printf("Midgar Engine\n");
	auto app = Midgar::CreateApplication();
	app->Run();
	delete app;
}

#endif