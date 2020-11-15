#pragma once
#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <cstdlib>
#include <sstream>
#include "BaseClasses.h"
#include "TravelPlan.h"

/*shopping 结构体定义了shopping的相应描述
*/
struct Shopping : public DPObject 
{
public:
	Path* path;//相应的路径
	Description* description;//相应的描述
	Spot* spot;
	/*析构函数
	* 用于防止内存泄露，递归释放对象
	*/
	~Shopping() 
	{
		if (path != nullptr) { delete path; }
		if (description != nullptr) { delete description; }
	}
};

/*产品的定价结构体
* 商店中的各个物品都在这里进行定价
* 以下各个商品会对定价进行相应的提示
*/
struct Price : public DPObject
{
	constexpr int static juicePrice = 10;//果汁的价格
	constexpr int static yogertPrice = 8;//酸奶的价格
	constexpr int static CandiesPrice = 2;//糖果的价格
	constexpr int static equipmentRentingPrice = 100;//租赁一套装备的价格
}Price;

/***************************************************************/
/***************买物品Factory and Abstruct Factory **************/
/***************************************************************/

/*纯虚函数：货物的抽象工厂
 * 包括商品的定价 和商品的信息的描述
 */
class Abstract_goods : public DPObject
{
public:
	int price;//物品的价格
	/*析构函数
	*释放类的实例和类中预定义的数据和变量
	*/
	virtual ~Abstract_goods() {};
	/*商品价格显示
	 * 显示对应的商品的价格
	*/
	virtual void typePrice() = 0;
	virtual std::string type() const = 0;//商品信息
};

/*果汁工厂类
 *继承抽象工厂类:重写其中的虚函数
 *可以创建多个具体产品类的实例
 */
class Juice : public Abstract_goods
{
public:
	int price = Price.juicePrice;//果汁的价格

	/*价格函数
	*根据产品定价输出相应的产品价格
	*/
	void typePrice() override
	{
		std::cout << "The price is" << price << "RMB.";
		return;
	}

	/*描述函数
	*对顾客选择的商品进行描述并返回
	*/
	std::string type() const override 
	{
		std::string coutpart1 = "Juice ,and you should pay ";
		std::string value = std::to_string(price);
		std::string coutpart2 = " yuan ,thanks.";

		return coutpart1 + value + coutpart2;
	}

};

/*糖果工厂类
 *继承抽象工厂类 :重写其中的虚函数
 *可以创建多个具体产品类的实例
 */
class Candies : public Abstract_goods 
{
	int price = Price.CandiesPrice;//糖果的价格

	/*价格函数
	*根据产品定价输出相应的产品价格
	*/
	void typePrice() override
	{
		std::cout << "The price is" << price << "RMB.";
		return;
	}

	/*描述函数
	*对顾客选择的商品进行描述并返回
	*/
	std::string type() const override 
	{
		std::string coutpart1 = "Candies,and you should pay ";
		std::string value = std::to_string(price);
		std::string coutpart2 = " yuan ,thanks.";

		return coutpart1 + value + coutpart2;
	}
};

/*酸奶工厂类
 *继承抽象工厂类:重写其中的虚函数
 *可以创建多个具体产品类的实例
 */
class Yogert :public Abstract_goods//酸奶工厂 继承抽象产品类
{
	int price = Price.yogertPrice;//酸奶的价格

	/*价格函数
	*根据产品定价输出相应的产品价格
	*/
	void typePrice() override
	{
		std::cout << "The price is" << price << "RMB.";
		return;
	}

	/*描述函数
	*对顾客选择的商品进行描述并返回
	*/
	std::string type() const override
	{
		std::string coutpart1 = "Yogert ,and you should pay ";
		std::string value = std::to_string(price);
		std::string coutpart2 = " yuan ,thanks.";

		return coutpart1 + value + coutpart2;
	}
};

/*纯虚函数：口味抽象工厂
 * 包括口味类型的选择 和口味的描述
 */
