#pragma once

#include"BaseClasses.h"
#include<string>

/**
 * ��������
 * ����ʵ�����ݴ���Ĺ�����
 */
class Filters : public DPObject {
public:
	/**
	 * ��Ʊ���͹�����
	 * ������Ʊ��ţ����˵õ�����Ʊ���ο�����
	 * @param id ��Ʊ���
	 * @return string ��Ʊ��Ӧ���ο�����
	 */
	std::string Filter_TicketType(std::string id) {
		int status = (int)id[0] - 48;		//����Ʊ����й����ο����͵Ĳ������ַ���תΪ����
		switch (status) {
		case 0:
			return "��ͯƱ";
		case 1:
			return "����Ʊ";
		default:
			return "����";
		}
	}

	/**
	 * ��������Ŀ���ݹ�����
	 * ������Ʊ��ţ����˵õ�����Ʊ��ѡ���������Ŀ�����ݱ��
	 * @param id ��Ʊ���
	 * @return int ��Ʊ��Ӧ��������Ŀ�����ݱ��
	 */
	int Filter_Cave(std::string id) {
		int status = (int)id[1] - 48;		//����Ʊ����й��ڱ����ߵĲ������ַ���תΪ����
		return status;
	}

	/**
	 * ��ɽ��Ŀ���ݹ�����
	 * ������Ʊ��ţ����˵õ�����Ʊ��ѡ���ɽ��Ŀ�����ݱ��
	 * @param id ��Ʊ���
	 * @return int ��Ʊ��Ӧ��ɽ��Ŀ�����ݱ��
	 */
	int Filter_Mountain(std::string id) {
		int status = (int)id[2] - 48;	//����Ʊ����й��ڵ�ɽ�Ĳ������ַ���תΪ����
		return status;
	}

	/**
	 * ����԰�ι���Ŀ���ݹ�����
	 * ������Ʊ��ţ����˵õ�����Ʊ��ѡ����԰�ι���Ŀ�����ݱ��
	 * @param id ��Ʊ���
	 * @return int ��Ʊ��Ӧ����԰�ι���Ŀ�����ݱ��
	 */
	int Filter_Zoo(std::string id) {
		int status = (int)id[3] - 48;	//����Ʊ����й����οͶ���԰�ι۵Ĳ������ַ���תΪ����
		return status;
	}
};

/**
 * �ܵ���
 * ����ʵ������������Ĺܵ����û������ʵ��
 */
class Pipe : public DPObject{
public:
	/**
	 * ��Ʊ�����
	 * �������ɶ�Ӧ���û����棬���ղ������û������룬����������Ա�����Ʊ���ͼ�����
	 * @return void
	 */
	void Check() {
		std::string itemID;										//ʹ�ô�ϵͳ�Ĺ�����Ա��������Ŀ���
		std::string itemName[] = {"������", "��ɽ", "����԰"};	//ʹ�ô�ϵͳ�Ĺ�����Ա��������Ŀ����
		std::string ticketID;									//��������Ʊ���
		std::string d;			//������û�����������ݵ��ַ���
		int id = 0;			//ʹ�ô�ϵͳ�Ĺ�����Ա��������Ŀ���(����)
		Filters *p_filter = new Filters();

		std::cout << "  ������������Ŀ���: ";
		while (1) {
			getline(std::cin, itemID);
			if (itemID.length() == 1 && itemID >= "1" && itemID <= "3") {		//���������Ŀ��źϷ���ӭ������������Ա����һ��
				id = (int)itemID[0] - 49;		//���ַ���תΪ����
				std::cout << "  ��ӭ��, " << itemName[id] << " �Ĺ�����Ա��" << std::endl;
				break;				//��Ŀ��Ż�ȡ�ɹ�������ѭ��
			}
			else 
				std::cout << "  ��Ŀ��Ŵ�������������: ";		//���������Ŀ��Ų��Ϸ������ѭ��
		}

		while (1) {
			std::cout << "  �������ο���Ʊ����λ����(�Կո�ָ�)(��quit�˳�): ";
			std::cin >> ticketID;
			getline(std::cin, d);			//��û�������������
			if (ticketID == "quit") {	//���û������˳�ϵͳ�������Ӧ��ʾ������ѭ��
				std::cout << "�ɹ��˳���Ʊ��ѯ!" << std::endl;
				break;
			}
			if (ticketID.length() == 4) {	//�������ʽ�ϸ��������һ���ж�
				int status;					//��Ŀ���ݵı��
				std::string type;				//��Ʊ�����ߵ��ο�����
				type = p_filter->Filter_TicketType(ticketID);		//��ȡ����ǰ��Ʊ���ο�����

				if (type == "����") {		//����������ͱ�������������Ӧ��ʾ����ת����һ��ѭ��
					std::cout << "  �����������������!" << std::endl;
					continue;
				}
				switch (id+1) {			//����ʹ��ϵͳ�û���Ա��������Ŀ��ŵĲ�ͬ���ò�ͬ�ķ���
				case 1:
					status = p_filter->Filter_Cave(ticketID);		//ʹ�ù������õ���Ʊ����б����ߵĲ���
					Content_Cave(type, status);			//������Ʊ����й��˵õ��Ŀ������������Ӧ��Ϣ
					break;
				case 2:
					status = p_filter->Filter_Mountain(ticketID);	//ʹ�ù������õ���Ʊ����е�ɽ�Ĳ���
					Content_Mountain(type, status);		//������Ʊ����й��˵õ��Ŀ������������Ӧ��Ϣ
					break;
				case 3:
					status = p_filter->Filter_Zoo(ticketID);		//ʹ�ù������õ���Ʊ����ж���԰�ι۵Ĳ���
					Content_Zoo(type, status);			//������Ʊ����й��˵õ��Ŀ������������Ӧ��Ϣ
					break;
				}
				
			}
			else				//�������ʽ���ϸ������ѭ��
				std::cout << "  ��ʽ��������������!" << std::endl;
		}
	}

