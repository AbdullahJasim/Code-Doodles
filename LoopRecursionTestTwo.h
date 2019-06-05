#pragma once

#include <memory>
#include "LoopRecursionTestOne.h"

class RecursionA;

class RecursionB {
public:
	//this will cause an infinite loop and the program will not compile
	//RecursionA a;

	//A pointer / reference will work
	//std::unique_ptr<RecursionA> a;
	//RecursionA* a;
	RecursionA& a;
private:
};