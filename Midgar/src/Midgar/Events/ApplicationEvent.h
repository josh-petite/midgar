#pragma once

#include "Event.h"

namespace Midgar
{
	class MIDGAR_API AppRenderEvent : public Event
	{
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(AppEventCategory)
	};

	class MIDGAR_API AppTickEvent : public Event
	{
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(AppEventCategory)
	};

	class MIDGAR_API AppUpdateEvent : public Event
	{
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(AppEventCategory)
	};

	class MIDGAR_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(AppEventCategory)
	};

	class MIDGAR_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int w, unsigned int h) : width(w), height(h) {}

		inline unsigned int GetWidth() const { return width; }
		inline unsigned int GetHeight() const { return height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << width << ", " << height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(AppEventCategory)
	private:
		unsigned int width;
		unsigned int height;
	};
}