#pragma once

#include "Event.h"

namespace Midgar
{
	class MIDGAR_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return button; }

		EVENT_CLASS_CATEGORY(MouseEventCategory | InputEventCategory)
	protected:
		MouseButtonEvent(int button) : button(button) {}
		int button;
	};

	class MIDGAR_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) 
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MIDGAR_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

	class MIDGAR_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: mouseX(x), mouseY(y) {}

		inline float GetX() const { return mouseX; }
		inline float GetY() const { return mouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << "(" << mouseX << ", " << mouseY << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(MouseEventCategory | InputEventCategory)
	private:
		float mouseX;
		float mouseY;
	};

	class MIDGAR_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: xOffset(xOffset), yOffset(yOffset) {}

		inline float GetXOffset() const { return xOffset; }
		inline float GetYOffset() const { return xOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << "(" << xOffset << ", " << yOffset << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(MouseEventCategory | InputEventCategory)
	private:
		float xOffset;
		float yOffset;
	};
}