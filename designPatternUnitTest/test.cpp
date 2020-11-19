#include "pch.h"
#include "TestCaseTest_wjy.h"
#include "BookingTest_wjy.h"
#include "TicketBuyerTest_wjy.h"
#include "ShoppingMallTest_wjy.h"
#include"VisitorClassesTest_wsq.h"
#include"StateTest_wsq.h"
#include"SnowmanTest_wsq.h"


int main(int argc, char **argv) {
	std::string str;
	std::cout << "输入任意键开始测试" << std::endl;
	getline(std::cin, str);
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}