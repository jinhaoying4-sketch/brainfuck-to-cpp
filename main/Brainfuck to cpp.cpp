#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include<cstdio>
#include <vector>
using namespace std;

//全局变量


//函数
void bfGo(string input,string output,int num){
	string tempLine;
	ifstream inp(input);
	ofstream out(output);
	out<<
	"#include<iostream>\n"
	"#include<cstdio>\n"
	"#include <cstdint>\n"
	"//brainfuck to cpp\n"
	"using namespace std;\n"
	"int main(){\n"
	"   static uint8_t array["<<num<<"] = {0};\n"
	"   uint8_t *ptr = array;\n"
	"   int temp;\n\n";
	while (getline(inp, tempLine)){
		for(char a : tempLine){
			if(a == '>') out<<"ptr++;//>\n";
			else if(a == '<') out<<"ptr--;//<\n";
			else if(a == '+') out<<"(*ptr)++;//+\n";
			else if(a == '-') out<<"(*ptr)--;//-\n";
			else if(a == '.') out<<"putchar(*ptr);fflush(stdout);//.\n";
			else if(a == ',') {
				out<<
				"(*ptr) = getchar();\n"
				"while ((temp = getchar()) != '\n' && temp != EOF);//,\n";
			}
			else if(a == '[') out<<"while(*ptr){//[\n";
			else if(a == ']') out<<"}//]\n";
		}
	}
	out<<
	"return *ptr;\n"
	"}\n";
	inp.close();
	out.close();
}

int main(){
	//主程序
	cout<<"brianfuck to cpp"<<endl;
	cout<<"입력할 .bf 파일 경로를 입력하세요:"<<endl;
	
	string i;
	string o;
	cin>>i;
	cout<<"출력할 C++ 파일명을 입력하세요 (예: output.cpp):"<<endl;
	cin>>o;
	cout<<"사용할 메모리 배열(格)의 크기를 입력하세요:"<<endl;
	int num;
	cin>>num;
	bfGo(i,o,num);
	cout<<"[성공] 변환이 완료되었습니다!"<<endl;
	
	return 0;
}
