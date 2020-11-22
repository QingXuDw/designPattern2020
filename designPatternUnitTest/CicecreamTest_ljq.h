#include "pch.h"
#include "../designPattern/CIcecream.h"
#include <string>
#include <iostream>
#include <map>
namespace ljq {
	class  CIcecreamTest : public RedirectIO
	{
	protected:
		CIcecream* p_cIcecream;
		void SetUp() override {
			RedirectIO::SetUp();
			p_cIcecream = new CIcecream(CIcecream::icBallType(0), CIcecream::icBiscuitType(0), false);
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_cIcecream);
		}
	};
	TEST_F(CIcecreamTest, icType) {
		p_cIcecream->icType();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "您购买了一个中号带有南瓜小饼干的西瓜冰激凌。请享用！");
	}
	class IcecreamManagerTest : public RedirectIO {
	protected:
		CIcecream* p_cIcecream;
		IcecreamManager* p_IcecreamManager;
		void SetUp() override {
			RedirectIO::SetUp();
			p_cIcecream = new CIcecream();
			p_IcecreamManager = &(IcecreamManager::getInstance());
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
		static void s_delete(void* ptr) {
			if ((ptr) != nullptr) { delete (ptr); (ptr) = nullptr; }
		}
	};
	TEST_F(IcecreamManagerTest, HandleCommand)
	{
		std::string result;
		sin << "000";
		sin << endl;
		EXPECT_NO_THROW(p_IcecreamManager->handleCommand(""));
		
		//sin << endl;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "欢迎光临冰雪冰激凌店！");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "请选择冰激凌样式：");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "冰激凌球：西瓜-0，草莓-1，芒果-2，榴莲-3，巧克力-4");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "小饼干：南瓜-0，黄瓜-1");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "大小：中份-0，大份-1");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "请用三位数字代码表示冰激凌样式，如：芒果冰激凌球+南瓜小饼干+大份的代码为201");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "若要复制一个样式相同的冰激凌，请输入代码8");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "若要离开冰激凌店，请输入代码9");

		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "您购买了一个中号带有南瓜小饼干的西瓜冰激凌。请享用！");
	}
	TEST_F(IcecreamManagerTest, HandleCommand2)
	{
		std::string result;
		sin << "9911";
		sin << endl;
		EXPECT_NO_THROW(p_IcecreamManager->handleCommand(""));

		
	}
	TEST_F(IcecreamManagerTest, PrintHelp) {
		EXPECT_NO_THROW(p_IcecreamManager->printHelp(0));
	}
}

