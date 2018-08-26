#include "PillCard.h"

std::ostream& operator<< (std::ostream& os, const PillCard& pc)
{
	os << "---------------\n"
		<< "|  Pill Card  |\n"
		<< "---------------\n"
		<< "\n";

	for (auto it = pc.m_drugs.begin(); it != pc.m_drugs.end(); ++it)
	{
		std::cout << *it->second << std::endl;
	}
	os << "---------------\n";
	return os;
}

PillCard::PillCard(PillCard&& other)
{
	for (auto itr = other.m_drugs.begin(); itr != other.m_drugs.end(); ++itr)
	{
		this->m_drugs.emplace(itr->first, move(itr->second));
	}

	other.m_drugs.clear();
}


void PillCard::AddDrug(Drug&& d)
{
	this->m_drugs.emplace(d.GetApplNo(), std::make_unique<Drug>(d));
}

PillCard& PillCard::operator=(PillCard&& other)
{
	if (this != &other)
	{
		for (auto itr = other.m_drugs.begin(); itr != other.m_drugs.end(); ++itr)
		{
			this->m_drugs.emplace(itr->first, move(itr->second));
		}

		other.m_drugs.clear();
	}
	return *this;
}