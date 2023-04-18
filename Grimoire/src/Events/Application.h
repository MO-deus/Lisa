#pragma once

#include "Events.h"
#include <sstream>

namespace Grimoire {

	class GRIM_API WinResizeEvent : public Event
	{
		protected:
			unsigned int m_width, m_height;

		public:
			WinResizeEvent(unsigned int width, unsigned int height) :
				m_width(width), m_height(height){}
			
			inline  unsigned int GetWindowWidth() { return m_width; }
			inline  unsigned int GetWindowHeight() { return m_height; }

			std::string ToStringDebug() const override 
			{
				std::stringstream ss;
				ss << "WindowResizingEvent" << m_height << "," << m_width;
				return ss.str();
			}

			EVENT_CLASS_TYPE(WinResize);
			EVENT_CLASS_CATEGORY(EventCatagory::EventCategoryApplication);
	};

	class GRIM_API WinCLoseEvent : public Event
	{
		public:
			WinCLoseEvent();

			EVENT_CLASS_TYPE(WinExit);
	};
}