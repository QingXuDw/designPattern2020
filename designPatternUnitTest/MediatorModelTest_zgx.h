#pragma once
#include "pch.h"
#include "../designPattern/ShoppingMall.h"
#include"../designPattern/MediatorModel.h"
#include <vector>

//用namespace包裹以防止命名冲突
namespace zgx {
	/*class ColleagueTest : public RedirectIO {
	protected:
		//用于维护各子类对象的vector
		vector<Colleague*> Colleagues;
		//在Colleagues中为每一个子类生成一个对象
		void SetUp() override {
			RedirectIO::SetUp();
			Colleague* p_colleague;
			Mediator* m_mediator;
			p_colleague = new ConcreteColleague_0(m_mediator);
			Colleagues.push_back(p_colleague);
			p_colleague = new ConcreteColleague_1(m_mediator);
			Colleagues.push_back(p_colleague);
		}
		//清理Colleagues中的全部子类对象
		void TearDown() override {
			RedirectIO::TearDown();
			for (std::vector<Colleague*>::iterator i = Colleagues.begin();
				i != Colleagues.end();
				i++)
			{
				S_DELETE((*i));
			}
		}
	};

	TEST_F(ColleagueTest, send) {
		for (std::vector<Colleague*>::iterator i = Colleagues.begin();
			i != Colleagues.end();
			i++)
		{
			EXPECT_NO_THROW((*i)->send(""));
			EXPECT_NO_THROW((*i)->send("10086"));
		}
	}

	TEST_F(ColleagueTest, notify) {
		for (std::vector<Colleague*>::iterator i = Colleagues.begin();
			i != Colleagues.end();
			i++)
		{
			EXPECT_NO_THROW((*i)->notify(""));
			EXPECT_NO_THROW((*i)->notify("10086"));
		}
	}
	*/
	class MediatorManagerTest : public RedirectIO {
	protected:
		MediatorManager* p_mediatorManager;
		void SetUp() override {
			RedirectIO::SetUp();
			p_mediatorManager = &(MediatorManager::getInstance());
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
		}
	};
	TEST_F(MediatorManagerTest, HandleCommand) {
		EXPECT_NO_THROW(p_mediatorManager->handleCommand(""));
		EXPECT_NO_THROW(p_mediatorManager->handleCommand("mediator"));
		EXPECT_NO_THROW(p_mediatorManager->handleCommand("mediator make"));
		EXPECT_NO_THROW(p_mediatorManager->handleCommand("mediator sendmessage"));
		EXPECT_NO_THROW(p_mediatorManager->handleCommand("JLNB!!!"));
	}


}

