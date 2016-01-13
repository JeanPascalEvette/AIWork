#include "State.hpp"
namespace octet {

	template <class A> class StateMachine {
	public:
		StateMachine<A>(A* a) { agent = a; currentState = ScatterState(); }
		StateMachine<A>() { agent = GhostAI(); currentState = ScatterState(); }
		A getAgent() { return agent; }
		void setAgent(A a) { agent = a; }
		void setState(State<A> newState) { currentState = newState; }

		void changeState(State<A> newState) {
			currentState.exit(this);
			currentState = newState;
			currentState.enter(this);
		}

		void update() {
			currentState.execute(agent, this);
		}
	private:
		A* agent;
		State<A> currentState;

	};
}