#include "Context.h"
#include "state.h"
#include "StateA.h"
Context::Context()
{
	 _state = StateA::Instance();
}

void Context::Action1()
{
	_state->Action1(this);
}

void Context::Action2()
{
	_state->Action2(this);
}

void Context::Action3()
{
	_state->Action3(this);
}

void Context::Action4()
{
	_state->Action4(this);
}

void Context::ChangeState(State* s)
{
	_state = s;
}
