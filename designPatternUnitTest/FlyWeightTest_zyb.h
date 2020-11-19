#pragma once
#include "pch.h"
#include "../designPattern/FlyWeight.h"
#include <thread>
#include <Windows.h>
namespace zyb {

	class ConcreteFlyWeightTest :public RedirectIO 
	{
	protected:
		ConcreteFlyWeight* p_CFW;
		void SetUp() override 
		{
			RedirectIO::SetUp();
			p_CFW = new ConcreteFlyWeight();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_CFW);
		}
	};

	TEST_F(ConcreteFlyWeightTest, ConcreteFlyWeightTestOptionTest)
	{
		EXPECT_NO_THROW(p_CFW->Operation(0));
	}

	class  FlyweightFactoryTest :public RedirectIO
	{
		
	protected:\
		FlyweightFactory* p_Fac;
			void SetUp() override
			{
				RedirectIO::SetUp();
				p_Fac= new FlyweightFactory();
			}
			void TearDown() override
			{
				RedirectIO::TearDown();
				S_DELETE(p_Fac);
			}

	};

	TEST_F(FlyweightFactoryTest, FlyweightFactoryGetFlyWeightTest)
	{
		p_Fac->GetFlyWeight("xglp");
		EXPECT_EQ(p_Fac->countN(),1);
		p_Fac->GetFlyWeight("xglp");
		EXPECT_EQ(p_Fac->countN(), 1);
		p_Fac->GetFlyWeight("lp");
		EXPECT_EQ(p_Fac->countN(), 2);
	}


}