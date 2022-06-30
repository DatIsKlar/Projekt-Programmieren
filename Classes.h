#ifndef CLASSES_H_
#define CLASSES_H_

#include <vector>
#include <string>
#include <armadillo>
#include <fstream>
#include <sstream>
#include "Data.h"
#include <iostream>

class Alloy {
private:
	float copper;
	float zinc;
	float tin;
	std::string name;
	float amount;
public:
	/**
	 * @fn Alloy()
	 * Standart Konstruktor mit leeren Anfangswerten des typen Alloys
	 */
	Alloy();

	/**
	 * @fn Alloy(float copperIn, float zincIn, float tinIn, std::string nameIn,float amountIn)
	 * Konstruktor mit Anfangswerten des typen Alloy
	 * @param float copperIn
	 * Anfangswert von Kuppfer/Copper
	 * @param float zincIn
	 * Anfangswert von Zink/Zinc
	 * @param float tinIn
	 * Anfangswert von Zinn/Tin
	 * @param float nameIn
	 * Setzen vom Namen
	 * @param float amountIn
	 * Anfangswert von der Menge/amount
	 */
	Alloy(float copperIn, float zincIn, float tinIn, std::string nameIn, float amountIn);

	/**
	 *	@fn	float getCopper()
	 *	gibt den Kuppfer/Copper gehalt der Legierung wieder
	 */
	float getCopper();

	/**
	 *	@fn	float getZinc()
	 *	gibt den Zink/Zinc gehalt der Legierung wieder
	 */
	float getZinc();

	/**
	 *	@fn	float getTin()
	 *	gibt den Zinn/Tin gehalt der Legierung wieder
	 */
	float getTin();

	/**
	 *	@fn	std::string getName()
	 *	gibt den Namen der Legierung wieder
	 */
	std::string getName();

	/**
	 *	@fn	float getAmount()
	 *	gibt die Menge der Legierung wieder
	 */
	float getAmount();

	/**
	 *	@fn	setAmount(float ammountIn)
	 *	setzen/ueberschreiben der Menger der Legierung
	 *	@param amountIn
	 *	neuer Wert der Menge;
	 */
	void setAmount(float ammountIn);

	/**
	 *	@fn	operator==(const Alloy &b)
	 *	Vergleicht zwei Legierungen auf gleichheit a == b und gibt wahr oder falsch wieder
	 *	@param b
	 *	Ist der zu vergleichende Alloy
	 */
	bool operator==(const Alloy &b);

	/**
	 *	@fn	operator!=(const Alloy &b)
	 *	Vergleicht zwei Legierungen auf ungleichheit a !=b und gibt wahr oder falsch wieder
	 *	@param b
	 *	Ist der zu vergleichende Alloy
	 */
	bool operator!=(const Alloy &b);

	bool operator%(const Alloy &b);

	void print();
};

class Firm {
private:
	std::string name;
	std::string street;
	std::string zip;
	std::string city;
	std::string comment;
public:
	/**
	 * @fn Firm()
	 * Standart Konstruktor mit leeren Anfangswerten des typen Firm
	 */
	Firm();

	/**
	 * @fn Firm(std::string nameIn, std::string streetIn, std::string zipIn, std::string cityIn, std::string commentIn)
	 * Konstruktor mit Anfangswerten des typen Firm
	 * @param std::string nameIn
	 * Setzen vom Namen
	 * @param std::string streetIn
	 * Setzten der Stra�e
	 * @param std::sring zipIn
	 * Setzten der Postleitzahl
	 * @param std:.string cityIn
	 * Setzten der Stadt
	 * @param std:.string commandIn
	 * Kommentar �ber die Firma
	 */
	Firm(std::string nameIn, std::string streetIn, std::string zipIn, std::string cityIn, std::string commentIn);

	/**
	 * @fn std::string getName()
	 * gibt den Namen der Firma wieder
	 */
	std::string getName();

	/**
	 * @fn std::string getStreet()
	 * gibt den Stra�ennamen wieder
	 */
	std::string getStreet();

	/**
	 * @fn std::string getZip()
	 * gibt die Postleitzahl wieder
	 */
	std::string getZip();

