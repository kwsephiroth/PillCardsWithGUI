#pragma once
#include "Enums.h"
#include "Helpers.h"
#include "Structs.h"
#include <string>
#include <stdint.h>

class Drug
{
private:
	using Strength = std::pair<uint32_t, UnitOfMeasurement>;

	//uint64_t m_applNo;
	//string m_name;
	//Strength m_strength = make_pair<uint32_t, UnitOfMeasurement>(0, UnitOfMeasurement::Milligram);
	//string m_purpose;
	//string m_directions;
	//TimeOfDay m_timeOfDay;
	//string m_additionalInfo;

	DrugInfo m_drugInfo;

public:
	/*Drug(uint64_t applNo,
		string name,
		Strength strength,
		string purpose,
		string directions,
		TimeOfDay timeOfDay,
		string additionalInfo = "")
	{
		m_applNo = applNo;
		m_name = name;
		m_strength = strength;
		m_purpose = purpose;
		m_directions = directions;
		m_timeOfDay = timeOfDay;
		m_additionalInfo = additionalInfo;
	}*/
	Drug(DrugInfo&& info) : m_drugInfo(std::move(info)) {}
	//Drug()=default;
	~Drug()=default;

	uint64_t GetApplNo() const { return this->m_drugInfo.applNo; }
	std::string GetName() const { return this->m_drugInfo.name; }
	Strength GetStrength() const { return this->m_drugInfo.strength; }
	std::string GetPurpose() const { return this->m_drugInfo.purpose; }
	std::string GetDirections() const { return this->m_drugInfo.directions; }
	TimeOfDay GetTimeOfDay() const { return this->m_drugInfo.timeOfDay; }
	std::string GetAdditionalInfo() const { return this->m_drugInfo.additionalInfo; }

	friend std::ostream& operator<< (std::ostream& os, const Drug& pc);
};