#include "DoorState.h"

DoorState::~DoorState() {}

void DoorState::SetState(StateMachine& sm, DoorState* state) {
	DoorState* temp = sm.m_State;
	sm.m_State = state;
	delete temp;
}

OpenDoorState::~OpenDoorState() {}

void OpenDoorState::Open(StateMachine& sm) {
	std::cout << "Door is already opened." << std::endl;
}

void OpenDoorState::Close(StateMachine& sm) {
	std::cout << "Closing door....." << std::endl;
	std::cout << "Door is closed." << std::endl;
	SetState(sm, new CloseDoorState());
}

CloseDoorState::~CloseDoorState() {}

void CloseDoorState::Open(StateMachine& sm) {
	std::cout << "Opening door....." << std::endl;
	std::cout << "Door is opened." << std::endl;
	SetState(sm, new OpenDoorState());
}

void CloseDoorState::Close(StateMachine& sm) {
	std::cout << "Door is already closed." << std::endl;
}