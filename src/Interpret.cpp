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
		if (this->unprocessedOperator) {	//If binary operator is waiting for second operand
			switch (this->oper) {
				case Lex::Operator::ADD:
					try {
						this->result = this->result.add(lex.getAsNumber());
					}
					catch (std::exception& e) {
						notifyAboutError();
					}
					break;
				case Lex::Operator::SUB:
					try {
						this->result = this->result.sub(lex.getAsNumber());
					}
					catch (std::exception& e) {
						notifyAboutError();
					}
					break;
				case Lex::Operator::MUL:
					try {
						this->result = this->result.mul(lex.getAsNumber());
					}
					catch (std::exception& e) {
						notifyAboutError();
					}
					break;
				case Lex::Operator::DIV:
					try {
						this->result = this->result.div(lex.getAsNumber());
					}
					catch (std::exception& e) {
						notifyAboutError();
					}
					break;
				case Lex::Operator::EXP:
					try {
						this->result = this->result.pow(lex.getAsNumber());
					}
					catch (std::exception& e) {
						notifyAboutError();
					}
					break;
				case Lex::Operator::ROOT:											//Check this
					try {
						this->result = lex.getAsNumber().root(this->result);
					}
					catch (std::exception& e) {
						notifyAboutError();
					}
					break;
				case Lex::Operator::MOD:
					try {
						this->result = this->result.mod(lex.getAsNumber());
					}
					catch (std::exception& e) {
						notifyAboutError();
					}
					break;
				case Lex::Operator::EVAL:
					this->result = lex.getAsNumber();
					break;
			}
			this->unprocessedNumber = true;
			this->unprocessedOperator = false;
			notifyResultChanged();
		}
		else {
			if (this->unprocessedNumber) {		//Cannot insert another number without operator
				notifyAboutError();
			}
			this->result = lex.getAsNumber();
			this->unprocessedNumber = true;
			notifyResultChanged();
		}
	}
	else {
		if ((lex.getAsOperator() == Lex::Operator::BS) || (lex.getAsOperator() == Lex::Operator::CLEAR)) {
			this->result = 0;
			this->unprocessedOperator = false;
			this->unprocessedNumber = false;
			notifyResultChanged();
		}
		else if (this->unprocessedOperator && (this->oper != Lex::Operator::EVAL)) {	//Cannot insert another operator without number (except BS, CLEAR, EVAL)
			notifyAboutError();
		}
		else if (lex.getAsOperator() == Lex::Operator::FACTORIAL) {
			try {
				this->result = this->result.fact();
			}
			catch (std::exception& e) {
				notifyAboutError();
			}
			notifyResultChanged();
		}
		else if (lex.getAsOperator() == Lex::Operator::NEG) {
			this->result = (this->result * (-1));
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
