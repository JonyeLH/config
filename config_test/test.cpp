#include <iostream>
#include <fstream>
#include <istream>
#include "config.h"


using namespace std;

int main() {
	std::string strConfigFileName("config.ini");	//��ȡconfig.ini���ַ���,��Ŀ·���±������ļ�
	Config config(strConfigFileName);				//��ʼ��Config��
	//��ȡ��ֵ
	std::string strKey = "file_path";				
	std::string strValue;
	strValue = config.Read<std::string>(strKey);	
	std::cout << "Read Key " << strKey << "'s Value is " << strValue << std::endl;

	//��·���µ��ļ�open()
	fstream infile;
	infile.open(strValue, std::ios::app);
	string str;
	if (infile) {
		cout << "config_file open scessful" << endl;
		getline(infile, str);//������ʾ
		cout << str << endl;
		infile.close();
	}
	else
		cout << "config_file doesn't exist" << endl;

	system("pause");
	return 0;
}
