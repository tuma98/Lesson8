#pragma once
#include "gamestatebase.h"

class Player;
class Bullet;
class BulletLeft;
class BulletRight;
class Enermy;
class Boss;
class Text;
class ExplosiveEffect;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void Init()override;
	void Exit()override;

	void Pause()override;
	void Resume()override;

	void HandleEvents() override;
	void HandleKeyEvents(int key, bool bIsPressed) override;
	void HandleMouseEvents(int x, int y) override;

	void HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void Update(float deltaTime) override;
	void Draw() override;
	
	static int m_score;

private:
	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Text>  m_scoreText;
	std::shared_ptr<Text>  m_playerHealText;
	std::shared_ptr<Player> m_Player;
	std::vector<std::shared_ptr<Bullet>> m_listBullet;
	std::vector<std::shared_ptr<BulletLeft>> m_listBulletLeft;
	std::vector<std::shared_ptr<BulletRight>> m_listBulletRight;
	std::vector<std::shared_ptr<Enermy>> m_listEnermy;
	std::vector<std::shared_ptr<Boss>> m_listEnermy2;
	std::vector<std::shared_ptr<ExplosiveEffect>> m_listExplosiveEffect;

	float m_SpawnCooldown;
	float m_SpawnCooldownBoss;
	void CreateRandomEnermy();
	void CreateBoss();
	void SpawnExplosive(Vector2 pos);
	float m_time;
};

