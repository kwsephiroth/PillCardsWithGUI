#include "Drug.h"

std::ostream& operator<< (std::ostream& os, const Drug& pc)
{
	os  << "Appl No: " << pc.m_drugInfo.applNo << "\n"
		<< "Drug Name: " << pc.m_drugInfo.name << "\n"
		<< "Strength: " << pc.m_drugInfo.strength.first << " " << GetUnitOfMeasurementString(pc.m_drugInfo.strength.second) << "\n"
		<< "Purpose: " << pc.m_drugInfo.purpose << "\n"
		<< "Directions: " << pc.m_drugInfo.directions << "\n"
		<< "Time Of Day: " << GetTimeOfDayString(pc.m_drugInfo.timeOfDay) << "\n"
		<< "Additional Info: " << pc.m_drugInfo.additionalInfo << "\n";
	return os;
}