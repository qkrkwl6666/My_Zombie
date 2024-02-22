#pragma once
#include "TextGo.h"
class Score : public TextGo
{
public:
	Score(const std::string& name = "");
	~Score() override = default;

	void AddScore(int score);
	void SetScore(int score);
	int GetScore();

	void Init() override;
	void Reset() override;

	void SetString(const std::string& str);
	void Set(const sf::Font& texture, const std::string& str, int size, const sf::Color& color);

	void SetFont(const std::string& textureId);
	void SetFont(const sf::Font& texture);

	void Translate(const sf::Vector2f& delta);

	void SetPosition(const sf::Vector2f& pos) override;
	void SetOrigin(Origins preset) override;

	void SetRotation(float r) override;

	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetScale(const sf::Vector2f& scale) override;
	void Update(float dt);
	

protected:
	int score = 0;

};

