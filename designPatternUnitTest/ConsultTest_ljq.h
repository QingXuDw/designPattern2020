#pragma once
#include"pch.h"
#include "../designPattern/Consult.h"
namespace ljq {
	using namespace std;
	class ParkPlayingTest : public RedirectIO {
	protected:
		ParkPlaying* p_parkPlaying;
		void SetUp() override {
			RedirectIO::SetUp();
			p_parkPlaying = new ParkPlaying();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_parkPlaying);
		}
	};
	TEST_F(ParkPlayingTest, Location) {
		p_parkPlaying->Location();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "  ������λ��԰������");
		
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "  ��ɽ��ǰ��԰���ϲ�");
	}
	class ParkFacilityTest : public RedirectIO {
	protected:
		ParkFacility* p_parkFacility;
		void SetUp() override {
			RedirectIO::SetUp();
			p_parkFacility = new ParkFacility();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_parkFacility);
		}
	};
	TEST_F(ParkFacilityTest, Location) {
		p_parkFacility->Location();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "  ������λ����ο�԰����ͼ" );
	}
	class ParkEatingTest : public RedirectIO {
	protected:
		ParkEating* p_parkEating;
		void SetUp() override {
			RedirectIO::SetUp();
			p_parkEating = new ParkEating();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_parkEating);
		}
	};
	TEST_F(ParkEatingTest, Location) {
		p_parkEating->Location();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "  ����λ��԰��������");
	}
	class ParkHousingTest : public RedirectIO {
	protected:
		ParkHousing* p_parkHousing;
		void SetUp() override {
			RedirectIO::SetUp();
			p_parkHousing = new ParkHousing();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_parkHousing);
		}
	};
	TEST_F(ParkHousingTest, Location) {
		p_parkHousing->Location();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "  �Ƶ�λ��԰�����ϲ�");
	}
	class FacadeTest : public RedirectIO {
	protected:
		Facade* p_facade;
		void SetUp() override {
			RedirectIO::SetUp();
			p_facade = new Facade();
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
		static void s_delete(void* ptr) {
			if ((ptr) != nullptr) { delete (ptr); (ptr) = nullptr; }
		}
	};
	TEST_F(FacadeTest, ConsultPlay) {
		p_facade->ConsultPlay();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "  ������λ��԰������");
		
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "  ��ɽ��ǰ��԰���ϲ�");
	}
	TEST_F(FacadeTest, ConsultFacility) {
		p_facade->ConsultFacility();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "  ������λ����ο�԰����ͼ");
	}
	TEST_F(FacadeTest, ConsultEating) {
		p_facade->ConsultEating();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "  ����λ��԰��������");
	}
	TEST_F(FacadeTest, ConsultHousing) {
		p_facade->ConsultHousing();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "  �Ƶ�λ��԰�����ϲ�");
	}
	
}