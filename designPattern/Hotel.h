#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>
#include <vector>


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
    * ��д�����ԡ�ҵ���������������Ӧ�ĺ������������׷��е�ԡ�ҽ�����Ӧ������
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
    * ��д�����ԡ�ҵ����ú���������Ӧ�ĺ������������׷��е�ԡ�ҽ�����Ӧ������
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
    /*��������
    * ��д����Ĵ�����������������Ӧ����ů���������׷��еĴ�������Ӧ������
    * @return void
    */
    void TellBedType()const override
    {
        std::cout << "��ů��������" << std::endl;
        std::cout << "��������Ϊ������" << std::endl;
    }
    /*���ӵ�����
   * ��д��������ӵ���������������Ӧ����ů���������׷��е����ӽ�����Ӧ������
   * @return void
   */
    void TellChairType()const override
    {
        std::cout << "���ӵ�����Ϊ������" << std::endl;
    }
    /*����������
   * ��д��������ӵ���������������Ӧ����ů���������׷��еı���������Ӧ������
   * @return void
   */
    void TellWallType()const override
    {
        std::cout << "���ⱳ��������Ϊ������ӣ��" << std::endl;
    }

    /*ԡ�ҵ�����
    * ��д�����ԡ�ҵ���������������Ӧ����ů���������׷��е�ԡ�ҽ�����Ӧ������
    * @return void
    */
    void TellBathType()const override
    {
        std::cout << "ԡ���䷽Ϊ��õ�廨ԡ" << std::endl;
    }

    /*��������
    * ��д����Ĵ������ú���������Ӧ����ů���������׷��еĴ�������Ӧ������
    * @return void
    */
    void SetBedType()const override
    {
        this->product->parts_.push_back("����");
    }
    /*���ӵ�����
    * ��д��������ӵ����ú���������Ӧ����ů���������׷��е����ӽ�����Ӧ������
    * @return void
    */
    void SetChairType()const override
    {
        this->product->parts_.push_back("����");
    }

    /*����������
    * ��д�����ԡ�ҵ����ú���������Ӧ����ů���������׷��еı���������Ӧ������
    * @return void
    */
    void SetWallType()const override
    {
        this->product->parts_.push_back("����ӣ��");
    }
    /*ԡ�ҵ�����
    * ��д�����ԡ�ҵ����ú���������Ӧ����ů���������׷��е�ԡ�ҽ�����Ӧ������
    * @return void
    */
    void SetBathType()const override
    {
        this->product->parts_.push_back("õ�廨ԡ");
    }

    /*��ů�����׷��Ĵ���
    * ������Ӧ����ů���յ��׷�
    * @return result ����һ����Ӧ����ů���յ������ֵ
    */
    WarmSpringThemeRoom* GetProduct()
    {
        WarmSpringThemeRoom* result = this->product;
        this->Reset();
        return result;
    }
};

/*һ�������׷��Ľ�������
* �̳г���Ľ������࣬���һ���������ⷿ������ú�����
* ���س���Ľ������е����еĺ���
*/
class FallInLoveThemeBuilder : public  Abstract_builder
{
private:
    FallInLoveThemeRoom* product;//��Ӧ��һ��������׷���ʵ��
public:
    /*���캯��
    * ����һ����Ӧ��һ�����鷿��
    */
    FallInLoveThemeBuilder()
    {
        this->Reset();
    }
    /*��������
    * ɾ����Ӧ��һ������ķ���
    */
    ~FallInLoveThemeBuilder()
    {
        delete product;
    }

