#include "pch.h"
#include "Bullet.h"
#include "Player.h"

Bullet::Bullet(const std::string& name) : ShapeGo(name)
{

}

void Bullet::Init()
{
	GameObject::Init();

	shape.setRadius(5.5f);
	SetColor(sf::Color::Yellow);
	SetOrigin(Origins::MC);

	player = dynamic_cast<Player*>(SCENE_MGR.GetCurrentScene()->FindGo("Player"));
	SetPosition(player->GetPosition());

	mousePos = (sf::Vector2i)InputMgr::GetMousePos();

	mouseWorldPos = SCENE_MGR.GetCurrentScene()->ScreenToWorld(mousePos);
	direction = mouseWorldPos - player->GetPosition();
	Utils::Nomalize(direction);

}

void Bullet::Release()
{
	ShapeGo::Release();
}

void Bullet::Reset()
{
	ShapeGo::Reset();
}

void Bullet::Draw(sf::RenderWindow& window)
{
	ShapeGo::Draw(window);
}

void Bullet::Update(float dt)
{
	ShapeGo::Update(dt);
	timer += dt;

	if (timer > removeTime && !isRemove)
	{
		isRemove = true;
	}

	Translate(direction * dt * speed);
}
