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
//namespace für unsere Funktionen damit wir die nicht in der Main datei haben müssen. bsp im code functions::Funktionsname
//Funktionen werden hier einmal eingetragen wie man an readSupplierFile sehen kann und die Richtige funktion wird dann wie readSupplierFile auch in functions.cpp
//im namespace noch mal definiert aber diesmal mit dem code
namespace functions{
bool isNumber(std::string number);
int eingabe(int o, std::string CC);
bool isInt(float numberIn);
bool saveSupplier(std::string filename, std::string spacer, std::vector<Supplier> sup);
void  anschriftPflegen(Firm& eigeneFirma);
std::vector<Supplier> supplierPlfegen(std::vector<Supplier> suppliers);
}



#endif /* FUNCTIONS_H_ */