    /*������Ʒ
    * Ϊ��Ӧ�Ĳ�Ʒ���и�ֵ�õ����������
    * @return void
    */
    void Reset()
    {
        this->product = new FallInLoveThemeRoom();
    }
    /*��������
   * ��д����Ĵ�����������������Ӧ��һ�����������׷��еĴ�������Ӧ������
   * @return void
   */
    void TellBedType()const override
    {
        std::cout << "һ����������" << std::endl;
        std::cout << "��������Ϊ��Բ��" << std::endl;
    }
    /*���ӵ�����
    * ��д��������ӵ���������������Ӧ��һ�����������׷��е����ӽ�����Ӧ������
    * @return void
    */
    void TellChairType()const override
    {
        std::cout << "���ӵ�����Ϊ��ҡ��" << std::endl;
    }
    /*����������
    * ��д����ı�������������������Ӧ��һ�����������׷��еı���������Ӧ������
    * @return void
    */
    void TellWallType()const override
    {
        std::cout << "����������Ϊ�������" << std::endl;
    }
    /*ԡ�ҵ�����
     * ��д�����ԡ�ҵ���������������Ӧ��һ�����������׷��е�ԡ�ҽ�����Ӧ������
    * @return void
    */
    void TellBathType()const override
    {
        std::cout << "ԡ���䷽Ϊ��ţ��ԡ" << std::endl;
    }
    /*��������
   * ��д����Ĵ������ú���������Ӧ��һ�����������׷��еĴ�������Ӧ������
   * @return void
   */
    void SetBedType()const override
    {
        this->product->parts_.push_back("Բ��");
    }
    /*���ӵ�����
   * ��д��������ӵ����ú���������Ӧ��һ�����������׷��е����ӽ�����Ӧ������
   * @return void
   */
    void SetChairType()const override
    {
        this->product->parts_.push_back("ҡ��");
    }
    /*����������
   * ��д�����ԡ�ҵ����ú���������Ӧ��һ�����������׷��еı���������Ӧ������
   * @return void
   */
    void SetWallType()const override
    {
        this->product->parts_.push_back("�����");
    }
    /*ԡ�ҵ�����
    * ��д�����ԡ�ҵ����ú���������Ӧ��һ�����������׷��е�ԡ�ҽ�����Ӧ������
    * @return void
    */
    void SetBathType()const override
    {
        this->product->parts_.push_back("ţ��ԡ");
    }
    /*һ�������׷��Ĵ���
    * ������Ӧ��һ������������׷�
    * @return result ����һ����Ӧ��һ������������ֵ
    */
    FallInLoveThemeRoom* GetProduct()
    {
        FallInLoveThemeRoom* result = this->product;
        this->Reset();
        return result;
    }
};


/*������
* �������ඨ����Ӧ�ķ���Ĺ��첽���˳��
* �����ඨ���˽��ܷ���͹��췿��������Ӧ�ķ���
*/
class Director
{
private:
    Abstract_builder* builder;
public:
    /*��ʼ��builder
    * ����Ӧ��ָ��ָ��builder
    * @return void
    */
    void set_builder(Abstract_builder* builder)
    {
        this->builder = builder;
    }
    /*���ܷ���
    * ���û�������Ӧ�Ļ��͵�ʱ���������������Ӧ�������Ӧ��Ŀ�����÷���builder ���ĸ�����
    * @return void
    */
    void TellTotalRoom()
    {
        this->builder->TellBedType();
        this->builder->TellChairType();
        this->builder->TellWallType();
        this->builder->TellBathType();
    }
    /*���췿��
    * �����û�����Ҫ����Ӧ�ķ�����в��ã����÷���builder���Ĳ�����
    * @return void
    */
    void BuildTotalRoom()
    {
        this->builder->SetBedType();
        this->builder->SetChairType();
        this->builder->SetWallType();
        this->builder->SetBathType();
    }
};

/*����ı���¼��
* ��������Ӧ�ı���¼��Ӧ���е���Ϣ�Ͳ���
*/
class Memento
{
public:
    /*�麯������¼������
    * ����¼�м�¼����Ӧ���¼�������
    * @return string
    */
    virtual std::string GetName() const = 0;

    /*�麯������¼��ʱ��
   * ����¼�м�¼����Ӧ���¼���ʱ��
   * @return string ����ʱ���ַ���
   */
    virtual std::string date() const = 0;

    /*�麯������¼��״̬
   * ����¼�м�¼����Ӧ��״̬������
   * @return string
   */
    virtual std::string state() const = 0;
};

/*����ı���¼��
* �̳г���ı���¼�࣬�����Ӧ�������Ϣ�ļ���
*
*/
class ConcreteMemento : public Memento
{
private:
    std::string state_;//��Ӧ�ı���¼��״̬
    std::string date_;//����¼������

public:
    /*��¼ʱ��
    * ��ȡϵͳ��ʱ�䲢����ת��Ϊ�ַ���
    * @time_t_time ��Ӧ��ϵͳʱ��
    * @reutnr string
    */
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
    /*���캯��
    * ������Ӧ��״̬�����ڼ�¼���ϼ�¼��Ӧ��״̬�����仯��ʱ��
    */
    ConcreteMemento(std::string state) : state_(state)
    {
        this->state_ = state;
        std::time_t now = std::time(0);
        this->date_ = time_t2string(now);
    }
    /*״̬����
    * ��д�����е� ���� ����Ӧ��״̬����ת��
    * @return string
    */
    std::string state() const override
    {
        return this->state_;
    }

