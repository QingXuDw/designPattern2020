#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "VisitorClasses.h"
#include "BaseClasses.h"

enum ICETYPE/*ö�����飬��Ӧ��ͬ�ı����൱�ڲ�Ʒ��ʶ��*/
{
    AT_Start = -1, AT_Cat, AT_Dog, AT_Cattle, AT_Sheep, AT_End
};

class CICE/*����һ��������*/
{
public:
    static CICE* CreateAnIce(ICETYPE typeCode, std::string name);
    virtual ~CICE() {};
    ICETYPE GetTypeCode() { return m_typeCode; }/*����ö������*/
    std::string GetTypeName() { return m_typeName; }/*���ر�������*/
    std::string GetColor() { return m_IceColor; }/*���ر�����ɫ*/
    std::string GetName() { return m_name; }/*���ر�������*/
    static CICE* m_exemplars[4];/*����һ�����飬�����洢����*/

protected:
    CICE(ICETYPE typeCode, std::string typeName, std::string strColor, std::string name);
    CICE* Clone(std::string name);/*��¡һ������*/

private:/*��ʼ���������������*/
    static CICE* ICENUM[4];
    ICETYPE m_typeCode;
    std::string m_IceColor;
    std::string m_typeName;
    std::string m_name;

public:
    friend std::ostream& operator<<(std::ostream& out, CICE* myself);
    CICE() {};

};
std::ostream& operator <<(std::ostream& out, CICE* myself) {
    out << myself->m_IceColor << ' ' << myself->m_typeName << ' ' << myself->m_name;
    return out;
}
CICE* CICE::m_exemplars[] =/*����������ʵ�����������������*/
{
    new CICE(AT_Cat,"è","��","����A��"),
    new CICE(AT_Dog,"��","��","��Ȯ�͸�"),
    new CICE(AT_Cattle,"ţ","��","ţ������"),
    new CICE(AT_Sheep,"��","��","����̩"),
};
CICE* CICE::CreateAnIce(ICETYPE typeCode, std::string name)/*����һ���µı���*/
{
    if (typeCode <= AT_Start || typeCode >= AT_End)
        return NULL;
    else
    {
        return m_exemplars[typeCode]->Clone(name);
    }

}
CICE::CICE(ICETYPE typeCode, std::string typeName, std::string strColor, std::string name)
{
    m_name = name;
    m_typeCode = typeCode;
    m_typeName = typeName;
    m_IceColor = strColor;
}
CICE* CICE::Clone(std::string name)/*��¡һ���µı���ʵ�ֶ������Ŀ���*/
{
    return new CICE(m_typeCode, m_typeName, m_IceColor, name);
}
class exhibit {
    exhibit() {};
public:
    //��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
    exhibit(const exhibit&) = delete;
    //��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
    exhibit& operator=(const exhibit&) = delete;
    /*
    * ��ȡȫ��Ψһ�����ã�����ʵ�ֵ�����
    * @return SkaterFactory& ����������������
    */
    static exhibit& getInstance() {
        static exhibit instance;
        return instance;
    }
    void showExhibit()/*������*/
    {
        std::cout << "����������ι۵ı����ţ���0-è��1-����2-ţ��3-���" << std::endl;
        int a;
        std::cin >> a;
        while (1) {
            if (std::cin.good())
            {
                break;
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(1024,'\n');
                std::cout << "�������ָ���������������룺" << std::endl;
                std::cin >> a;
            }
        }
        if(AT_Start<a&&a<AT_End)
        {
            CICE C;
            std::cout << C.m_exemplars[a];
        }
        else if(a<=AT_Start||a>=AT_End)
        {
            std::cout << "������ı�Ų����ڣ�" << std::endl;
        }
        std::cin.clear();
        string tmp;
        std::getline(std::cin, tmp);
    }
};


