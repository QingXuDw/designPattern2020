//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include "../designPattern/BaseClasses.h"
#include <thread>
#include <Windows.h>

#define DP_TEST_F_THREAD_CLASS_NAME(test_case_name, test_name) \
	test_case_name##_##test_name##_##Thread
#define DP_TEST_F_THREAD_CLASS_PASS(test_case_name, test_name) \
	test_case_name##_##test_name##_##Thread##_##Pass
#define DP_TEST_F_THREAD_CLASS_RUN(test_case_name, test_name) \
	test_case_name##_##test_name##_##Thread##_##Run
#define DP_TEST_F_THREAD_CLASS_FUNC(test_case_name, test_name) \
	test_case_name##_##test_name##_##Thread##_##Func
/*在子线程中测试（性能调教）
* 用于目标代码有可能出现死循环、超时、阻塞、死锁等情况的测试，当子线程运行超时时将会调用EXPECT_TRUE报错。
* 可以通过调整检测周期优化性能，合适的周期与电脑性能和系统调度方式有关。
* @param test_case_name 测试用例名（类名）
* @param test_name 测试单元名（类似TEST_F）
* @param period 检测周期，通常而言预计执行时间越短周期越短，预计执行时间越长周期越长。
* @param max_time 时间限制（单位ms）
*/
#define DP_TEST_F_THREAD_FULL_PARAM(test_case_name, test_name, period, max_time) \
class DP_TEST_F_THREAD_CLASS_NAME(test_case_name, test_name) : public test_case_name {\
protected:\
	bool DP_TEST_F_THREAD_CLASS_PASS(test_case_name, test_name) = false;\
public:\
	void DP_TEST_F_THREAD_CLASS_RUN(test_case_name, test_name)();\
	void DP_TEST_F_THREAD_CLASS_FUNC(test_case_name, test_name)() { \
		DP_TEST_F_THREAD_CLASS_RUN(test_case_name, test_name)();\
		DP_TEST_F_THREAD_CLASS_PASS(test_case_name, test_name) = true; \
	} \
};\
TEST_F(DP_TEST_F_THREAD_CLASS_NAME(test_case_name, test_name), test_name){ \
	int count = 0; \
	std::thread cThread(&DP_TEST_F_THREAD_CLASS_NAME(test_case_name, test_name)::DP_TEST_F_THREAD_CLASS_FUNC(test_case_name, test_name), this); \
	cThread.detach(); \
	while (!DP_TEST_F_THREAD_CLASS_PASS(test_case_name, test_name)) { \
		count++; \
		Sleep(period); \
		if (count * period > max_time) { \
			EXPECT_TRUE(DP_TEST_F_THREAD_CLASS_PASS(test_case_name, test_name)); \
			break; \
		} \
	} \
} \
void DP_TEST_F_THREAD_CLASS_NAME(test_case_name, test_name)::DP_TEST_F_THREAD_CLASS_RUN(test_case_name, test_name)()

/*在子线程中测试（用法类似TEST_F)
* 用于目标代码有可能出现死循环、超时、阻塞、死锁等情况的测试，当子线程运行超时时将会调用EXPECT_TRUE报错，默认超时检测周期为50ms。
* @param test_case_name 测试用例名（类名）
* @param test_name 测试单元名（类似TEST_F）
* @param max_time 时间限制（单位ms）
*/
#define DP_F_TIME(test_case_name, test_name, max_time) \
	DP_TEST_F_THREAD_FULL_PARAM(test_case_name, test_name, 25, max_time)

/*线程安全的测试（用法类似TEST_F)
* 开辟一个子线程测试代码，用于目标代码不太可能出现死循环、超时、阻塞、死锁等情况的测试，
* 当子线程运行超时时将会调用EXPECT_TRUE报错，默认超时时间为10000ms
* @param test_case_name 测试用例名（类名）
* @param test_name 测试单元名（类似TEST_F）
*/
#define DP_F(test_case_name, test_name) \
	DP_TEST_F_THREAD_FULL_PARAM(test_case_name, test_name, 10, 1000)
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