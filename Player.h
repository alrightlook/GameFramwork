#ifndef PLAYER_HEADER
#define PLAYER_HEADER
class Player
{
	public:
		~Player();
		static Player* Instance();
		void GeneratePlayer();
	private:
		static Player* m_Instance;
		Player();
		int m_nPosx;
		int m_nPosy;

};
#endif
