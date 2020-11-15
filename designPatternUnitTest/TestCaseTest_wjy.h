#pragma once
#include "pch.h"

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
		virtual void SetUp()
		{
			str = new std::string("abaaba");
			std::cout << "SetUp" << std::endl;	
		}
		virtual void TearDown()
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
}
