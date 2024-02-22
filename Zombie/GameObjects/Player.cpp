#include "pch.h"
#include "Player.h"
#include "Bullet.h"

Player::Player(const std::string& name)
	: SpriteGo(name)
{

}

void Player::Init()
{
	SpriteGo::Init();
	//InputMgr::Init();
	SetTexture("graphics/player.png");
	SetOrigin(Origins::MC);
	hpBar = new ShapeGo<sf::RectangleShape>("hpBar");
	hpBar->SetScale({ 500.f , 80.f });
	hpBar->sortLayer = 11;
	SCENE_MGR.GetCurrentScene()->AddGo(hpBar , Scene::Layers::Ui);
	hpBar->SetPosition(position);
}

void Player::Release()
{
	SpriteGo::Release();
}

void Player::Translate(const sf::Vector2f& delta)
{
	position += delta;
	sprite.setPosition(position);
}

void Player::Reset()
{
	SpriteGo::Reset();
}



sf::FloatRect Player::GetGlobalBounds()
{
	return sprite.getGlobalBounds();

}

void Player::Update(float dt)
{
	//InputMgr::Clear();
	SpriteGo::Update(dt);

	sf::Vector2i mousePos = (sf::Vector2i)InputMgr::GetMousePos();
	sf::Vector2f mouseWorldPos = SCENE_MGR.GetCurrentScene()->ScreenToWorld(mousePos);

	float h = InputMgr::GetAxis(Axis::Horizontal);
	float v = InputMgr::GetAxis(Axis::Vertical);

	// View && Renderwindow �ʿ��� 
	direction.x = h;
	direction.y = v;

	if (Utils::Magnitude(direction) > 1.f)
	{
		Utils::Nomalize(direction);
	}

	SetPosition(position + direction * speed * dt);

	look = mouseWorldPos - position;
	Utils::Nomalize(look);
	SetRotation(Utils::Angle(look));

	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	{
		Bullet* bullet = new Bullet();
		bullet->Init();
		bullets.push_back(bullet);
		SCENE_MGR.GetCurrentScene()->AddGo(bullet);
	}

}

void Player::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);
}