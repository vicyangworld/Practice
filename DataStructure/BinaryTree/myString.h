#ifndef _H_MYSTRING_
#define _H_MYSTRING_ value

using std::ostream;
using std::istream;

const int MaxSize = 100;
class myString
{
private:
	int m_ncurlen;
	char *m_pstr;
	int *m_pnext;
public:
	myString(const myString & copy);
	myString(const char *init);
	myString();
	~myString(){
		delete [] m_pstr;
	}

	int Length() const{
		return m_ncurlen;
	}
	bool Find(myString part) const;
	char* GetBuffer() const;
	myString& operator()(int pos, int len);
	bool operator==(const myString cmp_str) const;
	bool operator!=(const myString cmp_str) const;
	bool operator<(const myString cmp_str) const;
	bool operator>(const myString cmp_str) const;
	bool operator!() const{
		return m_ncurlen==0;
	}

	myString& operator=(const myString& copy);
	myString& operator+=(const myString& add);
	char& operator[](int i);
	friend ostream& operator<<(ostream&, myString&);
	friend istream& operator>>(istream&, myString&);
};
#endif
