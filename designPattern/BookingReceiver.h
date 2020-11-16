#pragma once
#include "BaseClasses.h"
#include "Booking.h"
#include "caculate.h"
/************************************************************************************
*																					*
*							BookingԤ��Ʊģ��        								*
*																					*
*************************************************************************************/
class Ticket_Buyer :public CommandReciver
{
private:
	Ticket_Buyer() :CommandReciver("booking") {}

	std::vector<Booking*> bookingList;

	void createBooking(std::string cmd)
	{
		Booking* book = new Booking();
		book->concreteCommand = book->make_ConcreteCommand();
		book->ticket_officer = book->make_Ticket_officer();
		book->description = book->makeDescription(cmd);
		book->spot = book->makeSpot();
		bookingList.push_back(book);
	}
	std::string getDescription(int pos) {
		if (pos >= bookingList.size() || pos < 0) {
			return "��δ���ø�λ�õ�Ԥ��";
		}
		return bookingList[pos]->description->content;
	}
protected:
	bool executeCommand(std::string cmd)
	{
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "create") {
			if (cmd == "man") {
				createBooking(cmd);
				std::cout << "�ɹ�Ԥ����ʿƱ" << std::endl;
				return true;
			}
			else if (cmd == "woman") {
				createBooking(cmd);
				std::cout << "�ɹ�Ԥ��ŮʿƱ" << std::endl;
				return true;
			}
			else if (cmd == "child") {
				createBooking(cmd);
				std::cout << "�ɹ�Ԥ����ͯƱ" << std::endl;
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
		if (subCmd == "getChain") {
			std::string paramTag1 = sliceCommand(cmd);		//����������ʵ��
			removeBlank(cmd);
			if (paramTag1 == "-p") {
				int pos = std::stoi(cmd);
				if (bookingList[pos]->description->content == "��ͯƱ") std::cout << "��ͯƱ��һ����ʩ����" << std::endl;
				if (bookingList[pos]->description->content == "ŮʿƱ") std::cout << "ŮʿƱ�ڶ�����ʩ����" << std::endl;
				if (bookingList[pos]->description->content == "��ʿƱ") std::cout << "��ʿƱ��������ʩ����" << std::endl;
				return true;
			}
			cmd = paramTag1 + " " + cmd;
		}
		if (subCmd == "sum")
		{
			int sum_ticket = 0;
			for (int i = 0; i < bookingList.size(); i++)
			{
				if (bookingList[i]->description->content == "��ʿƱ") sum_ticket += 30;
				if (bookingList[i]->description->content == "ŮʿƱ") sum_ticket += 20;
				if (bookingList[i]->description->content == "��ͯƱ") sum_ticket += 10;
			}
			std::cout << "Ԥ����Ʊ�ܼ�Ϊ" << sum_ticket << std::endl;
			return true;
		}
		return false;
	}
public:
	Ticket_Buyer(const Ticket_Buyer&) = delete;
	Ticket_Buyer& operator=(const Ticket_Buyer&) = delete;

	static Ticket_Buyer& getInstance()
	{
		static Ticket_Buyer reciver;
		return reciver;
	}
	virtual void printHelp(int level) {
		__super::printHelp(level);				//���ø����Ĭ��printHelp�������ݹ������ǰ���ӽ�������tag
		level++;								//����ָ����ʾ����һ��
		std::string head(level * 3, '-');
		std::cout << head + "create" << std::endl;								//�����ָ��
		std::cout << head + "---" + "man" << std::endl;					//�����ָ��
		std::cout << head + "---" + "woman" << std::endl;					//�����ָ��
		std::cout << head + "---" + "child" << std::endl;					//�����ָ��
		std::cout << head + "getDescription -p:Ԥ�����б��е�λ��" << std::endl;//�����ָ��
		std::cout << head + "sum Ʊ�����" << std::endl;//�����ָ��
		std::cout << head + "getChain ���������" << std::endl;//�����ָ��
	}

	~Ticket_Buyer()
	{
		for (int i = 0; i < bookingList.size(); i++)
		{
			if (bookingList[i] != nullptr) {
				delete bookingList[i];
			}
		}
	}
};

class Booking :public DPObject
{
public:
	Ticket_officer* ticket_officer;
	ConcreteCommand* concreteCommand;
	Description* description;
	CommandReciver* spot;

	Ticket_officer* make_Ticket_officer()
	{
		Ticket_officer* ticket_officer = new Ticket_officer("����԰��Ʊ��");
		return ticket_officer;
	}
	ConcreteCommand* make_ConcreteCommand()
	{
		ConcreteCommand* concreteCommand = new ConcreteCommand(ticket_officer);
		return concreteCommand;
	}
	Description* makeDescription(std::string cmd) {
		Description* des = new Description();
		if (cmd == "man") des->content = "��ʿƱ";
		if (cmd == "woman") des->content = "ŮʿƱ";
		if (cmd == "child") des->content = "��ͯƱ";
		return des;
	}
	Spot* makeSpot() {
		Spot& spot = Ticket_Buyer::getInstance();
		return &spot;
	}

	~Booking()
	{
		if (ticket_officer != nullptr) { delete ticket_officer; }
		if (concreteCommand != nullptr) { delete concreteCommand; }
		if (description != nullptr) { delete description; }
	}
};




