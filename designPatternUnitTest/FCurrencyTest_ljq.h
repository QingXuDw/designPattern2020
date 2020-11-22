#pragma once
#include "pch.h"
#include "../designPattern/FCurrency.h"
namespace ljq {
	class DollarTest :public RedirectIO {
	protected:
		Dollar* p_dollar;
		void SetUp() override {
			RedirectIO::SetUp();
			p_dollar = new Dollar();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_dollar);
		}
	};
	TEST_F(DollarTest, exchange) {
		
		EXPECT_FLOAT_EQ(p_dollar->exchange(1, true), 6.576f);
	}
	TEST_F(DollarTest, Destructor) {
		S_DELETE(p_dollar);
		EXPECT_TRUE(p_dollar == nullptr);
	}
	class PoundTest :public RedirectIO {
	protected:
		Pound* p_pound;
		void SetUp() override {
			RedirectIO::SetUp();
			p_pound = new Pound();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_pound);
		}
	};
	TEST_F(PoundTest, exchange) {
		EXPECT_FLOAT_EQ(p_pound->exchange(1, true), 8.6685f);
		
	}
	TEST_F(PoundTest, Destructor) {
		S_DELETE(p_pound);
		EXPECT_TRUE(p_pound == nullptr);
	}
	class YenTest :public RedirectIO {
	protected:
		Yen* p_yen;
		void SetUp() override {
			RedirectIO::SetUp();
			p_yen = new Yen();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_yen);
		}
	};
	TEST_F(YenTest, exchange) {
		
		EXPECT_FLOAT_EQ(p_yen->exchange(1, false), 15.9313f);
	}
	TEST_F(YenTest, Destructor) {
		S_DELETE(p_yen);
		EXPECT_TRUE(p_yen == nullptr);
	}
}