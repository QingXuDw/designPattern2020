#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include<ostream>
#include <Windows.h>
#include "BaseClasses.h"
#include"TravelPlan.h"
#include"exhibit.h"

using namespace std;

/************************************************************************************
*																					*
*							         ������ģʽ								      *
*																					*
*************************************************************************************/

/*����һ��ö������*/

/*�����߳������
* ��Ŀ�����������߾��̳��Դ���
*/
class AbstractVisitor :public DPObject
{
public:
	/*���ʱ�����
	* ���ڴ�ӡ������̽�յ�ģ�忪��
	* @return void
	*/
	virtual void VisitGhostCave() {
		cout << "*********************************************************************" << endl;
		cout << "****************************** ������ *****************************" << endl;
		cout << "*********************************************************************" << endl << endl;
		cout << "��ӭ���������ߣ�" << endl << endl << "̽���ߣ�������ǰ����׼������" << endl << endl;
		cout << "����������������������������������������������������������������������" << endl;

	}
	/*���ʱ���չ��
	* ���ڴ�ӡ�ι۱���չ����ģ�忪��
	* @return void
	*/
	virtual void VisitIceSculptureExhibit() {
		cout << "��ӭ�ι۱���չ����" << endl << endl;
		cout << "����������鿴�ı����ţ�" << endl << endl;
		exhibit::getInstance().showExhibit();
		system("pause");
		
	}
};

/*ʵ�ʷ�������
* �̳г���������࣬����ʵ�ַ�������Ϊ
*/
class ConcreteVisitor:public AbstractVisitor
{
public:
	//��ʽ���幹�캯��ʹ�ø���Ĭ�Ϲ��캯��
	ConcreteVisitor():AbstractVisitor(){};

	/*���ʱ�����
	* ���ظ����麯������ӡ����̽�������ߵ��ж�
	* @return void
	*/
	void VisitGhostCave();

	/*���ʱ���չ��
	* ���ظ����麯������ӡ����ι۱���չ�����ж�
	* @return void
	*/
	void VisitIceSculptureExhibit(){
		AbstractVisitor::VisitIceSculptureExhibit();
		cout<<endl<<"�ι۽�����������̤���г̡�"<<endl<<endl;
		system("pause");
	}
};
/*���󳡾���
* ������ģ����ʵ�ֵĳ������̳и���
*/
class Scene :public DPObject
{
public:
	/*���շ�����
	* ���麯����ʵ�ֳ���������߽ӿ�
	* @param level ���յķ����߶���
	* @return void
	*/
	virtual void accept(AbstractVisitor* visitor) = 0;

};
/*ʵ�ʷ�������
* �̳г���������࣬����ʵ�ַ�������Ϊ
*/
class ConcreteVisitor;
class IceSculptureExhibit :public Scene
{
	/*��ӡ����ָ��
	* �����麯����ʵ�ֱ���չ�������߽ӿ�
	* @param level ���յķ����߶���
	* @return void
	*/
public:
	void accept(AbstractVisitor* visitor) {
		visitor->VisitIceSculptureExhibit();
	}
};

class ConcreteVisitor :public AbstractVisitor
{
public:
	//��ʽ���幹�캯��ʹ�ø���Ĭ�Ϲ��캯��
	ConcreteVisitor() :AbstractVisitor() {};

	/*���ʱ�����
	* ���ظ����麯������ӡ����̽�������ߵ��ж�
	* @return void
	*/
	void VisitGhostCave();

	/*����չ����
* �̳г��󳡾���
*/

/*���ʱ���չ��
* ���ظ����麯������ӡ����ι۱���չ�����ж�
* @return void
*/
	void VisitIceSculptureExhibit() {
		AbstractVisitor::VisitIceSculptureExhibit();
		cout << endl << "�ι۽�����������̤���г̡�" << endl << endl;
		system("pause");
	}
};


/*��������
* �̳г��󳡾���
*/
class GhostCave :public Scene
{
public:
	/*��ӡ����ָ��
	* �����麯����ʵ�ֱ����߷����߽ӿ�
	* @param level ���յķ����߶���
	* @return void
	*/
	void accept(AbstractVisitor* visitor) {
		visitor->VisitGhostCave();
	}
	/*��ʾװ��
	* ����չʾ��ʼ״̬�����ߵ�װ��
	* @return void
	*/
	virtual void showDecorate() {
		cout << "�����ߵ�ǰ��װ��Ϊ��" << endl << "��׶" << endl;
	}
};

