#pragma once

#include "Event.h"

#include <Walnut/Input/KeyCodes.h>

#include <glm/glm.hpp>
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

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(glm::vec2 pos)
			: m_Pos(pos) {}
		MouseMovedEvent(double xpos, double ypos)
			: m_Pos(xpos, ypos) {}

		inline glm::vec2 GetMousePos() const { return m_Pos; }

		std::string ToString() const override
		{
			return std::format("MouseMovedEvent: x: {}, y: {}", m_Pos.x, m_Pos.y);
		}

		EVENT_CLASS_TYPE(MouseMoved)
	private:
		glm::vec2 m_Pos;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(glm::vec2 scrollOffset)
			: m_ScrollOffset(scrollOffset) {}
		MouseScrolledEvent(double xoffset, double yoffset)
			: m_ScrollOffset(xoffset, yoffset) {}

		inline glm::vec2 GetScrollOffset() const { return m_ScrollOffset; }

		std::string ToString() const override
		{
			return std::format("MouseScrolledEvent: x: {}, y: {}", m_ScrollOffset.x, m_ScrollOffset.y);
		}

		EVENT_CLASS_TYPE(MouseScrolled)
	private:
		glm::vec2 m_ScrollOffset;
	};

}
