/*
 * functions.h
 *
 *  Created on: 08.06.2022
 *      Author: Aaron
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include "Data.h"
#include "Classes.h"
//namespace f�r unsere Funktionen damit wir die nicht in der Main datei haben m�ssen. bsp im code functions::Funktionsname
//Funktionen werden hier einmal eingetragen wie man an readSupplierFile sehen kann und die Richtige funktion wird dann wie readSupplierFile auch in functions.cpp
//im namespace noch mal definiert aber diesmal mit dem code
namespace functions{
std::vector<Supplier> readSupplierFile(std::string filename, std::string spacer);
bool isNumber(std::string number);
}



#endif /* FUNCTIONS_H_ */