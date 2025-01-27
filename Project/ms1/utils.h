/* Citation and Sources...
Final Project Milestone 1
Module: utils
Filename: utils.cpp
Version 1.0
Author	Sehajpreet Singh
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/13  Preliminary release
2020/11/13  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
   int getInt();
   int getTime(); // returns the time of day in minutes

   extern bool debug; // this makes bool sdds::debug variable in utils.cpp global to 
                      // all the files which include: "utils.h" 
                      //(you will learn this in detail in oop345)
   
}
#endif // !SDDS_UTILS_H_

