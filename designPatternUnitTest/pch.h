//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include "../designPattern/BaseClasses.h"
/*安全释放一个指针
* 释放指针前检查指针指向的对象是否已经被释放，释放后设置指针指向nullptr
* @param ptr 待释放的指针
*/
#define S_DELETE(ptr) if ((ptr) != nullptr) { delete (ptr); (ptr) = nullptr; }

/************************************************************************************
*																					*
*								TestCase测试用例										*
*																					*
*					继承自TestCase的子类可以作为TEST_F()宏的第一个参数					*
*		为保证正常测试流程，子类禁止重载构造函数或析构函数，构造函数和析构函数的工作应交给		*
*		SetUp/SetUpUseCase和TearDown/TearDownUseCase进行。							*
*																					*
*		其中SetUpUseCase/TearDownUseCase函数以测试单元组为单位（同名测试用例的全部测		*
*		试单元为一测试单元组），在测试单元组执行前/后执行，SetUp/TearDown函数以测试单元		*
*		为单位，在每一个测试单元前/后执行，具体执行情况见TestCaseTest测试用例。				*
*																					*
*	为了保证测试单元的相对独立，测试用例中出现的对象请通过声明指针搭配new/delete控制生命周期		*
*																					*
*	注意：子类类名中不能有下划线，下划线在此框架中为特殊符号，xx_yy表示xx测试用例的yy测试单元		*
*************************************************************************************/
typedef testing::Test TestCase;





/************************************************************************************
*																					*
*							RedirectIO输入输出流重定向									*
*																					*
*				继承自RedirectIO的子类中的cout和cin会被重定向到sout和sin					*
*子类重载SetUp函数和TearDown函数时需要通过__super或RedirectIO调用父函数以保证正常输入输出重定向*
*************************************************************************************/
class RedirectIO : public TestCase {
protected:
	std::stringstream sin;
	std::stringstream sout;
	std::streambuf* p_cinBackup;
	std::streambuf* p_coutBackup;
	/*搭建测试单元
	* 在每一个测试单元执行前调用
	*/
	void SetUp() override {
		p_cinBackup = std::cin.rdbuf(sin.rdbuf());
		p_coutBackup = std::cout.rdbuf(sout.rdbuf());
	}
	/*搭建测试单元
	* 在每一个测试单元执行后调用
	*/
	void TearDown() override {
		std::cin.rdbuf(p_cinBackup);
		std::cout.rdbuf(p_coutBackup);
	}
	/*搭建测试用例
	* 在测试单元组执行前调用
	*/
	static void SetUpTestCase() {}
	/*搭建测试用例
	* 在测试单元组执行后调用
	*/
	static void TearDownTestCase() {}
public:
	/*切换IO流
	* @param type IO流类型：0为默认控制台输入输出，1为sin/sout, -1是在两者间切换
	* @return void
	*/
	void switchIO(int type = -1) {
		switch (type) {
		case 0:
			std::cin.rdbuf(p_cinBackup);
			std::cout.rdbuf(p_coutBackup);
			break;
		case 1:
			std::cin.rdbuf(sin.rdbuf());
			std::cout.rdbuf(sout.rdbuf());
			break;
		case -1:
			if (std::cin.rdbuf() == p_cinBackup) {
				std::cin.rdbuf(sin.rdbuf());
				std::cout.rdbuf(sout.rdbuf());
			}
			else {
				std::cin.rdbuf(p_cinBackup);
				std::cout.rdbuf(p_coutBackup);
			}
			break;
		default:
			break;
		}
	}
	/*打印Sout到控制台*/
	void printSout() {
		std::string line;
		switchIO();//切换为控制台输入输出流
		while (sout >> line) {
			std::cout << line << std::endl;
		}
		switchIO();
	}
};

/************************************************************************************
*																					*
*							TestReceiver测试用指令接收器								*
*																					*
*					最小的可用接收器，用于测试宏指令接收器的添加移除功能						*
*************************************************************************************/
class TestReceiver : public CommandReceiver {
private:
	TestReceiver() : CommandReceiver("testReceiver") {}
protected:
	bool executeCommand(std::string cmd) { return true; }
public:
	TestReceiver(const TestReceiver&) = delete;
	TestReceiver& operator=(const TestReceiver&) = delete;
	static TestReceiver& getInstance() {
		static TestReceiver reciver;
		return reciver;
	}
};