class Abstract_flavor : public DPObject
{

public:
	/*析构函数
	*释放类的实例和类中预定义的数据和变量
	*/
	virtual ~Abstract_flavor() {};
	/*虚函数：选择口味
	*根据客户的输入来决定创建的口味工厂类型
	*并返回相应的类型*/
	virtual std::string selectflavor() const = 0;
	/*虚函数：描述商品
	 *@Abstract_goods &goodsType 引用的商品类型
	 *对整个商品进行描述并返回描述
	 */
	virtual std::string describeGoods(const Abstract_goods &goodsType) const = 0;
};
/*苹果口味类
 *继承抽象口味类:重写其中的虚函数
 *可以创建多个具体产品类的实例
 */
class Apple : public Abstract_flavor
{
public:
	/*选择口味
	*重写口味类中的函数，当客户选择苹果口味时候，将抽象工厂定义为苹果口味的工厂
	*返回相应的信息为苹果口味*/
	std::string selectflavor() const override
	{
		return "The customer choose an apple one.";
	}
	/*描述商品
	*@Abstract_goods &goodsType 引用商品工厂中的商品类型
	*重写抽象口味类中的函数，将苹果工厂与该商品的名称进行连接
	*返回相应的商品整体描述*/
	std::string describeGoods(const Abstract_goods &goodsType) const override
	{
		const std::string result = goodsType.type();
		return "Here is your apple " + result + " ";
	}
};
/*橙子口味类
 *继承抽象口味类:重写其中的虚函数
 *可以创建多个具体产品类的实例
 */
class Orange : public Abstract_flavor
{
public:
	/*选择口味
	*重写口味类中的函数，当客户选择橙子口味时候，将抽象工厂定义为橙子口味的工厂
	*返回相应的信息为苹果口味*/
	std::string selectflavor() const override
	{
		return "The customer choose an Orange one.";
	}
	/*描述商品
	*Abstract_goods &goodsType 引用商品工厂中的商品类型
	*重写抽象口味类中的函数，将橙子工厂与该商品的名称进行连接
	*返回相应的商品整体描述*/
	std::string describeGoods(const Abstract_goods &goodsType) const override
	{
		const std::string result = goodsType.type();
		return "Here is your orange  " + result + " ";
	}
};

/*商品类
*创建既有口味属性又有商品类型的商品
*/
class Get_goods : public DPObject 
{//抽象工厂 生产有两个属性的产品
public:
	/*商品类型虚函数
	*调用Abstract_goods 中获得商品的属性
	*/
	virtual Abstract_goods *getGoodsType() const = 0;
	/*口味类型虚函数
	 *调用Abstract_goods 中获得商品的属性
	 */
	virtual Abstract_flavor *getGoodsflavor() const = 0;
};
/*苹果汁类
*创建苹果汁
*/
class  Get_apple_juice : public Get_goods
{

public:
	/*获得商品的类型
	*重写虚函数：将商品类型设为果汁
	*返回相应的商品类型*/
	Abstract_goods *getGoodsType() const override
	{
		std::cout << "There is a juice facotory here,from goods facotory. " << std::endl;
		return new Juice();
	}
	/*获得口味的类型
	*重写虚函数：将商品口味设为苹果
	*返回相应的商品类型*/
	Abstract_flavor *getGoodsflavor() const override
	{
		std::cout << "There is an Apple flavor factory here,from flavor factory." << std::endl;
		return new Apple();
	}
};

/*苹果糖类
*创建苹果糖
*/

class Get_apple_candies : public Get_goods
{
public:
	/*获得商品的类型
	*重写虚函数：将商品类型设为糖果
	*返回相应的商品类型*/
	Abstract_goods *getGoodsType() const override
	{
		std::cout << "There is a candies facotory here,from goods facotory. " << std::endl;
		return  new Candies();
	}
	/*获得口味的类型
	*重写虚函数：将商品口味设为苹果	
	*返回相应的商品类型*/
	Abstract_flavor *getGoodsflavor() const override
	{
		std::cout << "There is a apple facotory here,from flavor facotory. " << std::endl;
		return new Apple();
	}
};

