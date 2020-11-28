#pragma once

#include"BaseClasses.h"
#include<string>

/**
 * 过滤器类
 * 包含实现数据处理的过滤器
 */
class Filters : public DPObject {
public:
	/**
	 * 套票类型过滤器
	 * 给定套票编号，过滤得到该套票的游客类型
	 * @param id 套票编号
	 * @return string 套票对应的游客类型
	 */
	std::string Filter_TicketType(std::string id) {
		int status = (int)id[0] - 48;		//将套票编号中关于游客类型的部分由字符串转为整型
		switch (status) {
		case 0:
			return "儿童票";
		case 1:
			return "成人票";
		default:
			return "错误";
		}
	}

	/**
	 * 冰封鬼窟项目内容过滤器
	 * 给定套票编号，过滤得到该套票所选择冰封鬼窟项目的内容编号
	 * @param id 套票编号
	 * @return int 套票对应冰封鬼窟项目的内容编号
	 */
	int Filter_Cave(std::string id) {
		int status = (int)id[1] - 48;		//将套票编号中关于冰封鬼窟的部分由字符串转为整型
		return status;
	}

	/**
	 * 登山项目内容过滤器
	 * 给定套票编号，过滤得到该套票所选择登山项目的内容编号
	 * @param id 套票编号
	 * @return int 套票对应登山项目的内容编号
	 */
	int Filter_Mountain(std::string id) {
		int status = (int)id[2] - 48;	//将套票编号中关于登山的部分由字符串转为整型
		return status;
	}

	/**
	 * 动物园参观项目内容过滤器
	 * 给定套票编号，过滤得到该套票所选择动物园参观项目的内容编号
	 * @param id 套票编号
	 * @return int 套票对应动物园参观项目的内容编号
	 */
	int Filter_Zoo(std::string id) {
		int status = (int)id[3] - 48;	//将套票编号中关于游客动物园参观的部分由字符串转为整型
		return status;
	}
};

/**
 * 管道类
 * 包含实现数据流传输的管道和用户界面的实现
 */
class Pipe : public DPObject{
public:
	/**
	 * 套票检查类
	 * 用于生成对应的用户界面，接收并处理用户的输入，帮助工作人员检查套票类型及内容
	 * @return void
	 */
	void Check() {
		std::string itemID;										//使用此系统的工作人员所属的项目编号
		std::string itemName[] = {"冰封鬼窟", "登山", "动物园"};	//使用此系统的工作人员所属的项目名称
		std::string ticketID;									//所检查的套票编号
		std::string d;			//用于吞没多余输入内容的字符串
		int id = 0;			//使用此系统的工作人员所属的项目编号(整型)
		Filters *p_filter = new Filters();

		std::cout << "  请输入您的项目编号: ";
		while (1) {
			getline(std::cin, itemID);
			if (itemID.length() == 1 && itemID >= "1" && itemID <= "3") {		//若输入的项目编号合法则欢迎并引导工作人员至下一步
				id = (int)itemID[0] - 49;		//由字符串转为整型
				std::cout << "  欢迎你, " << itemName[id] << " 的工作人员！" << std::endl;
				break;				//项目编号获取成功，跳出循环
			}
			else 
				std::cout << "  项目编号错误，请重新输入: ";		//若输入的项目编号不合法则继续循环
		}

		while (1) {
			std::cout << "  请输入游客套票的四位编码(以空格分隔)(以quit退出): ";
			std::cin >> ticketID;
			getline(std::cin, d);			//吞没多余的输入内容
			if (ticketID == "quit") {	//若用户决定退出系统则给予相应提示并跳出循环
				std::cout << "成功退出套票查询!" << std::endl;
				break;
			}
			if (ticketID.length() == 4) {	//若编码格式合格则进行下一步判断
				int status;					//项目内容的编号
				std::string type;				//套票持有者的游客类型
				type = p_filter->Filter_TicketType(ticketID);		//获取到当前套票的游客类型

				if (type == "错误") {		//若输入的类型编码错误则给予相应提示并跳转至下一轮循环
					std::cout << "  编码错误，请重新输入!" << std::endl;
					continue;
				}
				switch (id+1) {			//根据使用系统用户人员所属于项目编号的不同调用不同的方法
				case 1:
					status = p_filter->Filter_Cave(ticketID);		//使用过滤器得到套票编号中冰封鬼窟的部分
					Content_Cave(type, status);			//根据套票编号中过滤得到的可用内容输出相应信息
					break;
				case 2:
					status = p_filter->Filter_Mountain(ticketID);	//使用过滤器得到套票编号中登山的部分
					Content_Mountain(type, status);		//根据套票编号中过滤得到的可用内容输出相应信息
					break;
				case 3:
					status = p_filter->Filter_Zoo(ticketID);		//使用过滤器得到套票编号中动物园参观的部分
					Content_Zoo(type, status);			//根据套票编号中过滤得到的可用内容输出相应信息
					break;
				}
				
			}
			else				//若编码格式不合格则继续循环
				std::cout << "  格式错误，请重新输入!" << std::endl;
		}
	}

