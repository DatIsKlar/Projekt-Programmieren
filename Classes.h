#ifndef CLASSES_H_
#define CLASSES_H_

#include <vector>
#include <string>
#include <armadillo>
#include <fstream>
#include <sstream>
#include "Data.h"
#include <iostream>
#include "Functions.h"

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
	 * @param copperIn
	 * Anfangswert von Kuppfer/Copper
	 * @param zincIn
	 * Anfangswert von Zink/Zinc
	 * @param tinIn
	 * Anfangswert von Zinn/Tin
	 * @param nameIn
	 * Setzen vom Namen
	 * @param amountIn
	 * Anfangswert von der Menge/amount
	 */
	Alloy(float copperIn, float zincIn, float tinIn, std::string nameIn, float amountIn);

	/**
	 *	@fn	bool isValidAlloy()
	 *	?berpr?ft ein Alloy auf seine zul?ssigkeit
	 */
	bool isValidAlloy();

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
	 *	Vergleicht zwei Legierungen auf gleichheit a == b
	 *	@param b
	 *	Ist der zu vergleichende Alloy
	 *	@return
	 *	true or false
	 */
	bool operator==(const Alloy &b);

	/**
	 *	@fn	operator!=(const Alloy &b)
	 *	Vergleicht zwei Legierungen auf ungleichheit a !=b
	 *	@param b
	 *	Ist der zu vergleichende Alloy
	 *	@return
	 *	true or false
	 */
	bool operator!=(const Alloy &b);

	/**
	 *	@fn	bool operator%(const Alloy &b)
	 *	Vergleicht zwei Legierungen auf gleichheit a ==b ohne betrachtung der menge
	 *	@param b
	 *	Ist der zu vergleichende Alloy
	 *	@return
	 *	true or false
	 */
	bool operator%(const Alloy &b);


	/**
	 * @fn std::vector<float> makeAlloyMix(std::vector<std::string> namesIn)
	 * gibt die Verhaeltnisse der gegebenen Legierung als Vector mit der Postions im Verglich zu der Pos. der gebenen Namen
	 * der gesuchten Legierung wieder und entfernt die benoetigte Menge aus dem Lager
	 * @param namesIn
	 * ein Vector mit den Namen der gegebenen Legierungen
	 * @return
	 * ein vector des Typen float
	 */
	std::vector<float> makeAlloyMix(std::vector<Alloy> alloyIn);
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
	 * @param ameIn
	 * Setzen vom Namen
	 * @param streetIn
	 * Setzten der Strasse
	 * @param ipIn
	 * Setzten der Postleitzahl
	 * @param ityIn
	 * Setzten der Stadt
	 * @param commandIn
	 * Kommentar ueber die Firma
	 */
	Firm(std::string nameIn, std::string streetIn, std::string zipIn, std::string cityIn, std::string commentIn);

	/**
	 * @fn std::string getName()
	 * gibt den Namen der Firma wieder
	 */
	std::string getName();

	/**
	 * @fn std::string getStreet()
	 * gibt den Strassennamen wieder
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
	 * setzte/ueberschreibt Firmennamen
	 * @param nameIn
	 * der zu setztende Name
	 */
	void setName(std::string nameIn);

	/**
	 * @fn void setStreet(std::string streetIn)
	 * setzt/ueberschreibt den Strassennamen
	 * @param steetIn
	 * der zu setztende Strassenname
	 */
	void setStreet(std::string streetIn);

	/**
	 * @fn void setZip(std::string zipIn)
	 * setzt/ueberschreibt die Postleitzahl
	 * @param zipnIn
	 * die zu setztende Postleitzahl
	 */
	void setZip(std::string zipIn);

	/**
	 * @fn void setCity(std::string cityIn)
	 * setzt/ueberschreibt den Stadtnamen
	 * @param cityIn
	 * der zu setztende Stadtnamen
	 */
	void setCity(std::string cityIn);

	/**
	 * @fn void commentZip(std::string commentIn)
	 * setzt/ueberschreibt den Kommentar
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
	 * nimmt ein Vector des typen Alloys fuer die Anfangswerte
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
	 * @param alloyNameIn
	 * Name der gesuchten Legierung
	 * @return
	 * -1 = Legierung nicht gefunden
	 */
	int getAlloyPosByName(std::string alloyNameIn);

	/**
	 * @fn int getAlloyPosByType(Alloy& alloyIn)
	 * gibt einen integer mit der Position der gesuchten Legierung im Vector wieder.
	 * @param alloyIn
	 * Referenz der gesuchten Legierung
	 * @return
	 * -1 = Legierung nicht gefunden
	 */
	int getAlloyPosByType(const Alloy alloyIn);

	/**
	 * @fn void addAlloy(Alloy alloyIn)
	 * packt ein Legierung dem Lager hinzu/Vector
	 * @param alloyIn
	 * Legierung welche dem Lager hinzugefuegt werden soll
	 */
	void addAlloy(const Alloy alloyIn);

	/**
	 * @fn bool removeAlloyByName(std::string alloyNameIn)
	 * entfernt eine Legierung mit dem gesuchten Namen aus dem Lager
	 * @param alloyNameIn
	 * Name der gesuchten Legierung
	 * @return
	 * true = Legierung gefunden
	 * false = Legierung nicht gefunden
	 */
	bool removeAlloyByName(std::string alloyNameIn);

	/**
	 * @fn bool removeAlloyByName(std::string alloyNameIn)
	 * entfernt eine Legierung mit der gesuchten Legierung aus dem Lager.
	 * @param alloyIn
	 * Referenz der gesuchten Legierung
	 * @return
	 * true = Legierung gefunden
	 * false = Legierung nicht gefunden
	 */
	bool removeAlloyByType(const Alloy alloyIn);


	/**
	 * @fn bool editAlloyByName(std::string namesIn ,Alloy edit)
	 * bearbeitet die gesuchte Legierung mit den neuen Werten, sucht mit Namen.
	 * @param namesIn
	 * Name der gesuchten Legierung
	 * @param edit
	 * Kopie der neuen Legierung
	 * @return
	 * true = Legierung gefunden
	 * false = Legierung nicht gefunden
	 */
	bool editAlloyByName(std::string namesIn, Alloy edit);

	/**
	 * @fn bool editAlloyByType(Alloy in ,Alloy edit)
	 * bearbeitet die gesuchte Legierung mit den neuen Werten, sucht mit einer Kopie des gesuchten Alloys.
	 * @param in
	 * kopie der gesuchten Legierung
	 * @param edit
	 * Kopie der neuen Legierung
	 * @return
	 * true = Legierung gefunden
	 * false = Legierung nicht gefunden
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
	 * setzt/ueberschreibt die Menge der Bestellung
	 * @param amountIn
	 * die neue Bestellmenge
	 */
	void setAmount(float amountIn);

	/**
	 * @fn void setFirmName(std::string firmNameIn)
	 * setzt/ueberschreibt den Namen der auftraggebenden Firma
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
	 * fuegt eine neue Bestellung dem vector Order hinzu
	 * @param
	 * orderIn
	 * neue Bestellung
	 */
	void setOrder(Order orderIn);

	/**
	 * @fn setAlloy(Alloy alloyIn)
	 * fuegt eine neue Legierung hinzu
	 * @param alloyIn
	 * neue Legierung
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

	/**
	 * @fn void html()
	 * gibt eine Bestell?bersicht der letzten Bestellung als html Datei aus
	 */
	void html();

};

#endif /* CLASSES_H_ */
