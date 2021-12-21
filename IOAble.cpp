/*==================================================
OOP Project Milestone #2
==================================================
Name    : Diego Bravo Torres
ID      : 138350202
Email   : dbravo-torres@myseneca.ca
Section : ZAAL */



#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "utils.h"
#include <cstring>
#include <iostream>
#include "IOAble.h"

using namespace std;
namespace sdds
{
	std::ostream& IOAble::csvWrite(std::ostream& os) const
	{
		return os;
	}

	std::istream& IOAble::csvRead(std::istream& is) 
	{
		return is;
	}

	std::ostream& IOAble::write(std::ostream& os) const
	{

		return os;
		// TODO: insert return statement here
	}

	std::istream& IOAble::read(std::istream& is)
	{

		return is;
		// TODO: insert return statement here
	}

	IOAble::~IOAble()
	{


	}


	ostream& operator<<( ostream& os, IOAble& object)
	{
		return object.write(os);
		//return object;
	}

	istream& operator>>( istream& is, IOAble& object)
	{

		return object.read(is);

		//return object;
	}

}



