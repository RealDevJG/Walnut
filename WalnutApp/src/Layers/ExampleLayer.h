#pragma once

#include <Walnut/Layer.h>

class ExampleLayer : public Walnut::Layer
{
public:
	virtual void OnEvent(Walnut::Event& event) override;
};
