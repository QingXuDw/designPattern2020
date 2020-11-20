#pragma once

#include<iostream>
#include<queue>
#include"BaseClasses.h"

/**
 * 黑板交互者类
 * 包含可以向黑板提供消息和可以从中读取消息的对象操作
 */
class BBParticipant : public DPObject {
public:
	/**
	 * 写入消息
	 * 用于向消息队列中添加公告内容
	 * @param queue<string> msg 需要进行修改的消息队列
	 * @return void
	 */
	void addNotice(std::queue<std::string > &msg) {
		std::string content;			//消息写入者提供的消息内容字符串
		std::cout << "请输入您需要添加的公告内容(请勿换行)：\n";
		getline(std::cin, content);
		std::cout << "  添加完成！" << std::endl;
		msg.push(content);		//添加消息到队列
	}

	/**
	 * 获取消息
	 * 用于从消息队列中获取消息并遍历输出
	 * @param queue<string> msg 需要进行修改的消息队列
	 * @return void
	 */
	void getNotice(std::queue<std::string > &msg) {
		std::queue<std::string> output = msg;		//复制一份队列
		int len = msg.size();			//获取队列长度
		if (len == 0)			//对于空队列的判断处理
			std::cout << "  抱歉，目前公告栏为空！" << std::endl;
		else {					//对于非空队列则通过不断读取复制队列并弹出的操作遍历输出队列中的消息内容
			for (int i = 0; i < len; i++) {
				std::cout << "  公告" << i + 1 << ": " << output.front() << std::endl;
				output.pop();
			}
			std::cout << "  以上为目前的全部公告！" << std::endl;
		}
	}
};

/**
 * 黑板类
 * 作为黑板模式的基础，存放实现“黑板”的消息队列，同时实现了调用与黑板交互函数的方法
 */
class Blackboard : public DPObject {
public:
	/**
	 * 黑板交互启动
	 * 用于生成对应的用户界面，接收并处理用户的输入，判别用户身份并进行相应的交互操作
	 * @return void
	 */
	void start() {
		std::string c;	//用户键入的咨询命令
		std::string d;	//用于接收多余的字符

		while (1) {		//循环读取命令以实现公告栏读写功能的多次使用
			std::cout << "请输入您的身份（1为工作人员，2为游客，0为返回）：";	//对用户输入命令的提示
			std::cin >> c;
			getline(std::cin, d);
			if (c == "1" ) {
				BBParticipant *worker = new BBParticipant();	//创建游客对象
				worker->addNotice(msg);							//游客对象使用读取黑板方法
			}
			else if (c == "2") {
				BBParticipant *visitor = new BBParticipant();	//创建工作人员对象
				visitor->getNotice(msg);						//工作人员对象使用写入黑板方法
			}
			else if (c == "0") {			//当用户决定退出时跳出循环并给予提示
				std::cout << "  成功退出公告栏！" << std::endl;
				return;
			}
			else							//当命令非法时的提示
				std::cout << "输入有误，请重新输入！\n";
		}
	}

private:
	std::queue<std::string> msg;		//存放黑板内容的消息队列

};