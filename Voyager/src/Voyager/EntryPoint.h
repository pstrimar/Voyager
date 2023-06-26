#pragma once

#ifdef VGR_PLATFORM_WINDOWS

extern Voyager::Application* Voyager::CreateApplication();

int main(int argc, char** argv)
{
	Voyager::Log::Init();
	VGR_CORE_WARN("Initialized Log!");
	int a = 5;
	VGR_INFO("Hello! Var={0}", a);

	auto app = Voyager::CreateApplication();
	app->Run();
	delete app;
}

#endif
