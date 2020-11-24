#pragma once
#include "pch.h"
#include "../designPattern/BaseClasses.h"
	

//用namespace包裹以防止命名冲突
namespace wjy {
	class TestMap :public testing::Test
	{
	public:
		std::string* str;
		static void SetUpTestCase()
		{
			std::cout << "SetUpTestCase" << std::endl;
		}
		static void TearDownTestCase()
		{
			std::cout << "TearDownTestCase" << std::endl;
		}
		virtual void SetUp() override
		{
			str = new std::string("abaaba");
			std::cout << "SetUp" << std::endl;	
		}
		virtual void TearDown() override
		{
			std::cout << "TearDown" << std::endl;
			S_DELETE(str);
		}
	};
	/*TEST_F宏声明了一个测试单元
	* 测试单元为测试的最小单位，通常一个测试单元对应一个类的一个接口（public的函数）
	* @param param1 测试单元所属测试用例名
	* @param param2 测试单元名
	* 宏会自动生成继承于param1的名为param1_param2的子类用于测试
	* 故测试用例名和测试单元名中均不能出现下划线
	*/
	TEST_F(TestMap, Compare)
	{
		//断言param1与param2相等，当不相等时终止程序运行
		ASSERT_EQ(str->compare("abaaba"), 0);
	}
	TEST_F(TestMap, Size)
	{
		//期待param1与param2相等，当不相等时输出错误位置和详情，程序继续运行
		EXPECT_EQ(str->size(), 6);
	}

	/*多线程测试（测试代码运行在子线程中)
	* 解决测试代码中出现死锁、死循环、阻塞输入等问题（下称卡死）。
	* 下面是一些简单示例，当stuck == true时代码陷入死循环中，通过DP_F/DP_F_TIME可以正常进行测试，而TEST_F会停止响应
	* 其中DP_F应该用于不太可能出现卡死的测试代码
	* DF_F_TIME应该用于有可能出现卡死的测试代码
	* 尽量不要使用TEST_F，除非卡死后继续后面的测试项没有意义
	*/
	class ThreadTest : public TestCase {
	protected:
		bool stuck = false;
	};

	DP_F_TIME(ThreadTest, DPFThread, 100) {
		do {} while (stuck);
	}
	DP_F(ThreadTest, DPF) {
		do {} while (stuck);
	}
	TEST_F(ThreadTest, TestF) {
		do {} while (stuck);
	}
}
