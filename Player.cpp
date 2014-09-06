#include "Player.h"
#include "MapEngine.h"

Player* Player::m_Instance = 0;
Player* Player::Instance()
{
	if(m_Instance == 0) {
		m_Instance = new Player();
	}
	return m_Instance;
}
Player::Player()
{
	m_nPosx = -1;
	m_nPosy = -1;
}

Player::~Player()
{
}

void Player::GeneratePlayer()
{
	MapEngine::Instance()->QuerySpace(&m_nPosx, &m_nPosy);
	MapEngine::Instance()->SetTile(m_nPosx, m_nPosy, PLAYER);
}
