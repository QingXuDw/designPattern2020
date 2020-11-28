#pragma once
#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <cstdlib>
#include <sstream>
#include "BaseClasses.h"
#include "TravelPlan.h"
#include "CIcecream.h"
#include "Clothesshop.h"


/*��Ʒ�Ķ��۽ṹ��
* �̵��еĸ�����Ʒ����������ж���
* ���¸�����Ʒ��Զ��۽�����Ӧ����ʾ
*/
struct Price : public DPObject
{
	constexpr int static juicePrice = 10;//��֭�ļ۸�
	constexpr int static yogertPrice = 8;//���̵ļ۸�
	constexpr int static CandiesPrice = 2;//�ǹ��ļ۸�
	constexpr int static equipmentRentingPrice = 100;//����һ��װ���ļ۸�
}Price;

/***************************************************************/
/***************����ƷFactory and Abstruct Factory **************/
/***************************************************************/

/*���麯��������ĳ��󹤳�
 * ������Ʒ�Ķ��� ����Ʒ����Ϣ������
 */
class Abstract_goods : public DPObject
{
public:
	int price;//��Ʒ�ļ۸�
	/*��������
	*�ͷ����ʵ��������Ԥ��������ݺͱ���
	*/
	virtual ~Abstract_goods() {};
	/*��Ʒ�۸���ʾ
	 * ��ʾ��Ӧ����Ʒ�ļ۸�
	*/
	virtual void typePrice() = 0;
	virtual std::string type() const = 0;//��Ʒ��Ϣ
};

/*��֭������
 *�̳г��󹤳���:��д���е��麯��
 *���Դ�����������Ʒ���ʵ��
 */
class Juice : public Abstract_goods
{
public:
	int price = Price.juicePrice;//��֭�ļ۸�

	/*�۸���
	*���ݲ�Ʒ���������Ӧ�Ĳ�Ʒ�۸�
	*/
	void typePrice() override
	{
		std::cout << "The price is" << price << "RMB.";
		return;
	}

	/*��������
	*�Թ˿�ѡ�����Ʒ��������������
	*/
	std::string type() const override
	{
		std::string coutpart1 = "Juice ,and you should pay ";
		std::string value = std::to_string(price);
		std::string coutpart2 = " yuan ,thanks.";

		return coutpart1 + value + coutpart2;
	}

};

/*�ǹ�������
 *�̳г��󹤳��� :��д���е��麯��
 *���Դ�����������Ʒ���ʵ��
 */
class Candies : public Abstract_goods
{
	int price = Price.CandiesPrice;//�ǹ��ļ۸�

	/*�۸���
	*���ݲ�Ʒ���������Ӧ�Ĳ�Ʒ�۸�
	*/
	void typePrice() override
	{
		std::cout << "The price is" << price << "RMB.";
		return;
	}

	/*��������
	*�Թ˿�ѡ�����Ʒ��������������
	*/
	std::string type() const override
	{
		std::string coutpart1 = "Candies,and you should pay ";
		std::string value = std::to_string(price);
		std::string coutpart2 = " yuan ,thanks.";

		return coutpart1 + value + coutpart2;
	}
};

/*���̹�����
 *�̳г��󹤳���:��д���е��麯��
 *���Դ�����������Ʒ���ʵ��
 */
class Yogert :public Abstract_goods//���̹��� �̳г����Ʒ��
{
	int price = Price.yogertPrice;//���̵ļ۸�

	/*�۸���
	*���ݲ�Ʒ���������Ӧ�Ĳ�Ʒ�۸�
	*/
	void typePrice() override
	{
		std::cout << "The price is" << price << "RMB.";
		return;
	}

	/*��������
	*�Թ˿�ѡ�����Ʒ��������������
	*/
	std::string type() const override
	{
		std::string coutpart1 = "Yogert ,and you should pay ";
		std::string value = std::to_string(price);
		std::string coutpart2 = " yuan ,thanks.";

		return coutpart1 + value + coutpart2;
	}
};

/*���麯������ζ���󹤳�
 * ������ζ���͵�ѡ�� �Ϳ�ζ������
 */
class Abstract_flavor : public DPObject
{

public:
	/*��������
	*�ͷ����ʵ��������Ԥ��������ݺͱ���
	*/
	virtual ~Abstract_flavor() {};
	/*�麯����ѡ���ζ
	*���ݿͻ������������������Ŀ�ζ��������
	*��������Ӧ������*/
	virtual std::string selectflavor() const = 0;
	/*�麯����������Ʒ
	 *@Abstract_goods &goodsType ���õ���Ʒ����
	 *��������Ʒ������������������
	 */
	virtual std::string describeGoods(const Abstract_goods& goodsType) const = 0;
};
/*ƻ����ζ��
 *�̳г����ζ��:��д���е��麯��
 *���Դ�����������Ʒ���ʵ��
 */