/*苹果酸奶类
*创建苹果酸奶
*/
class Get_apple_yogert : public Get_goods
{
public:
	/*获得商品的类型
	*重写虚函数：将商品类型设为酸奶
	*返回相应的商品类型*/
	Abstract_goods *getGoodsType() const override
	{
		std::cout << "There is a yogert facotory here,from goods facotory. " << std::endl;
		return  new Yogert();
	}
	/*获得口味的类型
	*重写虚函数：将商品口味设为苹果
	*返回相应的商品类型*/
	Abstract_flavor *getGoodsflavor() const override
	{
		std::cout << "There is a apple facotory here,from flavor facotory. " << std::endl;
		return new Apple();
	}
};

/*橙味糖果类
*创建橙味糖果
*/

class Get_orange_candies : public Get_goods
{
public:
	/*获得商品的类型
	*重写虚函数：将商品类型设为糖果
	*返回相应的商品类型*/
	Abstract_goods *getGoodsType() const override
	{
		std::cout << "There is a Candies facotory here,from goods facotory. " << std::endl;
		return  new Candies();
	}
	/*获得口味的类型
	*重写虚函数：将商品口味设为橙味
	*返回相应的商品类型*/
	Abstract_flavor *getGoodsflavor() const override
	{
		std::cout << "There is a orange facotory here,from flavor facotory. " << std::endl;
		return new Orange();
	}
};
/*橙汁类
*创建橙汁
*/

class Get_orange_juice : public Get_goods
{
public:
	/*获得商品的类型
	*重写虚函数：将商品类型设为果汁
	*返回相应的商品类型*/
	Abstract_goods *getGoodsType() const override
	{
		std::cout << "There is a juice facotory here,from goods facotory. " << std::endl;
		return  new Juice();
	}
	/*获得口味的类型
	*重写虚函数：将商品口味设为橙味
	*返回相应的商品类型*/
	Abstract_flavor *getGoodsflavor() const override
	{
		std::cout << "There is a orange facotory here,from flavor facotory. " << std::endl;
		return new Orange();
	}
};

/*橙味酸奶类
*创建橙味酸奶
*/

class Get_orange_yogert : public Get_goods
{
public:
	/*获得商品的类型
	*重写虚函数：将商品类型设为酸奶
	*返回相应的商品类型*/
	Abstract_goods *getGoodsType() const override
	{
		std::cout << "There is a yogert facotory here,from goods facotory. " << std::endl;
		return  new Yogert();
	}
	/*获得口味的类型
	*重写虚函数：将商品口味设为橙味
	*返回相应的商品类型*/
	Abstract_flavor *getGoodsflavor() const override
	{
		std::cout << "There is a orange facotory here,from flavor facotory. " << std::endl;
		return new Orange();
	}
};



/******************************************************************/
/*********************bridge 租用成套的东西*************************/
/******************************************************************/
/*抽象类器材：
*描述可以租用的所有器材
*为所有可以租用的器材的父类
*/
class Abstruct_equipment : public DPObject
{
public:
	/*析构函数
	*释放类的实例和类中预定义的数据和变量
	*/
	virtual ~Abstruct_equipment() {}
	/*租用操作
	*用于定义可以进行的租用操作
	*返回将要进行的操作
	*/
	virtual std::string renting() const = 0;
};

/*雪杖类
*继承器材父类:对杖进行租赁操作
*/
class Sticks : public Abstruct_equipment
{
public:
	/*租用操作
	*重写父类中的rent 函数租用雪杖
	*/
	std::string renting() const override
	{
		return "The sticks are equipment.\n";
	}
};

/*滑板类
*继承器材父类：完成对板的租赁操作
*/
class Board : public Abstruct_equipment
{
public:
	/*租用操作
	*重写父类中的rent 函数租用板
	*/
	std::string renting() const override
	{
		return "The  board is a equipment.\n";
	}
};

/*Suit 定义了两个类之间的接口
它维护对实现对象的引用
并将所有实际工作委托给此对象。*/
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

/*Extend_suit 对两个类之间的操作进行了相应的扩展
*对应手杖和板的匹配操作
*/
class Extend_suit : public Suit 
{
public:

	Extend_suit(Abstruct_equipment* equipment) : Suit(equipment) {}

	std::string getTogether() const override
	{
		return  this->equipment_->renting() +"The board and the sticks is a pair.Please take away them together!\n"+ "It costs 100 yuan.\n";
	}

};




/************************************************************************
*							ShoppingMall模块							*
*************************************************************************/


