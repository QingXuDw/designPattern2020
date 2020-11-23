#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include "BaseClasses.h"
#include "TravelPlan.h"

//参观冰雪动物园，iterator
class CIceZoo:public DPObject
{
protected:
	std::vector<std::string> animallist = {"企鹅","海豹","白鲸","北极熊"};  //动物列表,按参观顺序排列
public:
	//iterator类，内部类
	class CIterator:public DPObject
	{
	public:
		/**
		* iterator初始化函数
		* @param iz1 对应动物园的指针
		*/
		CIterator(CIceZoo* iz1) {
			iz = iz1;  //获取参观的动物园的指针
		}

		/**
		* 判断是否还有未参观的动物
		* @return bool
		*/
		bool hasNext() {
			if (index < iz->animallist.size()) {
				return true;
			}
			return false;
		}

		/**
		* 返回当前正在参观的动物的信息，并前往参观下一种动物
		* @return string 动物名
		*/
		string Next() {
			return iz->animallist[index++];
		}
	private:
		int index = 0;  //当前正在参观的动物的序号
		CIceZoo* iz; //iterator对应动物园的指针
	};
};

class IceZooManager :public CommandReceiver {
private:
	//记录的字符串
	std::string str;
	/*构造函数
	* 构造函数为private，用于实现单例，tag为"choose"
	* @return void
	*/
	IceZooManager() : CommandReceiver("iceZoo") {}
protected:
	/*执行指令
	* 重载父类执行指令的纯虚函数，根据输入的命令执行相应操作
	* @param cmd 用户输入的指令内容
	* @return bool 指令格式是否正确
	*/
	bool executeCommand(std::string cmd) {
		using namespace std;
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd != "") {
			return false;
		}
		CIceZoo* zoo1 = new CIceZoo;
		CIceZoo::CIterator* itr = new CIceZoo::CIterator(zoo1);
		cout << "欢迎游览冰雪动物园！" << endl;
		while (itr->hasNext()) {  //遍历游览动物园
			cout << "您正在游览" << itr->Next() << "馆；" << endl;
			Sleep(500);
		}
		cout << "您已离开冰雪动物园。" << endl;
		delete(itr);
		delete(zoo1);
		return true;
	}
public:
	//标记复制构造函数为删除，用于实现单例
	IceZooManager(const IceZooManager&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	IceZooManager& operator=(const IceZooManager&) = delete;
	/*获取当前接收器的引用
	* 获取全局唯一当前接收器的实例的引用，用于实现单例。
	* @return Mountain& 当前接收器的引用
	*/
	static IceZooManager& getInstance() {
		static IceZooManager receiver;
		return receiver;
	}
};

class IceZooFactory : public AbstractPlanFactory {
public:
	/*生成路径
	* @return Path* 生成的路径
	*/
	Path* makePath() {
		Path* path = new Path();
		path->vehicle = "walk";
		return path;
	}
	/*生成描述
	* @return Path* 生成的描述
	*/
	Description* makeDescription() {
		Description* des = new Description();
		des->content = "冰雪动物园实现了迭代器模式，详情见头文件CIceZoo.h";
		return des;
	}
	/*生成目标地点
	* @return Path* 生成的目标地点
	*/
	Spot* makeSpot() {
		Spot& spot = IceZooManager::getInstance();
		return &spot;
	}
};