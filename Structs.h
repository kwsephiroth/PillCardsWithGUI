#pragma once
#include <stdint.h>
#include <string>
#include "Enums.h"

struct Date
{
	uint8_t month;
	uint8_t day;
	uint16_t year;
};

struct PhoneNumber
{
	uint16_t areaCode;//First 3 digits
	uint16_t prefix;//Middle 3 digits
	uint16_t lineNumber;//Last 4 digits
};

struct SocialSecurityNumber
{
	uint16_t area;//First 3 digits
	uint16_t group;//Middle 2 digits
	uint16_t serial;//Last 4 digits
};

struct PatientInfo
{
	uint64_t id;
	std::string name;
	char sex;
	Date dateOfBirth;
	std::string address;
	SocialSecurityNumber social;
	PhoneNumber phone;
};

struct DrugInfo
{
	using Strength = std::pair<uint32_t, UnitOfMeasurement>;

	uint64_t applNo;
	std::string name;
	Strength strength;
	std::string purpose;
	std::string directions;
	TimeOfDay timeOfDay;
	std::string additionalInfo;
};