class Apple : public Abstract_flavor
{
public:
	/*ѡ���ζ
	*��д��ζ���еĺ��������ͻ�ѡ��ƻ����ζʱ�򣬽����󹤳�����Ϊƻ����ζ�Ĺ���
	*������Ӧ����ϢΪƻ����ζ*/
	std::string selectflavor() const override
	{
		return "The customer choose an apple one.";
	}
	/*������Ʒ
	*@Abstract_goods &goodsType ������Ʒ�����е���Ʒ����
	*��д�����ζ���еĺ�������ƻ�����������Ʒ�����ƽ�������
	*������Ӧ����Ʒ��������*/
	std::string describeGoods(const Abstract_goods& goodsType) const override
	{
		const std::string result = goodsType.type();
		return "Here is your apple " + result + " ";
	}
};
/*���ӿ�ζ��
 *�̳г����ζ��:��д���е��麯��
 *���Դ�����������Ʒ���ʵ��
 */
class Orange : public Abstract_flavor
{
public:
	/*ѡ���ζ
	*��д��ζ���еĺ��������ͻ�ѡ����ӿ�ζʱ�򣬽����󹤳�����Ϊ���ӿ�ζ�Ĺ���
	*������Ӧ����ϢΪ���ӿ�ζ*/
	std::string selectflavor() const override
	{
		return "The customer choose an Orange one.";
	}
	/*������Ʒ
	*Abstract_goods &goodsType ������Ʒ�����е���Ʒ����
	*��д�����ζ���еĺ����������ӹ��������Ʒ�����ƽ�������
	*������Ӧ����Ʒ��������*/
	std::string describeGoods(const Abstract_goods& goodsType) const override
	{
		const std::string result = goodsType.type();
		return "Here is your orange  " + result + " ";
	}
};

/*��Ʒ��
*�������п�ζ����������Ʒ���͵���Ʒ
*/
class Get_goods : public DPObject
{//���󹤳� �������������ԵĲ�Ʒ
public:
	/*��Ʒ�����麯��
	*����Abstract_goods �л����Ʒ������
	*/
	virtual Abstract_goods* getGoodsType() const = 0;
	/*��ζ�����麯��
	 *����Abstract_goods �л����Ʒ������
	 */
	virtual Abstract_flavor* getGoodsflavor() const = 0;
};
/*ƻ��֭��
*����ƻ��֭
*/
class  Get_apple_juice : public Get_goods
{

public:
	/*�����Ʒ������
	*��д�麯��������Ʒ������Ϊ��֭
	*������Ӧ����Ʒ����*/
	Abstract_goods* getGoodsType() const override
	{
		std::cout << "There is a juice facotory here,from goods facotory. " << std::endl;
		return new Juice();
	}
	/*��ÿ�ζ������
	*��д�麯��������Ʒ��ζ��Ϊƻ��
	*������Ӧ����Ʒ����*/
	Abstract_flavor* getGoodsflavor() const override
	{
		std::cout << "There is an Apple flavor factory here,from flavor factory." << std::endl;
		return new Apple();
	}
};

/*ƻ������
*����ƻ����
*/

class Get_apple_candies : public Get_goods
{
public:
	/*�����Ʒ������
	*��д�麯��������Ʒ������Ϊ�ǹ�
	*������Ӧ����Ʒ����*/
	Abstract_goods* getGoodsType() const override
	{
		std::cout << "There is a candies facotory here,from goods facotory. " << std::endl;
		return  new Candies();
	}
	/*��ÿ�ζ������
	*��д�麯��������Ʒ��ζ��Ϊƻ��
	*������Ӧ����Ʒ����*/
	Abstract_flavor* getGoodsflavor() const override
	{
		std::cout << "There is a apple facotory here,from flavor facotory. " << std::endl;
		return new Apple();
	}
};

/*ƻ��������
*����ƻ������
*/
class Get_apple_yogert : public Get_goods
{
public:
	/*�����Ʒ������
	*��д�麯��������Ʒ������Ϊ����
	*������Ӧ����Ʒ����*/
	Abstract_goods* getGoodsType() const override
	{
		std::cout << "There is a yogert facotory here,from goods facotory. " << std::endl;
		return  new Yogert();
	}
	/*��ÿ�ζ������
	*��д�麯��������Ʒ��ζ��Ϊƻ��
	*������Ӧ����Ʒ����*/
	Abstract_flavor* getGoodsflavor() const override
	{
		std::cout << "There is a apple facotory here,from flavor facotory. " << std::endl;
		return new Apple();
	}
};

