#pragma once

#include <Walnut/Core/Events/Event.h>

namespace Walnut {

	class Layer
	{
	public:
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnEvent(Event& event) {}

		virtual void OnUpdate(float ts) {}
		virtual void OnRender() {}
		virtual void OnUIRender() {}
	};

}