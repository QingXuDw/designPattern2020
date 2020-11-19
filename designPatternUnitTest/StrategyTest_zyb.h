#pragma once
#include "pch.h"
#include "../designPattern/Strategy.h"
#include <thread>
#include <Windows.h>
namespace zyb {

	class WalkingTest : public RedirectIO
	{
	protected:
		Walking* p_walker;
		void SetUp() override
		{
			RedirectIO::SetUp();
			p_walker = new Walking();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_walker);
		}
	};

	TEST_F(WalkingTest, WalkingChoose)
	{
		EXPECT_NO_THROW(p_walker->choose());
	}

	class CableCarTest : public RedirectIO
	{
		protected:
		Cable_car* p_cable;
		void SetUp() override
		{
			RedirectIO::SetUp();
			p_cable = new Cable_car();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_cable);
		}
	};

	TEST_F(CableCarTest, CableChoose)
	{
		EXPECT_NO_THROW(p_cable->choose());
	}



	class PuddleTest : public RedirectIO
	{
		protected:
		Puddle_jumper* p_puddle;
		void SetUp() override
		{
			RedirectIO::SetUp();
			p_puddle = new Puddle_jumper();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_puddle);
		}
	};

	TEST_F(PuddleTest, PuddleChoose)
	{
		EXPECT_NO_THROW(p_puddle->choose());
	}


	class TestThread : public CommandReceiver {
	private:
		TestThread() : CommandReceiver("TestThread") {}
	protected:
		bool executeCommand(std::string cmd) {
			if (cmd == "test") {
				char temp;
				std::cin >> temp;
				while (temp == '\0') {
					std::cin >> temp;
				}
				std::cout << temp;
				return true;
			}
		}
	public:
		TestThread(const TestThread&) = delete;
		TestThread& operator=(const TestThread&) = delete;
		static TestThread& getInstance() {
			static TestThread reciver;
			return reciver;
		}
	};

	class ThreadTest : public RedirectIO {
	protected:
		bool pass;
		void SetUp() override {
			RedirectIO::SetUp();
			pass = false;
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
	public:
		void runTest() {
			TestThread::getInstance().handleCommand("test");
			pass = true;
		}
	};
	/*
	TEST_F(ThreadTest, Test)
	{
		char temp = 't';
		char result = '\0';

		int count = 0;
		sin << temp;
		std::thread c_thread(&ThreadTest::runTest, this);
		c_thread.detach();
		while (!pass) 
		{
			count++;
			Sleep(50);
			if (count > 10) 
			{
				EXPECT_TRUE(pass);
				break;
			}
		}

		EXPECT_TRUE(!sout.eof());
		if (!sout.eof()) {
			sout >> result;
			EXPECT_EQ('t', result);
		}
	}*/
	class MountainTest : public RedirectIO
	{
	protected:
		Mountain* p_mountain;
		void SetUp() override
		{
			RedirectIO::SetUp();
			p_mountain = &(Mountain::getInstance());
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

	TEST_F(MountainTest, ExecuteCommandTest) 
	{
		EXPECT_NO_THROW(p_mountain->handleCommand(""));
		EXPECT_NO_THROW(p_mountain->handleCommand("plan"));
		EXPECT_NO_THROW(p_mountain->handleCommand("plan create"));
		EXPECT_NO_THROW(p_mountain->handleCommand("plan create mountain"));
		EXPECT_NO_THROW(p_mountain->handleCommand("mountain"));
		EXPECT_NO_THROW(p_mountain->handleCommand("mountain choose"));
		EXPECT_NO_THROW(p_mountain->handleCommand("mountain choose q"));
		EXPECT_NO_THROW(p_mountain->handleCommand("mountain choose #"));
		EXPECT_NO_THROW(p_mountain->handleCommand("mountain choose 1"));
		sout.str("");//Çå¿ÕÊä³öÁ÷
	}

	class MountainModeTest :public RedirectIO 
	{
		protected:
			MountainMode* p_walking;
			MountainMode* p_cable;
			MountainMode* p_puddle;
			void SetUp() override 
			{
				RedirectIO::SetUp();
				p_walking = new MountainMode(new Walking());
				p_cable= new MountainMode(new Cable_car());
				p_puddle = new MountainMode(new Puddle_jumper());
			}
			void TearDown() override 
			{
				RedirectIO::TearDown();
				S_DELETE(p_walking);
				S_DELETE(p_cable);
				S_DELETE(p_puddle);
			}
	};

	TEST_F(MountainModeTest, caseTest)
	{
		EXPECT_NO_THROW(p_walking->choose());
		EXPECT_NO_THROW(p_cable->choose());
		EXPECT_NO_THROW(p_puddle->choose());
	}

	class MountainPlanFactoryTest :public RedirectIO
	{
		protected:
		MountainPlanFactory* p_mpf;
		void SetUp() override
		{
			RedirectIO::SetUp();
			p_mpf = new MountainPlanFactory();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_mpf);
		}
		
	};

	TEST_F(MountainPlanFactoryTest, MakePathTest)
	{
		std::string type = p_mpf->makePath()->vehicle;
		EXPECT_NO_THROW(p_mpf->makePath());
		EXPECT_STREQ(type.c_str(), "car");
	}

	TEST_F(MountainPlanFactoryTest, DescriptionTest)
	{
		std::string type = p_mpf->makeDescription()->content;
		EXPECT_NO_THROW(p_mpf->makeDescription());
		EXPECT_STREQ(type.c_str(), "this is a test Plan");
	}

	TEST_F(MountainPlanFactoryTest, MakeSpotTest)
	{
		EXPECT_NO_THROW(p_mpf->makeSpot());
	}
	


	
}