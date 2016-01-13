#ifndef STATE_HPP
#define STATE_HPP
#include <iostream>
#include <string>

template <class A> class StateMachine;
template <class A> class State {
public:
	State<A>() { name = "base"; }
	virtual void execute(A* agent, StateMachine<A>* sm) {}
	virtual void enter(StateMachine<A>* sm) {}
	virtual void exit(StateMachine<A>* sm) {}
	std::string getName() { return name; }

protected:
	std::string name;
};


template <class A> class ScatterState : public State<A> {
public:
	ScatterState<A>() { name = "Scatter"; }
	void execute(A* agent, StateMachine<A>* sm)
	{
		log("Agent is scattering !");
		if (agent->isAttackWave())
			sm->changeState(new AttackState<A>());
	}
	void enter(StateMachine<A>* sm)
	{
		log("Agent starts scattering !");
	}
	void exit(StateMachine<A>* sm)
	{
		log("Agent is no longer scattering !");
	}

private:
};

template <class A> class AttackState : public State<A> {
public:
	AttackState<A>() { name = "Attack"; }
	void execute(A* agent, StateMachine<A>* sm)
	{
		log("Agent is attacking !");
		if (!agent->isAttackWave())
			sm->changeState(new ScatterState<A>());
	}
	void enter(StateMachine<A>* sm)
	{
		log("Agent starts attacking !");
	}
	void exit(StateMachine<A>* sm)
	{
		log("Agent is no longer attacking !");
	}

private:
};

template <class A> class ScaredState : public State<A> {
public:
	ScaredState<A>() { name = "Scared"; }
	void execute(A* agent, StateMachine<A>* sm)
	{
		log("Agent is scared !");
	}
	void enter(StateMachine<A>* sm)
	{
		log("Agent starts being scared !");
	}
	void exit(StateMachine<A>* sm)
	{
		log("Agent is no longer scared !");
	}

private:
	};

void log(std::string str) {
	std::cout << str << std::endl;
};

#endif