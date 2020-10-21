#pragma once

#include "Event.h"

#include <sstream>

namespace Seed {
	class SEED_API KeyEvent : public Event {
	public: 
		inline int getKeyCode() const { return m_keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected: 
		KeyEvent(int keyCode) : m_keyCode(keyCode) {}

		int m_keyCode; 
	};

	class SEED_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_repeatCount(repeatCount) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private: 
		int m_repeatCount
	};

	class SEED_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_keyCode; 
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}
