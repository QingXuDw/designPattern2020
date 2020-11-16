#include"BaseClasses.h"
#include"TravelPlan.h"
#include"ShoppingMall.h"
#include<cstring>
/*��ָ�������
* �̳��ں�ָ�����������ָ�������������ĸ��ڵ㣬������ռ������벢�·�
*/
class MainReciver : public MacroCommandReciver {
private:
	//�Ƿ���������µ�����
	bool toContinue = true;
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ""
	* @return void
	*/
	MainReciver() : MacroCommandReciver("") {}

protected:
	/*ִ��ָ��
	* ���ظ���ִ��ָ��Ĵ��麯�����������������ִ����Ӧ����
	* @param cmd �û������ָ������
	* @return bool ָ���ʽ�Ƿ���ȷ
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);				//��Ƭ��ǰָ��
		removeBlank(cmd);									//�Ƴ�����ո�
		if (subCmd == "quit") {								//ƥ����ָ��
			std::cout << "�������" << std::endl;
			toContinue = false;								//����������ѭ��
			return true;									//���أ�ָ���ʽ��ȷ
		}
		if (subCmd == "help") {
			std::cout << "����ָ���б�Ϊ��" << std::endl;
			printHelp(0);
			return true;
		}
		return false;
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	MainReciver(const MainReciver&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	MainReciver& operator=(const MainReciver&) = delete;
	/*��ȡ������������
	* ��ȡȫ��Ψһ����������ʵ�������ã�����ʵ�ֵ�����
	* @return MainReciver& ��������������
	*/
	static MainReciver& getInstance() {
		static MainReciver reciver;
		return reciver;
	}
	/*����
	* ���н����û������ָ�����
	* @return void
	*/
	void run() {
		std::string cmd;
		std::cout << "����ָ�� help �鿴��ǰ����ָ��" << std::endl;
		while (toContinue) {
			std::cout << ">";
			std::getline(std::cin, cmd);
			handleCommand(cmd);
		}
	}
	/*��ӡ����ָ��
	* ���ظ����麯��������level��ӡ��Ӧ��ʽ��ָ��Լ�������ָ��
	* @param level ��ǰReciver��Reciver���еĲ㼶
	* @return void
	*/
	virtual void printHelp(int level) {
		__super::printHelp(level);				//���ø����Ĭ��printHelp�������ݹ������ǰ���ӽ�������tag
		level++;								//����ָ����ʾ����һ��
		std::string head(level * 3, '-');
		std::cout << head + "quit" << std::endl;	//�����ָ��
		std::cout << head + "help" << std::endl;	//�����ָ��
	}
};
/*���Եص�
* �̳���ָ�������������Ϊ������ʾʾ����ʵ����;
*/
class TestSpot : public CommandReciver {
private:
	//��¼���ַ���
	std::string str;
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"test"
	* @return void
	*/
	TestSpot() : CommandReciver("test") {}
protected:
	/*ִ��ָ��
	* ���ظ���ִ��ָ��Ĵ��麯�����������������ִ����Ӧ����
	* @param cmd �û������ָ������
	* @return bool ָ���ʽ�Ƿ���ȷ
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "setStr") {
			std::string paramTag1 = sliceCommand(cmd);		//ͨ����Ƭ��ָ���õ�һ�������ı�ǩ
			removeBlank(cmd);								//�Ƴ�����ո�
			if (paramTag1 == "-s") {
				str = cmd;
				return true;
			}
			cmd = paramTag1 + " " + cmd;					//�����и��ָ��ƴ��ȥ
		}
		if (subCmd == "getStr") {
			std::cout << "str�д�������ǣ�" << str << std::endl;
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
		__super::printHelp(level);				//���ø����Ĭ��printHelp�������ݹ������ǰ���ӽ�������tag
		level++;								//����ָ����ʾ����һ��
		std::string head(level * 3, '-');	
		std::cout << head + "setStr -s:���洢���ַ���" << std::endl;	//�����ָ��
		std::cout << head + "getStr" << std::endl;	//�����ָ��
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	TestSpot(const TestSpot&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	TestSpot& operator=(const TestSpot&) = delete;
	/*��ȡ��ǰ������������
	* ��ȡȫ��Ψһ��ǰ��������ʵ�������ã�����ʵ�ֵ�����
	* @return TestSpot& ��ǰ������������
	*/
	static TestSpot& getInstance() {
		static TestSpot reciver;
		return reciver;
	}
};

