#pragma once

#ifdef MG_PLATFORM_WINDOWS

extern Midgar::Application* Midgar::CreateApplication();

int main(int argc, char** argv)
{
	Midgar::Log::Init();

	auto app = Midgar::CreateApplication();
	app->Run();
	delete app;
}

#endif