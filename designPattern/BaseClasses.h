#pragma once
#include<string>
#include<vector>
#include<iostream>
/*������ϵ�ĸ���
* ��Ŀ�г��ֵ���������̳��Դ��࣬����Ϊ����
*/
class DPObject {};

/************************************************************************************
*																					*
*							CommandReceiverָ�������								*
*																					*
*	��ģ��ĸ���ָ�����������һ�ö����������Ŀ�ж������MainReciverΪ���ڵ㣬��	*
*	MacroCommandReceiver����������Ϊ��֧�ڵ㣬��CommandReceiver����������ΪҶ�ӽڵ�	*
*************************************************************************************/

/*ָ��������������
* ��Ŀ�г��ֵ�����ָ������߾��̳��Դ���
* ���뱻���ز���ʹ�õĴ��麯��Ϊbool executeCommand(std::string cmd)
*/
class CommandReceiver : public DPObject {
protected:
	/*ִ��ָ��
	* ���ղ���û�û�����cmd������cmd����ִ����Ӧ�Ĳ������ڲ�����cin
	* @param cmd �û������ָ������
	* @return bool ָ���ʽ�Ƿ���ȷ
	*/
	virtual bool executeCommand(std::string cmd) = 0;
	/*�Ƴ��ַ���ǰ�ո�
	* ����һ���ַ��������ã��Ƴ���ǰ���ո����޶���ո�ֱ�ӷ���
	* @param cmd ��������ַ���
	* @return void
	*/
	void removeBlank(std::string& cmd) {
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] != ' ') {
				cmd = cmd.substr(i);
				return;
			}
		}
	}
	/*ָ����Ƭ
	* ����һ���ַ��������ã����ݿո�ָ����Ϊ����ֵsubCmd������cmd�����֣���ָ��Ϊ�շ��ؿ��ַ���
	* @param cmd ��Ƭǰ����Ƭ���ַ���/��Ƭ��ո����ַ���
	* @return std::string ��Ƭ��ո�ǰ��֧����
	*/
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
	//��ǩ������ǰCommandReceiver��Ψһ��ʶ��
	std::string tag;
	/*��ӡ����ָ��
	* ����level��ӡ��Ӧ��ʽ��ָ�Ĭ�ϴ�ӡtag
	* @param level ��ǰReciver��Reciver���еĲ㼶
	* @return void
	*/
	virtual void printHelp(int level) {
		std::string head(level * 3, '-');
		std::cout << head + tag << std::endl;
	}
	/*����ָ��
	* ��ǰReciver�յ���ָ�����Ƚ���������д���Ĭ�ϴ���ʽ���Ƴ�ָ��ǰ�ո�
	* @param cmd �û������ָ������
	* @return void
	*/
	virtual void handleCommand(std::string cmd) {
		removeBlank(cmd);
		if (!executeCommand(cmd)) {
			std::cout << "��Чָ�����������ָ���ʽ" << std::endl;
			std::cout << "���һ����Чָ���µĿ���ָ��Ϊ��" << std::endl;
			printHelp(0);
		}
	}
	/*���캯��
	* ���캯����Ҫtag��ΪΨһ��ʶ��
	* @param tag_in ��ǩ
	* @return void
	*/
	CommandReceiver(std::string tag_in) {
		tag = tag_in;
	}
};
/*��ָ��������������
* �̳���ָ�������������࣬�ڲ�ά��һ��vector�����ӽ�����
*/
class MacroCommandReceiver : public CommandReceiver {
private:
	//�ӽ������б�
	std::vector<CommandReceiver*> receiverList;
	/*������ָ��
	* ������ָ���д�ƥ���tag������tagƥ���ӽ�������������ָ���ӽ�������ָ��
	* @param subCmd ��ƥ��ı�ǩ
	* @return CommandReceiver* ָ���ӽ�������ָ�루������Ӧ�ӽ���������nullptr��
	*/
	CommandReceiver* resolveSubCommand(std::string& subCmd) {
		for (std::vector<CommandReceiver*>::iterator i = receiverList.begin(); i != receiverList.end(); i++) {
			if (subCmd == (*i)->tag) {
				return (*i);
			}
		}
		return nullptr;
	}
public:
	/*���캯��
	* ���캯����Ҫtag��ΪΨһ��ʶ��
	* @param tag_in ��ǩ
	* @return void
	*/
	MacroCommandReceiver(std::string tag_in) : CommandReceiver(tag_in) {};
	/*��ӡ����ָ��
	* ����level��ӡ��Ӧ��ʽ��ָ�Ĭ���ȴ�ӡtag���ٵݹ�����ӽ�������printHelp������VLR
	* @param level ��ǰReciver��Reciver���еĲ㼶
	* @return void
	*/
	virtual void printHelp(int level) {
		std::string head(level * 3, '-');
		std::cout << head + tag << std::endl;
		level++;
		for (int i = 0; i < receiverList.size(); i++) {
			receiverList[i]->printHelp(level);
		}
	}
	/*����ӽ�����
	* ����ά��receiverList�����Ѵ���ͬtag�ӽ����������ʧ�ܣ�������ӵ��б�β
	* @param p_reciver ָ�����ӵ��ӽ�������ָ��
	* @return bool �Ƿ���ӳɹ�
	*/
	virtual bool addReceiver(CommandReceiver* p_reciver) {
		for (std::vector<CommandReceiver*>::iterator i = receiverList.begin(); i != receiverList.end(); i++) {
			if (tag == (*i)->tag) {
				return false;
			}
		}
		receiverList.push_back(p_reciver);
		return true;
	}
	/*�Ƴ��ӽ�����
	* ����ά��receiverList�����Ѵ���ͬtag�ӽ��������Ƴ�������ʧ��
	* @param tag ���Ƴ����ӽ������ı�ǩ
	* @return bool �Ƿ�ɹ�
	*/
	virtual bool removeReceiver(std::string tag) {
		for (std::vector<CommandReceiver*>::iterator i = receiverList.begin(); i != receiverList.end(); i++) {
			if (tag == (*i)->tag) {
				receiverList.erase(i);
				return true;
			}
		}
		return false;
	}
	/*�Ƴ��ӽ�����
	* ����ά��receiverList�����Ѵ���ͬtag�ӽ��������Ƴ�������ʧ��
	* @param p_reciver ָ����Ƴ����ӽ�������ָ��
	* @return bool �Ƿ�ɹ�
	*/
	virtual bool removeReceiver(CommandReceiver* reciver) { return removeReceiver(reciver->tag); }
	/*����ָ��
	* ��ǰReciver�յ���ָ�����Ƚ���������д���Ĭ�ϴ���ʽ��ƥ���ӽ���������ƥ��ʧ����ִ��ָ��
	* @param cmd �û������ָ������
	* @return void
	*/
	virtual void handleCommand(std::string cmd) {
		removeBlank(cmd);
		std::string subCmd = sliceCommand(cmd);
		CommandReceiver* childReciver = resolveSubCommand(subCmd);
		if (childReciver == nullptr) {
			if (!executeCommand(subCmd + cmd)) {
				std::cout << "��Чָ�����������ָ���ʽ" << std::endl;
				std::cout << "���һ����Чָ���µĿ���ָ��Ϊ��" << std::endl;
				printHelp(0);
			}
		}
		else {
			childReciver->handleCommand(cmd);
		}

	}
};