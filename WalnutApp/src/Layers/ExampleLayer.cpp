#include "ExampleLayer.h"

#include <Walnut/Core/Events/InputEvents.h>
#include <iostream>

bool OnKeyPressed(Walnut::KeyPressedEvent& event)
{
	std::cout << event.ToString() << "\n";
	return true;
}

bool OnKeyReleased(Walnut::KeyReleasedEvent& event)
{
	std::cout << event.ToString() << "\n";
	return true;
}

bool OnMousePressed(Walnut::MousePressedEvent& event)
{
	std::cout << event.ToString() << "\n";
	return true;
}

bool OnMouseReleased(Walnut::MouseReleasedEvent& event)
{
	std::cout << event.ToString() << "\n";
	return true;
}

void ExampleLayer::OnEvent(Walnut::Event& event)
{
	Walnut::EventDispatcher dispatcher(event);
	dispatcher.Dispatch<Walnut::KeyPressedEvent>([this](Walnut::KeyPressedEvent& e) { return OnKeyPressed(e); });
	dispatcher.Dispatch<Walnut::KeyReleasedEvent>([this](Walnut::KeyReleasedEvent& e) { return OnKeyReleased(e); });

	dispatcher.Dispatch<Walnut::MousePressedEvent>([this](Walnut::MousePressedEvent& e) { return OnMousePressed(e); });
	dispatcher.Dispatch<Walnut::MouseReleasedEvent>([this](Walnut::MouseReleasedEvent& e) { return OnMouseReleased(e); });
}
