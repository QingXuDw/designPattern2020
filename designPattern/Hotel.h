#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "BaseClasses.h"


/*���������׷���
*���ڼ�¼�����׷��е���Ϣ����
*/
class UnderwaterWorldThemeRoom
{
public:
    std::vector<std::string> parts_;//�������飺���ڼ�¼�������ֵ����
    /*�������
    * ������Ӧ��������������������������
    * @return void
    */
    void ListParts()const
    {
        std::cout << "--------- ";
        std::cout << std::endl;
        for (size_t i = 0; i < parts_.size(); i++)
        {
            if (i == 0)
            {
                std::cout << "��ѡ�񴲵�����Ϊ��";
            }
            if (i == 1)
            {
                std::cout << "��ѡ������ӵ�����Ϊ��";
            }
            if (i == 2)
            {
                std::cout << "��ѡ��ı���������Ϊ:";
            }
            if (i == 3)
            {
                std::cout << "��ѡ���ԡ�ҵ�����Ϊ:";
            }
            if (i > 3)
            {
                std::cout << "û����Ӧ������";
            }
            
            if (parts_[i] == parts_.back())
            {
                std::cout << parts_[i];
            }
            else
            {
                std::cout << parts_[i] << ", ";
                std::cout << std::endl;
            }
        }
        std::cout << "\n\n";
    }
};


/*��ů�����׷���
*���ڼ�¼�����׷��е���Ϣ����
*/
class WarmSpringThemeRoom
{
public:
    std::vector<std::string> parts_;//�������飺���ڼ�¼�������ֵ����
    void ListParts()const
    {
        std::cout << "-----------";
        /*�������
        * ������Ӧ��������������������������
        * @return void
        */
        for (size_t i = 0; i < parts_.size(); i++)
        {
            if (i == 0)
            {
                std::cout << "��ѡ�񴲵�����Ϊ��";
            }
            if (i == 1)
            {
                std::cout << "��ѡ������ӵ�����Ϊ��";
            }
            if (i == 2)
            {
                std::cout << "��ѡ��ı���������Ϊ:";
            }
            if (i == 3)
            {
                std::cout << "��ѡ���ԡ�ҵ�����Ϊ:";
            }
            if (i > 3)
            {
                std::cout << "û����Ӧ������";
            }
            if (parts_[i] == parts_.back())
            {
                std::cout << parts_[i];
            }
            else
            {
                std::cout << parts_[i] << ", ";
                std::cout << std::endl;
            }
        }
        std::cout << "\n\n";
    }
};


/*һ�������׷���
*���ڼ�¼�����׷��е���Ϣ����
*/
class FallInLoveThemeRoom
{
public:
    std::vector<std::string> parts_;//�������飺���ڼ�¼�������ֵ����
       /*�������
       * ������Ӧ��������������������������
       * @return void
       */
    void ListParts()const
    {
        std::cout << "---------- ";
    
        for (size_t i = 0; i < parts_.size(); i++)
        {
            if (i == 0)
            {
                std::cout << "��ѡ�񴲵�����Ϊ��";
            }
            if (i == 1)
            {
                std::cout << "��ѡ������ӵ�����Ϊ��";
            }
            if (i == 2)
            {
                std::cout << "��ѡ��ı���������Ϊ:";
            }
            if (i == 3)
            {
                std::cout << "��ѡ���ԡ�ҵ�����Ϊ:";
            }
            if (i > 3)
            {
                std::cout << "û����Ӧ������";
            }
            if (parts_[i] == parts_.back())
            {
                std::cout << parts_[i];
            }
            else
            {
                std::cout << parts_[i] << ", ";
                std::cout << std::endl;
            }
        }
        std::cout << "\n\n";
    }
};

/*����Ľ�������
* ��������Ӧ�Ľ����ߵĲ���
*/
class Abstract_builder
{
public:
    /*��������
    * ɾ����Ӧ�ĳ�������
    */
    virtual ~Abstract_builder() {}

    /*��������
    * ��������Ĵ����ͺ���Ϣ
    * @return void
    */
    virtual void TellBedType() const = 0;

