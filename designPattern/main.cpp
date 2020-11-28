#include <cstring>
#include "ShoppingMall.h"
#include "Strategy.h"
#include "State.h"
#include "TouristCenter.h"
#include "VisitorClasses.h"
#include "TicketBuyer.h"
#include "TestPlan.h"
#include "CIceZoo.h"
#include "CIcecream.h"
#include "Snowman.h"
#include "MediatorModel.h"
#include "TicketChecking.h"
#include "IceSkating.h"
#include "Clothesshop.h"
#include "IceExhibit.h"
#include "Hotel.h"

/*��ָ�������
* �̳��ں�ָ�����������ָ�������������ĸ��ڵ㣬������ռ������벢�·�
*/
class MainReceiver : public MacroCommandReceiver {
private:
	//�Ƿ���������µ�����
	bool toContinue = true;
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ""
	* @return void
	*/
	MainReceiver() : MacroCommandReceiver("") {}

protected:
	/*ִ��ָ��
	* ���ظ���ִ��ָ��Ĵ��麯�����������������ִ����Ӧ����
	* @param cmd �û������ָ������
	* @return bool ָ���ʽ�Ƿ���ȷ
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);				//��Ƭ��ǰָ��
		removeBlank(cmd);									//�Ƴ�����ո�
		if (subCmd == "quit") {								//ƥ����ָ��
			std::cout << "�������" << std::endl;
			toContinue = false;								//����������ѭ��
			return true;									//���أ�ָ���ʽ��ȷ
		}
		if (subCmd == "help") {
			std::cout << "����ָ���б�Ϊ��" << std::endl;
			printHelp(0);
			return true;
		}
		return false;
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	MainReceiver(const MainReceiver&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	MainReceiver& operator=(const MainReceiver&) = delete;
	/*��ȡ������������
	* ��ȡȫ��Ψһ����������ʵ�������ã�����ʵ�ֵ�����
	* @return MainReceiver& ��������������
	*/
	static MainReceiver& getInstance() {
		static MainReceiver reciver;
		return reciver;
	}
	/*����
	* ���н����û������ָ�����
	* @return void
	*/
	void run() {
		std::string cmd;
		std::cout << "����ָ�� help �鿴��ǰ����ָ��" << std::endl;
		while (toContinue) {
			std::cout << ">";
			while (1) {
				std::getline(std::cin, cmd);
				if (cmd.size())
					break;
			}
			handleCommand(cmd);
		}
	}
	/*��ӡ����ָ��
	* ���ظ����麯��������level��ӡ��Ӧ��ʽ��ָ��Լ�������ָ��
	* @param level ��ǰReciver��Reciver���еĲ㼶
	* @return void
	*/
	virtual void printHelp(int level) {
		__super::printHelp(level);				//���ø����Ĭ��printHelp�������ݹ������ǰ���ӽ�������tag
		level++;								//����ָ����ʾ����һ��
		std::string head(level * 3, '-');
		std::cout << head + "quit" << std::endl;	//�����ָ��
		std::cout << head + "help" << std::endl;	//�����ָ��
	}
};


/************************************************************************
*							�ƻ�������ģ��								*
*************************************************************************/

