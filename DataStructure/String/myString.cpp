#include <iostream>
#include <sctring>
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
	int posT = 0;
	int lengthP = part.m_ncurlen;
	int lengthT = this->m_ncurlen;

	part.next();
	while(posP<lengthP && posT<lengthT){
		if (part.m_pstr[posP] == this->m_pstr[posT])
		{
			posP++;
			posT++;
		}
		else
		{
			if (posP == 0)
			{
				posT++;
			}
			else
			{
				posP = part.m_pnext[posP-1];
			}
		}
	}
	delete [] part.m_pnext;
	if (posP<lengthP)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void myString::next(){
	int length = this->m_ncurlen;
	this->m_pnext = new int[length];
	this->m_pnext[0] = 0;
	for (int i = 1; i < length; ++i)
	{
		int j=this->m_pnext[i-1];
		while(*(this->m_pstr+i) != *(this->m_pstr+j) && j>0){
			j = this->m_pnext[j-1];
		}
		if (*(this->m_pstr+i) == *(this->m_pstr+j))
		{
			this->m_pnext[i] = j+1;
		}
		else
		{
			this->m_pnext[i] = 0;
		}
	}
}


char *myString::operator()(int pos, int len){
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
	for (int i = 0; i < thid->m_ncurlen; ++i)
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
	strcpy(this->m_pstr, copy.m_pster);
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
