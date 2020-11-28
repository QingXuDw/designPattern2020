#pragma once
#include <iostream>
// #include <windows.h>
#include "BaseClasses.h"
#include "TravelPlan.h"



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
	/**
	* ���ʱ������
	* ���ڴ�ӡ�������̽�յ�ģ�忪��
	* @return void
	*/
	virtual void VisitGhostCave(){
		std::cout<<"*********************************************************************"<<std::endl;
		std::cout<<"****************************** ������� *****************************"<<std::endl;
		std::cout<<"*********************************************************************"<<std::endl<<std::endl;
		std::cout<<"��ӭ����������ߣ�"<<std::endl<<std::endl<<"̽���ߣ�������ǰ����׼������"<<std::endl<<std::endl;
		std::cout<<"����������������������������������������������������������������������"<<std::endl;
	}
	
	/*���ʱ���չ��
	* ���ڴ�ӡ�ι۱���չ����ģ�忪��
	* @return void
	*/
	virtual void VisitIceSculptureExhibit() {
		std::cout<<std::endl<<"��ӭ�ι۱���չ����"<<std::endl<<std::endl;
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

	/*���ʱ������
	* ���ظ����麯������ӡ�����߾���̽��������ߵ��ж�
	* @return void
	*/
	void VisitGhostCave();

	/*���ʱ���չ��
	* ���ظ����麯������ӡ�����߾���ι۱���չ�����ж�
	* @return void
	*/
	void VisitIceSculptureExhibit(){
		AbstractVisitor::VisitIceSculptureExhibit();
		exhibit::getInstance().showExhibit();
		std::cout<<std::endl<<"�ι۽�����������̤���г̡�"<<std::endl<<std::endl;
		system("pause");
	}
};
/*���󳡾���
* ������ģ����ʵ�ֵĳ������̳и���
*/
class Scene :public DPObject
{
protected:
	/*���շ�����
	* ���麯����ʵ�ֳ�������ܷ����߶���Ľӿ�
	* @param level ���յķ����߶���
	* @return void
	*/
	virtual void accept(AbstractVisitor* visitor) = 0;

};
/*ʵ�ʷ�������
* �̳г���������࣬����ʵ�ַ�������Ϊ
*/
class IceSculptureExhibit :public Scene
{
	/*��ӡ����ָ��
	* ��д�����麯����ʵ�ֱ���չ�����ܷ����߶���Ľӿ�
	* @param level ���յķ����߶���
	* @return void
	*/
public:
	void accept(AbstractVisitor* visitor) {
		visitor->VisitIceSculptureExhibit();
	}
	
};

/*���������
* �̳г��󳡾���
*/
class GhostCave :public Scene
{
public:
	/*��ӡ����ָ��
	* ��д�����麯����ʵ�ֱ�����߽��ܷ����߶���Ľӿ�
	* @param level ���յķ����߶���
	* @return void
	*/
	void accept(AbstractVisitor* visitor) {
		visitor->VisitGhostCave();
	}
	/*��ʾװ��
	* ����չʾ��ʼ״̬������ߵ�װ��
	* @return void
	*/
	virtual void showDecorate(){
        std::cout<< "������ߵ�ǰ��װ��Ϊ��"<<std::endl<<"��׶"<<std::endl;
    }
};

/************************************************************************************
*																					*
*							         װ��ģʽ								      *
*				 ����ʵ��װ�α�����ߣ�����GhostCave��װ������Ļ���				  *
*																					*
*************************************************************************************/

/*װ������
* ����װ�������࣬����ʵ��װ������̳��ڴ���
*/
class Decorator :public GhostCave
{
protected:
	/*װ�������캯��
	* ���캯����ҪGhostCave������Ϊװ�ζ���
	* @param mainCave GhostCave����
	* @return void
	*/
	Decorator(GhostCave* mainCave) : cave(mainCave) {}
	/*��ʾװ��
	* ���ظ����麯��������չʾ��ʼ״̬������ߵ�װ��
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
* �̳�װ�����࣬ʵ�����ӱ���װ��
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
	* ���ظ����麯������������װ��
	* @return void
	*/
    void showDecorate() {
        Decorator::showDecorate();
        std::cout<<"����"<<std::endl;
    }
};
/*װ��������
* �̳�װ�����࣬ʵ����������װ��
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
	* ���ظ����麯������������װ��
	* @return void
	*/
    void showDecorate() {
        Decorator::showDecorate();
        std::cout<<"����"<<std::endl;
    }
};