/*��ζ�ǹ���
*������ζ�ǹ�
*/

class Get_orange_candies : public Get_goods
{
public:
	/*�����Ʒ������
	*��д�麯��������Ʒ������Ϊ�ǹ�
	*������Ӧ����Ʒ����*/
	Abstract_goods* getGoodsType() const override
	{
		std::cout << "There is a Candies facotory here,from goods facotory. " << std::endl;
		return  new Candies();
	}
	/*��ÿ�ζ������
	*��д�麯��������Ʒ��ζ��Ϊ��ζ
	*������Ӧ����Ʒ����*/
	Abstract_flavor* getGoodsflavor() const override
	{
		std::cout << "There is a orange facotory here,from flavor facotory. " << std::endl;
		return new Orange();
	}
};
/*��֭��
*������֭
*/

class Get_orange_juice : public Get_goods
{
public:
	/*�����Ʒ������
	*��д�麯��������Ʒ������Ϊ��֭
	*������Ӧ����Ʒ����*/
	Abstract_goods* getGoodsType() const override
	{
		std::cout << "There is a juice facotory here,from goods facotory. " << std::endl;
		return  new Juice();
	}
	/*��ÿ�ζ������
	*��д�麯��������Ʒ��ζ��Ϊ��ζ
	*������Ӧ����Ʒ����*/
	Abstract_flavor* getGoodsflavor() const override
	{
		std::cout << "There is a orange facotory here,from flavor facotory. " << std::endl;
		return new Orange();
	}
};

/*��ζ������
*������ζ����
*/

class Get_orange_yogert : public Get_goods
{
public:
	/*�����Ʒ������
	*��д�麯��������Ʒ������Ϊ����
	*������Ӧ����Ʒ����*/
	Abstract_goods* getGoodsType() const override
	{
		std::cout << "There is a yogert facotory here,from goods facotory. " << std::endl;
		return  new Yogert();
	}
	/*��ÿ�ζ������
	*��д�麯��������Ʒ��ζ��Ϊ��ζ
	*������Ӧ����Ʒ����*/
	Abstract_flavor* getGoodsflavor() const override
	{
		std::cout << "There is a orange facotory here,from flavor facotory. " << std::endl;
		return new Orange();
	}
};



/******************************************************************/
/*********************bridge ���ó��׵Ķ���*************************/
/******************************************************************/
/*���������ģ�
*�����������õ���������
*Ϊ���п������õ����ĵĸ���
*/
class Abstruct_equipment : public DPObject
{
public:
	/*��������
	*�ͷ����ʵ��������Ԥ��������ݺͱ���
	*/
	virtual ~Abstruct_equipment() {}
	/*���ò���
	*���ڶ�����Խ��е����ò���
	*���ؽ�Ҫ���еĲ���
	*/
	virtual std::string renting() const = 0;
};

/*ѩ����
*�̳����ĸ���:���Ƚ������޲���
*/
class Sticks : public Abstruct_equipment
{
public:
	/*���ò���
	*��д�����е�rent ��������ѩ��
	*/
	std::string renting() const override
	{
		return "The sticks are equipment.\n";
	}
};

/*������
*�̳����ĸ��ࣺ��ɶ԰�����޲���
*/
class Board : public Abstruct_equipment
{
public:
	/*���ò���
	*��д�����е�rent �������ð�
	*/
	std::string renting() const override
	{
		return "The  board is a equipment.\n";
	}
};

/*Suit ������������֮��Ľӿ�
��ά����ʵ�ֶ��������
��������ʵ�ʹ���ί�и��˶���*/
class Suit : public DPObject
{

protected:
	Abstruct_equipment* equipment_;

public:
	int price = Price.equipmentRentingPrice;
	Suit(Abstruct_equipment* equipment) : equipment_(equipment) {}

	virtual ~Suit() {}

	virtual std::string getTogether() const
	{
		return "Here is a basic operation.\n";
	}
};

/*Extend_suit ��������֮��Ĳ�����������Ӧ����չ
*��Ӧ���ȺͰ��ƥ�����
*/
class Extend_suit : public Suit
{
public:

