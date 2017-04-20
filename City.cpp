//I affirm that all code given below was written solely by me, <Breeann Wilson>, 
//and that any help I received adhered to the rules stated for this exam.

#include <vector>
#include <string>
#include <fstream>
using namespace std;
#include "Citizen.h"
#include "City.h"

City::City(string newcityName) {
	cityName = newcityName;
	
	ifstream input(newcityName.c_str());

	//does the file exist?
	if (input.fail()) {
		cout << "This file does not exist." << endl;
		return;
	}
	else {
		cout << "Opened file successfully." << endl;
		int id;
		string firstname;
		string lastname;
		string color;

		//while loop will continue until reaches the end of the file
		while (input >> id >> firstname >> lastname >> color) {
			Citizen* p = new Citizen(id, firstname, lastname, color);
			citizennames.push_back(p);
			cout << p->getFirstName() << endl;
		}
	}
	//close file
	input.close();
}


//destructor for the city
City::~City() {
	fstream outfile(cityName, ios::out);
	//if the file is open
	if (outfile.is_open()) {

		for (int i = 0; i < citizennames.size(); i++) {
			//read each citizen from the list inside the city
			//before delete the city, store it in the file
			outfile << citizennames[i]->getId() << " "
				<< citizennames[i]->getFirstName() << " "
				<< citizennames[i]->getLastName() << " " 
				<< citizennames[i]->getFavoriteColor() << endl;
			delete citizennames[i];
		}
	}
		//still want to delete the citizen if it doesnt exist
	else
		for (int i = 0; i < citizennames.size(); i++) {
			delete citizennames[i];
		}
}


//get city name function
string City::getCityName() {
	return cityName;
}


//what is the population size for the city?
int City::populationSize() {
	return citizennames.size();
}


//looking for a certain citizen at "index"
Citizen* City::getCitizenAtIndex(int index) {
	//make sure int "index" is within bounds of array
	//array size starts at 0 and ends at populationsize - which is citizennames.size()
	if (index >= 0 && index < citizennames.size()) {
		//return pointer for citizen value
		return citizennames[index];
	}
	//if int "index" is out of bounds of array
	//return NULL, because it is invalid
	return NULL;
}


//pushback/add this citizen to the end of the citizennames vector
void City::addCitizen(Citizen* citizen) {
	Citizen* p = new Citizen(citizen);
	citizennames.push_back(p);
}


//look for the citizien with int id
Citizen* City::getCitizenWithId(int id) {
	//go through list of citizens through all the size of the vector to check if citizen
	//with this id exists - if they do exist, return the citizen at that "i" spot 
	for (int i = 0; i < citizennames.size(); i++) {
		cout << citizennames[i] << endl;
		if (id == citizennames[i]->getId()) {
			return citizennames[i];
		}
	}
		//if the citizen with int id does not exist, return null
		return NULL;
}


//return vector of all citizens with given "color" as favorite color
vector<Citizen*> City::getCitizensForFavoriteColor(string color) {
	//go through size of citizen vector to see if citizen has same color listed
	//if the color matches, return the citizen at that part of the vector citizennames
	//push this back into the vector Citizen*
	vector<Citizen*> favoritecolor;
	for (int k = 0; k < citizennames.size(); k++) {
		if (color == citizennames[k]->getFavoriteColor())
			favoritecolor.push_back(citizennames[k]);
	}
	return favoritecolor;
}
