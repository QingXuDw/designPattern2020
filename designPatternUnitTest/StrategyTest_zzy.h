#pragma once
#include "pch.h"
#include "../designPattern/Strategy.h"
#include <vector>

namespace zzy {
	using namespace std;

	class MountaineeringTest : public RedirectIO {
	protected:
		//����ά������������vector
		vector<Mountaineering*> mous;
		//��mous��Ϊÿһ����������һ������
		void SetUp() override {
			RedirectIO::SetUp();
			Mountaineering* p_mou;
			p_mou = new Walking();
			mous.push_back(p_mou);
			p_mou = new Cable_car();
			mous.push_back(p_mou);
			p_mou = new Puddle_jumper();
			mous.push_back(p_mou);
		}
		//����mous�е�ȫ���������
		void TearDown() override {
			RedirectIO::TearDown();
			for (vector<Mountaineering*>::iterator i = mous.begin();
				i != mous.end();
				i++)
			{
				S_DELETE((*i));
			}
		}
	};

	TEST_F(MountaineeringTest, Choose) {
		for (std::vector<Mountaineering*>::iterator i = mous.begin();
			i != mous.end();
			i++)
		{
			EXPECT_NO_THROW((*i)->choose());
		}
	}

	class MountainTest : public RedirectIO {
	protected:
		Mountain * p_mountain;
		void SetUp() override {
			RedirectIO::SetUp();
			p_mountain = &(Mountain::getInstance());
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
		static void s_delete(void* ptr) {
			if ((ptr) != nullptr) { delete (ptr); (ptr) = nullptr; }
		}
	};

	TEST_F(MountainTest, HandleCommand) {
		std::string result;
		EXPECT_NO_THROW(p_mountain->handleCommand(""));
		EXPECT_NO_THROW(p_mountain->handleCommand("mountain choose"));
		EXPECT_NO_THROW(p_mountain->handleCommand("1"));
		EXPECT_NO_THROW(p_mountain->handleCommand("2"));
		EXPECT_NO_THROW(p_mountain->handleCommand("3"));
		EXPECT_NO_THROW(p_mountain->handleCommand("4"));

	}

	TEST_F(MountainTest, PrintHelp) {
		//	EXPECT_NO_THROW(p_mountain->printHelp(0));
	}

}
