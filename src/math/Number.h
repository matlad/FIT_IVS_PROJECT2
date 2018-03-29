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

#include <cmath>    //Used for isnan()
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

	explicit operator std::complex<double>() const {return value;}

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
	 * @see add
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
	 * @see sub
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
	 * @see mul
	 */
    Number operator*(const Number &number) const;

    /**
     * @brief Dělení
     *
     * @param divisor dělitel
     * @return rozdíl
     * @throws UndefinedException TODO
     */
    Number div(Number divisor) const;

    /**
	 * @see div
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
	 * @see pow
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
	 * @see mod
	 */
    Number operator%(const Number &number) const;

    /**
     * @brief Faktoriál
     *
     * @return faktoriál
     */
    Number fact() const;

    Number operator!() const;

    bool operator==(const Number &rhs) const;
    bool operator!=(const Number &rhs) const;

    /**
     * @details Vypíše komplexní číslo ve tvaru: reálná_část +/- imaginární_část. Pokud je některá z částí 0, není vypsána, pokud jsou 0 části obě, vypíše 0.
     */
    friend std::ostream &operator<<(std::ostream &os, const Number &number);

};

};

#endif //FIT_IVS_PROJECT2_NUMBER_H
