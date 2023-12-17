#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Employee
{
private:
	string firstname;
	string secondname;
	long long phone_number;
	string login;
	string position;
public:
	Employee();
	int id;
	//long long get_number() { return phone_number; }
	void print_info();
	friend istream& operator>>(istream& input, Employee& emp);
	friend ifstream& operator>>(ifstream& input, Employee& employee);
	friend ofstream& operator<<(ofstream& output, Employee& employee);
	void from_file(string filename);
};

