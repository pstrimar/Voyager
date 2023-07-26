#include <Voyager.h>
#include <Voyager/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Voyager {

	class VoyagerEditor : public Application
	{
	public:
		VoyagerEditor()
			: Application("Voyager Editor")
		{
			PushLayer(new EditorLayer());
		}

		~VoyagerEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new VoyagerEditor();
	}
}