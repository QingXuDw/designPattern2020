#pragma once
#include <string>
#include <iostream>
#include <map>
#include "BaseClasses.h"

using namespace std;

//�����ѩ�����裬prototype
class CIcecream :public DPObject
{
public:
	enum icBallType { ����, ��ݮ, â��, ����, �ɿ��� };  //��������Ŀ�ζ��
	enum icBiscuitType { �Ϲ�, �ƹ� };  //������С���ɵĿ�ζ��
	map<icBallType, string> mBallMap =
	{ { ����,"����" },{ ��ݮ,"��ݮ" },{ â�� ,"â��" },{ ����,"����" },{ �ɿ��� ,"�ɿ���" } }; //��������ַ���
	map<icBiscuitType, string> mBiscuitMap =
	{ { �Ϲ�,"�Ϲ�" },{ �ƹ�,"�ƹ�" } };

	/**
	* CIcecream��ʼ������
	*/
	CIcecream()
	{
	}

	/**
	* CIcecream��ʼ������
	* @param icball1 �˿�ѡ��ı�������Ŀ�ζ
	* @param icbiscuit1 �˿�ѡ��ı�����С���ɵĿ�ζ
	* @param isLarge1 �Ƿ�ѡ����
	*/
	CIcecream(icBallType icball1, icBiscuitType icbiscuit1, bool isLarge1)
	{
		icBall = icball1;
		icBiscuit = icbiscuit1;
		isLarge = isLarge1;
	}

	/**
	* clone����������һ���µ���֮һ���ı�����
	*/
	CIcecream clone()
	{
		CIcecream cNewIC(icBall, icBiscuit, isLarge);  //��ԭ�ͱ�����Ŀ�ζ���С�����±�����
		return cNewIC;
	}

	/**
	* �����������ʽ
	*/
	void icType()
	{
		string tsize = "�к�";
		if (isLarge) {
			tsize = "���";
		}
		cout <<"��������һ��"<< tsize << "����" << mBiscuitMap[icBiscuit] << "С���ɵ�" << mBallMap[icBall] << "�����衣�����ã�" << endl;
	}

private:
	icBallType icBall = ����;  //��������Ŀ�ζ
	icBiscuitType icBiscuit = �Ϲ�;  //������С���ɵĿ�ζ
	bool isLarge = false;  //�Ƿ�ѡ����
};

class IcecreamManager :public CommandReceiver {
private:
	//��¼���ַ���
	std::string str;
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"choose"
	* @return void
	*/
	IcecreamManager() : CommandReceiver("icecream") {}
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
		string sorder;  //�û�����Ĵ���
		CIcecream::icBallType oball = CIcecream::icBallType(0);  //Ĭ�Ͽ�ı�����
		CIcecream::icBiscuitType obiscuit = CIcecream::icBiscuitType(0);
		bool olarge = false;
		CIcecream nic(oball, obiscuit, olarge);  //nicΪ���������ı�����
		cout << "��ӭ���ٱ�ѩ������꣡" << endl;
		cout << "��ѡ���������ʽ��" << endl;
		cout << "������������-0����ݮ-1��â��-2������-3���ɿ���-4" << endl;
		cout << "С���ɣ��Ϲ�-0���ƹ�-1" << endl;
		cout << "��С���з�-0�����-1" << endl;
		cout << "������λ���ִ����ʾ��������ʽ���磺â����������+�Ϲ�С����+��ݵĴ���Ϊ201" << endl;
		cout << "��Ҫ����һ����ʽ��ͬ�ı����裬���������8" << endl;
		cout << "��Ҫ�뿪������꣬���������9" << endl;
		while (cin >> sorder) {
			if (sorder.length()==3&&sorder[0]>='0'&&sorder[0]<='4'&&sorder[1] >= '0'&&sorder[1] <= '1'&&sorder[2] >= '0'&&sorder[2] <= '1') {  //�û���ȷ������������
				int iballtype = static_cast<int>(sorder[0]-'0');
				int ibiscuittype = static_cast<int>(sorder[1]-'0');
				nic=CIcecream(CIcecream::icBallType(iballtype), CIcecream::icBiscuitType(ibiscuittype), (bool)(sorder[2]-'0'));
				nic.icType();
			}
			else if (sorder.length() == 1&&sorder[0]=='9') {  //�û��뿪�������
				cout << "��ӭ�ٴι��٣�" << endl;
				std::string temp;
				getline(cin, temp);
				return true;
			}
			else if (sorder.length() == 1 && sorder[0] == '8') {  //�û�Ҫ���Ʊ�����
				nic = nic.clone();
				nic.icType();
			}
			else {  //�û����벻�Ϸ��Ĵ���
				cout << "��С��������������˼�����������롣" << endl;
			}
		}
		return true;
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	IcecreamManager(const IcecreamManager&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	IcecreamManager& operator=(const IcecreamManager&) = delete;
	/*��ȡ��ǰ������������
	* ��ȡȫ��Ψһ��ǰ��������ʵ�������ã�����ʵ�ֵ�����
	* @return Mountain& ��ǰ������������
	*/
	static IcecreamManager& getInstance() {
		static IcecreamManager receiver;
		return receiver;
	}
 };