    /*��������
    * ������������ӵ��ͺ���Ϣ
    * @return void
    */
    virtual void TellChairType() const = 0;

    /*��������
    * ��������ı������ͺ���Ϣ
    * @return void
    */
    virtual void TellWallType() const = 0;

    /*ԡ������
    * ���������ԡ�ҵ�������Ϣ
    * @return void
    */
    virtual void TellBathType() const = 0;

    /*���ķ���
    * ��ֵ��Ӧ�ķ����������飬����Ӧ�Ĵ��Ž�����
    * @return void
    */
    virtual void SetBedType() const = 0;

    /*���ӵķ���
    * ��ֵ��Ӧ�ķ����������飬����Ӧ�����ӷŽ�����
    * @return void
    */
    virtual void SetChairType() const = 0;

    /*����������
    * ��ֵ��Ӧ�ķ����������飬����Ӧ�ı���װ�뷿��
    * @return void
    */
    virtual void SetWallType() const = 0;

    /*ԡ�ҵ�����
    * ��ֵ��Ӧ�ķ����������飬����Ӧ��ԡ����ƽ�����
    * @return void
    */
    virtual void SetBathType() const = 0;
};

/*��������Ľ�������
* �̳г���Ľ������࣬��ɺ����������ⷿ������ú�����
* ���س���Ľ������е����еĺ���
*/
class UnderwaterWorldThemeBuilder : public  Abstract_builder
{
private:
    UnderwaterWorldThemeRoom* product;//��Ӧ�ĺ����׷���ʵ��
public:
    /*���캯��
    * ����һ����Ӧ�ĺ������緿��
    */
    UnderwaterWorldThemeBuilder()
    {
        this->Reset();
    }

    /*��������
    * ɾ����Ӧ�ĺ�������ķ���
    */
    ~UnderwaterWorldThemeBuilder()
    {
        delete product;
    }
    
    /*������Ʒ
    * Ϊ��Ӧ�Ĳ�Ʒ���и�ֵ�õ����������
    * @return void
    */
    void Reset()
    {
        this->product = new UnderwaterWorldThemeRoom();
    }

    /*��������
    * ��д����Ĵ�����������������Ӧ�ĺ������������׷��еĴ�������Ӧ������
    * @return void
    */
    void TellBedType()const override
    {
        std::cout << "������������" << std::endl;
        std::cout << "��������Ϊ��ˮ��" << std::endl;
    }
    /*���ӵ�����
    * ��д��������ӵ���������������Ӧ�ĺ������������׷��е����ӽ�����Ӧ������
    * @return void
    */
    void TellChairType()const override
    {
        std::cout << "���ӵ�����Ϊ������" << std::endl;
    }

    /*����������
    * ��д����ı�������������������Ӧ�ĺ������������׷��еı���������Ӧ������
    * @return void
    */
    void TellWallType()const override
    {
        std::cout << "����������Ϊ����ɫ����" << std::endl;
    }

    /*ԡ�ҵ�����
    * ��д�����ԡ�ҵ���������������Ӧ�ĺ������������׷��еĴ�������Ӧ������
    * @return void
    */
    void TellBathType()const override
    {
        std::cout << "ԡ���䷽Ϊ����ˮԡ" << std::endl;
    }

    /*��������
    * ��д����Ĵ������ú���������Ӧ�ĺ������������׷��еĴ�������Ӧ������
    * @return void
    */
    void SetBedType()const override
    {
        this->product->parts_.push_back("ˮ��");
    }
    /*���ӵ�����
    * ��д��������ӵ����ú���������Ӧ�ĺ������������׷��е����ӽ�����Ӧ������
    * @return void
    */
    void SetChairType()const override
    {
        this->product->parts_.push_back("����");
    }

    /*����������
    * ��д�����ԡ�ҵ����ú���������Ӧ�ĺ������������׷��еı���������Ӧ������
    * @return void
    */
    void SetWallType()const override
    {
        this->product->parts_.push_back("��ɫ����");
    }
    /*ԡ�ҵ�����
    * ��д�����ԡ�ҵ����ú���������Ӧ�ĺ������������׷��еĴ�������Ӧ������
    * @return void
    */
    void SetBathType()const override
    {
        this->product->parts_.push_back("��ˮԡ");
    }

