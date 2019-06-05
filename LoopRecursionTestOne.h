#pragma once

//if two files include each other, there will be an infinite loop that prevents
//the program from known the size of each class
//this can be avoided by using pointers / references coupled with forward declarations

#include <memory>
#include "LoopRecursionTestTwo.h"

class RecursionB;
 
class RecursionA {
public:
	//This will not break the program, as this file was include first in the main file
	//RecursionB b;

	//Pointers / references will also work
	//std::unique_ptr<RecursionB> b;

private:
};