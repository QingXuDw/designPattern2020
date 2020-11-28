#include "pch.h"
#include "TestCaseTest_wjy.h"
#include "BookingTest_wjy.h"
#include "TicketBuyerTest_wjy.h"
#include "ShoppingMallTest_wjy.h"
#include "AdapterTest_zgx.h"
#include "ConsultTest_zgx.h"
#include "MediatorModelTest_zgx.h"
#include "SnowmanTest_zgx.h"
#include "TestPlanTest_zgx.h"
#include "TouristCenterTest_zgx.h"
#include "VisitorClassesTest_wsq.h"
#include "StateTest_wsq.h"
#include "IceSkatingTest_xjn.h"
#include "StateTest_zzy.h"
#include "StrategyTest_zzy.h"


int main(int argc, char **argv) {
	std::string str;
	std::cout << "按回车键开始测试" << std::endl;
	getline(std::cin, str);
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}