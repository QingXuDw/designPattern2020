#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <conio.h>
#include "BaseClasses.h"
#include "TravelPlan.h"

/************************************************************************************
*																					*
*							    事件-总线/空对象模式							     *
*																					*
* EventBus为总线，Skater为订阅者，订阅者从总线处获得定时器的事件分发，并得到可移动信息	*
*                        总线还需要得到并管理订阅者的移动事件                         *
*************************************************************************************/

/*
* 事件-总线模式中的订阅者
* 滑冰者抽象基类，项目中出现的其他滑冰者均继承自此类
* 用于实现滑冰者基本功能，纯虚函数isNull,isName,move必须被重载
*/  
class Skater : public DPObject
{
public:
    /**
	* 判断该对象是否为空对象
	* @return bool 
	*/
    virtual bool isNull() = 0;
    /**
	* 判断传入的姓名是否为该滑冰者对象的姓名
	* @param Name 用户输入的姓名
	* @return bool 
	*/
    virtual bool isName(std::string Name) = 0;
    /**
	* 滑冰者的移动逻辑
    * @param rand 
	* @return void 
	*/
    virtual void move(int rand) = 0;
    /**
	* 输出滑冰者当前的状态描述
	* @return void 
	*/
    virtual void getState() {};
    /**
	* 返回滑冰者的X轴坐标
	* @return int 
	*/
    int getX(){
        return x;
    }
    /**
	* 返回滑冰者的Y轴坐标
	* @return int 
	*/
    int getY(){
        return y;
    }
    /**
	* 设置滑冰者的X轴坐标
    * @param X 要设定的值 
	* @return int 
	*/
    void setX(int X){
        x=X;
    }
    /**
	* 设置滑冰者的Y轴坐标
    * @param X 要设定的值 
	* @return int 
	*/
    void setY(int Y){
        y=Y;
    }

protected:
    //保存X、Y轴坐标的变量
    int x=1,y=1;
};
/*
* 代表用户自己的滑冰者
* 继承于滑冰者抽象基类
*/
class SelfSkater : public Skater
{
private:
    /**
    * 构造函数
	* 构造函数为private，用于实现单例，并设置初始位置
	* @return void
	*/
    SelfSkater() {
        x=2;
        y=2;
    }
    /**
	* 对纯虚函数的实现
    * @param name
	* @return bool
	*/
    bool isName(std::string name){
        return false;
    }

public:
    //标记复制构造函数为删除，用于实现单例
	SelfSkater(const SelfSkater&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	SelfSkater& operator=(const SelfSkater&) = delete;
	/*获取SelfSkater的引用
	* 获取全局唯一的代表系统用户自己的滑冰者的实例，用于实现单例。
	* @return SelfSkater& SelfSkater的引用
	*/
	static SelfSkater& getInstance() {
		static SelfSkater instance;
		return instance;
	}
    /**
	* 实现SelfSkater的位置移动
    * @param rand 该int值表示方向
	* @return void
	*/
    void move(int rand){
        if(rand==0){
            x--;
        }
        if(rand==1){
            x++;
        }
        if(rand==2){
            y--;
        }
        if(rand==3){
            y++;
        }
    }
    /**
	* 非空对象直接返回false
	* @return bool
	*/
    bool isNull(){
        return false;
    }

};
/*
* 代表滑冰场中其他的滑冰者
* 继承于滑冰者抽象基类
*/
class OtherSkater : public Skater
{
private:
    //该滑冰者的姓名
    std::string name;
    //保存该滑冰者当前移动的方向
    int direction;

public:
    /**
    * 构造函数
	* 完成该滑冰者位置、姓名、移动方向的初始化
	* @return void
	*/
    OtherSkater(std::string Name){
        srand((unsigned)time(0)*1001);
        direction=rand()%4;
        name=Name;
        x=2;
        y=2;
    }
    /**
	* 实现OtherSkater的位置移动
    * @param rand 该int值为总线分发给该对象的随机数，用于辅助实现移动逻辑
	* @return void
	*/
    void move(int rand);
    /**
	* 非空对象直接返回false
	* @return bool
	*/
    bool isNull(){
        return false;
    }
    /**
	* 判断传入的姓名是否为该对象的姓名
    * @param name
	* @return bool
	*/
    bool isName(std::string Name){
        if(name==Name){
            return true;
        }
        else{
            return false;
        }
    }
    /**
	* 输出滑冰者当前的位置描述
	* @return void 
	*/
    void getState(){
        std::cout<<name<<"当前的位置为:（"<<getX()<<","<<getY()<<"）"<<std::endl;
        std::cout<<"（向下为X正轴方向，向右为y正轴方向）"<<std::endl;
    }
};
/*
* 空的滑冰者类，用于实现空对象模式
* 继承于滑冰者抽象基类
*/
class NullSkater : public Skater
{
private:
    /**
	* 纯虚函数的空实现
    * @param rand 
	* @return void
	*/
    void move(int rand) {}

public:
    /**
	* 空对象直接返回true
	* @return bool
	*/
    bool isNull(){
        return true;
    }
    /**
	* 空对象直接返回true，用于searchFriend中无条件匹配
	* @return bool
	*/
    bool isName(std::string Name){
        return true;
    }
    /**
	* 输出对该空对象的描述
	* @return void
	*/
    void getState(){
        std::cout<<"场内不存在叫这个名字的游客！"<<std::endl;
    }
};

/*
* 事件-总线模式中的总线
* 用于实现整个滑冰场的事件分发以及，并集中处理与滑冰者(订阅者)之间的消息传递
*/   
class EventBus : public DPObject
{
private:
    /*构造函数
	* 构造函数为private，用于实现单例，并构造初始滑冰者对象
	* @return void
	*/
	EventBus() {
        initFeild();
        isAutoRunning=false;  //初始化非运行状态
        isRunning=false;
        //添加两个初始滑冰者
        skaters[0]= new OtherSkater("张光昕");
        if(skaters[0]==nullptr){
            std::cout<<"new OtherSkater failed in EveventBus"<<std::endl;
            isAutoRunning=true;
            return;
        }
        skaters[0]->setX(10);
        skaters[0]->setY(15);
        skaters[1]= new OtherSkater("薛嘉宁");
        if(skaters[1]==nullptr){
            std::cout<<"new OtherSkater failed in EveventBus"<<std::endl;
            isAutoRunning=true;
            return;
        }
        skaters[1]->setX(18);
        skaters[1]->setY(70);
        skaters[2]= new NullSkater();
        if(skaters[2]==nullptr){
            std::cout<<"new NullSkater failed in EveventBus"<<std::endl;
            isAutoRunning=true;
            return;
        }
    };
    /**
	* 用于初始化滑冰场
	* @return void
	*/
    void initFeild(){
        int i=0,j=0;
        for(j=0;j<90;j++){
            field[i][j]='#';
        }
        for(i=1;i<23;i++){
            j=0;
            field[i][j]='#';
            for(j=1;j<89;j++){
                field[i][j]=' ';
            }
            field[i][j]='#';
        }
        for(j=0;j<90;j++){
            field[i][j]='#';
        }
    }
    /**
	* 打印当前的滑冰场地
	* @return void
	*/
    void printFeild(){
        for(int i=0;i<24;i++){
            for(int j=0;j<90;j++){
                std::cout<<field[i][j];
            }
            std::cout<<std::endl;
        }
    }
    
