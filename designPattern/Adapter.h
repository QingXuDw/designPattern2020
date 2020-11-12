#pragma once

#include<iostream>
#include<sstream>
#include "FCurrency.h"

/**
 * 适配器类
 * 作为不同货币之间兑换的适配器，将不便使用的接口转换为易用的接口
 */
class Adapter : public DPObject
{
public:
	/**
	 * 适配器类构造函数
	 * 在创建新的构造器对象时分别创建新的外币对象
	 */
	Adapter()
	{
		dollar = new Dollar;
		pound = new Pound;
		yen = new Yen;
	}
	/**
	 * 适配器析构函数
	 * 在对象生命周期结束后分别删除并释放外币对象的空间
	 */
	~Adapter()
	{
		delete dollar;
		delete pound;
		delete yen;
	}
public:
	/**
	 * 接口转换
	 * 接收传入的货币金额num，和当前需要进行的货币兑换操作编号situ
	 * @param num 货币数量
	 * @param situ 兑换操作编号
	 * @return void
	 */
	void exchange(float num, int situ) {
		float mid;		//中间值
		float result;	//结果值
		switch (situ) {	//根据situ的不同以不同方式使用初级接口
		case 44:	//当命令非法时的提示
			cout << "请输入正确的命令！\n";
			break;
		case 0:		//当命令中转换前后货币相同时的提示
		case 11:
		case 22:
		case 33:
			cout << "请选择不同的货币！" << endl;
			break;
		case 1:		//美元->英镑
			mid = dollar->exchange(num, true);
			result = pound->exchange(mid, false);
			cout << "兑换完成：" << num << "美元已兑换为" << result << "英镑" << endl;
			break;
		case 2:		//美元->日元
			mid = dollar->exchange(num, true);
			result = yen->exchange(mid, false);
			cout << "兑换完成：" << num << "美元已兑换为" << result << "日元" << endl;
			break;
		case 3:		//美元->人民币
			result = dollar->exchange(num, true);
			cout << "兑换完成：" << num << "美元已兑换为" << result << "人民币" << endl;
			break;
		case 10:	//英镑->美元
			mid = pound->exchange(num, true);
			result = dollar->exchange(mid, false);
			cout << "兑换完成：" << num << "英镑已兑换为" << result << "美元" << endl;
			break;
		case 12:	//英镑->日元
			mid = pound->exchange(num, true);
			result = yen->exchange(mid, false);
			cout << "兑换完成：" << num << "英镑已兑换为" << result << "日元" << endl;
			break;
		case 13:	//英镑->人民币
			result = pound->exchange(num, true);
			cout << "兑换完成：" << num << "英镑已兑换为" << result << "人民币" << endl;
			break;
		case 20:	//日元->美元
			mid = yen->exchange(num, true);
			result = dollar->exchange(mid, false);
			cout << "兑换完成：" << num << "日元已兑换为" << result << "美元" << endl;
			break;
		case 21:	//日元->英镑
			mid = yen->exchange(num, true);
			result = pound->exchange(mid, false);
			cout << "兑换完成：" << num << "日元已兑换为" << result << "英镑" << endl;
			break;
		case 23:	//日元->人民币
			result = yen->exchange(num, true);
			cout << "兑换完成：" << num << "日元已兑换为" << result << "人民币" << endl;
			break;
		case 30:	//人民币->美元
			result = dollar->exchange(num, false);
			cout << "兑换完成：" << num << "人民币已兑换为" << result << "美元" << endl;
			break;
		case 31:	//人民币->英镑
			result = pound->exchange(num, false);
			cout << "兑换完成：" << num << "人民币已兑换为" << result << "英镑" << endl;
			break;
		case 32:	//人民币->日元
			result = yen->exchange(num, false);
			cout << "兑换完成：" << num << "人民币已兑换为" << result << "日元" << endl;
			break;
		default:
			cout << "请输入正确的命令！\n";
			return;
		}
		return;
	}

	/**
	 * 外币给予编号
	 * 接收传入的货币名称，返回对应的编号以便其他函数的使用
	 * @param string 货币名称
	 * @return int 对应的货币编号
	 */
	int Transform(string c) {
		if (c == "dollar" || c == "美元")		//同时支持中英文名称
			return 0;
		else if (c == "pound" || c == "英镑")
			return 1;
		else if (c == "yen" || c == "日元")
			return 2;
		else if (c == "RMB" || c == "人民币")
			return 3;
		else			//非法名称则返回异常编号
			return 4;
	}

	/**
	 * 货币兑换启动
	 * 用于生成对应的用户界面，接收并处理用户的输入，正确调用相应的函数
	 * @return void
	 */
	void start() {
		string input;		//外币类型
		float num;			//外币数量
		cout << "请输入要兑换的货币种类以及数量:\n";		//对用户输入命令的提示
		cout << "(按照\"货币数量 持有货币 需求货币\"的格式, 以\"quit\"结束)\n";
		cout << "(支持美元、英镑、日元、人民币的相互兑换)" << endl;	
		while (getline(cin,input)) {	//循环读取命令以实现外币兑换功能可多次使用
			if (input == "quit") {		//当用户决定退出时跳出循环并给予提示
				cout << "成功退出货币兑换！" << endl;
				break;
			}
			string from, to;			//转换前后的货币类
			stringstream ss(input);		//将单行命令转化为流
			ss >> num >> from >> to;	//从转化的流中获取命令中的三个参数
			exchange(num, Transform(from)*10+Transform(to));	//将参数按指定格式传递给兑换函数
		}
	}

private:
	FCurrency *dollar;	//美元类对象
	FCurrency *pound;	//英镑类对象
	FCurrency *yen;		//日元类对象
};