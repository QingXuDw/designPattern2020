#pragma once
#include "pch.h"
#include "../designPattern/Booking.h"

namespace wjy {
	class TicketOfficerTest : public RedirectIO {
	protected:
		Ticket_officer* p_ticketOfficer;
		void SetUp() override {
			RedirectIO::SetUp();
			p_ticketOfficer = new Ticket_officer("name");
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_ticketOfficer);
		}

	};

	TEST_F(TicketOfficerTest, Constructor) {
		EXPECT_STREQ(p_ticketOfficer->name.c_str(), "name");
	}
	TEST_F(TicketOfficerTest, Action) {
		p_ticketOfficer->Action();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "Ticket_officer->Action");
	}

	class ConcreteCommandTest : public RedirectIO {
	protected:
		Ticket_officer* p_ticketOfficer;
		ConcreteCommand* p_concreteCommand;
		void SetUp() override {
			RedirectIO::SetUp();
			p_ticketOfficer = new Ticket_officer("name");
			p_concreteCommand = new ConcreteCommand(p_ticketOfficer);
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_ticketOfficer);
			S_DELETE(p_concreteCommand);
		}
	};

	TEST_F(ConcreteCommandTest, Execute) {
		p_concreteCommand->Execute();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "Ticket_officer->Action");
	}

	TEST_F(ConcreteCommandTest, Destructor) {
		S_DELETE(p_concreteCommand);
		EXPECT_TRUE(p_concreteCommand == nullptr);
	}

}

