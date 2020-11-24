#pragma once
#include "pch.h"
#include "../designPattern/IceSkating.h"
#include <vector>
#include<string>

//用namespace包裹以防止命名冲突
namespace xjn {
	//Skater测试1 (√)
	//抽象类无法测

	//SelfSkater测试 (√)
	class SelfSkaterTest : public RedirectIO {
	public:
		SelfSkater* p_selfSkater;
		void SetUp() override {
			RedirectIO::SetUp();
			p_selfSkater = &(SelfSkater::getInstance());
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
		}
	};
	DP_F(SelfSkaterTest, move) {
		EXPECT_NO_THROW(p_selfSkater->move(0));
		EXPECT_NO_THROW(p_selfSkater->move(1));
		EXPECT_NO_THROW(p_selfSkater->move(2));
		EXPECT_NO_THROW(p_selfSkater->move(3));
		EXPECT_NO_THROW(p_selfSkater->move(6));
	}
	DP_F(SelfSkaterTest, isNull) {
		EXPECT_FALSE(p_selfSkater->isNull());
	}
	DP_F(SelfSkaterTest, isName) {
		EXPECT_FALSE(p_selfSkater->isName("JLNB!"));
	}

	//OtherSkater测试 (√)
	class OtherSkaterTest : public RedirectIO {
	public:
		OtherSkater* p_otherSkater;
		void SetUp() override {
			RedirectIO::SetUp();
			std::string str = "Julao";
			p_otherSkater = new OtherSkater(str);
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_otherSkater);
		}
	};
	DP_F(OtherSkaterTest, move) {
		EXPECT_NO_THROW(p_otherSkater->move(1));
	}
	DP_F(OtherSkaterTest, isNull) {
		EXPECT_FALSE(p_otherSkater->isNull());
	}
	DP_F(OtherSkaterTest, isName) {
		EXPECT_TRUE(p_otherSkater->isName("Julao"));
		EXPECT_FALSE(p_otherSkater->isName("Xinge"));
	}
	DP_F(OtherSkaterTest, getState) {
		p_otherSkater->getState();
		std::string result1;
		std::string result2;
		getline(sout, result1);
		getline(sout, result2);
		EXPECT_NO_THROW(p_otherSkater->getState());
		EXPECT_STREQ(result2.c_str(), "（向下为X正轴方向，向右为y正轴方向）");
	}

	//NullSkater测试 (√)
	class NullSkaterTest : public RedirectIO {
	public:
		NullSkater* p_nullSkater;
		void SetUp() override {
			RedirectIO::SetUp();
			p_nullSkater = new NullSkater();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_nullSkater);
		}
	};
	DP_F(NullSkaterTest, isNull) {
		//EXPECT_NO_THROW(p_nullSkater->isNull());
		EXPECT_TRUE(p_nullSkater->isNull());
	}
	DP_F(NullSkaterTest, isName) {
		EXPECT_TRUE(p_nullSkater->isName("Julao"));
	}
	DP_F(NullSkaterTest, move) {
		EXPECT_NO_THROW(p_nullSkater->move(1));
	}
	DP_F(NullSkaterTest, getState) {
		p_nullSkater->getState();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "场内不存在叫这个名字的游客！");
	}

	//EventBus测试 (?)
	class EventBusTest : public RedirectIO {
	public:
		EventBus* p_eventBus;
		void SetUp() override {
			RedirectIO::SetUp();
			p_eventBus = &(EventBus::getInstance());
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
		}
	};
	DP_F(EventBusTest, getCnt) {
		EXPECT_NO_THROW(p_eventBus->getCnt());
	}
	DP_F(EventBusTest, printFeild) {
		p_eventBus->printFeild();
		std::string field1;
		std::string field2;
		getline(sout, field1);
		getline(sout, field2);
		EXPECT_STREQ(field1.c_str(), "##########################################################################################");
		EXPECT_STREQ(field2.c_str(), "#                                                                                        #");
	}
	DP_F(EventBusTest, notifyAll) {
		EXPECT_NO_THROW(p_eventBus->notifyAll());
	}
	DP_F(EventBusTest, update) {
		EXPECT_NO_THROW(p_eventBus->update());
	}
	DP_F(EventBusTest, getMovableDir) {
		EXPECT_NO_THROW(p_eventBus->getMovableDir(1, 1));
	}
	//这边需要持续键入，不知道怎么测
	DP_F(EventBusTest, play) {
		/*
		sin << "wasd";
		EXPECT_NO_THROW(p_eventBus->play());
		*/
	}
	DP_F(EventBusTest, searchFriend) {
		EXPECT_NO_THROW(p_eventBus->searchFriend("昕哥"));
		std::string result1;
		std::string result2;
		getline(sout, result1);
		getline(sout, result2);
		EXPECT_STREQ(result2.c_str(), "（向下为X正轴方向，向右为y正轴方向）");
	}
	DP_F(EventBusTest, addSkater) {
		p_eventBus->addSkater("Julao");
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "邀请成功！");
	}

	//SkaterFactory测试 (√ ..)
	class SkaterFactoryTest : public RedirectIO {
	public:
		SkaterFactory* p_skaterFactory;
		void SetUp() override {
			RedirectIO::SetUp();
			p_skaterFactory = &(SkaterFactory::getInstance());
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
		}
	};
	DP_F(SkaterFactoryTest, run) {
		sin << "7\n 1";
		EXPECT_NO_THROW(p_skaterFactory->run());
		sin.str("");
		sin << "2\n 1";
		EXPECT_NO_THROW(p_skaterFactory->run());
	}

	//IceSkatingReceiver测试 (√)
	class IceSkatingReceiverTest : public RedirectIO {
	public:
		IceSkatingReceiver* p_iceSkatingReceiver;
		void SetUp() override {
			RedirectIO::SetUp();
			p_iceSkatingReceiver = &(IceSkatingReceiver::getInstance());
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
		}
	};
	TEST_F(IceSkatingReceiverTest, handleCommand) {
		EXPECT_NO_THROW(p_iceSkatingReceiver->handleCommand(""));
		EXPECT_NO_THROW(p_iceSkatingReceiver->handleCommand("skate"));
		EXPECT_NO_THROW(p_iceSkatingReceiver->handleCommand("skate go"));
		EXPECT_NO_THROW(p_iceSkatingReceiver->handleCommand("skate go xgnb"));
		EXPECT_NO_THROW(p_iceSkatingReceiver->handleCommand("JLNB!!!"));
	}

	//IceSkatingPlanFactory测试 (√)
	class IceSkatingPlanFactoryTest : public RedirectIO {
	public:
		IceSkatingPlanFactory* p_iceSkatingPlanFactory;
		void SetUp() override {
			RedirectIO::SetUp();
			p_iceSkatingPlanFactory = new IceSkatingPlanFactory();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_iceSkatingPlanFactory);
		}
	};
	TEST_F(IceSkatingPlanFactoryTest, handleCommand) {
		EXPECT_NO_THROW(p_iceSkatingPlanFactory->makeDescription());
		EXPECT_NO_THROW(p_iceSkatingPlanFactory->makePath());
		EXPECT_NO_THROW(p_iceSkatingPlanFactory->makeSpot());
	}
}
