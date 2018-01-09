#ifndef _H_COMPARE_
#define _H_COMPARE_ value

template<typename T> class Compare
{
public:
	static bool lt(T item1, T item2);
};

template<typename T> bool Compare<T>::lt(T item1, T item2){
	return item1<item2;
}

struct SpecialData
{
	friend ostream& operator<<(ostream&, SpecialData &);
	int m_ntenor;
	int m_npir;
};

ostream & operator<<(ostream& os, SpecialData &out){
	os<<out.m_ntenor<<"..."<<out.m_npir;
	return os;
};

ostream& operator<<(ostream& os, SpecialData &out){
	os<<out.m_ntenor<<"..."<<out.m_npir;
	return os;
};

class SpecialCompare
{
public:
	static bool lt(SpecialData item1, SpecialData item2);
};

bool SpecialCompare::lt(SpecialData item1, SpecialData item2){
	return item1.m_npir < item2.m_npir;
}
#endif