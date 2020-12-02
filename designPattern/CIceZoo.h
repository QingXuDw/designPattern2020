#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include "BaseClasses.h"
#include "TravelPlan.h"
using namespace std;

//�ι۱�ѩ����԰��iterator
class CIceZoo:public DPObject
{
protected:
	vector<string> animallist = {"���","����","�׾�","������"};  //�����б�,���ι�˳������
public:
	//iterator�࣬�ڲ���
	class CIterator:public DPObject
	{
	public:
		/**
		* iterator��ʼ������
		* @param iz1 ��Ӧ����԰��ָ��
		*/
		CIterator(CIceZoo* iz1) {
			iz = iz1;  //��ȡ�ι۵Ķ���԰��ָ��
		}

		/**
		* �ж��Ƿ���δ�ι۵Ķ���
		* @return bool
		*/
		bool hasNext() {
			if (index < iz->animallist.size()) {
				return true;
			}
			return false;
		}

		/**
		* ���ص�ǰ���ڲι۵Ķ������Ϣ����ǰ���ι���һ�ֶ���
		* @return string ������
		*/
		string Next() {
			return iz->animallist[index++];
		}
	private:
		int index = 0;  //��ǰ���ڲι۵Ķ�������
		CIceZoo* iz; //iterator��Ӧ����԰��ָ��
	};
};

class IceZooManager :public CommandReceiver {
private:
	//��¼���ַ���
	std::string str;
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"choose"
	* @return void
	*/
	IceZooManager() : CommandReceiver("iceZoo") {}
protected:
	/*ִ��ָ��
	* ���ظ���ִ��ָ��Ĵ��麯�����������������ִ����Ӧ����
	* @param cmd �û������ָ������
	* @return bool ָ���ʽ�Ƿ���ȷ
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd != "") {
			return false;
		}
		CIceZoo* zoo1 = new CIceZoo;
		CIceZoo::CIterator* itr = new CIceZoo::CIterator(zoo1);
		cout << "��ӭ������ѩ����԰��" << endl;
		while (itr->hasNext()) {  //������������԰
			cout << "����������" << itr->Next() << "�ݣ�" << endl;
			Sleep(500);
		}
		cout << "�����뿪��ѩ����԰��" << endl;
		delete(itr);
		delete(zoo1);
		return true;
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	IceZooManager(const IceZooManager&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	IceZooManager& operator=(const IceZooManager&) = delete;
	/*��ȡ��ǰ������������
	* ��ȡȫ��Ψһ��ǰ��������ʵ�������ã�����ʵ�ֵ�����
	* @return Mountain& ��ǰ������������
	*/
	static IceZooManager& getInstance() {
		static IceZooManager receiver;
		return receiver;
	}
};

class IceZooFactory : public AbstractPlanFactory {
public:
	/*����·��
	* @return Path* ���ɵ�·��
	*/
	Path* makePath() {
		Path* path = new Path();
		path->vehicle = "walk";
		return path;
	}
	/*��������
	* @return Path* ���ɵ�����
	*/
	Description* makeDescription() {
		Description* des = new Description();
		des->content = "��ѩ����԰ʵ���˵�����ģʽ�������ͷ�ļ�CIceZoo.h";
		return des;
	}
	/*����Ŀ��ص�
	* @return Path* ���ɵ�Ŀ��ص�
	*/
	Spot* makeSpot() {
		Spot& spot = IceZooManager::getInstance();
		return &spot;
	}
};