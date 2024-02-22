#include "pch.h"
#include "ZombieSpawner.h"

ZombieSpawner::ZombieSpawner(const std::string& name)
	: GameObject(name)
{

}

void ZombieSpawner::Init()
{
	GameObject::Init();
}

void ZombieSpawner::Release()
{
	GameObject::Release();
}

void ZombieSpawner::Reset()
{
	GameObject::Reset();

	zombieTypes.clear();
	zombieTypes.push_back(ZombieGo::Types::Bloater);
	zombieTypes.push_back(ZombieGo::Types::Chase);
	zombieTypes.push_back(ZombieGo::Types::Chase);
	zombieTypes.push_back(ZombieGo::Types::Chase);
	zombieTypes.push_back(ZombieGo::Types::Crawler);
	zombieTypes.push_back(ZombieGo::Types::Crawler);

	interval = 1.f;
	spawnCount = 1;
	radius = 250.f;
	timer = 0.f;

}

void ZombieSpawner::Update(float dt)
{
	GameObject::Update(dt);

	timer += dt;

	if (timer > interval) 
	{
		timer = 0.f;

		for (int i = 0; i < spawnCount; i++) 
		{
			sf::Vector2f pos = position +
				Utils::RandomInUnitCircle() * radius;

			ZombieGo::Types zombieType = zombieTypes
				[Utils::RandomRange(0, zombieTypes.size())];

			ZombieGo* zombie = ZombieGo::Create(zombieType);
			zombie->Init();
			zombie->Reset();
			zombie->SetPosition(pos); 

			SCENE_MGR.GetCurrentScene()->AddGo(zombie);

		}
	}
}
