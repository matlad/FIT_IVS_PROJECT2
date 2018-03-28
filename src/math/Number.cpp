/**
 * @file     Number.cpp
 * @encoding UTF-8
 * @date     26.3.18
 * @author   Matyáš Sládek <xslade21@stud.fit.vutbr.cz>
 * 
 * @brief    Number z matematické knihovny
 */

#include "Number.h"
#include "UndefinedException.h"

using namespace team22::Math;
using namespace std;

bool Number::anyParamNan(double param1, double param2, double param3, double param4) const
{
    if (isnan(param1) || isnan(param2) || isnan(param3) || isnan(param4))
        return true;
    return false;
}
bool Number::anyParamInf(double param1, double param2, double param3, double param4) const
{
    if (isinf(param1) || isinf(param2) || isinf(param3) || isinf(param4))
        return true;
    return false;
}
bool Number::allParamsInf(double param1, double param2, double param3, double param4) const
{
    if (isinf(param1) && isinf(param2) && isinf(param3) && isinf(param4))
        return true;
    return false;
}
double Number::getReal() const
{
    return value.real();
}
double Number::getImaginary() const
{
    return value.imag();
}
Number::Number(double real, double imaginary)
{
    value = complex(real, imaginary);
}
Number::Number(const complex<double> &other)
{
    value = other;
}
Number Number::add(Number addend) const
{
    if (anyParamNan(value.real(), value.imag(), addend.getReal(), addend.getImaginary())) {
        throw UndefinedException();
    }
    if (allParamsInf(value.real(), value.imag(), addend.getReal(), addend.getImaginary())) {
        if ((value.real() != addend.getReal()) || (value.imag() != addend.getImaginary())) {	//Pokud se reálné nebo imaginární části sčítanců nerovnají
            throw UndefinedException();
        }
    }
    return (value + static_cast<complex<double>>(addend));
}
Number Number::operator+(const Number &number) const
{
    return add(number);
}
Number Number::sub(Number subtrahend) const
{
    if (anyParamNan(value.real(), value.imag(), subtrahend.getReal(), subtrahend.getImaginary())) {
        throw UndefinedException();
    }
    if (allParamsInf(value.real(), value.imag(), subtrahend.getReal(), subtrahend.getImaginary())) {
        if ((value.real() != (-subtrahend.getReal())) || (value.imag() != (-subtrahend.getImaginary()))) {	//Pokud reálná/imaginární část menšence není opačná k reálné/imaginární části menšitele
            throw UndefinedException();
        }
    }
    return (value - static_cast<complex<double>>(subtrahend));
}
Number Number::operator-(const Number &number) const
{
    return sub(number);
}
Number Number::mul(Number multiplier) const
{
    if (anyParamNan(value.real(), value.imag(), multiplier.getReal(), multiplier.getImaginary())) {
        throw UndefinedException();
    }
    if (anyParamInf(value.real(), value.imag(), multiplier.getReal(), multiplier.getImaginary())) {
        throw UndefinedException();
    }
    return (value * static_cast<complex<double>>(multiplier));
}
Number Number::operator*(const Number &number) const
{
    return mul(number);
}
Number Number::div(Number divisor) const
{
    if (anyParamNan(value.real(), value.imag(), divisor.getReal(), divisor.getImaginary())) {
        throw UndefinedException();
    }
    if (allParamsInf(value.real(), value.imag(), divisor.getReal(), divisor.getImaginary())) {
        throw UndefinedException();
    }
    if ((divisor.getReal() == 0) && (divisor.getImaginary() == 0)) {	//Pokud je dělitel roven nule
        if (!(isinf(value.real()) && isinf(value.imag()))				//Pokud obě šásti dělence nejsou nekonečno
        	&& !(isinf(value.real()) && (value.imag() > 0))				//a reálná část dělence není pozitivní nekonečno
        	&& !isinf(value.imag())) {									//a imaginární část dělence není nekonečno
            throw UndefinedException();
        }
    }
    return (value / static_cast<complex<double>>(divisor));
}
Number Number::operator/(const Number &number) const
{
    return div(number);
}
Number Number::pow(Number exponent) const
{
    if (anyParamNan(value.real(), value.imag(), exponent.getReal(), exponent.getImaginary())) {
        throw UndefinedException();
    }
    if (anyParamInf(value.real(), value.imag(), exponent.getReal(), exponent.getImaginary())) {
        if (!((value.real() == 0) && (value.imag() == 0) && (isinf(exponent.getReal())) && (exponent.getReal() > 0))					//Pokud obě části mocněnce nejsou rovny nule a mocnitel není pozitivní nekonečno
            && !((allParamsInf(value.real(), value.imag(), exponent.getReal(), exponent.getImaginary()))
                && (((value.real() > 0) && (value.imag() > 0) && (exponent.getReal() < 0) && (exponent.getImaginary() > 0))				//Pokud je mocněnec v prvním kvadrantu a mocnitel v druhém kvadrantu
                    || ((value.real() < 0) && (value.imag() > 0) && (exponent.getReal() < 0) && (exponent.getImaginary() > 0))			//nebo je mocněnec v druhém kvadrantu a mocnitel v druhém kvadrantu
                    || ((value.real() < 0) && (value.imag() < 0) && (exponent.getReal() < 0) && (exponent.getImaginary() < 0))			//nebo je mocněnec v třetím kvadrantu a mocnitel v třetím kvadrantu
                    || ((value.real() > 0) && (value.imag() < 0) && (exponent.getReal() < 0) && (exponent.getImaginary() < 0))))) {		//nebo je mocněnec ve čtvrtém kvadrantu a mocnitel v třetím kvadrantu
            throw UndefinedException();
        }
    }
    if ((value.real() == 0) && (value.imag() == 0) && (exponent.getReal() == 0) && (exponent.getImaginary() == 0)) {
        throw UndefinedException();
    }
    return std::pow(value, static_cast<complex<double>>(exponent));
}
Number Number::operator^(const Number &number) const
{
    return pow(number);
}
Number Number::root(Number degree) const
{
    if (anyParamNan(value.real(), value.imag(), degree.getReal(), degree.getImaginary())) {
        throw UndefinedException();
    }
    if (anyParamInf(value.real(), value.imag(), degree.getReal(), degree.getImaginary())) {
        throw UndefinedException();
    }
    if (((value.real() != 0) || (value.imag() != 0)) && (degree.getReal() == 0) && (degree.getImaginary() == 0)) {		//Pokud je některá z částí odmocněnce nenulová a odmocnitel je nulový
        throw UndefinedException();
    }
    if ((value.real() == 0) && (value.imag() == 0) && (degree.getReal() == 0) && (degree.getImaginary() == 0)) {		//Pokud je odmocněnec i odmocnitel nulový
        return Number(0, 0);
    }
    complex<double> temporary;
    temporary = complex(degree.getReal(), (degree.getImaginary() * (-1)));
    temporary /= (static_cast<complex<double>>(degree) * temporary);
    return std::pow(value, temporary);
}
Number Number::mod(Number divisor) const
{
    if (anyParamNan(value.real(), value.imag(), divisor.getReal(), divisor.getImaginary())) {
        throw UndefinedException();
    }
    if (anyParamInf(value.real(), value.imag(), divisor.getReal(), divisor.getImaginary())) {
        throw UndefinedException();
    }
    if ((divisor.getReal() == 0) && (divisor.getImaginary() == 0)) {		//Pokud je dělitel nulový
        throw UndefinedException();
    }
    complex<double> temporary;
    temporary = value / static_cast<complex<double>>(divisor);
    temporary = complex(trunc(temporary.real()), trunc(temporary.imag()));
    temporary *= static_cast<complex<double>>(divisor);
    return (value - temporary);
}
Number Number::operator%(const Number &number) const
{
    return mod(number);
}
Number Number::fact() const
{
    //TODO Implementace faktoriálu
    return Number(0);
}
Number Number::operator!() const
{
    //TODO Implementace faktoriálu
    return Number(0);
}

ostream &team22::Math::operator<<(ostream &os, const Number &number)
{
    if (number.getReal() != 0) {
        os << number.getReal();
        if (number.getImaginary() != 0) {
        	(number.getImaginary() < 0) ? (os << " - ") : (os << " + ");
            os << abs(number.getImaginary());
            os << "i";
        }
    } else {
        if (number.getImaginary() != 0) {
            os << number.getImaginary();
            os << "i";
        } else {
            os << 0;
        }
    }
    return os;
}

bool team22::Math::Number::operator==(const team22::Math::Number &rhs) const
{
    return num == rhs.num;
}

bool team22::Math::Number::operator!=(const team22::Math::Number &rhs) const
{
    return !(rhs == *this);
}
