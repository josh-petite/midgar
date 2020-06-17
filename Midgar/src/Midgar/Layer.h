#pragma once

#include "Midgar/Core.h"
#include "Midgar/Events/Event.h"

namespace Midgar
{
	class MIDGAR_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return debugName; }
	private:
		std::string debugName;
	};
}