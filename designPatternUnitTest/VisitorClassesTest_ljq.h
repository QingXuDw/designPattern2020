#pragma once
#include "pch.h"
#include "../designPattern/VisitorClasses.h"
namespace ljq {
	using namespace std;
	class AbstractVisitorTest : public RedirectIO {
	protected:
		AbstractVisitor* p_abstractVisitor;
		void SetUp() override {
			RedirectIO::SetUp();
			p_abstractVisitor = new AbstractVisitor();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_abstractVisitor);
		}
	};
	TEST_F(AbstractVisitorTest, VisitGhostCave) {
		p_abstractVisitor->VisitGhostCave();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "*********************************************************************");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "****************************** 冰封鬼窟 *****************************");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "*********************************************************************");
		getline(sout, result);
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "欢迎来到冰封鬼窟！");
		getline(sout, result);
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "探险者，你做好前进的准备了吗？");
		getline(sout, result);
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "———————————————————————————————————");
	}
	TEST_F(AbstractVisitorTest, VisitIceSculptureExhibit) {
		p_abstractVisitor->VisitIceSculptureExhibit();
		std::string result;
		getline(sout, result);
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "欢迎参观冰雕展览！");
		getline(sout, result);
	}
	class ConcreteVisitorTest : public RedirectIO {
	protected:
		ConcreteVisitor* p_concreteVisitor;
		void SetUp() override {
			RedirectIO::SetUp();
			p_concreteVisitor = new ConcreteVisitor();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_concreteVisitor);
		}
	};
	TEST_F(ConcreteVisitorTest, VisitIceSculptureExhibit) {
		p_concreteVisitor->VisitIceSculptureExhibit();
		std::string result;
		getline(sout, result);
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "欢迎参观冰雕展览！");
		getline(sout, result);
		getline(sout, result);
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "参观结束，将继续踏上行程。");
		getline(sout, result);
	}
	class GhostCaveTest : public RedirectIO {
	protected:
		GhostCave* p_ghostCave;
		void SetUp() override {
			RedirectIO::SetUp();
			p_ghostCave = new GhostCave();
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_ghostCave);
		}
	};
	TEST_F(GhostCaveTest, showDecorate) {
		p_ghostCave->showDecorate();
		std::string result;
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "冰封鬼窟当前的装饰为：");
		getline(sout, result);
		EXPECT_STREQ(result.c_str(), "冰锥");
	}
	class DecoratorTest :public RedirectIO {
	protected:
		Decorator* p_decorator;
		GhostCave* p_ghostCave;
		void SetUp() override {
			RedirectIO::SetUp();
			p_decorator = new Decorator(p_ghostCave);
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_decorator);
			S_DELETE(p_ghostCave);
		}
	};
	class AddGhostTest :public RedirectIO {
	protected:
		AddGhost* p_addGhost;
		GhostCave* p_ghostCave;
		void SetUp() override {
			RedirectIO::SetUp();
			p_ghostCave = new GhostCave();
			p_addGhost = new AddGhost(p_ghostCave);
		}
		void TearDown() override {
			RedirectIO::TearDown();
			S_DELETE(p_addGhost);
			S_DELETE(p_ghostCave);
		}
	};
	TEST_F(AddGhostTest, showDecorate) {
		EXPECT_NO_THROW(p_addGhost->showDecorate());
	}
}