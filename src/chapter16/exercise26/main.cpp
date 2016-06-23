//
// Created by crypt on 6/20/16.
//

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <cassert>

using namespace std;

namespace exercise16_26 {
    enum Type {
        Number = '0',
        Sum = '+',
        Subtraction = '-',
        Multiplication = '*',
        Division = '/'
    };


    template<typename PrimitiveNumber>
    class Expression {
    protected:
        Type type;

        virtual PrimitiveNumber __eval() = 0;

    public:

        Expression(Type type) : type(type) { };

        Type getType() { return type; }

        PrimitiveNumber eval() {
            PrimitiveNumber result = this->__eval();
            return result;
        }

    };

    template<typename PrimitiveNumber>
    class ExpressionOperation : public Expression<PrimitiveNumber> {
        vector<Expression<PrimitiveNumber> *> operands;
    protected:
        PrimitiveNumber __eval() {
            PrimitiveNumber result;
            if (operands.size() == 2) {
                PrimitiveNumber op1 = operands[0]->eval();
                PrimitiveNumber op2 = operands[1]->eval();
                switch (this->type) {
                    case Type::Sum:
                        result = op1 + op2;
                        break;
                    case Type::Division:
                        if (op2 != 0) {
                            result = op1 / op2;
                        } else {
                            throw invalid_argument("Unable to divide by 0");
                        }
                        break;
                    case Type::Multiplication:
                        result = op1 * op2;
                        break;
                    case Type::Subtraction:
                        result = op1 - op2;
                        break;
                    default:
                        throw invalid_argument("Unknown expression type " + this->type);
                }
            } else {
                ostringstream ost;
                ost << "unable to evaluate expression type:" << this->type << endl;
                if (operands.size() > 0) {
                    ost << "with " << operands.size() << " operand";
                    ost << (operands.size() > 1 ? "s" : "") << endl;
                    int i = 0;
                    for_each(operands.begin(), operands.end(),
                             [&](auto item) {
                                 ost << i << ": " << item->getType() << endl;
                                 i++;
                             });
                }
                throw new invalid_argument(ost.str());
            }
            return result;
        }

    public:
        ExpressionOperation(Type type) : Expression<PrimitiveNumber>(type) { }

        void addOperand(Expression<PrimitiveNumber> *op) {
            this->operands.emplace_back(op);
        }

    };


    template<typename PrimitiveNumber>
    class ExpressionNumber : public Expression<PrimitiveNumber> {
        PrimitiveNumber value;
    public:
        ExpressionNumber(PrimitiveNumber value) : Expression<PrimitiveNumber>(Type::Number), value(value) { }

        void setValue(PrimitiveNumber value) {
            if (this->type == Type::Number) {
                this->value = value;
            } else {
                throw invalid_argument("unable to set value for an expression with type " + this->type);
            }
        }

        PrimitiveNumber __eval() {
            return value;
        }
    };

    template<typename PrimitiveNumber>
    class Calculator {

        void tokenize(const string &expression, vector<pair<Type, string>> &tokens) {
            unsigned long startIndex = 0;
            for (unsigned long i = 0; i < expression.size(); i++) {
                char c = expression.at(i);
                if (c == '+' || c == '-' || c == '/' || c == '*') {
                    tokens.emplace_back(Type::Number, expression.substr(startIndex, i - startIndex));
                    Type type = (Type) c;
                    tokens.push_back({type, expression.substr(i, 1)});
                    startIndex = i + 1;
                }
            }
            if (startIndex < expression.size()) {
                tokens.push_back({Type::Number, expression.substr(startIndex)});
            }
        }

        void build_operation_expression(stack<Expression<PrimitiveNumber> *> &expressionStack,
                                        pair<Type, string> &token
        ) {
            ExpressionOperation<PrimitiveNumber> *expression = new ExpressionOperation<PrimitiveNumber>(
                    token.first);
            if (expressionStack.top()->getType() == Type::Number) {
                expression->addOperand(expressionStack.top());
                expressionStack.pop();
            } else {
                expression->addOperand(expressionStack.top());
                expressionStack.pop();
            }
            if (expressionStack.size() > 0 && (expressionStack.top()->getType() != Type::Number)) {
                auto *oExpression = (ExpressionOperation<PrimitiveNumber> *) expressionStack.top();

                oExpression->addOperand(expression);
            }
            expressionStack.push(expression);
        }

        void build_number_expression(stack<Expression<PrimitiveNumber> *> &expressionStack, pair<Type, string> &token) {
            PrimitiveNumber number = strtold(token.second.c_str(), nullptr);
            auto *expression = new ExpressionNumber<PrimitiveNumber>(token.first);
            expression->setValue(number);

            if (expressionStack.size() > 0 && (expressionStack.top()->getType() == Type::Multiplication ||
                                               expressionStack.top()->getType() == Type::Division)) {
                auto *oExpression = (ExpressionOperation<PrimitiveNumber> *) expressionStack.top();
                oExpression->addOperand(expression);

            } else {
                expressionStack.push(expression);
            }
        }

        Expression<PrimitiveNumber> *build_expr(vector<pair<Type, string>> &tokens) {
            //vector<Expression<PrimitiveNumber> *> expressionSequence;
            //Expression<PrimitiveNumber> *lastOperation = nullptr;
            stack<Expression<PrimitiveNumber> *> expressionStack;
            for (unsigned long i = 0; i < tokens.size(); i++) {
                //expressionSequence.emplace_back(expression);
                auto token = tokens[i];
                if (token.first != Type::Number) {
                    build_operation_expression(expressionStack, token);
                } else {
                    build_number_expression(expressionStack, token);
                }
            }
            while (expressionStack.size() > 1) {

                auto expressionTop = expressionStack.top();
                if (expressionTop->getType() == Type::Number) {
                    expressionStack.pop();
                    if (expressionStack.top()->getType() != Type::Number) {
                        auto *oExpression = (ExpressionOperation<PrimitiveNumber> *) expressionStack.top();
                        oExpression->addOperand(expressionTop);
                    }
                } else {
                    expressionStack.pop();
                }
            }
            return expressionStack.top();
        }

    public:

        PrimitiveNumber eval(const string &equation) {
            vector<pair<Type, string>> tokens;
            tokenize(equation, tokens);
            Expression<PrimitiveNumber> *exp = build_expr(tokens);
            return exp->eval();
        }
    };

    void main() {
        string equation;
        Calculator<int> calculator;



        assert(calculator.eval("5+5") == 10);
        assert(calculator.eval("5/5") == 1);
        assert(calculator.eval("5*5") == 25);
        assert(calculator.eval("5-5") == 0);

        assert(calculator.eval("5+5+5") == 15);

        assert(calculator.eval("5*5+5") == 30);
        assert(calculator.eval("5+5-5") == 5);
        assert(calculator.eval("5*5*5") == 125);
        assert(calculator.eval("5*5+5+2") == 32);

        /*
        do {
            getline(cin, equation);
            int result = calculator.eval(equation);
            cout << result << endl;
        } while (equation != "end");
        */
    }

}
