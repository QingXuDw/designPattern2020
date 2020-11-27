#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <conio.h>
#include "BaseClasses.h"
#include "TravelPlan.h"

/************************************************************************************
*																					*
*							    �¼�-����/�ն���ģʽ							     *
*																					*
* EventBusΪ���ߣ�SkaterΪ�����ߣ������ߴ����ߴ���ö�ʱ�����¼��ַ������õ����ƶ���Ϣ	*
*                        ���߻���Ҫ�õ����������ߵ��ƶ��¼�                         *
*************************************************************************************/

/*
* �¼�-����ģʽ�еĶ�����
* �����߳�����࣬��Ŀ�г��ֵ����������߾��̳��Դ���
* ����ʵ�ֻ����߻������ܣ����麯��isNull,isName,move���뱻����
*/  
class Skater : public DPObject
{
public:
    /**
	* �жϸö����Ƿ�Ϊ�ն���
	* @return bool 
	*/
    virtual bool isNull() = 0;
    /**
	* �жϴ���������Ƿ�Ϊ�û����߶��������
	* @param Name �û����������
	* @return bool 
	*/
    virtual bool isName(std::string Name) = 0;
    /**
	* �����ߵ��ƶ��߼�
    * @param rand 
	* @return void 
	*/
    virtual void move(int rand) = 0;
    /**
	* ��������ߵ�ǰ��״̬����
	* @return void 
	*/
    virtual void getState() {};
    /**
	* ���ػ����ߵ�X������
	* @return int 
	*/
    int getX(){
        return x;
    }
    /**
	* ���ػ����ߵ�Y������
	* @return int 
	*/
    int getY(){
        return y;
    }
    /**
	* ���û����ߵ�X������
    * @param X Ҫ�趨��ֵ 
	* @return int 
	*/
    void setX(int X){
        x=X;
    }
    /**
	* ���û����ߵ�Y������
    * @param X Ҫ�趨��ֵ 
	* @return int 
	*/
    void setY(int Y){
        y=Y;
    }

protected:
    //����X��Y������ı���
    int x=1,y=1;
};
/*
* �����û��Լ��Ļ�����
* �̳��ڻ����߳������
*/
class SelfSkater : public Skater
{
private:
    /**
    * ���캯��
	* ���캯��Ϊprivate������ʵ�ֵ����������ó�ʼλ��
	* @return void
	*/
    SelfSkater() {
        x=2;
        y=2;
    }
    /**
	* �Դ��麯����ʵ��
    * @param name
	* @return bool
	*/
    bool isName(std::string name){
        return false;
    }

public:
    //��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	SelfSkater(const SelfSkater&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	SelfSkater& operator=(const SelfSkater&) = delete;
	/*��ȡSelfSkater������
	* ��ȡȫ��Ψһ�Ĵ���ϵͳ�û��Լ��Ļ����ߵ�ʵ��������ʵ�ֵ�����
	* @return SelfSkater& SelfSkater������
	*/
	static SelfSkater& getInstance() {
		static SelfSkater instance;
		return instance;
	}
    /**
	* ʵ��SelfSkater��λ���ƶ�
    * @param rand ��intֵ��ʾ����
	* @return void
	*/
    void move(int rand){
        if(rand==0){
            x--;
        }
        if(rand==1){
            x++;
        }
        if(rand==2){
            y--;
        }
        if(rand==3){
            y++;
        }
    }
    /**
	* �ǿն���ֱ�ӷ���false
	* @return bool
	*/
    bool isNull(){
        return false;
    }

};
/*
* ���������������Ļ�����
* �̳��ڻ����߳������
*/
class OtherSkater : public Skater
{
private:
    //�û����ߵ�����
    std::string name;
    //����û����ߵ�ǰ�ƶ��ķ���
    int direction;

public:
    /**
    * ���캯��
	* ��ɸû�����λ�á��������ƶ�����ĳ�ʼ��
	* @return void
	*/
    OtherSkater(std::string Name){
        srand((unsigned)time(0)*1001);
        direction=rand()%4;
        name=Name;
        x=2;
        y=2;
    }
    /**
	* ʵ��OtherSkater��λ���ƶ�
    * @param rand ��intֵΪ���߷ַ����ö��������������ڸ���ʵ���ƶ��߼�
	* @return void
	*/
    void move(int rand);
    /**
	* �ǿն���ֱ�ӷ���false
	* @return bool
	*/
    bool isNull(){
        return false;
    }
    /**
	* �жϴ���������Ƿ�Ϊ�ö��������
    * @param name
	* @return bool
	*/
    bool isName(std::string Name){
        if(name==Name){
            return true;
        }
        else{
            return false;
        }
    }
    /**
	* ��������ߵ�ǰ��λ������
	* @return void 
	*/
    void getState(){
        std::cout<<name<<"��ǰ��λ��Ϊ:��"<<getX()<<","<<getY()<<"��"<<std::endl;
        std::cout<<"������ΪX���᷽������Ϊy���᷽��"<<std::endl;
    }
};
/*
* �յĻ������࣬����ʵ�ֿն���ģʽ
* �̳��ڻ����߳������
*/
class NullSkater : public Skater
{
private:
    /**
	* ���麯���Ŀ�ʵ��
    * @param rand 
	* @return void
	*/
    void move(int rand) {}

public:
    /**
	* �ն���ֱ�ӷ���true
	* @return bool
	*/
    bool isNull(){
        return true;
    }
    /**
	* �ն���ֱ�ӷ���true������searchFriend��������ƥ��
	* @return bool
	*/
    bool isName(std::string Name){
        return true;
    }
    /**
	* ����Ըÿն��������
	* @return void
	*/
    void getState(){
        std::cout<<"���ڲ����ڽ�������ֵ��οͣ�"<<std::endl;
    }
};

