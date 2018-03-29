/**
 * @file     LexicalAnalyzer.cpp
 * @encoding UTF-8
 * @date     28.3.18
 * @author   Adam Mátl <xmatla00@stud.fit.vutbr.cz> <matla@matla.cz>, Jiří Čechák <xcecha04@stud.fit.vutbr.cz>
 */
#include "LexicalAnalyzer.h"

bool team22::Calc::LexicalAnalyzer::isNumber(std::string s)
{
	if (s == "") {
		return false;
	}

	for (const char c : s) {
		if (!isdigit(c)) {
			return false;
		}
	}

	return true;
}

bool team22::Calc::LexicalAnalyzer::isNumberWithDotEnd(std::string s)
{
	bool flag = true;

	if (s.length() < 2 || s[s.length() - 1] != '.') {
		return false;
	}

	unsigned int i = 0;
	for (const char c : s) {
		if (i >= s.length() - 1) {
			break;
		}

		if (!isdigit(c)) {
			return false;
		}

		i++;
	}

	return true;
}

bool team22::Calc::LexicalAnalyzer::isNumberWithDot(std::string s)
{
	bool flag = true;

	if (s == "") {
		return false;
	}

	unsigned int i = 0;
	for (const char c : s) {
		if (!isdigit(c) && (((!flag || i == 0 || i == s.length() - 1) && c == '.') || c != '.')) {
			return false;
		}

		if (c == '.') {
			flag = false;
		}

		i++;
	}

	return true;
}

void team22::Calc::LexicalAnalyzer::sendLex(Lex lex) {
	for (auto callBack:this->lexCallbackObjects)
	{
		callBack->sendIdentifiedLex(lex);
	}
}

team22::Calc::Lex team22::Calc::LexicalAnalyzer::getCharLex(char c) {
	switch(c) {
		case '+':
			return Lex(Lex::ADD);
		case '-':
			return Lex(Lex::SUB);
		case '/':
			return Lex(Lex::DIV);
		case '*':
			return Lex(Lex::MUL);
		case '=':
			return Lex(Lex::EVAL);
		case '^':
			return Lex(Lex::EXP);
		case '!':
			return Lex(Lex::FACTORIAL);
		case '%':
			return Lex(Lex::MOD);
		case 'C':
			return Lex(Lex::CLEAR);
		default:
			if (isdigit(c)) {
				std::string digit;
				digit.push_back(c);
				return Lex(team22::Math::Number(stringToDouble(digit)));
			}

			throw LexicalAnalyzerException();
	}
}

double team22::Calc::LexicalAnalyzer::stringToDouble(std::string s) {
	std::stringstream stringStream;
	double number;

	stringStream << s;
	stringStream >> number;

	return number;
}

void team22::Calc::LexicalAnalyzer::pushSymbol(char symbol)
{
	if (saved == "") {
		switch(symbol) {
			case '+':
			case '-':
			case '/':
			case '*':
			case '=':
			case '^':
			case '!':
			case '%':
			case 'C':
				if (last != symbol) {
					sendLex(getCharLex(symbol));
					last = symbol;
				}
				return;
			case 'R':
			case 'N':
			case 'B':
				saved += symbol;
				last = symbol;
				return;
			default:
				if (isdigit(symbol)) {
					if (last == 'i') {
						throw LexicalAnalyzerException();
					}
					saved += symbol;
					last = symbol;
					return;
				}
				break;
		}
	} else {
		if ((saved == "R" && symbol == 'O') || 
		(saved == "RO" && symbol == 'O') || 
		(saved == "N" && symbol == 'E') || 
		(isNumber(saved) && (isdigit(symbol) || symbol == '.')) ||
		((isNumberWithDotEnd(saved) || isNumberWithDot(saved)) && isdigit(symbol))) {
			saved += symbol;
			last = symbol;
			return;
		} else if (saved == "ROO" && symbol == 'T') {
			sendLex(Lex(Lex::ROOT));
			saved = "";
			last = symbol;
			return;
		} else if (saved == "NE" && symbol == 'G') {
			sendLex(Lex(Lex::NEG));
			saved = "";
			last = symbol;
			return;
		} else if (saved == "B" && symbol == 'S') {
			sendLex(Lex(Lex::BS));
			saved = "";
			last = symbol;
			return;
		} else if (isNumber(saved) || isNumberWithDot(saved)) {
			switch(symbol) {
				case '+':
				case '-':
				case '/':
				case '*':
				case '=':
				case '^':
				case '!':
				case '%':
				case 'C':
					sendLex(Lex(team22::Math::Number(stringToDouble(saved))));
					sendLex(getCharLex(symbol));
					saved = "";
					last = symbol;
					return;
				case 'i':
					sendLex(Lex(team22::Math::Number(0, stringToDouble(saved))));
					saved = "";
					last = symbol;
					return;
				default:
					break;
			}
		}
	}

	throw LexicalAnalyzerException();
}

void team22::Calc::LexicalAnalyzer::registLexemCalback(team22::Calc::LexIdentificationObserver *lexCallbackObject)
{
	lexCallbackObjects.emplace(lexCallbackObject);
}

team22::Calc::LexicalAnalyzer::LexicalAnalyzer()
{

}