/*���Լƻ�����
* �̳��ڳ���ƻ�����������Ϊ������ʾʾ����ʵ����;
*/
class testPlanFactory : public AbstractPlanFactory {
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
		des->content = "this is a test Plan";
		return des;
	}
	/*����Ŀ��ص�
	* @return Path* ���ɵ�Ŀ��ص�
	*/
	Spot* makeSpot() {
		Spot& spot = TestSpot::getInstance();
		return &spot;
	}
};



/************************************************************************
*							ShoppingMallģ��							*
*************************************************************************/

class ShoppingManager : public CommandReciver
{

private:
	ShoppingManager() : CommandReciver("shop") {}
	std::vector<Shopping*> ShoppingList;

protected:
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);

		if (subCmd == "buy")
		{
			if (cmd == "AppleJuice")
			{
				ClientOption("buy", "AppleJuice");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "OrangeJuice")
			{
				ClientOption("buy", "OrangeJuice");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "AppleYogert")
			{
				ClientOption("buy", "AppleYogert");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "OrangeYogert")
			{
				ClientOption("buy", "OrangeYogert");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "AppleCandies")
			{
				ClientOption("buy", "AppleCandies");
				std::cout << std::endl;
				return true;
			}
			if (cmd == "OrangeCandies")
			{
				ClientOption("buy", "OrangeCandies");
				std::cout << std::endl;
				return true;
			}
			return false;
		}
		if (subCmd == "rent")
		{
			if (cmd == "sticks")
			{
				ClientOption("rent", "sticks");
				return true;
			}
			if (cmd == "board")
			{
				ClientOption("rent", "board");
				return true;
			}
		}



		return false;
	}
public:
	ShoppingManager(const ShoppingManager&) = delete;
	ShoppingManager& operator=(const ShoppingManager&) = delete;

	static ShoppingManager& getInstance()
	{
		static ShoppingManager reciver;
		return reciver;
	}

	virtual void printHelp(int level)
	{
		CommandReciver::printHelp(level);
		level++;
		std::string head(level * 3, '-');
		std::cout << head + "buy" << std::endl;
		std::cout << head + "---" + "AppleJuice" << std::endl;
		std::cout << head + "---" + "AppleYogert" << std::endl;
		std::cout << head + "---" + "AppleCandies" << std::endl;
		std::cout << head + "---" + "OrangeJuice" << std::endl;
		std::cout << head + "---" + "OrangeYogert" << std::endl;
		std::cout << head + "---" + "OrangeCandies" << std::endl;
		std::cout << head + "rent" << std::endl;
		std::cout << head + "---" + "sticks" << std::endl;
		std::cout << head + "---" + "board" << std::endl;
	}
	~ShoppingManager()
	{
		for (int i = 0; i < ShoppingList.size(); i++)
		{
			if (ShoppingList[i] != nullptr)
			{
				delete ShoppingList[i];
			}

		}
	}
};

