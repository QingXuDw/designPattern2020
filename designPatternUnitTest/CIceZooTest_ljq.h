#pragma once
#include "pch.h"
#include "../designPattern/CIceZoo.h"
namespace ljq {
	using namespace std;
	class CIceZooTest : public RedirectIO {
	protected:
		CIceZoo* p_cIceZoo;
		void SetUp() override {
			RedirectIO::SetUp();
			p_cIceZoo = new CIceZoo();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_cIceZoo);
		}
	};

	class IceZooManagerTest : public RedirectIO {

	protected:
		CIceZoo* p_cIceZoo;
		IceZooManager* p_iceZooManager;
		void SetUp() override {
			RedirectIO::SetUp();
			p_cIceZoo = new CIceZoo();
			p_iceZooManager = &(IceZooManager::getInstance());
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
		static void s_delete(void* ptr) {
			if ((ptr) != nullptr) { delete (ptr); (ptr) = nullptr; }
		}
	};
	TEST_F(IceZooManagerTest, HandleCommand) {
		std::string result;
		EXPECT_NO_THROW(p_iceZooManager->handleCommand(""));
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "��ӭ������ѩ����԰��");
		
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "�������������ݣ�");
		
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "���������������ݣ�");
		
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "�����������׾��ݣ�");
		
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "���������������ܹݣ�");
		
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "�����뿪��ѩ����԰��");
	}
	TEST_F(IceZooManagerTest, PrintHelp) {
		EXPECT_NO_THROW(p_iceZooManager->printHelp(0));
	}
}
