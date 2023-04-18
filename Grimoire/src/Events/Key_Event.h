#pragma once

#include "Events.h"
#include <sstream>

namespace Grimoire {
	class GRIM_API KeyBoardEvent : public Event
	{
		protected:
			int m_keycode;
			KeyBoardEvent(int keycode) : m_keycode(keycode) {};

		public:
			inline int Get_keycode() const { return m_keycode; }
			EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
					

	};

	class GRIM_API KeyPressedEvent : public KeyBoardEvent {

	};
}