	/**
	 * @fn std::string getCity()
	 * gibt den Stadtnamen wieder
	 */
	std::string getCity();

	/**
	 * @fn std:.string getCommnt()
	 * gibt Kommentar wieder
	 */
	std::string getComment();

	/**
	 * @fn void setname(std::string nameIn)
	 * setzte/�berschreibt Firmennamen
	 * @param nameIn
	 * der zu setztende Name
	 */
	void setName(std::string nameIn);

	/**
	 * @fn void setStreet(std::string streetIn)
	 * setzt/�berschreibt den Stra�ennamen
	 * @param steetIn
	 * der zu setztende Stra�enname
	 */
	void setStreet(std::string streetIn);

	/**
	 * @fn void setZip(std::string zipIn)
	 * setzt/�berschreibt die Postleitzahl
	 * @param zipnIn
	 * die zu setztende Postleitzahl
	 */
	void setZip(std::string zipIn);

	/**
	 * @fn void setCity(std::string cityIn)
	 * setzt/�berschreibt den Stadtnamen
	 * @param cityIn
	 * der zu setztende Stadtnamen
	 */
	void setCity(std::string cityIn);

	/**
	 * @fn void commentZip(std::string commentIn)
	 * setzt/�berschreibt den Kommentar
	 * @param commentIn
	 * der zu setztende Kommentar
	 */
	void setComment(std::string commentIn);
};

class Storage: public Firm {
private:
	std::vector<Alloy> alloy;
public:
	/**
	 * @fn Storage()
	 * Konstruktor mit leeren Werten des Typen Storage
	 */
	Storage();

	/**
	 * @fn Storage(std::vector<Alloy> aI)
	 * Konstruktor mit Anfangswerten des typen Storage
	 * @param alloyIn
	 * nimmt ein Vector des typen Alloys f�r die Anfangswerte
	 * wenn noch kein Vector vorliegt nimmt leeren konstruktor und Funktion addAlloy
	 */
	Storage(std::vector<Alloy> alloyIn);

	/**
	 * @fn std::vector<Alloy> getAlloys()
	 * gibt eine Kopie des Vector mit den Gelagerten Legierungen wieder
	 */
	std::vector<Alloy> getAlloys();

	/**
	 * @fn int getAlloyPosByName(std::string alloyNameIn)
	 * gibt einen integer mit der Position der gesuchten Legierung im Vector wieder.
	 * wenn die Legierung nicht gefunden wurde wird eine -1 zur�ckgeben
	 * @param alloyNameIn
	 * Name der gesuchten Legierung
	 */
	int getAlloyPosByName(std::string alloyNameIn);

	/**
	 * @fn int getAlloyPosByType(Alloy& alloyIn)
	 * gibt einen integer mit der Position der gesuchten Legierung im Vector wieder.
	 * wenn die Legierung nicht gefunden wurde wird eine -1 zur�ckgeben
	 * @param alloyIn
	 * Referenz der gesuchten Legierung
	 */
	int getAlloyPosByType(const Alloy alloyIn);

	/**
	 * @fn void addAlloy(Alloy alloyIn)
	 * packt ein Legierung dem Lager hinzu/Vector
	 * @param alloyIn
	 * Legierung welche dem lager hinzugef�gt werden soll
	 */
	void addAlloy(const Alloy &alloyIn);

	/**
	 * @fn bool removeAlloyByName(std::string alloyNameIn)
	 * entfernt eine Legierung mit dem gesuchten Namen aus dem Lager
	 * Gibt wahr wider wenn gesuchte Legierung gefunden wurde, falsch wenn nicht
	 * @param alloyNameIn
	 * Name der gesuchten Legierung
	 */
	bool removeAlloyByName(std::string alloyNameIn);

	/**
	 * @fn bool removeAlloyByName(std::string alloyNameIn)
	 * entfernt eine Legierung mit der gesuchten Legierung aus dem Lager.
	 * Gibt wahr wider wenn gesuchte Legierung gefunden wurde, falsch wenn nicht
	 * @param alloyIn
	 * Referenz der gesuchten Legierung
	 */
	bool removeAlloyByType(const Alloy &alloyIn);


