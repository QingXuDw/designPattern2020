#pragma once
#include "pch.h"
#include"../designPattern/TouristCenter.h"
#include <vector>

//用namespace包裹以防止命名冲突
namespace zgx {
	/************************************************************************************
	*																					*
	*						负责测试TouristCenter.h中的类								*
	*************************************************************************************/
	class TouristCenterTest : public RedirectIO {
	public:
		TouristCenter* p_touristCenter;
		void SetUp() override {
			RedirectIO::SetUp();
			p_touristCenter = &(TouristCenter::getInstance());
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
	};
	TEST_F(TouristCenterTest, HandleCommand) {
		EXPECT_NO_THROW(p_touristCenter->handleCommand(""));
		EXPECT_NO_THROW(p_touristCenter->handleCommand("tourist"));
		EXPECT_NO_THROW(p_touristCenter->handleCommand("tourist consult"));
		EXPECT_NO_THROW(p_touristCenter->handleCommand("tourist currency"));
		EXPECT_NO_THROW(p_touristCenter->handleCommand("JLNB!!!"));
	}

	TEST_F(TouristCenterTest, PrintHelp) {
		EXPECT_NO_THROW(p_touristCenter->printHelp(0));
	}

}
