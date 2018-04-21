/**
 * @file     ResultObserver.h
 * @encoding UTF-8
 * @date     29.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#ifndef FIT_IVS_PROJECT2_RESULTOBSERVER_H
#define FIT_IVS_PROJECT2_RESULTOBSERVER_H

#include "math/Number.h"
#include "InterpretException.h"

namespace team22{ namespace Calc
{
class ResultObserver
{
public:

    /**
     * Callback volaný pokud vznikla chyba při výpočtu
     * @param InterpretException
     */
    virtual void onError(InterpretException exception) = 0;

    /**
     * Callback volaný při změně výsledku
     * @param result
     */
    virtual void onResultChange(Math::Number result) = 0;
};
}}

#endif //FIT_IVS_PROJECT2_RESULTOBSERVER_H
