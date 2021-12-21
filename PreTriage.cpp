/*==================================================
OOP Project Milestone #5
==================================================
Name    : Diego Bravo Torres
ID      : 138350202
Email   : dbravo-torres@myseneca.ca
Section : ZAAL */


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

#include "PreTriage.h"
#include "Time.h"
#include "Patient.h"
#include "Menu.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "IOAble.h"

using namespace std;

namespace sdds {
	PreTriage::PreTriage(const char* dataFilename):m_averCovidWait(15),m_averTriageWait(5),m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit",2),m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage",2)
	{
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();


	}

	PreTriage::~PreTriage()
	{
		ofstream of;
		of.open(m_dataFilename);

		if (of.is_open()) {

			of << m_averCovidWait << "," << m_averTriageWait <<	endl;

			cout << "Saving Average Wait Times," << endl;
			cout << "   COVID Test: ";
			cout << m_averCovidWait << endl;
			cout << "   Triage: ";
			cout << m_averTriageWait << endl;

			cout << "Saving m_lineup..." << endl;

			for (int i = 0; i < m_lineupSize; i++)
			{
				m_lineup[i]->csvWrite(of) << endl;
				cout << (i+1) << "- ";
				m_lineup[i]->csvWrite(cout) << endl;
				delete m_lineup[i];
			}


			//delete[] m_lineup;
			delete[]  m_dataFilename;
			cout << "done!" << endl;

		}


	}




	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		int i, match = 0;
		for (i = 0; i < m_lineupSize; i++) {
			if (m_lineup[i]->type() == p.type()) 
					match++;
		}

		return Time(p) *= match;
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{

		Time Current;
		int ticketNum = p.number();
		Current.setToNow();

		if (p.type() == 'C') {

			m_averCovidWait = ((Current - p.operator sdds::Time()) + (m_averCovidWait *= (ticketNum - 1))) /= ticketNum;

		}
		else {
			m_averTriageWait = ((Current - p.operator sdds::Time()) + (m_averTriageWait *= (ticketNum - 1))) /= ticketNum;
		
		}

	
	}

	void PreTriage::removePatientFromLineup(int index)
	{

		removeDynamicElement(m_lineup,index,m_lineupSize);


	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int returnValue = -1;
		bool keepLooking = true;
		int i = 0;
		for (i = 0; i < m_lineupSize && keepLooking; i++) {

			if (m_lineup[i]->type() == type)
			{
				returnValue = i;
				keepLooking = false;
			}
					

			
		}
		return returnValue;
	}

	void PreTriage::load()
	{
		char ch;
		int i;
		ifstream fin;
		fin.open(m_dataFilename);
		cout << "Loading data..." << endl;
		if (fin)
		{
			fin >> m_averCovidWait;
			fin.ignore(200, ',');
			fin >> m_averTriageWait;
			fin.ignore(200, '\n');
			Patient* p = nullptr;
			for (i = 0; i < maxNoOfPatients && fin; i++)
			{
				ch = 'x';
				fin >> ch;
				fin.ignore(100, ',');
				if (ch == 'C')
				{
					p = new CovidPatient();
				}
				else if (ch == 'T')
				{
					p = new TriagePatient();
				}
				if (p != nullptr)
				{
					p->fileIO(true);
					p->csvRead(fin);
					p->fileIO(false);
					m_lineup[i] = p;
					m_lineupSize++;
					p = nullptr;
				}
			}
		}
		if (fin)
		{
			cout << "Warning: number of records exceeded " <<
				maxNoOfPatients << endl;
			cout << m_lineupSize << " Records imported...\n\n";
		}
		else if (m_lineupSize == 0)
		{
			cout << "No data or bad data file!\n\n";
		}
		else
		{
			cout << m_lineupSize << " Records imported...\n\n";
		}
		
		
		/*
		bool init = true;
		Patient* P = nullptr;
		int i = 0;
		ifstream in;

		char type = 'x';

		in.open(m_dataFilename);
		cout << "Loading data..." << endl;

		if (in) {

			
			in >> m_averCovidWait;
			in.ignore(200, ',');
			in >> m_averTriageWait;
			in.ignore(200, '\n');

			for (i = 0; i < sdds::maxNoOfPatients && in; i++) {

				in >> type;
				in.ignore(200, ',');

				if (type == 'C') {

					P = new CovidPatient;
				}
				else if (type == 'T') {

					P = new TriagePatient;
				
				}
				else {
					init = false;
				}

				if (init) {

					P->fileIO(true);
					P->read(in);
					P->fileIO(false);
					m_lineup[i] = P;
					m_lineupSize++;
				
				}
			}
		}
		if (m_lineupSize >= sdds::maxNoOfPatients)
			cout << "Warning: number of records exceeded "<< sdds::maxNoOfPatients << endl;

		if (m_lineupSize) {
			cout << m_lineupSize << " Records imported..." << endl;
		}
		else
			cout << "No data or bad data file!" << endl << endl;*/


	}


	void PreTriage::reg()
	{
		

		if (m_lineupSize == maxNoOfPatients) {
			cout << "Line up full!" << endl;
		}
		else {
			int option;
			m_pMenu >> option;
			switch (option) {
			case 0:
				break;
			case 1:
				m_lineup[m_lineupSize] = new CovidPatient();
				break;
			case 2:
				m_lineup[m_lineupSize] = new TriagePatient();
				break;
			}

			if (option == 1 || option == 2) {
				m_lineup[m_lineupSize]->setArrivalTime();
				m_lineup[m_lineupSize]->fileIO(false);
				cout << "Please enter patient information: " <<
					endl;
				cin >> *m_lineup[m_lineupSize];
				cout << endl;
				cout << "******************************************"
					<< endl;
				cout << *m_lineup[m_lineupSize];
				cout << "Estimated Wait Time: " <<
					getWaitTime(*m_lineup[m_lineupSize]) << endl;
				cout << "******************************************"
					<< endl << endl;
				m_lineupSize++;
			}
		}



	}

	void PreTriage::admit()
	{

		int option, index = 0;
		char type = '\0';
		m_pMenu >> option;
		switch (option) {
		case 1:
			type = 'C';
			break;
		case 2:
			type = 'T';
			break;
		case 0:
			break;
		}

		if (option == 1 || option == 2) {
			if (indexOfFirstInLine(type) == -1)
			{
				return;
			}
			else {
				index = indexOfFirstInLine(type);
				cout << endl;
				cout << "******************************************" << endl;
				m_lineup[index]->fileIO(false);
				cout << "Calling for ";
				cout << *m_lineup[indexOfFirstInLine(type)];
				cout << "******************************************" << endl << endl;
				setAverageWaitTime(*m_lineup[index]);
				removePatientFromLineup(index);
			}
		}
		
	}


	void PreTriage::run(void)
	{
		int option = 0;

		do {
			m_appMenu >> option;
			if (option != 0) {

				if (option == 1)
					reg();
				if (option == 2)
					admit();
			}
		} while (option != 0);
	}
}