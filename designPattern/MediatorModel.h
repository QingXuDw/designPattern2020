#pragma once
#include <string>
#include <iostream>
#include "BaseClasses.h"
class Colleague;

class Mediator
{
public:
	virtual void send(std::string  msg, Colleague* p) = 0;
};

class Colleague
{
protected:
	Mediator* m_mediator;
public:
	Colleague(Mediator* p)
	{
		m_mediator = p;
	}
	virtual void send(std::string msg) = 0;
	virtual void notify(std::string msg) = 0;
};

class ConcreteColleague_0 : public Colleague
{
public:
	ConcreteColleague_0(Mediator* p) : Colleague(p) {}
	void send(std::string msg)
	{
		m_mediator->send(msg, this);
	}
	void notify(std::string msg)
	{
		std::cout << "房东 收到了消息：" << msg << std::endl;
	}
};

class ConcreteColleague_1 : public Colleague
{
public:
	ConcreteColleague_1(Mediator* p) : Colleague(p) {}
	void send(std::string msg)
	{
		m_mediator->send(msg, this);
	}
	void notify(std::string msg)
	{
		std::cout << "游客 收到了消息：" << msg << std::endl;
	}
};

class ConcreteMediator : public Mediator
{
private:
	// 这里也可以是一个列表
	Colleague* m_p1;
	Colleague* m_p2;
public:
	void addColleague(Colleague* p1, Colleague* p2)
	{
		m_p1 = p1;
		m_p2 = p2;
	}
	void send(std::string msg, Colleague* p)
	{
		// 这里接受来自一个同事发过来的消息，具体应该给谁要根据需求来
		// 这里知识一个很简单的应用。比如该类总可以是有两个队列。
		// 一个队列是客户，一个队列是客服
		if (p == m_p1)
			m_p2->notify(msg);
		else
			m_p1->notify(msg);
	}
};
class MediatorManager : public CommandReceiver {
private:
	std::string str;
	MediatorManager() : CommandReceiver("mediator") {}
protected:
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		ConcreteMediator* p = new ConcreteMediator();
		Colleague* pCol1 = new ConcreteColleague_0(p);
		Colleague* pCol2 = new ConcreteColleague_1(p);
		p->addColleague(pCol1, pCol2);
		removeBlank(cmd);
		if (subCmd == "make") {
			cout << "房东-中介-游客已构建！" << endl;
			return true;
		}
		if (subCmd == "sendmessage") {
			std::string paramTag1 = sliceCommand(cmd);
			int a1 = std::stoi(paramTag1);
			removeBlank(cmd);

			std::string paramTag2 = sliceCommand(cmd);
			removeBlank(cmd);
			if (a1 == 1)
			{
				pCol1->send(paramTag2);
			
			}
			if (a1 == 2)
				pCol2->send(paramTag2);
			return true;
		}
		return false;
	}
	virtual void printHelp(int level) {
		__super::printHelp(level);
		level++;
		std::string head(level * 3, '-');
		std::cout << head + "make " << std::endl;	//输出子指令
		std::cout << head + "sendmessage 1/2(发送方：1代表房东，2代表游客) message(要说的话)" << std::endl;	//输出子指令
	}
public:
	//标记复制构造函数为删除，用于实现单例
	MediatorManager(const MediatorManager&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	MediatorManager& operator=(const MediatorManager&) = delete;
	/*获取当前接收器的引用
	* 获取全局唯一当前接收器的实例的引用，用于实现单例。
	* @return TestSpot& 当前接收器的引用
	*/
	static MediatorManager& getInstance() {
		static MediatorManager reciver;
		return reciver;
	}
};