    /*���������׷��Ĵ���
    * ������Ӧ�ĺ�������������׷�
    * @return result ����һ����Ӧ�ĺ�������������ֵ
    */
    UnderwaterWorldThemeRoom* GetProduct()
    {
        UnderwaterWorldThemeRoom* result = this->product;
        this->Reset();
        return result;
    }
};


/*��ů���յĽ�������
* �̳г���Ľ������࣬�����ů�������ⷿ������ú�����
* ���س���Ľ������е����еĺ���
*/
class WarmSpringThemeBuilder : public  Abstract_builder
{
private:
    WarmSpringThemeRoom* product;//��Ӧ����ů���յ�ʵ��
public:

    /*���캯��
    * ����һ����Ӧ�ĺ������緿��
    */
    WarmSpringThemeBuilder()
    {
        this->Reset();
    } 

    /*��������
    * ɾ����Ӧ�ĺ�������ķ���
    */
    ~WarmSpringThemeBuilder()
    {
        delete product;
    }

    /*������Ʒ
    * Ϊ��Ӧ�Ĳ�Ʒ���и�ֵ�õ����������
    * @return void
    */
    void Reset()
    {
        this->product = new WarmSpringThemeRoom();
    }

    void TellBedType()const override
    {
        std::cout << "��ů��������" << std::endl;
        std::cout << "��������Ϊ������" << std::endl;
    }

    void TellChairType()const override
    {
        std::cout << "���ӵ�����Ϊ������" << std::endl;
    }

    void TellWallType()const override
    {
        std::cout << "���ⱳ��������Ϊ������ӣ��" << std::endl;
    }

    void TellBathType()const override
    {
        std::cout << "ԡ���䷽Ϊ��õ�廨ԡ" << std::endl;
    }

    void SetBedType()const override
    {
        this->product->parts_.push_back("����");
    }

    void SetChairType()const override
    {
        this->product->parts_.push_back("����");
    }

    void SetWallType()const override
    {
        this->product->parts_.push_back("����ӣ��");
    }

    void SetBathType()const override
    {
        this->product->parts_.push_back("õ�廨ԡ");
    }
    //����һ����ů���յķ���
    WarmSpringThemeRoom* GetProduct()
    {
        WarmSpringThemeRoom* result = this->product;
        this->Reset();
        return result;
    }
};

//һ������ķ���Ľ����� �̳���Ӧ�Ľ�������
class FallInLoveThemeBuilder : public  Abstract_builder
{
private:
    FallInLoveThemeRoom* product;
public:

    FallInLoveThemeBuilder()
    {
        this->Reset();
    }

    ~FallInLoveThemeBuilder()
    {
        delete product;
    }

    void Reset()
    {
        this->product = new FallInLoveThemeRoom();
    }

    void TellBedType()const override
    {
        std::cout << "һ����������" << std::endl;
        std::cout << "��������Ϊ��Բ��" << std::endl;
    }

    void TellChairType()const override
    {
        std::cout << "���ӵ�����Ϊ��ҡ��" << std::endl;
    }

    void TellWallType()const override
    {
        std::cout << "����������Ϊ�������" << std::endl;
    }

    void TellBathType()const override
    {
        std::cout << "ԡ���䷽Ϊ��ţ��ԡ" << std::endl;
    }
    void SetBedType()const override
    {
        this->product->parts_.push_back("Բ��");
    }

    void SetChairType()const override
    {
        this->product->parts_.push_back("ҡ��");
    }

    void SetWallType()const override
    {
        this->product->parts_.push_back("�����");
    }

    void SetBathType()const override
    {
        this->product->parts_.push_back("ţ��ԡ");
    }

    FallInLoveThemeRoom* GetProduct()
    {
        FallInLoveThemeRoom* result = this->product;
        this->Reset();
        return result;
    }
};



