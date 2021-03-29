#include <iostream>
#include "upis_objekata.h"
#include "Cvijet.h"

void upis_sunca(Cvijet& cvijet)
{
	float radijus, x, y;
	std::cout << "** UPIS SUNCA **" << std::endl;
	std::cout << "Radijus: ";
	std::cin >> radijus;
	std::cout << "x koordinata: ";
	std::cin >> x;
	std::cout << "y koordinata: ";
	std::cin >> y;

	cvijet.set_radijus_sunca(radijus);
	cvijet.set_pozicija_sunca(x, y);
}

void upis_cvijeta(Cvijet& cvijet)
{
	float radijus, x, y;
	std::cout << "** UPIS TUCKA **" << std::endl;
	std::cout << "Radijus: ";
	std::cin >> radijus;
	std::cout << "x koordinata: ";
	std::cin >> x;
	std::cout << "y koordinata: ";
	std::cin >> y;
	
	cvijet.set_pozicija_tucka(x, y);
	cvijet.set_radijus_tucka(radijus);
	
}
