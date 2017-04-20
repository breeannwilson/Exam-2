//I affirm that all code given below was written solely by me, <Breeann Wilson>, 
//and that any help I received adhered to the rules stated for this exam.
#include <string>
#include <iostream>
#include "Citizen.h"
using namespace std;

//construct citizen object
Citizen::Citizen(int newid, string newfirstName, string newlastName, string newcolor) {
	id = newid;
	firstName = newfirstName;
	lastName = newlastName;
	color = newcolor;
}

//create new citizen object by copying data from the passed in citizen
Citizen::Citizen(Citizen* citizen) {
	if (citizen != NULL) {
		id = citizen->getId();
		firstName = citizen->getFirstName();
		lastName = citizen->getLastName();
		color = citizen->getFavoriteColor();
	}
}


//get first name function
string Citizen::getFirstName() {
	return firstName;
}

//get last name function
string Citizen::getLastName() {
	return lastName;
}

//get id function
int Citizen::getId() {
	return id;
}

//get favorite color function
string Citizen::getFavoriteColor() {
	return color;
}

//set favorite color function
void Citizen::setFavoriteColor(string newcolor) {
	color = newcolor;
}