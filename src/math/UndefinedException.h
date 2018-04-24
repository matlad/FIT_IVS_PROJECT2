/**
 * @file     UndefinedException.h
 * @encoding UTF-8
 * @date     18.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#ifndef FIT_IVS_PROJECT2_UNDEFINEDEXCEPTION_H
#define FIT_IVS_PROJECT2_UNDEFINEDEXCEPTION_H

#include <exception>
namespace team22 { namespace Math
{

/**
 * Výjimka vrácena pokud operace pro vstupy mimo definiční obor fce
 */
class UndefinedException: public std::exception
{
public:

	const char* what() {
		return "Result of this operation is not defined for given values.";
	}
};

}
}



#endif //FIT_IVS_PROJECT2_UNDEFINEDEXCEPTION_H
