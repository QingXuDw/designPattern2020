#pragma once
#include <iostream>
// #include <windows.h>
#include "BaseClasses.h"
#include "TravelPlan.h"



/************************************************************************************
*																					*
*							         访问者模式								      *
*																					*
*************************************************************************************/

/*访问者抽象基类
* 项目中其他访问者均继承自此类
*/
class AbstractVisitor:public DPObject
{
public:
	/**
	* 访问冰封鬼窟
	* 用于打印冰封鬼窟探险的模板开局
	* @return void
	*/
	virtual void VisitGhostCave(){
		std::cout<<"*********************************************************************"<<std::endl;
		std::cout<<"****************************** 冰封鬼窟 *****************************"<<std::endl;
		std::cout<<"*********************************************************************"<<std::endl<<std::endl;
		std::cout<<"欢迎来到冰封鬼窟！"<<std::endl<<std::endl<<"探险者，你做好前进的准备了吗？"<<std::endl<<std::endl;
		std::cout<<"———————————————————————————————————"<<std::endl;
	}
	
	/*访问冰雕展览
	* 用于打印参观冰雕展览的模板开局
	* @return void
	*/
	virtual void VisitIceSculptureExhibit() {
		std::cout<<std::endl<<"欢迎参观冰雕展览！"<<std::endl<<std::endl;
		system("pause");
		
	}
};

/*实际访问者类
* 继承抽象访问者类，具体实现访问者行为
*/
class ConcreteVisitor:public AbstractVisitor
{
public:
	//显式定义构造函数使用父类默认构造函数
	ConcreteVisitor():AbstractVisitor(){};

	/*访问冰封鬼窟
	* 重载父类虚函数，打印访问者具体探索冰封鬼窟的行动
	* @return void
	*/
	void VisitGhostCave();

	/*访问冰雕展览
	* 重载父类虚函数，打印访问者具体参观冰雕展览的行动
	* @return void
	*/
	void VisitIceSculptureExhibit(){
		AbstractVisitor::VisitIceSculptureExhibit();
		std::cout<<std::endl<<"参观结束，将继续踏上行程。"<<std::endl<<std::endl;
		system("pause");
	}
};

/*抽象场景类
* 访问者模块中实现的场景均继承该类
*/
class Scene:public DPObject
{
protected:
	/*接收访问者
	* 纯虚函数，实现场景类接受访问者对象的接口
	* @param level 接收的访问者对象
	* @return void
	*/
	virtual void accept(AbstractVisitor* visitor)=0;
	
};

/*冰雕展览类
* 继承抽象场景类
*/
class IceSculptureExhibit:public Scene
{
public:
	/*打印可用指令
	* 重写父类虚函数，实现冰雕展览接受访问者对象的接口
	* @param level 接收的访问者对象
	* @return void
	*/
	void accept(AbstractVisitor* visitor){
		visitor->VisitIceSculptureExhibit();
	}
	
};

/*冰封鬼窟类
* 继承抽象场景类
*/
class GhostCave:public Scene
{
public:
	/*打印可用指令
	* 重写父类虚函数，实现冰封鬼窟接受访问者对象的接口
	* @param level 接收的访问者对象
	* @return void
	*/
    void accept(AbstractVisitor* visitor){
		visitor->VisitGhostCave();
	}
	/*显示装饰
	* 用于展示初始状态冰封鬼窟的装饰
	* @return void
	*/
	virtual void showDecorate(){
        std::cout<< "冰封鬼窟当前的装饰为："<<std::endl<<"冰锥"<<std::endl;
    }
};

/************************************************************************************
*																					*
*							         装饰模式								      *
*				 具体实现装饰冰封鬼窟，以上GhostCave是装饰器类的基类				  *
*																					*
*************************************************************************************/

