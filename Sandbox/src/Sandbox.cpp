#include "mgpch.h"
#include <Midgar.h>

#include "imgui/imgui.h"

class ExampleLayer : public Midgar::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		//MG_INFO("ExampleLayer::Update");
		if (Midgar::Input::IsKeyPressed(MG_KEY_TAB))
			MG_INFO("Key tab pressed");
	}

	virtual void OnImGuiRender() override
	{
		// this is broken for some reason, won't compile -- linker errors.
		// need to investigate more
		/*static bool open = true;
		ImGui::Begin("in example", &open, ImGuiWindowFlags_ChildWindow);
		ImGui::Text("Hello World!");
		ImGui::End();*/
	}

	void OnEvent(Midgar::Event& event) override
	{
		//MG_TRACE("{0}", event);
	}
};

class Sandbox : public Midgar::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());		
	}

	~Sandbox()
	{
	}
};

Midgar::Application* Midgar::CreateApplication()
{
	MG_INFO("Sandbox starting...");
	return new Sandbox();
}