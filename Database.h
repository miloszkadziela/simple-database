#include <iostream>
#include <string>

class Database 
{
public:
	std::string author;
	std::string category;
	std::string status;
	unsigned int pages;
	Database(std::string author, std::string category, std::string status, unsigned int pages);

	friend std::ostream& operator<<(std::ostream& o, Database& db)
	{
		o << "Author: " << db.author;
		o << "; Category: " << db.category;
		o << "; Status: " << db.status;
		o << "; Number of Pages: " << db.pages;
		return o;
	}
};