#include "mgpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Midgar
{
	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		for (auto it = layerStack.end(); it != layerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.IsHandled())
				break;
		}
	}

	void Application::Run()
	{
		while (isRunning)
		{
			glClearColor(0.5, 0.5, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : layerStack)
				layer->OnUpdate();

			window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		layerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		layerStack.PushOverlay(overlay);
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		isRunning = false;
		return true;
	}
}