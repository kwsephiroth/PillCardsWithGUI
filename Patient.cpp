#include "Patient.h"

std::ostream& operator<< (std::ostream& os, const Patient& p)
{
	os << "Patient Name: " << p.m_patientInfo.name << "\n"
		<< "Sex: " << p.m_patientInfo.sex << "\n"
		<< "Date Of Birth: " << (short)p.m_patientInfo.dateOfBirth.month << "/" << (short)p.m_patientInfo.dateOfBirth.day << "/" << p.m_patientInfo.dateOfBirth.year << "\n"
		<< "Social: " << p.m_patientInfo.social.area << "-" << p.m_patientInfo.social.group << "-" << p.m_patientInfo.social.serial << "\n"
		<< "Identification: " << p.m_patientInfo.id << "\n"
		<< "Address: " << p.m_patientInfo.address << "\n"
		<< "Phone: (" << p.m_patientInfo.phone.areaCode << ") " << p.m_patientInfo.phone.prefix << " - " << p.m_patientInfo.phone.lineNumber <<  "\n\n";
		if(p.m_pillCard)
			os << *p.m_pillCard;

	return os;
}

Patient::Patient(Patient&& other)//Move constructor
{
	this->m_patientInfo.id = other.m_patientInfo.id;
	this->m_pillCard = move(other.m_pillCard);
	this->m_patientInfo.name = other.m_patientInfo.name;
	this->m_patientInfo.sex = other.m_patientInfo.sex;
	this->m_patientInfo.dateOfBirth = other.m_patientInfo.dateOfBirth;
	this->m_patientInfo.address = other.m_patientInfo.address;
	this->m_patientInfo.social = other.m_patientInfo.social;
	this->m_patientInfo.phone = other.m_patientInfo.phone;

	other.m_pillCard = nullptr;
	other.m_patientInfo.name = "";
	other.m_patientInfo.sex = '\0';
	other.m_patientInfo.dateOfBirth.day = 0; other.m_patientInfo.dateOfBirth.month = 0; other.m_patientInfo.dateOfBirth.year = 0;
	other.m_patientInfo.social = { 0,0,0 };
	other.m_patientInfo.id = 0;
	other.m_patientInfo.phone = { 0,0,0 };
	other.m_patientInfo.address = "";
}

Patient& Patient::operator=(Patient&& other)//Move assignment operator
{
	if (this != &other)//Not copying from same object pointers
	{
		this->m_patientInfo.id = other.m_patientInfo.id;
		this->m_pillCard = move(other.m_pillCard);
		this->m_patientInfo.name = other.m_patientInfo.name;
		this->m_patientInfo.sex = other.m_patientInfo.sex;
		this->m_patientInfo.dateOfBirth = other.m_patientInfo.dateOfBirth;
		this->m_patientInfo.address = other.m_patientInfo.address;
		this->m_patientInfo.social = other.m_patientInfo.social;
		this->m_patientInfo.phone = other.m_patientInfo.phone;

		other.m_pillCard = nullptr;
		other.m_patientInfo.name = "";
		other.m_patientInfo.sex = '\0';
		other.m_patientInfo.dateOfBirth.day = 0; other.m_patientInfo.dateOfBirth.month = 0; other.m_patientInfo.dateOfBirth.year = 0;
		other.m_patientInfo.social = { 0,0,0 };
		other.m_patientInfo.id = 0;
		other.m_patientInfo.phone = { 0,0,0 };
		other.m_patientInfo.address = "";
	}
	return *this;
}

bool Patient::IsBlank() const
{
	if (this->m_patientInfo.id == 0)
		return true;
	else
		return false;
}