#pragma once
#include "BaseClasses.h"
#include "Booking.h"
#include "caculate.h"
/************************************************************************************
*																					*
*							BookingԤ��Ʊģ��        								*
*																					*
*************************************************************************************/

class Booking :public DPObject
{
public:
	Ticket_officer* ticket_officer;
	ConcreteCommand* concreteCommand;
	Description_Booking* description;
	CommandReceiver* spot;

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
	Description_Booking* makeDescription(std::string cmd) {
		Description_Booking* des = new Description_Booking();
		if (cmd == "man") 
		{
			des->content = "��ʿƱ";
			des->identifier = 1000;
		}
		if (cmd == "woman")
		{
			des->content = "ŮʿƱ";
			des->identifier = 500;
		}
		if (cmd == "child")
		{
			des->content = "��ͯƱ";
			des->identifier = 100;
		}
		return des;
	}

	~Booking()
	{
		if (ticket_officer != nullptr) { delete ticket_officer; }
		if (concreteCommand != nullptr) { delete concreteCommand; }
		if (description != nullptr) { delete description; }
	}
};

class Ticket_Buyer :public CommandReceiver
{
private:
	Ticket_Buyer() :CommandReceiver("booking") {}

	std::vector<Booking*> bookingList;

	void createBooking(std::string cmd)
	{
		Booking* book = new Booking();
		book->concreteCommand = book->make_ConcreteCommand();
		book->ticket_officer = book->make_Ticket_officer();
		book->description = book->makeDescription(cmd);
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
				child_play(bookingList[pos]->description);
				woman_play(bookingList[pos]->description);
				man_play(bookingList[pos]->description);
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
	void child_play(Description_Booking* des)
	{
		if (des->identifier > 0 && des->identifier <= 300) std::cout << "��ͯƱ��һ����ʩ����" << std::endl;
	}
	void woman_play(Description_Booking* des)
	{
		if (des->identifier > 300 && des->identifier <= 800) std::cout << "ŮʿƱ�ڶ�����ʩ����" << std::endl;
	}
	void man_play(Description_Booking* des)
	{
		if (des->identifier > 800) std::cout << "��ʿƱ��������ʩ����" << std::endl;
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
		std::cout << head + "getDescription -p:Ʊ���б��е�λ��" << std::endl;//�����ָ��
		std::cout << head + "sum Ʊ�����" << std::endl;//�����ָ��
		std::cout << head + "getChain ��������� -p:Ʊ���б��е�λ��" << std::endl;//�����ָ��
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






