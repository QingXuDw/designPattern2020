#pragma once
#include<iostream>
#include"BaseClasses.h"
#include<map>
#include<string>
using namespace std;

class Flyweight : public DPObject//抽象的享元类
{
public:
	virtual void Operation(int i) = 0;
};
class ConcreteFlyWeight :public Flyweight//共享的子类
{
public:
	void Operation(int i)
	{
		std::cout << "共享的FlyWeight:" << i << std::endl;
	}
};
class UnsharedConcreteFlyweight :public Flyweight//不共享的子类
{
	void Operation(int i)
	{
		std::cout << "不共享的FlyWeight:" << i << std::endl;
	}
};
class FlyweightFactory : public DPObject//享元工厂
{
private:
	map<string, Flyweight*>flyweights;//模块名列表
public:
	FlyweightFactory()//初始共享模块列表
	{
		flyweights["W"] = new ConcreteFlyWeight();//这里需要用堆，因为这是给客户程序返回的，如果不用堆，则会返回局部对象的引用
		flyweights["C"] = new ConcreteFlyWeight();
		flyweights["P"] = new ConcreteFlyWeight();//所有的属性为“P”的模块都只对应这个一个实例，这正是享元模式的精髓所在呀
	}

	Flyweight* GetFlyWeight(string key)//工厂返回享元对象，而这些对象的属性都存放在一个该工厂的模块名列表中
	{
		if (!flyweights.count(key))//先检查下是否在列表中，如果不在则新建该列表项
		{
			flyweights[key] = new ConcreteFlyWeight();//这里只能返回堆空间
		}
		return flyweights[key];
	}
	map<string, Flyweight*>::size_type countN()//返回当前有多少个可供共享的模块
	{
		return flyweights.size();
	}
};
