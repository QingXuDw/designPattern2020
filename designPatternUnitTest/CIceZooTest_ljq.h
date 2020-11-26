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
		EXPECT_STREQ(result.c_str(), "欢迎游览冰雪动物园！");
		
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "您正在游览企鹅馆；");
		
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "您正在游览海豹馆；");
		
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "您正在游览白鲸馆；");
		
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "您正在游览北极熊馆；");
		
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "您已离开冰雪动物园。");
	}
	TEST_F(IceZooManagerTest, PrintHelp) {
		EXPECT_NO_THROW(p_iceZooManager->printHelp(0));
	}
}