    /*��¼����
    * ��д���ຯ���еĺ�������¼ÿһ����¼������
    * return string
    */
    std::string GetName() const override
    {
        return this->date_ + " / (" + this->state_.substr(0, 30) + "...)";
    }
    /*��¼ʱ��
    * ��д���ຯ���к���,��¼��Ӧ��״̬������ʱ��
    * @return string
    */
    std::string date() const override
    {
        return this->date_;
    }
};

/*ԭ������
* ��¼�е�ǰʱ��������ڲ�״̬,���𴴽�һ������¼
*/
class Originator
{

private:
    std::string state_;//��Ӧ��״̬


public:
    //��ʼ��ԭ����
    Originator(std::string state) : state_(state)
    {
        //std::cout << "��¼����ԭʼ״̬�� " << this->state_ << "\n";
    }
    /*��¼״̬
    * �û�ѡ������Ӧ�ĺ�����������⣬��¼��Ӧ��״̬
    * @return void
    */
    void RecordUnderWaterTheme()
    {
        this->state_ = "�û�ѡ�������⺣������";
        std::cout << "�û����ڵ�״̬Ϊ" << this->state_ << std::endl;
    }
    /*��¼״̬
    * �û�ѡ������Ӧ��һ����������⣬��¼��Ӧ��״̬
    * @return void
    */
    void RecordFallInLoveTheme()
    {
        this->state_ = "�û�ѡ��������һ������";
        std::cout << "�û����ڵ�״̬Ϊ" << this->state_ << "\n";
    }
    /*��¼״̬
    * �û�ѡ������Ӧ����ů���յ����⣬��¼��Ӧ��״̬
    * @return void
    */
    void RecordWarmSpring()
    {
        this->state_ = "�û�ѡ����������ů����";
        std::cout << "�û����ڵ�״̬Ϊ" << this->state_ << "\n";
    }

    /*�ڱ���¼�д洢��Ӧ��״̬
    * ����һ���µı���¼�Ķ���
    * return Memento
    */
    Memento* Save()
    {
        return new ConcreteMemento(this->state_);
    }
    /* ��ԭ����
     * ��ԭ��Ӧ�ı���¼��״̬
     * @return void
     */
    void Restore(Memento* memento)
    {
        this->state_ = memento->state();
        std::cout << "�û����ڵ�״̬Ϊ��" << this->state_ << "\n";
    }
};




/* ��������
* ���𱣴汸��¼.���ǲ��ܶԱ���¼�����ݽ��в���
*/
class Caretaker
{

private:
    std::vector<Memento*> mementos_;//����¼
    Originator* originator_;//ԭ����

public:
    //���캯�� ����Ŷ��Ӧ��ԭ����
    Caretaker(Originator* originator) : originator_(originator)
    {
        this->originator_ = originator;
    }
    /*�鿴��¼״̬
    * ����Ӧ����ʷ״̬�����е���Ӧ����Ϣ���д洢
    * @return void
    */
    void Backup()
    {
        std::cout << "���ڴ洢�û�����Ϣ��¼\n";
        this->mementos_.push_back(this->originator_->Save());
    }
    /*�ع�״̬
    * ������Ӧ�ı���¼�еļ�¼ ��ִ�ڵ�״̬����һ�����Ļع�
    * return void
    */
    bool Undo() {
        if (!this->mementos_.size())
        {
			return false;;
        }
        Memento* memento = this->mementos_.back();
        this->mementos_.pop_back();
        std::cout << "�ع����û���ѡ��: " << memento->GetName() << "\n";

        try
        {
            this->originator_->Restore(memento);
			return true;
        }
        catch (...)
        {
            std::cout << "�޿ɻع�����ʷ��¼" << std::endl;
			return false;
        }
		return true;
    }
    /*��ʾ����¼�ļ�¼
    * �鿴��Ӧ����ʷ��¼�����������е�״̬��
    * return void
    */
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


/*����ӿ�֧��
* ֧���ĳ���ӿ�
*/
class PayMethod
{
public:
    /*���麯����֧��
    * �����Ӧ��֧���Ĳ���
    * @return void
    */
    virtual void Pay() const = 0;
};

/*�ֽ𸶿�
* �̳���֧���࣬����ֽ�ĸ���
*/
class Cash : public PayMethod
{
public:
    /*֧������
    * ��д�����е�֧���������������ֽ�ĸ���Ĺ���
    * return void
    */
    void Pay() const override
    {
        std::cout << "����֧�������Ժ�..." << std::endl;
        std::cout << "֧���ɹ�" << std::endl;
        std::cout << "�����ɹ������ķ����Ϊ401��" << std::endl;
    }

};

/*֧����������
* �̳�֧���࣬��֧���������Ӧ��֧�������ֽ�
*/
class Alipay : public PayMethod {

private:
    Cash* real_subject_;//�ֽ�
    /*�����Ƿ��¼
    * @return bool
    */
    bool CheckAccess() const
    {
        // Some real checks should go here.
        std::cout << "���Ѿ��ɹ���¼֧����\n";
        return true;
    }
    /*����֮��Ӧ��Ӧ����ʾ
    * return void
    */
    void endPay() const
    {
        std::cout << "֧�������ѣ�����һ��֧��,��ע�����\n";
    }

public:
    Alipay(Cash* real_subject) : real_subject_(new Cash(*real_subject)) {
    }

