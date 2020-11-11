#pragma once
#include "FCurrency.h"

class Adapter : public DPObject
{
public:

	Adapter()
	{
		dollar = new Dollar;
		pound = new Pound;
		yen = new Yen;
	}
	~Adapter()
	{
		delete dollar;
		delete pound;
		delete yen;
	}
public:
	void exchange(string type, float num) {
		if (type == "dollar" || type == "美元")
		{
			dollar->exchange(num);
		}
		else if (type == "pound" || type == "英镑")
		{
			pound->exchange(num);
		}
		else if (type == "yen" || type == "日元")
		{
			yen->exchange(num);
		}
	}
	void start() {
		string type;	//外币类型
		float num;		//外币数量
		while (cin >> type) {
			if (type == "quit") {
				getline(cin, type);
				break;
			}
			cin >> num;
			exchange(type, num);
		}
	}

private:
	FCurrency *dollar;
	FCurrency *pound;
	FCurrency *yen;
};