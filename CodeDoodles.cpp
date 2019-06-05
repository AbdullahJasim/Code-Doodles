#include <iostream>
#include <string>

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

template <typename T>
void TestForTemplates(T param) {
	std::cout << "Template type passed is " << typeid(T).name() << std::endl;
}

//exception in constructor test
void TestForCtorException() {
	class Example {
	public:
		Example() { throw "This ctor cannot be called!"; };
		Example(int x) { m_Value = x; };

		~Example() { std::cout << "This dtor will not be called when the ctor throws an exception!" << std::endl; };
	private:
		int m_Value;
	};

	try {
		Example ex;
	} catch (const char* error) {
		std::cout << error;
	}
}

//--------------------------------------------------------------------//
//----------------------------------MAIN------------------------------//
//--------------------------------------------------------------------//
int main() {
	//cout << TestForOdd(15);

	//TestClassInsideFunction(23);

	//TestForStateMachine();

	//std::string test = "Hello World";
	//TestForTemplates(test);

	TestForCtorException();

	std::cin.get();
}
