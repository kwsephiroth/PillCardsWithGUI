#pragma once
#include "Drug.h"
#include "Enums.h"
#include "Helpers.h"
#include "Structs.h"
#include "PillCard.h"
#include <string>
#include <stdint.h>
#include <memory>

class Patient
{
private:
	//uint64_t m_id;
	//string m_name;
	//char m_sex;
	//Date m_dateOfBirth;
	//string m_address;
	//uint64_t m_social;
	//string m_phone;//TODO: Create struct of integers for phone number??

	PatientInfo m_patientInfo{ 0, "BLANK", ' ',{0,0,0},"", {0,0,0}, {0,0,0} };
	std::unique_ptr<PillCard> m_pillCard = nullptr;

public:
    Patient(const PatientInfo info, PillCard&& card) : m_patientInfo(info), m_pillCard(std::make_unique<PillCard>(std::forward<PillCard>(card))) {}
    Patient(const PatientInfo info) : m_patientInfo(info){}
	Patient()=default;//TODO: Default constructor for creating a blank patient. Should I keep this?
	~Patient()=default;

	//Disable copying
	Patient(const Patient&) = delete;
	Patient& operator=(const Patient&) = delete;

	//Move constructor and assignment operator
	Patient(Patient&&);
	Patient& operator=(Patient&&);

	//Getters
	uint64_t GetId() const { return this->m_patientInfo.id; }
	std::string GetName() const { return this->m_patientInfo.name; }
	char GetSex() const { return this->m_patientInfo.sex; }
	Date GetDateOfBirth() const { return this->m_patientInfo.dateOfBirth; }
	std::string GetAddress() const { return this->m_patientInfo.address; }
	SocialSecurityNumber GetSocial() const { return this->m_patientInfo.social; }
	PhoneNumber GetPhone() const { return this->m_patientInfo.phone; }
	const PillCard& GetPillCard() const { return *this->m_pillCard; }//TODO: Handle case where the pill card pointer is null
	bool IsBlank() const;
	//static const Patient BLANK;

	friend std::ostream& operator<< (std::ostream& os, const Patient& p);
};

