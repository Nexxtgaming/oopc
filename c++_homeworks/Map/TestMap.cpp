#include "Map.h"														// Defines template Map<Key, Value>
#include "Employee.h"													// Defines class Employee
#include "Book.h"

typedef unsigned int ID; 												// Identification number of employee
typedef Map<ID, Employee> Database; 									// Database of employees

using namespace std;

void addEmployees(Database& database);
void modifyEmployees(Database& database);


void addSameKeys(Database& database){
    database.add(730505129, Employee("Michal Komorowski", "shop assistant",21));
    database.add(730505129, Employee("Michal Nowak", "shop assistant",22));
}

void getNonExistingKey(Database& database){
    Employee* emp = database.find(1223);
    
}

void LibraryDatabase(){
    Map<std::string, Book> database;
    Book firstBook("Harry Potter"," fantasy ", "J.K Rowling", 300, false);
    database.add(firstBook.name, firstBook);
    Book* foundBook = database.find("Harry Potter");
    foundBook->borrowed = true;
    cout<<"-------- LIBRARY DATABASE-------"<<endl;
    cout<<database<<endl;
}

int main() {
	Database database;
	addEmployees(database);

	Database newDatabase = database;									// Make a copy of database (copy constructor called)
	newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43));	// Add fourth employee
	modifyEmployees(newDatabase);

	cout << "Original database:" << endl << database << endl;
	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase;												// Update original database (assignment operator called)

	cout << "Database after the assignment:" << endl << database << endl;

    addSameKeys(database);
    getNonExistingKey(database);
    LibraryDatabase();
}

void addEmployees(Database& database) {
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
}

void modifyEmployees(Database& database) {
	Employee* pE;

	pE = database.find(510212881);										// Find employee using its ID
	pE->position = "salesman";											// Modify the position of employee
	
	pE = database.find(761028073);										// Find employee using its ID
	pE->age = 29;														// Modify the age of employee
}
