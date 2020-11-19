#pragma once
#include "pch.h"
#include "../designPattern/VisitorClasses.h"

namespace zyb
{
	class GhostCaveReceiverTest :public RedirectIO
	{
		protected:
		GhostCaveReceiver * p_CGRT;
		void SetUp() override 
		{
			RedirectIO::SetUp();
			p_CGRT = &(GhostCaveReceiver::getInstance());
		}
		void TearDown() override 
		{
			RedirectIO::TearDown();
		}
		static void s_delete(void* ptr)
		{
			if ((ptr) != nullptr) { delete (ptr); (ptr) = nullptr; }
		}
	};
	TEST_F(GhostCaveReceiverTest, HandleCommand)
	{
		EXPECT_NO_THROW(p_CGRT->handleCommand(""));
		EXPECT_NO_THROW(p_CGRT->handleCommand("cave"));
		EXPECT_NO_THROW(p_CGRT->handleCommand("cave go"));
		EXPECT_NO_THROW(p_CGRT->handleCommand("!#$@"));
		
	}


	class CavePlanFactoryTest :public RedirectIO

	{
	public:
		CavePlanFactory * p_CGFT;
		void SetUp() override
		{
			RedirectIO::SetUp();
			p_CGFT = new CavePlanFactory();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_CGFT);
		}
	};

	TEST_F(CavePlanFactoryTest, CavePlanFactoryMakepathTest)
	{
		EXPECT_NO_THROW(p_CGFT->makePath());
		EXPECT_NO_THROW(p_CGFT->makeDescription());
		EXPECT_NO_THROW(p_CGFT->makeSpot());

	}

	class  ExhibitReceiverTest :public RedirectIO
	{
		public:
			ExhibitReceiver* p_ER;
		void SetUp() override
		{
			RedirectIO::SetUp();
			p_ER = &(ExhibitReceiver::getInstance());
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
		static void s_delete(void* ptr) {
			if ((ptr) != nullptr) { delete (ptr); (ptr) = nullptr; }
		}

	};

	TEST_F(ExhibitReceiverTest, ExhibitReceiverHandleTest)
	{
		EXPECT_NO_THROW(p_ER->handleCommand(""));
		EXPECT_NO_THROW(p_ER->handleCommand("exhibit"));
		EXPECT_NO_THROW(p_ER->handleCommand("exhibit go"));
		EXPECT_NO_THROW(p_ER->handleCommand("exhibit    go"));
		EXPECT_NO_THROW(p_ER->handleCommand("@!#$"));
			sout.str("");//清空输出流

	}


	class ExhibitionPlanFactoryTest :public RedirectIO

	{
	public:
		ExhibitPlanFactory * p_CGFT;
		void SetUp() override
		{
			RedirectIO::SetUp();
			p_CGFT = new  ExhibitPlanFactory ();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_CGFT);
		}
	};

	TEST_F(ExhibitionPlanFactoryTest, CavePlanFactoryMakepathTest)
	{
		EXPECT_NO_THROW(p_CGFT->makePath());
		EXPECT_NO_THROW(p_CGFT->makeDescription());
		EXPECT_NO_THROW(p_CGFT->makeSpot());

	}
	
	class DecoratorReceiverTest :public RedirectIO
	{
		public :
		DecoratorReceiver* p_DR;
		void SetUp() override 
		{
			RedirectIO::SetUp();
			p_DR = &(DecoratorReceiver::getInstance());
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
		static void s_delete(void* ptr) {
			if ((ptr) != nullptr) { delete (ptr); (ptr) = nullptr; }
		}
	};

	TEST_F(DecoratorReceiverTest, HandleCommand)
	{
		//EXPECT_NO_THROW(p_DR->handleCommand(""));
		EXPECT_NO_THROW(p_DR->handleCommand("decorate"));
		EXPECT_NO_THROW(p_DR->handleCommand("decorate zds"));
		EXPECT_NO_THROW(p_DR->handleCommand("!#$@"));
		sout.str("");//清空输出流
	}

	class ConcreteVisitorTest :public RedirectIO
	{
		public:
			ConcreteVisitor* p_CV;
		void SetUp() override
		{
			RedirectIO::SetUp();
			p_CV = new ConcreteVisitor();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_CV);
		}
	};

	TEST_F(ConcreteVisitorTest, ConcreteVisitorTestfuction)//有system pause 测试没有问题会影响测试体验 注释掉了
	{
		//EXPECT_NO_THROW(p_CV->VisitGhostCave( ));
		//EXPECT_NO_THROW(p_CV->VisitIceSculptureExhibit());
	}

}