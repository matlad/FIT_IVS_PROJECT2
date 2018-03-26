/**
 * @file     Number.cpp
 * @encoding UTF-8
 * @date     26.3.18
 * @author   Matyáš Sládek <xslade21@stud.fit.vutbr.cz>
 * @brief    Number z matematické knihovny
 */

#include "Number.h"
#include "UndefinedException.h"

using namespace team22::Math;

bool Number::anyParamNan(double param1, double param2, double param3, double param4)
{
    if (std::isnan(param1) || std::isnan(param2) || std::isnan(param3) || std::isnan(param4))
        return true;
    return false;
}
bool Number::anyParamInf(double param1, double param2, double param3, double param4)
{
    if (std::isinf(param1) || std::isinf(param2) || std::isinf(param3) || std::isinf(param4))
        return true;
    return false;
}
bool Number::allParamsInf(double param1, double param2, double param3, double param4)
{
    if (std::isinf(param1) && std::isinf(param2) && std::isinf(param3) && std::isinf(param4))
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
Number::Number(double real, double imagine)
{
    value = std::complex(real, imagine);
}
Number Number::add(Number adder)
{
    UndefinedException exception;
    if (anyParamNan(value.real(), value.imag(), adder.getReal(), adder.getImaginary())) {
        throw exception;
    }
    if (allParamsInf(value.real(), value.imag(), adder.getReal(), adder.getImaginary())) {
        if ((value.real() != adder.getReal()) || (value.imag() != adder.getImaginary())) {
            throw exception;
        }
    }
    value += std::complex(adder.getReal(), adder.getImaginary());
    return Number(value.real(), value.imag());
}
Number Number::operator+(Number &number)
{
    return Number(add(number));
}
Number Number::sub(Number subtrahend)
{
    UndefinedException exception;
    if (anyParamNan(value.real(), value.imag(), subtrahend.getReal(), subtrahend.getImaginary())) {
        throw exception;
    }
    if (allParamsInf(value.real(), value.imag(), subtrahend.getReal(), subtrahend.getImaginary())) {
        if ((value.real() != (-subtrahend.getReal())) || (value.imag() != (-subtrahend.getImaginary()))) {
            throw exception;
        }
    }
    value -= std::complex(subtrahend.getReal(), subtrahend.getImaginary());
    return Number(value.real(), value.imag());
}
Number Number::operator-(Number &number)
{
    return Number(sub(number));
}
Number Number::mul(Number multiplier)
{
    UndefinedException exception;
    if (anyParamNan(value.real(), value.imag(), multiplier.getReal(), multiplier.getImaginary())) {
        throw exception;
    }
    if (anyParamInf(value.real(), value.imag(), multiplier.getReal(), multiplier.getImaginary())) {
        throw exception;
    }
    value *= std::complex(multiplier.getReal(), multiplier.getImaginary());
    return Number(value.real(), value.imag());
}
Number Number::operator*(Number &number)
{
    return Number(mul(number));
}
Number Number::div(Number divisor)
{
    UndefinedException exception;
    if (anyParamNan(value.real(), value.imag(), divisor.getReal(), divisor.getImaginary())) {
        throw exception;
    }
    if (allParamsInf(value.real(), value.imag(), divisor.getReal(), divisor.getImaginary())) {
        throw exception;
    }
    if ((divisor.getReal() == 0) && (divisor.getImaginary() == 0)) {
        if (!(std::isinf(value.real()) && std::isinf(value.imag())) && !(std::isinf(value.real()) && ((value.imag())) > 0) && !std::isinf(value.imag())) {
            throw exception;
        }
    }
    value /= std::complex(divisor.getReal(), divisor.getImaginary());
    return Number(value.real(), value.imag());
}
Number Number::operator/(Number &number)
{
    return Number(div(number));
}
Number Number::pow(Number number)
{
    UndefinedException exception;
    if (anyParamNan(value.real(), value.imag(), number.getReal(), number.getImaginary())) {
        throw exception;
    }
    if (anyParamInf(value.real(), value.imag(), number.getReal(), number.getImaginary())) {
        if (!((value.real() == 0) && (value.imag() == 0) && (std::isinf(number.getReal())) && (number.getReal() > 0))
            && !((allParamsInf(value.real(), value.imag(), number.getReal(), number.getImaginary()))
                && (((value.real() < 0) && (value.imag() < 0) && (number.getReal() < 0) && (number.getImaginary() < 0))
                    || ((value.real() > 0) && (value.imag() > 0) && (number.getReal() < 0) && (number.getImaginary() > 0))
                    || ((value.real() > 0) && (value.imag() < 0) && (number.getReal() < 0) && (number.getImaginary() < 0))
                    || ((value.real() < 0) && (value.imag() > 0) && (number.getReal() < 0) && (number.getImaginary() > 0))))) {
            throw exception;
        }
    }
    if ((value.real() == 0) && (value.imag() == 0) && (number.getReal() == 0) && (number.getImaginary() == 0)) {
        throw exception;
    }
    value = std::pow(value, (std::complex(number.getReal(), number.getImaginary())));
    return Number(value.real(), value.imag());
}
Number Number::operator^(Number &number)
{
    return Number(pow(number));
}
Number Number::root(Number degree)
{
    UndefinedException exception;
    if (anyParamNan(value.real(), value.imag(), degree.getReal(), degree.getImaginary())) {
        throw exception;
    }
    if (anyParamInf(value.real(), value.imag(), degree.getReal(), degree.getImaginary())) {
        throw exception;
    }
    if (((value.real() != 0) || (value.imag() != 0)) && (degree.getReal() == 0) && (degree.getImaginary() == 0)) {
        throw exception;
    }
    if ((value.real() == 0) && (value.imag() == 0) && (degree.getReal() == 0) && (degree.getImaginary() == 0)) {
        return Number(0, 0);
    }
    std::complex<double> temporary = std::complex(degree.getReal(), (degree.getImaginary() * (-1)));
    temporary /= (std::complex(degree.getReal(), degree.getImaginary()) * temporary);
    value = std::pow(value, temporary);
    return Number(value.real(), value.imag());
}
Number Number::mod(Number total)
{
    UndefinedException exception;
    if (anyParamNan(value.real(), value.imag(), total.getReal(), total.getImaginary())) {
        throw exception;
    }
    if (anyParamInf(value.real(), value.imag(), total.getReal(), total.getImaginary())) {
        throw exception;
    }
    if ((total.getReal() == 0) && (total.getImaginary() == 0)) {
        throw exception;
    }
    std::complex<double> temporary = std::complex(total.getReal(), total.getImaginary());
    temporary = value / temporary;
    temporary = std::complex(std::trunc(temporary.real()), std::trunc(temporary.imag()));
    temporary *= std::complex(total.getReal(), total.getImaginary());
    value -= temporary;
    return Number(value.real(), value.imag());
}
Number Number::operator%(Number &number)
{
    return Number(mod(number));
}
Number Number::fact()
{
    //TODO Implementace faktoriálu
    return Number(0);
}
Number Number::operator!()
{
    //TODO Implementace faktoriálu
    return Number(0);
}

std::ostream &team22::Math::operator<<(std::ostream &os, const Number &number)
{
    if (number.getReal() != 0) {
        os << number.getReal();
        if (number.getImaginary() != 0) {
            os << " + ";
            os << number.getImaginary();
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
