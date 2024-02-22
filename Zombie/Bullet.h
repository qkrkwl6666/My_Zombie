#pragma once
#include "ShapeGo.h"
class Player;

class Bullet : public ShapeGo<sf::CircleShape>
{

public:
	Bullet(const std::string& name = "");
	~Bullet() override = default;
	void Init() override;
	void Release() override;
	void Reset() override;
	void Draw(sf::RenderWindow& window) override;
	void Update(float dt) override;
	float GetDamage() { return damage; }
	void SetDamage(float damage) { this->damage = damage; }

	float timer = 0.f;
	float removeTime = 3.f;
	float isRemove = false;

protected:
	Player* player;
	float speed = 1500.f;
	float damage = 10.f;

	sf::Vector2i mousePos;
	sf::Vector2f mouseWorldPos;
	sf::Vector2f direction;

};

