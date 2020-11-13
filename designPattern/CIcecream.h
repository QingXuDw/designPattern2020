#pragma once
#include <string>
#include <iostream>
#include <map>
#include "BaseClasses.h"

using namespace std;

//购买冰雪冰激凌，prototype
class CIcecream :public DPObject
{
public:
	enum icBallType { 西瓜, 草莓, 芒果, 榴莲, 巧克力 };  //冰激凌球的口味表
	enum icBiscuitType { 南瓜, 黄瓜 };  //冰激凌小饼干的口味表
	map<icBallType, string> mBallMap =
	{ { 西瓜,"西瓜" },{ 草莓,"草莓" },{ 芒果 ,"芒果" },{ 榴莲,"榴莲" },{ 巧克力 ,"巧克力" } }; //用于输出字符串
	map<icBiscuitType, string> mBiscuitMap =
	{ { 南瓜,"南瓜" },{ 黄瓜,"黄瓜" } };

	/**
	* CIcecream初始化函数
	*/
	CIcecream()
	{
	}

	/**
	* CIcecream初始化函数
	* @param icball1 顾客选择的冰激凌球的口味
	* @param icbiscuit1 顾客选择的冰激凌小饼干的口味
	* @param isLarge1 是否选择大号
	*/
	CIcecream(icBallType icball1, icBiscuitType icbiscuit1, bool isLarge1)
	{
		icBall = icball1;
		icBiscuit = icbiscuit1;
		isLarge = isLarge1;
	}

	/**
	* clone函数，返回一份新的与之一样的冰激凌
	*/
	CIcecream clone()
	{
		CIcecream cNewIC(icBall, icBiscuit, isLarge);  //将原型冰激凌的口味与大小传给新冰激凌
		return cNewIC;
	}

	/**
	* 输出冰激凌样式
	*/
	void icType()
	{
		string tsize = "中号";
		if (isLarge) {
			tsize = "大号";
		}
		cout <<"您购买了一个"<< tsize << "带有" << mBiscuitMap[icBiscuit] << "小饼干的" << mBallMap[icBall] << "冰激凌。请享用！" << endl;
	}

private:
	icBallType icBall = 西瓜;  //冰激凌球的口味
	icBiscuitType icBiscuit = 南瓜;  //冰激凌小饼干的口味
	bool isLarge = false;  //是否选择大号
};

class IcecreamManager :public CommandReceiver {
private:
	//记录的字符串
	std::string str;
	/*构造函数
	* 构造函数为private，用于实现单例，tag为"choose"
	* @return void
	*/
	IcecreamManager() : CommandReceiver("icecream") {}
protected:
	/*执行指令
	* 重载父类执行指令的纯虚函数，根据输入的命令执行相应操作
	* @param cmd 用户输入的指令内容
	* @return bool 指令格式是否正确
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		string sorder;  //用户输入的代码
		CIcecream::icBallType oball = CIcecream::icBallType(0);  //默认款的冰激凌
		CIcecream::icBiscuitType obiscuit = CIcecream::icBiscuitType(0);
		bool olarge = false;
		CIcecream nic(oball, obiscuit, olarge);  //nic为正在制作的冰激凌
		cout << "欢迎光临冰雪冰激凌店！" << endl;
		cout << "请选择冰激凌样式：" << endl;
		cout << "冰激凌球：西瓜-0，草莓-1，芒果-2，榴莲-3，巧克力-4" << endl;
		cout << "小饼干：南瓜-0，黄瓜-1" << endl;
		cout << "大小：中份-0，大份-1" << endl;
		cout << "请用三位数字代码表示冰激凌样式，如：芒果冰激凌球+南瓜小饼干+大份的代码为201" << endl;
		cout << "若要复制一个样式相同的冰激凌，请输入代码8" << endl;
		cout << "若要离开冰激凌店，请输入代码9" << endl;
		while (cin >> sorder) {
			if (sorder.length()==3&&sorder[0]>='0'&&sorder[0]<='4'&&sorder[1] >= '0'&&sorder[1] <= '1'&&sorder[2] >= '0'&&sorder[2] <= '1') {  //用户正确输入冰激凌代码
				int iballtype = static_cast<int>(sorder[0]-'0');
				int ibiscuittype = static_cast<int>(sorder[1]-'0');
				nic=CIcecream(CIcecream::icBallType(iballtype), CIcecream::icBiscuitType(ibiscuittype), (bool)sorder[0]);
				nic.icType();
			}
			else if (sorder.length() == 1&&sorder[0]=='9') {  //用户离开冰激凌店
				cout << "欢迎再次光临！" << endl;
				std::string temp;
				getline(cin, temp);
				return true;
			}
			else if (sorder.length() == 1 && sorder[0] == '8') {  //用户要复制冰激凌
				nic = nic.clone();
				nic.icType();
			}
			else {  //用户输入不合法的代码
				cout << "店小二不明白您的意思，请重新输入。" << endl;
			}
		}
		return true;
	}
public:
	//标记复制构造函数为删除，用于实现单例
	IcecreamManager(const IcecreamManager&) = delete;
	//标记拷贝赋值操作符为删除，用于实现单例
	IcecreamManager& operator=(const IcecreamManager&) = delete;
	/*获取当前接收器的引用
	* 获取全局唯一当前接收器的实例的引用，用于实现单例。
	* @return Mountain& 当前接收器的引用
	*/
	static IcecreamManager& getInstance() {
		static IcecreamManager receiver;
		return receiver;
	}
 };

