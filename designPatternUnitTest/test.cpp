#include "pch.h"
#include "TestCaseTest_wjy.h"
#include "BookingTest_wjy.h"
#include "TicketBuyerTest_wjy.h"
#include "ShoppingMallTest_wjy.h"


int main(int argc, char **argv) {
	std::string str;
	std::cout << "�����������ʼ����" << std::endl;
	getline(std::cin, str);
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}