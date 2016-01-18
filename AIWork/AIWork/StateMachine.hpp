#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#include <Windows.h>
#include <stack>

#include "State.hpp"

template <class A> class StateMachine {
public:
	StateMachine<A>() {
		agent = nullptr;
		currentState = new ScatterState<A>(5);
		savedStates = std::stack<State<A>*>();
	}
	StateMachine<A>(A* a) 
	{ 
		agent = a; 
		currentState = new ScatterState<A>(5);
		savedStates = std::stack<State<A>*>();
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
		//asdsdf
		if (GetAsyncKeyState(VK_UP) && currentState->getName() != "GoHome")
		{
			startInterrupt(new ScaredState<A>(5));
		}
		else if (GetAsyncKeyState(VK_DOWN) && currentState->getName() == "Scared")
		{
			startInterrupt(new GoHomeState<A>(5));
		}
	}

	void startInterrupt(State<A>* newState)
	{
		savedStates.push(currentState);
		changeState(newState);
	}

	void exitInterrupt()
	{
		changeState(savedStates.top());
		savedStates.pop();
	}

	//Assumed to run once per sec
	void update() {
		handleInputs();
		currentState->execute(agent, this);
	}
private:
	A* agent;
	State<A>* currentState;
	std::stack<State<A>*> savedStates;
	};

#endif