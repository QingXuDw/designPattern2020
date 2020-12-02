#include <iostream>
#include"BaseClasses.h"
#include"TravelPlan.h"
#include"Flyweight.h"
using namespace std;
/**
 * 状态模式的实现
 */

class Context;//提前声明Context类

/**
 * 载具状态类
 * 定义一个接口以封装与Context的一个特定状态相关的行为
 */

class Vehicle_State : public DPObject
{
	/**
	 * 定义状态行为
	 * @return void
	 */
public:
	virtual void Handle(Context* pContext) = 0;
};
/**
 * 等待状态类
 * 将载具的状态置为等待
 * @return void
 */
class Waiting : public Vehicle_State
{
public:
	virtual void Handle(Context* pContext)
	{
		std::cout << "当前载具为等待状态！" << std::endl;
	}
};
/**
 * 等待状态类
 * 将载具的状态置为等待
 * @return void
 */
class Running : public Vehicle_State
{
public:
	virtual void Handle(Context* pContext)
	{
		std::cout << "当前载具为运行状态！" << std::endl;
	}
};

/**
 * Context类定义客户端感兴趣的接口
 * 维护一个ConcreteState子类的实例，这个实例定义当前状态
 */
class Context
{
public:
	Context(Vehicle_State* pState) : m_pState(pState) {}
	/**
	 * 调用handle操作使用的函数request
	 * @return void
	 */
	void Request()
	{
		if (m_pState)
		{
			m_pState->Handle(this);
		}
	}
	/**
	 * 状态转换
	 * 接收状态类，将此时状态转换为需要转换成的状态
	 * @param pState 需要转换成的状态类
	 * @return void
	 */
	void ChangeState(Vehicle_State* pState)
	{
		m_pState = pState;
	}
private:
	Vehicle_State* m_pState;
};

class Storage {//存储状态用
public:
	int n_state = 0;//初始状态置为0，即等待状态
}storage;


class Vehicle : public CommandReceiver {
private:
	//记录的字符串
	std::string str;
	/*构造函数
	* 构造函数为private，用于实现单例，tag为"Vehicle"
	* @return void
	*/
	Vehicle() : CommandReceiver("vehicle") {}
protected:
	/*执行指令
	* 重载父类执行指令的纯虚函数，根据输入的命令执行相应操作
	* @param cmd 用户输入的指令内容
	* @return bool 指令格式是否正确
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "all") {
			string ord;
			std::cout << "您可以在此操作中添加载具种类（禁止添加两次同种载具。请填写对应编号哦~）" << std::endl;
			std::cout << "1.11路公交车		2.缆车		3.托马斯小火车" << std::endl;
			std::cin >> ord;
			getchar();
			if (ord == "1") {
				Fac.GetFlyWeight("W");//获取W对应的模块，相当于用属性列表给固定部分穿上衣服
				std::cout << "11路公交车已成功加入载具库！" << std::endl;
				std::cout << "当前可供共享的载具种类有:" << Fac.countN() << "种!" << std::endl;
			}
			else if (ord == "2") {
				Fac.GetFlyWeight("C");//获取C对应的模块
				std::cout << "缆车已成功加入载具库！" << std::endl;
				std::cout << "当前可供共享的载具种类有:" << Fac.countN() << "种!" << std::endl;
			}
			else if (ord == "3") {
				Fac.GetFlyWeight("P");
				std::cout << "托马斯小火车已成功加入载具库！" << std::endl;
				std::cout << "当前可供共享的载具种类有:" << Fac.countN() << "种!" << std::endl;
			}
			else {
				cout << "输入指令错误！" << endl;
			}
			return true;
		}
		else if (subCmd == "state") {
			string ord;
			if (storage.n_state == 0)
			{
				std::cout << "当前载具的状态为等待状态；" << std::endl;
			}
			else if (storage.n_state == 1)
			{
				std::cout << "当前载具的状态为运行状态；" << std::endl;
			}
			std::cout << "如果你想让载具状态为运行请按1，置为等待请按0." << std::endl;
			cin >> ord;
			getchar();
			if (ord == "0") {
				Vehicle_State* wait = new Waiting();
				Context* pContext = new Context(wait);
				storage.n_state = 0;//置为等待状态
				pContext->Request();
				delete wait;
				delete pContext;
			}
			else if (ord == "1") {
				Vehicle_State* run = new Running();
				Context* pContext = new Context(run);
				storage.n_state = 1;//置为运行状态
				pContext->Request();
				delete run;
				delete pContext;
			}
			else {
				cout << "输入指令错误！" << endl;
			}
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
		__super::printHelp(level);				//调用父类的默认printHelp函数，递归输出当前及子接收器的tag
		level++;								//将子指令显示到下一层
		std::string head(level * 3, '-');
		std::cout << head + "all" << std::endl;	//输出子指令
		std::cout << head + "state" << std::endl;
	}
public:
	//标记复制构造函数为删除，用于实现单例
	Vehicle(const Vehicle&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	Vehicle& operator=(const Vehicle&) = delete;
	/*获取当前接收器的引用
	* 获取全局唯一当前接收器的实例的引用，用于实现单例。
	* @return Mountain& 当前接收器的引用
	*/
	static Vehicle& getInstance() {
		static Vehicle reciver;
		return reciver;
	}
};
