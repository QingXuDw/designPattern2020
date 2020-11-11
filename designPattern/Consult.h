#ifndef _CONSULT_H_
#define _CONSULT_H_

#include<iostream>
using namespace std;

class Subsystem1 : public DPObject
{
public:
	Subsystem1() {};
	~Subsystem1() {};

	void Location() {
		cout << "冰封鬼窟位于园区北部" << endl;
	}
};

class Subsystem2 : public DPObject
{
public:
	Subsystem2() {};
	~Subsystem2() {};

	void Location() {
		cout << "登山请前往园区南部" << endl;
	}
};

class Subsystem3 : public DPObject
{
public:
	Subsystem3() {};
	~Subsystem3() {};

	void Location() {
		cout << "卫生间位置请参考园区地图" << endl;
	}
};

class Subsystem4 : public DPObject
{
public:
	Subsystem4() {};
	~Subsystem4() {};

	void Location() {
		cout << "餐厅位于园区西北部" << endl;
	}
};

class Facade : public DPObject
{
public:
	Facade() {
		this->_subsys1 = new Subsystem1();
		this->_subsys2 = new Subsystem2();
		this->_subsys3 = new Subsystem3();
		this->_subsys4 = new Subsystem4();
	}

	void ConsultPlay() {
		this->_subsys1->Location();
		this->_subsys2->Location();
		//this->_subsys3->Location();
		//this->_subsys4->Location();
	}
	void ConsultFacility() {
		this->_subsys3->Location();
	}
	void ConsultEatLive() {
		this->_subsys4->Location();
	}

	void start() {
		int c;
		string d;
		while (cin >> c) {
			getline(cin, d);
			if (cin.fail())  break;
			switch (c) {
			case 1:
				ConsultPlay();
				break;
			case 2:
				ConsultFacility();
				break;
			case 3:
				ConsultEatLive();
				break;
			case 0:
				return;
			default:
				cout << "输入有误，请重新输入！\n";
				break;
			}
		}

	}

private:
	Subsystem1* _subsys1;
	Subsystem2* _subsys2;
	Subsystem3* _subsys3;
	Subsystem4* _subsys4;

	~Facade() {
		delete this->_subsys1;
		delete this->_subsys2;
		delete this->_subsys3;
		delete this->_subsys4;

		this->_subsys1 = NULL;
		this->_subsys2 = NULL;
		this->_subsys3 = NULL;
		this->_subsys4 = NULL;
	}

};

#endif
