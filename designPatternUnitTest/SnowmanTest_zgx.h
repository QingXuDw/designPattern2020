#pragma once
#include "pch.h"
#include "../designPattern/Snowman.h"
#include <vector>

//用namespace包裹以防止命名冲突
namespace zgx {
	/************************************************************************************
	*																					*
	*						负责测试Snowman.h中类										*
	*************************************************************************************/
	class voidTest : public RedirectIO {
	public:
		int a[4] = { 0 };
		void SetUp() override {
			RedirectIO::SetUp();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
		}
	};
	TEST_F(voidTest, seInit) {
		EXPECT_NO_THROW(setInit(6,a));
	}
	TEST_F(voidTest, setStatus) {
		EXPECT_NO_THROW(setStatus(0,1));
	}

	class SnowmanManagerTest : public RedirectIO {
	public:
		SnowmanManager* p_snowmanManager;
		void SetUp() override {
			RedirectIO::SetUp();
			p_snowmanManager = &(SnowmanManager::getInstance());
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
	};
	TEST_F(SnowmanManagerTest, HandleCommand) {
		EXPECT_NO_THROW(p_snowmanManager->handleCommand(""));
		EXPECT_NO_THROW(p_snowmanManager->handleCommand("snowman"));
		EXPECT_NO_THROW(p_snowmanManager->handleCommand("snowman make"));
		EXPECT_NO_THROW(p_snowmanManager->handleCommand("snowman update"));
		EXPECT_NO_THROW(p_snowmanManager->handleCommand("JLNB!!!"));
	}


}
