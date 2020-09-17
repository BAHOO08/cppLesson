#pragma once
#include "Context.h"
class State
{
public:
	State(){}
	virtual ~State(){}
	virtual void Action1(Context* p) {}
	virtual void Action2(Context* p) {}
	virtual void Action3(Context* p) {}
	virtual void Action4(Context* p) {}
protected:
	void ChangeState(Context*, State*);
};