	/**
	 * @fn bool editAlloyByName(std::string namesIn ,Alloy edit)
	 * bearbeitet die gesuchte Legierung mit den neuen Werten, sucht mit Namen.
	 * Gibt wahr wider wenn gesuchte Legierung gefunden wurde, falsch wenn nicht
	 * @param namesIn
	 * Name der gesuchten Legierung
	 * @param edit
	 * Kopie der neuen Legierung
	 */
	bool editAlloyByName(std::string namesIn, Alloy edit);

	/**
	 * @fn bool editAlloyByType(Alloy in ,Alloy edit)
	 * bearbeitet die gesuchte Legierung mit den neuen Werten, sucht mit einer Kopie des gesuchten Alloys.
	 * Gibt wahr wider wenn gesuchte Legierung gefunden wurde, falsch wenn nicht
	 * @param in
	 * kopie der gesuchten Legierung
	 * @param edit
	 * Kopie der neuen Legierung
	 */
	bool editAlloyByType(Alloy in, Alloy edit);
};

class Order {
private:
	float amount;
	Firm firm;
public:
	/**
	 * @fn Order()
	 * Konstruktor mit leeren Werten des typen Order
	 */
	Order();

	/**
	 * @fn Order(float amountIn, std::string firmNameIn,unsigned int idIn)
	 * Konstruktor mit Anfangswerten des typen Order
	 * @param amountIn
	 * menge der Bestellung
	 * @param firmNameIn
	 * name der Firma  welche die Bestellung aufgibt
	 * @param idIn
	 * Bestellnummer(unsigned int IMMER NUR POSITIVE WERTE)
	 *
	 */
	Order(float amountIn, Firm firma);
	//~Order();

	/**
	 * @fn float getAmount()
	 * gibt die Menge der Bestellung wieder
	 */
	float getAmount();

	/**
	 * @fn std::string getFirmName()
	 * gibt den Namen der auftraggebenden Firma wieder
	 */
	Firm getFirm();

	/**
	 * @fn void setAmount(float amountIn)
	 * setzt/�berschreibt die Menge der Bestellung
	 * @param amountIn
	 * die neue Bestellmenge
	 */
	void setAmount(float amountIn);

	/**
	 * @fn void setFirmName(std::string firmNameIn)
	 * setzt/�berschreibt den Namen der auftraggebenden Firma
	 * @param firmNameIn
	 * neuer Firmenname
	 */
	void setFirmName(Firm firmaIn);

};

class Supplier: public Firm {
private:
	Alloy alloy;
	std::vector<Order> order;
public:
	/**
	 * @fn Supplier()
	 * Konstruktor mit leeren Werten des Typen Supplier
	 */
	Supplier();

	/**
	 * @fn Supplier(Alloy alloyIn)
	 * Konstruktor mit Anfangswert
	 * @param alloyIn
	 * Legierung des Zulieferes
	 * hier noch keine Bestellung erst in setOrder
	 */
	Supplier(Alloy alloyIn, std::string nameIn, std::string streetIn, std::string zipIn, std::string cityIn, std::string commentIn);
	//~Supplier();

	/**
	 * @fn setOrder(Order orderIn)
	 * f�gt eine neue Legierung hinzu
	 * @param
	 * alloyIn
	 * neue Legierung
	 */
	void setOrder(Order orderIn);

	/**
	 * @fn setAlloy(Alloy alloyIn)
	 * f�gt eine neue Bestellung dem vector Order hinzu
	 * @param
	 * orderIn
	 * neue Bestellung
	 */
	void setAlloy(Alloy alloyIn);

	/**
	 * @fn std::vector<Order> getOrder()
	 * gibt eine Kopie des vectors mit den Bestellungen wieder
	 */
	std::vector<Order> getOrder();

	/**
	 * @fn Alloy getAlloy()
	 * gibt eine Kopie der Legierung des Zulieferer wieder
	 */
	Alloy getAlloy();

	//bool saveSupplier(std::string nameIn, std::string spacerIn); muss noch neu �berdacht werden speichern und lesen der Zulieferer noch nicht ganz gel�st
	//bool readSupplier(std::string filename, std::string spacerIn);

};

#endif /* CLASSES_H_ */
