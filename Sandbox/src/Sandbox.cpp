#include "mgpch.h"
#include <Midgar.h>

class ExampleLayer : public Midgar::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		//MG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Midgar::Event& event) override
	{
		MG_TRACE("{0}", event);
	}
};

class Sandbox : public Midgar::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Midgar::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Midgar::Application* Midgar::CreateApplication()
{
	MG_INFO("Info log");
	return new Sandbox();
}