#include <string>
#include <iostream>

#include "Employee.h"

Employee::Employee(const std::string& name, const std::string& position, unsigned int age) 
{
	this->name = name;
	this->position = position;
	this->age = age;
}