#pragma once

#include "Voyager/Core/Layer.h"

#include "Voyager/Events/ApplicationEvent.h"
#include "Voyager/Events/KeyEvent.h"
#include "Voyager/Events/MouseEvent.h"

namespace Voyager {

	class VOYAGER_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}