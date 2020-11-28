#pragma once
#include "pch.h"
#include "../designPattern/Adapter.h"
#include <vector>

//用namespace包裹以防止命名冲突
namespace zgx {
	/************************************************************************************
	*																					*
	*						负责测试Adapter.h中的Adapter类								*
	*************************************************************************************/
	class AdapterTest : public RedirectIO {
	public:
		Adapter* p_adapter;
		void SetUp() override {
			RedirectIO::SetUp();
			p_adapter = new Adapter();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_adapter);
		}
	};
	TEST_F(AdapterTest, exchange) {
		EXPECT_NO_THROW(p_adapter->exchange(100, 44));
		EXPECT_NO_THROW(p_adapter->exchange(100, 0));
		EXPECT_NO_THROW(p_adapter->exchange(100, 11));
		EXPECT_NO_THROW(p_adapter->exchange(100, 2));
		EXPECT_NO_THROW(p_adapter->exchange(100, 3));
		EXPECT_NO_THROW(p_adapter->exchange(100, 10));
		EXPECT_NO_THROW(p_adapter->exchange(100, 12));
		EXPECT_NO_THROW(p_adapter->exchange(100, 13));
		EXPECT_NO_THROW(p_adapter->exchange(100, 20));
		EXPECT_NO_THROW(p_adapter->exchange(100, 21));
		EXPECT_NO_THROW(p_adapter->exchange(100, 23));
		EXPECT_NO_THROW(p_adapter->exchange(100, 30));
		EXPECT_NO_THROW(p_adapter->exchange(100, 31));
		EXPECT_NO_THROW(p_adapter->exchange(100, 32));
		EXPECT_NO_THROW(p_adapter->exchange(100, 10086));
	}
	TEST_F(AdapterTest, Transform) {
		EXPECT_NO_THROW(p_adapter->Transform("dollar"));
		EXPECT_NO_THROW(p_adapter->Transform("pound"));
		EXPECT_NO_THROW(p_adapter->Transform("日元"));
		EXPECT_NO_THROW(p_adapter->Transform("人民币"));
		EXPECT_NO_THROW(p_adapter->Transform("JLNB"));
	}
	TEST_F(AdapterTest, start) {
		EXPECT_NO_THROW(p_adapter->start());
	}
}
