/*
 * Menu.h
 *
 *  Created on: 13.06.2022
 *      Author: broelaar
 */

#ifndef MENU_H_
#define MENU_H_

#include "Data.h"
#include "Classes.h"
#include <sstream>
#include <iomanip>
#include <iostream>

namespace menu {

/**
 * @fn void anschriftPflegen(Firm &eigeneFirma)
 * Behandelt die komplette funtkion des anschrift Pflegens.
 * Ausgabe der Anfrage sowie eingabe des Benutzters
 * @param &eigeneFirma
 * eine Refernz unsere Firma in welche die Werte übernommen werden.
 */
void anschriftPflegen(Firm &eigeneFirma);

/**
 * @fn void supplierPlfegen(std::vector<Supplier> &suppliers)
 * Behandelt die komplette funtkion des bearbeiten von den Supplier.
 * Ausgabe der Anfrage sowie eingabe des Benutzters und überprüfung der Werte.
 * @param &suppliers
 * eine Refernz zu unsere Liste von in welche die Werte übernommen werden.
 */
void supplierPlfegen(std::vector<Supplier> &suppliers);

/**
 * @fn void lagerPflegen(Storage &Lager)
 * Behandelt die ausgabe sowie das Löschen aus dem Lager.
 * Ausgabe der Anfrage sowie eingabe des Benutzters und überprüfung der Werte.
 * @param &suppliers
 * eine Referenz zu unserem Lager in welches die Werte übernommen werden.
 */
void lagerPflegen(Storage &Lager);

/**
 * @fn Alloy alloyNewLager(Storage &stor)
 * Behandelt das erstellen einer Neuen Legierung für das Lager, diese Sollte nur für Fehlerbehandlung verwendet werden.
 * Ausgabe der Anfrage sowie eingabe des Benutzters und überprüfung der Werte.
 * @param &stor
 * eine Refernz zu unserem Lager in welches die neue Legierung soll.
 * @return
 * Gibt den erstellten Alloy wieder.
 */
Alloy alloyNewLager(Storage &stor);

/**
 * @fn Alloy alloyNewSupplier()
 * Behandelt das erstellen einer Neuen Legierung für einen Zuliefere. Hier wird z.B Menge ignoriert da diese keine Rolle beim Zuliefere spielt
 * Ausgabe der Anfrage sowie eingabe des Benutzters und überprüfung der Werte.
 * @return
 * Gibt den erstellten Alloy wieder.
 */
Alloy alloyNewSupplier();

/**
 * @fn Supplier supplierNew(Alloy alloyIn)
 * Behandelt das erstellen eines neuen Zuliefere.
 * Ausgabe der Anfrage sowie eingabe des Benutzters und überprüfung der Werte.
 * @param alloyIn
 * die Legierung welche dem Zulieferer zugeordnet werden soll.
 * @return
 * Gibt den erstellten Supplier wieder.
 */
Supplier supplierNew(Alloy alloyIn);

/**
 * @fn int bestellung(Storage &Lager, std::vector<Supplier> &sup, Firm firm)
 * Behandelt den Kompletten bestellablauf sowie das inzufügen im Lager.
 * Ausgabe der Anfrage sowie eingabe des Benutzters und überprüfung der Werte.
 * @param &Lager
 * Refernz des Lagers in welchem die Bestellung gelagert werden soll
 * @param &sup
 * Refernz unsere mometanen Zuliefere.
 * @param firm
 * Die eigene Firma welche die Bestellung aufgibt
 * @return
 * 0 = Erfolg
 *-1 = Bestellung abgebrochen
 */
int bestellung(Storage &Lager, std::vector<Supplier> &sup, Firm firm);

/**
 * @fn void ProdProtokoll(std::vector<Alloy> vek, Firm a, Alloy wanted, std::vector<float> mengen)
 * Behandelt den Kompletten bestellablauf sowie das inzufügen im Lager.
 * Ausgabe der Anfrage sowie eingabe des Benutzters und überprüfung der Werte.
 * @param vek
 * Liste der Legierungen welche zur Produktion benutzt wurden
 * @param a
 * Firma welche die Produktion durchgeführt hat
 * @param wanted
 * Die Ziellegierung der Produktion
 * @param mengen
 * Liste der Mengen
 */
void ProdProtokoll(std::vector<Alloy> vek, Firm a, Alloy wanted, std::vector<float> mengen);

/**
 * @fn void produktion(Storage &Lager, std::vector<Supplier> &sup, Firm firm)
 * Behandelt den Kompletten bestellablauf sowie das inzufügen im Lager.
 * Ausgabe der Anfrage sowie eingabe des Benutzters und überprüfung der Werte.
 * @param &Lager
 * Referenz des Lager welches für die Produktion verwendet werden soll.
 * @param &sup
 * Referenz der Zuliefere welche zum Produzieren benutzt.
 * @param &sup
 * Referent der Zuliefere für Bestellungen
 * @param firm
 * Firma welche die Produktion durchführt
 */
void produktion(Storage &Lager, std::vector<Supplier> &sup, Firm firm);

}

#endif /* MENU_H_ */
