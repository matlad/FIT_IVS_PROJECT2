/**
 * @file     profiling.cpp
 * @encoding UTF-8
 * @date     17.4.2018
 * @author   Jacek Mitura <xmitur01@stud.fit.vutbr.cz>
 *
 * @brief    Implementace vyběrové směrodatné odchylky za účelem profilingu funkcí z matematické knihovny. Vypočte vyběrovou směrodatnou odchylku.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include "../math/Number.h"

using namespace team22::Math;

int main(int argc, char **argv){
	
	std::string in;										//vstupni hodnota
	//Number mean = {0};									//prumer
	std::vector<Number> inValues;						//pole vstupnich hodnot
	Number sum = {0};
	Number average = {0};
	Number sampleSD = {0};
	Number sq = {2};

	std::ifstream insert ( argv[1] );					//otevreni souboru
	
	if (insert.is_open()) {								//kontrola zdali je soubor otevren
			while (std::getline(insert,in)) 			//nacteni hodnot ze vstupu
				inValues.push_back(std::stod(in));		//presun hodnoty na misto v poli
		
		insert.close();									//zavreni souboru
	}
	
	/**
	 * vypocet prumeru
	 */
	for (auto value : inValues) 
		sum = sum + Number(value);
	
	average = sum/Number(inValues.size());

	/**
	 * vypocet vyberove smerodatne odchylky
	 */
	for (auto value: inValues)
    	sampleSD = sampleSD + Number((value - average)^sq);
	
	sampleSD = sampleSD/Number(inValues.size() - 1);
	sampleSD = sampleSD^Number(0.5);


	std::cout << std::flush << "Smerodatna odchylka = " << sampleSD << std::endl;
	
	return 0;}

