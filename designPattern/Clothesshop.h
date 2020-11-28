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

class Clothes {/*服装基类*/
public:
    Clothes(std::string name, int sex, int price);
    ~Clothes();

public:
    std::string _name;/*套装名称*/
    int _price;/*价格*/
    int _sex;/*性别*/
};
Clothes::Clothes(std::string name, int sex, int price) {
    _name = name;
    _sex = sex;
    _price = price;
}

Clothes::~Clothes() {

}
/*查询接口*/
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
/*按性别查询的接口*/
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
/*按照价格小于查询的接口*/
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
/*调用接口*/
class IUserProviderEx {
public:
    virtual std::vector<Clothes*> findUser(ISpecification* spec) = 0;
};
/*具体实现接口*/
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
*							clothesshop模块							*
*************************************************************************/

class clothesshop {
    clothesshop() {};
public:
    //标记复制构造函数为删除，用于实现单例
    clothesshop(const clothesshop&) = delete;
    //标记拷贝赋值操作符为删除，用于实现单例
    clothesshop& operator=(const clothesshop&) = delete;
    /*
    * 获取全局唯一的引用，用于实现单例。
    */
    static clothesshop& getInstance() {
        static clothesshop instance;
        return instance;
    }
    void buy() {
        Clothes* u1 = new Clothes("北极熊套装", 1, 160);
        Clothes* u2 = new Clothes("北极熊套装", 0, 170);
        Clothes* u3 = new Clothes("企鹅套装", 1, 160);
        Clothes* u4 = new Clothes("企鹅套装", 1, 165);
        Clothes* u5 = new Clothes("企鹅套装", 0, 175);
        Clothes* u6 = new Clothes("海豹套装", 0, 180);
        Clothes* u7 = new Clothes("白雪公主套装", 1, 165);
        Clothes* u8 = new Clothes("雪夜王子套装", 0, 175);
        Clothes* u9 = new Clothes("冰雪奇缘套装", 1, 160);
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
        std::cout << "如果您想按照性别查询请输入sex，如果您想按照价格查询请输入price" << std::endl;
        std::getline(std::cin, str);
        int a, b;
        if (str == "sex") {
            std::cout << "请输入您想查询的服装的性别，（0-男装，1-女装）：" << std::endl;
            std::cin >> a;
            ISpecification* s1 = new SexSpecification(a);
            std::vector<Clothes*>l3 = ProviderEx->findUser(s1);

            int num3 = l3.size();
            if (num3 == 0) {
                std::cout << "您输入的性别不存在！" << std::endl;
            }
            else {
                for (int i = 0; i < num3; i++)
                    std::cout << "名称：" << l3.at(i)->_name.c_str() << "性别：" << l3.at(i)->_sex << "价格：" << l3.at(i)->_price << std::endl;
            }
        }
        else if (str == "price")
        {
            std::cout << "请输入您想查询的服装的最高的价格：" << std::endl;
            std::cin >> b;
            ISpecification* s2 = new PriceThenSpecification(b);
            std::vector<Clothes*>l4 = ProviderEx->findUser(s2);
            std::cout << std::endl << std::endl;
            int num4 = l4.size();
            if (num4 == 0) {
                std::cout << "您再挣点钱再来吧！" << std::endl;
            }
            else {
                for (int i = 0; i < num4; i++) {
                    std::cout << "名称：" << l4.at(i)->_name.c_str() << "性别：" << l4.at(i)->_sex << "价格：" << l4.at(i)->_price << std::endl;
                }
            }
        }
        std::cin.clear();
		std::string tmp;
        std::getline(std::cin,tmp);
    }
};



