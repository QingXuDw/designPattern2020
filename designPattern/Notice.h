#pragma once

#include<iostream>
#include<queue>
#include"BaseClasses.h"

/**
 * �ڰ彻������
 * ����������ڰ��ṩ��Ϣ�Ϳ��Դ��ж�ȡ��Ϣ�Ķ������
 */
class BBParticipant : public DPObject {
public:
	/**
	 * д����Ϣ
	 * ��������Ϣ��������ӹ�������
	 * @param queue<string> msg ��Ҫ�����޸ĵ���Ϣ����
	 * @return void
	 */
	void addNotice(std::queue<std::string > &msg) {
		std::string content;			//��Ϣд�����ṩ����Ϣ�����ַ���
		std::cout << "����������Ҫ��ӵĹ�������(������)��\n";
		getline(std::cin, content);
		std::cout << "  �����ɣ�" << std::endl;
		msg.push(content);		//�����Ϣ������
	}

	/**
	 * ��ȡ��Ϣ
	 * ���ڴ���Ϣ�����л�ȡ��Ϣ���������
	 * @param queue<string> msg ��Ҫ�����޸ĵ���Ϣ����
	 * @return void
	 */
	void getNotice(std::queue<std::string > &msg) {
		std::queue<std::string> output = msg;		//����һ�ݶ���
		int len = msg.size();			//��ȡ���г���
		if (len == 0)			//���ڿն��е��жϴ���
			std::cout << "  ��Ǹ��Ŀǰ������Ϊ�գ�" << std::endl;
		else {					//���ڷǿն�����ͨ�����϶�ȡ���ƶ��в������Ĳ���������������е���Ϣ����
			for (int i = 0; i < len; i++) {
				std::cout << "  ����" << i + 1 << ": " << output.front() << std::endl;
				output.pop();
			}
			std::cout << "  ����ΪĿǰ��ȫ�����棡" << std::endl;
		}
	}
};

/**
 * �ڰ���
 * ��Ϊ�ڰ�ģʽ�Ļ��������ʵ�֡��ڰ塱����Ϣ���У�ͬʱʵ���˵�����ڰ彻�������ķ���
 */
class Blackboard : public DPObject {
public:
	/**
	 * �ڰ彻������
	 * �������ɶ�Ӧ���û����棬���ղ������û������룬�б��û���ݲ�������Ӧ�Ľ�������
	 * @return void
	 */
	void start() {
		std::string c;	//�û��������ѯ����
		std::string d;	//���ڽ��ն�����ַ�

		while (1) {		//ѭ����ȡ������ʵ�ֹ�������д���ܵĶ��ʹ��
			std::cout << "������������ݣ�1Ϊ������Ա��2Ϊ�οͣ�0Ϊ���أ���";	//���û������������ʾ
			std::cin >> c;
			getline(std::cin, d);
			if (c == "1" ) {
				BBParticipant *worker = new BBParticipant();	//�����οͶ���
				worker->addNotice(msg);							//�οͶ���ʹ�ö�ȡ�ڰ巽��
			}
			else if (c == "2") {
				BBParticipant *visitor = new BBParticipant();	//����������Ա����
				visitor->getNotice(msg);						//������Ա����ʹ��д��ڰ巽��
			}
			else if (c == "0") {			//���û������˳�ʱ����ѭ����������ʾ
				std::cout << "  �ɹ��˳���������" << std::endl;
				return;
			}
			else							//������Ƿ�ʱ����ʾ
				std::cout << "�����������������룡\n";
		}
	}

private:
	std::queue<std::string> msg;		//��źڰ����ݵ���Ϣ����

};