//���� ��Director�� �ඨ����ù��첽���˳��
//�����������ֻ�н�����������ķ���
class Director
{
private:
    Abstract_builder* builder;
public:
    void set_builder(Abstract_builder* builder)
    {
        this->builder = builder;
    }

    void TellTotalRoom()
    {
        this->builder->TellBedType();
        this->builder->TellChairType();
        this->builder->TellWallType();
        this->builder->TellBathType();
    }
    void BuildTotalRoom()
    {
        this->builder->SetBedType();
        this->builder->SetChairType();
        this->builder->SetWallType();
        this->builder->SetBathType();
    }
};

//������¼��
class Memento 
{
public:
    virtual std::string GetName() const = 0;//����¼������
    virtual std::string date() const = 0;//��Ӧ��ʱ��
    virtual std::string state() const = 0;// ���ڵ�״̬
};


class ConcreteMemento : public Memento
{
private:
    std::string state_;
    std::string date_;

public:
    //��ȡ��ǰ��ʱ�� ������ת��Ϊ�ַ���
    std::string time_t2string(const time_t time_t_time)
    {
        char szTime[100] = { '\0' };

        tm* pTm = new tm;
        localtime_s(pTm, &time_t_time);
        //pTm = localtime(&time_t_time);
        pTm->tm_year += 1900;
        pTm->tm_mon += 1;

        sprintf_s(szTime, "%04d/%02d/%02d %02d:%02d:%02d",
            pTm->tm_year,
            pTm->tm_mon,
            pTm->tm_mday,
            pTm->tm_hour,
            pTm->tm_min,
            pTm->tm_sec);

        std::string strTime = szTime;

        delete pTm;
        pTm = NULL;

        return strTime;
    }

    ConcreteMemento(std::string state) : state_(state)
    {
        this->state_ = state;
        std::time_t now = std::time(0);
        this->date_ = time_t2string(now);
    }

    std::string state() const override
    {
        return this->state_;
    }

    //ÿһ����¼����Ӧ������
    std::string GetName() const override
    {
        return this->date_ + " / (" + this->state_.substr(0, 30) + "...)";
    }
    std::string date() const override
    {
        return this->date_;
    }
};

//����¼�е�ԭ����
class Originator
{

private:
    std::string state_;


public:
    Originator(std::string state) : state_(state)
    {
        //std::cout << "��¼����ԭʼ״̬�� " << this->state_ << "\n";
    }

    void RecordUnderWaterTheme()
    {
        this->state_ = "�û�ѡ�������⺣������";
        std::cout << "�û����ڵ�״̬Ϊ" << this->state_ << std::endl;
    }

    void RecordFallInLoveTheme()
    {
        this->state_ = "�û�ѡ��������һ������";
        std::cout << "�û����ڵ�״̬Ϊ" << this->state_ << "\n";
    }

    void RecordWarmSpring()
    {
        this->state_ = "�û�ѡ����������ů����";
        std::cout << "�û����ڵ�״̬Ϊ" << this->state_ << "\n";
    }

    //��¼��Ӧ��״̬
    Memento* Save()
    {
        return new ConcreteMemento(this->state_);
    }
    /**
     * Restores the Originator's state from a memento object.
     */
    void Restore(Memento* memento)
    {
        this->state_ = memento->state();
        std::cout << "�û����ڵ�״̬Ϊ��" << this->state_ << "\n";
    }
};

//������,ֻ֪��ʱ�����Ӧ��״̬���ǲ����޸�
class Caretaker
{

private:
    std::vector<Memento*> mementos_;
    Originator* originator_;

public:
    Caretaker(Originator* originator) : originator_(originator)
    {
        this->originator_ = originator;
    }
    //��¼��Ӧ����Ϣ
    void Backup()
    {
        std::cout << "���ڴ洢�û�����Ϣ��¼\n";
        this->mementos_.push_back(this->originator_->Save());
    }
    //�ع���Ӧ����Ϣ
    void Undo() {
        if (!this->mementos_.size())
        {
            return;
        }
        Memento* memento = this->mementos_.back();
        this->mementos_.pop_back();
        std::cout << "�ع����û���ѡ��: " << memento->GetName() << "\n";
        try
        {
            this->originator_->Restore(memento);
        }
        catch (...)
        {
            this->Undo();
        }
    }
    //��ʾ����¼����Ϣ
    void ShowHistory() const
    {
        std::cout << "��¼���еļ�¼����:\n";
        for (Memento* memento : this->mementos_)
        {
            if (memento->GetName() == "")
            {
                std::cout << "û����Ӧ�ļ�¼" << std::endl;
            }
            std::cout << memento->GetName() << "\n";
        }
    }
};


