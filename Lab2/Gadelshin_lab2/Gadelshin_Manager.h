#pragma once
#include "framework.h" 
#include "Gadelshin_Employee.h"

class Gadelshin_Manager : public Gadelshin_Employee
{
private:
	size_t teamSize;
	size_t expYears;

public:
	DECLARE_SERIAL(Gadelshin_Manager)
	Gadelshin_Manager();
	virtual ~Gadelshin_Manager() = default;
	void init_employee() override;
	void print_info() override;
	void Serialize(CArchive& ar) override;
};

