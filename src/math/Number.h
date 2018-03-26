/**
 * @file Number.h
 * @author Adam Mátl <xmatla00@stud.fit.vutbr.cz>
 * @author Matyáš Sládek <xslade21@stud.fit.vutbr.cz>
 *
 * @brief
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
     * @brief Checks if any of the given parameters is Nan.
     * 
     * @param param1 First parameter.
     * @param param2 Second parameter.
     * @param param3 Third parameter.
     * @param param4 Fourth parameter.
     * @return True if any of the given parameters is Nan, False otherwise.
     */
	bool anyParamNan(double param1, double param2, double param3, double param4);

    /**
     * @brief Checks if any of the given parameters is infinity.
     * 
     * @param param1 First parameter.
     * @param param2 Second parameter.
     * @param param3 Third parameter.
     * @param param4 Fourth parameter.
     * @return True if any of the given parameters is infinity, False otherwise.
     */
	bool anyParamInf(double param1, double param2, double param3, double param4);

    /**
     * @brief Checks if all given parameters are infinity.
     * 
     * @param param1 First parameter.
     * @param param2 Second parameter.
     * @param param3 Third parameter.
     * @param param4 Fourth parameter.
     * @return True if all given parameters are infinity, False otherwise.
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
