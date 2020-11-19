#pragma once
#include "pch.h"
#include <thread>
#include"../designPattern/Snowman.h"

namespace wsq {

	class SnowmanManagerTest :public RedirectIO
	{
	protected:
		bool pass;
		SnowmanManager* snowmanManager;
		void SetUp() override {
			RedirectIO::SetUp();
			snowmanManager = &(SnowmanManager::getInstance());
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
	public:
		void runTest() {
			SnowmanManager::getInstance().handleCommand("make");
			pass = true;
		}
	};
	TEST_F(SnowmanManagerTest, executeCommand)
	{
		EXPECT_NO_THROW(snowmanManager->handleCommand(""));
		EXPECT_NO_THROW(snowmanManager->handleCommand("make"));
		EXPECT_NO_THROW(snowmanManager->handleCommand("make 1 2 3 4"));
		EXPECT_NO_THROW(snowmanManager->handleCommand("make 1 1 1 1"));
		EXPECT_NO_THROW(snowmanManager->handleCommand("make 1 1 2 2"));
		EXPECT_NO_THROW(snowmanManager->handleCommand("update"));
		EXPECT_NO_THROW(snowmanManager->handleCommand("uodate 1"));
		EXPECT_NO_THROW(snowmanManager->handleCommand("update 3"));
		EXPECT_NO_THROW(snowmanManager->handleCommand("update 1 5"));
		EXPECT_NO_THROW(snowmanManager->handleCommand("update 1 265"));
	}
}