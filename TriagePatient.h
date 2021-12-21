/*==================================================
OOP Project Milestone #4
==================================================
Name    : Diego Bravo Torres
ID      : 138350202
Email   : dbravo-torres@myseneca.ca
Section : ZAAL */

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"

namespace sdds {
	class TriagePatient : public Patient {
		char* m_symptoms;
	public:
		TriagePatient();
		virtual char type() const;
		virtual ostream& csvWrite(ostream& os) const;
		virtual istream& csvRead(istream& is);
		virtual ostream& write(ostream& os)const;
		virtual istream& read(istream& is);
		virtual ~TriagePatient();

	};
}
#endif // !SDDS_TRIAGEPATIENT_H