	Extend_suit(Abstruct_equipment* equipment) : Suit(equipment) {}
	/*��ϲ���
	* �����Ⱥ���Ӧ�Ļ������
	*/
	std::string getTogether() const override
	{
		return  this->equipment_->renting() + "The board and the sticks is a pair.Please take away them together!\n" + "It costs 100 yuan.\n";
	}

};




/************************************************************************
*							ShoppingMallģ��							*
*************************************************************************/


class ShoppingManager : public  CommandReceiver
{

private:
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"shop"
	* @return void
	*/
	ShoppingManager() : CommandReceiver("shop") {}


	/*�û���������
	* ����suit.Together���������������
	* @return void
	*/
	void Client_equipment(const Suit& suit)
	{
		std::cout << suit.getTogether();
	}


protected:
	/*�û�������Ʒ
	* @param factory ����Get_goods����ͨ�����󹤳�������Ʒ
	* @return void
	*/
	void Client_goods(const Get_goods& factory)
	{
		const Abstract_goods* product_a = factory.getGoodsType();
		//ͨ�����󹤳������������Ʒ
		const Abstract_flavor* product_b = factory.getGoodsflavor();
		//ͨ�����󹤳���������Ŀ�ζ
		std::cout << product_b->selectflavor() << "\n";
		std::cout << product_b->describeGoods(*product_a) << "\n";
		delete product_a;
		delete product_b;
	}

	/*�û�������ָ��
	*�����û�����Ҫ������Ӧ�Ķ������
	* @param op �û���������/�����
	* @param obj �û���Ҫ��õľ������
	* @return void
	*/
	void ClientOption(std::string op, std::string obj)
	{
		//�ж��Ƿ�Ϊbuy ��ָ��
		if (op == "buy")
		{
			if (obj == "AppleJuice")//�û�ѡ��
			{
				Get_apple_juice* objAppleJuice = new Get_apple_juice();//������֭�Ĺ�����ƻ��ζ�Ĺ���
				std::cout << "Client:I'd like some apple juice.\n";//���鴴���Ƿ�ɹ�
				Client_goods(*objAppleJuice);//����ͻ���Ҫ����Ӧ�Ķ���
				delete objAppleJuice;
			}
			else if (obj == "OrangeJuice")//�û�ѡ��
			{
				Get_orange_juice* objOrangeJuice = new Get_orange_juice();//������֭�Ĺ����ͳ���ζ�Ĺ���
				std::cout << "Client:I'd like some orange juice.\n";//���鴴���Ƿ�ɹ�
				Client_goods(*objOrangeJuice);//����ͻ���Ҫ����Ӧ�Ķ���
				delete objOrangeJuice;
			}
			else if (obj == "AppleYogert")//�û�ѡ��
			{
				Get_apple_yogert* objAppleYogert = new Get_apple_yogert();//�������̹�����ƻ��ζ�Ĺ���
				std::cout << "Client:I'd like some apple yougert.\n";//���鴴���Ƿ�ɹ�
				Client_goods(*objAppleYogert);//����ͻ���Ҫ����Ӧ�Ķ���
				delete objAppleYogert;
			}
			else if (obj == "OrangeYogert")//�û�ѡ��
			{
				Get_orange_yogert* objOrangeYogert = new Get_orange_yogert();//�������̹����ͳ�ζ����
				std::cout << "Client:I'd like some orange yogert.\n";//���鴴���Ƿ�ɹ�
				Client_goods(*objOrangeYogert);//����ͻ���Ҫ����Ӧ�Ķ���
				delete objOrangeYogert;
			}
			else if (obj == "AppleCandies")//�û�ѡ��
			{
				Get_apple_candies* objAppleCandies = new Get_apple_candies();//�����ǹ�������ƻ��ζ����
				std::cout << "Client:I'd like some apple candies.\n";//���鴴���Ƿ�ɹ�
				Client_goods(*objAppleCandies);//����ͻ���Ҫ����Ӧ�Ķ���
				delete objAppleCandies;
			}
			else if (obj == "OrangeCandies")
			{
				Get_orange_candies* objOrangeCandies = new Get_orange_candies();//�����ǹ������ͳ�ζ����
				std::cout << "Client:I'd like some orange candies.\n";//���鴴���Ƿ�ɹ�
				Client_goods(*objOrangeCandies);//����ͻ���Ҫ����Ӧ�Ķ���
				delete objOrangeCandies;
			}

			else
			{
				std::cout << "Wrong Input,Please input again!" << std::endl;//δ���������������������
			}
		}

		else if (op == "rent")//�����Ҫ���еĲ���Ϊ���޵Ĳ���
		{
			if (obj == "sticks")//ʶ����Ӧ��ָ��
			{
				Abstruct_equipment* equipment = new Sticks;//�ӳ��󹤳��������
				Suit* suit = new Extend_suit(equipment);//����suit ����������Ҫ�Ķ����������
				Client_equipment(*suit);//�����Ӧ�������Ϣ
				delete equipment;
				delete suit;
			}
			else if (obj == "board")
			{
				Abstruct_equipment* equipment = new Board;    //�ӳ��󹤳��������
				Suit* suit = new Extend_suit(equipment);//����suit ����������Ҫ�Ķ����������
				Client_equipment(*suit);//�����Ӧ�������Ϣ
				delete equipment;
				delete suit;
			}
			else
			{
				std::cout << "Wrong Input,Please input again!" << std::endl;//����������ʾ��������������
			}
		}


	}

