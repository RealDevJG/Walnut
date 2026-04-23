#pragma once

#include <Walnut/Layer.h>

class ApplicationLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override;

	void UI_DrawAboutModal();
	void ShowAboutModal();
private:
	bool m_AboutModalOpen = false;
};
