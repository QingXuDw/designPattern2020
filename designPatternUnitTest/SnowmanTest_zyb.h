#pragma once
#include "pch.h"
#include "../designPattern/Snowman.h"
#include <vector>

namespace zyb {

	

	class FuctionTest : public RedirectIO
	{
	public:
		int a[4] = { 0 };
		void SetUp() override 
		{
			RedirectIO::SetUp();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
		}
	};

	TEST_F(FuctionTest, seInit) 
	{
		EXPECT_NO_THROW(setInit(6, a));
	}
	TEST_F(FuctionTest, setStatus)
	{
		EXPECT_NO_THROW(setStatus(0, 1));
	}


	class SnowmanManagerTest : public RedirectIO 
	{
	public:
		SnowmanManager* p_snowmanManager;
		void SetUp() override 
		{
			RedirectIO::SetUp();
			p_snowmanManager = &(SnowmanManager::getInstance());
		}
		void TearDown() override 
		{
			RedirectIO::TearDown();
		}
	};

	TEST_F(SnowmanManagerTest, HandleCommand) 
	{
		EXPECT_NO_THROW(p_snowmanManager->handleCommand(""));
		EXPECT_NO_THROW(p_snowmanManager->handleCommand("jqlp"));
		EXPECT_NO_THROW(p_snowmanManager->handleCommand("snowman"));
		EXPECT_NO_THROW(p_snowmanManager->handleCommand("snowman make"));
		EXPECT_NO_THROW(p_snowmanManager->handleCommand("snowman update"));
		EXPECT_NO_THROW(p_snowmanManager->handleCommand("snowman update"));
	}

}