/**
 * @file     Interpret.cpp
 * @encoding UTF-8
 * @date     22.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>
 */
#include "Interpret.h"

using namespace team22::Calc;
using namespace team22::Math;

void Interpret::sendIdentifiedLex(Lex lex)
{
	if (lex.getType() == Lex::Types::NUMBER) {
		if (this->unprocessedOperator) {
			switch (this->oper) {
				case Lex::Operator::ADD:
					this->result = this->result.add(lex.getAsNumber());
					break;
				case Lex::Operator::SUB:
					this->result = this->result.sub(lex.getAsNumber());
					break;
				case Lex::Operator::MUL:
					this->result = this->result.mul(lex.getAsNumber());
					break;
				case Lex::Operator::DIV:
					this->result = this->result.div(lex.getAsNumber());
					break;
				case Lex::Operator::EXP:
					this->result = this->result.pow(lex.getAsNumber());
					break;
				case Lex::Operator::ROOT:											//Look here
					this->result = lex.getAsNumber().root(this->result);
					break;
				case Lex::Operator::MOD:
					this->result = this->result.mod(lex.getAsNumber());
					break;
				case Lex::Operator::EVAL:
					this->result = lex.getAsNumber();
					break;
			}
			this->unprocessedOperator = false;
			notifyResultChanged();
		}
		else {
			this->result = lex.getAsNumber();
			notifyResultChanged();
		}
	}
	else {
		if (lex.getAsOperator() == Lex::Operator::FACTORIAL) {
			this->result = this->result.fact();
			notifyResultChanged();
		}
		else if (lex.getAsOperator() == Lex::Operator::NEG) {
			this->result = (this->result * (-1));
			notifyResultChanged();
		}
		else if ((lex.getAsOperator() == Lex::Operator::BS) || (lex.getAsOperator() == Lex::Operator::CLEAR)) {
			this->result = 0;
			notifyResultChanged();
		}
		else {
			this->oper = lex.getAsOperator();
			this->unprocessedOperator = true;
		}
	}
}

void Interpret::registrResultCallback(ResultObserver *resultCallbackObject)
{
    resultCallbackObjects.emplace(resultCallbackObject);
}

void Interpret::notifyResultChanged()
{
    for (auto callBack: this->resultCallbackObjects)
        callBack->onResultChange(this->result);
}

void Interpret::notifyAboutError()
{
	InterpretException exception;
    for (auto callBack: this->resultCallbackObjects)
        callBack->onError(exception);
}
