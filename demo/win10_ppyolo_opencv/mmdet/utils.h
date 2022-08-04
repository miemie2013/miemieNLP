#ifndef __UTILS_H_
#define __UTILS_H_

#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "tensor.h"
#include <iostream>
#include <fstream>
using namespace std;


namespace mmdet {

class Utils
{
public:
	Utils() {

	}
	vector<string> split(string s, char ch) {
		int start = 0;
		int len = 0;
		vector<string> ret;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ch) {
				ret.push_back(s.substr(start, len));
				start = i + 1;
				len = 0;
			}
			else {
				len++;
			}
		}
		if (start < s.length())
			ret.push_back(s.substr(start, len));
		return ret;
	}


	void readTxt(string file, vector<string>& param_names, vector<string>& param_values)
	{
		ifstream infile;
		infile.open(file.data());   //���ļ����������ļ��������� 
		assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 

		string line;
		while (getline(infile, line))
		{
			vector<string> ss = split(line, ' ');
			param_names.push_back(ss[0]);
			param_values.push_back(ss[1]);
		}
		infile.close();             //�ر��ļ������� 
	}
};

} // namespace mmdet

#endif // __UTILS_H_

