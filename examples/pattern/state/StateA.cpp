#include "StateA.h"
#include "StateB.h"
#include <iostream>
State* StateA::Instance()
{
	std::cout << "state A" << std::endl;
	return new StateA();
}

void StateA::Action1(Context* p)
{
	std::cout << "action1 state A" << std::endl;
}

void StateA::Action2(Context* p)
{
	std::cout << "action2 state A" << std::endl;
	ChangeState(p, StateB::Instance());
}
