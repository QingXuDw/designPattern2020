#pragma once
#include "pch.h"
#include "../designPattern/ShoppingMall.h"
#include <vector>

//用namespace包裹以防止命名冲突
namespace wjy {
	/************************************************************************************
	*																					*
	*								GoodsTest货物测试用例									*
	*																					*
	*					负责测试ShoppingMall.h中的Abstract_goods类及其子类					*
	*************************************************************************************/
	class GoodsTest : public RedirectIO {
	protected:
		//用于维护各子类对象的vector
		vector<Abstract_goods*> goods;
		//在goods中为每一个子类生成一个对象
		void SetUp() override {
			RedirectIO::SetUp();
			Abstract_goods* p_good;
			p_good = new Juice();
			goods.push_back(p_good);
			p_good = new Candies();
			goods.push_back(p_good);
			p_good = new Yogert();
			goods.push_back(p_good);
		}
		//清理goods中的全部子类对象
		void TearDown() override {
			RedirectIO::TearDown();
			for (std::vector<Abstract_goods*>::iterator i = goods.begin();
				i != goods.end();
				i++)
			{
				S_DELETE((*i));
			}
		}
	};

	TEST_F(GoodsTest, TypePrice) {
		for (std::vector<Abstract_goods*>::iterator i = goods.begin();
			i != goods.end();
			i++)
		{
			EXPECT_NO_THROW((*i)->typePrice());
		}
	}

	TEST_F(GoodsTest, Type) {
		for (std::vector<Abstract_goods*>::iterator i = goods.begin();
			i != goods.end();
			i++)
		{
			EXPECT_NO_THROW((*i)->type());
		}
	}



	class FlavorsTest : public RedirectIO {
	protected:
		vector<Abstract_flavor*> flavors;
		void SetUp() override {
			RedirectIO::SetUp();
			Abstract_flavor* p_flavor;
			p_flavor = new Apple();
			flavors.push_back(p_flavor);
		}
		void TearDown() override {
			RedirectIO::TearDown();
			for (std::vector<Abstract_flavor*>::iterator i = flavors.begin();
				i != flavors.end();
				i++)
			{
				S_DELETE((*i));
			}
		}
	public:
	};

	TEST_F(FlavorsTest, SelectFlavor) {
		for (std::vector<Abstract_flavor*>::iterator i = flavors.begin();
			i != flavors.end();
			i++)
		{
			EXPECT_NO_THROW((*i)->selectflavor());
		}
	}

	TEST_F(FlavorsTest, DescribeGoods) {
		vector<Abstract_goods*> goods;
		Abstract_goods* p_good;
		p_good = new Juice();
		goods.push_back(p_good);
		p_good = new Candies();
		goods.push_back(p_good);
		p_good = new Yogert();
		goods.push_back(p_good);
		for (std::vector<Abstract_flavor*>::iterator iFlavor = flavors.begin();
			iFlavor != flavors.end();
			iFlavor++)
		{
			for (std::vector<Abstract_goods*>::iterator iGood = goods.begin();
				iGood != goods.end();
				iGood++)
			{
				EXPECT_NO_THROW((*iFlavor)->describeGoods((*(*iGood))));
			}
		}
		for (std::vector<Abstract_goods*>::iterator iGood = goods.begin();
			iGood != goods.end();
			iGood++)
		{
			S_DELETE((*iGood));
		}
	}


	class GetGoodsTest : public RedirectIO {
	protected:
		vector<Get_goods*> getGoods;
		void SetUp() override {
			RedirectIO::SetUp();
			Get_goods* p_getGood;
			p_getGood = new Get_apple_juice();
			getGoods.push_back(p_getGood);
			p_getGood = new Get_apple_candies();
			getGoods.push_back(p_getGood);
			p_getGood = new Get_apple_yogert();
			getGoods.push_back(p_getGood);
			p_getGood = new Get_orange_juice();
			getGoods.push_back(p_getGood);
			p_getGood = new Get_orange_candies();
			getGoods.push_back(p_getGood);
			p_getGood = new Get_orange_yogert();
			getGoods.push_back(p_getGood);
		}
		void TearDown() override {
			RedirectIO::TearDown();
			for (std::vector<Get_goods*>::iterator i = getGoods.begin();
				i != getGoods.end();
				i++)
			{
				S_DELETE((*i));
			}
		}
	};

