#include "Gadelshin_Manager.h"
#include "Gadelshin_Employee.h"

IMPLEMENT_SERIAL(Gadelshin_Manager, Gadelshin_Employee, VERSIONABLE_SCHEMA | 0)

Gadelshin_Manager::Gadelshin_Manager() {
	teamSize = 0;
	expYears = 0;
}

bool isValidTeamSize(int teamSize) {
	return (teamSize > 0 && teamSize < 11);
}

int getValidTeamSize() {
	int team;
	while (((cin >> team).fail()) || (cin.peek() != '\n') || !isValidTeamSize(team)) {
		cout << "Please input the correct number of subordinate employees(>0 and < 11): " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return team;
}

bool isValidExp(int expYears) {
	return (expYears > 3 && expYears < 20);
}

int getValidExp() {
	int exp;
	while (((cin >> exp).fail()) || (cin.peek() != '\n') || !isValidExp(exp)) {
		cout << "Enter the correct number of years of work as a manager (>3 and <20): " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return exp;
}

void Gadelshin_Manager::init_employee() {
	Gadelshin_Employee::init_employee();
	cout << "Input number of employees subordinate to the manager: " << "\n";
	teamSize = getValidTeamSize();
	cout << "Input number of years as a manager: " << "\n";
	expYears = getValidExp();
}

void Gadelshin_Manager::print_info() {
	Gadelshin_Employee::print_info();
	cout << "Size of team: " << teamSize <<" persons" << "\nNumber of exp years: " << expYears << " years" << "\n";
}

void Gadelshin_Manager::Serialize(CArchive& ar) {
	Gadelshin_Employee::Serialize(ar);

	if (ar.IsStoring()) {
		ar << teamSize;
		ar << expYears;
	}
	else {
		ar >> teamSize;
		ar >> expYears;
	}
}