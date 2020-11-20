#pragma once
#include "pch.h"
#include "../designPattern/TestPlan.h"
#include <vector>

//用namespace包裹以防止命名冲突
namespace zgx {
	/************************************************************************************
	*																					*
	*						负责测试TestPlan.h中的类									*
	*************************************************************************************/
	class TestSpotTest : public RedirectIO {
	public:
		TestSpot* p_testSpot;
		void SetUp() override {
			RedirectIO::SetUp();
			p_testSpot = &(TestSpot::getInstance());
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
	};
	TEST_F(TestSpotTest, HandleCommand) {
		EXPECT_NO_THROW(p_testSpot->handleCommand(""));
		EXPECT_NO_THROW(p_testSpot->handleCommand("test"));
		EXPECT_NO_THROW(p_testSpot->handleCommand("test setStr"));
		EXPECT_NO_THROW(p_testSpot->handleCommand("test setStr cpdd"));
		EXPECT_NO_THROW(p_testSpot->handleCommand("test getStr"));
		EXPECT_NO_THROW(p_testSpot->handleCommand("JLNB!!!"));
	}

	class TestPlanFactoryTest : public RedirectIO {
	public:
		TestPlanFactory* p_testPlanFactory;
		void SetUp() override {
			RedirectIO::SetUp();
			p_testPlanFactory = new TestPlanFactory();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_testPlanFactory);
		}
	};

	TEST_F(TestPlanFactoryTest, HandleCommand) {
		EXPECT_NO_THROW(p_testPlanFactory->makeDescription());
		EXPECT_NO_THROW(p_testPlanFactory->makePath());
		EXPECT_NO_THROW(p_testPlanFactory->makeSpot());
	}
}
