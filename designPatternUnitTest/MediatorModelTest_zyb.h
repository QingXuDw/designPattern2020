#pragma once
#include "pch.h"
#include"../designPattern/MediatorModel.h"
#include <vector>

//用namespace包裹以防止命名冲突
namespace zyb {

	class MediatorManagerTest : public RedirectIO 
	{
	protected:
		MediatorManager* p_mediatorManager;
		void SetUp() override 
		{
			RedirectIO::SetUp();
			p_mediatorManager = &(MediatorManager::getInstance());
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
		}
	};


	TEST_F(MediatorManagerTest, HandleCommand) 
	{
		EXPECT_NO_THROW(p_mediatorManager->handleCommand(""));
		EXPECT_NO_THROW(p_mediatorManager->handleCommand("mediator"));
		EXPECT_NO_THROW(p_mediatorManager->handleCommand("mediator make"));
		EXPECT_NO_THROW(p_mediatorManager->handleCommand("mediator sendmessage"));
		EXPECT_NO_THROW(p_mediatorManager->handleCommand("JqLP"));
	}


}