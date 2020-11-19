#pragma once

#include"BaseClasses.h"
#include<string>

/**
 * �ܵ���������
 * ����ʵ������������Ĺܵ������ݴ���Ĺ�����
 */
class PipeFilters : DPObject{
public:
	/**
	 * ��Ʊ�����
	 * �������ɶ�Ӧ���û����棬���ղ������û������룬����������Ա�����Ʊ���ͼ�����
	 * @return void
	 */
	void Check() {
		string itemID;										//ʹ�ô�ϵͳ�Ĺ�����Ա��������Ŀ���
		string itemName[] = {"������", "��ɽ", "����԰"};	//ʹ�ô�ϵͳ�Ĺ�����Ա��������Ŀ����
		string ticketID;									//��������Ʊ���
		string d;			//������û�����������ݵ��ַ���
		int id = 0;			//ʹ�ô�ϵͳ�Ĺ�����Ա��������Ŀ���(����)

		cout << "  ������������Ŀ���: ";
		while (1) {
			cin >> itemID;
			if (itemID.length() == 1 && itemID >= "1" && itemID <= "3") {		//���������Ŀ��źϷ���ӭ������������Ա����һ��
				id = (int)itemID[0] - 49;		//���ַ���תΪ����
				cout << "  ��ӭ��, " << itemName[id] << " �Ĺ�����Ա��" << endl;
				break;				//��Ŀ��Ż�ȡ�ɹ�������ѭ��
			}
			else 
				cout << "  ��Ŀ��Ŵ�������������: ";		//���������Ŀ��Ų��Ϸ������ѭ��
		}

		while (1) {
			cout << "  �������ο���Ʊ����λ����(�Կո�ָ�)(��quit�˳�): ";
			cin >> ticketID;
			getline(cin, d);			//��û�������������
			if (ticketID == "quit") {	//���û������˳�ϵͳ�������Ӧ��ʾ������ѭ��
				cout << "�ɹ��˳���Ʊ��ѯ!" << endl;
				break;
			}
			if (ticketID.length() == 4) {	//�������ʽ�ϸ��������һ���ж�
				int status;					//��Ŀ���ݵı��
				string type;				//��Ʊ�����ߵ��ο�����
				type = Filter_TicketType(ticketID);		//��ȡ����ǰ��Ʊ���ο�����

				if (type == "����") {		//����������ͱ�������������Ӧ��ʾ����ת����һ��ѭ��
					cout << "  �����������������!" << endl;
					continue;
				}
				switch (id+1) {			//����ʹ��ϵͳ�û���Ա��������Ŀ��ŵĲ�ͬ���ò�ͬ�ķ���
				case 1:
					status = Filter_Cave(ticketID);		//ʹ�ù������õ���Ʊ����б����ߵĲ���
					Content_Cave(type, status);			//������Ʊ����й��˵õ��Ŀ������������Ӧ��Ϣ
					break;
				case 2:
					status = Filter_Mountain(ticketID);	//ʹ�ù������õ���Ʊ����е�ɽ�Ĳ���
					Content_Mountain(type, status);		//������Ʊ����й��˵õ��Ŀ������������Ӧ��Ϣ
					break;
				case 3:
					status = Filter_Zoo(ticketID);		//ʹ�ù������õ���Ʊ����ж���԰�ι۵Ĳ���
					Content_Zoo(type, status);			//������Ʊ����й��˵õ��Ŀ������������Ӧ��Ϣ
					break;
				}
				

			}
			else				//�������ʽ���ϸ������ѭ��
				cout << "  ��ʽ��������������!" << endl;
		}
	}