/*
* �¼�-����ģʽ�е�����
* ����ʵ���������������¼��ַ��Լ��������д����뻬����(������)֮�����Ϣ����
*/   
class EventBus : public DPObject
{
private:
    /*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ������������ʼ�����߶���
	* @return void
	*/
	EventBus() {
        initFeild();
        isAutoRunning=false;  //��ʼ��������״̬
        isRunning=false;
        //���������ʼ������
        skaters[0]= new OtherSkater("�Ź��");
        if(skaters[0]==nullptr){
            std::cout<<"new OtherSkater failed in EveventBus"<<std::endl;
            isAutoRunning=true;
            return;
        }
        skaters[0]->setX(10);
        skaters[0]->setY(15);
        skaters[1]= new OtherSkater("Ѧ����");
        if(skaters[1]==nullptr){
            std::cout<<"new OtherSkater failed in EveventBus"<<std::endl;
            isAutoRunning=true;
            return;
        }
        skaters[1]->setX(18);
        skaters[1]->setY(70);
        skaters[2]= new NullSkater();
        if(skaters[2]==nullptr){
            std::cout<<"new NullSkater failed in EveventBus"<<std::endl;
            isAutoRunning=true;
            return;
        }
    };
    /**
	* ���ڳ�ʼ��������
	* @return void
	*/
    void initFeild(){
        int i=0,j=0;
        for(j=0;j<90;j++){
            field[i][j]='#';
        }
        for(i=1;i<23;i++){
            j=0;
            field[i][j]='#';
            for(j=1;j<89;j++){
                field[i][j]=' ';
            }
            field[i][j]='#';
        }
        for(j=0;j<90;j++){
            field[i][j]='#';
        }
    }
    /**
	* ��ӡ��ǰ�Ļ�������
	* @return void
	*/
    void printFeild(){
        for(int i=0;i<24;i++){
            for(int j=0;j<90;j++){
                std::cout<<field[i][j];
            }
            std::cout<<std::endl;
        }
    }
    
    /**
	* ֪ͨ���л����ߣ���ɶ�ʱ���¼��ַ�
	* @return void
	*/
    void notifyAll(){
        srand((unsigned)time(0)*1001);
        for(int i=0;i<cnt;i++){
            skaters[i]->move(rand());
        }
    }
    //���滬�����Ķ�ά����
    char field[24][90];
    //���滬���߶���ָ�������
    Skater* skaters[15];
    //�����ߵ�����
    int cnt=2;           

public:
    /**
	* ��������
	* �ͷ����еĻ����߶���
	* @return void
	*/
    ~EventBus(){
        for(int i=0;i<=cnt;i++){
            delete skaters[i];
        }
    }
    //��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	EventBus(const EventBus&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	EventBus& operator=(const EventBus&) = delete;
	/*��ȡEventBus������
	* ��ȡȫ��Ψһ���ߵ�ʵ�������ã�����ʵ�ֵ�����
	* @return EventBus& ������������
	*/
	static EventBus& getInstance() {
		static EventBus instance;
		return instance;
	}

    //����EventBus�Ƿ��Զ����е�״ֵ̬�����ڿ��ƶ�ʱ���¼��̵߳�ֹͣ
    bool isAutoRunning;
    //�����û��Լ��Ƿ��ƶ���״̬�������л��Զ�/��������״̬
    bool isRunning;