class ShoppingManager : public  CommandReceiver
{

private:
	/*构造函数
	* 构造函数为private，用于实现单例，tag为"shop"
	* @return void
	*/
	ShoppingManager() : CommandReceiver("shop") {}

	//创建购物列表
	std::vector<Shopping*> ShoppingList;

	/*用户租用器材
	* 调用suit.Together方法，将器材配对
	* @return void
	*/
	void Client_equipment(const Suit& suit)
	{
		std::cout << suit.getTogether();
	}

	/*用户购买物品
	* @param factory 调用Get_goods方法通过抽象工厂产生产品
	* @return void
	*/
	void Client_goods(const Get_goods &factory)
	{
		const Abstract_goods *product_a = factory.getGoodsType();
		//通过抽象工厂创建具体的物品
		const Abstract_flavor *product_b = factory.getGoodsflavor();
		//通过抽象工厂创建具体的口味
		std::cout << product_b->selectflavor() << "\n";
		std::cout << product_b->describeGoods(*product_a) << "\n";
		delete product_a;
		delete product_b;
	}
protected:

	/*用户可输入指令
	*根据用户的需要创建相应的对象并完成
	* @param op 用户将进行租/买服务
	* @param obj 用户将要获得的具体对象
	* @return void
	*/
	void ClientOption(std::string op, std::string obj)
	{
		//判断是否为buy 的指令
		if (op == "buy")
		{
			if (obj == "AppleJuice")//用户选择
			{
				Get_apple_juice *objAppleJuice = new Get_apple_juice();//创建果汁的工厂和苹果味的工厂
				std::cout << "Client:I'd like some apple juice.\n";//检验创建是否成功
				Client_goods(*objAppleJuice);//创造客户需要的相应的对象
				delete objAppleJuice;
			}
			else if (obj == "OrangeJuice")//用户选择
			{
				Get_orange_juice*objOrangeJuice = new Get_orange_juice();//创建果汁的工厂和橙子味的工厂
				std::cout << "Client:I'd like some orange juice.\n";//检验创建是否成功
				Client_goods(*objOrangeJuice);//创造客户需要的相应的对象
				delete objOrangeJuice;
			}
			else if (obj == "AppleYogert")//用户选择
			{
				Get_apple_yogert*objAppleYogert = new Get_apple_yogert();//创造酸奶工厂和苹果味的工厂
				std::cout << "Client:I'd like some apple yougert.\n";//检验创建是否成功
				Client_goods(*objAppleYogert);//创造客户需要的相应的对象
				delete objAppleYogert;
			}
			else if (obj == "OrangeYogert")//用户选择
			{
				Get_orange_yogert*objOrangeYogert = new Get_orange_yogert();//创造酸奶工厂和橙味工厂
				std::cout << "Client:I'd like some orange yogert.\n";//检验创建是否成功
				Client_goods(*objOrangeYogert);//创造客户需要的相应的对象
				delete objOrangeYogert;
			}
			else if (obj == "AppleCandies")//用户选择
			{
				Get_apple_candies*objAppleCandies = new Get_apple_candies();//创建糖果工厂和苹果味工厂
				std::cout << "Client:I'd like some apple candies.\n";//检验创建是否成功
				Client_goods(*objAppleCandies);//创造客户需要的相应的对象
				delete objAppleCandies;
			}
			else if (obj == "OrangeCandies")
			{
				Get_orange_candies*objOrangeCandies = new Get_orange_candies();//创建糖果工厂和橙味工厂
				std::cout << "Client:I'd like some orange candies.\n";//检验创建是否成功
				Client_goods(*objOrangeCandies);//创造客户需要的相应的对象
				delete objOrangeCandies;
			}

			else
			{
				std::cout << "Wrong Input,Please input again!" << std::endl;//未检测的命令报错并提醒重新输入
			}
		}

		else if (op == "rent")//如果将要进行的操作为租赁的操作
		{
			if (obj == "sticks")//识别相应的指令
			{
				Abstruct_equipment*equipment = new Sticks;//从抽象工厂创造对象
				Suit* suit = new Extend_suit(equipment);//调用suit 方法将其需要的东西进行配对
				Client_equipment(*suit);//输出相应的配对信息
				delete equipment;
				delete suit;
			}
			else if (obj == "board")
			{
				Abstruct_equipment* equipment = new Board;    //从抽象工厂创造对象
				Suit *suit = new Extend_suit(equipment);//调用suit 方法将其需要的东西进行配对
				Client_equipment(*suit);//输出相应的配对信息
				delete equipment;
				delete suit;
			}
			else
			{
				std::cout << "Wrong Input,Please input again!" << std::endl;//错误输入提示并提醒重新输入
			}
		}


	}

