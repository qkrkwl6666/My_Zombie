#pragma once
#include "SpriteGo.h"
#include "ShapeGo.h"

class TileMap;
class Bullet;

class Player : public SpriteGo
{
protected:
	sf::Vector2f direction = { 0.f , 0.f }; // ����
	sf::Vector2f look = {1.0f , 0.f}; // ȸ��
	float speed = 700.f;
	sf::Vector2f currentMousePos = { 0.f , 0.f };
	sf::Vector2f currentPlayerPos = { 0.f , 0.f };
	sf::Vector2f ObjectPos = { 0.f , 0.f };
	std::string textureId;
	ShapeGo<sf::RectangleShape>* hpBar;
	int maxHp = 500;
	SpriteGo* crosshHair;
	TileMap* tileMap;
	sf::FloatRect tileMapBounds;

public:
	Player(const std::string& name = "");
	~Player() override = default;

	 void Init() override;
	 void Release() override;
	 void Translate(const sf::Vector2f& delta);
	 void Reset() override;

	 sf::FloatRect GetGlobalBounds();
	 void Update(float dt) override;
	 void Draw(sf::RenderWindow& window) override;

	 std::list<Bullet*> bullets;
};

