/*==================================================
OOP Project Milestone #4
==================================================
Name    : Diego Bravo Torres
ID      : 138350202
Email   : dbravo-torres@myseneca.ca
Section : ZAAL */

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include "Patient.h"

namespace sdds {
	class CovidPatient : public Patient {

	public:
		CovidPatient();
		virtual char type() const;

		virtual istream& csvRead(istream& is);
		virtual ostream& write(ostream& os)const;
		virtual istream& read(istream& is);


	};

}
#endif // !SDDS_COVIDPATIENT_H_