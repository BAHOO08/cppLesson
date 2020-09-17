#include "StateB.h"

#include <iostream>
State* StateB::Instance()
{
	std::cout << "state B" << std::endl;
	return new StateB();
}

void StateB::Action1(Context* p)
{
	std::cout << "Action1 state B" << std::endl;
}
