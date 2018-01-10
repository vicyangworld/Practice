#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "myString.h"

using std::cout;
using std::endl;
using std::ostream;
using std::istream;

myString::myString(){
	m_pstr = new char[MaxSize+1];
	if (!m_pstr)
	{
		cout<<"Application Error!"<<endl;
		exit(1);
	}
	this->m_ncurlen = 0;
	m_pstr[0]='\0';
}

myString::myString(const char *init){
	m_pstr = new char[MaxSize+1];
	if (!m_pstr)
	{
		cout<<"Application Error!"<<endl;
		exit(1);
	}
	this->m_ncurlen = strlen(init);
	strcpy(m_pstr,init);
}

myString::myString(const myString &copy){
	m_pstr = new char[MaxSize+1];
	if (!m_pstr)
	{
		cout<<"Application Error!"<<endl;
		exit(1);
	}
	this->m_ncurlen = copy.m_ncurlen;
	strcpy(m_pstr,copy.m_pstr);
}

bool myString::Find(myString part) const{
	int posP = 0;
	for (int i = 0; i < this->m_ncurlen; ++i)
	{
		if (part.m_pstr[posP] == this->m_pstr[i])
		{
			posP++;
		}		
	}
	if (posP != part.m_ncurlen)
	{
		return false;
	}
	else
	{
		return true;
	}
}


myString& myString::operator()(int pos, int len){
	myString *temp = new myString;
	if (pos<0 || pos+len-1>MaxSize || len<0)
	{
		temp->m_ncurlen = 0;
		temp->m_pstr[0]='\0';
	}
	else
	{
		if (pos+len-1>=m_ncurlen)
		{
			len = m_ncurlen - pos;
		}
		temp->m_ncurlen = len;
		for (int i = 0,j=pos; i < len; ++i,++j)
		{
			temp->m_pstr[i] = m_pstr[j];
		}
		temp->m_pstr[len]='\0';
	}
	return *temp;
}

bool myString::operator==(const myString cmp_str) const{
	if (this->m_ncurlen != cmp_str.m_ncurlen)
	{
		return false;
	}
	for (int i = 0; i < this->m_ncurlen; ++i)
	{
		if (this->m_pstr[i]!=cmp_str.m_pstr[i])
		{
			return false;
		}
	}
	return true;
}

bool myString::operator!=(const myString cmp_str) const{
	if (*this==cmp_str)
	{
		return false;
	}
	return true;
}

bool myString::operator<(const myString cmp_str) const{
	if (this->m_ncurlen != cmp_str.m_ncurlen)
	{
		return this->m_ncurlen < cmp_str.m_ncurlen;
	}
	for (int i = 0; i < this->m_ncurlen; ++i)
	{
		if (this->m_pstr[i] != cmp_str.m_pstr[i])
		{
			return this->m_pnext[i] < cmp_str.m_pnext[i];
		}
	}
	return false;
}

bool myString::operator>(const myString cmp_str) const{
	if (*this<cmp_str || *this==cmp_str)
	{
		return false;
	}
	return true;
}

myString& myString::operator=(const myString &copy) {
	delete [] this->m_pstr;
	this->m_pstr = new char[copy.m_ncurlen+1];
	strcpy(this->m_pstr, copy.m_pstr);
	return *this;
}

myString& myString::operator+=(const myString &add)
{
	int length = this->m_ncurlen + add.m_ncurlen;
	int n = this->m_ncurlen;
	myString temp(*this);
	delete [] this->m_pstr;
	this->m_pstr = new char[length+1];
	for (int i = 0; i < n; ++i)
	{
		this->m_pstr[i] = temp[i];
	}
	for (int i = n; i < length; ++i)
	{
		this->m_pstr[i]=add.m_pstr[i-n];
	}
	this->m_pstr[length] = '\0';
	return *this;
}

char& myString::operator[](int i){
	if (i<0 || i>=this->m_ncurlen)
	{
		cout<<"out of boundary!"<<endl;
		exit(1);
	}
	return this->m_pstr[i];
}

ostream& operator<<(ostream& outs, myString& str){
	outs<<str.m_pstr;
	return outs;
}


istream& operator>>(istream& ins, myString& str){
	ins>>str.m_pstr;
	return ins;
}
