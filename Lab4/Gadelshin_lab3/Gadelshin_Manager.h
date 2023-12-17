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

	vector<int> get_extents(CDC* pDC, int num);

	void draw(CDC* pDC, vector<int> x_coordinates, int& top, int y_height);

	void Serialize(CArchive& ar) override;

	virtual size_t get_teamSize();
	virtual size_t get_expYears();

	virtual void set_teamSize(size_t teamSize);
	virtual void set_expYears(size_t expYears);
};


