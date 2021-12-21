/*==================================================
OOP Project Milestone #2
==================================================
Name    : Diego Bravo Torres
ID      : 138350202
Email   : dbravo-torres@myseneca.ca
Section : ZAAL */



#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <stdio.h>
#include<fstream>
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds {

	class IOAble
	{

	public:
		virtual ostream& csvWrite(ostream&) const = 0;

		virtual istream& csvRead(istream&) = 0;

		virtual ostream& write(ostream&) const = 0;
		virtual istream& read(istream&)= 0;

		virtual ~IOAble();
	};


	ostream& operator<<(ostream&, IOAble&);
	istream& operator>>(istream&, IOAble&);


};

#endif

// SDDS_IOABLE_H

