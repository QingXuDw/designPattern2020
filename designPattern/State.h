#pragma once
#include <iostream>
#include"BaseClasses.h"
#include"TravelPlan.h"
#include"Flyweight.h"
using namespace std;
//状态模式实现
class Context;
//载具状态
class Vehicle_State : public DPObject
{
public:
	virtual void Handle(Context* pContext) = 0;
};

class Waiting : public Vehicle_State
{
public:
	virtual void Handle(Context* pContext)
	{
		std::cout << "当前载具为等待状态！" << std::endl;
	}
};

class Running : public Vehicle_State
{
public:
	virtual void Handle(Context* pContext)
	{
		std::cout << "当前载具为运行状态！" << std::endl;
	}
};

class Context : public DPObject
{
public:
	Context(Vehicle_State* pState) : m_pState(pState) {}

	void Request()
	{
		if (m_pState)
		{
			m_pState->Handle(this);
		}
	}

	void ChangeState(Vehicle_State* pState)
	{
		m_pState = pState;
	}

private:
	Vehicle_State* m_pState;
};


class Vehicle : public CommandReceiver {
private:
	//记录的字符串
	std::string str;
	/*构造函数
	* 构造函数为private，用于实现单例，tag为"Vehicle"
	* @return void
	*/
	Vehicle() : CommandReceiver("vehicle") {}
protected:
	/*执行指令
	* 重载父类执行指令的纯虚函数，根据输入的命令执行相应操作
	* @param cmd 用户输入的指令内容
	* @return bool 指令格式是否正确
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "all") {
			FlyweightFactory Fac;//整个过程值采用一个工厂
			Flyweight* pw = Fac.GetFlyWeight("W");//获取W对应的模块，相当于用属性列表给固定部分穿上衣服
			Flyweight* pc = Fac.GetFlyWeight("C");//获取C对应的模块
			Flyweight* pp = Fac.GetFlyWeight("P");
			std::cout << "当前可供共享的模块有:" << Fac.countN() << "个!" << std::endl;
			delete pw;
			delete pc;
			delete pp;
			return true;
		}
		else if (subCmd == "state") {
			int ord = 0;
			Vehicle_State* wait = new Waiting();
			Context* pContext = new Context(wait);
			pContext->Request();
			std::cout << "如果你想改变状态为运行请按1" << std::endl;
			cin >> ord;
			getchar();
			if (ord == 1)
			{
				Vehicle_State* run = new Running();
				pContext->ChangeState(run);
				pContext->Request();
				delete run;
			}
			delete wait;
			delete pContext;
			return true;
		}
		return false;
	}
	/*打印可用指令
	* 重载父类虚函数，根据level打印对应格式的指令，以及可用子指令
	* @param level 当前Reciver在Reciver树中的层级
	* @return void
	*/
	virtual void printHelp(int level) {
		__super::printHelp(level);				//调用父类的默认printHelp函数，递归输出当前及子接收器的tag
		level++;								//将子指令显示到下一层
		std::string head(level * 3, '-');
		std::cout << head + "all" << std::endl;	//输出子指令
		std::cout << head + "state" << std::endl;
	}
public:
	//标记复制构造函数为删除，用于实现单例
	Vehicle(const Vehicle&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	Vehicle& operator=(const Vehicle&) = delete;
	/*获取当前接收器的引用
	* 获取全局唯一当前接收器的实例的引用，用于实现单例。
	* @return Mountain& 当前接收器的引用
	*/
	static Vehicle& getInstance() {
		static Vehicle reciver;
		return reciver;
	}
};
