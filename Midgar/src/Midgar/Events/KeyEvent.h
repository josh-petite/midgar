#pragma once

#include "Event.h"

namespace Midgar
{
	class MIDGAR_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return keycode; }

		EVENT_CLASS_CATEGORY(Keyboard | Input)
	protected:
		KeyEvent(int keycode) : keycode(keycode) {}

		int keycode;
	};

	class MIDGAR_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), repeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return repeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keycode << " (" << repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int repeatCount;
	};

	class MIDGAR_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keycode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}