/*������߽�����
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
			delete mainCave;
			delete visitor;
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
	/*��ȡ������ߵ�����
	* ��ȡȫ��Ψһ������ߵ�ʵ�������ã�����ʵ�ֵ�����
	* @return TestSpot& ������ߵ�����
	*/
	static GhostCaveReceiver& getInstance() {
		static GhostCaveReceiver instance;
		return instance;
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
		des->content = "�������ʵ����װ��ģʽ�ͷ�����ģʽ����������VisitorClasses.h";
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
			AbstractVisitor* visitor = new ConcreteVisitor();
			IceSculptureExhibit* mainExhibit = new IceSculptureExhibit();
			mainExhibit->accept(visitor);

			delete visitor;
			delete mainExhibit;
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
* �̳���ָ���������ʵ�ֶԱ�����ߵ�װ��
*/
class DecoratorReceiver :public CommandReceiver
{
private:
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"decorate"
	* @return void
	*/
	DecoratorReceiver() : CommandReceiver("decorate") {
		mainCave=new GhostCave();
		if(mainCave==nullptr){
			std::cout<<"new GhostCave failed"<<std::endl;
		}
	}
	//װ����ʹ�õı�����ߵ�Ψһʵ����ָ��
	GhostCave* mainCave=nullptr;

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
		
		std::cout<<"*********************************************************************"<<std::endl;
		std::cout<<"************************** �������װ��ģ�� *************************"<<std::endl;
		std::cout<<"*********************************************************************"<<std::endl<<std::endl;
		int order;
		while(1){
			if(state==0){
				std::cout<<"������ָ�����Լ�����1������������  2����ʾ��ǰװ��  3�����ӱ���  4����������"<<std::endl;
				std::cout<<">";
				if(std::cin>>order){
					std::cin.get();
					if(order==1){
						std::cout<<"�ѷ���"<<std::endl<<std::endl;
						break;
					}
					if (order == 2) {
						mainCave->showDecorate();
						std::cout<<std::endl;
						continue;
					}
					if(order==3){
						mainCave=new AddGhost(mainCave);
						std::cout<<"װ�γɹ�"<<std::endl<<std::endl;
						state=1;
						continue;
					}
					if(order==4){
						mainCave=new AddBone(mainCave);
						std::cout<<"װ�γɹ�"<<std::endl<<std::endl;
						state=2;
						continue;
					}
					std::cout<<"��Чָ�����������ָ���ʽ"<<std::endl;
				}
				else{
					std::cout<<"��Чָ�����������ָ���ʽ"<<std::endl;
					std::cin.clear();                     //����cin������
					std::string tmpbuf;                   //������ȡ���������Ч��
					getline(std::cin,tmpbuf);
				}
			}
			if(state==1){
				std::cout<<"������ָ�����Լ�����1������������  2����ʾ��ǰװ��  3����������"<<std::endl;
				std::cout<<">";
				if(std::cin>>order){
					std::cin.get();
					if(order==1){
						std::cout<<"�ѷ���"<<std::endl<<std::endl;
						break;
					}
					if (order == 2) {
						mainCave->showDecorate();
						std::cout<<std::endl;
						continue;
					}
					if(order==3){
						mainCave=new AddBone(mainCave);
						std::cout<<"װ�γɹ�"<<std::endl<<std::endl;
						state=3;
						continue;
					}
					std::cout<<"��Чָ�����������ָ���ʽ"<<std::endl;//�������ֵ����
				}
				else{
					std::cout<<"��Чָ�����������ָ���ʽ"<<std::endl;
					std::cin.clear();                     //����cin������
					std::string tmpbuf;                   //������ȡ���������Ч��
					getline(std::cin,tmpbuf);
				}
			}
			if(state==2){
				std::cout<<"������ָ�����Լ�����1������������  2����ʾ��ǰװ��  3�����ӱ���"<<std::endl;
				std::cout<<">";
				if(std::cin>>order){
					std::cin.get();
					if(order==1){
						std::cout<<"�ѷ���"<<std::endl<<std::endl;
						break;
					}
					if (order == 2) {
						mainCave->showDecorate();
						std::cout<<std::endl;
						continue;
					}
					if(order==3){
						mainCave=new AddGhost(mainCave);
						std::cout<<"װ�γɹ�"<<std::endl<<std::endl;
						state=3;
						continue;
					}
					std::cout<<"��Чָ�����������ָ���ʽ"<<std::endl;
				}
				else{
					std::cout<<"��Чָ�����������ָ���ʽ"<<std::endl;
					std::cin.clear();                     //����cin������
					std::string tmpbuf;                   //������ȡ���������Ч��
					getline(std::cin,tmpbuf);
				}
			}
			if(state==3){
				std::cout<<"������ָ�����Լ�����1������������  2����ʾ��ǰװ��"<<std::endl;
				std::cout<<">";
				if(std::cin>>order){
					std::cin.get();
					if(order==1){
						std::cout<<"�ѷ���"<<std::endl<<std::endl;
						break;
					}
					if (order == 2) {
						mainCave->showDecorate();
						std::cout<<std::endl;
						continue;
					}
					std::cout<<"��Чָ�����������ָ���ʽ"<<std::endl;
				}
				else{
					std::cout<<"��Чָ�����������ָ���ʽ"<<std::endl;
					std::cin.clear();                     //����cin������
					std::string tmpbuf;                   //������ȡ���������Ч��
					getline(std::cin,tmpbuf);
				}
			}
			std::cout<<std::endl;
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

void ConcreteVisitor:: VisitGhostCave(){
		AbstractVisitor::VisitGhostCave();
		int currentState=DecoratorReceiver::getInstance().state;//ȡ�ù��ߵ�ǰװ��״̬
		system("pause");
		std::cout<<"����������������������������������������������������������������������"<<std::endl<<std::endl;
		std::cout<<"������խ�Ķ��ڣ�ӳ����������һ���İ��Ķ��ߡ�"<<std::endl<<std::endl;
		std::cout<<"���ߵ��ıڽԱ����������ǣ����ҵı�׶������Σ�յĹ�â��"<<std::endl<<std::endl;
		std::cout<<"������������Լ�ص���Ů�ӵ����ʡ��޿ײ����������Ϣ���㲻�����˸���ս��"<<std::endl<<std::endl;
		if(currentState==1||currentState==3){
			std::cout<<"���ܸо���һ��Ӱ�Ӳ�ʱ����ĳ��������ζ���������ÿ���㶨��һ����ȴʲôҲû����"<<std::endl<<std::endl;
		}

		std::cout<<"����������������������������������������������������������������������"<<std::endl;
		system("pause");
		std::cout<<"����������������������������������������������������������������������"<<std::endl<<std::endl;
		std::cout<<"������Щ���£����㻹��Ӳ��ͷƤ�򶴿��ǰ��������������"<<std::endl<<std::endl;
		std::cout<<"Ī�������������ţ�������������������䣬Զ����ɼ��ĺڰ���������������ʲô������������"<<std::endl<<std::endl;
		std::cout<<"���Ų��ϵ�ǰ�����ռ佥��������Զ�������˻�����ˮ����һ����ֱ�ĺ���Ҳ������������Ұ�"<<std::endl<<std::endl;

		std::cout<<"����������������������������������������������������������������������"<<std::endl;
		system("pause");
		std::cout<<"����������������������������������������������������������������������"<<std::endl<<std::endl;
		std::cout<<"�Ǻ�ˮɫ����죬�治���������̡�"<<std::endl<<std::endl;
		std::cout<<"��������һ���ţ�ͨ��ʺڣ����������������ദ��ֵİ��졣"<<std::endl<<std::endl;
		std::cout<<"�����������죬���ǹ���ȴ����Ψһ��ǰ·���˿����Ѳ�Ը��ǰ����"<<std::endl<<std::endl;

		std::cout<<"����������������������������������������������������������������������"<<std::endl;
		system("pause");
		std::cout<<"����������������������������������������������������������������������"<<std::endl<<std::endl;
		std::cout<<"ͻȻ���󷽴���һ���ͳ����޺�"<<std::endl<<std::endl;
		std::cout<<"��תͷһƲ������һ�����׶�ߵ����ΰ�ë�������������"<<std::endl<<std::endl;
		std::cout<<"���ŵû겻���ᣬ��æ���������Ӵܹ�ȥ������������"<<std::endl<<std::endl;
		if(currentState > 1){
			std::cout<<"�����ϱ���ʱ����ͻȻ���ֺ�����Ư�����������İ׹ǡ���Щ�������ˮ�棬�·�Ҫ����Ҳ��������һ�����硤����������"<<std::endl<<std::endl;
		}

		std::cout<<"����������������������������������������������������������������������"<<std::endl;
		system("pause");
		std::cout<<"����������������������������������������������������������������������"<<std::endl<<std::endl;
		std::cout<<"���Ŷ���֮�󣬶���ȴ�Ѽ���ͷ��Ψ�б�����һխ����"<<std::endl<<std::endl;
		std::cout<<"���ɨ����������������ѩ���Ѿ�Խ��Խ�������Ȳ����ѵ�������խ���С�����������"<<std::endl<<std::endl;
		std::cout<<"����խ���������»�����ӿ��һ˿�ӳ���������ң���������һ�������ļ�С�"<<std::endl<<std::endl;
		std::cout<<"������Χ���ڷ�������Ŀ���⣬�㿴����ǰһ����ɫ�Ĺ�Ӱ�������������ŵñ������۾�������������"<<std::endl<<std::endl;
		std::cout<<"����������������������������������������������������������������������"<<std::endl;
		system("pause");
		std::cout<<"����������������������������������������������������������������������"<<std::endl<<std::endl;
		std::cout<<"���������۾����Ѿ��ٴ���������԰�С�����������"<<std::endl<<std::endl;
	}