/*装饰器类
* 抽象装饰器基类，其他实际装饰类均继承于此类
*/
class Decorator:public GhostCave
{
protected:
	/*装饰器构造函数
	* 构造函数需要GhostCave对象作为装饰对象
	* @param mainCave GhostCave对象
	* @return void
	*/
    Decorator(GhostCave* mainCave): cave(mainCave) {} 
	/*显示装饰
	* 重载父类虚函数，用于展示初始状态冰封鬼窟的装饰
	* @return void
	*/
    virtual void showDecorate(){
        cave->showDecorate();
    }
private:
	//私有成员，被装饰对象的指针
    GhostCave* cave;
};
/*装饰冰鬼类
* 继承装饰器类，实现添加冰鬼装饰
*/
class AddGhost:public Decorator
{
public:
	/*构造函数
	* 构造函数需要GhostCave对象作为装饰对象
	* @param mainCave GhostCave对象
	* @return void
	*/
    AddGhost(GhostCave* mainCave): Decorator(mainCave) {} 
	/*显示装饰
	* 重载父类虚函数，用于添加装饰
	* @return void
	*/
    void showDecorate() {
        Decorator::showDecorate();
        std::cout<<"冰鬼"<<std::endl;
    }
};
/*装饰骷髅类
* 继承装饰器类，实现添加骷髅装饰
*/
class AddBone:public Decorator
{
public:
	/*构造函数
	* 构造函数需要GhostCave对象作为装饰对象
	* @param mainCave GhostCave对象
	* @return void
	*/
    AddBone(GhostCave* mainCave): Decorator(mainCave) {} 
	/*显示装饰
	* 重载父类虚函数，用于添加装饰
	* @return void
	*/
    void showDecorate() {
        Decorator::showDecorate();
        std::cout<<"骷髅"<<std::endl;
    }
};

