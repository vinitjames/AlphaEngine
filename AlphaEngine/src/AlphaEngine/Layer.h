#pragma once
#include "AlphaEngine/Core.h"
#include "AlphaEngine/Events/Event.h"

namespace AlphaEngine {
	class AlphaEngine_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& e) {};

		inline const std::string& GetName() const { return m_LayerName; }

	private:
		std::string m_LayerName;
	};
}