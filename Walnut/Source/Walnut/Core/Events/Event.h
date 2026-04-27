#pragma once

#include <functional>
#include <string>
#include <string_view>

namespace Walnut {

	enum class EventType
	{
		None = 0,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual std::string_view GetName() const override { return #type; }

	class Event
	{
	public:
		virtual ~Event() {}

		virtual EventType GetEventType() const = 0;
		virtual std::string_view GetName() const = 0;
		virtual std::string ToString() const { return GetName().data(); }
	public:
		bool Handled = false;
	};

	class EventDispatcher
	{
		template<typename T> requires std::is_base_of_v<Event, T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T> requires std::is_base_of_v<Event, T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType() && !m_Event.Handled)
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}

			return false;
		}
	private:
		Event& m_Event;
	};

}
