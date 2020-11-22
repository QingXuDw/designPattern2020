#pragma once
#include "pch.h"
#include "../designPattern/Adapter.h"

namespace ljq {
	using namespace std;
	class AdapterTest : public RedirectIO {
	protected:
		Adapter* p_adapter;
		void SetUp() override {
			RedirectIO::SetUp();
			p_adapter = new Adapter();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_adapter);
		}
	};
	TEST_F(AdapterTest, exchange) {
		EXPECT_NO_THROW(p_adapter->exchange(1,44));
		EXPECT_NO_THROW(p_adapter->exchange(1, 0));
		EXPECT_NO_THROW(p_adapter->exchange(1, 11));
		EXPECT_NO_THROW(p_adapter->exchange(1, 2));
	}
	TEST_F(AdapterTest, Transform) {
		EXPECT_NO_THROW(p_adapter->Transform("dollar"));
		EXPECT_NO_THROW(p_adapter->Transform("Ó¢°÷"));
		EXPECT_NO_THROW(p_adapter->Transform("½ğÔª±¦"));
	}
}