	/*执行指令
	* 重载父类执行指令的纯虚函数，根据输入的命令执行相应操作
	* @param cmd 用户输入的指令内容
	* @return bool 指令格式是否正确
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);//对命令进行切割
		removeBlank(cmd);
		//如果tag 为buy
		if (subCmd == "buy")
		{
			if (cmd == "AppleJuice")//tag ="AppleJuice" 对应相应的用户操作
			{
				ClientOption("buy", "AppleJuice");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "OrangeJuice")//tag ="OrangeJuicee" 对应相应的用户操作
			{
				ClientOption("buy", "OrangeJuice");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "AppleYogert")//tag ="AppleYogert" 对应相应的用户操作
			{
				ClientOption("buy", "AppleYogert");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "OrangeYogert")//tag ="OrangeYogert" 对应相应的用户操作
			{
				ClientOption("buy", "OrangeYogert");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "AppleCandies")//tag ="AppleCandies" 对应相应的用户操作
			{
				ClientOption("buy", "AppleCandies");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "OrangeCandies")//tag ="OrangeCandies" 对应相应的用户操作
			{
				ClientOption("buy", "OrangeCandies");
				std::cout << std::endl;
				return true;
			}
			return false;
		}
		if (subCmd == "rent")//如果tag 为"rent"
		{
			if (cmd == "sticks")//tag="sticks" 对应对应相应的用户操作
			{
				ClientOption("rent", "sticks");
				return true;
			}
			if (cmd == "board")//tag="board" 对应相应的用户操作
			{
				ClientOption("rent", "board");
				return true;
			}
		}



		return false;
	}
public:
	//标记复制构造函数为删除，用于实现单例
	ShoppingManager(const ShoppingManager&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	ShoppingManager& operator=(const ShoppingManager&) = delete;

	/*获取主接收器引用
	* 获取全局唯一主接收器的实例的引用，用于实现单例。
	* @return MainReciver& 主接收器的引用
	*/
	static ShoppingManager& getInstance()
	{
		static ShoppingManager reciver;
		return reciver;
	}
	/*打印可用指令
	* 重载父类虚函数，根据level打印对应格式的指令，以及可用子指令
	* @param level 当前Reciver在Reciver树中的层级
	* @return void
	*/
	virtual void printHelp(int level)
	{
		CommandReceiver::printHelp(level);
		level++;								//调用父类的默认printHelp函数，递归输出当前及子接收器的tag
		std::string head(level * 3, '-');		//将子指令显示到下一层
		std::cout << head + "buy" << std::endl;		//输出第一层子命令
		std::cout << head + "---" + "AppleJuice" << std::endl;		//输出第二层子命令						
		std::cout << head + "---" + "AppleYogert" << std::endl;		//输出第二层子命令
		std::cout << head + "---" + "AppleCandies" << std::endl;		//输出第二层子命令
		std::cout << head + "---" + "OrangeJuice" << std::endl;		//输出第二层子命令
		std::cout << head + "---" + "OrangeYogert" << std::endl;		//输出第二层子命令
		std::cout << head + "---" + "OrangeCandies" << std::endl;	//输出第二层子命令
		std::cout << head + "rent" << std::endl;					//输出第一层rent 子命令
		std::cout << head + "---" + "sticks" << std::endl;           //输出第二层子命令
		std::cout << head + "---" + "board" << std::endl;			//输出第二层子命令
	}

	/*析构函数
	* 用于防止内存泄露，递归释放shoppingList 中的对象
	*/
	~ShoppingManager()
	{
		for (int i = 0; i < ShoppingList.size(); i++)
		{
			if (ShoppingList[i] != nullptr)
			{
				delete ShoppingList[i];
			}

		}
	}
};


