#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include "../src/math/Number.h"

using namespace team22::Math;

int main(int argc, char** argv){
	
	//double in; //vstupni hodnota
	std::string in;
	Number mean = {0}; //prumer
	std::vector<Number> inValues;
	
	std::ifstream insert( argv[1] );
	
	if(insert.is_open()){
	//ifs.open(argv[1]);
		//nacitani hodnot ze vstupu
		//while(std::cin >> in){
		while(std::getline(insert,in)){
			//if(in == EOF){break;}
			inValues.push_back(std::stod(in)); //nacteni hodnot ze vstupu
		}
		insert.close();
	}

	Number sum = {0}; 
	Number average = {0};
	//vypocet prumeru
	for(auto value : inValues){
		sum = sum + Number(value);
	}
	average = sum/Number(inValues.size());

	Number sampleSD = {0};
	Number sq = {2};

	//vypocet vyberove smerodatne odchylky
	for(auto value: inValues){
    	sampleSD = sampleSD + Number((value - mean)^sq);
	}
	sampleSD = sampleSD/Number(inValues.size() - 1);
	sampleSD = sampleSD^Number(2);


	std::cout << std::flush << "Smerodatna odchylka = " << sampleSD << std::endl;
	
	return 0;}

/**
 * @brief funkce pro vypocet prumeru
 * @param inValues pole hodnot
 * @param size pocet hodnot
 * @return average prumer
 */

/**
 * @brief funkce pro vypocet vyberove smerodatne odchylky
 * @param inValues pole hodnot
 * @param mean prumer
 * @param size pocet hodnot
 * @return sampleSD vyberova smerodatna odchylka
 */

