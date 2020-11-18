#pragma once
#include "pch.h"
#include "../designPattern/Consult.h"
#include <vector>

//用namespace包裹以防止命名冲突
namespace zgx {
	/************************************************************************************
	*																					*
	*						负责测试Consult.h中的类										*
	*************************************************************************************/
	class ParkPlayingTest : public RedirectIO {
	public:
		ParkPlaying* p_parkPlaying;
		void SetUp() override {
			RedirectIO::SetUp();
			p_parkPlaying = new ParkPlaying();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_parkPlaying);
		}
	};
	TEST_F(ParkPlayingTest, Location) {
		EXPECT_NO_THROW(p_parkPlaying->Location());
	}

	class ParkFacilityTest : public RedirectIO {
	public:
		ParkFacility* p_parkFacility;
		void SetUp() override {
			RedirectIO::SetUp();
			p_parkFacility = new ParkFacility();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_parkFacility);
		}
	};
	TEST_F(ParkFacilityTest, Location) {
		EXPECT_NO_THROW(p_parkFacility->Location());
	}

	class ParkEatingTest : public RedirectIO {
	public:
		ParkEating* p_parkEating;
		void SetUp() override {
			RedirectIO::SetUp();
			p_parkEating = new ParkEating();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_parkEating);
		}
	};
	TEST_F(ParkEatingTest, Location) {
		EXPECT_NO_THROW(p_parkEating->Location());
	}

	class ParkHousingTest : public RedirectIO {
	public:
		ParkHousing* p_parkHousing;
		void SetUp() override {
			RedirectIO::SetUp();
			p_parkHousing = new ParkHousing();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_parkHousing);
		}
	};
	TEST_F(ParkHousingTest, Location) {
		EXPECT_NO_THROW(p_parkHousing->Location());
	}

	class FacadeTest : public RedirectIO {
	public:
		Facade* p_facade;
		void SetUp() override {
			RedirectIO::SetUp();
			p_facade = new Facade();
		}
		void TearDown() override
		{
			RedirectIO::TearDown();
			S_DELETE(p_facade);
		}
	};

	TEST_F(FacadeTest, ConsultPlay) {
		ParkPlaying* _parkPlaying;
		p_facade->ConsultPlay();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "_parkPlaying->Location()");
		_parkPlaying = NULL;
		delete(_parkPlaying);
	}

	TEST_F(FacadeTest, ConsultFacility) {
		ParkFacility* _parkFacility;
		p_facade->ConsultFacility();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "_parkFacility->Location()");
		_parkFacility = NULL;
		delete(_parkFacility);
	}

	TEST_F(FacadeTest, ConsultEating) {
		ParkEating* _parkEating;
		p_facade->ConsultEating();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "_parkEating->Location()");
		_parkEating = NULL;
		delete(_parkEating);
	}

	TEST_F(FacadeTest, ConsultHousing) {
		ParkHousing* _parkHousing;
		p_facade->ConsultHousing();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "_parkHousing->Location()");
		_parkHousing = NULL;
		delete(_parkHousing);
	}

	TEST_F(FacadeTest, start) {
		EXPECT_NO_THROW(p_facade->start());
	}
}

	
