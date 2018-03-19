/**
 * @file Number.h
 * @author Adam Mátl xmatla00@stud.fit.vutbr.cz
 *
 * @brief
 */

#include <iostream>

namespace team22::Math
{

/**
 * Třída reprezentující číslo v komplexní rovině a operace nad tímto číslem
 */
class Number
{
public:

    /**
     * Realná část
     * @return
     */
    double getReal();

    /**
     * Imaginární část
     * @return
     */
    double getImaginary();

    /**
     *
     * @param real
     * @param imagine
     */
    Number(double real, double imagine = 0);

    /**
     *
     * @param adder1
     * @param adder2
     * @return
     */
    Number add(Number adder);

    Number operator+(Number &number);

    /**
     *
     * @param minuend
     * @param subtrahend
     * @return
     */
    Number sub(Number subtrahend);

    Number operator-(Number &number);

    /**
     * násobení
     */
    Number mul(Number multiplier);

    Number operator*(Number &number);

    /**
     * dělení
     */
    Number div(Number divisor);

    Number operator/(Number &number);

    /**
     * mocnina
     */
    Number pow(Number exponent);

    Number operator^(Number &number);

    /**
     * odmocnina
     */
    Number root(Number degree);

    /**
     * Vrací zbytek po dělení
     */
    Number mod(Number total);

    Number operator%(Number &number);

    /**
     * faktorial
     */
    Number fact();

    Number operator!();

    /**
     * vypíše číslo jako realná část + imaginarní část i
     * pokud je některá část 0 nevypisuje
     * př.
     * 2 + 6i
     * 6 // imaginární část je 0
     * 7i // realná část je 0
     * 0 // obě části jsou 0
     */
    friend std::ostream &operator<<(std::ostream &os, const Number &number);

};

};
