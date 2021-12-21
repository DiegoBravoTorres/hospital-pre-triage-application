/*==================================================
OOP Project Milestone #1
==================================================
Name    : Diego Bravo Torres
ID      : 138350202
Email   : dbravo-torres@myseneca.ca
Section : ZAAL */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }


   int getInt(const char* prompt)
   {
       bool flag = true;
       int rtn;
       char secondValue;

       if (prompt != nullptr) {
           cout << prompt;
       };
       
      do  {

        rtn = 0;
        
       
       cin >> rtn;
       cin.get(secondValue);
  

           if (cin.fail()) {
               
               cin.clear();
               cin.ignore(142, '\n');
               
               cout << "Bad integer value, try again: ";
              
               flag = false;
           }
           else if (secondValue != '\n') {

               cin.clear();
               cin.ignore(142, '\n');
               cout << "Enter only an integer, try again: ";
               flag = false;

           }
           else {
               flag = true;
           }
         //  cout.clear();
               

      } while (!flag);
 
       return rtn;
   }


   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
   {
       bool flag = true;
       int rtn;
       char secondValue;

       if (prompt != nullptr) {
           cout << prompt;
       };

       do {

           rtn = 0;
           cin >> rtn;
           cin.get(secondValue);


          


           if (cin.fail()) {

               cin.clear();
               cin.ignore(142, '\n');

               cout << "Bad integer value, try again: ";

               flag = false;
           }
           else if (secondValue != '\n') {

               cin.clear();
               cin.ignore(142, '\n');
               cout << "Enter only an integer, try again: ";
               flag = false;

           }
           else if (rtn < min || rtn > max) {

               cin.clear();
               if (showRangeAtError) {

                   cout << errorMessage <<"[" << min <<" <= value <= " << max << "]: ";

               }else
               if (errorMessage != nullptr) cout << errorMessage;

               flag = false;

           } else  {
               flag = true;
           }
           //  cout.clear();


       } while (!flag);

       return rtn;

  
   }
   char* getcstr(const char* prompt, std::istream& istr, char delimiter)
   {
       char* allocation = new char[1]; ;
       char oneCharacter  = 0;
       int index = 0;
       int size = 1;
       bool flag = true;

       if (prompt != nullptr) {
           cout << prompt;
       }

   
      

       do {
           istr.get(oneCharacter);
           if (oneCharacter == delimiter) {
               flag= false;
           } 
           
           if (!(index + 1 < size) && flag) {
               int newSize; 
               char* temp; 
               newSize = size * 2; 
               temp = new char[newSize]; 
               memcpy(temp, allocation, size); 
               delete[] allocation; 
               allocation = temp; 
               size = newSize;
           } allocation[index++] = oneCharacter;
       } while (flag); 

     
       allocation[index-1] = '\0'; 
       
       return allocation;
   }

    //   oneCharacterar* value =0;
    //  // char* rtn;

    //   if (prompt != nullptr) {
    //       cout << prompt ;
    //   }

    //  // strlen(istr.read()) 

    //  // getline(istr, value, delimit);

    // //  istr >> value;

    //   char* rtn = new char[strlen(value) +1];

    ////   istr.read(rtn, strlen(value) + 1);

    //   strcpy(rtn, value);

    //   return rtn ;
   }
