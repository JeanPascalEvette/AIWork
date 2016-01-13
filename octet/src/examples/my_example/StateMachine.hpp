#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#include <conio.h>

#include "State.hpp"

template <class A> class StateMachine {
public:
	StateMachine<A>() {
		agent = nullptr;
		currentState = new ScatterState<A>();
		startScared = 0;
	}
	StateMachine<A>(A* a) 
	{ 
		agent = a; 
		currentState = new ScatterState<A>(); 
		startScared = 0;
	}
	A* getAgent() { return agent; }
	void setAgent(A* a) { agent = a; }
	void setState(State<A>* newState) { currentState = newState; }

	void changeState(State<A>* newState) {
		currentState->exit(this);
		currentState = newState;
		currentState->enter(this);
	}

	void handleInputs()
	{
		if(GetAsyncKeyState(VK_UP))
		{
			changeState(new ScaredState<A>());
			startScared = clock(); 
		}
	}

	void update() {
		if (currentState->getName() == "Scared" && startScared + 3000 < clock())
			changeState(new ScatterState<A>());
		handleInputs();
		currentState->execute(agent, this);
	}
private:
	A* agent;
	State<A>* currentState;
	time_t startScared;
	};

#endif