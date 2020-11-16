#include"BaseClasses.h"
#include"TravelPlan.h"
#include<cstring>

class MainReciver : public MacroCommandReciver {
private:
	bool toContinue = true;
	MainReciver() : MacroCommandReciver("") {}
protected:
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		if (subCmd == "quit") {
			std::cout << "程序结束" << std::endl;
			return true;
		}
		return false;
	}
public:
	MainReciver(const MainReciver&) = delete;
	MainReciver& operator=(const MainReciver&) = delete;
	static MainReciver& getInstance() {
		static MainReciver reciver;
		return reciver;
	}
	void run() {
		std::string cmd;
		while (toContinue) {
			std::getline(std::cin, cmd);
			handleCommand(cmd);
		}
	}
};

class TestSpot : public MacroCommandReciver {
private:
	std::string str;
	TestSpot() : MacroCommandReciver("test") {}
protected:
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		if (subCmd == "setStr") {
			str = cmd;
			return true;
		}
		if (subCmd == "getStr") {
			std::cout << "str中存的内容是：" << str << std::endl;
			return true;
		}
		return false;
	}
public:

	TestSpot(const TestSpot&) = delete;
	TestSpot& operator=(const TestSpot&) = delete;
	static TestSpot& getInstance() {
		static TestSpot reciver;
		return reciver;
	}
};

class testPlanFactory : public AbstractPlanFactory {
public:
	Path* makePath() {
		Path path;
		path.vehicle = "car";
		return &path;
	}
	Description* makeDescription() {
		Description des;
		des.content = "this is a test Plan";
		return &des;
	}
	Spot* makeSpot() {
		Spot& spot = TestSpot::getInstance();
		return &spot;
	}
};

class PlanManager : public CommandReciver {
private:
	PlanManager() : CommandReciver("planManager") {}

	std::vector<Plan*> schedule;
	void createPlan(AbstractPlanFactory& factory) {
		Plan plan;
		plan.description = factory.makeDescription();
		plan.spot = factory.makeSpot();
		plan.path = factory.makePath();
		schedule.push_back(&plan);
		MainReciver::getInstance().addReciver(plan.spot);
	}
	std::string getDescription(int pos) {
		if (pos >= schedule.size() || pos < 0) {
			return "尚未设置该位置的计划";
		}
		return schedule[pos]->description->content;
	}
protected:
	bool executeCommand(std::string cmd) {
		std::string subCmd = sliceCommand(cmd);
		if (subCmd == "create") {
			if (cmd == "testSpot") {
				testPlanFactory factory;
				createPlan(factory);
				std::cout << "成功创建testSpot，指令为test" << std::endl;
				return true;
			}
			return false;
		}
		if (subCmd == "getDescription") {
			int pos = std::stoi(cmd);
			std::cout << getDescription(pos) << std::endl;
			return true;
		}
		std::cout << "有效指令为 testSpot 和 getDescription" << std::endl;
		return true;
		return false;
	}
public:
	PlanManager(const PlanManager&) = delete;
	PlanManager& operator=(const PlanManager&) = delete;
	static PlanManager& getInstance() {
		static PlanManager reciver;
		return reciver;
	}
	~PlanManager() {
		for (int i = 0; i < schedule.size(); i++)
		{
			if (schedule[i] != nullptr) {
				delete schedule[i];
			}
		}
	}
};



int main() {
	MainReciver& mainReciver = MainReciver::getInstance();
	mainReciver.addReciver(&PlanManager::getInstance());
	mainReciver.run();
}