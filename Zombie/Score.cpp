#include "pch.h"
#include "Score.h"

Score::Score(const std::string& name) : TextGo(name)
{

}

void Score::AddScore(int score)
{
	this->score += score;
}

void Score::SetScore(int score)
{
	this->score = score;
}

int Score::GetScore()
{
	return score;
}

void Score::Init()
{
	RES_MGR_FONT.Instance().Get("fonts/zombiecontrol.ttf");
	SetFont("fonts/zombiecontrol.ttf");
	SetString("Score : " + std::to_string(score));
	SetCharacterSize(75);
}

void Score::Reset()
{
	TextGo::Reset();
	score = 0;
}

void Score::SetString(const std::string& str)
{
	TextGo::SetString(str);
}

void Score::Set(const sf::Font& texture, const std::string& str, int size, const sf::Color& color)
{
	TextGo::Set(texture, str, size, color);
}

void Score::SetFont(const std::string& textureId)
{
	TextGo::SetFont(textureId);
}

void Score::SetFont(const sf::Font& texture)
{
	TextGo::SetFont(texture);
}

void Score::Translate(const sf::Vector2f& delta)
{
	TextGo::Translate(delta);
}

void Score::SetPosition(const sf::Vector2f& pos)
{
	TextGo::SetPosition(pos);
}

void Score::SetOrigin(Origins preset)
{
	TextGo::SetOrigin(preset);
}

void Score::SetRotation(float r)
{
	TextGo::SetRotation(r);
}

void Score::SetOrigin(const sf::Vector2f& newOrigin)
{
	TextGo::SetOrigin(newOrigin);
}

void Score::SetScale(const sf::Vector2f& scale)
{
	TextGo::SetScale(scale);
}

void Score::Update(float dt)
{
	TextGo::Update(dt);

	//SetPosition(text.get);
}

