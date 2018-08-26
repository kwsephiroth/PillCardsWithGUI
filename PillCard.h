#pragma once
#include "Drug.h"
#include "Enums.h"
#include "Helpers.h"
#include "Structs.h"
#include <string>
#include <stdint.h>
#include <map>
#include <memory>
#include <iostream>

class PillCard
{
private:
	using Drugs = std::map<uint64_t, std::unique_ptr<Drug>>;
	Drugs m_drugs = {};

public:
	PillCard() = default;
	~PillCard() = default;

	//Disable copying
	PillCard(const PillCard&) = delete;
	PillCard& operator=(const PillCard&) = delete;

	//Move constructor and assignment operator
	PillCard(PillCard&&);
	PillCard& operator=(PillCard&&);

	void AddDrug(Drug&&);
	void RemoveDrug(uint64_t);//TODO: Implement way to remove drug from map. Also, determine if application number is even a good key.
	const Drug& GetDrug(uint64_t applNo) const;
	const Drugs& GetDrugList() const { return this->m_drugs; }

	friend std::ostream& operator<< (std::ostream& os, const PillCard& pc);
};
