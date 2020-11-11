#pragma once
#include<string>
#include<vector>
#include <stack>
#include <map>
#include"BaseClasses.h"
#include"TravelPlan.h"

using namespace std;

class Expression
{
public:
    //解析公式和数值，其中var中的key是公式中的参数，value值是具体的数字
    //如a = 100; b = 20; c = 40
    virtual int interpreter(map<string, int>& var) = 0;
    virtual ~Expression() {};
};
class VarExpression : public Expression
{
    string key;
public:
    VarExpression(string key)
    {
        this->key = key;
    }

    //从map中取出变量的值
    int interpreter(map<string, int>& var)
    {
        return var[key];
    }

    ~VarExpression()
    {
        cout << "~VarExpression()" << endl;
    }
};
class SymbolExpression : public Expression
{
protected:
    Expression* left;
    Expression* right;
public:
    SymbolExpression(Expression* left, Expression* right)
    {
        this->left = left;
        this->right = right;
    }

    Expression* getLeft()
    {
        return left;
    }
    Expression* getRight()
    {
        return right;
    }
};

//加法解析器
class AddExpression : public SymbolExpression
{
public:
    AddExpression(Expression* left, Expression* right) : SymbolExpression(left, right)
    {
    }

    //把左右两个表达式运算的结果加起来
    int interpreter(map<string, int>& var)
    {
        return left->interpreter(var) + right->interpreter(var);
    }
    ~AddExpression()
    {
        cout << "~AddExpression()" << endl;
    }
};

//减法解析器
class SubExpression : public SymbolExpression
{
public:
    SubExpression(Expression* left, Expression* right) : SymbolExpression(left, right)
    {
    }

    //把左右两个表达式运算的结果相减
    int interpreter(map<string, int>& var)
    {
        return left->interpreter(var) - right->interpreter(var);
    }

    ~SubExpression()
    {
        cout << "~SubExpression()" << endl;
    }
};

//*********************************解析器封装类***************************************
//解析器封装类，这个类是根据迪米特法则进行封装，目的是让Client只与直接朋友打交道，相当于Facade
class Calculator
{
private:
    Expression* expression;
public:
    //构造函数传参，并解析表达式，构建语法树
    Calculator(string expStr)
    {
        expression = NULL;

        //栈，用来暂存中间结果
        stack<Expression*> stkExp;

        Expression* left = NULL;
        Expression* right = NULL;

        /*从左到向分析表达式（如:a+b-c)，最终的语法树如下：
         *           -
         *         /   \
         *       +     c
         *     /   \
         *    a     b
        */
        for (unsigned int i = 0; i < expStr.length(); i++)
        {
            switch (expStr[i])
            {
            case '+':  //加法
                //1.先从栈中取出左操作数
                left = stkExp.top();
                stkExp.pop();

                //2.从表达式中取出+号后面的右操作数，并生成终结符解析对象
                right = new VarExpression(expStr.substr(++i, 1));

                //3.将左右操作数相加，并把结果放入栈中
                stkExp.push(new AddExpression(left, right));

                break;

            case '-':
                //1.先从栈中取出左操作数
                left = stkExp.top();
                stkExp.pop();

                //2.从表达式中取出+号后面的右操作数，并生成终结符解析对象
                right = new VarExpression(expStr.substr(++i, 1));

                //3.将左右操作数相减，并把结果放入栈中
                stkExp.push(new SubExpression(left, right));

                break;

            default:
                //如果是变量（终结符）：如a+b+c中的a\b\c，
                //则直接生成对应的变量解析器对象
                stkExp.push(new VarExpression(expStr.substr(i, 1)));
            }
        }

        //栈中保存的就是最终语法树的根结点（本例为SuuExpression对象）
        if (!stkExp.empty())
        {
            expression = stkExp.top();
            stkExp.pop();
        }
    }

    void deltree(Expression* expression)
    {
        SymbolExpression* branch = dynamic_cast<SymbolExpression*>(expression);
        //叶子结点
        if (branch == NULL)
        {
            delete expression;
        }
        else  //分支结点
        {
            //左子树
            deltree(branch->getLeft());

            //右子树
            deltree(branch->getRight());

            //结点
            delete expression;
        }
    }

    ~Calculator()
    {
        deltree(expression);
        expression = NULL;
    }

    //开始运算
    int run(map<string, int>& var)
    {
        return (expression == NULL) ? 0 : expression->interpreter(var);
    }
};