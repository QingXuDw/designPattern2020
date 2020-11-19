#pragma once
#include "pch.h"
#include"../designPattern/VisitorClasses.h"
#include <thread>

namespace wsq {
	class ConcreteVisitorTest :public RedirectIO {
	protected:
		bool pass;
		ConcreteVisitor* concreteVisitor;
		void SetUp() override {
			RedirectIO::SetUp();
			concreteVisitor = new ConcreteVisitor();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(concreteVisitor);
		}
	public:
		void runTest() {
			ConcreteVisitor::ConcreteVisitor().VisitGhostCave();
			pass = true;
		}
		void runTest1()
		{
			ConcreteVisitor::ConcreteVisitor().VisitIceSculptureExhibit();
			pass = true;
		}
	};

	TEST_F(ConcreteVisitorTest, VisitGhostCave)
	{
		char temp = '1';
		char result = '\0';
		int count = 0;
		sin << temp << temp << temp << temp << temp << temp;
		std::thread c_thread(&ConcreteVisitorTest::runTest,this);
		c_thread.detach();
		while (!pass) {
			count++;
			Sleep(50);
			if (count > 10) {
				EXPECT_TRUE(pass);
				break;
			}
		}
		EXPECT_TRUE(!sout.eof());
		sin.str("");
		/*if (!sout.eof()) {
			sout >> result;
			EXPECT_EQ('t', result);
		}*/
	}
	TEST_F(ConcreteVisitorTest, VisitIceSculptureExhibit)
	{
		char temp = '1';
		int count = 0;
		sin << temp << temp ;
		std::thread c_thread(&ConcreteVisitorTest::runTest1, this);
		c_thread.detach();
		while (!pass) {
			count++;
			Sleep(50);
			if (count > 10) {
				EXPECT_TRUE(pass);
				break;
			}
		}
	}
	class IceSculptureExhibitTest :public RedirectIO
	{
	protected:
		bool pass;
		void SetUp() override {
			RedirectIO::SetUp();
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
	public:
		void runTest()
		{
			ConcreteVisitor* concreteVisitor = new ConcreteVisitor();
			IceSculptureExhibit* iceSculptureExhibit = new IceSculptureExhibit();
			iceSculptureExhibit->accept(concreteVisitor);
			pass = true;
		}
	};
	TEST_F(IceSculptureExhibitTest, accept)
	{
		char temp = '1';
		int count = 0;
		sin << temp << temp << temp;
		std::thread c_thread(&IceSculptureExhibitTest::runTest, this);
		c_thread.detach();
		while (!pass) {
			count++;
			Sleep(50);
			if (count > 10) {
				EXPECT_TRUE(pass);
				break;
			}
		}
	}
	class GhostCaveTest :public RedirectIO
	{
	protected:
		AbstractVisitor* visitor;
		GhostCave* ghostCave;
		void SetUp() override {
			RedirectIO::SetUp();
			visitor = new AbstractVisitor();
			ghostCave = new GhostCave();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(visitor);
			S_DELETE(ghostCave);
		}
	};
	TEST_F(GhostCaveTest, accept)
	{
		EXPECT_NO_THROW(ghostCave->accept(visitor));
	}
	TEST_F(GhostCaveTest, showDecorate)
	{
		EXPECT_NO_THROW(ghostCave->showDecorate());
	}
	class GhostCaveReceiverTest :public RedirectIO
	{
	public:
		bool pass;
		GhostCaveReceiver* ghostCaveReceiver;
		void SetUp() override {
			RedirectIO::SetUp();
			ghostCaveReceiver = &(GhostCaveReceiver::getInstance());
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
		void runTest()
		{
			GhostCaveReceiver::getInstance().handleCommand("go");
		}
	};
	TEST_F(GhostCaveReceiverTest, HandleCommand)
	{
		char temp = '1';
		char result = '\0';
		int count = 0;
		sin << temp;
		std::thread c_thread(&GhostCaveReceiverTest::runTest, this);
		c_thread.detach();
		while (!pass) {
			count++;
			Sleep(50);
			if (count > 10) {
				EXPECT_TRUE(pass);
				break;
			}
		}
	}

	class DecoratorReceiverTest :public RedirectIO
	{
	protected:
		bool pass;
		DecoratorReceiver* decoratorReceiver;
		void SetUp() override {
			RedirectIO::SetUp();
			decoratorReceiver = &(DecoratorReceiver::getInstance());
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
	public:
		void runTest() {
			DecoratorReceiver::getInstance().handleCommand("");
			pass = true;
		}
	};
	TEST_F(DecoratorReceiverTest, HandleCommand)
	{
		char temp = '1';
		int count = 0;
		sin << '4' << '3' << '2' << temp;
		std::thread c_thread(&DecoratorReceiverTest::runTest, this);
		c_thread.detach();
		while (!pass) {
			count++;
			Sleep(50);
			if (count > 10) {
				EXPECT_TRUE(pass);
				break;
			}
		}
	}
}