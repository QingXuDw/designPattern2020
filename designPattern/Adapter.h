#pragma once

#include<sstream>
#include "FCurrency.h"

/**
 * ��������
 * ��Ϊ��ͬ����֮��һ�����������������ʹ�õĽӿ�ת��Ϊ���õĽӿ�
 */
class Adapter : public DPObject
{
public:
	/**
	 * �������๹�캯��
	 * �ڴ����µĹ���������ʱ�ֱ𴴽��µ���Ҷ���
	 */
	Adapter()
	{
		dollar = new Dollar;
		pound = new Pound;
		yen = new Yen;
	}
	/**
	 * ��������������
	 * �ڶ����������ڽ�����ֱ�ɾ�����ͷ���Ҷ���Ŀռ�
	 */
	~Adapter()
	{
		delete dollar;
		delete pound;
		delete yen;
	}
public:
	/**
	 * �ӿ�ת��
	 * ���մ���Ļ��ҽ��num���͵�ǰ��Ҫ���еĻ��Ҷһ��������situ
	 * @param num ��������
	 * @param situ �һ��������
	 * @return void
	 */
	void exchange(float num, int situ) {
		float mid;		//�м�ֵ
		float result;	//���ֵ
		switch (situ) {	//����situ�Ĳ�ͬ�Բ�ͬ��ʽʹ�ó����ӿ�
		case 44:	//������Ƿ�ʱ����ʾ
			std::cout << "��������ȷ�����\n";
			break;
		case 0:		//��������ת��ǰ�������ͬʱ����ʾ
		case 11:
		case 22:
		case 33:
			std::cout << "��ѡ��ͬ�Ļ��ң�" << std::endl;
			break;
		case 1:		//��Ԫ->Ӣ��
			mid = dollar->exchange(num, true);
			result = pound->exchange(mid, false);
			std::cout << "�һ���ɣ�" << num << "��Ԫ�Ѷһ�Ϊ" << result << "Ӣ��" << std::endl;
			break;
		case 2:		//��Ԫ->��Ԫ
			mid = dollar->exchange(num, true);
			result = yen->exchange(mid, false);
			std::cout << "�һ���ɣ�" << num << "��Ԫ�Ѷһ�Ϊ" << result << "��Ԫ" << std::endl;
			break;
		case 3:		//��Ԫ->�����
			result = dollar->exchange(num, true);
			std::cout << "�һ���ɣ�" << num << "��Ԫ�Ѷһ�Ϊ" << result << "�����" << std::endl;
			break;
		case 10:	//Ӣ��->��Ԫ
			mid = pound->exchange(num, true);
			result = dollar->exchange(mid, false);
			std::cout << "�һ���ɣ�" << num << "Ӣ���Ѷһ�Ϊ" << result << "��Ԫ" << std::endl;
			break;
		case 12:	//Ӣ��->��Ԫ
			mid = pound->exchange(num, true);
			result = yen->exchange(mid, false);
			std::cout << "�һ���ɣ�" << num << "Ӣ���Ѷһ�Ϊ" << result << "��Ԫ" << std::endl;
			break;
		case 13:	//Ӣ��->�����
			result = pound->exchange(num, true);
			std::cout << "�һ���ɣ�" << num << "Ӣ���Ѷһ�Ϊ" << result << "�����" << std::endl;
			break;
		case 20:	//��Ԫ->��Ԫ
			mid = yen->exchange(num, true);
			result = dollar->exchange(mid, false);
			std::cout << "�һ���ɣ�" << num << "��Ԫ�Ѷһ�Ϊ" << result << "��Ԫ" << std::endl;
			break;
		case 21:	//��Ԫ->Ӣ��
			mid = yen->exchange(num, true);
			result = pound->exchange(mid, false);
			std::cout << "�һ���ɣ�" << num << "��Ԫ�Ѷһ�Ϊ" << result << "Ӣ��" << std::endl;
			break;
		case 23:	//��Ԫ->�����
			result = yen->exchange(num, true);
			std::cout << "�һ���ɣ�" << num << "��Ԫ�Ѷһ�Ϊ" << result << "�����" << std::endl;
			break;
		case 30:	//�����->��Ԫ
			result = dollar->exchange(num, false);
			std::cout << "�һ���ɣ�" << num << "������Ѷһ�Ϊ" << result << "��Ԫ" << std::endl;
			break;
		case 31:	//�����->Ӣ��
			result = pound->exchange(num, false);
			std::cout << "�һ���ɣ�" << num << "������Ѷһ�Ϊ" << result << "Ӣ��" << std::endl;
			break;
		case 32:	//�����->��Ԫ
			result = yen->exchange(num, false);
			std::cout << "�һ���ɣ�" << num << "������Ѷһ�Ϊ" << result << "��Ԫ" << std::endl;
			break;
		default:
			std::cout << "��������ȷ�����\n";
			return;
		}
		return;
	}

	/**
	 * ��Ҹ�����
	 * ���մ���Ļ������ƣ����ض�Ӧ�ı���Ա�����������ʹ��
	 * @param string ��������
	 * @return int ��Ӧ�Ļ��ұ��
	 */
	int Transform(std::string c) {
		if (c == "dollar" || c == "��Ԫ")		//ͬʱ֧����Ӣ������
			return 0;
		else if (c == "pound" || c == "Ӣ��")
			return 1;
		else if (c == "yen" || c == "��Ԫ")
			return 2;
		else if (c == "RMB" || c == "�����")
			return 3;
		else			//�Ƿ������򷵻��쳣���
			return 4;
	}

	/**
	 * ���Ҷһ�����
	 * �������ɶ�Ӧ���û����棬���ղ������û������룬��ȷ������Ӧ�ĺ���
	 * @return void
	 */
	void start() {
		std::string input;		//�������
		float num;			//�������
		std::cout << "������Ҫ�һ��Ļ��������Լ�����:\n";		//���û������������ʾ
		std::cout << "(����\"�������� ���л��� �������\"�ĸ�ʽ, ��\"quit\"����)\n";
		std::cout << "(֧����Ԫ��Ӣ������Ԫ������ҵ��໥�һ�)" << std::endl;	
		while (getline(std::cin,input)) {	//ѭ����ȡ������ʵ����Ҷһ����ܿɶ��ʹ��
			if (input == "quit") {		//���û������˳�ʱ����ѭ����������ʾ
				std::cout << "�ɹ��˳����Ҷһ���" << std::endl;
				break;
			}
			std::string from, to;			//ת��ǰ��Ļ�����
			std::stringstream ss(input);		//����������ת��Ϊ��
			ss >> num >> from >> to;	//��ת�������л�ȡ�����е���������
			exchange(num, Transform(from)*10+Transform(to));	//��������ָ����ʽ���ݸ��һ�����
		}
	}

private:
	FCurrency *dollar;	//��Ԫ�����
	FCurrency *pound;	//Ӣ�������
	FCurrency *yen;		//��Ԫ�����
};