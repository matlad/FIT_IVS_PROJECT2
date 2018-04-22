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
#include "../tests/TestConstants.h"

using namespace team22::Math;
using namespace std;

complex<double> Number::round(complex<double> value, double precision) const
{
	if (abs(value.real()) < precision) {
		value = complex(0.0, value.imag());
	}
	if (abs(value.imag()) < precision) {
		value = complex(value.real(), 0.0);
	}
	return value;
}

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
    return (round((value + static_cast<complex<double>>(addend)), DELTA));
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
    return (round((value - static_cast<complex<double>>(subtrahend)), DELTA));
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
    return (round((value * static_cast<complex<double>>(multiplier)), DELTA));
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
    return (round((value / static_cast<complex<double>>(divisor)), DELTA));
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
    return (round(std::pow(value, static_cast<complex<double>>(exponent)), DELTA));
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
    return (round(std::pow(value, temporary), DELTA));
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
    return (round((value - temporary), DELTA));
}
Number Number::operator%(const Number &number) const
{
    return mod(number);
}
Number Number::fact()
{
	if (isnan(value.real()) || isnan(value.imag())) {
		throw UndefinedException();
	}
	if ((isinf(value.real()) && isinf(value.imag())) || (isinf(value.real()) && (value.real() < 0))) {		//Pokud jsou obě části operandu nekonečno nebo reálná část operandu je záporné nekonečno
		throw UndefinedException();
	}
	if (isinf(value.real())) {																				//Pokud je reálná část operandu rovna nekonečnu
		return std::numeric_limits<double>::infinity();
	}
	if (isinf(value.imag())) {																				//Pokud je imaginární část operandu rovna nule
		return 0;
	}
	if ((value.real() < 0) && (value.real() == floor(value.real())) && (value.imag() == 0)) {				//Pokud je operand záporné celé číslo, nelze použít gamma funkci
		int res = abs(value.real());
		for (unsigned i = (abs(value.real()) - 1); i > 1; i--) {
			res *= i;
		}
		return (-res);
	}
    return Number(round(gamma(value + 1.0), DELTA_CF));
}
Number Number::operator!()
{
    return fact();
}

//Koeficienty pro Lanczosovu řadu
const double c[] = {
    1.000001502363886407565018998866435140371322631835938,
    0.464895966191246401422176859341561794281005859375000,
    -0.04956300218599807294594938866794109344482421875000,
    0.387353748287360133417678298428654670715332031250000,
    -2.32544894194688822608441114425659179687500000000000,
    8.977536034497006767196580767631530761718750000000000,
    -21.8474347546784883888904005289077758789062500000000,
    33.28472248815523926168680191040039062500000000000000,
    -30.7328214590961579233407974243164062500000000000000,
    15.70077904063509777188301086425781250000000000000000,
    -3.40185381879564374685287475585937500000000000000000
};

complex<double> Number::gamma(complex<double> z)
{
    if (z.real() < 1) {												//Reflection formula
    	return (M_PI / (sin(M_PI * z) * gamma(1.0 - z)));
    }
    z -= 1.0;
    complex<double> series = c[0];
    for(unsigned i = 1; i < (sizeof(c)/sizeof(double)); i++) {
        series += (c[i] / (z + static_cast<double>(i)));
    }
    complex<double> t = (z + 1.5);
    return (sqrt(2 * M_PI) * std::pow(t, (z + 0.5)) * exp(-t) * series);
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
    return value == rhs.value;
}

bool team22::Math::Number::operator!=(const team22::Math::Number &rhs) const
{
    return !(rhs == *this);
}
