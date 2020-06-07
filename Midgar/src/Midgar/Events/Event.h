#pragma once

#include "Midgar/Core.h"

namespace Midgar 
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowFocus, WindowLostFocus, WindowMoved, WindowResize,
		AppRender, AppTick, AppUpdate,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None					 = 0,
		AppEventCategory		 = BIT(0),
		InputEventCategory		 = BIT(1),
		KeyboardEventCategory	 = BIT(2),
		MouseEventCategory		 = BIT(3),
		MouseButtonEventCategory = BIT(4)
	};

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class MIDGAR_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }
		inline bool IsHandled() { return isHandled; }
	protected:
		bool isHandled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& e) : event(e) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (event.GetEventType() == T::GetStaticType())
			{
				event.isHandled = func(*(T*)&event);
				return true;
			}
			return false;
		}
	private:
		Event& event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}