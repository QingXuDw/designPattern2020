#pragma once
#include<string>
#include"BaseClasses.h"
struct Description: public DPObject {
public:
	std::string content;
};


struct Path: public DPObject {
public:
	std::string vehicle;
};

typedef CommandReciver Spot;

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

class AbstractPlanFactory: public DPObject {
public:
	virtual Path* makePath() = 0;
	virtual Description* makeDescription() = 0;
	virtual Spot* makeSpot() = 0;
};



class PlanBuilder : public DPObject {
public:
	virtual void buildPlan() = 0;
	virtual void buildPath() = 0;
	virtual void buildDescription(std::string str) = 0;
	virtual void buildSpot(CommandReciver* commandReciver) = 0;
	virtual Plan* getMacroPlan() = 0;
};



