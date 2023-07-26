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
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}