	/* Notes :	Implement a queue for event handling
	*			 	
	*
	*/
#pragma once

// Grimoire events are implemented as blocking events, for now
// i.e, there is no priority queue for event execution and 
// it works on the concept of FIFO, like a stack
// Future plan : to implement a priority bus[Queue] for event execution

#include "../Grim/Grim_core.h"

// better to place it in core profile
// Part of precompiled headers
#include <string> 
#include <functional>


namespace Grimoire {

	// dictates the value for the event type for ease of execution
	enum class EventType {
		NullEvent = 0,

		// Window Event type values :
		WinExit, WinResize, WinFocus, WinLostFocus, WinMoved,  

		// Application event values :
		AppTick, AppUpdate, AppRend,		// "Rend" for Render sounds cooler

		// KeyBoard Events , maybe in future more events would be added to this type
		KeyPressed, KeyReleased,

		// Mouse Events :
		// Mousebutton : MseBtn
		MseBtnPressed, MseBtnReleased, MouseMoved, MouseScroll
	};

	// little bit of bit masking for better recognition
	// a single event can be regarded as more than 1 event 
	// intended to work as flags
	enum EventCatagory 
	{
		NullCat = 0,
		EventCategoryApplication =	BIT(0),
		EventCategoryInput =		BIT(1),
		EventCategoryKeyboard =		BIT(2),
		EventCategoryMouse =		BIT(3),
		EventCategoryMouseBtn =		BIT(4)
	};

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() {return EventType::##type}\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* Getname() const override {return #type; }

#define EVENT_CLASS_CATEGORY(cat)	virtual int GetCategoryFlags() const override { return cat; }

class Event {
	friend class EventDispatcher;
public:
	virtual ~Event() = default;

	virtual EventType GetEventType() const = 0;
	virtual const char* Getname() const = 0;
	virtual int GetCatFlags() const = 0;
	virtual std::string ToStringDebug() const { return Getname(); }

	inline bool IsInValidCategory(EventCatagory cat) {
		return	GetCatFlags() & cat;
	}

protected : 
	bool event_handled = false;
};

class EventDispatcher {
		template <typename T>
		using Eventfn = std::function<bool(T&);

public:
	EventDispatcher(Event& eve) : m_event(eve) {}

private:
	Event& m_event;
};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToStringDebug();
	}

}