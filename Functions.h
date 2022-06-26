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
namespace functions {

/**
 * @fn bool isNumber(std::string number)
 * �berpr�ft ob der eingegebene string eine Zahl ist.
 * Gibt true wieder wenn wahr and false wenn falsch.
 * @param std::string number
 * string welcher �berpr�ft werden soll.
 */
bool isNumber(std::string number);

/**
 * @fn int eingabe(int o, std::string CC)
 * �berpr�ft ob der eingegebene string innerhalb der oberen Grennze und 0 liegt.
 * Gibt true wieder wenn wahr and false wenn falsch.
 * @param int o
 * Obere Grenze
 * @param std::string CC
 * string welcher �berpr�ft werden soll.
 */
int eingabe(int o, std::string CC);

/**
 * @fn bool isInt(float numberIn)
 * �berpr�ft ob der eingegebene string ein int ist.
 * Gibt true wieder wenn wahr and false wenn falsch.
 * @param std::string numberIn
 * string welcher �berpr�ft werden soll.
 */
bool isInt(float numberIn);

/**
 * @fn bool isPositive(std::string numberIn)
 * �berpr�ft ob der eingegebene string eine posetive Zahl ist.
 * Gibt true wieder wenn wahr and false wenn falsch.
 * @param std::string numberIn
 * string welcher �berpr�ft werden soll.
 */
bool isPositive(std::string numberIn);


/**
 * @fn bool saveSupplier(std::string filename, std::string spacer, std::vector<Supplier> sup)
 * Speichert ein vector vom typ Supplier in einer csv datei.
 * Gibt true wieder wenn wahr and false wenn falsch.
 * @param std::string filename
 * dateiname
 * @param std::string spacer
 * spacer ( in csv am besten ";" )
 * @param std::vector<Supplier> sup
 * Kopie des vector mit den Supplier
 */
bool saveSupplier(std::string filename, std::string spacer, std::vector<Supplier> sup);

/**
 * @fn bool saveSupplier(std::string filename, std::string spacer, std::vector<Supplier> sup)
 * Speichert ein vector vom typ Supplier in einer csv datei.
 * Gibt true wieder wenn erfolgreich and false wenn nicht.
 * @param std::string filename
 * dateiname
 * @param std::string spacer
 * spacer ( in csv am besten ";" )
 * @param std::vector<Supplier> &sup
 * Refnerz des vector mit in welchem die Supplier gespeichert werden sollen
 */
bool readSupplier(std::string filename, std::string spacer, std::vector<Supplier> &suppliers);

/**
 * @fn std::vector<float> makeAlloyMix(std::vector<std::string> namesIn,Alloy& wantedIn)
 * gibt die Ver�ltnisse der gegebenen Legierung als Vector mit der Postions im Verglich zu der Pos. der gebenen Namen
 * der gesuchten Legierung wieder und entfernt die ben�tigte Menge aus dem Lager
 * @param namesIn
 * ein Vector mit den Namen der gegebenen Legierungen
 * @param  wantedIn
 * eine Referenz der gew�nschten Legierung
 */
std::vector<float> makeAlloyMix(std::vector<Alloy> alloyIn, Alloy &wantedIn);
//std::vector<float> makeAlloyMixLager(Storage &Lager, Alloy &wantedIn);
}

#endif /* FUNCTIONS_H_ */
