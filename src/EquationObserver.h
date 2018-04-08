/**
 * @file     EquationObserver.h
 * @encoding UTF-8
 * @date     8.4.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#ifndef FIT_IVS_PROJECT2_EQUATIONOBSERVER_H
#define FIT_IVS_PROJECT2_EQUATIONOBSERVER_H

namespace team22::Calc
{
class EquationObserver
{
public:
    virtual void onEquationChange() = 0;
};
}

#endif //FIT_IVS_PROJECT2_EQUATIONOBSERVER_H
