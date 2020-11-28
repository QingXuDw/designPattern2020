#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>
#include <vector>


/*海底世界套房类
*用于记录海景套房中的信息内容
*/
class UnderwaterWorldThemeRoom
{
public:
    std::vector<std::string> parts_;//内容数组：用于记录各个部分的情况
    /*内容输出
    * 根据相应的内容数组依次输出数组的内容
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
                std::cout << "您选择床的类型为：";
            }
            if (i == 1)
            {
                std::cout << "您选择的椅子的类型为：";
            }
            if (i == 2)
            {
                std::cout << "您选择的背景的类型为:";
            }
            if (i == 3)
            {
                std::cout << "您选择的浴室的类型为:";
            }
            if (i > 3)
            {
                std::cout << "没有相应的描述";
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


/*温暖春日套房类
*用于记录海景套房中的信息内容
*/
class WarmSpringThemeRoom
{
public:
    std::vector<std::string> parts_;//内容数组：用于记录各个部分的情况
    void ListParts()const
    {
        std::cout << "-----------";
        /*内容输出
        * 根据相应的内容数组依次输出数组的内容
        * @return void
        */
        for (size_t i = 0; i < parts_.size(); i++)
        {
            if (i == 0)
            {
                std::cout << "您选择床的类型为：";
            }
            if (i == 1)
            {
                std::cout << "您选择的椅子的类型为：";
            }
            if (i == 2)
            {
                std::cout << "您选择的背景的类型为:";
            }
            if (i == 3)
            {
                std::cout << "您选择的浴室的类型为:";
            }
            if (i > 3)
            {
                std::cout << "没有相应的描述";
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


/*一见钟情套房类
*用于记录海景套房中的信息内容
*/
class FallInLoveThemeRoom
{
public:
    std::vector<std::string> parts_;//内容数组：用于记录各个部分的情况
       /*内容输出
       * 根据相应的内容数组依次输出数组的内容
       * @return void
       */
    void ListParts()const
    {
        std::cout << "---------- ";

        for (size_t i = 0; i < parts_.size(); i++)
        {
            if (i == 0)
            {
                std::cout << "您选择床的类型为：";
            }
            if (i == 1)
            {
                std::cout << "您选择的椅子的类型为：";
            }
            if (i == 2)
            {
                std::cout << "您选择的背景的类型为:";
            }
            if (i == 3)
            {
                std::cout << "您选择的浴室的类型为:";
            }
            if (i > 3)
            {
                std::cout << "没有相应的描述";
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

/*抽象的建造者类
* 定义了相应的建造者的操作
*/
class Abstract_builder
{
public:
    /*析构函数
    * 删除相应的抽象建造者
    */
    virtual ~Abstract_builder() {}

    /*床型描述
    * 描述房间的床的型号信息
    * @return void
    */
    virtual void TellBedType() const = 0;

    /*椅子描述
    * 描述房间的椅子的型号信息
    * @return void
    */
    virtual void TellChairType() const = 0;

    /*背景描述
    * 描述房间的背景的型号信息
    * @return void
    */
    virtual void TellWallType() const = 0;

    /*浴室描述
    * 描述房间的浴室的类型信息
    * @return void
    */
    virtual void TellBathType() const = 0;

    /*床的放置
    * 赋值相应的房间内容数组，将相应的床放进房间
    * @return void
    */
    virtual void SetBedType() const = 0;

    /*椅子的放置
    * 赋值相应的房间内容数组，将相应的椅子放进房间
    * @return void
    */
    virtual void SetChairType() const = 0;

    /*背景的设置
    * 赋值相应的房间内容数组，将相应的背景装入房间
    * @return void
    */
    virtual void SetWallType() const = 0;

    /*浴室的设置
    * 赋值相应的房间内容数组，将相应的浴室设计进房间
    * @return void
    */
    virtual void SetBathType() const = 0;
};

/*海底世界的建造者类
* 继承抽象的建造者类，完成海底世界主题房间的设置和描述
* 重载抽象的建造者中的所有的函数
*/
class UnderwaterWorldThemeBuilder : public  Abstract_builder
{
private:
    UnderwaterWorldThemeRoom* product;//相应的海底套房的实例
public:
    /*构造函数
    * 建造一个相应的海底世界房间
    */
    UnderwaterWorldThemeBuilder()
    {
        this->Reset();
    }

    /*析构函数
    * 删除相应的海底世界的房间
    */
    ~UnderwaterWorldThemeBuilder()
    {
        delete product;
    }

    /*创建产品
    * 为相应的产品进行赋值得到房间的类型
    * @return void
    */
    void Reset()
    {
        this->product = new UnderwaterWorldThemeRoom();
    }

    /*床的描述
    * 重写父类的床的描述函数，对相应的海底世界主题套房中的床进行相应的描述
    * @return void
    */
    void TellBedType()const override
    {
        std::cout << "海底世界主题" << std::endl;
        std::cout << "床的类型为：水床" << std::endl;
    }
    /*椅子的描述
    * 重写父类的椅子的描述函数，对相应的海底世界主题套房中的椅子进行相应的描述
    * @return void
    */
    void TellChairType()const override
    {
        std::cout << "椅子的类型为：座椅" << std::endl;
    }

    /*背景的描述
    * 重写父类的背景的描述函数，对相应的海底世界主题套房中的背景进行相应的描述
    * @return void
    */
    void TellWallType()const override
    {
        std::cout << "背景的类型为：冷色海洋" << std::endl;
    }

    /*浴室的描述
    * 重写父类的浴室的描述函数，对相应的海底世界主题套房中的浴室进行相应的描述
    * @return void
    */
    void TellBathType()const override
    {
        std::cout << "浴室配方为：盐水浴" << std::endl;
    }

    /*床的设置
    * 重写父类的床的设置函数，对相应的海底世界主题套房中的床进行相应的设置
    * @return void
    */
    void SetBedType()const override
    {
        this->product->parts_.push_back("水床");
    }
    /*椅子的设置
    * 重写父类的椅子的设置函数，对相应的海底世界主题套房中的椅子进行相应的设置
    * @return void
    */
    void SetChairType()const override
    {
        this->product->parts_.push_back("座椅");
    }

    /*背景的设置
    * 重写父类的浴室的设置函数，对相应的海底世界主题套房中的背景进行相应的设置
    * @return void
    */
    void SetWallType()const override
    {
        this->product->parts_.push_back("冷色海洋");
    }
    /*浴室的设置
    * 重写父类的浴室的设置函数，对相应的海底世界主题套房中的浴室进行相应的设置
    * @return void
    */
    void SetBathType()const override
    {
        this->product->parts_.push_back("盐水浴");
    }

    /*海底世界套房的创建
    * 创建相应的海底世界主题的套房
    * @return result 返回一个相应的海底世界的主题的值
    */
    UnderwaterWorldThemeRoom* GetProduct()
    {
        UnderwaterWorldThemeRoom* result = this->product;
        this->Reset();
        return result;
    }
};


/*温暖春日的建造者类
* 继承抽象的建造者类，完成温暖春日主题房间的设置和描述
* 重载抽象的建造者中的所有的函数
*/
class WarmSpringThemeBuilder : public  Abstract_builder
{
private:
    WarmSpringThemeRoom* product;//相应的温暖春日的实例
public:

    /*构造函数
    * 建造一个相应的海底世界房间
    */
    WarmSpringThemeBuilder()
    {
        this->Reset();
    }

    /*析构函数
    * 删除相应的海底世界的房间
    */
    ~WarmSpringThemeBuilder()
    {
        delete product;
    }

    /*创建产品
    * 为相应的产品进行赋值得到房间的类型
    * @return void
    */
    void Reset()
    {
        this->product = new WarmSpringThemeRoom();
    }
    /*床的描述
    * 重写父类的床的描述函数，对相应的温暖春日主题套房中的床进行相应的描述
    * @return void
    */
    void TellBedType()const override
    {
        std::cout << "温暖春日主题" << std::endl;
        std::cout << "床的类型为：吊床" << std::endl;
    }
    /*椅子的描述
   * 重写父类的椅子的描述函数，对相应的温暖春日主题套房中的椅子进行相应的描述
   * @return void
   */
    void TellChairType()const override
    {
        std::cout << "椅子的类型为：吊椅" << std::endl;
    }
    /*背景的描述
   * 重写父类的椅子的描述函数，对相应的温暖春日主题套房中的背景进行相应的描述
   * @return void
   */
    void TellWallType()const override
    {
        std::cout << "主题背景的类型为：浪漫樱花" << std::endl;
    }

    /*浴室的描述
    * 重写父类的浴室的描述函数，对相应的温暖春日主题套房中的浴室进行相应的描述
    * @return void
    */
    void TellBathType()const override
    {
        std::cout << "浴室配方为：玫瑰花浴" << std::endl;
    }

    /*床的设置
    * 重写父类的床的设置函数，对相应的温暖春日主题套房中的床进行相应的设置
    * @return void
    */
    void SetBedType()const override
    {
        this->product->parts_.push_back("吊床");
    }
    /*椅子的设置
    * 重写父类的椅子的设置函数，对相应的温暖春日主题套房中的椅子进行相应的设置
    * @return void
    */
    void SetChairType()const override
    {
        this->product->parts_.push_back("吊椅");
    }

    /*背景的设置
    * 重写父类的浴室的设置函数，对相应的温暖春日主题套房中的背景进行相应的设置
    * @return void
    */
    void SetWallType()const override
    {
        this->product->parts_.push_back("浪漫樱花");
    }
    /*浴室的设置
    * 重写父类的浴室的设置函数，对相应的温暖春日主题套房中的浴室进行相应的设置
    * @return void
    */
    void SetBathType()const override
    {
        this->product->parts_.push_back("玫瑰花浴");
    }

    /*温暖春日套房的创建
    * 创建相应的温暖春日的套房
    * @return result 返回一个相应的温暖春日的主题的值
    */
    WarmSpringThemeRoom* GetProduct()
    {
        WarmSpringThemeRoom* result = this->product;
        this->Reset();
        return result;
    }
};

/*一见钟情套房的建造者类
* 继承抽象的建造者类，完成一见钟情主题房间的设置和描述
* 重载抽象的建造者中的所有的函数
*/
class FallInLoveThemeBuilder : public  Abstract_builder
{
private:
    FallInLoveThemeRoom* product;//相应的一见钟情的套房的实例
public:
    /*构造函数
    * 建造一个相应的一见钟情房间
    */
    FallInLoveThemeBuilder()
    {
        this->Reset();
    }
    /*析构函数
    * 删除相应的一见钟情的房间
    */
    ~FallInLoveThemeBuilder()
    {
        delete product;
    }

    /*创建产品
    * 为相应的产品进行赋值得到房间的类型
    * @return void
    */
    void Reset()
    {
        this->product = new FallInLoveThemeRoom();
    }
    /*床的描述
   * 重写父类的床的描述函数，对相应的一见钟情主题套房中的床进行相应的描述
   * @return void
   */
    void TellBedType()const override
    {
        std::cout << "一见钟情主题" << std::endl;
        std::cout << "床的类型为：圆床" << std::endl;
    }
    /*椅子的描述
    * 重写父类的椅子的描述函数，对相应的一见钟情主题套房中的椅子进行相应的描述
    * @return void
    */
    void TellChairType()const override
    {
        std::cout << "椅子的类型为：摇椅" << std::endl;
    }
    /*背景的描述
    * 重写父类的背景的描述函数，对相应的一见钟情主题套房中的背景进行相应的描述
    * @return void
    */
    void TellWallType()const override
    {
        std::cout << "背景的类型为：丘比特" << std::endl;
    }
    /*浴室的描述
     * 重写父类的浴室的描述函数，对相应的一见钟情主题套房中的浴室进行相应的描述
    * @return void
    */
    void TellBathType()const override
    {
        std::cout << "浴室配方为：牛奶浴" << std::endl;
    }
    /*床的设置
   * 重写父类的床的设置函数，对相应的一见钟情主题套房中的床进行相应的设置
   * @return void
   */
    void SetBedType()const override
    {
        this->product->parts_.push_back("圆床");
    }
    /*椅子的设置
   * 重写父类的椅子的设置函数，对相应的一见钟情主题套房中的椅子进行相应的设置
   * @return void
   */
    void SetChairType()const override
    {
        this->product->parts_.push_back("摇椅");
    }
    /*背景的设置
   * 重写父类的浴室的设置函数，对相应的一见钟情主题套房中的背景进行相应的设置
   * @return void
   */
    void SetWallType()const override
    {
        this->product->parts_.push_back("丘比特");
    }
    /*浴室的设置
    * 重写父类的浴室的设置函数，对相应的一见钟情主题套房中的浴室进行相应的设置
    * @return void
    */
    void SetBathType()const override
    {
        this->product->parts_.push_back("牛奶浴");
    }
    /*一见钟情套房的创建
    * 创建相应的一见钟情主题的套房
    * @return result 返回一个相应的一见钟情的主题的值
    */
    FallInLoveThemeRoom* GetProduct()
    {
        FallInLoveThemeRoom* result = this->product;
        this->Reset();
        return result;
    }
};


/*主管类
* 主管类类定义相应的房间的构造步骤和顺序
* 主管类定义了介绍房间和构造房间两种相应的方法
*/
class Director
{
private:
    Abstract_builder* builder;
public:
    /*初始化builder
    * 将相应的指针指向builder
    * @return void
    */
    void set_builder(Abstract_builder* builder)
    {
        this->builder = builder;
    }
    /*介绍房间
    * 当用户查问相应的户型的时候，依次输出介绍相应的主题对应项目，调用房间builder 的四个调用
    * @return void
    */
    void TellTotalRoom()
    {
        this->builder->TellBedType();
        this->builder->TellChairType();
        this->builder->TellWallType();
        this->builder->TellBathType();
    }
    /*建造房间
    * 根据用户的需要对相应的房间进行布置，调用房间builder的四部放置
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

/*抽象的备忘录类
* 定义了相应的备忘录中应该有的信息和操作
*/
class Memento
{
public:
    /*虚函数备忘录的名称
    * 备忘录中记录的相应的事件的名称
    * @return string
    */
    virtual std::string GetName() const = 0;

    /*虚函数备忘录的时间
   * 备忘录中记录的相应的事件的时间
   * @return string 返回时间字符串
   */
    virtual std::string date() const = 0;

    /*虚函数备忘录的状态
   * 备忘录中记录的相应的状态的名称
   * @return string
   */
    virtual std::string state() const = 0;
};

/*具体的备忘录类
* 继承抽象的备忘录类，完成相应的相关信息的记载
*
*/
class ConcreteMemento : public Memento
{
private:
    std::string state_;//相应的备忘录的状态
    std::string date_;//备忘录的日期

public:
    /*记录时间
    * 获取系统的时间并将其转化为字符串
    * @time_t_time 相应的系统时间
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
    /*构造函数
    * 输入相应的状态，并在记录本上记录相应的状态发生变化的时间
    */
    ConcreteMemento(std::string state) : state_(state)
    {
        this->state_ = state;
        std::time_t now = std::time(0);
        this->date_ = time_t2string(now);
    }
    /*状态函数
    * 重写父类中的 函数 将相应的状态进行转化
    * @return string
    */
    std::string state() const override
    {
        return this->state_;
    }

    /*记录名称
    * 重写父类函数中的函数，记录每一条记录的名称
    * return string
    */
    std::string GetName() const override
    {
        return this->date_ + " / (" + this->state_.substr(0, 30) + "...)";
    }
    /*记录时间
    * 重写父类函数中函数,记录相应的状态发生的时间
    * @return string
    */
    std::string date() const override
    {
        return this->date_;
    }
};

/*原生器类
* 记录有当前时刻自身的内部状态,负责创建一个备忘录
*/
class Originator
{

private:
    std::string state_;//相应的状态


public:
    //初始化原生器
    Originator(std::string state) : state_(state)
    {
        //std::cout << "记录本的原始状态是 " << this->state_ << "\n";
    }
    /*记录状态
    * 用户选择了相应的海底世界的主题，记录相应的状态
    * @return void
    */
    void RecordUnderWaterTheme()
    {
        this->state_ = "用户选择了主题海底世界";
        std::cout << "用户现在的状态为" << this->state_ << std::endl;
    }
    /*记录状态
    * 用户选择了相应的一见钟情的主题，记录相应的状态
    * @return void
    */
    void RecordFallInLoveTheme()
    {
        this->state_ = "用户选择了主题一见钟情";
        std::cout << "用户现在的状态为" << this->state_ << "\n";
    }
    /*记录状态
    * 用户选择了相应的温暖夏日的主题，记录相应的状态
    * @return void
    */
    void RecordWarmSpring()
    {
        this->state_ = "用户选择了主题温暖春日";
        std::cout << "用户现在的状态为" << this->state_ << "\n";
    }

    /*在备忘录中存储相应的状态
    * 创建一个新的备忘录的对象
    * return Memento
    */
    Memento* Save()
    {
        return new ConcreteMemento(this->state_);
    }
    /* 还原操作
     * 还原相应的备忘录的状态
     * @return void
     */
    void Restore(Memento* memento)
    {
        this->state_ = memento->state();
        std::cout << "用户现在的状态为：" << this->state_ << "\n";
    }
};




/* 管理者类
* 负责保存备忘录.但是不能对备忘录的内容进行操作
*/
class Caretaker
{

private:
    std::vector<Memento*> mementos_;//备忘录
    Originator* originator_;//原生器

public:
    //构造函数 床在哦相应的原生器
    Caretaker(Originator* originator) : originator_(originator)
    {
        this->originator_ = originator;
    }
    /*查看记录状态
    * 将相应的历史状态及其中的相应的信息进行存储
    * @return void
    */
    void Backup()
    {
        std::cout << "正在存储用户的信息记录\n";
        this->mementos_.push_back(this->originator_->Save());
    }
    /*回滚状态
    * 根据相应的备忘录中的记录 对执勤的状态进行一个个的回滚
    * return void
    */
    bool Undo() {
        if (!this->mementos_.size())
        {
			return false;;
        }
        Memento* memento = this->mementos_.back();
        this->mementos_.pop_back();
        std::cout << "回滚到用户的选择: " << memento->GetName() << "\n";

        try
        {
            this->originator_->Restore(memento);
			return true;
        }
        catch (...)
        {
            std::cout << "无可回滚的历史记录" << std::endl;
			return false;
        }
		return true;
    }
    /*显示备忘录的记录
    * 查看相应的历史记录（不包括现有的状态）
    * return void
    */
    void ShowHistory() const
    {
        std::cout << "记录本中的记录如下:\n";
        for (Memento* memento : this->mementos_)
        {
            if (memento->GetName() == "")
            {
                std::cout << "没有相应的记录" << std::endl;
            }
            std::cout << memento->GetName() << "\n";
        }
    }
};


/*抽象接口支付
* 支付的抽象接口
*/
class PayMethod
{
public:
    /*纯虚函数：支付
    * 完成相应的支付的操作
    * @return void
    */
    virtual void Pay() const = 0;
};

/*现金付款
* 继承相支付类，完成现金的付款
*/
class Cash : public PayMethod
{
public:
    /*支付函数
    * 重写父类中的支付函数，体现用现金的付款的过程
    * return void
    */
    void Pay() const override
    {
        std::cout << "正在支付，请稍后..." << std::endl;
        std::cout << "支付成功" << std::endl;
        std::cout << "订购成功：您的房间号为401！" << std::endl;
    }

};

/*支付宝付款类
* 继承支付类，用支付宝完成相应的支付代理现金
*/
class Alipay : public PayMethod {

private:
    Cash* real_subject_;//现金
    /*检验是否登录
    * @return bool
    */
    bool CheckAccess() const
    {
        // Some real checks should go here.
        std::cout << "您已经成功登录支付宝\n";
        return true;
    }
    /*结束之后反应相应的提示
    * return void
    */
    void endPay() const
    {
        std::cout << "支付宝提醒：您有一笔支出,请注意查验\n";
    }

public:
    Alipay(Cash* real_subject) : real_subject_(new Cash(*real_subject)) {
    }

    ~Alipay()
    {
        delete real_subject_;
    }
    /*支付函数
    * 重写相应的函数 完成相应的支付宝的支付
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

/*微信付款类
* 继承支付类，用微信完成相应的支付代理现金
*/
class Wechat : public PayMethod {

private:
    Cash* real_subject_;//现金
     /*检验是否登录
     * @return bool
     */
    bool CheckAccess() const
    {
        // Some real checks should go here.
        std::cout << "您已经成功登录微信\n";
        return true;
    }
    /*结束之后反应相应的提示
    * return void
    */
    void endPay() const
    {
        std::cout << "微信提醒：您有一笔支出\n";
    }

public:
    Wechat(Cash* real_subject) : real_subject_(new Cash(*real_subject)) {
    }

    ~Wechat()
    {
        delete real_subject_;
    }
    /*支付函数
    * 重写相应的函数 完成相应的微信的支付
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


/*用户类
* 定义相应的用户可以进行的操作
*/
class Client
{
public:
    void ThemeDetails(Director& director);//显示主题的内容
    void ClientChooseUnderWaterTheme(Director& director);//选择相应的房间类型
    void ClientChooseWarmingSpring(Director& director);
    void ClientChooseFallInLove(Director& director);
    void ClientPay(PayMethod& subject);//支付

};
/*房间的主题提示
* 对相应的房间进行信息的提示
* @Dircetor&director 相应的主管
* @return void
*/
void Client::ThemeDetails(Director& director)
{
    UnderwaterWorldThemeBuilder* builder_UWT = new UnderwaterWorldThemeBuilder();
    WarmSpringThemeBuilder* builder_WST = new WarmSpringThemeBuilder();
    FallInLoveThemeBuilder* builder_FIL = new FallInLoveThemeBuilder();

    std::cout << "本宾馆可以对相应的：床型，椅子型，背景和浴室类型进行选择" << std::endl;
    std::cout << "并推出如下主题套餐：" << std::endl;
    std::cout << std::endl;
    //海底世界房间的介绍
    director.set_builder(builder_UWT);
    director.TellTotalRoom();
    UnderwaterWorldThemeRoom* p_UWT = builder_UWT->GetProduct();
    p_UWT->ListParts();

    //温暖春日的介绍
    director.set_builder(builder_WST);
    director.TellTotalRoom();
    WarmSpringThemeRoom* p_WST = builder_WST->GetProduct();
    p_WST->ListParts();

    //一见钟情的介绍
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

/*客户选择相应的海底世界主题
* 装饰相应的主题套件 并对相应的套件信息进行提示
* @Dircetor&director 相应的主管
* @return void
*/
void Client::ClientChooseUnderWaterTheme(Director& director)
{
    UnderwaterWorldThemeBuilder* builder_UWT = new UnderwaterWorldThemeBuilder();
    director.set_builder(builder_UWT);
    std::cout << "您选择的套餐为: 海底世界";
    std::cout << std::endl;
    UnderwaterWorldThemeRoom* p_UWT = builder_UWT->GetProduct();
    director.BuildTotalRoom();
    p_UWT = builder_UWT->GetProduct();
    p_UWT->ListParts();
    delete p_UWT;

}


/*客户选择相应的温暖春日主题
* 装饰相应的主题套件 并对相应的套件信息进行提示
* @Dircetor&director 相应的主管
* @return void
*/
void Client::ClientChooseWarmingSpring(Director& director)
{

    WarmSpringThemeBuilder* builder_WST = new WarmSpringThemeBuilder();
    director.set_builder(builder_WST);
    std::cout << "您选择的套餐为：温暖春日";
    std::cout << std::endl;
    WarmSpringThemeRoom* p_WST = builder_WST->GetProduct();
    director.BuildTotalRoom();
    p_WST = builder_WST->GetProduct();
    p_WST->ListParts();
    delete p_WST;
    delete builder_WST;
}

/*客户选择相应的一见钟情主题
* 装饰相应的主题套件 并对相应的套件信息进行提示
* @Dircetor&director 相应的主管
* @return void
*/
void Client::ClientChooseFallInLove(Director& director)
{
    FallInLoveThemeBuilder* builder_FIL = new FallInLoveThemeBuilder();
    director.set_builder(builder_FIL);
    std::cout << "您选择的套餐为：一见钟情";
    std::cout << std::endl;
    FallInLoveThemeRoom* p_FIL = builder_FIL->GetProduct();
    director.BuildTotalRoom();

    p_FIL = builder_FIL->GetProduct();
    p_FIL->ListParts();
    delete p_FIL;
    delete builder_FIL;
}

/*客户选择相应的支付函数
* @payMethod 相应的付款方式
* @return void
*/
void Client::ClientPay(PayMethod& subject)
{
    subject.Pay();
}


class HotelManager : public MacroCommandReceiver
{

private:
	/*构造函数
   * 构造函数为private，用于实现单例，tag为"Hotel"
   * @return void
   */
	HotelManager() : MacroCommandReceiver("Hotel") { }
	Originator* originator = new Originator("无已经完成的订单");
	Caretaker* caretaker = new Caretaker(originator);
protected:
	/*执行指令
   * 重载父类执行指令的纯虚函数，根据输入的命令执行相应操作
   * @param cmd 用户输入的指令内容
   * @return bool 指令格式是否正确
   */
	bool executeCommand(std::string cmd)
	{
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "HotelHelp")
		{
			if (cmd == "OrderRoomDetails")
			{
				std::cout << "欢迎查看相关的套餐" << std::endl;
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
				std::cout << "欢迎查看付款的方式" << std::endl;
				std::cout << "本店支持的付款方式有：现金，微信，支付宝" << std::endl;
				return true;
			}
			if (cmd == "HistorySearch")
			{
				std::cout << "您可以查询开房记录，并选择和上次一样的房型哦" << std::endl;
				return true;
			}
		}
		if (subCmd == "OrderRoom")
		{

			if (cmd == "UnderWaterTheme")
			{
				if (unPaid == true)
				{
					std::cout << "有待支付的房间" << std::endl;
					return true;
				}
				else {
					std::cout << "感谢您预定“海底世界”主题房间" << std::endl;
					Director* director = new Director();
					Client* client = new Client();
					client->ClientChooseUnderWaterTheme(*director);
					originator->RecordUnderWaterTheme();
					std::cout << "请您及时付款，以确认预定" << std::endl;
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
					std::cout << "有待支付的房间" << std::endl;
					return true;
				}
				else {
					std::cout << "感谢您预定“一见钟情”主题房间" << std::endl;
					Director* director = new Director();
					Client* client = new Client();
					client->ClientChooseFallInLove(*director);
					originator->RecordFallInLoveTheme();

					std::cout << "请您及时付款，以确认预定" << std::endl;
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
					std::cout << "有待支付的房间" << std::endl;
					return true;
				}
				else {
					std::cout << "感谢您预定“温暖春日”主题房间" << std::endl;
					Director* director = new Director();
					Client* client = new Client();
					client->ClientChooseWarmingSpring(*director);
					originator->RecordWarmSpring();
					std::cout << "请您及时付款，以确认预定" << std::endl;
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
					std::cout << "无待支付的预定" << std::endl;
					return true;
				}
				Client* client = new Client();
				std::cout << "用户使用现金支付\n";
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
					std::cout << "无待支付的预定" << std::endl;
					return true;
				}
				Cash* cash = new Cash;
				std::cout << "用户使用微信支付" << std::endl;
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
					std::cout << "无待支付的预定" << std::endl;
					return true;
				}
				Cash* cash = new Cash;
				std::cout << "用户使用支付宝支付\n";
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
				std::cout << "\n客户：我想要我上次的房间\n";
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
	/*打印可用指令
   * 重载父类虚函数，根据level打印对应格式的指令，以及可用子指令
   * @param level 当前Reciver在Reciver树中的层级
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
    std::cout << "微信支付" << std::endl;
    Wechat* wechat = new Wechat(cash);
    ClientCode(*wechat);
    delete cash;
    delete alipay;
    delete wechat;
    return 0;
}
*/



