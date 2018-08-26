#include "Helpers.h"

#include <iostream>

std::string GetUnitOfMeasurementString(const UnitOfMeasurement unit)
{
	std::string unitStr;

	switch (unit)
	{
	case UnitOfMeasurement::Gram:
		unitStr = "g";
		break;
	case UnitOfMeasurement::Microgram:
		unitStr = "micrograms";
		break;
	case UnitOfMeasurement::Milligram:
		unitStr = "mG";
		break;
	case UnitOfMeasurement::Milliter:
		unitStr = "mL";
		break;
	case UnitOfMeasurement::Unit:
		unitStr = "units";
		break;
	default:
		unitStr = "<ERROR: Invalid Unit Of Measurement>";
		break;
	}
	return unitStr;
}

std::string GetTimeOfDayString(const TimeOfDay tod)
{
	std::string todStr;

	switch (tod)
	{
	case TimeOfDay::Any:
		todStr = "Any";
		break;
	case TimeOfDay::Morning:
		todStr = "Morning";
		break;
	case TimeOfDay::Noon:
		todStr = "Noon";
		break;
	case TimeOfDay::Night:
		todStr = "Night";
		break;
	default:
		todStr = "<ERROR: Invalid Time Of Day>";
		break;
	}

	return todStr;
}
