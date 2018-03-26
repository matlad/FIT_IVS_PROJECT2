/**
 * @file     Number.h
 * @encoding UTF-8
 * @date     26.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz>
 * @author   Matyáš Sládek <xslade21@stud.fit.vutbr.cz>
 * 
 * @brief    Hlavičkový soubor pro Number z matematické knihovny
 */

#include <cmath>
#include <complex>
#include <iostream>

namespace team22::Math
{

/**
 * Třída reprezentující číslo v komplexní rovině a operace nad tímto číslem
 */
class Number
{
private:

    std::complex<double> value;

    /**
     * @return True pokud je některý z parametrů Nan, jiank False
     */
	bool anyParamNan(double param1, double param2, double param3, double param4);

    /**
     * @return True pokud je některý z parametrů nekonečno, jiank False
     */
	bool anyParamInf(double param1, double param2, double param3, double param4);

    /**
     * @return True pokud jsou všechny parametry nekonečno, jiank False
     */
	bool allParamsInf(double param1, double param2, double param3, double param4);

public:

    /**
     * Realná část
     * @return
     */
    double getReal() const;

    /**
     * Imaginární část
     * @return
     */
    double getImaginary() const;

    /**
     * @param real Reálná část
     * @param imaginary Imaginární část
     */
    Number(double real, double imaginary = 0);

    /**
     * @brief Sčítání
     * 
     * @param addend sčítanec
     * @return součet
     */
    Number add(Number addend);

    Number operator+(Number &number);

    /**
     * @brief Odečítání
     * 
     * @param subtrahend menšitel
     * @return rozdíl
     */
    Number sub(Number subtrahend);

    Number operator-(Number &number);

    /**
     * @brief Násobení
     * 
     * @param multiplier činitel
     * @return součin
     */
    Number mul(Number multiplier);

    Number operator*(Number &number);

    /**
     * @brief Dělení
     * 
     * @param divisor dělitel
     * @return rozdíl
     */
    Number div(Number divisor);

    Number operator/(Number &number);

    /**
     * @brief Umocňování
     * 
     * @param exponent mocnitel
     * @return mocnina
     */
    Number pow(Number exponent);

    Number operator^(Number &number);

    /**
     * @brief Odmocňování
     * 
     * @param degree odmocnitel
     * @return odmocnina
     */
    Number root(Number degree);

    /**
     * @brief Zbytek po dělení
     * 
     * @param divisor dělitel
     * @return zbytek
     */
    Number mod(Number divisor);

    Number operator%(Number &number);

    /**
     * @brief Faktoriál
     * 
     * @return faktoriál
     */
    Number fact();

    Number operator!();

    /**
     * vypíše číslo jako realná část +/- imaginarní část i
     * pokud je některá část 0 nevypisuje
     * př.
     * 2 + 6i
     * 6 // imaginární část je 0
     * 7i // realná část je 0
     * 0 // obě části jsou 0
     */
    /**
     * @brief Vypíše komplexní číslo
     * @details Vypíše komplexní číslo ve tvaru: reálná_část +/- imaginární_část. Pokud je některá z částí 0, není vypsána, pokud jsou 0 části obě, vypíše 0.
     */
    friend std::ostream &operator<<(std::ostream &os, const Number &number);

};

};
