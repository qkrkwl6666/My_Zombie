#pragma once
#include "Scene.h"

class ZombieSpawner;
class Player;
class Bullet;
class SpriteGo;
class TextGo;
class Score;

class SceneGame : public Scene
{
protected:
	Player* player = nullptr;
	SpriteGo* titleBackground = nullptr;
	Score* score = nullptr;

	std::vector<ZombieSpawner*> spawners;

	float timeScale = 0.f;
	bool isTitle = true;

public:
	SceneGame(SceneIds id);
	~SceneGame() override = default;

	void Init() override;
	void Release() override;

	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