/*�ƻ�������
* �̳���ָ���������������������ƻ�
*/
class PlanManager : public CommandReciver {
private:
	/*���캯��
	* ���캯��Ϊprivate������ʵ�ֵ�����tagΪ"plan"
	* @return void
	*/
	PlanManager() : CommandReciver("plan") {}
	//�ƻ��б�
	std::vector<Plan*> planList;
	/*�����¼ƻ�
	* ���ݴ������Ĺ������ã������µļƻ���������ƻ��б�β
	* @param factory Ŀ��ƻ�����������
	* @return void
	*/
	void createPlan(AbstractPlanFactory& factory) {
		Plan* plan = new Plan();
		plan->description = factory.makeDescription();
		plan->spot = factory.makeSpot();
		plan->path = factory.makePath();
		planList.push_back(plan);
		MainReciver::getInstance().addReciver(plan->spot);
	}
	/*��ȡ�ƻ���������
	* ��ȡ��pos+1��ļƻ�������������
	* @param pos �ƻ��ڼƻ��б��е�λ��
	* @return std::string ����
	*/
	std::string getDescription(int pos) {
		if (pos >= planList.size() || pos < 0) {
			return "��δ���ø�λ�õļƻ�";
		}
		return planList[pos]->description->content;
	}
protected:
	/*ִ��ָ��
	* ���ظ���ִ��ָ��Ĵ��麯�����������������ִ����Ӧ����
	* @param cmd �û������ָ������
	* @return bool ָ���ʽ�Ƿ���ȷ
	*/
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		removeBlank(cmd);
		if (subCmd == "create") {
			if (cmd == "testSpot") {
				testPlanFactory factory;
				createPlan(factory);
				std::cout << "�ɹ�����testSpot��ָ��Ϊtest" << std::endl;
				return true;
			}
			if (cmd == "shoppingMall") {
				MainReciver::getInstance().addReciver(&(ShoppingManager::getInstance()));
			}
			return false;
		}
		if (subCmd == "getDescription") {
			std::string paramTag1 = sliceCommand(cmd);		//ͨ����Ƭ��ָ���õ�һ�������ı�ǩ
			removeBlank(cmd);								//�Ƴ�����ո�
			if (paramTag1 == "-p") {
				int pos = std::stoi(cmd);
				std::cout << getDescription(pos) << std::endl;
				return true;
			}
			cmd = paramTag1 + " " + cmd;
		}
		return false;
	}
public:
	//��Ǹ��ƹ��캯��Ϊɾ��������ʵ�ֵ���
	PlanManager(const PlanManager&) = delete;
	//��ǿ�����ֵ������Ϊɾ��������ʵ�ֵ���
	PlanManager& operator=(const PlanManager&) = delete;
	/*��ȡ��ǰ������������
	* ��ȡȫ��Ψһ��ǰ��������ʵ�������ã�����ʵ�ֵ�����
	* @return PlanManager& ��ǰ������������
	*/
	static PlanManager& getInstance() {
		static PlanManager reciver;
		return reciver;
	}
	/*��ӡ����ָ��
	* ���ظ����麯��������level��ӡ��Ӧ��ʽ��ָ��Լ�������ָ��
	* @param level ��ǰReciver��Reciver���еĲ㼶
	* @return void
	*/
	virtual void printHelp(int level) {
		__super::printHelp(level);				//���ø����Ĭ��printHelp�������ݹ������ǰ���ӽ�������tag
		level++;								//����ָ����ʾ����һ��
		std::string head(level * 3, '-');
		std::cout << head + "create" << std::endl;								//�����ָ��
		std::cout << head + "---" + "testSpot" << std::endl;					//�����ָ��
		std::cout << head + "---" + "shoppingMall" << std::endl;					//�����ָ��
		std::cout << head + "getDescription -p:�ƻ����б��е�λ��" << std::endl;//�����ָ��
	}
	/*��������
	* ���ڷ�ֹ�ڴ�й¶���ݹ��ͷ�planList�еĶ���
	*/
	~PlanManager() {
		for (int i = 0; i < planList.size(); i++)
		{
			if (planList[i] != nullptr) {
				delete planList[i];
			}
		}
	}
};


int main() {
	MainReciver& mainReciver = MainReciver::getInstance();	//��ȡ��������������
	mainReciver.addReciver(&PlanManager::getInstance());	//��Ӽƻ���������������������
	mainReciver.run();										//����
}