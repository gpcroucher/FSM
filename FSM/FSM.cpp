// FSM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool doorsensor = false;
bool request = false;

void DoorSensor() {
	doorsensor = true;
}

void Request() {
	request = true;
}

int main()
{


    return 0;
}

class StateEngine {
	

};

class StateOpening {
public:
	static void Enter() {

	}
};

class StateClosing {
public:
	static void Enter() {
		if (doorsensor) {
			StateOpening::Enter();
		}
		else {
			StateClosed::Enter();
		}
	}
};

class StateClosed {
	public:
		StateClosed() {

		}
		static void Enter() {
			if (request) {
				StateMoving::Enter();
			}
			else {

			}
		}
};

class StateOpen {
public:
	static void Enter() {
		StateClosing st;
		st.Enter();
	}
};

class StateMoving {
	public:
		static void Enter() {
			StateClosed st;
			st.Enter();
		}
};