#pragma once

#include "StateMachine.h"

class StateMachine;

class DoorState {
public:
	virtual ~DoorState();

	virtual void Open(StateMachine& sm) = 0;
	virtual void Close(StateMachine& sm) = 0;

protected:
	virtual void SetState(StateMachine& sm, DoorState* state);
};

class OpenDoorState : public DoorState {
public:
	virtual ~OpenDoorState();
	virtual void Open(StateMachine& sm);
	virtual void Close(StateMachine& sm);
};

class CloseDoorState : public DoorState {
public:
	virtual ~CloseDoorState();
	virtual void Open(StateMachine& sm);
	virtual void Close(StateMachine& sm);
};