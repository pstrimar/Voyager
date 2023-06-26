#pragma once

#include "Core.h"

namespace Voyager {

	class VOYAGER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

