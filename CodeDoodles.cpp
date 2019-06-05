#include <iostream>

//notice the order of inclusions
#include "LoopRecursionTestOne.h"
#include "LoopRecursionTestTwo.h"

#include "StateMachine.h"

//bit sign & can be used to test for odd / even when used with 1
//bit signs >> shift the binary of the number at the given digit
//for example 8 >> 3 does the following:
//8 = 1000
//8 >> 3 = 0001
bool TestForOdd(int x) {
	return (x & 1) ? true : false;
}

//classes can be defined with a function
void TestClassInsideFunction(int x) {
	class Example {
	public :
		Example(int value = 10) { m_Value = value; };
		void PrintValue() { std::cout << m_Value << std::endl; };

	private:
		int m_Value;
	};

	Example em(x);
	em.PrintValue();
}

void TestForStateMachine() {
	StateMachine sm;

	int selection = -1;

	while (selection != 0) {
		std::cout << "0 - Exit" << std::endl;
		std::cout << "1 - Open Door" << std::endl;
		std::cout << "2 - Close Door" << std::endl;

		std::cin >> selection;

		if (selection == 0) break;

		if (selection == 1) {
			sm.Open();
		} else if (selection == 2) {
			sm.Close();
		}
	}
}

int main() {
	int x = 15;

	//cout << TestForOdd(x);
	//TestClassInsideFunction(23);
	TestForStateMachine();

	std::cin.get();
}
