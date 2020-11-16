#include <cstring>
#include "BaseClasses.h"
#include "TravelPlan.h"
#include "ShoppingMall.h"
#include "Strategy.h"
#include "State.h"
#include "TouristCenter.h"
#include "VisitorClasses.h"

/*主指令接收器
* 继承于宏指令接收器，是指令接收器多叉树的根节点，负责接收键盘输入并下发
*/
class MainReciver : public MacroCommandReciver {
private:
	//是否继续接收新的输入
	bool toContinue = true;
	/*构造函数
	* 构造函数为private，用于实现单例，tag为""
	* @return void
	*/
	MainReciver() : MacroCommandReciver("") {}

protected:
	/*执行指令
	* 重载父类执行指令的纯虚函数，根据输入的命令执行相应操作
	* @param cmd 用户输入的指令内容
	* @return bool 指令格式是否正确
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);				//切片当前指令
		removeBlank(cmd);									//移除多余空格
		if (subCmd == "quit") {								//匹配子指令
			std::cout << "程序结束" << std::endl;
			toContinue = false;								//结束输入主循环
			return true;									//返回：指令格式正确
		}
		if (subCmd == "help") {
			std::cout << "可用指令列表为：" << std::endl;
			printHelp(0);
			return true;
		}
		return false;
	}
public:
	//标记复制构造函数为删除，用于实现单例
	MainReciver(const MainReciver&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	MainReciver& operator=(const MainReciver&) = delete;
	/*获取主接收器引用
	* 获取全局唯一主接收器的实例的引用，用于实现单例。
	* @return MainReciver& 主接收器的引用
	*/
	static MainReciver& getInstance() {
		static MainReciver reciver;
		return reciver;
	}
	/*运行
	* 按行接收用户输入的指令并处理
	* @return void
	*/
	void run() {
		std::string cmd;
		std::cout << "输入指令 help 查看当前可用指令" << std::endl;
		while (toContinue) {
			std::cout << ">";
			std::getline(std::cin, cmd);
			handleCommand(cmd);
		}
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
		std::cout << head + "quit" << std::endl;	//输出子指令
		std::cout << head + "help" << std::endl;	//输出子指令
	}
};
/*测试地点
* 继承于指令接收器，仅作为代码演示示例无实际用途
*/
class TestSpot : public CommandReciver {
private:
	//记录的字符串
	std::string str;
	/*构造函数
	* 构造函数为private，用于实现单例，tag为"test"
	* @return void
	*/
	TestSpot() : CommandReciver("test") {}
protected:
	/*执行指令
	* 重载父类执行指令的纯虚函数，根据输入的命令执行相应操作
	* @param cmd 用户输入的指令内容
	* @return bool 指令格式是否正确
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "setStr") {
			std::string paramTag1 = sliceCommand(cmd);		//通过切片子指令，获得第一个参数的标签
			removeBlank(cmd);								//移除多余空格
			if (paramTag1 == "-s") {
				str = cmd;
				return true;
			}
			cmd = paramTag1 + " " + cmd;					//将误切割的指令拼回去
		}
		if (subCmd == "getStr") {
			std::cout << "str中存的内容是：" << str << std::endl;
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
		std::cout << head + "setStr -s:待存储的字符串" << std::endl;	//输出子指令
		std::cout << head + "getStr" << std::endl;	//输出子指令
	}
public:
	//标记复制构造函数为删除，用于实现单例
	TestSpot(const TestSpot&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	TestSpot& operator=(const TestSpot&) = delete;
	/*获取当前接收器的引用
	* 获取全局唯一当前接收器的实例的引用，用于实现单例。
	* @return TestSpot& 当前接收器的引用
	*/
	static TestSpot& getInstance() {
		static TestSpot reciver;
		return reciver;
	}
};

/*测试计划工厂
* 继承于抽象计划工厂，仅作为代码演示示例无实际用途
*/
class testPlanFactory : public AbstractPlanFactory {
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
		des->content = "this is a test Plan";
		return des;
	}
	/*生成目标地点
	* @return Path* 生成的目标地点
	*/
	Spot* makeSpot() {
		Spot& spot = TestSpot::getInstance();
		return &spot;
	}
};





