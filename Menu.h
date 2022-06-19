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

namespace menu {
void anschriftPflegen(Firm &eigeneFirma);
void supplierPlfegen(std::vector<Supplier> &suppliers);
Alloy alloyNew(Storage &stor);
Supplier supplierNew(Storage &stor);
}

#endif /* MENU_H_ */
