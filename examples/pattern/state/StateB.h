#pragma once
#include "state.h"
class StateB :public State
{
public:
	StateB() {};
	static State* Instance();


	virtual void Action1(Context* p);
	virtual void Action2(Context* p) {}
	virtual void Action3(Context* p) {}
	virtual void Action4(Context* p) {}
};

