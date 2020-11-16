//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include "../designPattern/BaseClasses.h"
/*��ȫ�ͷ�һ��ָ��
* �ͷ�ָ��ǰ���ָ��ָ��Ķ����Ƿ��Ѿ����ͷţ��ͷź�����ָ��ָ��nullptr
* @param ptr ���ͷŵ�ָ��
*/
#define S_DELETE(ptr) if ((ptr) != nullptr) { delete (ptr); (ptr) = nullptr; }

/************************************************************************************
*																					*
*								TestCase��������										*
*																					*
*					�̳���TestCase�����������ΪTEST_F()��ĵ�һ������						*
*		Ϊ��֤�����������̣������ֹ���ع��캯�����������������캯�������������Ĺ���Ӧ����			*
*		SetUp/SetUpUseCase��TearDown/TearDownUseCase���С�							*
*																					*
*		����SetUpUseCase/TearDownUseCase�����Բ��Ե�Ԫ��Ϊ��λ��ͬ������������ȫ����			*
*		�Ե�ԪΪһ���Ե�Ԫ�飩���ڲ��Ե�Ԫ��ִ��ǰ/��ִ�У�SetUp/TearDown�����Բ��Ե�Ԫ			*
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