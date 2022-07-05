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
//namespace fuer unsere Funktionen damit wir die nicht in der Main datei haben muessen. bsp im code functions::Funktionsname
//Funktionen werden hier einmal eingetragen wie man an readSupplierFile sehen kann und die Richtige funktion wird dann wie readSupplierFile auch in functions.cpp
//im namespace noch mal definiert aber diesmal mit dem code
namespace functions {

/**
 * @fn bool isNumber(std::string number)
 * ueberprueft ob der eingegebene string eine Zahl ist.
 * Gibt true wieder wenn wahr and false wenn falsch.
 * @param std::string number
 * string welcher ueberprueft werden soll.
 */
bool isNumber(std::string number);

/**
 * @fn int eingabe(int o, std::string CC)
 * ueberprueft ob der eingegebene string innerhalb der oberen Grennze und 0 liegt.
 * Gibt true wieder wenn wahr and false wenn falsch.
 * @param int o
 * Obere Grenze
 * @param std::string CC
 * string welcher ueberprueft werden soll.
 */
int eingabe(int o, std::string CC);

/**
 * @fn bool isInt(float numberIn)
 * ueberprueft ob der eingegebene string ein int ist.
 * Gibt true wieder wenn wahr and false wenn falsch.
 * @param std::string numberIn
 * string welcher ueberprueft werden soll.
 */
bool isInt(float numberIn);

/**
 * @fn bool isPositive(std::string numberIn)
 * ueberprueft ob der eingegebene string eine posetive Zahl ist.
 * Gibt true wieder wenn wahr and false wenn falsch.
 * @param std::string numberIn
 * string welcher ueberprueft werden soll.
 */
bool isPositive(std::string numberIn);

/**
 * @fn bool isValidZip(std::string zipIn)
 * ueberprueft ob der eingegebene string eine Postleitzahl ist.
 * Gibt true wieder wenn wahr and false wenn falsch.
 * @param std::string numberIn
 * string welcher ueberprueft werden soll.
 */
bool isValidZip(std::string zipIn);

/**
 * @fn std::vector<float> makeAlloyMix(std::vector<std::string> namesIn,Alloy& wantedIn)
 * gibt die Verhaeltnisse der gegebenen Legierung als Vector mit der Postions im Verglich zu der Pos. der gebenen Namen
 * der gesuchten Legierung wieder und entfernt die benoetigte Menge aus dem Lager
 * @param namesIn
 * ein Vector mit den Namen der gegebenen Legierungen
 * @param  wantedIn
 * eine Referenz der gewuenschten Legierung
 */
std::vector<float> makeAlloyMix(std::vector<Alloy> alloyIn, Alloy &wantedIn);


/**
 * @fn void html(Supplier Zulieferer,Alloy meineLeg,Order meineBestellung)
 * gibt eine Bestellübersicht als html Datei aus
 * der gesuchten Legierung wieder und entfernt die benoetigte Menge aus dem Lager
 * @param Zulieferer
 * Lieferer der gwünschten Legierung
 * @param  meineLeg
 * die zu bestellende Legierung
 * @param meineBestellung
 * bestellung
 */
void html(Supplier Zulieferer,Alloy meineLeg,Order meineBestellung);
}

#endif /* FUNCTIONS_H_ */