    /**
	* ���ص�ǰ�����ߵ�����
	* @return int
	*/
    int getCnt(){
        return cnt;
    }
    
    /**
	* ��ɶ�ʱ���¼��ַ���֪ͨ���л�������ʵ�ֻ�����״̬�ĸ���
	* @return void
	*/
    void update(){
        for(int i=2;i<22;i++){
            for(int j=2;j<88;j++){
                field[i][j]=' ';
            }
        }
        for(int i=0;i<cnt;i++){
            field[skaters[i]->getX()][skaters[i]->getY()]='X';
        }
        SelfSkater& player=SelfSkater::getInstance();
        field[player.getX()][player.getY()]='O';

        notifyAll();
    }
    /**
    * �õ����ƶ�����
	* ʵ�ֲ鿴�������߿��ƶ�����Ĺ��ܣ������ߵ��øú�����ȡ���ƶ���Ϣ
    * @param x @param y  Ҫ�鿴���ƶ���Ϣ�Ļ��������� 
	* @return bool* ���ƶ�����boolֵ������
	*/
    bool* getMovableDir(int x,int y){
        SelfSkater& player=SelfSkater::getInstance();
        bool* dir =new bool[4];                //�ϡ��¡�����
        if(dir==nullptr){
            std::cout<<"new dir failed: in EventBus::getMovableDir"<<std::endl;
            return dir;
        }
        for(int i=0;i<4;i++){
            dir[i]=true;
        }
        //�ж���
        int dx=player.getX();
        int dy=player.getY();
        for(int i=0;i<cnt+1;i++){
            if(dx-x>=-2&&dx-x<=2&&dy-y>=-2&&dy-y<=2){
                if(dx==x){
                    if(dy==y+1||dy==y+2){
                        dir[3]=false;
                    }
                    if(dy==y-1||dy==y-2){
                        dir[2]=false;
                    }
                }
                if(dy==y){
                    if(dx==x+1||dx==x+2){
                        dir[1]=false;
                    }
                    if(dx==x-1||dx==x-2){
                        dir[0]=false;
                    }
                }
                if(dx==x+1&&dy==y-1){  //����
                    dir[1]=false;
                    dir[2]=false;
                }
                if(dx==x-1&&dy==y-1){  //����
                    dir[0]=false;
                    dir[2]=false;
                }
                if(dx==x-1&&dy==y+1){  //����
                    dir[0]=false;
                    dir[3]=false;
                }
                if(dx==x+1&&dy==y+1){  //����
                    dir[3]=false;
                    dir[1]=false;
                }
            }
            dx=skaters[i]->getX();
            dy=skaters[i]->getY();
        }

        //�ж�ǽ
        if(field[x-2][y]=='#'){
            dir[0]=false;
        }
        if(field[x+2][y]=='#'){
            dir[1]=false;
        }
        if(field[x][y-2]=='#'){
            dir[2]=false;
        }
        if(field[x][y+2]=='#'){
            dir[3]=false;
        }
        return dir;
    }
    /**
	* ʵ��ϵͳ�û��Լ��ٿ�SelfSkater�����ƶ����߼�
	* @return void
	*/
    void play(){
        isRunning=true;      //�л��������ƶ�״̬
        char ch;
        SelfSkater& player=SelfSkater::getInstance();
        bool* dir;

        while(true){
            dir=getMovableDir(player.getX(),player.getY());
            if(dir==nullptr){
                isRunning=false; 
                return;
            }
            std::cout<<"����w��a��s��d�����ƶ�������������Ϊֹͣ��O�����Լ���X���������ˡ�"<<std::endl;
            update();
            printFeild();
            #if WIN32         //�жϲ���ϵͳ
            _getch();
            #elif LINUX
            getch();
            #endif
            ch=getch();
            if(ch=='w'||ch=='W'){
                if(dir[0]){
                    player.move(0);
                }
                system("cls");
                continue;
            }
            if(ch=='s'||ch=='S'){
                if(dir[1]){
                    player.move(1);
                }
                system("cls");
                continue;
            }
            if(ch=='a'||ch=='A'){
                if(dir[2]){
                    player.move(2);
                }
                system("cls");
                continue;
            }
            if(ch=='d'||ch=='D'){
                if(dir[3]){
                    player.move(3);
                }
                system("cls");
                continue;
            }
            break;
        }
        system("cls");
        delete[] dir;
        isRunning=false; 
    }
    /**
	* ʵ�ֲ��һ����������ѵĹ���
    * @param fname  Ҫ���ҵ���������
	* @return void
	*/
    void searchFriend(std::string fname){
        int i;
        for(i=0;i<15;i++){
            if(skaters[i]->isName(fname)){  //���ն����Զ�����
                break;
            }
        }
        skaters[i]->getState();
    }
    /**
	* ʵ���ڻ������м���һ�������ѵĹ���
    * @param name �¼������������
	* @return void
	*/
    void addSkater(std::string name){
        skaters[cnt+1]=skaters[cnt];    //���ն���ŵ��������
        skaters[cnt]= new OtherSkater(name);
        if(skaters[cnt]==nullptr){
            std::cout<<"new Skater() failed"<<std::endl;
            return;
        }
        //���½��½��Ļ����߶��������һ���յĻ�����λ��
        SelfSkater& player=SelfSkater::getInstance();
        for(int j=2;j<88;j++){
            int k;
            for(k=0;k<cnt;k++){
                if(skaters[k]->getX()==2&&skaters[k]->getY()==j){
                    break;
                }
            }
            if(k>=cnt&&(player.getX()!=2||player.getY()!=j)){
                skaters[cnt]->setX(2);
                skaters[cnt]->setY(j);
                std::cout<<"����ɹ���"<<std::endl;
                break;
            }
        }
        cnt++;
    }
};