//����ӿڸ�Ǯ
class PayMethod
{
    public:
    virtual void Pay() const = 0;
};

//�ֽ𸶿�
class Cash : public PayMethod
{
    public:
        
    void Pay() const override 
    {
        std::cout << "����֧�������Ժ�..."<<std::endl;
        std::cout << "֧���ɹ�" << std::endl;
        std::cout << "�����ɹ������ķ����Ϊ401��" << std::endl;
    }

};

//֧�������� �����ֽ�
class Alipay : public PayMethod {
   
private:
    Cash * real_subject_;

    bool CheckAccess() const 
    {
        // Some real checks should go here.
        std::cout << "���Ѿ��ɹ���¼֧����\n";
        return true;
    }
    void LogAccess() const 
    {
        std::cout << "֧�������ѣ�����һ��֧��,��ע�����\n";
    }

public:
    Alipay(Cash * real_subject) : real_subject_(new Cash (*real_subject)) {
    }

    ~Alipay()
    {
        delete real_subject_;
    }

    void Pay() const override 
    {
        if (this->CheckAccess()) 
        {
            this->real_subject_->Pay();
            this->LogAccess();
        }
    }
};

//΢�Ÿ��� �����ֽ�
class Wechat : public PayMethod {

private:
    Cash* real_subject_;
    bool CheckAccess() const
    {
        // Some real checks should go here.
        std::cout << "���Ѿ��ɹ���¼΢��\n";
        return true;
    }
    void LogAccess() const
    {
        std::cout << "΢�����ѣ�����һ��֧��\n";
    }

public:
    Wechat(Cash* real_subject) : real_subject_(new Cash(*real_subject)) {
    }

    ~Wechat()
    {
        delete real_subject_;
    }

    void Pay() const override
    {
        if (this->CheckAccess())
        {
            this->real_subject_->Pay();
            this->LogAccess();
        }
    }
};


//�û���
class Client
{
public:
    void ThemeDetails(Director& director);//��ʾ���������
    void ClientChooseUnderWaterTheme(Director& director);//ѡ����Ӧ�ķ�������
    void ClientChooseWarmingSpring(Director& director);
    void ClientChooseFallInLove(Director& director);
    void ClientPay(PayMethod& subject);//֧��

};

void Client::ThemeDetails(Director& director)
{
    UnderwaterWorldThemeBuilder* builder_UWT = new UnderwaterWorldThemeBuilder();
    WarmSpringThemeBuilder* builder_WST = new WarmSpringThemeBuilder();
    FallInLoveThemeBuilder* builder_FIL = new FallInLoveThemeBuilder();

    std::cout << "�����ݿ��Զ���Ӧ�ģ����ͣ������ͣ�������ԡ�����ͽ���ѡ��" << std::endl;
    std::cout << "���Ƴ����������ײͣ�" << std::endl;
    std::cout << std::endl;
    //�������緿��Ľ���
    director.set_builder(builder_UWT);
    director.TellTotalRoom();
    UnderwaterWorldThemeRoom* p_UWT = builder_UWT->GetProduct();
    p_UWT->ListParts();

    //��ů���յĽ���
    director.set_builder(builder_WST);
    director.TellTotalRoom();
    WarmSpringThemeRoom* p_WST = builder_WST->GetProduct();
    p_WST->ListParts();

    //һ������Ľ���
    director.set_builder(builder_FIL);
    director.TellTotalRoom();
    FallInLoveThemeRoom* p_FIL = builder_FIL->GetProduct();
    p_FIL->ListParts();

    /*
        std::cout << "Custom product:\n";
        builder_UWT->SetBedType();
        builder_UWT->SetWallType();
        p_UWT = builder_UWT->GetProduct();
        p_UWT->ListParts();*/

    delete p_UWT;
    delete p_FIL;
    delete p_WST;
    delete builder_UWT;
    delete builder_WST;
    delete builder_FIL;
}


