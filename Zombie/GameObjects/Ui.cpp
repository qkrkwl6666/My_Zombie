#include "pch.h"
#include "Ui.h"
#include "Scene.h"

Ui::Ui(const std::string& name) : Scene(name)
{

}

void Ui::Draw(sf::RenderWindow& window)
{

}

void Ui::Update(float dt)
{

}

void Ui::Init()
{
	titleBackground = new SpriteGo("titleBackground");
	RES_MGR_TEXTURE.Instance().Get("graphics/background.png");
	titleBackground->SetTexture("graphics/background.png");
	titleBackground->sortLayer = 10;
	titleBackground->SetOrigin(Origins::MC);
	AddGo(titleBackground);
}

void Ui::Release()
{

}

void Ui::Reset()
{

}
