#pragma once
#include<string>
#include<vector>
#include<iostream>
/*单根体系的根类
* 项目中出现的其他类均继承自此类，本身为空类
*/
class DPObject {};

/************************************************************************************
*																					*
*							CommandReceiver指令接收器								*
*																					*
*	本模块的各类指令接收器构成一棵多叉树，本项目中多叉树以MainReciver为根节点，由	*
*	MacroCommandReceiver派生的子类为分支节点，由CommandReceiver派生的子类为叶子节点	*
*************************************************************************************/

/*指令接收器抽象基类
* 项目中出现的其他指令接受者均继承自此类
* 必须被重载才能使用的纯虚函数为bool executeCommand(std::string cmd)
*/
class CommandReceiver : public DPObject {
protected:
	/*执行指令
	* 接收并吞没用户输入cmd，根据cmd内容执行相应的操作，内部可用cin
	* @param cmd 用户输入的指令内容
	* @return bool 指令格式是否正确
	*/
	virtual bool executeCommand(std::string cmd) = 0;
	/*移除字符串前空格
	* 接收一个字符串的引用，移除其前部空格，若无多余空格直接返回
	* @param cmd 待处理的字符串
	* @return void
	*/
	void removeBlank(std::string& cmd) {
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] != ' ') {
				cmd = cmd.substr(i);
				return;
			}
		}
	}
	/*指令切片
	* 接收一个字符串的引用，根据空格将指令切为返回值subCmd和输入cmd两部分，若指令为空返回空字符串
	* @param cmd 切片前待切片的字符串/切片后空格后的字符串
	* @return std::string 切片后空格前的支付串
	*/
	std::string sliceCommand(std::string& cmd) {
		std::string subCmd = "";
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] == ' ') {
				subCmd = cmd.substr(0, i);
				cmd = cmd.substr(i);
				return subCmd;
			}
		}
		subCmd = cmd;
		cmd = "";
		return subCmd;
	}
public:
	//标签——当前CommandReceiver的唯一标识符
	std::string tag;
	/*打印可用指令
	* 根据level打印对应格式的指令，默认打印tag
	* @param level 当前Reciver在Reciver树中的层级
	* @return void
	*/
	virtual void printHelp(int level) {
		std::string head(level * 3, '-');
		std::cout << head + tag << std::endl;
	}
	/*处理指令
	* 当前Reciver收到的指令首先进入这里进行处理，默认处理方式是移除指令前空格
	* @param cmd 用户输入的指令内容
	* @return void
	*/
	virtual void handleCommand(std::string cmd) {
		removeBlank(cmd);
		if (!executeCommand(cmd)) {
			std::cout << "无效指令请检查输入的指令格式" << std::endl;
			std::cout << "最后一级有效指令下的可用指令为：" << std::endl;
			printHelp(0);
		}
	}
	/*构造函数
	* 构造函数需要tag作为唯一标识符
	* @param tag_in 标签
	* @return void
	*/
	CommandReceiver(std::string tag_in) {
		tag = tag_in;
	}
};
/*宏指令接收器抽象基类
* 继承于指令接收器抽象基类，内部维护一个vector保存子接收器
*/
class MacroCommandReceiver : public CommandReceiver {
private:
	//子接收器列表
	std::vector<CommandReceiver*> reciverList;
	/*解析子指令
	* 接收子指令中待匹配的tag，根据tag匹配子接收器，并返回指向子接收器的指针
	* @param subCmd 待匹配的标签
	* @return CommandReceiver* 指向子接收器的指针（若无相应子接收器返回nullptr）
	*/
	CommandReceiver* resolveSubCommand(std::string& subCmd) {
		for (std::vector<CommandReceiver*>::iterator i = reciverList.begin(); i != reciverList.end(); i++) {
			if (subCmd == (*i)->tag) {
				return (*i);
			}
		}
		return nullptr;
	}
public:
	/*构造函数
	* 构造函数需要tag作为唯一标识符
	* @param tag_in 标签
	* @return void
	*/
	MacroCommandReceiver(std::string tag_in) : CommandReceiver(tag_in) {};
	/*打印可用指令
	* 根据level打印对应格式的指令，默认先打印tag，再递归调用子接收器的printHelp，类似VLR
	* @param level 当前Reciver在Reciver树中的层级
	* @return void
	*/
	virtual void printHelp(int level) {
		std::string head(level * 3, '-');
		std::cout << head + tag << std::endl;
		level++;
		for (int i = 0; i < reciverList.size(); i++) {
			reciverList[i]->printHelp(level);
		}
	}
	/*添加子接收器
	* 用于维护reciverList，若已存在同tag子接收器则添加失败，否则添加到列表尾
	* @param p_reciver 指向待添加的子接收器的指针
	* @return bool 是否添加成功
	*/
	virtual bool addReciver(CommandReceiver* p_reciver) {
		for (std::vector<CommandReceiver*>::iterator i = reciverList.begin(); i != reciverList.end(); i++) {
			if (tag == (*i)->tag) {
				return false;
			}
		}
		reciverList.push_back(p_reciver);
		return true;
	}
	/*移除子接收器
	* 用于维护reciverList，若已存在同tag子接收器则移除，否则失败
	* @param tag 待移除的子接收器的标签
	* @return bool 是否添加成功
	*/
	virtual bool removeReciver(std::string tag) {
		for (std::vector<CommandReceiver*>::iterator i = reciverList.begin(); i != reciverList.end(); i++) {
			if (tag == (*i)->tag) {
				reciverList.erase(i);
				return true;
			}
		}
		return false;
	}
	/*移除子接收器
	* 用于维护reciverList，若已存在同tag子接收器则移除，否则失败
	* @param p_reciver 指向待移除的子接收器的指针
	* @return bool 是否添加成功
	*/
	virtual bool removeReciver(CommandReceiver* reciver) { return removeReciver(reciver->tag); }
	/*处理指令
	* 当前Reciver收到的指令首先进入这里进行处理，默认处理方式是匹配子接收器，若匹配失败则执行指令
	* @param cmd 用户输入的指令内容
	* @return void
	*/
	virtual void handleCommand(std::string cmd) {
		removeBlank(cmd);
		std::string subCmd = sliceCommand(cmd);
		CommandReceiver* childReciver = resolveSubCommand(subCmd);
		if (childReciver == nullptr) {
			if (!executeCommand(subCmd + cmd)) {
				std::cout << "无效指令请检查输入的指令格式" << std::endl;
				std::cout << "最后一级有效指令下的可用指令为：" << std::endl;
				printHelp(0);
			}
		}
		else {
			childReciver->handleCommand(cmd);
		}
	}
};