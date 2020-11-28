#pragma once
#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <cstdlib>
#include <vector>
#include <sstream>
#include "BaseClasses.h"
#include "ShoppingMall.h"

class Clothes {/*��װ����*/
public:
    Clothes(std::string name, int sex, int price);
    ~Clothes();

public:
    std::string _name;/*��װ����*/
    int _price;/*�۸�*/
    int _sex;/*�Ա�*/
};
Clothes::Clothes(std::string name, int sex, int price) {
    _name = name;
    _sex = sex;
    _price = price;
}

Clothes::~Clothes() {

}
/*��ѯ�ӿ�*/
class ISpecification {
public:
    ISpecification();
    ~ISpecification();

    virtual bool isBy(Clothes* iclothes);
};

ISpecification::ISpecification() {

}
ISpecification::~ISpecification() {

}
bool ISpecification::isBy(Clothes* iclothes) {
    return true;
}
/*���Ա��ѯ�Ľӿ�*/
class SexSpecification :public ISpecification {
public:
    SexSpecification(int sex);
    bool isBy(Clothes* iclothes)override;
private:
    int _sex;
};
SexSpecification::SexSpecification(int sex) {
    _sex = sex;
}
bool SexSpecification::isBy(Clothes* iclothes) {
    if (_sex == iclothes->_sex) {
        return true;
    }
    return false;
}
/*���ռ۸�С�ڲ�ѯ�Ľӿ�*/
class PriceThenSpecification :public ISpecification {
public:
    PriceThenSpecification(int price);
    bool isBy(Clothes* iclothes)override;
private:
    int _price;
};
PriceThenSpecification::PriceThenSpecification(int price) {
    _price = price;
};
bool PriceThenSpecification::isBy(Clothes* iclothes) {
    if (iclothes->_price <= _price) {
        return true;
    }
    return false;
};
/*���ýӿ�*/
class IUserProviderEx {
public:
    virtual std::vector<Clothes*> findUser(ISpecification* spec) = 0;
};
/*����ʵ�ֽӿ�*/
class UserProviderEx :public IUserProviderEx {
public:
    UserProviderEx(std::vector<Clothes*>clothes);
    virtual std::vector<Clothes*> findUser(ISpecification* spec)override;
private:
    std::vector<Clothes*>_clothes;
};
UserProviderEx::UserProviderEx(std::vector<Clothes*> clothes) {
    _clothes = clothes;
}
std::vector<Clothes*>UserProviderEx::findUser(ISpecification* spec) {
    std::vector<Clothes*> l;
    int cnt = _clothes.size();
    for (int i = 0; i < cnt; i++) {
        if (spec->isBy(_clothes.at(i))) {
            l.push_back(_clothes.at(i));
        }
    }
    return l;
}


/************************************************************************
*							clothesshopģ��							*
*************************************************************************/

class clothesshop {
    clothesshop() {};
public:
    //��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
    clothesshop(const clothesshop&) = delete;
    //��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
    clothesshop& operator=(const clothesshop&) = delete;
    /*
    * ��ȡȫ��Ψһ�����ã�����ʵ�ֵ�����
    */
    static clothesshop& getInstance() {
        static clothesshop instance;
        return instance;
    }
    void buy() {
        Clothes* u1 = new Clothes("��������װ", 1, 160);
        Clothes* u2 = new Clothes("��������װ", 0, 170);
        Clothes* u3 = new Clothes("�����װ", 1, 160);
        Clothes* u4 = new Clothes("�����װ", 1, 165);
        Clothes* u5 = new Clothes("�����װ", 0, 175);
        Clothes* u6 = new Clothes("������װ", 0, 180);
        Clothes* u7 = new Clothes("��ѩ������װ", 1, 165);
        Clothes* u8 = new Clothes("ѩҹ������װ", 0, 175);
        Clothes* u9 = new Clothes("��ѩ��Ե��װ", 1, 160);
        std::vector<Clothes*> clothes;
        clothes.push_back(u1);
        clothes.push_back(u2);
        clothes.push_back(u3);
        clothes.push_back(u4);
        clothes.push_back(u5);
        clothes.push_back(u6);
        clothes.push_back(u7);
        clothes.push_back(u8);
        clothes.push_back(u9);
        IUserProviderEx* ProviderEx = new UserProviderEx(clothes);
        std::string str;
        std::cout << "������밴���Ա��ѯ������sex��������밴�ռ۸��ѯ������price" << std::endl;
        std::getline(std::cin, str);
        while (1) {
            if (str == "price" || str == "sex") {
                break;
            }
            else {
                std::cin.clear();
                std::cin.sync();
                std::cout << "�������ָ���������������룺" << std::endl;
                std::getline(std::cin, str);
            }
        }
        int a, b;
        if (str == "sex") {
            std::cout << "�����������ѯ�ķ�װ���Ա𣬣�0-��װ��1-Ůװ����" << std::endl;
            std::cin >> a;
            while(1) {
                if (std::cin.good()&&a == 0 || a == 1&&std::cin.good()) {
                    break;
                }
                else {
                    std::cin.clear();
                    std::cin.ignore(1024,'\n');
                    std::cout << "�������ָ���������������룺" << std::endl;
                    std::cin >> a;
                }   
            }
                ISpecification* s1 = new SexSpecification(a);
                std::vector<Clothes*>l3 = ProviderEx->findUser(s1);

                int num3 = l3.size();
                if (num3 == 0) {
                    std::cout << "��������Ա𲻴��ڣ�" << std::endl;
                }
                else {
                    for (int i = 0; i < num3; i++)
                        std::cout << "���ƣ�" << l3.at(i)->_name.c_str() << "�Ա�" << l3.at(i)->_sex << "�۸�" << l3.at(i)->_price << std::endl;
                }
        }
        else if (str == "price")
        {
            std::cout << "�����������ѯ�ķ�װ����ߵļ۸�" << std::endl;
            std::cin >> b;
            while (1) {
                if (std::cin.good())
                {
                    break;
                }
                else
                {
                    std::cin.clear();
                    std::cin.ignore(1024,'\n');
                    std::cout << "�������ָ���������������룺" << std::endl;
                    std::cin >> b;
                }
            }
            ISpecification* s2 = new PriceThenSpecification(b);
            std::vector<Clothes*>l4 = ProviderEx->findUser(s2);
            std::cout << std::endl << std::endl;
            int num4 = l4.size();
            if (num4 == 0) {
                std::cout << "��������Ǯ�����ɣ�" << std::endl;
            }
            else {
                for (int i = 0; i < num4; i++) {
                    std::cout << "���ƣ�" << l4.at(i)->_name.c_str() << "�Ա�" << l4.at(i)->_sex << "�۸�" << l4.at(i)->_price << std::endl;
                }
            }
        }
        std::cin.clear();
        string tmp;
        std::getline(std::cin,tmp);
    }
};



