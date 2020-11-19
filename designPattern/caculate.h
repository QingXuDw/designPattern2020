#pragma once
#include<string>
#include<vector>
#include <stack>
#include <map>
#include"BaseClasses.h"
#include"TravelPlan.h"

namespace wsq_cal {
    using namespace std;
    class Expression : public DPObject
    {
    public:
        //������ʽ����ֵ������var�е�key�ǹ�ʽ�еĲ�����valueֵ�Ǿ��������
        //��a = 100; b = 20; c = 40
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

        //��map��ȡ��������ֵ
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

    //�ӷ�������
    class AddExpression : public SymbolExpression
    {
    public:
        AddExpression(Expression* left, Expression* right) : SymbolExpression(left, right)
        {
        }

        //�������������ʽ����Ľ��������
        int interpreter(map<string, int>& var)
        {
            return left->interpreter(var) + right->interpreter(var);
        }
        ~AddExpression()
        {
            cout << "~AddExpression()" << endl;
        }
    };

    //����������
    class SubExpression : public SymbolExpression
    {
    public:
        SubExpression(Expression* left, Expression* right) : SymbolExpression(left, right)
        {
        }

        //�������������ʽ����Ľ�����
        int interpreter(map<string, int>& var)
        {
            return left->interpreter(var) - right->interpreter(var);
        }

        ~SubExpression()
        {
            cout << "~SubExpression()" << endl;
        }
    };

    //*********************************��������װ��***************************************
    //��������װ�࣬������Ǹ��ݵ����ط�����з�װ��Ŀ������Clientֻ��ֱ�����Ѵ򽻵����൱��Facade
    class Calculator : public DPObject
    {
    private:
        Expression* expression;
    public:
        //���캯�����Σ����������ʽ�������﷨��
        Calculator(string expStr)
        {
            expression = NULL;

            //ջ�������ݴ��м���
            stack<Expression*> stkExp;

            Expression* left = NULL;
            Expression* right = NULL;

            /*������������ʽ����:a+b-c)�����յ��﷨�����£�
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
                case '+':  //�ӷ�
                    //1.�ȴ�ջ��ȡ���������
                    left = stkExp.top();
                    stkExp.pop();

                    //2.�ӱ��ʽ��ȡ��+�ź�����Ҳ��������������ս����������
                    right = new VarExpression(expStr.substr(++i, 1));

                    //3.�����Ҳ�������ӣ����ѽ������ջ��
                    stkExp.push(new AddExpression(left, right));

                    break;

                case '-':
                    //1.�ȴ�ջ��ȡ���������
                    left = stkExp.top();
                    stkExp.pop();

                    //2.�ӱ��ʽ��ȡ��+�ź�����Ҳ��������������ս����������
                    right = new VarExpression(expStr.substr(++i, 1));

                    //3.�����Ҳ�������������ѽ������ջ��
                    stkExp.push(new SubExpression(left, right));

                    break;

                default:
                    //����Ǳ������ս��������a+b+c�е�a\b\c��
                    //��ֱ�����ɶ�Ӧ�ı�������������
                    stkExp.push(new VarExpression(expStr.substr(i, 1)));
                }
            }

            //ջ�б���ľ��������﷨���ĸ���㣨����ΪSuuExpression����
            if (!stkExp.empty())
            {
                expression = stkExp.top();
                stkExp.pop();
            }
        }

        void deltree(Expression* expression)
        {
            SymbolExpression* branch = dynamic_cast<SymbolExpression*>(expression);
            //Ҷ�ӽ��
            if (branch == NULL)
            {
                delete expression;
            }
            else  //��֧���
            {
                //������
                deltree(branch->getLeft());

                //������
                deltree(branch->getRight());

                //���
                delete expression;
            }
        }

        ~Calculator()
        {
            deltree(expression);
            expression = NULL;
        }

        //��ʼ����
        int run(map<string, int>& var)
        {
            return (expression == NULL) ? 0 : expression->interpreter(var);
        }
    };
}