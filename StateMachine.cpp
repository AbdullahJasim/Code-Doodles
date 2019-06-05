#include "StateMachine.h"

StateMachine::StateMachine() {
	m_State = new OpenDoorState();
}

StateMachine::~StateMachine() {
	delete m_State;
	m_State = nullptr;
}

void StateMachine::Open() {
	m_State->Open(*this);
}

void StateMachine::Close() {
	m_State->Close(*this);
}