/*�ƻ�������
* �̳���ָ���������������������ƻ�
*/
class PlanManager : public CommandReceiver {
private:
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"plan"
	* @return void
	*/
	PlanManager() : CommandReceiver("plan") {}
	//�ƻ��б�
	std::vector<Plan*> planList;
	/*�����¼ƻ�
	* ���ݴ������Ĺ������ã������µļƻ����������ƻ��б�β
	* @param factory Ŀ��ƻ�����������
	* @return void
	*/
	void createPlan(AbstractPlanFactory& factory) {
		Plan* plan = new Plan();
		plan->description = factory.makeDescription();
		plan->spot = factory.makeSpot();
		plan->path = factory.makePath();
		planList.push_back(plan);
		MainReceiver::getInstance().addReceiver(plan->spot);
	}
	/*��ȡ�ƻ���������
	* ��ȡ��pos+1��ļƻ�������������
	* @param pos �ƻ��ڼƻ��б��е�λ��
	* @return std::string ����
	*/
	std::string getDescription(int pos) {
		if (pos >= planList.size() || pos < 0) {
			return "��δ���ø�λ�õļƻ�";
		}
		return planList[pos]->description->content;
	}
protected:
	/*ִ��ָ��
	* ���ظ���ִ��ָ��Ĵ��麯�����������������ִ����Ӧ����
	* @param cmd �û������ָ������
	* @return bool ָ���ʽ�Ƿ���ȷ
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "create") {
			if (cmd == "testSpot") {
				TestPlanFactory factory;
				createPlan(factory);
				std::cout << "�ɹ�����testSpot��ָ��Ϊtest" << std::endl;
				return true;
			}
			if (cmd == "mountain") {
				MountainPlanFactory factory;
				createPlan(factory);
				std::cout << "�ɹ�����mountain��ָ��Ϊchoose" << std::endl;
				return true;
			}
			if (cmd == "cave") {
				CavePlanFactory factory;
				createPlan(factory);
				std::cout << "�������̽���Ѽ���ƻ���ָ��Ϊcave" << std::endl;
				return true;
			}
			if (cmd == "exhibit") {
				ExhibitPlanFactory factory;
				createPlan(factory);
				std::cout << "�ι۱���չ���Ѽ���ƻ���ָ��Ϊexhibit" << std::endl;
				return true;
			}
			if (cmd == "iceZoo") {
				IceZooFactory factory;
				createPlan(factory);
				std::cout << "��ѩ����԰�Ѽ���ƻ���ָ��ΪiceZoo" << std::endl;
				return true;
			}
			if (cmd == "iceSkating") {
				IceSkatingPlanFactory factory;
				createPlan(factory);
				std::cout << "������Ѽ���ƻ���ָ��Ϊskate" << std::endl;
				return true;
			}
			if (cmd == "exhibit") {
				ExhibitPlanFactory factory;
				createPlan(factory);
				std::cout << "����չ�[�Ѽ���ƻ���ָ��Ϊexhibit" << std::endl;
				return true;
			}
			return false;
		}
		if (subCmd == "getDescription") {
			std::string paramTag1 = sliceCommand(cmd);		//ͨ����Ƭ��ָ���õ�һ�������ı�ǩ
			removeBlank(cmd);								//�Ƴ�����ո�
			if (paramTag1 == "-p") {
				int pos = std::stoi(cmd);
				std::cout << getDescription(pos) << std::endl;
				return true;
			}
			cmd = paramTag1 + " " + cmd;
		}
		return false;
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	PlanManager(const PlanManager&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	PlanManager& operator=(const PlanManager&) = delete;
	/*��ȡ��ǰ������������
	* ��ȡȫ��Ψһ��ǰ��������ʵ�������ã�����ʵ�ֵ�����
	* @return PlanManager& ��ǰ������������
	*/
	static PlanManager& getInstance() {
		static PlanManager reciver;
		return reciver;
	}
	/*��ӡ����ָ��
	* ���ظ����麯��������level��ӡ��Ӧ��ʽ��ָ��Լ�������ָ��
	* @param level ��ǰReciver��Reciver���еĲ㼶
	* @return void
	*/
	virtual void printHelp(int level) {
		__super::printHelp(level);				//���ø����Ĭ��printHelp�������ݹ������ǰ���ӽ�������tag
		level++;								//����ָ����ʾ����һ��
		std::string head(level * 3, '-');
		std::cout << head + "create" << std::endl;								//�����ָ��
		std::cout << head + "---" + "testSpot" << std::endl;					//�����ָ��
		std::cout << head + "---" + "mountain" << std::endl;					//�����ָ��
		std::cout << head + "---" + "cave   (�������)" << std::endl;				//�����ָ��
		std::cout << head + "---" + "iceZoo   (��ѩ����԰)" << std::endl;			//�����ָ��
		std::cout << head + "---" + "iceSkating   (�����)" << std::endl;		//�����ָ��
		std::cout << head + "---" + "exhibit   (����չ��)" << std::endl;			//�����ָ��
		std::cout << head + "getDescription -p:�ƻ����б��е�λ��" << std::endl;	//�����ָ��
	}
	/*��������
	* ���ڷ�ֹ�ڴ�й¶���ݹ��ͷ�planList�еĶ���
	*/
	~PlanManager() {
		for (int i = 0; i < planList.size(); i++)
		{
			if (planList[i] != nullptr) {
				delete planList[i];
			}
		}
	}
};


int main() {
	MainReceiver& mainReciver = MainReceiver::getInstance();	//��ȡ��������������
	mainReciver.addReceiver(&PlanManager::getInstance());	//���Ӽƻ���������������������
	mainReciver.addReceiver(&ShoppingManager::getInstance());
	mainReciver.addReceiver(&Vehicle::getInstance());
	mainReciver.addReceiver(&SnowmanManager::getInstance());
	mainReciver.addReceiver(&MediatorManager::getInstance());
	mainReciver.addReceiver(&DecoratorReceiver::getInstance());
	mainReciver.addReceiver(&Ticket_Buyer::getInstance());
	mainReciver.addReceiver(&CheckingManager::getInstance());
	mainReciver.addReceiver(&HotelManager::getInstance());
	mainReciver.addReceiver(&TouristCenter::getInstance());	//�����ο����ĵ�������������
	mainReciver.run();										//����
}