#pragma once

#include"BaseClasses.h"

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
		std::cout << "  ������λ��԰������" << std::endl;
		std::cout << "  ��ɽ����λ��԰���ϲ�" << std::endl;
		std::cout << "  ����԰λ��԰���ϲ�" << std::endl;
		std::cout << "  ����չ��λ��԰����������" << std::endl;
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
		std::cout << "  ������λ����ο�԰����ͼ" << std::endl;
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
		std::cout << "  ����λ��԰��������" << std::endl;
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
		std::cout << "  �Ƶ�λ��԰������" << std::endl;
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
		std::string c;	//�û��������ѯ����
		std::string d;	//���ڽ��ն�����ַ�
		std::cout << "��ѡ��Ҫ��ѯ�����ݣ�1Ϊ������Ŀ��2Ϊ԰����ʩ��3Ϊ԰��������4Ϊ԰��ס�ޣ�0Ϊ���أ���\n";	//���û������������ʾ
		while (std::cin >> c) {		//ѭ����ȡ������ʵ����Ҷһ����ܿɶ��ʹ��
			getline(std::cin, d);
			if (c == "1")			//��ѯ������Ŀ
				ConsultPlay();
			else if (c == "2")		//��ѯ԰����ʩ
				ConsultFacility();
			else if (c == "3")		//��ѯ԰�ڲ���
				ConsultEating();
			else if (c == "4")		//��ѯ԰��ס��
				ConsultHousing();
			else if (c == "0") {	//���û������˳�ʱ����ѭ����������ʾ
				std::cout << "�ɹ��˳���ѯ����" << std::endl;
				return;
			}
			else					//������Ƿ�ʱ����ʾ
				std::cout << "�����������������룡\n";
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