	/**
	 * 冰封鬼窟项目内容说明
	 * 给定冰封鬼窟项目的内容编号，输出包含的内容
	 * @param type 拥有套票的游客类型
	 * @param status 套票对应冰封鬼窟项目的内容编号
	 * @return void
	 */
	void Content_Cave(std::string type, int status) {
		std::cout << "  此位游客购买了" << type << ", ";		//向工作人员输出当前游客套票中与自己所属项目的内容
		switch (status) {
		case 0:
			std::cout << "但未选择本项目。" << std::endl;
			break;
		case 1:
			std::cout << "并选择了本项目， 您可以引导此位游客开始冰封鬼窟项目的游玩！" << std::endl;
			break;
		default:
			std::cout << "但编码错误，请重新输入！" << std::endl;
		}
	}

	/**
	 * 登山项目内容说明
	 * 给定登山项目的内容编号，输出包含的内容
	 * @param type 拥有套票的游客类型
	 * @param status 套票对应登山项目的内容编号
	 * @return void
	 */
	void Content_Mountain(std::string type, int status) {
		std::cout << "  此位游客购买了" << type << ", ";		//向工作人员输出当前游客套票中与自己所属项目的内容
		switch (status) {
		case 0:
			std::cout << "但未选择本项目。" << std::endl;
			break;
		case 1:
			std::cout << "并选择了本项目, 同时选择了初级套餐， 您可以引导此位游客开始体验登山！" << std::endl;
			break;
		case 2:
			std::cout << "并选择了本项目, 同时选择了高级套餐， 您可以引导此位游客开始体验登山！" << std::endl;
			break;
		case 3:
			std::cout << "并选择了本项目, 同时选择了专业套餐， 您可以引导此位游客开始进行登山！" << std::endl;
			break;
		default:
			std::cout << "但编码错误，请重新输入！" << std::endl;
		}
	}

	/**
	 * 动物园参观项目内容说明
	 * 给定动物园参观项目的内容编号，输出包含的内容
	 * @param type 拥有套票的游客类型
	 * @param status 套票对应动物园参观项目的内容编号
	 * @return void
	 */
	void Content_Zoo(std::string type, int status) {
		std::cout << "  此位游客购买了" << type << ", ";		//向工作人员输出当前游客套票中与自己所属项目的内容
		switch (status) {
		case 0:
			std::cout << "但未选择本项目。" << std::endl;
			break;
		case 1:
			std::cout << "并选择了本项目, 同时选择了普通参观， 您可以引导此位游客进入动物园！" << std::endl;
			break;
		case 2:
			std::cout << "并选择了本项目, 同时选择了基础参观+纪念品赠送， 您可以引导此位游客进入动物园！" << std::endl;
			break;
		case 3:
			std::cout << "并选择了本项目, 同时选择了基础参观+主题餐厅就餐， 您可以引导此位游客进入动物园！" << std::endl;
			break;
		default:
			std::cout << "但编码错误，请重新输入！" << std::endl;
		}
	}

};

//套票检票 -- 管道-过滤器模式
class CheckingManager : public CommandReceiver {
private:
	/*构造函数
	* 构造函数为private，用于实现单例，tag为"ticketChecking"
	* @return void
	*/
	CheckingManager() : CommandReceiver("ticketChecking") {}

protected:
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "visitor") {
			std::cout << "请在项目入口向工作人员查询！" << std::endl;
			return true;
		}
		else if (subCmd == "worker") {
			Pipe *worker = new Pipe();
			worker->Check();
			return true;
		}
		else
			return false;
	}
public:
	//标记复制构造函数为删除，用于实现单例
	CheckingManager(const CheckingManager&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	CheckingManager& operator=(const CheckingManager&) = delete;
	/*获取当前接收器的引用
	* 获取全局唯一当前接收器的实例的引用，用于实现单例。
	* @return CheckingManager& 当前接收器的引用
	*/
	static CheckingManager& getInstance() {
		static CheckingManager reciver;
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
		std::cout << head + "visitor" << std::endl;			//输出子指令		
		std::cout << head + "worker" << std::endl;
	}
};