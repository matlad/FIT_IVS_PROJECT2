#include "Number.h"
#include "UndefinedException.h"

bool paramsNan(double param1, double param2, double param3, double param4)
{
    if (std::isnan(param1) || std::isnan(param2) || std::isnan(param3) || std::isnan(param4))
        return true;
    return false;
}
double team22::Math::Number::getReal() const
{
    return num.real();
}
double team22::Math::Number::getImaginary() const
{
    return num.imag();
}
team22::Math::Number::Number(double real, double imagine)
{
    num = std::complex(real, imagine);
}
team22::Math::Number team22::Math::Number::add(team22::Math::Number adder)
{
    if (paramsNan(num.real(), num.imag(), adder.getReal(), adder.getImaginary())) {
        UndefinedException e;
        throw e;
    }
    if (std::isinf(num.real()) && std::isinf(num.imag()) && std::isinf(adder.getReal()) && std::isinf(adder.getImaginary())) {
        if ((num.real() != adder.getReal()) || (num.imag() != adder.getImaginary())) {
            UndefinedException e;
            throw e;
        }
    }
    res = std::complex(adder.getReal(), adder.getImaginary());
    res = num + res;
    return team22::Math::Number(res.real(), res.imag());
}
team22::Math::Number team22::Math::Number::operator+(team22::Math::Number &number)
{
    return team22::Math::Number(add(number));
}
team22::Math::Number team22::Math::Number::sub(team22::Math::Number subtrahend)
{
    if (paramsNan(num.real(), num.imag(), subtrahend.getReal(), subtrahend.getImaginary())) {
        UndefinedException e;
        throw e;
    }
    if (std::isinf(num.real()) && std::isinf(num.imag()) && std::isinf(subtrahend.getReal()) && std::isinf(subtrahend.getImaginary())) {
        if ((num.real() != (-subtrahend.getReal())) || (num.imag() != (-subtrahend.getImaginary()))) {
            UndefinedException e;
            throw e;
        }
    }
    res = std::complex(subtrahend.getReal(), subtrahend.getImaginary());
    res = num - res;
    return team22::Math::Number(res.real(), res.imag());
}
team22::Math::Number team22::Math::Number::operator-(team22::Math::Number &number)
{
    return team22::Math::Number(sub(number));
}
team22::Math::Number team22::Math::Number::mul(team22::Math::Number multiplier)
{
    if (paramsNan(num.real(), num.imag(), multiplier.getReal(), multiplier.getImaginary())) {
        UndefinedException e;
        throw e;
    }
    if (std::isinf(num.real()) || std::isinf(num.imag()) || std::isinf(multiplier.getReal()) || std::isinf(multiplier.getImaginary())) {
        UndefinedException e;
        throw e;
    }
    res = std::complex(multiplier.getReal(), multiplier.getImaginary());
    res = num * res;
    return team22::Math::Number(res.real(), res.imag());
}
team22::Math::Number team22::Math::Number::operator*(team22::Math::Number &number)
{
    return team22::Math::Number(mul(number));
}
team22::Math::Number team22::Math::Number::div(team22::Math::Number divisor)
{
    if (paramsNan(num.real(), num.imag(), divisor.getReal(), divisor.getImaginary())) {
        UndefinedException e;
        throw e;
    }
    if (std::isinf(num.real()) && std::isinf(num.imag()) && std::isinf(divisor.getReal()) && std::isinf(divisor.getImaginary())) {
        UndefinedException e;
        throw e;
    }
    if ((divisor.getReal() == 0) && (divisor.getImaginary() == 0)) {
        if (!(std::isinf(num.real()) && std::isinf(num.imag())) && !(std::isinf(num.real()) && ((num.imag())) > 0) && !std::isinf(num.imag())) {
            UndefinedException e;
            throw e;
        }
    }
    res = std::complex(divisor.getReal(), divisor.getImaginary());
    res = num / res;
    return team22::Math::Number(res.real(), res.imag());
}
team22::Math::Number team22::Math::Number::operator/(team22::Math::Number &number)
{
    return team22::Math::Number(div(number));
}
team22::Math::Number team22::Math::Number::pow(team22::Math::Number number)
{
    if (paramsNan(num.real(), num.imag(), number.getReal(), number.getImaginary())) {
        UndefinedException e;
        throw e;
    }
    if (std::isinf(num.real()) || std::isinf(num.imag()) || std::isinf(number.getReal()) || std::isinf(number.getImaginary())) {
        if (!((num.real() == 0) && (num.imag() == 0) && (std::isinf(number.getReal())) && (number.getReal() > 0))
            && !((std::isinf(num.real()) && std::isinf(num.imag()) && std::isinf(number.getReal()) && std::isinf(number.getImaginary()))
                && (((num.real() < 0) && (num.imag() < 0) && (number.getReal() < 0) && (number.getImaginary() < 0))
                    || ((num.real() > 0) && (num.imag() > 0) && (number.getReal() < 0) && (number.getImaginary() > 0))
                    || ((num.real() > 0) && (num.imag() < 0) && (number.getReal() < 0) && (number.getImaginary() < 0))
                    || ((num.real() < 0) && (num.imag() > 0) && (number.getReal() < 0) && (number.getImaginary() > 0))))) {
            UndefinedException e;
            throw e;
        }
    }
    if ((num.real() == 0) && (num.imag() == 0) && (number.getReal() == 0) && (number.getImaginary() == 0)) {
        UndefinedException e;
        throw e;
    }
    res = std::complex(number.getReal(), number.getImaginary());
    res = std::pow(num, res);
    return team22::Math::Number(res.real(), res.imag());
}
team22::Math::Number team22::Math::Number::operator^(team22::Math::Number &number)
{
    return team22::Math::Number(pow(number));
}
team22::Math::Number team22::Math::Number::root(team22::Math::Number degree)
{
    if (paramsNan(num.real(), num.imag(), degree.getReal(), degree.getImaginary())) {
        UndefinedException e;
        throw e;
    }
    if (std::isinf(num.real()) || std::isinf(num.imag()) || std::isinf(degree.getReal()) || std::isinf(degree.getImaginary())) {
        UndefinedException e;
        throw e;
    }
    if (((num.real() != 0) || (num.imag() != 0)) && (degree.getReal() == 0) && (degree.getImaginary() == 0)) {
        UndefinedException e;
        throw e;
    }
    if ((num.real() == 0) && (num.imag() == 0) && (degree.getReal() == 0) && (degree.getImaginary() == 0)) {
        return team22::Math::Number(0, 0);
    }
    res = std::complex(degree.getReal(), (degree.getImaginary() * (-1)));
    res = res/(std::complex(degree.getReal(), degree.getImaginary()) * res);
    res = std::pow(num, res);
    return team22::Math::Number(res.real(), res.imag());
}
team22::Math::Number team22::Math::Number::mod(team22::Math::Number total)
{
    if (paramsNan(num.real(), num.imag(), total.getReal(), total.getImaginary())) {
        UndefinedException e;
        throw e;
    }
    if (!std::isinf(num.real()) && !std::isinf(num.imag()) && (total.getReal() == 0) && (total.getImaginary() == 0)) {
        UndefinedException e;
        throw e;
    }
    if (std::isinf(num.real()) || std::isinf(num.imag()) || std::isinf(total.getReal()) || std::isinf(total.getImaginary())) {
        UndefinedException e;
        throw e;
    }
    res = std::complex(total.getReal(), total.getImaginary());
    res = num / res;
    res = std::complex(std::trunc(res.real()), std::trunc(res.imag()));
    res = res*std::complex(total.getReal(), total.getImaginary());
    res = num-res;
    return team22::Math::Number(res.real(), res.imag());
}
team22::Math::Number team22::Math::Number::operator%(team22::Math::Number &number)
{
    return team22::Math::Number(mod(number));
}
team22::Math::Number team22::Math::Number::fact()
{
    return team22::Math::Number(0);
}
team22::Math::Number team22::Math::Number::operator!()
{
    return team22::Math::Number(0);
}

std::ostream &team22::Math::operator<<(std::ostream &os, const team22::Math::Number &number)
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

bool team22::Math::Number::operator==(const team22::Math::Number &rhs) const
{
    return num == rhs.num;
}

bool team22::Math::Number::operator!=(const team22::Math::Number &rhs) const
{
    return !(rhs == *this);
}
