/*==================================================
OOP Project Milestone #4
==================================================
Name    : Diego Bravo Torres
ID      : 138350202
Email   : dbravo-torres@myseneca.ca
Section : ZAAL */

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include "TriagePatient.h"
#include "utils.h"
#include <string>
using namespace std;


#include "TriagePatient.h"
namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient(): Patient(nextTriageTicket)
   {
	   m_symptoms = nullptr;
	  // Patient(nextTriageTicket);
	   nextTriageTicket ++;

   }

   char TriagePatient::type() const
   {
	   return 'T';
   }

   ostream& TriagePatient::csvWrite(ostream& os) const
   {
	   Patient::csvWrite(os);
	   os << ",";
	   os << m_symptoms;

	   return os;
	   // TODO: insert return statement here
   }

   istream& TriagePatient::csvRead(istream& is)
   {
	   

	   delete[] m_symptoms;
	   m_symptoms = nullptr;
	   Patient::csvRead(is);
	   is.ignore(1000, ',');

	   char str[100];
	   is.get(str, 100, '\n');
	   m_symptoms = new char[strlen(str) + 1];

	   strcpy(m_symptoms, str);
	   nextTriageTicket = (number()) + 1;

	   return is;

	   // TODO: insert return statement here
   }

   ostream& TriagePatient::write(ostream& os) const
   {
	   if (fileIO()) {
		   Patient::csvWrite(os);
		   os << "," << m_symptoms;
	   }
	   else {
		   os << "TRIAGE" << endl;
		   Patient::write(os) << endl;
		   os << "Symptoms: " << m_symptoms << endl;

	   }

	   return os;

	   // TODO: insert return statement here
   }

   istream& TriagePatient::read(istream& is)
   {

	   if (fileIO())
	   {
		   csvRead(is);
	   }
	   else
	   {
		   delete[] m_symptoms;
		   m_symptoms = nullptr;
		   Patient::read(is);
		   m_symptoms = getcstr("Symptoms: ", is, '\n');
	   }
	   return is;
   
	   // TODO: insert return statement here
   }

   TriagePatient::~TriagePatient()
   {
	   delete[] m_symptoms;

   }

}