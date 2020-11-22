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
		EXPECT_STREQ(result.c_str(), "��������һ���кŴ����Ϲ�С���ɵ����ϱ����衣�����ã�");
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
		EXPECT_STREQ(result.c_str(), "��ӭ���ٱ�ѩ������꣡");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "��ѡ���������ʽ��");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "������������-0����ݮ-1��â��-2������-3���ɿ���-4");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "С���ɣ��Ϲ�-0���ƹ�-1");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "��С���з�-0�����-1");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "������λ���ִ����ʾ��������ʽ���磺â����������+�Ϲ�С����+��ݵĴ���Ϊ201");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "��Ҫ����һ����ʽ��ͬ�ı����裬���������8");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "��Ҫ�뿪������꣬���������9");

		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "��������һ���кŴ����Ϲ�С���ɵ����ϱ����衣�����ã�");
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

