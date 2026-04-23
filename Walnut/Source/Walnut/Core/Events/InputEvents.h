#pragma once

#include "Event.h"

#include <Walnut/Input/KeyCodes.h>
#include <format>

namespace Walnut {

	// // Key events

	class KeyEvent : public Event
	{
	public:
		inline KeyCode GetKeyCode() const { return m_KeyCode; }
		inline uint16_t GetKeyCodeU16() const { return static_cast<uint16_t>(m_KeyCode); }
	protected:
		KeyEvent(KeyCode keyCode)
			: m_KeyCode(keyCode) {}

		KeyCode m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode keyCode, bool repeated)
			: KeyEvent(keyCode), m_Repeated(repeated) {}

		inline bool IsRepeat() const { return m_Repeated; }

		std::string ToString() const override
		{
			return std::format("KeyPressedEvent: {}, Repeated: {}", static_cast<uint16_t>(m_KeyCode), m_Repeated);
		}

		EVENT_CLASS_TYPE(KeyPressed);
	private:
		bool m_Repeated;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(KeyCode keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			return std::format("KeyReleasedEvent: {}", static_cast<uint16_t>(m_KeyCode));
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	// // Mouse events

	class MouseButtonEvent : public Event
	{
	public:
		inline MouseButton GetMouseButton() const { return m_Button; }
		inline uint16_t GetMouseButtonU16() const { return static_cast<uint16_t>(m_Button); }
	protected:
		MouseButtonEvent(MouseButton button)
			: m_Button(button) {}

		MouseButton m_Button;
	};

	class MousePressedEvent : public MouseButtonEvent
	{
	public:
		MousePressedEvent(MouseButton button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			return std::format("MousePressedEvent: {}", static_cast<uint16_t>(m_Button));
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseReleasedEvent(MouseButton button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			return std::format("MouseReleasedEvent: {}", static_cast<uint16_t>(m_Button));
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}
