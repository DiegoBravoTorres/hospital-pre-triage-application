/*==================================================
OOP Project Milestone #3
==================================================
Name    : Diego Bravo Torres
ID      : 138350202
Email   : dbravo-torres@myseneca.ca
Section : ZAAL */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Patient.h"
#include "Ticket.h"
#include "utils.h"


namespace sdds {
	Patient::Patient(int ticketNumber, bool IOFlag): m_ticket(ticketNumber)
	{
		m_name = nullptr;
		m_ohip_num = 0;
		m_IO_flag = IOFlag;

	}

	Patient::~Patient()
	{
		delete[] m_name;
		m_name = nullptr;


	}
	char Patient::type() const
	{
		char c = 'W';
		return c;
	}
	bool Patient::fileIO() const
	{
		return m_IO_flag;
	}
	void Patient::fileIO(bool flag)
	{
		m_IO_flag = flag;

	}

	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();

	}

	Patient::operator Time() const
	{
		return Time(m_ticket);
	}

	int Patient::number() const
	{
		return m_ticket.number();
	}

	ostream& Patient::csvWrite(ostream& os) const
	{

		os << type() << "," << m_name << "," << m_ohip_num << ",";
		m_ticket.csvWrite(os);
		return os;

		// TODO: insert return statement here
	}

	istream& Patient::csvRead(istream& is)
	{
		string name;
		getline(is, name, ',');
		delete[] m_name;
		m_name = nullptr;
		m_name = new char[strlen(name.c_str()) + 1];
		strcpy(m_name, name.c_str());
		is >> m_ohip_num;
		is.ignore(1000, ',');
		m_ticket.csvRead(is);
		return is;

		// TODO: insert return statement here
	}

	ostream& Patient::write(ostream& os) const
	{
		int x = 0;
		m_ticket.write(os);
		os << endl;
		if (strlen(m_name) > 25)
		{
			for (x = 0; x < 25; x++)
			{
				os << m_name[x];
			}
		}
		else
		{
			os << m_name;
		}
		os << ", OHIP: " << m_ohip_num;
		return os;
		// TODO: insert return statement here
	}

	istream& Patient::read(istream& is)
	{
		string name;
		int num=0;
		cout << "Name: ";
		getline(is, name, '\n');
		delete[] m_name;
		m_name = nullptr;
		m_name = new char[strlen(name.c_str()) + 1];
		strcpy(m_name, name.c_str());
		cout << "OHIP: ";
		num = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ", true);
		m_ohip_num = num;
		

		return is;
		// TODO: insert return statement here
	}



	bool operator==(const Patient& p, char c)
	{
		bool rtn = true;

		if (c == p.type())
		{
			rtn = true;
		}
		else
			rtn = false;

		return rtn;
	}
	bool operator==(const Patient& p1, const Patient& p2)
	{
		bool rtn = true;

		if (p1.type() == p2.type())
		{
			rtn = true;
		}
		else
			rtn = false;

		return rtn;
	}
};