/************************************************************************
*							计划管理器模块								*
*************************************************************************/

/*计划管理器
* 继承于指令接收器，负责管理游览计划
*/
class PlanManager : public CommandReciver {
private:
	/*构造函数
	* 构造函数为private，用于实现单例，tag为"plan"
	* @return void
	*/
	PlanManager() : CommandReciver("plan") {}
	//计划列表
	std::vector<Plan*> planList;
	/*创建新计划
	* 根据传进来的工厂引用，创建新的计划并添加至计划列表尾
	* @param factory 目标计划工厂的引用
	* @return void
	*/
	void createPlan(AbstractPlanFactory& factory) {
		Plan* plan = new Plan();
		plan->description = factory.makeDescription();
		plan->spot = factory.makeSpot();
		plan->path = factory.makePath();
		planList.push_back(plan);
		MainReciver::getInstance().addReciver(plan->spot);
	}
	/*获取计划的描述述
	* 获取第pos+1项的计划的描述并返回
	* @param pos 计划在计划列表中的位置
	* @return std::string 描述
	*/
	std::string getDescription(int pos) {
		if (pos >= planList.size() || pos < 0) {
			return "尚未设置该位置的计划";
		}
		return planList[pos]->description->content;
	}
protected:
	/*执行指令
	* 重载父类执行指令的纯虚函数，根据输入的命令执行相应操作
	* @param cmd 用户输入的指令内容
	* @return bool 指令格式是否正确
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "create") {
			if (cmd == "testSpot") {
				testPlanFactory factory;
				createPlan(factory);
				std::cout << "成功创建testSpot，指令为test" << std::endl;
				return true;
			}
			if (cmd == "mountain") {
				MountainPlanFactory factory;
				createPlan(factory);
				std::cout << "成功创建mountain，指令为choose" << std::endl;
				return true;
			}
			return false;
		}
		if (subCmd == "getDescription") {
			std::string paramTag1 = sliceCommand(cmd);		//通过切片子指令，获得第一个参数的标签
			removeBlank(cmd);								//移除多余空格
			if (paramTag1 == "-p") {
				int pos = std::stoi(cmd);
				std::cout << getDescription(pos) << std::endl;
				return true;
			}
			cmd = paramTag1 + " " + cmd;
		}
		return false;
	}
public:
	//标记复制构造函数为删除，用于实现单例
	PlanManager(const PlanManager&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	PlanManager& operator=(const PlanManager&) = delete;
	/*获取当前接收器的引用
	* 获取全局唯一当前接收器的实例的引用，用于实现单例。
	* @return PlanManager& 当前接收器的引用
	*/
	static PlanManager& getInstance() {
		static PlanManager reciver;
		return reciver;
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
		std::cout << head + "create" << std::endl;								//输出子指令
		std::cout << head + "---" + "testSpot" << std::endl;					//输出子指令
		std::cout << head + "---" + "mountain" << std::endl;					//输出子指令
		std::cout << head + "getDescription -p:计划在列表中的位置" << std::endl;//输出子指令
	}
	/*析构函数
	* 用于防止内存泄露，递归释放planList中的对象
	*/
	~PlanManager() {
		for (int i = 0; i < planList.size(); i++)
		{
			if (planList[i] != nullptr) {
				delete planList[i];
			}
		}
	}
};


int main() {
	MainReciver& mainReciver = MainReciver::getInstance();	//获取主接收器的引用
	mainReciver.addReciver(&PlanManager::getInstance());	//添加计划管理器到主接收器下面
	mainReciver.addReciver(&ShoppingManager::getInstance());
	mainReciver.addReciver(&Vehicle::getInstance());
	mainReciver.addReciver(&DecoratorReceiver::getInstance());
	mainReciver.addReciver(&TouristCenter::getInstance());	//添加游客中心到主接收器下面
	mainReciver.run();										//运行
}