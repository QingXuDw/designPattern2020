#pragma once

#include"BaseClasses.h"

/**
 * 园区游玩项目类
 * 作为咨询内容的一部分，用于向用户介绍园区游玩项目的各类信息
 */
class ParkPlaying : public DPObject
{
public:
	/**
	 * 位置介绍
	 * 向用户介绍园区游玩项目的位置
	 * @return void
	 */
	void Location() {
		std::cout << "  冰封鬼窟位于园区北部" << std::endl;
		std::cout << "  登山体验位于园区南部" << std::endl;
		std::cout << "  动物园位于园区南部" << std::endl;
		std::cout << "  冰雕展览位于园区东北部部" << std::endl;
	}
};

/**
 * 园区设施类
 * 作为咨询内容的一部分，用于向用户介绍园区各类设施的各类信息
 */
class ParkFacility : public DPObject
{
public:
	/**
	 * 位置介绍
	 * 向用户介绍园区内各类设施项目的位置
	 * @return void
	 */
	void Location() {
		std::cout << "  卫生间位置请参考园区地图" << std::endl;
	}
};

/**
 * 园区餐饮类
 * 作为咨询内容的一部分，用于向用户介绍园区内餐厅的各类信息
 */
class ParkEating : public DPObject
{
public:
	/**
	 * 位置介绍
	 * 向用户介绍园区内餐厅的位置
	 * @return void
	 */
	void Location() {
		std::cout << "  餐厅位于园区西北部" << std::endl;
	}
};

/**
 * 园区住宿类
 * 作为咨询内容的一部分，用于向用户介绍园区内酒店旅馆的各类信息
 */
class ParkHousing : public DPObject
{
public:
	/**
	 * 位置介绍
	 * 向用户介绍园区内酒店旅馆的位置
	 * @return void
	 */
	void Location() {
		std::cout << "  酒店位于园区西部" << std::endl;
	}
};

/**
 * 外观类
 * 作为咨询处的主体，帮助用户仅通过此类就可了解到园区内所有内容的信息
 */
class Facade : public DPObject
{
public:
	/**
	 * 外观类构造函数
	 * 在创建外观类的对象的同时分别生成园内各内容类的对象
	 */
	Facade(){
		this->_parkPlaying = new ParkPlaying();
		this->_parkFacility = new ParkFacility();
		this->_parkEating = new ParkEating();
		this->_parkHousing = new ParkHousing();
	}

	/**
	 * 游玩项目查询
	 * 调用游玩项目位置查询
	 * @return void
	 */
	void ConsultPlay() {
		this->_parkPlaying->Location();
	}

	/**
	 * 园内设施查询
	 * 调用园内设施位置查询
	 * @return void
	 */
	void ConsultFacility() {
		this->_parkFacility->Location();
	}

	/**
	 * 园内餐饮查询
	 * 调用园内餐饮位置查询
	 * @return void
	 */
	void ConsultEating() {
		this->_parkEating->Location();
	}

	/**
	 * 园内住宿查询
	 * 调用园内住宿位置查询
	 * @return void
	 */
	void ConsultHousing() {
		this->_parkHousing->Location();
	}
	
	/**
	 * 咨询启动
	 * 用于生成对应的用户界面，接收并处理用户的输入，正确调用相应的函数
	 * @return void
	 */
	void start() {
		std::string c;	//用户键入的咨询命令
		std::string d;	//用于接收多余的字符
		std::cout << "请选择要咨询的内容（1为游乐项目，2为园区设施，3为园区餐饮，4为园区住宿，0为返回）：\n";	//对用户输入命令的提示
		while (std::cin >> c) {		//循环读取命令以实现外币兑换功能可多次使用
			getline(std::cin, d);
			if (c == "1")			//咨询游玩项目
				ConsultPlay();
			else if (c == "2")		//咨询园内设施
				ConsultFacility();
			else if (c == "3")		//咨询园内餐饮
				ConsultEating();
			else if (c == "4")		//咨询园内住宿
				ConsultHousing();
			else if (c == "0") {	//当用户决定退出时跳出循环并给予提示
				std::cout << "成功退出咨询处！" << std::endl;
				return;
			}
			else					//当命令非法时的提示
				std::cout << "输入有误，请重新输入！\n";
		}
	}

	/**
	 * 外观类析构函数
	 * 在对象生命周期结束后分别删除并释放园内各内容对象的空间
	 */
	~Facade() {
		delete this->_parkPlaying;
		delete this->_parkFacility;
		delete this->_parkEating;
		delete this->_parkHousing;

		this->_parkPlaying = NULL;
		this->_parkFacility = NULL;
		this->_parkEating = NULL;
		this->_parkHousing = NULL;
	}

private:
	ParkPlaying* _parkPlaying;
	ParkFacility* _parkFacility;
	ParkEating* _parkEating;
	ParkHousing* _parkHousing;
 
};