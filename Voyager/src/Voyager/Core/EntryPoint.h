#pragma once

#ifdef VGR_PLATFORM_WINDOWS

extern Voyager::Application* Voyager::CreateApplication();

int main(int argc, char** argv)
{
	Voyager::Log::Init();

	VGR_PROFILE_BEGIN_SESSION("Startup", "VoyagerProfile-Startup.json");
	auto app = Voyager::CreateApplication();
	VGR_PROFILE_END_SESSION();

	VGR_PROFILE_BEGIN_SESSION("Runtime", "VoyagerProfile-Runtime.json");
	app->Run();
	VGR_PROFILE_END_SESSION();

	VGR_PROFILE_BEGIN_SESSION("Shutdown", "VoyagerProfile-Shutdown.json");
	delete app;
	VGR_PROFILE_END_SESSION();
}

#endif
