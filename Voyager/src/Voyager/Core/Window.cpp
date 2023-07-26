#include "vgrpch.h"
#include "Voyager/Core/Window.h"

#ifdef VGR_PLATFORM_WINDOWS
#include "Voyager/Platform/Windows/WindowsWindow.h"
#endif

namespace Voyager {

	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef VGR_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		VGR_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}
}