#pragma once
#include "pch.h"
#include "../designPattern/State.h"
#include <vector>

using namespace std;

class StateTest : public RedirectIO {
protected:
	//用于维护各子类对象的vector
	vector<Vehicle_State*> states;
	//在states中为每一个子类生成一个对象
	void SetUp() override {
		RedirectIO::SetUp();
		Vehicle_State* p_mou;
		p_mou = new Waiting();
		states.push_back(p_mou);
		p_mou = new Running();
		states.push_back(p_mou);
	}
	//清理states中的全部子类对象
	void TearDown() override {
		RedirectIO::TearDown();
		for (vector<Vehicle_State*>::iterator i = states.begin();
			i != states.end();
			i++)
		{
			S_DELETE((*i));
		}
	}
};

TEST_F(StateTest, Handle) {
	for (std::vector<Vehicle_State*>::iterator i = states.begin();
		i != states.end();
		i++)
	{
		EXPECT_NO_THROW(Context context1(*i));
		Context p_context(*i);
		EXPECT_NO_THROW(p_context.Request());
		EXPECT_NO_THROW(p_context.ChangeState(states[0]));
		EXPECT_NO_THROW(p_context.ChangeState(states[1]));
	}
}

class VehicleTest : public RedirectIO {
protected:
	Vehicle * p_vehicle;
	void SetUp() override {
		RedirectIO::SetUp();
		p_vehicle = &(Vehicle::getInstance());
	}
	void TearDown() override {
		RedirectIO::TearDown();
	}
	static void s_delete(void* ptr) {
		if ((ptr) != nullptr) { delete (ptr); (ptr) = nullptr; }
	}
};

TEST_F(VehicleTest, HandleCommand) {
	std::string result;
	EXPECT_NO_THROW(p_vehicle->handleCommand(""));
	EXPECT_NO_THROW(p_vehicle->handleCommand("vehicle"));
	EXPECT_NO_THROW(p_vehicle->handleCommand("vehicle all"));
	EXPECT_NO_THROW(p_vehicle->handleCommand("1"));
	EXPECT_NO_THROW(p_vehicle->handleCommand("2"));
	EXPECT_NO_THROW(p_vehicle->handleCommand("3"));
	EXPECT_NO_THROW(p_vehicle->handleCommand("4"));
	EXPECT_NO_THROW(p_vehicle->handleCommand("vehicle state"));
	EXPECT_NO_THROW(p_vehicle->handleCommand("vehicle ttt"));
}

TEST_F(VehicleTest, PrintHelp) {
//	EXPECT_NO_THROW(p_vehicle->printHelp(0));
}

