#pragma once

#ifdef VGR_PLATFORM_WINDOWS

extern Voyager::Application* Voyager::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Voyager::CreateApplication();
	app->Run();
	delete app;
}

#endif
