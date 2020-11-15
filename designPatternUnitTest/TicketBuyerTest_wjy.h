#pragma once
#include "pch.h"
#include "../designPattern/TicketBuyer.h"

namespace wjy {
	class BookingTest : public RedirectIO {
	protected:
		Booking* p_booking;
		void SetUp() override {
			RedirectIO::SetUp();
			p_booking = new Booking();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_booking);
		}
	};

	TEST_F(BookingTest, MakeTicketOfficer) {
		std::string name = p_booking->make_Ticket_officer()->name;
		EXPECT_STREQ(name.c_str(), "游乐园售票处");
	}

	TEST_F(BookingTest, MakeConcreteCommand) {
		ConcreteCommand* temp = p_booking->make_ConcreteCommand();
		temp->Execute();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "Ticket_officer->Action");
	}

	TEST_F(BookingTest, MakeDescription) {
		Description_Booking* des;
		des = p_booking->makeDescription("man");
		EXPECT_STREQ(des->content.c_str(), "男士票");
		EXPECT_EQ(des->identifier, 1000);
		des = p_booking->makeDescription("woman");
		EXPECT_STREQ(des->content.c_str(), "女士票");
		EXPECT_EQ(des->identifier, 500);
		des = p_booking->makeDescription("child");
		EXPECT_STREQ(des->content.c_str(), "儿童票");
		EXPECT_EQ(des->identifier, 100);
		std::string str;
		int integer;
		des = p_booking->makeDescription("");
		EXPECT_TRUE(des->content == str);
		EXPECT_NO_THROW(integer = des->identifier);
	}

	class TicketBuyerTest : public RedirectIO {
	protected:
		Ticket_Buyer* p_ticketBuyer;
		void SetUp() override {
			RedirectIO::SetUp();
			p_ticketBuyer = &(Ticket_Buyer::getInstance());
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
		static void s_delete(void* ptr) {
			if ((ptr) != nullptr) { delete (ptr); (ptr) = nullptr; }
		}
	};

	TEST_F(TicketBuyerTest, HandleCommand) {
		std::string result;
		EXPECT_NO_THROW(p_ticketBuyer->handleCommand(""));
		EXPECT_NO_THROW(p_ticketBuyer->handleCommand("create"));
		EXPECT_NO_THROW(p_ticketBuyer->handleCommand("create man"));
		EXPECT_NO_THROW(p_ticketBuyer->handleCommand("getDescription"));
		EXPECT_NO_THROW(p_ticketBuyer->handleCommand("getDescription -p"));
		EXPECT_NO_THROW(p_ticketBuyer->handleCommand("getDescription -p 0"));
		EXPECT_NO_THROW(p_ticketBuyer->handleCommand("create woman"));
		EXPECT_NO_THROW(p_ticketBuyer->handleCommand("create child"));

		sout.str("");//清空输出流
		EXPECT_NO_THROW(p_ticketBuyer->handleCommand("sum"));
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "预定的票总价为60");

		EXPECT_NO_THROW(p_ticketBuyer->handleCommand("getChain"));
		EXPECT_NO_THROW(p_ticketBuyer->handleCommand("getChain -p"));
		sout.str("");//清空输出流
		EXPECT_NO_THROW(p_ticketBuyer->handleCommand("getChain -p 0"));
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "男士票在三级设施游玩");

	}

	TEST_F(TicketBuyerTest, PrintHelp) {
		EXPECT_NO_THROW(p_ticketBuyer->printHelp(0));
	}
}


