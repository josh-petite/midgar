#pragma once

#include "Midgar/Layer.h"
#include "Midgar/Events/Event.h"
#include "Midgar/Events/ApplicationEvent.h"
#include "Midgar/Events/MouseEvent.h"
#include "Midgar/Events/KeyEvent.h"

namespace Midgar
{
	class MIDGAR_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);		
	private:
		bool OnKeyPressed(KeyPressedEvent& event);
		bool OnKeyReleased(KeyReleasedEvent& event);
		bool OnKeyTyped(KeyTypedEvent& event);
		bool OnMouseMoved(MouseMovedEvent& event);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleased(MouseButtonReleasedEvent& event);
		bool OnMouseScrolled(MouseScrolledEvent& event);
		bool OnWindowResized(WindowResizeEvent& event);

		float time = 0.0f;
	};
}