void OtherSkater::move(int rand){
    bool* dir;
    dir=EventBus::getInstance().getMovableDir(x,y); //��ÿ��ƶ�����
    if(dir==nullptr){
        return;
    }
    if(!dir[0]&&!dir[1]&&!dir[2]&&!dir[3]){  //�����ƶ�ֱ�ӷ���
        return;
    }

    //����ΪOtherSkater���ƶ��߼�
    int ran=rand%10;
    if(ran<6){
        if(direction==0&&dir[0]){
            x--;
            delete[] dir;
            return;
        }
        if(direction==1&&dir[1]){
            x++;
            delete[] dir;
            return;
        }
        if(direction==2&&dir[2]){
            y--;
            delete[] dir;
            return;
        }
        if(direction==3&&dir[3]){
            y++;
            delete[] dir;
            return;
        }
    }
    switch (ran)
    {
    case 6:
        if(dir[0] && direction!=1){
            x--;
            direction=0;
            break;
        }
    case 7:
        if(dir[1] && direction!=0){
            x++;
            direction=1;
            break;
        }
    case 8:
        if(dir[2] && direction!=3){
            y--;
            direction=2;
            break;
        }
    case 9:
        if(dir[3] && direction!=2){
            y++;
            direction=3;
            break;
        }
    default:
        if(dir[3]){
            y++;
            direction=3;
            break;
        }
        if(dir[1]){
            x++;
            direction=1;
            break;
        }
        if(dir[2]){
            y--;
            direction=2;
            break;
        }
        if(dir[0]){
            x--;
            direction=0;
            break;
        }
    }
    delete[] dir;
}

