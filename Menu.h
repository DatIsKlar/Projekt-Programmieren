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

namespace menu {
void anschriftPflegen(Firm &eigeneFirma);
void supplierPlfegen(std::vector<Supplier> &suppliers);
Alloy alloyNewLager(Storage &stor);
Alloy alloyNewSupplier();
Supplier supplierNew(Alloy alloyIn);

int bestellung(Storage &Lager,std::vector<Supplier> &sup, Firm firm);
void produktion(Storage &Lager,std::vector<Supplier> &sup, Firm firm);


}

#endif /* MENU_H_ */