    ~Alipay()
    {
        delete real_subject_;
    }
    /*֧������
    * ��д��Ӧ�ĺ��� �����Ӧ��֧������֧��
    * @return void
    */
    void Pay() const override
    {
        if (this->CheckAccess())
        {
            this->real_subject_->Pay();
            this->endPay();
        }
    }
};

/*΢�Ÿ�����
* �̳�֧���࣬��΢�������Ӧ��֧�������ֽ�
*/
class Wechat : public PayMethod {

private:
    Cash* real_subject_;//�ֽ�
     /*�����Ƿ��¼
     * @return bool
     */
    bool CheckAccess() const
    {
        // Some real checks should go here.
        std::cout << "���Ѿ��ɹ���¼΢��\n";
        return true;
    }
    /*����֮��Ӧ��Ӧ����ʾ
    * return void
    */
    void endPay() const
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
    /*֧������
    * ��д��Ӧ�ĺ��� �����Ӧ��΢�ŵ�֧��
    * @return void
    */
    void Pay() const override
    {
        if (this->CheckAccess())
        {
            this->real_subject_->Pay();
            this->endPay();
        }
    }
};


/*�û���
* ������Ӧ���û����Խ��еĲ���
*/
class Client
{
public:
    void ThemeDetails(Director& director);//��ʾ���������
    void ClientChooseUnderWaterTheme(Director& director);//ѡ����Ӧ�ķ�������
    void ClientChooseWarmingSpring(Director& director);
    void ClientChooseFallInLove(Director& director);
    void ClientPay(PayMethod& subject);//֧��

};
/*�����������ʾ
* ����Ӧ�ķ��������Ϣ����ʾ
* @Dircetor&director ��Ӧ������
* @return void
*/
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

/*�ͻ�ѡ����Ӧ�ĺ�����������
* װ����Ӧ�������׼� ������Ӧ���׼���Ϣ������ʾ
* @Dircetor&director ��Ӧ������
* @return void
*/
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


/*�ͻ�ѡ����Ӧ����ů��������
* װ����Ӧ�������׼� ������Ӧ���׼���Ϣ������ʾ
* @Dircetor&director ��Ӧ������
* @return void
*/
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

/*�ͻ�ѡ����Ӧ��һ����������
* װ����Ӧ�������׼� ������Ӧ���׼���Ϣ������ʾ
* @Dircetor&director ��Ӧ������
* @return void
*/
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

/*�ͻ�ѡ����Ӧ��֧������
* @payMethod ��Ӧ�ĸ��ʽ
* @return void
*/
void Client::ClientPay(PayMethod& subject)
{
    subject.Pay();
}


class HotelManager : public MacroCommandReceiver
{

private:
	/*���캯��
   * ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"Hotel"
   * @return void
   */
	HotelManager() : MacroCommandReceiver("Hotel") { }
	Originator* originator = new Originator("���Ѿ���ɵĶ���");
	Caretaker* caretaker = new Caretaker(originator);
protected:
	/*ִ��ָ��
   * ���ظ���ִ��ָ��Ĵ��麯�����������������ִ����Ӧ����
   * @param cmd �û������ָ������
   * @return bool ָ���ʽ�Ƿ���ȷ
   */
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
				std::cout << "��ӭ�鿴����ķ�ʽ" << std::endl;
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
				if (unPaid == true)
				{
					std::cout << "�д�֧���ķ���" << std::endl;
					return true;
				}
				else {
					std::cout << "��л��Ԥ�����������硱���ⷿ��" << std::endl;
					Director* director = new Director();
					Client* client = new Client();
					client->ClientChooseUnderWaterTheme(*director);
					originator->RecordUnderWaterTheme();
					std::cout << "������ʱ�����ȷ��Ԥ��" << std::endl;
					unPaid = true;
					delete director;
					delete client;
					return true;
				}
			}
			if (cmd == "FallInLoveTheme")
			{
				if (unPaid == true)
				{
					std::cout << "�д�֧���ķ���" << std::endl;
					return true;
				}
				else {
					std::cout << "��л��Ԥ����һ�����顱���ⷿ��" << std::endl;
					Director* director = new Director();
					Client* client = new Client();
					client->ClientChooseFallInLove(*director);
					originator->RecordFallInLoveTheme();

					std::cout << "������ʱ�����ȷ��Ԥ��" << std::endl;
					unPaid = true;
					delete director;
					delete client;

					return true;
				}
			}
			if (cmd == "WarmSpringTheme")
			{
				if (unPaid == true)
				{
					std::cout << "�д�֧���ķ���" << std::endl;
					return true;
				}
				else {
					std::cout << "��л��Ԥ������ů���ա����ⷿ��" << std::endl;
					Director* director = new Director();
					Client* client = new Client();
					client->ClientChooseWarmingSpring(*director);
					originator->RecordWarmSpring();
					std::cout << "������ʱ�����ȷ��Ԥ��" << std::endl;
					unPaid = true;
					delete director;
					delete client;
					return true;
				}
			}
			return false;
		}
		if (subCmd == "Pay")
		{
			if (cmd == "byCash")
			{
				if (!unPaid) {
					std::cout << "�޴�֧����Ԥ��" << std::endl;
					return true;
				}
				Client* client = new Client();
				std::cout << "�û�ʹ���ֽ�֧��\n";
				Cash* cash = new Cash;
				client->ClientPay(*cash);
				std::cout << "\n";
				caretaker->Backup();
				unPaid = false;
				delete cash;
				delete client;
				return true;
			}
			if (cmd == "byWechat")
			{
				if (!unPaid) {
					std::cout << "�޴�֧����Ԥ��" << std::endl;
					return true;
				}
				Cash* cash = new Cash;
				std::cout << "�û�ʹ��΢��֧��" << std::endl;
				Wechat* wechat = new Wechat(cash);
				Client* client = new Client();
				client->ClientPay(*wechat);
				std::cout << std::endl;
				caretaker->Backup();
				unPaid = false;
				delete cash;
				delete wechat;
				delete client;
				return true;
			}
			if (cmd == "byAlipay")
			{
				if (!unPaid) {
					std::cout << "�޴�֧����Ԥ��" << std::endl;
					return true;
				}
				Cash* cash = new Cash;
				std::cout << "�û�ʹ��֧����֧��\n";
				Alipay* alipay = new Alipay(cash);
				Client* client = new Client();
				client->ClientPay(*alipay);
				std::cout << "\n";
				caretaker->Backup();
				unPaid = false;
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
				if (caretaker->Undo()) {
					unPaid = true;
				}
				
				return true;
			}
		}

		return false;
	}
public:
	bool unPaid = false;
	HotelManager(const HotelManager&) = delete;
	HotelManager& operator=(const HotelManager&) = delete;

	static HotelManager& getInstance()
	{
		static HotelManager reciver;
		return reciver;
	}
	/*��ӡ����ָ��
   * ���ظ����麯��������level��ӡ��Ӧ��ʽ��ָ��Լ�������ָ��
   * @param level ��ǰReciver��Reciver���еĲ㼶
   * @return void
   */
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



