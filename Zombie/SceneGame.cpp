#include "pch.h"
#include "SceneGame.h"
#include "Player.h"
#include "TileMap.h"
#include "ZombieGo.h"
#include "ZombieSpawner.h"
#include "Bullet.h"
#include "TextGo.h"
#include "Score.h"

SceneGame::SceneGame(SceneIds id) : Scene(id)
{
	
}

void SceneGame::Init()
{
	//AddGo(new TileMap("Background"));
	titleBackground = new SpriteGo("titleBackground");
	RES_MGR_TEXTURE.Instance().Get("graphics/background.png");
	titleBackground->SetTexture("graphics/background.png");
	titleBackground->sortLayer = 10;
	titleBackground->SetOrigin(Origins::MC);

	// score
	score = new Score("Score");
	
	AddGo(score, Scene::Layers::Ui);
	
	AddGo(titleBackground);

	spawners.push_back(new ZombieSpawner());
	spawners.push_back(new ZombieSpawner());

	for (auto data : spawners) 
	{
		data->SetPosition(Utils::RandomOnUnitCircle() * 250.f);
		AddGo(data);
	}

	player = new Player("Player");

	TileMap* tileMap = new TileMap("Background");
	tileMap->sortLayer = -1;

	AddGo(player);
	AddGo(tileMap);

	Scene::Init();
}

void SceneGame::Release()
{
	Scene::Release();
}

void SceneGame::Enter()
{
	Scene::Enter();

	sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();
	sf::Vector2f centerPos = windowSize * 0.f;

	worldView.setSize(windowSize);
	worldView.setCenter({ 0.f, 0.f });
	uiView.setSize(windowSize);
	uiView.setCenter(centerPos);
	TileMap* tileMap = dynamic_cast<TileMap*>(FindGo("Background"));

	tileMap->SetPosition({ 0.f, 0.f });
	tileMap->SetOrigin(Origins::MC);
	player->SetPosition({ 0.f, 0.f });

	//tileMap->SetRotation(45);
	//tileMap->SetScale({ 2.5f , 2.5f });

}

void SceneGame::Exit()
{
	Scene::Exit();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt * timeScale);

	worldView.setCenter(player->GetPosition());
	titleBackground->SetPosition(player->GetPosition());

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && isTitle)
	{
		titleBackground->SetActive(false);
		timeScale = 1.f;
		isTitle = false;
	}
	else if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && !isTitle)
	{
		titleBackground->SetActive(true);
		timeScale = 0.f;
		isTitle = true;
	}

	//if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	//{
	//	ZombieGo::Types zombieType =
	//		(ZombieGo::Types)Utils::RandomRange(0, ZombieGo::TotalTypes);

	//	ZombieGo* zombie = ZombieGo::Create(zombieType);

	//	zombie->Init();

	//	zombie->Reset();

	//	zombie->SetPosition(Utils::RandomInUnitCircle() * 500.f);

	//	AddGo(zombie);
	//}

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
	/*	TileMap* tileMap = dynamic_cast<TileMap*>(FindGo("Background"));
		if (tileMap->sortLayer == -1)
		{
			tileMap->sortLayer = 1;
		}
		else
		{
			tileMap->sortLayer = -1;
		}
		ResortGo(tileMap);*/
	}


}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	
}