void Client::ClientChooseUnderWaterTheme(Director& director)
{
    UnderwaterWorldThemeBuilder* builder_UWT = new UnderwaterWorldThemeBuilder();
    director.set_builder(builder_UWT);
   std::cout << "��ѡ����ײ�Ϊ: ��������";
   std::cout << std::endl;
    UnderwaterWorldThemeRoom* p_UWT = builder_UWT->GetProduct();
    director.BuildTotalRoom();
    p_UWT = builder_UWT->GetProduct();
    p_UWT->ListParts();
    delete p_UWT;

}


void Client::ClientChooseWarmingSpring(Director& director)
{

    WarmSpringThemeBuilder* builder_WST = new WarmSpringThemeBuilder();
    director.set_builder(builder_WST);
    std::cout << "��ѡ����ײ�Ϊ����ů����";
    std::cout << std::endl;
    WarmSpringThemeRoom* p_WST = builder_WST->GetProduct();
    director.BuildTotalRoom();
    p_WST = builder_WST->GetProduct();
    p_WST->ListParts();
    delete p_WST;
    delete builder_WST;
}

void Client::ClientChooseFallInLove(Director& director)
{
    FallInLoveThemeBuilder* builder_FIL = new FallInLoveThemeBuilder();
    director.set_builder(builder_FIL);
    std::cout << "��ѡ����ײ�Ϊ��һ������";
    std::cout << std::endl;
    FallInLoveThemeRoom* p_FIL = builder_FIL->GetProduct();
    director.BuildTotalRoom();

    p_FIL = builder_FIL->GetProduct();
    p_FIL->ListParts();
    delete p_FIL;
    delete builder_FIL;
}

void Client::ClientPay(PayMethod & subject) 
{
    subject.Pay();
}



