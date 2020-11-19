#pragma once

#include<iostream>
#include"BaseClasses.h"

using namespace std;

/**
 * ԰��������Ŀ��
 * ��Ϊ��ѯ���ݵ�һ���֣��������û�����԰��������Ŀ�ĸ�����Ϣ
 */
class ParkPlaying : public DPObject
{
public:
	/**
	 * λ�ý���
	 * ���û�����԰��������Ŀ��λ��
	 * @return void
	 */
	void Location() {
		cout << "  ������λ��԰������" << endl;
		cout << "  ��ɽ����λ��԰���ϲ�" << endl;
		cout << "  ����԰λ��԰���ϲ�" << endl;
		cout << "  ����չ��λ��԰����������" << endl;
	}
};

/**
 * ԰����ʩ��
 * ��Ϊ��ѯ���ݵ�һ���֣��������û�����԰��������ʩ�ĸ�����Ϣ
 */
class ParkFacility : public DPObject
{
public:
	/**
	 * λ�ý���
	 * ���û�����԰���ڸ�����ʩ��Ŀ��λ��
	 * @return void
	 */
	void Location() {
		cout << "  ������λ����ο�԰����ͼ" << endl;
	}
};

/**
 * ԰��������
 * ��Ϊ��ѯ���ݵ�һ���֣��������û�����԰���ڲ����ĸ�����Ϣ
 */
class ParkEating : public DPObject
{
public:
	/**
	 * λ�ý���
	 * ���û�����԰���ڲ�����λ��
	 * @return void
	 */
	void Location() {
		cout << "  ����λ��԰��������" << endl;
	}
};

/**
 * ԰��ס����
 * ��Ϊ��ѯ���ݵ�һ���֣��������û�����԰���ھƵ��ùݵĸ�����Ϣ
 */
class ParkHousing : public DPObject
{
public:
	/**
	 * λ�ý���
	 * ���û�����԰���ھƵ��ùݵ�λ��
	 * @return void
	 */
	void Location() {
		cout << "  �Ƶ�λ��԰������" << endl;
	}
};

/**
 * �����
 * ��Ϊ��ѯ�������壬�����û���ͨ������Ϳ��˽⵽԰�����������ݵ���Ϣ
 */
class Facade : public DPObject
{
public:
	/**
	 * ����๹�캯��
	 * �ڴ��������Ķ����ͬʱ�ֱ�����԰�ڸ�������Ķ���
	 */
	Facade(){
		this->_parkPlaying = new ParkPlaying();
		this->_parkFacility = new ParkFacility();
		this->_parkEating = new ParkEating();
		this->_parkHousing = new ParkHousing();
	}

	/**
	 * ������Ŀ��ѯ
	 * ����������Ŀλ�ò�ѯ
	 * @return void
	 */
	void ConsultPlay() {
		this->_parkPlaying->Location();
	}

	/**
	 * ԰����ʩ��ѯ
	 * ����԰����ʩλ�ò�ѯ
	 * @return void
	 */
	void ConsultFacility() {
		this->_parkFacility->Location();
	}

	/**
	 * ԰�ڲ�����ѯ
	 * ����԰�ڲ���λ�ò�ѯ
	 * @return void
	 */
	void ConsultEating() {
		this->_parkEating->Location();
	}

	/**
	 * ԰��ס�޲�ѯ
	 * ����԰��ס��λ�ò�ѯ
	 * @return void
	 */
	void ConsultHousing() {
		this->_parkHousing->Location();
	}
	
	/**
	 * ��ѯ����
	 * �������ɶ�Ӧ���û����棬���ղ������û������룬��ȷ������Ӧ�ĺ���
	 * @return void
	 */
	void start() {
		string c;	//�û��������ѯ����
		string d;	//���ڽ��ն�����ַ�
		cout << "��ѡ��Ҫ��ѯ�����ݣ�1Ϊ������Ŀ��2Ϊ԰����ʩ��3Ϊ԰��������4Ϊ԰��ס�ޣ�0Ϊ���أ���\n";	//���û������������ʾ
		while (cin >> c) {		//ѭ����ȡ������ʵ����Ҷһ����ܿɶ��ʹ��
			getline(cin, d);
			if (c == "1")			//��ѯ������Ŀ
				ConsultPlay();
			else if (c == "2")		//��ѯ԰����ʩ
				ConsultFacility();
			else if (c == "3")		//��ѯ԰�ڲ���
				ConsultEating();
			else if (c == "4")		//��ѯ԰��ס��
				ConsultHousing();
			else if (c == "0") {	//���û������˳�ʱ����ѭ����������ʾ
				cout << "�ɹ��˳���ѯ����" << endl;
				return;
			}
			else					//������Ƿ�ʱ����ʾ
				cout << "�����������������룡\n";
		}
	}

	/**
	 * �������������
	 * �ڶ����������ڽ�����ֱ�ɾ�����ͷ�԰�ڸ����ݶ���Ŀռ�
	 */
	~Facade() {
		delete this->_parkPlaying;
		delete this->_parkFacility;
		delete this->_parkEating;
		delete this->_parkHousing;

		this->_parkPlaying = NULL;
		this->_parkFacility = NULL;
		this->_parkEating = NULL;
		this->_parkHousing = NULL;
	}

private:
	ParkPlaying* _parkPlaying;
	ParkFacility* _parkFacility;
	ParkEating* _parkEating;
	ParkHousing* _parkHousing;
 
};