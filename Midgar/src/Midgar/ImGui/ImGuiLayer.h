#pragma once

#include "Midgar/Layer.h"
//#include "Midgar/Events/Event.h"
//#include "Midgar/Events/ApplicationEvent.h"
//#include "Midgar/Events/MouseEvent.h"
//#include "Midgar/Events/KeyEvent.h"

namespace Midgar
{
	class MIDGAR_API ImGuiLayer : public Layer
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
		float time = 0.0f;
	};
}