#pragma once

#include"BaseClasses.h"
#include"Consult.h"
#include"Adapter.h"
#include"Notice.h"

//�ο����� �� ��ѯ--���ģʽ / ��Ҷһ�--������ģʽ / ԰��������--�ڰ�ģʽ ��
class TouristCenter: public CommandReceiver{
private:
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"tourist"
	* @return void
	*/
	TouristCenter() : CommandReceiver("tourist") {}
	
	//�����ڰ����������֤���ݵĳ־���
	Blackboard* pBlackboard = new Blackboard();	

protected:
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "consult") {
			Facade* pFacade = new Facade();
			pFacade->start();
			return true;
		}
		else if (subCmd == "currency") {
			Adapter* pAdapter = new Adapter();
			pAdapter->start();
			return true;
		}
		else if (subCmd == "notice") {
			pBlackboard->start();
			return true;
		}
		else
			return false;
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	TouristCenter(const TouristCenter&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	TouristCenter& operator=(const TouristCenter&) = delete;
	/*��ȡ��ǰ������������
	* ��ȡȫ��Ψһ��ǰ��������ʵ�������ã�����ʵ�ֵ�����
	* @return TouristCenter& ��ǰ������������
	*/
	static TouristCenter& getInstance() {
		static TouristCenter reciver;
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
		std::cout << head + "consult" << std::endl;						//�����ָ��
		std::cout << head + "currency" << std::endl;
		std::cout << head + "notice" << std::endl;
	}
};