#include <iostream>
#include <string>

#include "Database.h"

Database::Database(std::string author, std::string category, std::string status, unsigned int pages) 
{
	this->author = author;
    this->category = category;
	this->status = status;
    this->pages = pages;
}
