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

using namespace std;
namespace sdds
{
	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		m_text = nullptr;
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);
		m_noOfSel = NoOfSelections;
	}
	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}
	
	Menu::Menu(const Menu& cpy)
	{
		m_text = nullptr;
		m_text = new char[strlen(cpy.m_text) + 1];
		strcpy(m_text, cpy.m_text);
		m_noOfSel = cpy.m_noOfSel;
	}

	void Menu::display()const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	} 
	
	int& Menu::operator>>(int& Selection)
	{
		int input;
		display();
		input = getInt(0, m_noOfSel, "> ", "Invalid option	");
		Selection = input;
		return Selection;
	}

}




//#define _CRT_SECURE_NO_WARNINGS 
//#include "utils.h" 
//#include "Menu.h" 
//#include <iostream> 
//#include <string> 
//#include <cstring> 
//
//using namespace std;
//namespace sdds {
//
//
//	Menu::Menu() {
//		m_noOfSel = 0; 
//		m_text = nullptr;
//	}
//
//	void Menu::display() const
//	{
//		cout << m_text << endl;
//		cout << "0 - Exit" << endl;
//
//
//	}
//	Menu::Menu(const char* MenuContent, int NoOfSelections)
//	{
//
//		m_text = new char[strlen(MenuContent) + 1];
//		strcpy(m_text, MenuContent);
//		m_noOfSel = NoOfSelections;
//
//
//	}
//
//	 Menu:: ~Menu()
//	{	
//	//	delete[] m_text;
//	    m_text = nullptr;	
//	
//	}
//
//	int& Menu::operator>>(int& Selection)
//	{
//
//		display();
//		Selection = getInt(0, 3, "> ", "Invalid option [0 <= value <= 3]: ", false);
//		
//		return Selection;
//		// TODO: insert return statement here
//	}
//
//
//};