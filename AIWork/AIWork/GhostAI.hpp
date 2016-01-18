#ifndef GHOSTAI_HPP
#define GHOSTAI_HPP

#include "StateMachine.hpp"
#include <time.h>
	class GhostAI {
	public:
		GhostAI() {
			fsm = StateMachine<GhostAI>();
			startScatter = 0;
		}
		void update() {
			if (fsm.getAgent() == nullptr)
				fsm.setAgent(this);
			fsm.update();
		}

		bool isAttackWave()
		{
			if (startScatter + 3000 > clock())
			{
				return false;
			}
			else if (startScatter + 13000 > clock())
			{
				return true;
			}
			
			int randNum = rand() % 100;
			if (randNum < 33) return true;
			startScatter = clock();
			return false;
		}


	private:
		StateMachine<GhostAI> fsm;
		time_t startScatter;
	};
#endif