	/**
	 * ��Ʊ���͹�����
	 * ������Ʊ��ţ����˵õ�����Ʊ���ο�����
	 * @param id ��Ʊ���
	 * @return string ��Ʊ��Ӧ���ο�����
	 */
	string Filter_TicketType(string id) {
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
	int Filter_Cave(string id) {
		int status = (int)id[1]-48;		//����Ʊ����й��ڱ����ߵĲ������ַ���תΪ����
		return status;	
	}

	/**
	 * ��ɽ��Ŀ���ݹ�����
	 * ������Ʊ��ţ����˵õ�����Ʊ��ѡ���ɽ��Ŀ�����ݱ��
	 * @param id ��Ʊ���
	 * @return int ��Ʊ��Ӧ��ɽ��Ŀ�����ݱ��
	 */
	int Filter_Mountain(string id) {
		int status = (int)id[2] - 48;	//����Ʊ����й��ڵ�ɽ�Ĳ������ַ���תΪ����
		return status;
	}

	/**
	 * ����԰�ι���Ŀ���ݹ�����
	 * ������Ʊ��ţ����˵õ�����Ʊ��ѡ����԰�ι���Ŀ�����ݱ��
	 * @param id ��Ʊ���
	 * @return int ��Ʊ��Ӧ����԰�ι���Ŀ�����ݱ��
	 */
	int Filter_Zoo(string id) {
		int status = (int)id[3] - 48;	//����Ʊ����й����οͶ���԰�ι۵Ĳ������ַ���תΪ����
		return status;
	}

	/**
	 * ��������Ŀ����˵��
	 * ������������Ŀ�����ݱ�ţ��������������
	 * @param type ӵ����Ʊ���ο�����
	 * @param status ��Ʊ��Ӧ��������Ŀ�����ݱ��
	 * @return void
	 */
	void Content_Cave(string type, int status) {
		cout << "  ��λ�ο͹�����" << type << ", ";		//������Ա�����ǰ�ο���Ʊ�����Լ�������Ŀ������
		switch (status) {
		case 0:
			cout << "��δѡ����Ŀ��" << endl;
			break;
		case 1:
			cout << "��ѡ���˱���Ŀ�� ������������λ�οͿ�ʼ��������Ŀ�����棡" << endl;
			break;
		default:
			cout << "������������������룡" << endl;
		}
	}

	/**
	 * ��ɽ��Ŀ����˵��
	 * ������ɽ��Ŀ�����ݱ�ţ��������������
	 * @param type ӵ����Ʊ���ο�����
	 * @param status ��Ʊ��Ӧ��ɽ��Ŀ�����ݱ��
	 * @return void
	 */
	void Content_Mountain(string type, int status) {
		cout << "  ��λ�ο͹�����" << type << ", ";		//������Ա�����ǰ�ο���Ʊ�����Լ�������Ŀ������
		switch (status) {
		case 0:
			cout << "��δѡ����Ŀ��" << endl;
			break;
		case 1:
			cout << "��ѡ���˱���Ŀ, ͬʱѡ���˳����ײͣ� ������������λ�οͿ�ʼ�����ɽ��" << endl;
			break;
		case 2:
			cout << "��ѡ���˱���Ŀ, ͬʱѡ���˸߼��ײͣ� ������������λ�οͿ�ʼ�����ɽ��" << endl;
			break;
		case 3:
			cout << "��ѡ���˱���Ŀ, ͬʱѡ����רҵ�ײͣ� ������������λ�οͿ�ʼ���е�ɽ��" << endl;
			break;
		default:
			cout << "������������������룡" << endl;
		}
	}

	/**
	 * ����԰�ι���Ŀ����˵��
	 * ��������԰�ι���Ŀ�����ݱ�ţ��������������
	 * @param type ӵ����Ʊ���ο�����
	 * @param status ��Ʊ��Ӧ����԰�ι���Ŀ�����ݱ��
	 * @return void
	 */
	void Content_Zoo(string type, int status) {
		cout << "  ��λ�ο͹�����" << type << ", ";		//������Ա�����ǰ�ο���Ʊ�����Լ�������Ŀ������
		switch (status) {
		case 0:
			cout << "��δѡ����Ŀ��" << endl;
			break;
		case 1:
			cout << "��ѡ���˱���Ŀ, ͬʱѡ������ͨ�ιۣ� ������������λ�οͽ��붯��԰��" << endl;
			break;
		case 2:
			cout << "��ѡ���˱���Ŀ, ͬʱѡ���˻����ι�+����Ʒ���ͣ� ������������λ�οͽ��붯��԰��" << endl;
			break;
		case 3:
			cout << "��ѡ���˱���Ŀ, ͬʱѡ���˻����ι�+��������Ͳͣ� ������������λ�οͽ��붯��԰��" << endl;
			break;
		default:
			cout << "������������������룡" << endl;
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
			cout << "������Ŀ���������Ա��ѯ��" << endl;
			return true;
		}
		else if (subCmd == "worker") {
			PipeFilters *worker = new PipeFilters();
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