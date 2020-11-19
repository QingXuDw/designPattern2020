#pragma once
#include "pch.h"
#include"../designPattern/Strategy.h"
#include"../designPattern/State.h"

namespace wsq
{
	class VehicleTest :public RedirectIO
	{
	protected:
		bool pass;
		void SetUp() override {
			RedirectIO::SetUp();
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
	public:
		void runTest() {
			Vehicle::getInstance().handleCommand("all");
			pass = true;
		}
		void runTest1() {
			Vehicle::getInstance().handleCommand("state");
			pass = true;
		}
	};
	TEST_F(VehicleTest, HandleCommand)
	{
		char temp = '1';
		int count = 0;
		sin << temp;
		std::thread c_thread(&VehicleTest::runTest, this);
		c_thread.detach();
		while (!pass) {
			count++;
			Sleep(50);
			if (count > 10) {
				EXPECT_TRUE(pass);
				break;
			}
		}
	}
	TEST_F(VehicleTest, HandleCommand_2)
	{
		char temp = '0';
		int count = 0;
		sin << temp;
		std::thread c_thread(&VehicleTest::runTest1, this);
		c_thread.detach();
		while (!pass) {
			count++;
			Sleep(50);
			if (count > 10) {
				EXPECT_TRUE(pass);
				break;
			}
		}
	}
	class MountainTest :public RedirectIO
	{
	protected:
		bool pass;
		void SetUp() override {
			RedirectIO::SetUp();
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
	public:
		void runTest() {
			Mountain::getInstance().handleCommand("choose");
			pass = true;
		}
	};
	TEST_F(MountainTest, handleCommand)
	{
		char temp = '1';
		int count = 0;
		sin << temp;
		std::thread c_thread(&MountainTest::runTest, this);
		c_thread.detach();
		while (!pass) {
			count++;
			Sleep(50);
			if (count > 10) {
				EXPECT_TRUE(pass);
				break;
			}
		}
	}
	class FlyweightFactoryTest :public RedirectIO
	{
	protected:
		bool pass;
		FlyweightFactory* flyweightFactory;
		void SetUp() override {
			RedirectIO::SetUp();
			flyweightFactory = new FlyweightFactory();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(flyweightFactory);
		}
	};
	TEST_F(FlyweightFactoryTest, GetFlyWeight)
	{
		EXPECT_NO_THROW(flyweightFactory->GetFlyWeight("abaaba"));
	}
}