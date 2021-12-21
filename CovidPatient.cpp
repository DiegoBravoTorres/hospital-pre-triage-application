#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
/*==================================================
OOP Project Milestone #4
==================================================
Name    : Diego Bravo Torres
ID      : 138350202
Email   : dbravo-torres@myseneca.ca
Section : ZAAL */

#include "CovidPatient.h"
namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient():Patient(nextCovidTicket)
   {
	   nextCovidTicket++;

   }

   char CovidPatient::type() const
   {
	   return 'C';
   }

   istream& CovidPatient::csvRead(istream& is)
   {
	   Patient::csvRead(is);
	   nextCovidTicket = (number()) + 1;
	   is.ignore(1000, '\n');
	   return is;

	   // TODO: insert return statement here
   }

   ostream& CovidPatient::write(ostream& os) const
   {
	   if (fileIO()) {
		   Patient::csvWrite(os);
	   }
	   else {
		   os << "COVID TEST" << endl;
		   Patient::write(os);
		   os << endl;
	   }

	  // Patient::write(os);
	 

	   return os;

	   // TODO: insert return statement here
   }

   istream& CovidPatient::read(istream& is)
   {
	   if (fileIO()){
		   csvRead(is);
	   }
	   else
		   Patient::read(is);

	   return is;
	   // TODO: insert return statement here
   }

}