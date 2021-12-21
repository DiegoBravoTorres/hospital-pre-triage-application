/*==================================================
OOP Project Milestone #1
==================================================
Name    : Diego Bravo Torres
ID      : 138350202
Email   : dbravo-torres@myseneca.ca
Section : ZAAL */

#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time& Time::setToNow()
	{
		m_min = getTime();
		return *this;
		// TODO: insert return statement here
	}
	Time::Time(unsigned int min)
	{
		m_min = min;

		
	}
	std::ostream& Time::write(std::ostream& ostr) const
	{
		{
			int h = m_min / 60;
			int mins = m_min % 60;
			ostr.fill('0'); 
			ostr.width(2); 
			ostr << h << ":"; 
			ostr.fill('0'); 
			ostr.width(2); 
			ostr << mins; 


			return ostr; }
		// TODO: insert return statement here
	}


	

	std::istream& Time::read(std::istream& istr)
	{
		int mins = 0; 
		int hours = 0; 
		char delimiter = '\0'; 
		istr >> hours; 
		istr >> delimiter; 
		if (delimiter == ':' && hours >= 0 ) {
			istr >> mins; 
			if (mins >= 0) {
				m_min = hours * 60 + mins;
			}
			else {
				istr.setstate(ios::failbit);
			}
		}
		else {

			istr.setstate(ios::failbit);
		} return istr;
	};

	Time& Time::operator-=(const Time& D)
	{
		if ((unsigned)int(D) > m_min) {
			m_min += 24 * 60; 
		}

		m_min -= D.m_min;

		return *this;
	};


	Time Time::operator-(const Time& D) const
	{
		{ 
			Time M = *this;
			if ((unsigned)int(D) > m_min) {
				M += 24 * 60;
			}
			M -= D.m_min;

			return M;
		} 
		//return Time();
	}
	Time& Time::operator+=(const Time& D)
	{

		m_min += D.m_min;

		return *this;
		// TODO: insert return statement here
	}
	Time Time::operator+(const Time& D) const
	{
		Time M;
		M.m_min = m_min + D.m_min;
		return M;
	}
	Time& Time::operator=(unsigned int val)
	{

		m_min = val;
		return *this;

		// TODO: insert return statement here
	}
	Time& Time::operator*=(unsigned int val)
	{
		m_min *= val;
		return *this;
		// TODO: insert return statement here
	}
	Time& Time::operator/=(unsigned int val)
	{
		m_min = m_min / val;
		return *this;
		// TODO: insert return statement here
	}
	Time Time::operator*(unsigned int val) const
	{
		/*Time A;
		A.m_min = A.m_min *  val;
		return A;*/

		Time A = *this; 
		A = m_min * val; 
		return A;

	}
	Time Time::operator/(unsigned int val) const
	{
		Time A = *this; 
		A.m_min = m_min / val; 
		return A;
	};
	Time::operator unsigned int() const
	{
		return m_min;;
	}
	Time::operator int() const
	{
		return m_min;
	}
	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		D.write(ostr);
		return ostr;
		// TODO: insert return statement here
	}
	std::istream& operator>>(std::istream& istr, Time& D)
	{
		D.read(istr);
		return istr;
		// TODO: insert return statement here
	}
}