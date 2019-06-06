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
		//if a ctor throws an exception, the dtor won't be called
		Example() { throw "This ctor cannot be called!"; };
		Example(int x) { m_Value = x; };

		//a dtor should never throw an exception, even though it is possible
		//this is becase the dtor is the last chance of freeing up the memory
		~Example() { std::cout << "This dtor will not be called when the ctor throws an exception!" << std::endl; };
	private:
		int m_Value;
	};

	try {
		//Example ex;
		Example* ex = new Example();
		delete ex;
	} catch (const char* error) {
		std::cout << error;
	}
}

//new and delete operators can be overloaded
void TestForNewAndDeleteOverload() {
	class Example {
	public:
		void* operator new(size_t bytes) {
			std::cout << "The new operator is first called" << std::endl;
			
			//to allocate memory, use this new operator which only calls the allocator
			return ::operator new(bytes);

			//calling this new operator will cause the ctor to be called twice
			//void* ret = ::new Example();
			//return ret;
		}

		Example() {
			std::cout << "The ctor is called second" << std::endl;
		}

		~Example() {
			std::cout << "When delete is called, the dtor is first called" << std::endl;
		}

		void operator delete(void* p) {
			std::cout << "Finally, the delete operator is called" << std::endl;
			free(p);
		}
	};

	//this will  not call the new operator
	//Example ex;

	//the overloaded new and delete operators will be called
	Example* ex = new Example();
	delete ex;
	ex = nullptr;
}

//NULL passes the bool test against nullptr
//NULL is deprecated and nullptr should be used
void TestForNullAgainstNullptr() {
	if (NULL == nullptr) {
		std::cout << "NULL is equal to nullptr" << std::endl;
	} else {
		std::cout << "NULL is not equal to nullptr" << std::endl;
	}
}

//nullptr passes the bool test against void pointer
void TestForNullptrAgainstVoidPtr() {
	int x = 0;
	void* p = &x;

	if (nullptr == p) {
		std::cout << "nullptr is equal to void pointer" << std::endl;
	} else {
		std::cout << "nullptr is equal to void pointer" << std::endl;
	}
}

//NULL does not pass bool test against a void ptr
void TestForNullAgainstVoidPtr() {
	int x = 0;
	void* p = &x;

	if (NULL == p) {
		std::cout << "NULL is equal to void pointer" << std::endl;
	} else {
		std::cout << "NULL is not equal to void pointer" << std::endl;
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

	//TestForCtorException();

	//TestForNewAndDeleteOverload();

	TestForNullAgainstNullptr();
	TestForNullptrAgainstVoidPtr();
	TestForNullAgainstVoidPtr();

	std::cin.get();
}
