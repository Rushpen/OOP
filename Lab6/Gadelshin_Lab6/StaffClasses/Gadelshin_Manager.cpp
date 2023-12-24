#include "pch.h"
#include "Gadelshin_Manager.h"

IMPLEMENT_SERIAL(Gadelshin_Manager, Gadelshin_Employee, VERSIONABLE_SCHEMA | 0)


void Gadelshin_Manager::Serialize(CArchive& ar) {

    Gadelshin_Employee::Serialize(ar);

    if (ar.IsStoring()) {
        ar << teamSize
            << expYears;
    }
    else {
        ar >> teamSize
        >> expYears;
    }
}

void Gadelshin_Manager::to_class_info(class_info& ci) {
    Gadelshin_Employee::to_class_info(ci);
    ci.is_base_class = 0;
    ci.teamSize = teamSize;
    ci.expYears = expYears;
}

void  Gadelshin_Manager::from_class_info(class_info& ci) {

    Gadelshin_Employee::from_class_info(ci);
    teamSize = ci.teamSize;
    expYears = ci.expYears;
}
