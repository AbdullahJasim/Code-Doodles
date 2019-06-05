#pragma once

#include <iostream>
#include "DoorState.h"

//a simple state machine for a door opening / closing
class DoorState;

class StateMachine {
public:
	StateMachine();
	virtual ~StateMachine();

	virtual void Open();
	virtual void Close();

	DoorState* m_State;

private:
	bool m_IsOpen;
};