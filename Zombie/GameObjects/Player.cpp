#include "pch.h"
#include "Player.h"
#include "Bullet.h"
#include "TileMap.h"

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

	crosshHair = new SpriteGo("Crosshair");
	crosshHair->SetTexture("graphics/crosshair.png");
	crosshHair->SetOrigin(Origins::MC);
	crosshHair->sortLayer = 11;
	SCENE_MGR.GetCurrentScene()->AddGo(crosshHair);

	tileMap = dynamic_cast<TileMap*>(SCENE_MGR.GetCurrentScene()->FindGo("Background"));
	tileMapBounds = tileMap->GetBounds();

	
	//hpBar = new ShapeGo<sf::RectangleShape>("hpBar");
	//hpBar->SetScale({ 500.f , 80.f });
	//hpBar->sortLayer = 11;
	//SCENE_MGR.GetCurrentScene()->AddGo(hpBar , Scene::Layers::Ui);
	//hpBar->SetPosition(position);

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

	crosshHair->SetPosition(mouseWorldPos);

	float h = InputMgr::GetAxis(Axis::Horizontal);
	float v = InputMgr::GetAxis(Axis::Vertical);

	// View && Renderwindow 필요함 
	direction.x = h;
	direction.y = v;

	if (Utils::Magnitude(direction) > 1.f)
	{
		Utils::Nomalize(direction);
	}

	sf::Vector2f newPos = position + direction * speed * dt;


	float halfWidth = tileMapBounds.width / 2;
	float halfHeight = tileMapBounds.height / 2;

	float leftBound = tileMapBounds.left - halfWidth + 50.f;
	float rightBound = tileMapBounds.left + halfWidth - 50.f;
	float topBound = tileMapBounds.top - halfHeight + 50.f;
	float bottomBound = tileMapBounds.top + halfHeight - 50.f;

	if (newPos.x > leftBound && newPos.x < rightBound
		&& newPos.y > topBound && newPos.y < bottomBound)
	{
		SetPosition(newPos);
	}

	look = mouseWorldPos - position;
	Utils::Nomalize(look);
	SetRotation(Utils::Angle(look));

	if (InputMgr::GetMouseButton(sf::Mouse::Left))
	{
		Bullet* bullet = new Bullet();
		bullet->Init();
		bullets.push_back(bullet);
		SCENE_MGR.GetCurrentScene()->AddGo(bullet);
	}

	auto it = bullets.begin();
	while (it != bullets.end())
	{
		Bullet* bullet = *it;
		if (bullet->isRemove)
		{
			SCENE_MGR.GetCurrentScene()->RemoveGo(bullet);
			it = bullets.erase(it);
		}
		else
		{
			it++;
		}
	}

}

void Player::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);
	window.setMouseCursorVisible(false); // 마우스커서 비활성화
}
