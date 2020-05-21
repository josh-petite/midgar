#pragma once

#ifdef MG_PLATFORM_WINDOWS

extern Midgar::Application* Midgar::CreateApplication();

int main(int argc, char** argv)
{
	Midgar::Log::Init();
	MG_CORE_WARN("Initialized engine log!");
	MG_DEBUG("Initialized client log! {0}", 20);

	auto app = Midgar::CreateApplication();
	app->Run();
	delete app;
}

#endif