	TEST_F(GetGoodsTest, GetGoodsType) {
		for (std::vector<Get_goods*>::iterator i = getGoods.begin();
			i != getGoods.end();
			i++)
		{
			EXPECT_NO_THROW((*i)->getGoodsType());
		}
	}

	TEST_F(GetGoodsTest, GetGoodsFlavor) {
		for (std::vector<Get_goods*>::iterator i = getGoods.begin();
			i != getGoods.end();
			i++)
		{
			EXPECT_NO_THROW((*i)->getGoodsflavor());
		}
	}


	class EquipmentsTest : public RedirectIO {
	protected:
		vector<Abstruct_equipment*> quipments;
		void SetUp() override {
			RedirectIO::SetUp();
			Abstruct_equipment* p_euipment;
			p_euipment = new Sticks();
			quipments.push_back(p_euipment);
			p_euipment = new Board();
			quipments.push_back(p_euipment);
		}
		void TearDown() override {
			RedirectIO::TearDown();
			for (std::vector<Abstruct_equipment*>::iterator i = quipments.begin();
				i != quipments.end();
				i++)
			{
				S_DELETE((*i));
			}
		}
	};

	TEST_F(EquipmentsTest, Renting) {
		for (std::vector<Abstruct_equipment*>::iterator i = quipments.begin();
			i != quipments.end();
			i++)
		{
			EXPECT_NO_THROW((*i)->renting());
		}
	}

	class SuitsTest : public RedirectIO {
	protected:
		vector<Suit*> suits;
		vector<Abstruct_equipment*> quipments;
		void SetUp() override {
			RedirectIO::SetUp();
			Abstruct_equipment* p_euipment;
			Suit* p_suit;
			p_euipment = new Sticks();
			quipments.push_back(p_euipment);
			p_euipment = new Board();
			quipments.push_back(p_euipment);
			for (std::vector<Abstruct_equipment*>::iterator iEquipment = quipments.begin();
				iEquipment != quipments.end();
				iEquipment++)
			{
				p_suit = new Extend_suit((*iEquipment));
				suits.push_back(p_suit);
			}
		}
		void TearDown() override {
			RedirectIO::TearDown();
			for (std::vector<Suit*>::iterator iSuit = suits.begin();
				iSuit != suits.end();
				iSuit++)
			{
				S_DELETE((*iSuit));
			}
			for (std::vector<Abstruct_equipment*>::iterator iEquipment = quipments.begin();
				iEquipment != quipments.end();
				iEquipment++)
			{
				S_DELETE((*iEquipment));
			}
		}
	};

	TEST_F(SuitsTest, GetTogether) {
		for (std::vector<Suit*>::iterator i = suits.begin();
			i != suits.end();
			i++)
		{
			EXPECT_NO_THROW((*i)->getTogether());
		}
	}

	class ShoppingManagerTest : public RedirectIO {
	protected:
		ShoppingManager* p_shoppingManager;
		void SetUp() override {
			RedirectIO::SetUp();
			p_shoppingManager = &(ShoppingManager::getInstance());
		}
		void TearDown() override {
			RedirectIO::TearDown();
		}
		static void s_delete(void* ptr) {
			if ((ptr) != nullptr) { delete (ptr); (ptr) = nullptr; }
		}
	};

	TEST_F(ShoppingManagerTest, HandleCommand) {
		std::string result;
		EXPECT_NO_THROW(p_shoppingManager->handleCommand(""));
		EXPECT_NO_THROW(p_shoppingManager->handleCommand("buy"));
		EXPECT_NO_THROW(p_shoppingManager->handleCommand("buy AppleJuice"));
		EXPECT_NO_THROW(p_shoppingManager->handleCommand("buy OrangeJuice"));
		EXPECT_NO_THROW(p_shoppingManager->handleCommand("buy AppleYogert"));
		EXPECT_NO_THROW(p_shoppingManager->handleCommand("buy OrangeYogert"));
		EXPECT_NO_THROW(p_shoppingManager->handleCommand("buy AppleCandies"));
		EXPECT_NO_THROW(p_shoppingManager->handleCommand("buy OrangeCandies"));
		EXPECT_NO_THROW(p_shoppingManager->handleCommand("rent"));
		EXPECT_NO_THROW(p_shoppingManager->handleCommand("rent sticks"));
		EXPECT_NO_THROW(p_shoppingManager->handleCommand("rent board"));

	}

	TEST_F(ShoppingManagerTest, PrintHelp) {
		EXPECT_NO_THROW(p_shoppingManager->printHelp(0));
	}
}

