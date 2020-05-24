#pragma once

#include "Core.h"

#include "Window.h"
#include "Midgar/LayerStack.h"
#include "Midgar/Events/Event.h"
#include "Midgar/Events/ApplicationEvent.h"

namespace Midgar
{
	class MIDGAR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> window;
		bool isRunning = true;
		LayerStack layerStack;
	};

	// To be defined in client
	Application* CreateApplication();
}
