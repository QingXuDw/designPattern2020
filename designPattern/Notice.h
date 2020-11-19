#pragma once

#include<iostream>
#include<queue>
#include"BaseClasses.h"

using namespace std;

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
	void addNotice(queue<string > &msg) {
		string content;			//��Ϣд�����ṩ����Ϣ�����ַ���
		cout << "����������Ҫ��ӵĹ�������(������)��\n";
		getline(cin, content);
		cout << "  �����ɣ�" << endl;
		msg.push(content);		//�����Ϣ������
	}

	/**
	 * ��ȡ��Ϣ
	 * ���ڴ���Ϣ�����л�ȡ��Ϣ���������
	 * @param queue<string> msg ��Ҫ�����޸ĵ���Ϣ����
	 * @return void
	 */
	void getNotice(queue<string > &msg) {
		queue<string> output = msg;		//����һ�ݶ���
		int len = msg.size();			//��ȡ���г���
		if (len == 0)			//���ڿն��е��жϴ���
			cout << "  ��Ǹ��Ŀǰ������Ϊ�գ�" << endl;
		else {					//���ڷǿն�����ͨ�����϶�ȡ���ƶ��в������Ĳ���������������е���Ϣ����
			for (int i = 0; i < len; i++) {
				cout << "  ����" << i + 1 << ": " << output.front() << endl;
				output.pop();
			}
			cout << "  ����ΪĿǰ��ȫ�����棡" << endl;
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
		string c;	//�û��������ѯ����
		string d;	//���ڽ��ն�����ַ�

		while (1) {		//ѭ����ȡ������ʵ�ֹ�������д���ܵĶ��ʹ��
			cout << "������������ݣ�1Ϊ������Ա��2Ϊ�οͣ�0Ϊ���أ���";	//���û������������ʾ
			cin >> c;
			getline(cin, d);
			if (c == "1" ) {
				BBParticipant *worker = new BBParticipant();	//�����οͶ���
				worker->addNotice(msg);							//�οͶ���ʹ�ö�ȡ�ڰ巽��
			}
			else if (c == "2") {
				BBParticipant *visitor = new BBParticipant();	//����������Ա����
				visitor->getNotice(msg);						//������Ա����ʹ��д��ڰ巽��
			}
			else if (c == "0") {			//���û������˳�ʱ����ѭ����������ʾ
				cout << "  �ɹ��˳���������" << endl;
				return;
			}
			else							//������Ƿ�ʱ����ʾ
				cout << "�����������������룡\n";
		}
	}

private:
	queue<string> msg;		//��źڰ����ݵ���Ϣ����

};