/************************************************************************************
*																					*
*							         װ��ģʽ								      *
*				 ����ʵ��װ�α����ߣ�����GhostCave��װ������Ļ���				  *
*																					*
*************************************************************************************/

/*װ������
* ����װ�������࣬����ʵ��װ������̳��ڴ���
*/
class Decorator :public GhostCave
{
public:
	/*װ�������캯��
	* ���캯����ҪGhostCave������Ϊװ�ζ���
	* @param mainCave GhostCave����
	* @return void
	*/
	Decorator(GhostCave* mainCave) : cave(mainCave) {}
	/*��ʾװ��
	* ���ظ����麯��������չʾ��ʼ״̬�����ߵ�װ��
	* @return void
	*/
	virtual void showDecorate() {
		cave->showDecorate();
	}
private:
	//˽�г�Ա����װ�ζ����ָ��
	GhostCave* cave;
};
/*װ�α�����
* �̳�װ�����࣬ʵ����ӱ���װ��
*/
class AddGhost :public Decorator
{
public:
	/*���캯��
	* ���캯����ҪGhostCave������Ϊװ�ζ���
	* @param mainCave GhostCave����
	* @return void
	*/
	AddGhost(GhostCave* mainCave) : Decorator(mainCave) {}
	/*��ʾװ��
	* ���ظ����麯�����������װ��
	* @return void
	*/
	void showDecorate() {
		Decorator::showDecorate();
		cout << "����" << endl;
	}
};
/*װ��������
* �̳�װ�����࣬ʵ���������װ��
*/
class AddBone :public Decorator
{
public:
	/*���캯��
	* ���캯����ҪGhostCave������Ϊװ�ζ���
	* @param mainCave GhostCave����
	* @return void
	*/
	AddBone(GhostCave* mainCave) : Decorator(mainCave) {}
	/*��ʾװ��
	* ���ظ����麯�����������װ��
	* @return void
	*/
	void showDecorate() {
		Decorator::showDecorate();
		cout << "����" << endl;
	}
};

