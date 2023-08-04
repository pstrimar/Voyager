#pragma once

#include "Voyager/Core/Core.h"
#include "Voyager/Core/Application.h"

#ifdef VGR_PLATFORM_WINDOWS

extern Voyager::Application* Voyager::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Voyager::Log::Init();

	VGR_PROFILE_BEGIN_SESSION("Startup", "VoyagerProfile-Startup.json");
	auto app = Voyager::CreateApplication({ argc, argv });
	VGR_PROFILE_END_SESSION();

	VGR_PROFILE_BEGIN_SESSION("Runtime", "VoyagerProfile-Runtime.json");
	app->Run();
	VGR_PROFILE_END_SESSION();

	VGR_PROFILE_BEGIN_SESSION("Shutdown", "VoyagerProfile-Shutdown.json");
	delete app;
	VGR_PROFILE_END_SESSION();
}

#endif
