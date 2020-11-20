#pragma once

#include <iostream>
#include"BaseClasses.h"

/**
 * 外币抽象基类
 * 项目中出现的其他指令接受者均继承自此类
 */
class FCurrency : public DPObject
{
public:
	/**
	 * 货币兑换
	 * 接收传入的货币金额num，根据给定toRMB的布尔值决定顺向或逆向转化，输出兑换后相应的货币数量
	 * @param num 货币数量
	 * @param toRMB 是否为转换至RMB
	 * @return float 转换后的数量
	 */
	virtual float exchange(float num, bool toRMB) = 0;
};

/**
 * 美元类
 * 用于管理对美元相关的操作，继承自外币抽象基类
 */
class Dollar :public FCurrency {
public:
	/**
	 * 美元兑换
	 * 接收传入的货币金额num，根据给定toRMB的布尔值决定顺向或逆向转化，输出兑换后相应的货币数量
	 * @param num 货币数量
	 * @param toRMB 是否为转换至RMB
	 * @return float 转换后的数量
	 */
	virtual float exchange(float num, bool toRMB) {
		if (toRMB == true)
			return num * 6.576;
		else
			return num / 6.576;
	}
};

/**
 * 英镑类
 * 用于管理对英镑相关的操作，继承自外币抽象基类
 */
class Pound :public FCurrency {
public:
	/**
	 * 英镑兑换
	 * 接收传入的货币金额num，根据给定toRMB的布尔值决定顺向或逆向转化，输出兑换后相应的货币数量
	 * @param num 货币数量
	 * @param toRMB 是否为转换至RMB
	 * @return float 转换后的数量
	 */
	virtual float exchange(float num, bool toRMB) {
		if (toRMB == true)
			return num * 8.6685;
		else
			return num / 8.6685;
	}
};

/**
 * 日元类
 * 用于管理对日元相关的操作，继承自外币抽象基类
 */
class Yen :public FCurrency {
public:
	/**
	 * 日元兑换
	 * 接收传入的货币金额num，根据给定toRMB的布尔值决定顺向或逆向转化，输出兑换后相应的货币数量
	 * @param num 货币数量
	 * @param toRMB 是否为转换至RMB
	 * @return float 转换后的数量
	 */
	virtual float exchange(float num, bool toRMB) {
	if (toRMB == false)
		return num * 15.9313;
	else
		return num / 15.9313;
}
};