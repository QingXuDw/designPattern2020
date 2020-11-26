#include "pch.h"
#include "TestCaseTest_wjy.h"
#include "BookingTest_wjy.h"
#include "TicketBuyerTest_wjy.h"
#include "ShoppingMallTest_wjy.h"
#include "CicecreamTest_ljq.h"
#include "CIceZooTest_ljq.h"
#include"ConsultTest_ljq.h"
#include"FCurrencyTest_ljq.h"
#include"VisitorClassesTest_ljq.h"
#include"AdapterTest_ljq.h"
#include "AdapterTest_zgx.h"
#include "ConsultTest_zgx.h"
#include "MediatorModelTest_zgx.h"
#include "SnowmanTest_zgx.h"
#include "TestPlanTest_zgx.h"
#include "TouristCenterTest_zgx.h"
#include "IceSkatingTest_xjn.h"

int main(int argc, char **argv) {
	std::string str;
	std::cout << "按下任意键开始测试" << std::endl;
	getline(std::cin, str);
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}