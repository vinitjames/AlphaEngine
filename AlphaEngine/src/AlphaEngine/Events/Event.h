#pragma once
#include "Aepch.h"
#include "AlphaEngine/Core.h"


namespace AlphaEngine {
	
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication  = BIT(0),
		EventCategoryInput        = BIT(1),
		EventCategoryKeyboard     = BIT(2),
		EventCategoryMouse        = BIT(3),
		EventCategoryMouseButton  = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticEvent() { return EventType::##type; }\
							   virtual EventType GetEventType() const override  { return GetStaticEvent(); }\
						       virtual const char* GetName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;} 
			            
	class AlphaEngine_API Event {
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }
	
		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	class AlphaEngine_API EventDispatcher {
		
		template<typename T>
		using EventFunc = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFunc<T> func) {
			if (m_Event.GetEventType == T::GetStaticType())
				m_Event.m_Handled = func(*(T*)&m_Event);
			return m_Event.m_Handled;
		}


	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}