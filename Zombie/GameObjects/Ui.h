#pragma once
#include "Scene.h"
class SpriteGo;

class Ui : public Scene
{
public:
	Ui(const std::string& name = "");
	~Ui() override = default;

protected:
	SpriteGo* titleBackground;

	void Draw(sf::RenderWindow& window) override;
	void Update(float dt) override;

	void Init() override;
	void Release() override;
	void Reset() override;
};

