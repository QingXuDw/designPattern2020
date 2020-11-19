#pragma once
#include "pch.h"
#include "../designPattern/State.h"
#include <thread>
#include <Windows.h>
namespace zyb
{
	class StorageTest:public RedirectIO 
	{
		protected:
		Storage* p_storage;
		void SetUp() override 
		{
			RedirectIO::SetUp();
			p_storage = new Storage();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_storage);
		}
	};
	TEST_F(StorageTest, TestState)
	{
		EXPECT_EQ(p_storage->n_state,0);
	}

	class VehicleTest :public RedirectIO
	{
		protected:
		Vehicle* p_vehicle;
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
		EXPECT_NO_THROW(p_vehicle->handleCommand("vehical all"));
		EXPECT_NO_THROW(p_vehicle->handleCommand("vehical"));
		EXPECT_NO_THROW(p_vehicle->handleCommand("vehical state"));
		EXPECT_NO_THROW(p_vehicle->handleCommand(" "));
		sout.str("");//Çå¿ÕÊä³öÁ÷}
	}









}