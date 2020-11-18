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
/*�����߳��в��ԣ����ܵ��̣�
* ����Ŀ������п��ܳ�����ѭ������ʱ������������������Ĳ��ԣ������߳����г�ʱʱ�������EXPECT_TRUE����
* ����ͨ��������������Ż����ܣ����ʵ�������������ܺ�ϵͳ���ȷ�ʽ�йء�
* @param test_case_name ������������������
* @param test_name ���Ե�Ԫ��������TEST_F��
* @param period ������ڣ�ͨ������Ԥ��ִ��ʱ��Խ������Խ�̣�Ԥ��ִ��ʱ��Խ������Խ����
* @param max_time ʱ�����ƣ���λms��
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

/*�����߳��в��ԣ��÷�����TEST_F)
* ����Ŀ������п��ܳ�����ѭ������ʱ������������������Ĳ��ԣ������߳����г�ʱʱ�������EXPECT_TRUE����Ĭ�ϳ�ʱ�������Ϊ50ms��
* @param test_case_name ������������������
* @param test_name ���Ե�Ԫ��������TEST_F��
* @param max_time ʱ�����ƣ���λms��
*/
#define DP_F_TIME(test_case_name, test_name, max_time) \
	DP_TEST_F_THREAD_FULL_PARAM(test_case_name, test_name, 25, max_time)

/*�̰߳�ȫ�Ĳ��ԣ��÷�����TEST_F)
* ����һ�����̲߳��Դ��룬����Ŀ����벻̫���ܳ�����ѭ������ʱ������������������Ĳ��ԣ�
* �����߳����г�ʱʱ�������EXPECT_TRUE����Ĭ�ϳ�ʱʱ��Ϊ10000ms
* @param test_case_name ������������������
* @param test_name ���Ե�Ԫ��������TEST_F��
*/
#define DP_F(test_case_name, test_name) \
	DP_TEST_F_THREAD_FULL_PARAM(test_case_name, test_name, 10, 1000)
/*��ȫ�ͷ�һ��ָ��
* �ͷ�ָ��ǰ���ָ��ָ��Ķ����Ƿ��Ѿ����ͷţ��ͷź�����ָ��ָ��nullptr
* @param ptr ���ͷŵ�ָ��
*/
#define S_DELETE(ptr) if ((ptr) != nullptr) { delete (ptr); (ptr) = nullptr; }

/************************************************************************************
*																					*
*								TestCase��������										*
*																					*
*					�̳���TestCase�����������ΪTEST_F()��ĵ�һ������					*
*		Ϊ��֤�����������̣������ֹ���ع��캯�����������������캯�������������Ĺ���Ӧ����		*
*		SetUp/SetUpUseCase��TearDown/TearDownUseCase���С�							*
*																					*
*		����SetUpUseCase/TearDownUseCase�����Բ��Ե�Ԫ��Ϊ��λ��ͬ������������ȫ����		*
*		�Ե�ԪΪһ���Ե�Ԫ�飩���ڲ��Ե�Ԫ��ִ��ǰ/��ִ�У�SetUp/TearDown�����Բ��Ե�Ԫ		*
*		Ϊ��λ����ÿһ�����Ե�Ԫǰ/��ִ�У�����ִ�������TestCaseTest����������				*
*																					*
*	Ϊ�˱�֤���Ե�Ԫ����Զ��������������г��ֵĶ�����ͨ������ָ�����new/delete������������		*
*																					*
*	ע�⣺���������в������»��ߣ��»����ڴ˿����Ϊ������ţ�xx_yy��ʾxx����������yy���Ե�Ԫ		*
*************************************************************************************/
typedef testing::Test TestCase;





/************************************************************************************
*																					*
*							RedirectIO����������ض���									*
*																					*
*				�̳���RedirectIO�������е�cout��cin�ᱻ�ض���sout��sin					*
*��������SetUp������TearDown����ʱ��Ҫͨ��__super��RedirectIO���ø������Ա�֤������������ض���*
*************************************************************************************/
class RedirectIO : public TestCase {
protected:
	std::stringstream sin;
	std::stringstream sout;
	std::streambuf* p_cinBackup;
	std::streambuf* p_coutBackup;
	/*����Ե�Ԫ
	* ��ÿһ�����Ե�Ԫִ��ǰ����
	*/
	void SetUp() override {
		p_cinBackup = std::cin.rdbuf(sin.rdbuf());
		p_coutBackup = std::cout.rdbuf(sout.rdbuf());
	}
	/*����Ե�Ԫ
	* ��ÿһ�����Ե�Ԫִ�к����
	*/
	void TearDown() override {
		std::cin.rdbuf(p_cinBackup);
		std::cout.rdbuf(p_coutBackup);
	}
	/*���������
	* �ڲ��Ե�Ԫ��ִ��ǰ����
	*/
	static void SetUpTestCase() {}
	/*���������
	* �ڲ��Ե�Ԫ��ִ�к����
	*/
	static void TearDownTestCase() {}
public:
	/*�л�IO��
	* @param type IO�����ͣ�0ΪĬ�Ͽ���̨���������1Ϊsin/sout, -1�������߼��л�
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
	/*��ӡSout������̨*/
	void printSout() {
		std::string line;
		switchIO();//�л�Ϊ����̨���������
		while (sout >> line) {
			std::cout << line << std::endl;
		}
		switchIO();
	}
};

/************************************************************************************
*																					*
*							TestReceiver������ָ�������								*
*																					*
*					��С�Ŀ��ý����������ڲ��Ժ�ָ�������������Ƴ�����						*
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