    /**
	* 通知所有滑冰者，完成定时器事件分发
	* @return void
	*/
    void notifyAll(){
        srand((unsigned)time(0)*1001);
        for(int i=0;i<cnt;i++){
            skaters[i]->move(rand());
        }
    }
    //保存滑冰场的二维数组
    char field[24][90];
    //保存滑冰者对象指针的数组
    Skater* skaters[15];
    //滑冰者的数量
    int cnt=2;           

public:
    /**
	* 析构函数
	* 释放所有的滑冰者对象
	* @return void
	*/
    ~EventBus(){
        for(int i=0;i<=cnt;i++){
            delete skaters[i];
        }
    }
    //标记复制构造函数为删除，用于实现单例
	EventBus(const EventBus&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	EventBus& operator=(const EventBus&) = delete;
	/*获取EventBus的引用
	* 获取全局唯一总线的实例的引用，用于实现单例。
	* @return EventBus& 滑冰场的引用
	*/
	static EventBus& getInstance() {
		static EventBus instance;
		return instance;
	}

    //保存EventBus是否自动运行的状态值，用于控制定时器事件线程的停止
    bool isAutoRunning;
    //保存用户自己是否移动的状态，用于切换自动/主动运行状态
    bool isRunning;

    /**
	* 返回当前滑冰者的数量
	* @return int
	*/
    int getCnt(){
        return cnt;
    }
    
    /**
	* 完成定时器事件分发，通知所有滑冰者以实现滑冰场状态的更新
	* @return void
	*/
    void update(){
        for(int i=2;i<22;i++){
            for(int j=2;j<88;j++){
                field[i][j]=' ';
            }
        }
        for(int i=0;i<cnt;i++){
            field[skaters[i]->getX()][skaters[i]->getY()]='X';
        }
        SelfSkater& player=SelfSkater::getInstance();
        field[player.getX()][player.getY()]='O';

        notifyAll();
    }
    /**
    * 得到可移动方向
	* 实现查看各滑冰者可移动方向的功能，滑冰者调用该函数获取可移动信息
    * @param x @param y  要查看可移动信息的滑冰者坐标 
	* @return bool* 可移动方向bool值的数组
	*/
    bool* getMovableDir(int x,int y){
        SelfSkater& player=SelfSkater::getInstance();
        bool* dir =new bool[4];                //上、下、左、右
        if(dir==nullptr){
            std::cout<<"new dir failed: in EventBus::getMovableDir"<<std::endl;
            return dir;
        }
        for(int i=0;i<4;i++){
            dir[i]=true;
        }
        //判断人
        int dx=player.getX();
        int dy=player.getY();
        for(int i=0;i<cnt+1;i++){
            if(dx-x>=-2&&dx-x<=2&&dy-y>=-2&&dy-y<=2){
                if(dx==x){
                    if(dy==y+1||dy==y+2){
                        dir[3]=false;
                    }
                    if(dy==y-1||dy==y-2){
                        dir[2]=false;
                    }
                }
                if(dy==y){
                    if(dx==x+1||dx==x+2){
                        dir[1]=false;
                    }
                    if(dx==x-1||dx==x-2){
                        dir[0]=false;
                    }
                }
                if(dx==x+1&&dy==y-1){  //左下
                    dir[1]=false;
                    dir[2]=false;
                }
                if(dx==x-1&&dy==y-1){  //左上
                    dir[0]=false;
                    dir[2]=false;
                }
                if(dx==x-1&&dy==y+1){  //右上
                    dir[0]=false;
                    dir[3]=false;
                }
                if(dx==x+1&&dy==y+1){  //右下
                    dir[3]=false;
                    dir[1]=false;
                }
            }
            dx=skaters[i]->getX();
            dy=skaters[i]->getY();
        }

        //判断墙
        if(field[x-2][y]=='#'){
            dir[0]=false;
        }
        if(field[x+2][y]=='#'){
            dir[1]=false;
        }
        if(field[x][y-2]=='#'){
            dir[2]=false;
        }
        if(field[x][y+2]=='#'){
            dir[3]=false;
        }
        return dir;
    }
    /**
	* 实现系统用户自己操控SelfSkater滑冰移动的逻辑
	* @return void
	*/
    void play(){
        isRunning=true;      //切换到主动移动状态
        char ch;
        SelfSkater& player=SelfSkater::getInstance();
        bool* dir;

        while(true){
            dir=getMovableDir(player.getX(),player.getY());
            if(dir==nullptr){
                isRunning=false; 
                return;
            }
            std::cout<<"输入w、a、s、d进行移动，其他输入视为停止。O代表自己，X代表其他人。"<<std::endl;
            update();
            printFeild();
            #if WIN32         //判断操作系统
            _getch();
            #elif LINUX
            getch();
            #endif
            ch=getch();
            if(ch=='w'||ch=='W'){
                if(dir[0]){
                    player.move(0);
                }
                system("cls");
                continue;
            }
            if(ch=='s'||ch=='S'){
                if(dir[1]){
                    player.move(1);
                }
                system("cls");
                continue;
            }
            if(ch=='a'||ch=='A'){
                if(dir[2]){
                    player.move(2);
                }
                system("cls");
                continue;
            }
            if(ch=='d'||ch=='D'){
                if(dir[3]){
                    player.move(3);
                }
                system("cls");
                continue;
            }
            break;
        }
        system("cls");
        delete[] dir;
        isRunning=false; 
    }
    /**
	* 实现查找滑冰场中朋友的功能
    * @param fname  要查找的朋友姓名
	* @return void
	*/
    void searchFriend(std::string fname){
        int i;
        for(i=0;i<15;i++){
            if(skaters[i]->isName(fname)){  //遇空对象自动返回
                break;
            }
        }
        skaters[i]->getState();
    }
    /**
	* 实现在滑冰场中加入一个新朋友的功能
    * @param name 新加入的朋友姓名
	* @return void
	*/
    void addSkater(std::string name){
        skaters[cnt+1]=skaters[cnt];    //将空对象放到数组最后
        skaters[cnt]= new OtherSkater(name);
        if(skaters[cnt]==nullptr){
            std::cout<<"new Skater() failed"<<std::endl;
            return;
        }
        //以下将新建的滑冰者对象放置在一个空的滑冰场位置
        SelfSkater& player=SelfSkater::getInstance();
        for(int j=2;j<88;j++){
            int k;
            for(k=0;k<cnt;k++){
                if(skaters[k]->getX()==2&&skaters[k]->getY()==j){
                    break;
                }
            }
            if(k>=cnt&&(player.getX()!=2||player.getY()!=j)){
                skaters[cnt]->setX(2);
                skaters[cnt]->setY(j);
                std::cout<<"邀请成功！"<<std::endl;
                break;
            }
        }
        cnt++;
    }
};


void OtherSkater::move(int rand){
    bool* dir;
    dir=EventBus::getInstance().getMovableDir(x,y); //获得可移动方向
    if(dir==nullptr){
        return;
    }
    if(!dir[0]&&!dir[1]&&!dir[2]&&!dir[3]){  //不可移动直接返回
        return;
    }

    //以下为OtherSkater的移动逻辑
    int ran=rand%10;
    if(ran<6){
        if(direction==0&&dir[0]){
            x--;
            delete[] dir;
            return;
        }
        if(direction==1&&dir[1]){
            x++;
            delete[] dir;
            return;
        }
        if(direction==2&&dir[2]){
            y--;
            delete[] dir;
            return;
        }
        if(direction==3&&dir[3]){
            y++;
            delete[] dir;
            return;
        }
    }
    switch (ran)
    {
    case 6:
        if(dir[0] && direction!=1){
            x--;
            direction=0;
            break;
        }
    case 7:
        if(dir[1] && direction!=0){
            x++;
            direction=1;
            break;
        }
    case 8:
        if(dir[2] && direction!=3){
            y--;
            direction=2;
            break;
        }
    case 9:
        if(dir[3] && direction!=2){
            y++;
            direction=3;
            break;
        }
    default:
        if(dir[3]){
            y++;
            direction=3;
            break;
        }
        if(dir[1]){
            x++;
            direction=1;
            break;
        }
        if(dir[2]){
            y--;
            direction=2;
            break;
        }
        if(dir[0]){
            x--;
            direction=0;
            break;
        }
    }
    delete[] dir;
}

/*滑冰场工厂
* 用于实现滑冰项目主体逻辑并控制滑冰场线程
*/
class SkaterFactory : public DPObject
{
private:
    /*构造函数
	* 构造函数为private，用于实现单例
	* @return void
	*/
	SkaterFactory() {};
    /**
    * 定时器函数
	* 用于产生每秒一次的事件，仅可被run调用产生新线程
	* @return void*
    */
    static void Timer(){
        EventBus& mainSkatingManager =EventBus::getInstance();
        while(mainSkatingManager.isAutoRunning){
            while(mainSkatingManager.isRunning){}
            mainSkatingManager.update();
            std::chrono::milliseconds dura(1000);
            std::this_thread::sleep_for(dura);
        }
    }

public:
    //标记复制构造函数为删除，用于实现单例
	SkaterFactory(const SkaterFactory&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	SkaterFactory& operator=(const SkaterFactory&) = delete;
	/**
	* 获取全局唯一滑冰场工厂的引用，用于实现单例。
	* @return SkaterFactory& 滑冰场工厂的引用
	*/
	static SkaterFactory& getInstance() {
		static SkaterFactory instance;
		return instance;
	}
    /**
	* 用于进入滑冰项目的内部逻辑
	* @return void
	*/
    void run(){
        std::thread timer(Timer);   //创建滑冰场自动刷新线程
        timer.detach();
        //pthread_t id;
        //int ret = pthread_create(&id, nullptr, Timer, nullptr); //创建滑冰场自动刷新线程

        EventBus& mainSkatingManager =EventBus::getInstance();
        if(mainSkatingManager.isAutoRunning==true){   //EventBus构造时创建Skater对象出现问题，直接结束
            std::cout<<"skate exit!"<<std::endl;
            return;
        }
        mainSkatingManager.isAutoRunning=true;
        //滑冰指令逻辑开始
        std::cout<<"*********************************************************************"<<std::endl;
		std::cout<<"****************************** 冰湖滑冰场 ***************************"<<std::endl;
		std::cout<<"*********************************************************************"<<std::endl<<std::endl;
		std::cout<<"欢迎来到冰天雪地滑冰场！"<<std::endl<<"您的两个朋友昕哥和薛大已经在内游玩了，请开始吧！"<<std::endl<<std::endl;

        int order;
        while(1){
            std::cout<<"请输入指令编号以继续："<<std::endl<<
            "1、结束滑冰  2、移动  3、查找场内一个朋友的位置  4、再邀请一个朋友来玩"<<std::endl;
				std::cout<<">";
				if(std::cin>>order){
					std::cin.get();
                    if(order==1){
                        mainSkatingManager.isAutoRunning=false;
						std::cout<<"已返回"<<std::endl<<std::endl;
						break;
					}
					if(order==2){
                        system("cls");
                        mainSkatingManager.play();
                        
						continue;
					}
					if(order==3){
                        std::string name;
                        std::cout<<std::endl<<"请输入要找的朋友姓名：";
                        std::cin>>name;
                        std::cout<<std::endl;
                        mainSkatingManager.searchFriend(name);
                        std::cout<<std::endl;
						continue;
					}
					if(order==4){
                        if(mainSkatingManager.getCnt()>13){
                            std::cout<<std::endl<<"滑冰场已经无法容纳更多游客！"<<std::endl;
                        }
                        else{
                            std::string name;
                            std::cout<<std::endl<<"请输入邀请的朋友姓名：";
                            std::cin>>name;
                            mainSkatingManager.addSkater(name);
                        }
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
    }
};

/*滑冰场接收器
* 继承于指令接收器
*/
class IceSkatingReceiver:public CommandReceiver
{
private:
    /*构造函数
	* 构造函数为private，用于实现单例，tag为"cave"
	* @return void
	*/
	IceSkatingReceiver() : CommandReceiver("skate") {}

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
            SkaterFactory::getInstance().run();

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
	IceSkatingReceiver(const IceSkatingReceiver&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	IceSkatingReceiver& operator=(const IceSkatingReceiver&) = delete;
	/*获取滑冰指令接收器的引用
	* 获取全局唯一实例的引用，用于实现单例。
	* @return IceSkatingReceiver& 滑冰指令接收器的引用
	*/
	static IceSkatingReceiver& getInstance() {
		static IceSkatingReceiver instance;
		return instance;
	}
};
/*滑冰场计划工厂
* 继承于抽象计划工厂
*/
class IceSkatingPlanFactory : public AbstractPlanFactory {
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
		des->content = "滑冰场实现了事件-总线模式和空对象模式，具体代码见IceSkating.h";
		return des;
	}
	/*生成目标地点
	* @return Path* 生成的目标地点
	*/
	Spot* makeSpot() {
		Spot& spot = IceSkatingReceiver::getInstance();
		return &spot;
	}
};