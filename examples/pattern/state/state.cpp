#include "state.h"

void State::ChangeState(Context*c, State*s)
{
	c->ChangeState(s);
}
