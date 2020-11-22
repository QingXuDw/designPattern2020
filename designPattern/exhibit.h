#include <iostream>
#include <string>
#include <Windows.h>

enum ICETYPE/*枚举数组，对应不同的冰雕，相当于产品标识码*/
{
    AT_Start = -1, AT_Cat, AT_Dog, AT_Cattle, AT_Sheep, AT_End
};
class CICE/*定义一个冰雕类*/
{
   public:
      static CICE* CreateAnIce(ICETYPE typeCode, string name);
      virtual ~CICE() {};
      ICETYPE GetTypeCode() { return m_typeCode; }/*返回枚举类型*/
      string GetTypeName() { return m_typeName; }/*返回冰雕种类*/
      string GetColor() { return m_IceColor; }/*返回冰雕颜色*/
      string GetName() { return m_name; }/*返回冰雕名称*/
      static CICE* m_exemplars[4];/*定义一个数组，用来存储冰雕*/

   protected:
      CICE(ICETYPE typeCode, string typeName, string strColor, string name);
      CICE* Clone(string name);/*克隆一个冰雕*/

   private:/*初始化各个冰雕的属性*/
      static CICE* ICENUM[4];
      ICETYPE m_typeCode;
      string m_IceColor;
      string m_typeName;
      string m_name;

   public:
      friend ostream& operator<<(ostream& out, CICE* myself);
      CICE() {};

};

ostream& operator <<(ostream& out, CICE* myself) {
    out << myself->m_IceColor << ' ' << myself->m_typeName << ' ' << myself->m_name;
    return out;
}
CICE* CICE::m_exemplars[] =/*将各个冰雕实例化，存放在数组中*/
{
    new CICE(AT_Cat,"猫","白","哆来A梦"),
    new CICE(AT_Dog,"狗","黄","金犬送福"),
    new CICE(AT_Cattle,"牛","棕","牛气冲天"),
    new CICE(AT_Sheep,"羊","白","三羊开泰"),
};
CICE* CICE::CreateAnIce(ICETYPE typeCode, string name)/*创建一个新的冰雕*/
{
    if (typeCode <= AT_Start || typeCode >= AT_End)
        return NULL;
    else
    {
        return m_exemplars[typeCode]->Clone(name);
    }

}
CICE::CICE(ICETYPE typeCode, string typeName, string strColor, string name)
{
    m_name = name;
    m_typeCode = typeCode;
    m_typeName = typeName;
    m_IceColor = strColor;
}
CICE* CICE::Clone(string name)/*克隆一个新的冰雕，实现对自身的拷贝*/
{
    return new CICE(m_typeCode, m_typeName, m_IceColor, name);
}
class exhibit {
    exhibit();
    public:
        //标记复制构造函数为删除，用于实现单例
        exhibit(const exhibit&) = delete;
        //标记拷贝赋值操作符为删除，用于实现单例
        exhibit& operator=(const exhibit&) = delete;
        /*
        * 获取全局唯一的引用，用于实现单例。
        * @return SkaterFactory& 滑冰场工厂的引用
        */
        static exhibit& getInstance() {
            static exhibit instance;
            return instance;
        }
        void showExhibit()/*主函数*/
        {
            std::cout << "请输入您想参观的冰雕编号：（0-猫雕，1-狗雕，2-牛雕，3-羊雕）" << std::endl;
            int a;
            std::cin >> a;
            if (a<AT_Start || a>AT_End)
            {
                std::cout << "您输入的编号不存在！" << std::endl;
            }
            else
            {
                CICE C;
                std::cout << C.m_exemplars[a];
            }
        }
};
 