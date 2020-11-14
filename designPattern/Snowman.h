#include<iostream>
#include<vector>
#include "BaseClasses.h"
using namespace std;
//Observer.h
class Observer
{
public:
	Observer() {};
	virtual ~Observer()
	{

	};
	virtual void update() = 0;

};

//Subject.h
class Subject
{
public:
	Subject() {};
	virtual ~Subject() {};
	void addObserver(Observer* observer);
	void deleteObserver(Observer* observer);
	void notifyObservers();
	virtual int getStatus() = 0;

	virtual void setStatus(int status) = 0;
private:
	vector<Observer*> m_observers;
};
//Subject.cpp
void Subject::addObserver(Observer* observer)
{
	m_observers.push_back(observer);
}
void Subject::deleteObserver(Observer* observer)
{
	for (vector<Observer*>::iterator iter = m_observers.begin(); iter != m_observers.end(); iter++)
	{
		if (*iter == observer)
		{
			m_observers.erase(iter);
			return;
		}
	}
}
void Subject::notifyObservers() {
	for (vector<Observer*>::iterator iter = m_observers.begin(); iter != m_observers.end(); iter++)
	{
		(*iter)->update();
	}
}
//ConcreteObserver.h
class ConcreteObserver : public Observer
{
public:
	ConcreteObserver(string name, Subject* subject) :m_observerName(name), m_subject(subject) {};
	~ConcreteObserver() {};
	void update();

private:
	string m_observerName;
	Subject* m_subject;
};
//ConcreteSubject.h
class ConcreteSubject : public Subject
{
public:
	ConcreteSubject(string name) : m_subjectName(name) {};
	~ConcreteSubject() {};
	void setStatus(int status);
	int getStatus();

private:
	string m_subjectName;
	int m_status = 0;
};
//ConcreteObserver.cpp
void ConcreteObserver::update()
{
	cout << m_observerName << "看到状态为" << m_subject->getStatus() << endl;
}
//ConcreteSubject.cpp
void ConcreteSubject::setStatus(int status)
{
	m_status = status;
	cout << m_subjectName << "设置状态为" << status << endl;
}
int ConcreteSubject::getStatus()
{
	return m_status;
}

Subject* subject1 = new ConcreteSubject("雪人1");
Subject* subject2 = new ConcreteSubject("雪人2");


//设置初始状态 雪人两个 观察者最多四个，每个观察者只能观察一个雪人
void setInit(int x, int a[4])
{
	for (int i = 0; i < x; i++)
	{
		if (i == 0)
		{
			if (a[i] == 1)
			{
				Observer* observerA = new ConcreteObserver("观察者A", subject1);
				subject1->addObserver(observerA);
				cout << "观察者A观察雪人1" << endl;
			}
			else if (a[i] == 2)
			{
				Observer* observerA = new ConcreteObserver("观察者A", subject2);
				subject2->addObserver(observerA);
				cout << "观察者A观察雪人2" << endl;
			}
		}
		if (i == 1)
		{
			if (a[i] == 1)
			{
				Observer* observerB = new ConcreteObserver("观察者B", subject1);
				subject1->addObserver(observerB);
				cout << "观察者B观察雪人1" << endl;
			}
			else if (a[i] == 2)
			{
				Observer* observerB = new ConcreteObserver("观察者B", subject2);
				subject2->addObserver(observerB);
				cout << "观察者B观察雪人2" << endl;
			}
		}
		if (i == 2)
		{
			if (a[i] == 1)
			{
				Observer* observerC = new ConcreteObserver("观察者C", subject1);
				subject1->addObserver(observerC);
				cout << "观察者C观察雪人1" << endl;
			}
			else if (a[i] == 2)
			{
				Observer* observerC = new ConcreteObserver("观察者C", subject2);
				subject2->addObserver(observerC);
				cout << "观察者C观察雪人2" << endl;
			}
		}
		if (i == 3)
		{
			if (a[i] == 1)
			{
				Observer* observerD = new ConcreteObserver("观察者D", subject1);
				subject1->addObserver(observerD);
				cout << "观察者D观察雪人1" << endl;
			}
			else if (a[i] == 2)
			{
				Observer* observerD = new ConcreteObserver("观察者D", subject2);
				subject2->addObserver(observerD);
				cout << "观察者D观察雪人2" << endl;
			}
		}
	}
}
void setStatus(int sx, int status)
{
	if (sx == 1)
	{
		subject1->setStatus(status);
		subject1->notifyObservers();
	}
	if (sx == 2)
	{
		subject2->setStatus(status);
		subject2->notifyObservers();

	}
}
class SnowmanManager : public CommandReceiver {
private:
	std::string str;
	SnowmanManager() : CommandReceiver("snowman") {}
protected:
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "make") {
			if (cmd == "")
				return false;
			int a[4];
			std::string paramTag1 = sliceCommand(cmd);
			a[0] = std::stoi(paramTag1);
			removeBlank(cmd);
			std::string paramTag2 = sliceCommand(cmd);
			a[1] = std::stoi(paramTag2);
			removeBlank(cmd);
			std::string paramTag3 = sliceCommand(cmd);
			a[2] = std::stoi(paramTag3);
			removeBlank(cmd);
			std::string paramTag4 = sliceCommand(cmd);
			a[3] = std::stoi(paramTag4);
			removeBlank(cmd);
			if ((a[0] != 1 && a[0] != 2) || (a[1] != 1 && a[1] != 2) || (a[2] != 1 && a[2] != 2) || (a[3] != 1 && a[3] != 2))
				return false;

			setInit(4, a);
			return true;
		}
		if (subCmd == "update") {
			if (cmd == "")
				return false;
			std::string paramTag1 = sliceCommand(cmd);
			if ((paramTag1.length() != 1) || (paramTag1[0] != '1'&&paramTag1[0] != '2'))
				return false;
			int a1 = std::stoi(paramTag1);
			removeBlank(cmd);
			std::string paramTag2 = sliceCommand(cmd);
			if ((paramTag2.length() != 1) || (paramTag2[0] < '0'&&paramTag2[0] > '9'))
				return false;
			int a2;
			
			a2 = std::stoi(paramTag2);
			removeBlank(cmd);
			if (a1 != 1 && a1 != 2)
				return false;

			setStatus(a1, a2);
			return true;
		}
		return false;
	}
	virtual void printHelp(int level) {
		__super::printHelp(level);
		level++;
		std::string head(level * 3, '-');
		std::cout << head + "make int1 int2 int3 int4(四个int值，为1或2，代表四个观察者分别观察哪个雪人)" << std::endl;	//输出子指令
		std::cout << head + "update int1(雪人编号1或2) int2(代表雪人状态0~9)" << std::endl;	//输出子指令
	}
public:
	//标记复制构造函数为删除，用于实现单例
	SnowmanManager(const SnowmanManager&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	SnowmanManager& operator=(const SnowmanManager&) = delete;
	/*获取当前接收器的引用
	* 获取全局唯一当前接收器的实例的引用，用于实现单例。
	* @return TestSpot& 当前接收器的引用
	*/
	static SnowmanManager& getInstance() {
		static SnowmanManager receiver;
		return receiver;
	}
};