class HotelManager : public MacroCommandReceiver
{

private:
    HotelManager() : MacroCommandReceiver("Hotel")  { }
    Originator* originator = new Originator("��¼�����Ͽտ���Ҳ");
    Caretaker* caretaker = new Caretaker(originator);
protected:
    bool executeCommand(std::string cmd) 
{
        std::string subCmd = sliceCommand(cmd);
        removeBlank(cmd);
        if (subCmd == "HotelHelp")
        {
            if (cmd == "OrderRoomDetails")
            {
                std::cout << "��ӭ�鿴��ص��ײ�" << std::endl;
                Director* director = new Director();
                Client* client = new Client();
                client->ThemeDetails(*director);
                delete client;
                delete director;
                std::cout << std::endl;
                return true;
            }
            if (cmd == "PayMethod")
            {
                std::cout << "��ӭ�鿴����ķ�ʽ"<< std::endl;
                std::cout << "����֧�ֵĸ��ʽ�У��ֽ�΢�ţ�֧����" << std::endl;
                return true;
            }
            if (cmd == "HistorySearch")
            {
                std::cout << "�����Բ�ѯ������¼����ѡ����ϴ�һ���ķ���Ŷ" << std::endl;
                return true;
            }
        }
        if (subCmd == "OrderRoom")
        {
           
            if (cmd == "UnderWaterTheme")
            {
                std::cout << "��л��Ԥ�����������硱���ⷿ��" << std::endl;
                Director* director = new Director();
                Client* client = new Client();
                client->ClientChooseUnderWaterTheme(*director);
                caretaker->Backup();
                originator->RecordUnderWaterTheme();
                std::cout << "������ʱ�����ȷ��Ԥ��" << std::endl;
                delete director;
                delete client;
                return true;
            }
            if (cmd == "FallInLoveTheme")
            {
                std::cout << "��л��Ԥ����һ�����顱���ⷿ��" << std::endl;
                Director* director = new Director();
                Client* client = new Client();
                client->ClientChooseFallInLove(*director);
                caretaker->Backup();
                originator->RecordFallInLoveTheme();

                std::cout << "������ʱ�����ȷ��Ԥ��" << std::endl;
                delete director;
                delete client;
               
                return true;
            }
            if (cmd == "WarmSpringTheme")
            {
                std::cout << "��л��Ԥ������ů���ա����ⷿ��" << std::endl;
                Director* director = new Director();
                Client* client = new Client();
                client->ClientChooseWarmingSpring(*director);
                caretaker->Backup();
                originator->RecordWarmSpring();
                std::cout << "������ʱ�����ȷ��Ԥ��" << std::endl;
                delete director;
                delete client;
                return true;
            }
            return false;
        }
        if (subCmd == "Pay")
        {
            if (cmd == "byCash")
            {
                Client* client = new Client();
                std::cout << "�û�ʹ���ֽ�֧��\n";
                Cash* cash = new Cash;
                client->ClientPay(*cash);
                std::cout << "\n";
                delete cash;
                delete client;
                return true;
            }
            if (cmd == "byWechat")
            {
                Cash* cash = new Cash;
                std::cout << "�û�ʹ��΢��֧��" << std::endl;
                Wechat* wechat = new Wechat(cash);
                Client* client = new Client();
               client-> ClientPay(*wechat);
                delete cash;
                delete wechat;
                delete client;
                return true;
            }
            if (cmd == "byAlipay")
            {
                Cash* cash = new Cash;
                std::cout << "�û�ʹ��֧����֧��\n";
                Alipay* alipay = new Alipay(cash);
                Client* client = new Client();
                client->ClientPay(*alipay);
                std::cout << "\n";
                delete cash;
                delete alipay;
                delete client;
                return true;
            }
        }

        if (subCmd == "History")
        {
            if (cmd == "Show")
            {
                std::cout << "\n";
                caretaker->ShowHistory();
                return true;

            }

            if (cmd == "Undo")
            {
                std::cout << "\n�ͻ�������Ҫ���ϴεķ���\n";
                caretaker->Undo();
                return true;
            }
        }

        return false;
    }
public:
    HotelManager(const HotelManager&) = delete;
    HotelManager& operator=(const HotelManager&) = delete;

    static HotelManager& getInstance()
    {
        static HotelManager reciver;
        return reciver;
    }

    virtual void printHelp(int level)
    {
        MacroCommandReceiver::printHelp(level);
        level++;
        std::string head(level * 3, '-');
        std::cout << head + "HotelHelp" << std::endl;
        std::cout << head + "---" + "OrderRoomDetails" << std::endl;
        std::cout << head + "---" + "PayMethod" << std::endl;
        std::cout << head + "---" + "HistroySearch" << std::endl;
        std::cout << head + "OrderRoom" << std::endl;
        std::cout << head + "---" + "UnderWaterTheme" << std::endl;
        std::cout << head + "---" + "FallInLoveTheme" << std::endl;
        std::cout << head + "---" + "WarmSpringTheme" << std::endl;
        std::cout << head + "Pay" << std::endl;
        std::cout << head + "---" + "byCash" << std::endl;
        std::cout << head + "---" + "byWechat" << std::endl;
        std::cout << head + "---" + "byAlipay" << std::endl;
        std::cout << head + "History" << std::endl;
        std::cout << head + "---" + "Show" << std::endl;
        std::cout << head + "---" + "Undo" << std::endl;
    }
    ~HotelManager()
    {
        delete originator;
        delete caretaker;
    }
};


/*
int main() {
    Director* director = new Director();
    Client* client = new Client();
    client->ClientChooseUnderWaterTheme(*director);
    client->ClientChooseFallInLove(*director);
    client->ClientChooseWarmingSpring(*director);
    delete director;
    delete client;


    ClientSearch();
    std::cout << std::endl;

    Cash * cash  = new Cash;
    std::cout << "΢��֧��" << std::endl;
    Wechat* wechat = new Wechat(cash);
    ClientCode(*wechat);
    delete cash;
    delete alipay;
    delete wechat;
    return 0;
}
*/


