#include<iostream>
#include<string>
using namespace std;
void replaceDeststrFromStr(string &dest_str,string find_str,string replace_str,int start_pos);
void replaceDeststrFromStr(string &dest_str,string find_str,string replace_str,int start_pos,int time_hz);
void replaceDeststrFromStr(string &dest_str,string find_str,string replace_str,int start_pos,int time_hz) {
	int count=0;
	while(dest_str.find(find_str,start_pos)!=string::npos) {
		if(count==time_hz) {
			break;
		}
		dest_str.replace(dest_str.find(find_str,start_pos),find_str.length(),replace_str);
		start_pos+=find_str.length();
		count++;
	}
}
void replaceDeststrFromStr(string &dest_str,string find_str,string replace_str,int start_pos=0) {
	while(dest_str.find(find_str,start_pos)!=string::npos) {
		dest_str.replace(dest_str.find(find_str,start_pos),find_str.length(),replace_str);
		start_pos+=find_str.length();
	}
}
int main() {
	string inputstr="Xi'an Institute of Posts and Telecommunications is co-designed and implemented by the People's Government of Shaanxi Province and the Ministry of Industry and Information Technology.The Institute is located in Xi'an, a historic city in Northwest China, famous for its magnificent ancient culture.endInstitute University";
	string str1;
	string inputstr1;
	string deststr;
	string str;
	int endi=inputstr.find("end");
	int endj;
	int type;
	cin>>type;
	if(type) {
		str1=inputstr.substr(0,endi);
		inputstr=inputstr.substr(endi);
		endj=inputstr.find(" ");
		deststr=inputstr.substr(3,endj-3);
		str=inputstr.substr(endj+1);
	} else {
		while(true) {
			getline(cin,str1);
			if(str1.compare("end") == 0) {
				break;
			}
			inputstr1.append(str1);
		}
		str1=inputstr1.substr(0,inputstr1.find("end"));
		cin>>deststr>>str; 	
	}
	cout<<str1<<endl<<deststr<<endl<<str<<endl;
	replaceDeststrFromStr(str1,deststr,str,0);
	cout<<str1<<endl;
	return 0;
}
