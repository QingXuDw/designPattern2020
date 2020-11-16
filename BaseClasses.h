#pragma once
#include<string>
#include<vector>
#include<iostream>
class DPObject {

};
class CommandReciver : public DPObject {
protected:
	virtual bool executeCommand(std::string cmd) = 0;
	void removeBlank(std::string& cmd) {
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] != ' ') {
				cmd = cmd.substr(i);
				return;
			}
		}
	}
	std::string sliceCommand(std::string& cmd) {
		std::string subCmd = "";
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] == ' ') {
				subCmd = cmd.substr(0, i);
				cmd = cmd.substr(i);
				return subCmd;
			}
		}
		subCmd = cmd;
		cmd = "";
		return subCmd;
	}
public:
	std::string tag;
	virtual void handleCommand(std::string cmd) {
		removeBlank(cmd);
		if (!executeCommand(cmd)) {
			std::cout << "无效指令请检查输入的指令格式" << std::endl;
		}
	}
	CommandReciver(std::string tag_in) {
		tag = tag_in;
	}
};
class MacroCommandReciver : public CommandReciver {
private:
	std::vector<CommandReciver*> reciverList;
	CommandReciver* resolveSubCommand(std::string& subCmd) {
		for (std::vector<CommandReciver*>::iterator i = reciverList.begin(); i != reciverList.end(); i++) {
			if (subCmd == (*i)->tag) {
				return (*i);
			}
		}
		return nullptr;
	}
public:
	MacroCommandReciver(std::string tag_in) : CommandReciver(tag_in) {};
	virtual bool addReciver(CommandReciver* reciver) {
		for (std::vector<CommandReciver*>::iterator i = reciverList.begin(); i != reciverList.end(); i++) {
			if (tag == (*i)->tag) {
				return false;
			}
		}
		reciverList.push_back(reciver);
		return true;
	}
	virtual bool removeReciver(std::string tag) {
		for (std::vector<CommandReciver*>::iterator i = reciverList.begin(); i != reciverList.end(); i++) {
			if (tag == (*i)->tag) {
				reciverList.erase(i);
				return true;
			}
		}
		return false;
	}
	virtual bool removeReciver(CommandReciver* reciver) { return removeReciver(reciver->tag); }
	virtual void handleCommand(std::string cmd) {
		removeBlank(cmd);
		std::string subCmd = sliceCommand(cmd);
		CommandReciver* childReciver = resolveSubCommand(subCmd);
		if (childReciver == nullptr) {
			if (!executeCommand(subCmd + cmd)) {
				std::cout << "无效指令请检查输入的指令格式" << std::endl;
			}
		}
		else {
			childReciver->handleCommand(cmd);
		}
	}
};