	/**
	 * ��������Ŀ����˵��
	 * ������������Ŀ�����ݱ�ţ��������������
	 * @param type ӵ����Ʊ���ο�����
	 * @param status ��Ʊ��Ӧ��������Ŀ�����ݱ��
	 * @return void
	 */
	void Content_Cave(std::string type, int status) {
		std::cout << "  ��λ�ο͹�����" << type << ", ";		//������Ա�����ǰ�ο���Ʊ�����Լ�������Ŀ������
		switch (status) {
		case 0:
			std::cout << "��δѡ����Ŀ��" << std::endl;
			break;
		case 1:
			std::cout << "��ѡ���˱���Ŀ�� ������������λ�οͿ�ʼ��������Ŀ�����棡" << std::endl;
			break;
		default:
			std::cout << "������������������룡" << std::endl;
		}
	}

	/**
	 * ��ɽ��Ŀ����˵��
	 * ������ɽ��Ŀ�����ݱ�ţ��������������
	 * @param type ӵ����Ʊ���ο�����
	 * @param status ��Ʊ��Ӧ��ɽ��Ŀ�����ݱ��
	 * @return void
	 */
	void Content_Mountain(std::string type, int status) {
		std::cout << "  ��λ�ο͹�����" << type << ", ";		//������Ա�����ǰ�ο���Ʊ�����Լ�������Ŀ������
		switch (status) {
		case 0:
			std::cout << "��δѡ����Ŀ��" << std::endl;
			break;
		case 1:
			std::cout << "��ѡ���˱���Ŀ, ͬʱѡ���˳����ײͣ� ������������λ�οͿ�ʼ�����ɽ��" << std::endl;
			break;
		case 2:
			std::cout << "��ѡ���˱���Ŀ, ͬʱѡ���˸߼��ײͣ� ������������λ�οͿ�ʼ�����ɽ��" << std::endl;
			break;
		case 3:
			std::cout << "��ѡ���˱���Ŀ, ͬʱѡ����רҵ�ײͣ� ������������λ�οͿ�ʼ���е�ɽ��" << std::endl;
			break;
		default:
			std::cout << "������������������룡" << std::endl;
		}
	}

	/**
	 * ����԰�ι���Ŀ����˵��
	 * ��������԰�ι���Ŀ�����ݱ�ţ��������������
	 * @param type ӵ����Ʊ���ο�����
	 * @param status ��Ʊ��Ӧ����԰�ι���Ŀ�����ݱ��
	 * @return void
	 */
	void Content_Zoo(std::string type, int status) {
		std::cout << "  ��λ�ο͹�����" << type << ", ";		//������Ա�����ǰ�ο���Ʊ�����Լ�������Ŀ������
		switch (status) {
		case 0:
			std::cout << "��δѡ����Ŀ��" << std::endl;
			break;
		case 1:
			std::cout << "��ѡ���˱���Ŀ, ͬʱѡ������ͨ�ιۣ� ������������λ�οͽ��붯��԰��" << std::endl;
			break;
		case 2:
			std::cout << "��ѡ���˱���Ŀ, ͬʱѡ���˻����ι�+����Ʒ���ͣ� ������������λ�οͽ��붯��԰��" << std::endl;
			break;
		case 3:
			std::cout << "��ѡ���˱���Ŀ, ͬʱѡ���˻����ι�+��������Ͳͣ� ������������λ�οͽ��붯��԰��" << std::endl;
			break;
		default:
			std::cout << "������������������룡" << std::endl;
		}
	}

};

//��Ʊ��Ʊ -- �ܵ�-������ģʽ
class CheckingManager : public CommandReceiver {
private:
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"ticketChecking"
	* @return void
	*/
	CheckingManager() : CommandReceiver("ticketChecking") {}

protected:
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "visitor") {
			std::cout << "������Ŀ���������Ա��ѯ��" << std::endl;
			return true;
		}
		else if (subCmd == "worker") {
			Pipe *worker = new Pipe();
			worker->Check();
			return true;
		}
		else
			return false;
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	CheckingManager(const CheckingManager&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	CheckingManager& operator=(const CheckingManager&) = delete;
	/*��ȡ��ǰ������������
	* ��ȡȫ��Ψһ��ǰ��������ʵ�������ã�����ʵ�ֵ�����
	* @return CheckingManager& ��ǰ������������
	*/
	static CheckingManager& getInstance() {
		static CheckingManager reciver;
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
		std::cout << head + "visitor" << std::endl;			//�����ָ��		
		std::cout << head + "worker" << std::endl;
	}
};