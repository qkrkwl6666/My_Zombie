#pragma once
#include "GameObject.h"

class TileMap : public GameObject
{
protected:
	sf::VertexArray va;
	std::string spriteSheetId;
	sf::Texture* texture;
	
	sf::FloatRect bounds;

	sf::Vector2i cellCount;
	sf::Vector2f cellSize;

	sf::Transform transform;

public:
	int size = 0;

	TileMap(const std::string& name = "");

	void Set(const sf::Vector2i& count ,const sf::Vector2f& size);
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void Translate(const sf::Vector2f& delta);
	void UpdateTransform();

	sf::FloatRect GetBounds();

	void SetSpriteSheetId(const std::string& id);

	void SetPosition(const sf::Vector2f& pos) override;

	void SetScale(const sf::Vector2f& scale) override;

	void SetFlipX(bool flip) override;
	void SetFlipY(bool flip) override;

	void SetRotation(float r) override;

	void Init() override;

	void Release() override;

	void Reset() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

