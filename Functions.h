/*
 * functions.h
 *
 *  Created on: 08.06.2022
 *      Author: Aaron
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <iostream>
//namespace fuer unsere Funktionen damit wir die nicht in der Main datei haben muessen. bsp im code functions::Funktionsname
//Funktionen werden hier einmal eingetragen wie man an readSupplierFile sehen kann und die Richtige funktion wird dann wie readSupplierFile auch in functions.cpp
//im namespace noch mal definiert aber diesmal mit dem code
namespace functions {

/**
 * @fn bool isNumber(std::string number)
 * ueberprueft ob der eingegebene string eine Zahl ist.
 * @param number
 * string welcher ueberprueft werden soll.
 * @return
 * Gibt true or false wieder.
 */
bool isNumber(std::string number);

/**
 * @fn int eingabe(int o, std::string CC)
 * ueberprueft ob der eingegebene string innerhalb der oberen Grennze und 0 liegt.
 * @param o
 * Obere Grenze
 * @param CC
 * string welcher ueberprueft werden soll.
 * @return
 * Gibt true or false wieder.
 */
int eingabe(int o, std::string CC);

/**
 * @fn bool isInt(float numberIn)
 * ueberprueft ob der eingegebene string ein int ist.
 * @param numberIn
 * string welcher ueberprueft werden soll.
 * @return
 * Gibt true or false wieder.
 */
bool isInt(float numberIn);

/**
 * @fn bool isPositive(std::string numberIn)
 * ueberprueft ob der eingegebene string eine posetive Zahl ist.
 * @param numberIn
 * string welcher ueberprueft werden soll.
 * @return
 * Gibt true or false wieder.
 */
bool isPositive(std::string numberIn);

/**
 * @fn bool isValidZip(std::string zipIn)
 * ueberprueft ob der eingegebene string eine Postleitzahl ist.
 * @param numberIn
 * string welcher ueberprueft werden soll.
 * @return
 * Gibt true or false wieder.
 */
bool isValidZip(std::string zipIn);

/**
 * @fn bool clampFloat(float a, float b, float e)
 * ueberprueft zwei floats auf gleicheit mit begrenzter Nachkommastelle z.B das 1.0000000001 = 1.00000000
 * @param a
 * nummer 1
 * @param b
 * nummer 2
 * @param e
 * Nachkommastelle limit.
 * @return
 * Gibt true or false wieder.
 */
bool clampFloat(float a, float b, float e);
}

#endif /* FUNCTIONS_H_ */
