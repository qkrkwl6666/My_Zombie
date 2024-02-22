#include "pch.h"
#include "ZombieGo.h"
#include "Player.h"
#include "Scene.h"
#include "Bullet.h"

// �÷��̾ ������ ���� ����

ZombieGo* ZombieGo::Create(Types zombieType)
{
	ZombieGo* zombie = new ZombieGo("Zombie");
	zombie->type = zombieType;

	switch (zombieType)
	{
		case Types::Bloater:
			zombie->textureId = "graphics/bloater.png";
			zombie->maxHp = 40;
			zombie->speed = 100;
			break;
		case Types::Chase:
			zombie->textureId = "graphics/chaser.png";
			zombie->maxHp = 70;
			zombie->speed = 75;
			break;
		case Types::Crawler:
			zombie->textureId = "graphics/crawler.png";
			zombie->maxHp = 20;
			zombie->speed = 50;
			break;
	}

	return zombie;
}

ZombieGo::ZombieGo(const std::string& name) : SpriteGo(name)
{

}

void ZombieGo::Init()
{
	SpriteGo::Init();
	SetTexture(textureId);
	SetOrigin(Origins::MC);
}

void ZombieGo::Release()
{
	SpriteGo::Release();
}

void ZombieGo::Reset()
{
	SpriteGo::Reset();

	player = dynamic_cast<Player*>(SCENE_MGR.GetCurrentScene()
		->FindGo("Player"));
}

void ZombieGo::Update(float dt)
{
	SpriteGo::Update(dt);

	direction = player->GetPosition() - position;

	Utils::Nomalize(direction);

	Translate(direction * speed * dt);

	SetRotation(Utils::Angle(direction));

	

	ZombieDied();

	//�浹ó��
	// Utils::Distance �Ÿ� ��ȯ
	
	//if (Utils::Distance(position, player->GetPosition()) < 50.f) 
	//{
	//	SCENE_MGR.GetCurrentScene()->RemoveGo(this);
	//}

	//ZombieDied();

	//���� �÷��̾� ��ġ ��ó�� ������
	// �Ÿ��� �缭 �����Ѱ����� �������� ���� off

}

void ZombieGo::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);
}

void ZombieGo::ZombieDied()
{
	zombieBounds = sprite.getGlobalBounds();

	std::vector<Bullet*> bullet = player->bullets;
	// auto it = bullet.begin();

	for (int i = 0; i < bullet.size(); i++)
	{
		if (zombieBounds.intersects(bullet[i]->GetGlobalBounds()))
		{
			hp -= bullet[i]->GetDamage();
			bullet[i]->SetDamage(0);
			SCENE_MGR.GetCurrentScene()->RemoveGo(bullet[i]);
			//bullet.erase(bullet.begin() + i);

			if (hp < 0)
			{
				isDead = true;
				SCENE_MGR.GetCurrentScene()->RemoveGo(this);
			}
			return;
		}
	}
}
