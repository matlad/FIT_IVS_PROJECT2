/**
 * @file     Number.h
 * @encoding UTF-8
 * @date     26.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz>
 * @author   Matyáš Sládek <xslade21@stud.fit.vutbr.cz>
 *
 * @brief    Hlavičkový soubor pro Number z matematické knihovny
 */

#ifndef FIT_IVS_PROJECT2_NUMBER_H
#define FIT_IVS_PROJECT2_NUMBER_H

#include <cmath>
#include <complex>
#include <iostream>
#include <limits>

// uvažujeme přesnost na 10 des míst
#define DELTA 0.00000000005
// pro faktoriál komplexních čísel přesnost na 7 des míst
#define DELTA_CF 0.00000005

namespace team22 { namespace Math
{

/**
 * Třída reprezentující číslo v komplexní rovině a operace nad tímto číslem
 */
class Number
{
private:

    std::complex<double> value;

	explicit operator std::complex<double>() const {return value;}

    /**
     * @brief Funkce zaokrouhluje na danou přesnost
     * 
     * @param value Vstupní hodnota
     * @param precision Hodnota reprezentující přesnost, na kterou se zaokrouhluje
     * @return Zaokrouhlená výstupní hodnota
     */
    std::complex<double> round(std::complex<double> value, double precision) const;    
    /**
     * @details Gamma funkce implementovaná pomocí Lanczosovy aproximace
     * 
     * @param z vstupní operand
     * @return gamma čísla z
     */
    std::complex<double> gamma(std::complex<double> z);

    /**
     * @return True pokud je některý z parametrů Nan, jiank False
     */
	bool anyParamNan(double param1, double param2, double param3, double param4) const;

    /**
     * @return True pokud je některý z parametrů nekonečno, jiank False
     */
	bool anyParamInf(double param1, double param2, double param3, double param4) const;

    /**
     * @return True pokud jsou všechny parametry nekonečno, jiank False
     */
	bool allParamsInf(double param1, double param2, double param3, double param4) const;

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
     * @brief Konstruktor
     *
     * @param real Reálná část
     * @param imaginary Imaginární část
     */
    Number(double real, double imaginary = 0);

    /**
     * @brief Konstruktor
     *
     * @param other Komplexní číslo
     */
    Number(const std::complex<double>& other);

    /**
     * @brief Sčítání
     *
     * @param addend sčítanec
     * @return součet
     * @throws UndefinedException pokud je některá z částí operandů nan nebo pokud jsou obě části operandů nekonečno a zároveň operandy nejsou ze stejných kvadrantů komplexní roviny
     */
    Number add(Number addend) const;

    /**
	 * @see Number::add
	 */
    Number operator+(const Number &number) const;

    /**
     * @brief Odečítání
     *
     * @param subtrahend menšitel
     * @return rozdíl
     * @throws UndefinedException pokud je některá z částí operandů nan nebo pokud jsou obě části operandů nekonečno a zároveň operandy nejsou z opačných kvadrantů komplexní roviny
     */
    Number sub(Number subtrahend) const;

    /**
	 * @see Number::sub
	 */
    Number operator-(const Number &number) const;

    /**
     * @brief Násobení
     *
     * @param multiplier činitel
     * @return součin
     * @throws UndefinedException pokud je některá z částí operandů nan nebo nekonečno
     */
    Number mul(Number multiplier) const;

    /**
	 * @see Number::mul
	 */
    Number operator*(const Number &number) const;

    /**
     * @brief Dělení
     *
     * @param divisor dělitel
     * @return rozdíl
     * @throws UndefinedException Pokud je některá část operandů nan nebo obě části obou operandů jsou nekonečno nebo je dělitel nulový a obě části dělence nejsou nekonečno a reálná část dělence není pozitivní nekonečno a imaginární část dělence není nekonečno
     */
    Number div(Number divisor) const;

    /**
	 * @see Number::div
	 */
    Number operator/(const Number &number) const;

    /**
     * @brief Umocňování
     *
     * @param exponent mocnitel
     * @return mocnina
     * @throws UndefinedException TODO
     */
    Number pow(Number exponent) const;

    /**
	 * @see Number::pow
	 */
    Number operator^(const Number &number) const;

    /**
     * @brief Odmocňování
     *
     * @param degree odmocnitel
     * @return odmocnina
     * @throws UndefinedException pokud je některá z částí operandů nan nebo nekonečno nebo pokud je některá z částí odmocněnce nenulová a odmocnitel je nulový
     */
    Number root(Number degree) const;

    /**
     * @brief Zbytek po dělení
     *
     * @param divisor dělitel
     * @return zbytek
     * @throws UndefinedException pokud je některá z částí operandů nan nebo nekonečno nebo pokud je dělitel nulový
     */
    Number mod(Number divisor) const;

    /**
	 * @see Number::mod
	 */
    Number operator%(const Number &number) const;

    /**
     * @brief Faktoriál
     * 
     * @return faktoriál
     * @throws UndefinedException pokud je některá z částí operandů nan nebo jsou obě části operandů nekonečno nebo je reálná část operandu záporné nekonečno
     */
    Number fact();

    /**
     * @see Number::fact
     */
    Number operator!();

    bool operator==(const Number &rhs) const;
    bool operator!=(const Number &rhs) const;

    /**
     * @details Vypíše komplexní číslo ve tvaru: reálná_část +/- imaginární_část. Pokud je některá z částí 0, není vypsána, pokud jsou 0 části obě, vypíše 0.
     */
    friend std::ostream &operator<<(std::ostream &os, const Number &number);

};

};};

#endif //FIT_IVS_PROJECT2_NUMBER_H
