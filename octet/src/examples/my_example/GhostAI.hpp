#include "StateMachine.hpp"
namespace octet {
	class GhostAI {
	public:
		GhostAI() {
			fsm = StateMachine<GhostAI>(this);
			startScared = 0;
		}
		void update() {
			if (1)
			{
				fsm.changeState(ScaredState<GhostAI>());
				startScared = clock();
			}
			if (startScared + 3000 < clock())
				fsm.changeState(AttackState<GhostAI>());
			fsm.update();
		}

		bool isAttackWave()
		{
			int randNum = rand() % 100;
			if (rand < 33) return true;
			return false;
		}


	private:
		StateMachine<GhostAI> fsm;
		time_t startScared;
	};
}