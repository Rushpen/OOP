#pragma once

#include "Gadelshin_Employee.h"
#include "class_info.h"

class Gadelshin_Manager : public Gadelshin_Employee
{
private:
	unsigned int teamSize = 0;
	unsigned int expYears = 0;
public:
	DECLARE_SERIAL(Gadelshin_Manager)
	Gadelshin_Manager() {};
	virtual ~Gadelshin_Manager() = default;
	void to_class_info(class_info& ci);
	void from_class_info(class_info& ci);
	void Serialize(CArchive& ar) override;
};
