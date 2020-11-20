#pragma once

#include <iostream>
#include"BaseClasses.h"

/**
 * ��ҳ������
 * ��Ŀ�г��ֵ�����ָ������߾��̳��Դ���
 */
class FCurrency : public DPObject
{
public:
	/**
	 * ���Ҷһ�
	 * ���մ���Ļ��ҽ��num�����ݸ���toRMB�Ĳ���ֵ����˳�������ת��������һ�����Ӧ�Ļ�������
	 * @param num ��������
	 * @param toRMB �Ƿ�Ϊת����RMB
	 * @return float ת���������
	 */
	virtual float exchange(float num, bool toRMB) = 0;
};

/**
 * ��Ԫ��
 * ���ڹ������Ԫ��صĲ������̳�����ҳ������
 */
class Dollar :public FCurrency {
public:
	/**
	 * ��Ԫ�һ�
	 * ���մ���Ļ��ҽ��num�����ݸ���toRMB�Ĳ���ֵ����˳�������ת��������һ�����Ӧ�Ļ�������
	 * @param num ��������
	 * @param toRMB �Ƿ�Ϊת����RMB
	 * @return float ת���������
	 */
	virtual float exchange(float num, bool toRMB) {
		if (toRMB == true)
			return num * 6.576;
		else
			return num / 6.576;
	}
};

/**
 * Ӣ����
 * ���ڹ����Ӣ����صĲ������̳�����ҳ������
 */
class Pound :public FCurrency {
public:
	/**
	 * Ӣ���һ�
	 * ���մ���Ļ��ҽ��num�����ݸ���toRMB�Ĳ���ֵ����˳�������ת��������һ�����Ӧ�Ļ�������
	 * @param num ��������
	 * @param toRMB �Ƿ�Ϊת����RMB
	 * @return float ת���������
	 */
	virtual float exchange(float num, bool toRMB) {
		if (toRMB == true)
			return num * 8.6685;
		else
			return num / 8.6685;
	}
};

/**
 * ��Ԫ��
 * ���ڹ������Ԫ��صĲ������̳�����ҳ������
 */
class Yen :public FCurrency {
public:
	/**
	 * ��Ԫ�һ�
	 * ���մ���Ļ��ҽ��num�����ݸ���toRMB�Ĳ���ֵ����˳�������ת��������һ�����Ӧ�Ļ�������
	 * @param num ��������
	 * @param toRMB �Ƿ�Ϊת����RMB
	 * @return float ת���������
	 */
	virtual float exchange(float num, bool toRMB) {
	if (toRMB == false)
		return num * 15.9313;
	else
		return num / 15.9313;
}
};