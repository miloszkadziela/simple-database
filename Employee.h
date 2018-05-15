#include <iostream>
#include <string>

class Employee 
{
public:
	std::string name;
	std::string position;
	unsigned int age;
	Employee(const std::string& name = "", const std::string& position = "", unsigned int age = 0);

	friend std::ostream& operator<<(std::ostream& o, Employee& emp)
	{
		o << "Name: " << emp.name;
		o << "; Position: " << emp.position;
		o << "; Age: " << emp.age;
		return o;
	}
};