	/*ִ��ָ��
	* ���ظ���ִ��ָ��Ĵ��麯�����������������ִ����Ӧ����
	* @param cmd �û������ָ������
	* @return bool ָ���ʽ�Ƿ���ȷ
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);//����������и�
		removeBlank(cmd);
		//���tag Ϊbuy
		if (subCmd == "buy")
		{
			if (cmd == "AppleJuice")//tag ="AppleJuice" ��Ӧ��Ӧ���û�����
			{
				ClientOption("buy", "AppleJuice");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "OrangeJuice")//tag ="OrangeJuicee" ��Ӧ��Ӧ���û�����
			{
				ClientOption("buy", "OrangeJuice");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "AppleYogert")//tag ="AppleYogert" ��Ӧ��Ӧ���û�����
			{
				ClientOption("buy", "AppleYogert");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "OrangeYogert")//tag ="OrangeYogert" ��Ӧ��Ӧ���û�����
			{
				ClientOption("buy", "OrangeYogert");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "AppleCandies")//tag ="AppleCandies" ��Ӧ��Ӧ���û�����
			{
				ClientOption("buy", "AppleCandies");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "OrangeCandies")//tag ="OrangeCandies" ��Ӧ��Ӧ���û�����
			{
				ClientOption("buy", "OrangeCandies");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "clothes")
			{
				clothesshop::getInstance().buy();
				return true;
			}
			return false;
		}
		if (subCmd == "rent")//���tag Ϊ"rent"
		{
			if (cmd == "sticks")//tag="sticks" ��Ӧ��Ӧ��Ӧ���û�����
			{
				ClientOption("rent", "sticks");
				return true;
			}
			if (cmd == "board")//tag="board" ��Ӧ��Ӧ���û�����
			{
				ClientOption("rent", "board");
				return true;
			}
		}



		return false;
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	ShoppingManager(const ShoppingManager&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	ShoppingManager& operator=(const ShoppingManager&) = delete;

	/*��ȡ������������
	* ��ȡȫ��Ψһ����������ʵ�������ã�����ʵ�ֵ�����
	* @return MainReciver& ��������������
	*/
	static ShoppingManager& getInstance()
	{
		static ShoppingManager reciver;
		return reciver;
	}
	/*��ӡ����ָ��
	* ���ظ����麯��������level��ӡ��Ӧ��ʽ��ָ��Լ�������ָ��
	* @param level ��ǰReciver��Reciver���еĲ㼶
	* @return void
	*/
	virtual void printHelp(int level)
	{
		CommandReceiver::printHelp(level);
		level++;								//���ø����Ĭ��printHelp�������ݹ������ǰ���ӽ�������tag
		std::string head(level * 3, '-');		//����ָ����ʾ����һ��
		std::cout << head + "buy" << std::endl;		//�����һ��������
		std::cout << head + "---" + "AppleJuice" << std::endl;		//����ڶ���������						
		std::cout << head + "---" + "AppleYogert" << std::endl;		//����ڶ���������
		std::cout << head + "---" + "AppleCandies" << std::endl;		//����ڶ���������
		std::cout << head + "---" + "OrangeJuice" << std::endl;		//����ڶ���������
		std::cout << head + "---" + "OrangeYogert" << std::endl;		//����ڶ���������
		std::cout << head + "---" + "OrangeCandies" << std::endl;	//����ڶ���������
		std::cout << head + "rent" << std::endl;					//�����һ��rent ������
		std::cout << head + "---" + "sticks" << std::endl;           //����ڶ���������
		std::cout << head + "---" + "board" << std::endl;			//����ڶ���������
	}


};