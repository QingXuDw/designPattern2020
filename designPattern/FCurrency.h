#pragma once
#include <string>
#include <iostream>
#include "BaseClasses.h"
using namespace std;

class FCurrency : public DPObject
{
public:
	virtual void exchange(float num) = 0;
};

class Dollar :public FCurrency
{
public:
	virtual void exchange(float num)
	{
		cout << "兑换完成：" << num << " 美元已兑换为 " << 6.576*num << " 人民币" << endl;
	}
};

class Pound :public FCurrency
{
public:
	virtual void exchange(float num)
	{
		cout << "兑换完成：" << num << " 英镑已兑换为 " << 8.6685*num << " 人民币" << endl;
	}
};

class Yen :public FCurrency
{
public:
	virtual void exchange(float num)
	{
		cout << "兑换完成：" << num << " 日元已兑换为 " << 0.0635*num << " 人民币" << endl;
	}
};