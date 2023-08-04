#include <Voyager.h>
#include <Voyager/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Voyager {

	class VoyagerEditor : public Application
	{
	public:
		VoyagerEditor(ApplicationCommandLineArgs args)
			: Application("Voyager Editor", args)
		{
			PushLayer(new EditorLayer());
		}

		~VoyagerEditor()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new VoyagerEditor(args);
	}
}