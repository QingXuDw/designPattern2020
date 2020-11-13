#pragma once
#include <iostream>
#include"BaseClasses.h"
#include"TravelPlan.h"
using namespace std;
#define  free_ptr(p) \
	if(p) delete p; p = NULL;//释放指针
/*
策略模式让你可以动态的改变对象的行为，动态修改策略
*/
//抽象策略类登山
class Mountaineering : public DPObject
{
public:
	virtual ~Mountaineering() {};
	virtual void choose() = 0;
};
//步行模式
class Walking : public Mountaineering {
public:
	void choose() {
		std::cout << "You have chose the walking strategy" << std::endl;
	};
};
//缆车模式
class Cable_car : public Mountaineering {
public:
	void choose() {
		std::cout << "You have chose the Cable car strategy" << std::endl;
	};
};
//小火车模式
class Puddle_jumper : public Mountaineering {
public:
	void choose() {
		std::cout << "You have chose the puddle_jumper strategy" << std::endl;
	};
};
//登山环境类
class MountainMode : public DPObject {
public:
	MountainMode(Mountaineering* mountain) : m_mountain(mountain) {};
	~MountainMode() { free_ptr(m_mountain); }
	void choose() {
		m_mountain->choose();
	};
private:
	Mountaineering* m_mountain;
};


class Mountain : public CommandReceiver {
private:
	//记录的字符串
	std::string str;
	/*构造函数
	* 构造函数为private，用于实现单例，tag为"choose"
	* @return void
	*/
	Mountain() : CommandReceiver("mountain") {}
protected:
	/*执行指令
	* 重载父类执行指令的纯虚函数，根据输入的命令执行相应操作
	* @param cmd 用户输入的指令内容
	* @return bool 指令格式是否正确
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "choose") {
			int ord = 0;
			std::cout << "欢迎你来登山，选一种上山的方式吧！(请输入对应编号.)" << std::endl;
			std::cout << "1.11路公交上山	2.乘缆车上山	3.骑欢快的小火车上山哦~" << std::endl;
			std::cin >> ord;
			getchar();
			switch (ord) {
			case 1: {
				MountainMode* walk = new MountainMode(new Walking());
				walk->choose();
				free_ptr(walk);
			}break;
			case 2: {
				MountainMode* cable_car = new MountainMode(new Cable_car());
				cable_car->choose();
				free_ptr(cable_car);
			}break;
			case 3: {
				MountainMode* puddle_jumper = new MountainMode(new Puddle_jumper());
				puddle_jumper->choose();
				free_ptr(puddle_jumper);
			}break;
			default:
			{
				std::cout << "Sorry，你输入了错误的编号请重头再来！" << std::endl;
			}
			}
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
		std::cout << head + "choose" << std::endl;	//输出子指令
	}
public:
	//标记复制构造函数为删除，用于实现单例
	Mountain(const Mountain&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	Mountain& operator=(const Mountain&) = delete;
	/*获取当前接收器的引用
	* 获取全局唯一当前接收器的实例的引用，用于实现单例。
	* @return Mountain& 当前接收器的引用
	*/
	static Mountain& getInstance() {
		static Mountain reciver;
		return reciver;
	}
};


class MountainPlanFactory : public AbstractPlanFactory {
public:
	/*生成路径
	* @return Path* 生成的路径
	*/
	Path* makePath() {
		Path* path = new Path();
		path->vehicle = "car";
		return path;
	}
	/*生成描述
	* @return Path* 生成的描述
	*/
	Description* makeDescription() {
		Description* des = new Description();
		des->content = "登雪山模块实现了策略模式，具体代码见Strategy.h";
		return des;
	}
	/*生成目标地点
	* @return Path* 生成的目标地点
	*/
	Spot* makeSpot() {
		Spot& spot = Mountain::getInstance();
		return &spot;
	}
};
