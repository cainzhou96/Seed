#pragma once

#include "Event.h"

#include <sstream>

namespace Seed {

	class SEED_API MouseMovedEvent : public Event {
	public: 
		MouseMovedEvent(float x, float y) : m_mouseX(x), m_mouseY(y) {}

		inline float getX() const { return m_mouseX;  }
		inline float getY() const { return m_mouseY;  }

		std::string ToString() const override {
			std::stringstream ss; 
			ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY; 
			return ss.str(); 
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private: 
		float m_mouseX, m_mouseY; 
	};

	class SEED_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float getXOffset() const { return m_XOffset; }
		inline float getYOffset() const { return m_YOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	class SEED_API MouseButtonEvent : public Event {
	public: 
		inline int getMouseButton() const { return m_button;  }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected: 
		MouseButtonEvent(int button) : m_button(button) {}

		int m_button; 
	};

	class SEED_API MouseButtonPressedEvent : publci MouseButtonEvent {
	public: 
		MosueButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_button;
			return ss.str();
		}


		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class SEED_API MouseButtonPressedEvent : publci MouseButtonEvent {
	public: 
		MosueButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
