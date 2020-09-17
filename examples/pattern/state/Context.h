#pragma once
class State;

class Context
{
public:
	Context();
	~Context() {};

	void Action1();
	void Action2();
	void Action3();
	void Action4();
	
private:
	friend class State;
	void ChangeState(State*);
private:
	State* _state;
};