/*����������
* ����ʵ�ֻ�����Ŀ�����߼������ƻ������߳�
*/
class SkaterFactory : public DPObject
{
private:
    /*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ���
	* @return void
	*/
	SkaterFactory() {};
    /**
    * ��ʱ������
	* ���ڲ���ÿ��һ�ε��¼������ɱ�run���ò������߳�
	* @return void*
    */
    static void Timer(){
        EventBus& mainSkatingManager =EventBus::getInstance();
        while(mainSkatingManager.isAutoRunning){
            while(mainSkatingManager.isRunning){}
            mainSkatingManager.update();
            std::chrono::milliseconds dura(1000);
            std::this_thread::sleep_for(dura);
        }
    }

public:
    //��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	SkaterFactory(const SkaterFactory&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	SkaterFactory& operator=(const SkaterFactory&) = delete;
	/**
	* ��ȡȫ��Ψһ���������������ã�����ʵ�ֵ�����
	* @return SkaterFactory& ����������������
	*/
	static SkaterFactory& getInstance() {
		static SkaterFactory instance;
		return instance;
	}
    /**
	* ���ڽ��뻬����Ŀ���ڲ��߼�
	* @return void
	*/
    void run(){
        std::thread timer(Timer);   //�����������Զ�ˢ���߳�
        timer.detach();
        //pthread_t id;
        //int ret = pthread_create(&id, nullptr, Timer, nullptr); //�����������Զ�ˢ���߳�

        EventBus& mainSkatingManager =EventBus::getInstance();
        if(mainSkatingManager.isAutoRunning==true){   //EventBus����ʱ����Skater����������⣬ֱ�ӽ���
            std::cout<<"skate exit!"<<std::endl;
            return;
        }
        mainSkatingManager.isAutoRunning=true;
        //����ָ���߼���ʼ
        std::cout<<"*********************************************************************"<<std::endl;
		std::cout<<"****************************** ���������� ***************************"<<std::endl;
		std::cout<<"*********************************************************************"<<std::endl<<std::endl;
		std::cout<<"��ӭ��������ѩ�ػ�������"<<std::endl<<"������������꿸��Ѧ���Ѿ����������ˣ��뿪ʼ�ɣ�"<<std::endl<<std::endl;

        int order;
        while(1){
            std::cout<<"������ָ�����Լ�����"<<std::endl<<
            "1����������  2���ƶ�  3�����ҳ���һ�����ѵ�λ��  4��������һ����������"<<std::endl;
				std::cout<<">";
				if(std::cin>>order){
					std::cin.get();
                    if(order==1){
                        mainSkatingManager.isAutoRunning=false;
						std::cout<<"�ѷ���"<<std::endl<<std::endl;
						break;
					}
					if(order==2){
                        system("cls");
                        mainSkatingManager.play();
                        
						continue;
					}
					if(order==3){
                        std::string name;
                        std::cout<<std::endl<<"������Ҫ�ҵ�����������";
                        std::cin>>name;
                        std::cout<<std::endl;
                        mainSkatingManager.searchFriend(name);
                        std::cout<<std::endl;
						continue;
					}
					if(order==4){
                        if(mainSkatingManager.getCnt()>13){
                            std::cout<<std::endl<<"�������Ѿ��޷����ɸ����οͣ�"<<std::endl;
                        }
                        else{
                            std::string name;
                            std::cout<<std::endl<<"���������������������";
                            std::cin>>name;
                            mainSkatingManager.addSkater(name);
                        }
                        std::cout<<std::endl;
						continue;
					}
                    
					std::cout<<"��Чָ�����������ָ���ʽ"<<std::endl;
				}
				else{
					std::cout<<"��Чָ�����������ָ���ʽ"<<std::endl;
					std::cin.clear();                     //����cin������
					std::string tmpbuf;                   //������ȡ���������Ч��
					getline(std::cin,tmpbuf);
				}
        }
    }
};

/*������������
* �̳���ָ�������
*/
class IceSkatingReceiver:public CommandReceiver
{
private:
    /*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"cave"
	* @return void
	*/
	IceSkatingReceiver() : CommandReceiver("skate") {}

protected:
	/*ִ��ָ��
	* ���ظ���ִ��ָ��Ĵ��麯�����������������ִ����Ӧ����
	* @param cmd �û������ָ������
	* @return bool ָ���ʽ�Ƿ���ȷ
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "go") {
            SkaterFactory::getInstance().run();

			return true;
		}
		return false;
	}
	/*��ӡ����ָ��
	* ���ظ����麯��������level��ӡ��Ӧ��ʽ��ָ��Լ�������ָ��
	* @param level ��ǰReciver��Reciver���еĲ㼶
	* @return void
	*/
	virtual void printHelp(int level) {
		CommandReceiver::printHelp(level);				//���ø����Ĭ��printHelp�������ݹ������ǰ���ӽ�������tag
		level++;								//����ָ����ʾ����һ��
		std::string head(level * 3, '-');	
		std::cout << head + "go" << std::endl;	//�����ָ��
	}

public:
    //��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	IceSkatingReceiver(const IceSkatingReceiver&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	IceSkatingReceiver& operator=(const IceSkatingReceiver&) = delete;
	/*��ȡ����ָ�������������
	* ��ȡȫ��Ψһʵ�������ã�����ʵ�ֵ�����
	* @return IceSkatingReceiver& ����ָ�������������
	*/
	static IceSkatingReceiver& getInstance() {
		static IceSkatingReceiver instance;
		return instance;
	}
};
/*�������ƻ�����
* �̳��ڳ���ƻ�����
*/
class IceSkatingPlanFactory : public AbstractPlanFactory {
public:
	/*����·��
	* @return Path* ���ɵ�·��
	*/
	Path* makePath() {
		Path* path = new Path();
		path->vehicle = "car";
		return path;
	}
	/*��������
	* @return Path* ���ɵ�����
	*/
	Description* makeDescription() {
		Description* des = new Description();
		des->content = "������ʵ�����¼�-����ģʽ�Ϳն���ģʽ����������IceSkating.h";
		return des;
	}
	/*����Ŀ��ص�
	* @return Path* ���ɵ�Ŀ��ص�
	*/
	Spot* makeSpot() {
		Spot& spot = IceSkatingReceiver::getInstance();
		return &spot;
	}
};