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

namespace menu{
void anschriftPflegen(Firm& eigeneFirma);
std::vector<Supplier> supplierPlfegen(std::vector<Supplier> suppliers);

}


#endif /* MENU_H_ */
