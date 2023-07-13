#pragma once

#ifdef VGR_PLATFORM_WINDOWS

extern Voyager::Application* Voyager::CreateApplication();

int main(int argc, char** argv)
{
	Voyager::Log::Init();
	VGR_CORE_WARN("Initialized Log!");

	auto app = Voyager::CreateApplication();
	app->Run();
	delete app;
}

#endif
