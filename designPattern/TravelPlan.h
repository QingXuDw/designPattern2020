#pragma once
#include<string>
#include"BaseClasses.h"
/************************************************************************
*								游览计划模块								*
*************************************************************************/
//描述（针对每一个计划的描述）
struct Description: public DPObject {
public:
	std::string content;
};

//路径（从上一个目标位置到当前目标位置的方式
struct Path: public DPObject {
public:
	std::string vehicle;
};

//景点（每一个计划中的目标位置）
typedef CommandReceiver Spot;

//计划
struct Plan: public DPObject {
public:
	Path* path;
	Description* description;
	Spot* spot;
	~Plan() {
		if (path != nullptr) { delete path; }
		if (description != nullptr) { delete description; }
	}

};

//抽象计划工厂
class AbstractPlanFactory: public DPObject {
public:
	virtual Path* makePath() = 0;
	virtual Description* makeDescription() = 0;
	virtual Spot* makeSpot() = 0;
};


//计划建造器
class PlanBuilder : public DPObject {
public:
	virtual void buildPlan() = 0;
	virtual void buildPath() = 0;
	virtual void buildDescription(std::string str) = 0;
	virtual void buildSpot(CommandReceiver* commandReciver) = 0;
	virtual Plan* getMacroPlan() = 0;
};