/*�����߽�����
* �̳���ָ�������
*/
class GhostCaveReceiver :public CommandReceiver
{
private:
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"cave"
	* @return void
	*/
	GhostCaveReceiver() : CommandReceiver("cave") {}

protected:
	/*ִ��ָ��
	* ���ظ���ִ��ָ��Ĵ��麯�����������������ִ����Ӧ����
	* @param cmd �û������ָ������
	* @return bool ָ���ʽ�Ƿ���ȷ
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "go") {
			ConcreteVisitor* visitor = new ConcreteVisitor();
			GhostCave* mainCave = new GhostCave();
			mainCave->accept(visitor);

			return true;
		}
		return false;
	}
	/*��ӡ����ָ��
	* ���ظ����麯��������level��ӡ��Ӧ��ʽ��ָ��Լ�������ָ��
	* @param level ��ǰReciver��Reciver���еĲ㼶
	* @return void
	*/
	virtual void printHelp(int level) {
		CommandReceiver::printHelp(level);				//���ø����Ĭ��printHelp�������ݹ������ǰ���ӽ�������tag
		level++;								//����ָ����ʾ����һ��
		std::string head(level * 3, '-');
		std::cout << head + "go" << std::endl;	//�����ָ��
	}

public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	GhostCaveReceiver(const GhostCaveReceiver&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	GhostCaveReceiver& operator=(const GhostCaveReceiver&) = delete;
	/*��ȡ�����ߵ�����
	* ��ȡȫ��Ψһ�����ߵ�ʵ�������ã�����ʵ�ֵ�����
	* @return TestSpot& �����ߵ�����
	*/
	static GhostCaveReceiver& getInstance() {
		static GhostCaveReceiver cave;
		return cave;
	}
};
/*���ⶴ�߼ƻ�����
* �̳��ڳ���ƻ�����
*/
class CavePlanFactory : public AbstractPlanFactory {
public:
	/*����·��
	* @return Path* ���ɵ�·��
	*/
	Path* makePath() {
		Path* path = new Path();
		path->vehicle = "car";
		return path;
	}
	/*��������
	* @return Path* ���ɵ�����
	*/
	Description* makeDescription() {
		Description* des = new Description();
		des->content = "������ʵ����װ��ģʽ�ͷ�����ģʽ����������VisitorClasses.h";
		return des;
	}
	/*����Ŀ��ص�
	* @return Path* ���ɵ�Ŀ��ص�
	*/
	Spot* makeSpot() {
		Spot& spot = GhostCaveReceiver::getInstance();
		return &spot;
	}
};

/*չ��������
* �̳���ָ���������ʵ�ֲι۱���չ��
*/
class ExhibitReceiver :public CommandReceiver
{
private:
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"exhibit"
	* @return void
	*/
	ExhibitReceiver() : CommandReceiver("exhibit") {}

protected:
	/*ִ��ָ��
	* ���ظ���ִ��ָ��Ĵ��麯�����������������ִ����Ӧ����
	* @param cmd �û������ָ������
	* @return bool ָ���ʽ�Ƿ���ȷ
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "go") {
			ConcreteVisitor* visitor = new ConcreteVisitor();
			IceSculptureExhibit* mainExhibit = new IceSculptureExhibit();
			mainExhibit->accept(visitor);

			return true;
		}
		return false;
	}
	/*��ӡ����ָ��
	* ���ظ����麯��������level��ӡ��Ӧ��ʽ��ָ��Լ�������ָ��
	* @param level ��ǰReciver��Reciver���еĲ㼶
	* @return void
	*/
	virtual void printHelp(int level) {
		CommandReceiver::printHelp(level);				//���ø����Ĭ��printHelp�������ݹ������ǰ���ӽ�������tag
		level++;								//����ָ����ʾ����һ��
		std::string head(level * 3, '-');
		std::cout << head + "go" << std::endl;	//�����ָ��
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	ExhibitReceiver(const ExhibitReceiver&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	ExhibitReceiver& operator=(const ExhibitReceiver&) = delete;
	/*��ȡ����
	* ��ȡȫ��Ψһ����չ����ʵ�������ã�����ʵ�ֵ�����
	* @return TestSpot& ����չ��������
	*/
	static ExhibitReceiver& getInstance() {
		static ExhibitReceiver instance;
		return instance;
	}
};
/*����չ���ƻ�����
* �̳��ڳ���ƻ�����
*/
class ExhibitPlanFactory : public AbstractPlanFactory {
public:
	/*����·��
	* @return Path* ���ɵ�·��
	*/
	Path* makePath() {
		Path* path = new Path();
		path->vehicle = "car";
		return path;
	}
	/*��������
	* @return Path* ���ɵ�����
	*/
	Description* makeDescription() {
		Description* des = new Description();
		des->content = "����չ��";
		return des;
	}
	/*����Ŀ��ص�
	* @return Path* ���ɵ�Ŀ��ص�
	*/
	Spot* makeSpot() {
		Spot& spot = ExhibitReceiver::getInstance();
		return &spot;
	}
};


/*װ����������
* �̳���ָ���������ʵ�ֶԱ����ߵ�װ��
*/
class DecoratorReceiver :public CommandReceiver
{
private:
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"decorate"
	* @return void
	*/
	DecoratorReceiver() : CommandReceiver("decorate") {
		mainCave = new GhostCave();
	}

	GhostCave* mainCave = nullptr;

protected:
	/*ִ��ָ��
	* ���ظ���ִ��ָ��Ĵ��麯����ָ����ȷʱ����װ��ģ��
	* @param cmd �û������ָ������
	* @return bool ָ���ʽ�Ƿ���ȷ
	*/
	bool executeCommand(std::string cmd) {
		if (cmd != "") {
			return false;
		}
		cout << "*********************************************************************" << endl;
		cout << "************************** ������װ��ģ�� *************************" << endl;
		cout << "*********************************************************************" << endl << endl;
		int order;
		while (1) {
			if (state == 0) {
				cout << "������ָ�����Լ�����1������������  2����ʾ��ǰװ��  3����ӱ���  4���������" << endl;
				cout << ">";
				if (cin >> order) {
					cin.get();
					if (order == 1) {
						cout << "�ѷ���" << endl << endl;
						break;
					}
					if (order == 2) {
						mainCave->showDecorate();
						cout << endl;
						continue;
					}
					if (order == 3) {
						mainCave = new AddGhost(mainCave);
						cout << "װ�γɹ�" << endl << endl;
						state = 1;
						continue;
					}
					if (order == 4) {
						mainCave = new AddBone(mainCave);
						cout << "װ�γɹ�" << endl << endl;
						state = 2;
						continue;
					}
					cout << "��Чָ�����������ָ���ʽ" << endl;
				}
				else {
					cout << "��Чָ�����������ָ���ʽ" << endl;
					cin.clear();                     //����cin������
					string tmpbuf;                   //������ȡ���������Ч��
					getline(cin, tmpbuf);
				}
			}
			if (state == 1) {
				cout << "������ָ�����Լ�����1������������  2����ʾ��ǰװ��  3���������" << endl;
				cout << ">";
				if (cin >> order) {
					cin.get();
					if (order == 1) {
						cout << "�ѷ���" << endl << endl;
						break;
					}
					if (order == 2) {
						mainCave->showDecorate();
						cout << endl;
						continue;
					}
					if (order == 3) {
						mainCave = new AddBone(mainCave);
						cout << "װ�γɹ�" << endl << endl;
						state = 3;
						continue;
					}
					cout << "��Чָ�����������ָ���ʽ" << endl;//�������ֵ����
				}
				else {
					cout << "��Чָ�����������ָ���ʽ" << endl;
					cin.clear();                     //����cin������
					string tmpbuf;                   //������ȡ���������Ч��
					getline(cin, tmpbuf);
				}
			}
			if (state == 2) {
				cout << "������ָ�����Լ�����1������������  2����ʾ��ǰװ��  3����ӱ���" << endl;
				cout << ">";
				if (cin >> order) {
					cin.get();
					if (order == 1) {
						cout << "�ѷ���" << endl << endl;
						break;
					}
					if (order == 2) {
						mainCave->showDecorate();
						cout << endl;
						continue;
					}
					if (order == 3) {
						mainCave = new AddGhost(mainCave);
						cout << "װ�γɹ�" << endl << endl;
						state = 3;
						continue;
					}
					cout << "��Чָ�����������ָ���ʽ" << endl;
				}
				else {
					cout << "��Чָ�����������ָ���ʽ" << endl;
					cin.clear();                     //����cin������
					string tmpbuf;                   //������ȡ���������Ч��
					getline(cin, tmpbuf);
				}
			}
			if (state == 3) {
				cout << "������ָ�����Լ�����1������������  2����ʾ��ǰװ��" << endl;
				cout << ">";
				if (cin >> order) {
					cin.get();
					if (order == 1) {
						cout << "�ѷ���" << endl << endl;
						break;
					}
					if (order == 2) {
						mainCave->showDecorate();
						cout << endl;
						continue;
					}
					cout << "��Чָ�����������ָ���ʽ" << endl;
				}
				else {
					cout << "��Чָ�����������ָ���ʽ" << endl;
					cin.clear();                     //����cin������
					string tmpbuf;                   //������ȡ���������Ч��
					getline(cin, tmpbuf);
				}
			}
			cout << endl;
		}
		return true;
	}
	/*��ӡ����ָ��
	* ���ظ����麯��������level��ӡ��Ӧ��ʽ��ָ��Լ�������ָ��
	* @param level ��ǰReciver��Reciver���еĲ㼶
	* @return void
	*/
	virtual void printHelp(int level) {
		CommandReceiver::printHelp(level);				//���ø����Ĭ��printHelp�������ݹ������ǰ���ӽ�������tag
		level++;								//����ָ����ʾ����һ��
		std::string head(level * 3, '-');
		//std::cout << head + "go" << std::endl;	//�����ָ��
	}

public:
	//�����жϵ�ǰװ�ε�״̬
	int state = 0;
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	DecoratorReceiver(const DecoratorReceiver&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	DecoratorReceiver& operator=(const DecoratorReceiver&) = delete;
	/*��ȡ����
	* ��ȡȫ��Ψһװ������ʵ�������ã�����ʵ�ֵ�����
	* @return TestSpot& װ����������
	*/
	static DecoratorReceiver& getInstance() {
		static DecoratorReceiver instance;
		return instance;
	}

	//��������
	~DecoratorReceiver() {
		delete mainCave;
	}
};

void ConcreteVisitor::VisitGhostCave() {
	AbstractVisitor::VisitGhostCave();
	int currentState = DecoratorReceiver::getInstance().state;//ȡ�ù�ߵ�ǰװ��״̬
	system("pause");
	cout << "����������������������������������������������������������������������" << endl << endl;
	cout << "������խ�Ķ��ڣ�ӳ����������һ���İ��Ķ��ߡ�" << endl << endl;
	cout << "���ߵ��ıڽԱ����������ǣ����ҵı�׶������Σ�յĹ�â��" << endl << endl;
	cout << "������������Լ�ص���Ů�ӵ����ʡ��޿ײ����������Ϣ���㲻�����˸���ս��" << endl << endl;
	if (currentState == 1 || currentState == 3) {
		cout << "���ܸо���һ��Ӱ�Ӳ�ʱ����ĳ��������ζ���������ÿ���㶨��һ����ȴʲôҲû����" << endl << endl;
	}

	cout << "����������������������������������������������������������������������" << endl;
	system("pause");
	cout << "����������������������������������������������������������������������" << endl << endl;
	cout << "������Щ���£����㻹��Ӳ��ͷƤ�򶴿��ǰ��������������" << endl << endl;
	cout << "Ī�������������ţ�������������������䣬Զ����ɼ��ĺڰ���������������ʲô������������" << endl << endl;
	cout << "���Ų��ϵ�ǰ�����ռ佥��������Զ�������˻�����ˮ����һ����ֱ�ĺ���Ҳ������������Ұ�" << endl << endl;

	cout << "����������������������������������������������������������������������" << endl;
	system("pause");
	cout << "����������������������������������������������������������������������" << endl << endl;
	cout << "�Ǻ�ˮɫ����죬�治���������̡�" << endl << endl;
	cout << "��������һ���ţ�ͨ��ʺڣ���������������ദ��ֵİ��졣" << endl << endl;
	cout << "�����������죬���ǹ���ȴ����Ψһ��ǰ·���˿����Ѳ�Ը��ǰ����" << endl << endl;

	cout << "����������������������������������������������������������������������" << endl;
	system("pause");
	cout << "����������������������������������������������������������������������" << endl << endl;
	cout << "ͻȻ���󷽴���һ���ͳ����޺�" << endl << endl;
	cout << "��תͷһƲ������һ�����׶�ߵ����ΰ�ë�������������" << endl << endl;
	cout << "���ŵû겻���ᣬ��æ���������Ӵܹ�ȥ������������" << endl << endl;
	if (currentState > 1) {
		cout << "�����ϱ���ʱ����ͻȻ���ֺ�����Ư�����������İ׹ǡ���Щ�������ˮ�棬�·�Ҫ����Ҳ��������һ�����硤����������" << endl << endl;
	}

	cout << "����������������������������������������������������������������������" << endl;
	system("pause");
	cout << "����������������������������������������������������������������������" << endl << endl;
	cout << "���Ŷ���֮�󣬶���ȴ�Ѽ���ͷ��Ψ�б�����һխ����" << endl << endl;
	cout << "���ɨ���������������ѩ���Ѿ�Խ��Խ�������Ȳ����ѵ�������խ���С�����������" << endl << endl;
	cout << "����խ���������»�����ӿ��һ˿�ӳ���������ң���������һ�������ļ�С�" << endl << endl;
	cout << "������Χ���ڷ�������Ŀ���⣬�㿴����ǰһ����ɫ�Ĺ�Ӱ�������������ŵñ������۾�������������" << endl << endl;
	cout << "����������������������������������������������������������������������" << endl;
	system("pause");
	cout << "����������������������������������������������������������������������" << endl << endl;
	cout << "���������۾����Ѿ��ٴ�������԰�С�����������" << endl << endl;
}