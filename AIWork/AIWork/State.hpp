#ifndef STATE_HPP
#define STATE_HPP
#include <iostream>
#include <string>

template <class A> class StateMachine;
template <class A> class State {
public:
	State<A>() { name = "base"; life = -1; }
	State<A>(const int& lifeCount) { name = "base"; life = lifeCount; }
	virtual void execute(A* agent, StateMachine<A>* sm) { if (life > 0) life--; }
	virtual void enter(StateMachine<A>* sm) {}
	virtual void exit(StateMachine<A>* sm) {}
	std::string getName() { return name; }

protected:
	std::string name;
	int life;
};


template <class A> class ScatterState : public State<A> {
public:
	ScatterState<A>() { name = "Scatter"; life = -1; }
	ScatterState<A>(const int& lifeCount) { name = "Scatter"; life = lifeCount; }
	void execute(A* agent, StateMachine<A>* sm)
	{
		log("Agent is scattering !");
		State<A>::execute(agent, sm);
		if(life == 0)
			sm->changeState(new AttackState<A>(10));
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
	AttackState<A>() { name = "Attack"; life = -1; }
	AttackState<A>(const int& lifeCount) { name = "Attack"; life = lifeCount; }
	void execute(A* agent, StateMachine<A>* sm)
	{
		log("Agent is attacking !");
		State<A>::execute(agent, sm);
		if (life == 0)
			sm->changeState(new ScatterState<A>(5));
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
	ScaredState<A>() { name = "Scared"; life = -1 }
	ScaredState<A>(const int& lifeCount) { name = "Scared"; life = lifeCount; }
	void execute(A* agent, StateMachine<A>* sm)
	{
		log("Agent is scared !");
		State<A>::execute(agent, sm);
		if (life == 0)
			sm->exitInterrupt();
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


template <class A> class GoHomeState : public State<A> {
public:
	GoHomeState<A>() { name = "GoHome"; life = -1 }
	GoHomeState<A>(const int& lifeCount) { name = "GoHome"; life = lifeCount; }
	void execute(A* agent, StateMachine<A>* sm)
	{
		log("Agent is going home !");
		State<A>::execute(agent, sm);
		if (life == 0)
		{
			sm->exitInterrupt();
			sm->exitInterrupt();//Exits the Scared interrupt as well
		}
	}
	void enter(StateMachine<A>* sm)
	{
		log("Agent starts going home!");
	}
	void exit(StateMachine<A>* sm)
	{
		log("Agent is no longer going home!");
	}

	template <class A> A doStuff(A myData)
	{
		return myData;
	}

private:
};


void log(std::string str) {
	std::cout << str << std::endl;
};

#endif