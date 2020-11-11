#pragma once
#include"BaseClasses.h"

#include"Consult.h"
#include"Adapter.h"
//游客中心 （ 咨询--外观模式 / 外币兑换--适配器模式 ）
class TouristCenter : public CommandReceiver {
private:
	/*构造函数
	* 构造函数为private，用于实现单例，tag为"tourist"
	* @return void
	*/
	TouristCenter() : CommandReceiver("tourist") {}

protected:
	bool executeCommand(std::string cmd) {
		std::cout << cmd << std::endl;
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "consult") {
			std::cout << "请选择要咨询的内容（1为游乐项目，2为园区设施，3为饮食住宿， 0为返回）：\n";
			Facade* pFacade = new Facade();
			pFacade->start();
			return true;
		}
		else if (subCmd == "currency") {
			std::cout << "请输入要兑换的货币种类以及数量（以空格分隔, 以\"quit\"结束）：\n";
			Adapter* pAdapter = new Adapter();
			pAdapter->start();
			return true;
		}
		else
			return false;
	}
public:
	//标记复制构造函数为删除，用于实现单例
	TouristCenter(const TouristCenter&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	TouristCenter& operator=(const TouristCenter&) = delete;
	/*获取当前接收器的引用
	* 获取全局唯一当前接收器的实例的引用，用于实现单例。
	* @return PlanManager& 当前接收器的引用
	*/
	static TouristCenter& getInstance() {
		static TouristCenter reciver;
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
		std::cout << head + "consult" << std::endl;						//输出子指令
		std::cout << head + "currency" << std::endl;					//输出子指令

	}
};
