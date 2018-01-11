#include <iostream>
#include "myString.h"

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	myString str1("rongbaobei");
	myString str2("xiaorongbaobeiainiyou");
	cout<<str2.Find(str1)<<endl;
	cout<<str2(2,3)<<endl;

	if (str1 < str2)
	{
		cout<<str1<<"<"<<str2<<endl;
	}
	if (str1 == str2)
	{
		cout<<str1<<"="<<str2<<endl;
	}
	if (str1 > str2)
	{
		cout<<str1<<">"<<str2<<endl;
	}
	cout<<"print st2: ";
	int length=str2.Length();
	for (int i = 0; i < length; ++i)
	{
		cout<<str2[i];
	}
	cout<<endl;

	str1+=str2;
	cout<<str1<<endl;
	str1=str2;
	cout<<str1<<endl;
	return 0;
}
