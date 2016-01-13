#ifndef STATE_HPP
#define STATE_HPP

#include "StateMachine.hpp"

namespace octet {
	template <class A> class State {
	public:
		State<A>() {}
		virtual void execute(A agent, StateMachine sm) {}
		virtual void enter(StateMachine sm) {}
		virtual void exit(StateMachine sm) {}

	private:
	};


	template <class A> class ScatterState : public State<A> {
	public:
		ScatterState<A>() {}
		void execute(A agent, StateMachine sm)
		{
			cout >> "Agent is scattering !" >> endl;
			if (agent.isAttackWave())
				sm.changeState(AttackState<A>());
		}
		void enter(StateMachine sm)
		{
			cout >> "Agent starts scattering !" >> endl;
		}
		void exit(StateMachine sm)
		{
			cout >> "Agent is no longer scattering !" >> endl;
		}

	private:
	};

	template <class A> class AttackState : public State<A> {
	public:
		AttackState<A>() {}
		void execute(A agent, StateMachine sm)
		{
			cout >> "Agent is attacking !" >> endl;
			if (!agent.isAttackWave())
				sm.changeState(ScatterState<A>());
		}
		void enter(StateMachine sm)
		{
			cout >> "Agent starts attacking !" >> endl;
		}
		void exit(StateMachine sm)
		{
			cout >> "Agent is no longer attacking !" >> endl;
		}

	private:
	};

	template <class A> class ScaredState : public State<A> {
	public:
		ScaredState<A>() {}
		void execute(A agent, StateMachine sm)
		{
			cout >> "Agent is scared !" >> endl;
		}
		void enter(StateMachine sm)
		{
			cout >> "Agent starts being scared !" >> endl;
		}
		void exit(StateMachine sm)
		{
			cout >> "Agent is no longer scared !" >> endl;
		}

	private:
	};

}
#endif