/*冰封鬼窟接收器
* 继承于指令接收器
*/
class GhostCaveReceiver:public CommandReceiver
{
private:
    /*构造函数
	* 构造函数为private，用于实现单例，tag为"cave"
	* @return void
	*/
	GhostCaveReceiver() : CommandReceiver("cave") {}

protected:
	/*执行指令
	* 重载父类执行指令的纯虚函数，根据输入的命令执行相应操作
	* @param cmd 用户输入的指令内容
	* @return bool 指令格式是否正确
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "go") {
			ConcreteVisitor* visitor = new ConcreteVisitor();
			GhostCave* mainCave =new GhostCave();
			mainCave->accept(visitor);
			delete mainCave;
			delete visitor;
			return true;
		}
		return false;
	}
	/*打印可用指令
	* 重载父类虚函数，根据level打印对应格式的指令，以及可用子指令
	* @param level 当前Reciver在Reciver树中的层级
	* @return void
	*/
	virtual void printHelp(int level) {
		CommandReceiver::printHelp(level);				//调用父类的默认printHelp函数，递归输出当前及子接收器的tag
		level++;								//将子指令显示到下一层
		std::string head(level * 3, '-');	
		std::cout << head + "go" << std::endl;	//输出子指令
	}

public:
    //标记复制构造函数为删除，用于实现单例
	GhostCaveReceiver(const GhostCaveReceiver&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	GhostCaveReceiver& operator=(const GhostCaveReceiver&) = delete;
	/*获取冰封鬼窟的引用
	* 获取全局唯一冰封鬼窟的实例的引用，用于实现单例。
	* @return TestSpot& 冰封鬼窟的引用
	*/
	static GhostCaveReceiver& getInstance() {
		static GhostCaveReceiver instance;
		return instance;
	}
};
/*冰封洞窟计划工厂
* 继承于抽象计划工厂
*/
class CavePlanFactory : public AbstractPlanFactory {
public:
	/*生成路径
	* @return Path* 生成的路径
	*/
	Path* makePath() {
		Path* path = new Path();
		path->vehicle = "car";
		return path;
	}
	/*生成描述
	* @return Path* 生成的描述
	*/
	Description* makeDescription() {
		Description* des = new Description();
		des->content = "冰封鬼窟实现了装饰模式和访问者模式，具体代码见VisitorClasses.h";
		return des;
	}
	/*生成目标地点
	* @return Path* 生成的目标地点
	*/
	Spot* makeSpot() {
		Spot& spot = GhostCaveReceiver::getInstance();
		return &spot;
	}
};

/*展览接收器
* 继承于指令接收器，实现参观冰雕展览
*/
class ExhibitReceiver:public CommandReceiver
{
private:
    /*构造函数
	* 构造函数为private，用于实现单例，tag为"exhibit"
	* @return void
	*/
	ExhibitReceiver() : CommandReceiver("exhibit") {}

protected:
	/*执行指令
	* 重载父类执行指令的纯虚函数，根据输入的命令执行相应操作
	* @param cmd 用户输入的指令内容
	* @return bool 指令格式是否正确
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "go") {
			AbstractVisitor* visitor = new ConcreteVisitor();
			IceSculptureExhibit* mainExhibit =new IceSculptureExhibit();
			mainExhibit->accept(visitor);

			delete visitor;
			delete mainExhibit;
			return true;
		}
		return false;
	}
	/*打印可用指令
	* 重载父类虚函数，根据level打印对应格式的指令，以及可用子指令
	* @param level 当前Reciver在Reciver树中的层级
	* @return void
	*/
	virtual void printHelp(int level) {
		CommandReceiver::printHelp(level);				//调用父类的默认printHelp函数，递归输出当前及子接收器的tag
		level++;								//将子指令显示到下一层
		std::string head(level * 3, '-');	
		std::cout << head + "go" << std::endl;	//输出子指令
	}
public:
    //标记复制构造函数为删除，用于实现单例
	ExhibitReceiver(const ExhibitReceiver&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	ExhibitReceiver& operator=(const ExhibitReceiver&) = delete;
	/*获取引用
	* 获取全局唯一冰雕展览的实例的引用，用于实现单例。
	* @return TestSpot& 冰雕展览的引用
	*/
	static ExhibitReceiver& getInstance() {
		static ExhibitReceiver instance;
		return instance;
	}
};
/*冰雕展览计划工厂
* 继承于抽象计划工厂
*/
class ExhibitPlanFactory : public AbstractPlanFactory {
public:
	/*生成路径
	* @return Path* 生成的路径
	*/
	Path* makePath() {
		Path* path = new Path();
		path->vehicle = "car";
		return path;
	}
	/*生成描述
	* @return Path* 生成的描述
	*/
	Description* makeDescription() {
		Description* des = new Description();
		des->content = "冰雕展览";
		return des;
	}
	/*生成目标地点
	* @return Path* 生成的目标地点
	*/
	Spot* makeSpot() {
		Spot& spot = ExhibitReceiver::getInstance();
		return &spot;
	}
};


/*装饰器接收器
* 继承于指令接收器，实现对冰封鬼窟的装饰
*/
class DecoratorReceiver:public CommandReceiver
{
private:
    /*构造函数
	* 构造函数为private，用于实现单例，tag为"decorate"
	* @return void
	*/
	DecoratorReceiver() : CommandReceiver("decorate") {
		mainCave=new GhostCave();
		if(mainCave==nullptr){
			std::cout<<"new GhostCave failed"<<std::endl;
		}
	}
	//装饰中使用的冰封鬼窟的唯一实例的指针
	GhostCave* mainCave=nullptr;

protected:
	/*执行指令
	* 重载父类执行指令的纯虚函数，指令正确时进入装饰模块
	* @param cmd 用户输入的指令内容
	* @return bool 指令格式是否正确
	*/
	bool executeCommand(std::string cmd) {
		if(cmd!=""){
			return false;
		}
		
		std::cout<<"*********************************************************************"<<std::endl;
		std::cout<<"************************** 冰封鬼窟装饰模块 *************************"<<std::endl;
		std::cout<<"*********************************************************************"<<std::endl<<std::endl;
		int order;
		while(1){
			if(state==0){
				std::cout<<"请输入指令编号以继续：1、结束并返回  2、显示当前装饰  3、添加冰鬼  4、添加骷髅"<<std::endl;
				std::cout<<">";
				if(std::cin>>order){
					std::cin.get();
					if(order==1){
						std::cout<<"已返回"<<std::endl<<std::endl;
						break;
					}
					if(order==2){
						mainCave->showDecorate();
						std::cout<<std::endl;
						continue;
					}
					if(order==3){
						mainCave=new AddGhost(mainCave);
						std::cout<<"装饰成功"<<std::endl<<std::endl;
						state=1;
						continue;
					}
					if(order==4){
						mainCave=new AddBone(mainCave);
						std::cout<<"装饰成功"<<std::endl<<std::endl;
						state=2;
						continue;
					}
					std::cout<<"无效指令请检查输入的指令格式"<<std::endl;
				}
				else{
					std::cout<<"无效指令请检查输入的指令格式"<<std::endl;
					std::cin.clear();                     //清理cin错误标记
					std::string tmpbuf;                   //帮助读取掉输入的无效行
					getline(std::cin,tmpbuf);
				}
			}
			if(state==1){
				std::cout<<"请输入指令编号以继续：1、结束并返回  2、显示当前装饰  3、添加骷髅"<<std::endl;
				std::cout<<">";
				if(std::cin>>order){
					std::cin.get();
					if(order==1){
						std::cout<<"已返回"<<std::endl<<std::endl;
						break;
					}
					if(order==2){
						mainCave->showDecorate();
						std::cout<<std::endl;
						continue;
					}
					if(order==3){
						mainCave=new AddBone(mainCave);
						std::cout<<"装饰成功"<<std::endl<<std::endl;
						state=3;
						continue;
					}
					std::cout<<"无效指令请检查输入的指令格式"<<std::endl;//其他数字的情况
				}
				else{
					std::cout<<"无效指令请检查输入的指令格式"<<std::endl;
					std::cin.clear();                     //清理cin错误标记
					std::string tmpbuf;                   //帮助读取掉输入的无效行
					getline(std::cin,tmpbuf);
				}
			}
			if(state==2){
				std::cout<<"请输入指令编号以继续：1、结束并返回  2、显示当前装饰  3、添加冰鬼"<<std::endl;
				std::cout<<">";
				if(std::cin>>order){
					std::cin.get();
					if(order==1){
						std::cout<<"已返回"<<std::endl<<std::endl;
						break;
					}
					if(order==2){
						mainCave->showDecorate();
						std::cout<<std::endl;
						continue;
					}
					if(order==3){
						mainCave=new AddGhost(mainCave);
						std::cout<<"装饰成功"<<std::endl<<std::endl;
						state=3;
						continue;
					}
					std::cout<<"无效指令请检查输入的指令格式"<<std::endl;
				}
				else{
					std::cout<<"无效指令请检查输入的指令格式"<<std::endl;
					std::cin.clear();                     //清理cin错误标记
					std::string tmpbuf;                   //帮助读取掉输入的无效行
					getline(std::cin,tmpbuf);
				}
			}
			if(state==3){
				std::cout<<"请输入指令编号以继续：1、结束并返回  2、显示当前装饰"<<std::endl;
				std::cout<<">";
				if(std::cin>>order){
					std::cin.get();
					if(order==1){
						std::cout<<"已返回"<<std::endl<<std::endl;
						break;
					}
					if(order==2){
						mainCave->showDecorate();
						std::cout<<std::endl;
						continue;
					}
					std::cout<<"无效指令请检查输入的指令格式"<<std::endl;
				}
				else{
					std::cout<<"无效指令请检查输入的指令格式"<<std::endl;
					std::cin.clear();                     //清理cin错误标记
					std::string tmpbuf;                   //帮助读取掉输入的无效行
					getline(std::cin,tmpbuf);
				}
			}
			std::cout<<std::endl;
		}
		return true;
	}
	/*打印可用指令
	* 重载父类虚函数，根据level打印对应格式的指令，以及可用子指令
	* @param level 当前Reciver在Reciver树中的层级
	* @return void
	*/
	virtual void printHelp(int level) {
		CommandReceiver::printHelp(level);				//调用父类的默认printHelp函数，递归输出当前及子接收器的tag
		level++;								//将子指令显示到下一层
		std::string head(level * 3, '-');	
		//std::std::cout << head + "go" << std::std::endl;	//输出子指令
	}

public:
	//用于判断当前装饰的状态
	int state = 0;
    //标记复制构造函数为删除，用于实现单例
	DecoratorReceiver(const DecoratorReceiver&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	DecoratorReceiver& operator=(const DecoratorReceiver&) = delete;
	/*获取引用
	* 获取全局唯一装饰器的实例的引用，用于实现单例。
	* @return TestSpot& 装饰器的引用
	*/
	static DecoratorReceiver& getInstance() {
		static DecoratorReceiver instance;
		return instance;
	}

	//析构函数
	~DecoratorReceiver(){
		delete mainCave;
	}
};

void ConcreteVisitor:: VisitGhostCave(){
		AbstractVisitor::VisitGhostCave();
		int currentState=DecoratorReceiver::getInstance().state;//取得鬼窟当前装饰状态
		system("pause");
		std::cout<<"———————————————————————————————————"<<std::endl<<std::endl;
		std::cout<<"穿过狭窄的洞口，映入眼帘的是一个幽暗的洞窟。"<<std::endl<<std::endl;
		std::cout<<"洞窟的四壁皆被寒冰所覆盖，倒挂的冰锥反射着危险的光芒。"<<std::endl<<std::endl;
		std::cout<<"寒风拂过，深处隐约回荡着女子的呜咽。无孔不入的阴冷气息让你不禁打了个寒战。"<<std::endl<<std::endl;
		if(currentState==1||currentState==3){
			std::cout<<"你总感觉有一道影子不时地在某面冰壁中游动而过，但每当你定睛一看，却什么也没发现"<<std::endl<<std::endl;
		}

		std::cout<<"———————————————————————————————————"<<std::endl;
		system("pause");
		std::cout<<"———————————————————————————————————"<<std::endl<<std::endl;
		std::cout<<"尽管有些害怕，但你还是硬着头皮向洞窟深处前进······"<<std::endl<<std::endl;
		std::cout<<"莫名的声音环绕着，周遭的气氛愈发地阴冷，远处深不可见的黑暗就像是在孕育着什么······"<<std::endl<<std::endl;
		std::cout<<"随着不断地前进，空间渐渐开阔。远处传来了哗哗的水声，一条宽直的河流也渐渐出现在视野里。"<<std::endl<<std::endl;

		std::cout<<"———————————————————————————————————"<<std::endl;
		system("pause");
		std::cout<<"———————————————————————————————————"<<std::endl<<std::endl;
		std::cout<<"那河水色泽怪异，辨不出是蓝是绿。"<<std::endl<<std::endl;
		std::cout<<"河上又有一拱桥，通体呈黑，其上又凝结着许多处奇怪的暗红。"<<std::endl<<std::endl;
		std::cout<<"场景愈发诡异，而那拱桥却又是唯一的前路，此刻你已不愿再前进。"<<std::endl<<std::endl;

		std::cout<<"———————————————————————————————————"<<std::endl;
		system("pause");
		std::cout<<"———————————————————————————————————"<<std::endl<<std::endl;
		std::cout<<"突然，后方传来一声低沉的兽吼！"<<std::endl<<std::endl;
		std::cout<<"你转头一撇，那是一个三米多高的人形白毛怪物向你冲来。"<<std::endl<<std::endl;
		std::cout<<"你吓得魂不守舍，连忙向着桥上逃窜过去······"<<std::endl<<std::endl;
		if(currentState > 1){
			std::cout<<"在桥上奔逃时，你突然发现河流中漂流着数不尽的白骨。有些骨手伸出水面，仿佛要把你也拉入那另一个世界······"<<std::endl<<std::endl;
		}

		std::cout<<"———————————————————————————————————"<<std::endl;
		system("pause");
		std::cout<<"———————————————————————————————————"<<std::endl<<std::endl;
		std::cout<<"跨桥而过之后，洞窟却已见尽头，唯有冰壁上一窄洞。"<<std::endl<<std::endl;
		std::cout<<"余光扫过，身后那狰狞的雪怪已经越来越近，你迫不得已地钻入了窄洞中······"<<std::endl<<std::endl;
		std::cout<<"你在窄洞中蜿蜒下滑，刚涌起一丝逃出生天的庆幸，便听到了一声凄厉的尖叫。"<<std::endl<<std::endl;
		std::cout<<"伴着周围冰壁发出的炫目蓝光，你看到面前一个白色的鬼影向你扑来，你吓得闭上了眼睛······"<<std::endl<<std::endl;
		std::cout<<"———————————————————————————————————"<<std::endl;
		system("pause");
		std::cout<<"———————————————————————————————————"<<std::endl<<std::endl;
		std::cout<<"当你睁开眼睛，已经再次身处娱乐园中······"<<std::endl<<std::endl;
	}