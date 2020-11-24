#pragma once
#include "pch.h"
#include "../designPattern/BaseClasses.h"
	

//��namespace�����Է�ֹ������ͻ
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
	/*TEST_F��������һ�����Ե�Ԫ
	* ���Ե�ԪΪ���Ե���С��λ��ͨ��һ�����Ե�Ԫ��Ӧһ�����һ���ӿڣ�public�ĺ�����
	* @param param1 ���Ե�Ԫ��������������
	* @param param2 ���Ե�Ԫ��
	* ����Զ����ɼ̳���param1����Ϊparam1_param2���������ڲ���
	* �ʲ����������Ͳ��Ե�Ԫ���о����ܳ����»���
	*/
	TEST_F(TestMap, Compare)
	{
		//����param1��param2��ȣ��������ʱ��ֹ��������
		ASSERT_EQ(str->compare("abaaba"), 0);
	}
	TEST_F(TestMap, Size)
	{
		//�ڴ�param1��param2��ȣ��������ʱ�������λ�ú����飬�����������
		EXPECT_EQ(str->size(), 6);
	}

	/*���̲߳��ԣ����Դ������������߳���)
	* ������Դ����г�����������ѭ����������������⣨�³ƿ�������
	* ������һЩ��ʾ������stuck == trueʱ����������ѭ���У�ͨ��DP_F/DP_F_TIME�����������в��ԣ���TEST_F��ֹͣ��Ӧ
	* ����DP_FӦ�����ڲ�̫���ܳ��ֿ����Ĳ��Դ���
	* DF_F_TIMEӦ�������п��ܳ��ֿ����Ĳ��Դ���
	* ������Ҫʹ��TEST_F�����ǿ������������Ĳ�����û������
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
