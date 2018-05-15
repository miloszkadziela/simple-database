#include <iostream>
#include "Employee.h"													//Defines class Employee
#include "Template.h"													//Defines template Map<Key, Value>
#include "Database.h"

using namespace std;

int main() 
{
	typedef unsigned int ID; 											//Identification number of Employee
	Map<ID, Employee> database;											//Database of employees

	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	//Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	//Add second employee: name: Adam Nowak, position: storekeeper, age: 54
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	//Add third employee: name: Anna Zaradna, position: secretary, age: 32

	cout << database << endl;											//Print database

	Map<ID, Employee> newDatabase = database;							//Make a copy of database
	
	Employee* pE;
	pE = newDatabase.find(510212881);									//Find employee using its ID
	pE->position = "salesman";											//Modify the position of employee
	pE = newDatabase.find(761028073);									//Find employee using its ID
	pE->age = 29;														//Modify the age of employee

	database = newDatabase;												//Update original database
	
	cout << database << endl;											//Print original database

	Map<ID, Database> database2;
	database2.add(1, Database("O'Connor", "physics", "on the bookshelf", 444));
	database2.add(2, Database("Simons", "programming", "borrowed", 877));
	database2.add(3, Database("Gregg", "music", "on the shelf", 32));

	cout << database2 << endl;

	Map<ID, Database> newDatabase2 = database2;

	Database* pE2;
	pE2 = newDatabase2.find(1);
	pE2->author = "James";
	pE2 = newDatabase2.find(2);
	pE2->status = "on the bookshelf";
	database2 = newDatabase2;

	cout << database2 << endl;
	
	return 0;
}
