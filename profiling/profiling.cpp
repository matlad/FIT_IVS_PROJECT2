#include <iostream>
#include <cstdio>
#include "../src/math/Number.h"

using namespace team22::Math;

double average(double inValues[], int size);
double sampleStandartDeviation(double inValues[], double mean, int size);

int main(){
	
	//Number numb;
	int size = 0; //pocet hodnot
	double mean = 0; //prumer
	double inValues[size]; //pole hodnot nactenych ze vstupu

	std::cin >> size; //nacteni poctu hodnot
	
	//numb = new Number[size] {};
	
	//int i = 0;
	for (int i = 0; i < size; i++){
		std::cin >> inValues[i] ; //nacteni hodnot ze vstupu
		//std::cin >> numb[i] {};	
	}
	mean = average(inValues, size);
	std::cout << std::endl << "Smerodatna odchylka = " << sampleStandartDeviation(inValues, mean, size);
	
	return 0;
}

/**
 * @brief funkce pro vypocet prumeru
 * @param inValues pole hodnot
 * @param size pocet hodnot
 * @return average prumer
 */
double average(double inValues[], int size){

	double sum = 0; 
	double average = 0;
	//Number numb;

	for(int i = 0; i < size; i++){ //cyklus pro vypoce souctu vesech hodnot
		//sum = numb.add(inValues[i]);
		sum = sum + inValues[i];
	}
	//average = numb.div(sum, size);
	average = sum/size; //vypocet prumeru

	return average;
}

/**
 * @brief funkce pro vypocet vyberove smerodatne odchylky
 * @param inValues pole hodnot
 * @param mean prumer
 * @param size pocet hodnot
 * @return sampleSD vyberova smerodatna odchylka
 */
double sampleStandartDeviation(double inValues[], double mean, int size){
	
	double sampleSD = 0;
	//Number numb;

	for (int i = 0; i < size; i++){ 
		//sampleSD = sampleSD + (inValues[i] - mean) numb.pow(2);
		double value = inValues[i];
		//double tmp = value - mean;

		sampleSD = sampleSD + ((value - mean)^2);
		//sampleSD = sampleSD + ((value - mean)^(2));
	}
	//sampleSD = numb.div(sampleSD, (size - 1));
	sampleSD = sampleSD/(size - 1);
	//sampleSD = sampleSD numb.root(2);
	sampleSD = Number::root(2) const;

	return sampleSD;
}
