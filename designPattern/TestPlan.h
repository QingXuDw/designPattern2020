#pragma once
#include "BaseClasses.h"
#include "TravelPlan.h"
/*测试地点
* 继承于指令接收器，仅作为代码演示示例无实际用途
*/
class TestSpot : public CommandReceiver {
private:
	//记录的字符串
	std::string str;
	/*构造函数
	* 构造函数为private，用于实现单例，tag为"test"
	* @return void
	*/
	TestSpot() : CommandReceiver("test") {}
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
class TestPlanFactory : public AbstractPlanFactory {
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

