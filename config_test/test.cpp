#include <iostream>
#include <fstream>
#include <istream>
#include "config.h"


using namespace std;

int main() {
	std::string strConfigFileName("config.ini");	//读取config.ini到字符串,项目路径下必须有文件
	Config config(strConfigFileName);				//初始化Config类
	//读取键值
	std::string strKey = "file_path";				
	std::string strValue;
	strValue = config.Read<std::string>(strKey);	
	std::cout << "Read Key " << strKey << "'s Value is " << strValue << std::endl;

	//读路径下的文件open()
	fstream infile;
	infile.open(strValue, std::ios::app);
	string str;
	if (infile) {
		cout << "config_file open scessful" << endl;
		getline(infile, str);//按行显示
		cout << str << endl;
		infile.close();
	}
	else
		cout << "config_file doesn't exist" << endl;

	system("pause");
	return 0;
}
