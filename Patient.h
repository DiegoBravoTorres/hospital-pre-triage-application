/*==================================================
OOP Project Milestone #3
==================================================
Name    : Diego Bravo Torres
ID      : 138350202
Email   : dbravo-torres@myseneca.ca
Section : ZAAL */

#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include "IOAble.h"
#include "Ticket.h"

using namespace std;

namespace sdds {
    class Patient : public IOAble
    {
        char* m_name;
        int m_ohip_num;
        Ticket m_ticket;
        bool m_IO_flag;
    public:
        Patient(int ticketNumber = 0, bool IOFlag = false);
       virtual ~Patient();
        Patient(const Patient&) = delete;
        Patient& operator=(const Patient&) = delete;

        virtual char type() const;
        bool fileIO() const;
        void fileIO(bool flag);
        void setArrivalTime();
        operator Time() const;
        int number() const;

        virtual ostream& csvWrite(ostream& os)const ; //const = 0;
        virtual istream& csvRead(istream& is);//= 0;
        virtual ostream& write(ostream& os)const; //const = 0;
        virtual istream& read(istream& is); //= 0;




        


    };

     bool operator==(const Patient& p,char c);
     bool operator==(const Patient& p1, const Patient& p2);


};

#endif // SDDS_PATIENT_H