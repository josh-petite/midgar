#include "mgpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "Midgar/Application.h"

// TEMPORARY
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Midgar
{
	ImGuiLayer::ImGuiLayer() 
		: Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
		ImGui::DestroyContext();
	}

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float current = (float)glfwGetTime();
		io.DeltaTime = time > 0.0 ? (current - time) : (1.0f / 60.0f);
		time = current;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		if (!event.IsInCategory(InputEventCategory))
			return;

		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(ImGuiLayer::OnKeyPressed));
		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::OnKeyReleased));
		dispatcher.Dispatch<KeyTypedEvent>(BIND_EVENT_FN(ImGuiLayer::OnKeyTyped));
		dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressed));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleased));
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseMoved));
		dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(ImGuiLayer::OnWindowResized));
	}

	bool ImGuiLayer::OnKeyPressed(KeyPressedEvent& event)
	{
		int key = event.GetKeyCode();
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[key] = true;

		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];		
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];

		MG_CORE_INFO("{0}: Key {1} down", GetName(), key);
		return false;
	}

	bool ImGuiLayer::OnKeyReleased(KeyReleasedEvent& event)
	{
		int key = event.GetKeyCode();
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[key] = false;

		MG_CORE_INFO("{0}: Key {1} up", GetName(), key);
		return false;
	}

	bool ImGuiLayer::OnKeyTyped(KeyTypedEvent& event)
	{
		int key = event.GetKeyCode();		
		if (key > 0 && key < 0x10000)
		{
			ImGuiIO& io = ImGui::GetIO();
			io.AddInputCharacter((unsigned int)key);
		}

		MG_CORE_INFO("{0}: Key {1} typed", GetName(), key);
		return false;
	}

	bool ImGuiLayer::OnMouseButtonPressed(MouseButtonPressedEvent& event)
	{
		int button = event.GetMouseButton();
		
		ImGuiIO& io = ImGui::GetIO();		
		io.MouseDown[button] = true;

		MG_CORE_INFO("{0}: Mouse button {1} down", GetName(), button);
		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleased(MouseButtonReleasedEvent& event)
	{
		int button = event.GetMouseButton();		

		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[button] = false;

		MG_CORE_INFO("{0}: Mouse button {1} up", GetName(), button);
		return false;
	}

	bool ImGuiLayer::OnMouseMoved(MouseMovedEvent& event)
	{
		float x = event.GetX(), y = event.GetY();

		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(x, y);

		MG_CORE_INFO("{0}: Mouse position: ({1}, {2})", GetName(), x, y);
		return false;
	}

	bool ImGuiLayer::OnMouseScrolled(MouseScrolledEvent& event)
	{
		ImGuiIO& io = ImGui::GetIO();
		float xOffset = (float)event.GetXOffset();
		float yOffset = (float)event.GetYOffset();

		io.MouseWheelH += xOffset;
		io.MouseWheel += yOffset;

		MG_CORE_INFO("{0}: Mouse scrolled: ({1}, {2})", GetName(), io.MouseWheelH, io.MouseWheel);
		return false;
	}

	bool ImGuiLayer::OnWindowResized(WindowResizeEvent& event)
	{
		int w = event.GetWidth(), h = event.GetHeight();

		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(w, h);
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, w, h);

		MG_CORE_INFO("{0}: Window resized: ({1}, {2})", GetName(), w, h);
		return false;
	}
}