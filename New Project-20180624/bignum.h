#ifndef __BIGNUM__
#define __BIGNUM__ 20180623L

#include <iostream>
#include <cstdio>
#include <string>
using std::string;
using std::pair;
using std::istream;
using std::ostream;

class numtool {
protected:
	numtool () { }
	static void add(string&, const string&);
	static void subtract(string&, const string&);
	static void multiply(string&, const string&);
	static void divide(string&, const string&);
	static void mod(string&, const string&);

	static void pow(string&, const string&);
	static void inc(string&);
	static void dec(string&);

	static bool less(const string&, const string&);
	static bool greater(const string&, const string&);
	static bool less_equal(const string&, const string&);
	static bool greater_equal(const string&, const string&);
	static bool equal(const string&, const string&);
	static bool not_equal(const string&, const string&);

	static void thin(string&);
	static void fit(string&);
	
	static string tostring(unsigned long long);
	static string tostring(const char*);
	static string tostring(const char*, const char*);
private:
	static void multiply_each(string&, char);
	static char divide_try(const string&, const string&);
	static pair<string::const_reverse_iterator, string::const_reverse_iterator>
    	mismatch(
	        string::const_reverse_iterator,
	        string::const_reverse_iterator,
	        string::const_reverse_iterator);
};

class ubignum : protected numtool {
public:
	ubignum();
	ubignum(unsigned long long);
	ubignum(const char*);
	ubignum(const string&);
	
	ubignum& operator= (const unsigned long long&);
	ubignum& operator= (const char*);
	ubignum& operator= (const string&);
	
	ubignum operator+ (const ubignum&) const;
	template<class T> ubignum operator+ (const T&) const;
	
	ubignum operator- (const ubignum&) const;
	template<class T> ubignum operator- (const T&) const;
	
	ubignum operator* (const ubignum&) const;
	template<class T> ubignum operator* (const T&) const;
	
	ubignum operator/ (const ubignum&) const;
	template<class T> ubignum operator/ (const T&) const;
	
	ubignum operator% (const ubignum&) const;
	template<class T> ubignum operator% (const T&) const;
	
	ubignum& operator+= (const ubignum&);
	template<class T> ubignum& operator+= (const T&);
	
	ubignum& operator-= (const ubignum&);
	template<class T> ubignum& operator-= (const T&);
	
	ubignum& operator*= (const ubignum&);
	template<class T> ubignum& operator*= (const T&);
	
	ubignum& operator/= (const ubignum&);
	template<class T> ubignum& operator/= (const T&);
	
	ubignum& operator%= (const ubignum&);
	template<class T> ubignum& operator%= (const T&);
	
	ubignum& operator++();
	ubignum operator++(int);
	
	ubignum& operator--();
	ubignum operator--(int);
	
	bool operator< (const ubignum&) const;
	template<class T> bool operator< (const T&) const;
	
	bool operator> (const ubignum&) const;
	template<class T> bool operator> (const T&) const;
	
	bool operator<= (const ubignum&) const;
	template<class T> bool operator<= (const T&) const;
	
	bool operator>= (const ubignum&) const;
	template<class T> bool operator>= (const T&) const;
	
	bool operator== (const ubignum&) const;
	template<class T> bool operator== (const T&) const;
	
	bool operator!= (const ubignum&) const;
	template<class T> bool operator!= (const T&) const;
	
	virtual ubignum& pow(const ubignum&);
	template<class T> ubignum& pow(const T&);
	friend ubignum pow(const ubignum&, const ubignum&);
	template<class T> friend ubignum pow(const ubignum&, const T&);
	
	char operator[] (unsigned int) const;
	char at(unsigned int) const;
	
	virtual string get() const;
	
	unsigned int size() const;
	bool set(unsigned int, char);
	bool set(unsigned int, int);
	bool isodd() const;
	bool iseven() const;
	
	friend istream& operator>> (istream&, ubignum&);
	friend ostream& operator<< (ostream&, const ubignum&);
	
	virtual void read(FILE* = stdin);
	virtual void write(FILE* = stdout);
	
	friend const char* strdo(const char*, ubignum&);
protected:
	string str;
};

class bignum : public ubignum {
public:
	bignum();
	bignum(const bignum&);
	bignum(const ubignum&);
	bignum(long long);
	bignum(const char*);
	bignum(const string&);
	
	bignum operator= (const bignum&);
	bignum operator= (const ubignum&);
	bignum operator= (long long);
	bignum operator= (const char*);
	bignum operator= (const string&);
	
	bignum operator+ (const bignum&) const;
	template<class T> bignum operator+ (const T&) const;
	
	bignum operator- (const bignum&) const;
	template<class T> bignum operator- (const T&) const;
	
	bignum operator* (const bignum&) const;
	template<class T> bignum operator* (const T&) const;
	
	bignum operator/ (const bignum&) const;
	template<class T> bignum operator/ (const T&) const;
	
	bignum operator% (const bignum&) const;
	template<class T> bignum operator% (const T&) const;
	
	bignum& operator+= (const bignum&);
	template<class T> bignum& operator+= (const T&);
	
	bignum& operator-= (const bignum&);
	template<class T> bignum& operator-= (const T&);
	
	bignum& operator*= (const bignum&);
	template<class T> bignum& operator*= (const T&);
	
	bignum& operator/= (const bignum&);
	template<class T> bignum& operator/= (const T&);
	
	bignum& operator%= (const bignum&);
	template<class T> bignum& operator%= (const T&);
	
	bool operator< (const bignum&) const;
	template<class T> bool operator< (const T&) const;
	
	bool operator> (const bignum&) const;
	template<class T> bool operator> (const T&) const;
	
	bool operator<= (const bignum&) const;
	template<class T> bool operator<= (const T&) const;
	
	bool operator>= (const bignum&) const;
	template<class T> bool operator>= (const T&) const;
	
	bool operator== (const bignum&) const;
	template<class T> bool operator== (const T&) const;
	
	bool operator!= (const bignum&) const;
	template<class T> bool operator!= (const T&) const;
	
	bignum& opposite();
	bignum operator- () const;
	
	bignum& abs();
	friend bignum abs(const bignum&);
	
	bignum& operator++ ();
	bignum operator++ (int);
	
	bignum& operator-- ();
	bignum operator-- (int);
	
	bignum& pow(const bignum&);
	template<class T> bignum& pow(const T&);
	
	friend bignum pow(const bignum&, const bignum&);
	template<class T> friend bignum pow(const bignum&, const T&);
	
	string get() const;
	
	bool ispostive() const;
	bool isnegative() const;
	
	friend istream& operator>> (istream&, bignum&);
	friend ostream& operator<< (ostream&, const bignum&);
	
	void read(FILE* = stdin);
	void write(FILE* = stdout);
	
	friend const char* strdo(const char*, bignum&);
private:
	bignum (const string&, bool);
	bool negative;
};

void numtool::add(string &a, const string &b) {
	int n = a.size() < b.size() ? a.size() : b.size(), temp = 0;
	string::iterator _begin = a.begin(), _end = _begin + n;
	string::const_iterator _next = b.begin();
	for(; _begin < _end; ++_begin, ++_next)
		*_begin = (temp = *_begin - 48 + *_next + temp / 10 - 48) % 10 + 48;
	a.append(b.begin() + n, b.end());
	for(_begin = a.begin() + n, _end = a.end(); _begin < _end && temp > 9; ++_begin)
		*_begin = (temp = *_begin + temp / 10 - 48) % 10 + 48;
	if(temp > 9) a.push_back(temp / 10 + 48);
	fit(a);
}

void numtool::subtract(string &a, const string &b) {
	if(less_equal(a, b)) { a = "0"; return; }
	int n = a.size() < b.size() ? a.size() : b.size(), temp = 10;
	string::iterator _begin = a.begin(), _end = _begin + n;
	string::const_iterator _next = b.begin();
	for(; _begin < _end; ++_begin, ++_next)
		*_begin = (temp = *_begin - *_next - (temp < 10) + 10) % 10 + 48;
	for(_begin = a.begin() + n, _end = a.end(); _begin < _end && temp < 10; ++_begin)
		*_begin = (temp = *_begin - 48 - (temp < 10) + 10) % 10 + 48;
	thin(a);
	fit(a);
}

void numtool::multiply(string &a, const string &b) {
	if(a == "0" || b == "0") { a = "0"; return; }
	if(a == "1") { a = b; return; }
	if(b == "1") return;
	if(b == "2") { add(a, a); return; }
	if(a == "2") { a = b; add(a, a); return; }
	string ans;
	for(string::const_reverse_iterator _begin = b.rbegin(), _end = b.rend(); _begin < _end; ++_begin) {
		string temp(a);
		ans.insert(0, 1, 48);
		multiply_each(temp, *_begin);
		add(ans, temp);
	}
	fit(a = ans);
}

void numtool::divide(string &a, const string &b) {
	if(a == "0" || less(a, b)) { a = "0"; return; }
	if(b == "0") { a = "0"; return; }
	if(equal(a, b)) { a = "1"; return; }
	string t(a.end() - b.size(), a.end()), ans;
	for(string::reverse_iterator _begin = a.rbegin() + b.size(), _end = a.rend(); _begin < _end; ++_begin) {
		ans.insert(0, 1, divide_try(t, b));
		string temp(b);
		multiply_each(temp, ans[0]);
		subtract(t, temp);
		if(t == "0") t[0] = *_begin;
		else t.insert(0, 1, *_begin);
	}
	ans.insert(0, 1, divide_try(t, b));
	thin(a = ans);
	fit(a);
}

void numtool::mod(string &a, const string &b) {
	if(less(a, b)) return;
	if(equal(a, b)) { a = "0"; return; }
	string t(a.end() - b.size(), a.end()), d;
	for(string::reverse_iterator _begin = a.rbegin() + b.size(), _end = a.rend(); _begin < _end; ++_begin) {
		d.insert(0, 1, divide_try(t, b));
		string temp(b);
		multiply_each(temp, d[0]);
		subtract(t, temp);
		if(t == "0") t[0] = *_begin;
		else t.insert(0, 1, *_begin);
	}
	d.insert(0, 1, divide_try(t, b));
	thin(d);
	string temp(b);
	multiply_each(temp, d[0]);
	subtract(t, temp);
	fit(a = t);
}

void numtool::pow(string &a, const string &b) {
	if(b == "0" || a == "1") { a = "1"; return; }
	if(b == "2") { multiply(a, a); return; }
	if(a == "0") { return; }
	string base(a), n(b); a = "1";
	while(n != "0") {
		if(n[0] & 1) multiply(a, base);
		multiply(base, base);
		divide(n, "2");
	}
}

void numtool::inc(string &a) {
	++a[0];
	string::iterator _begin = a.begin(), _end = --a.end(), _next = _begin + 1;
	for(; _begin < _end; ++_begin, ++_next)
		if(*_begin > 57) *_begin = 48, ++*_next;
		else return;
	if(*_begin > 57) *_begin = 48, a.push_back(49);
}

void numtool::dec(string &a) {
	if(a == "0") return; --a[0];
	for(string::iterator _begin = a.begin(), _end = --a.end(), _next = _begin + 1; _begin < _end; ++_begin, ++_next)
		if(*_begin < 48) *_begin = 57, --*_next;
		else break;
	thin(a); 
}

bool numtool::less(const string &a, const string &b) {
    if(a.size() != b.size()) return a.size() < b.size();
    else {
        pair<string::const_reverse_iterator, string::const_reverse_iterator> temp(mismatch(a.rbegin(), a.rend(), b.rbegin()));
		return temp.first == a.rend() ? false : *temp.first < *temp.second;
    }
}

bool numtool::greater(const string &a, const string &b) {
    if(a.size() != b.size()) return a.size() > b.size();
	else {
		pair<string::const_reverse_iterator, string::const_reverse_iterator> temp(mismatch(a.rbegin(), a.rend(), b.rbegin()));
		return temp.first == a.rend() ? false : *temp.first > *temp.second;
	}
}

bool numtool::less_equal(const string &a, const string &b) { return !greater(a, b); }

bool numtool::greater_equal(const string &a, const string &b) { return !less(a, b); }

bool numtool::equal(const string &a, const string &b) { return a.size() != b.size() ? false : mismatch(a.rbegin(), a.rend(), b.rbegin()).first == a.rend(); }

bool numtool::not_equal(const string &a, const string &b) { return a.size() != b.size() ? true : mismatch(a.rbegin(), a.rend(), b.rbegin()).first != a.rend(); }

void numtool::thin(string &a) {
	string::iterator _begin = a.begin(), _end = --a.end();
	for(; _begin < _end && *_end == 48; --_end);
	a.erase(_end + 1, a.end());
}

inline void numtool::fit(string &a) {
#if __cplusplus >= 201103L
	a.shrink_to_fit();
#endif
}

void numtool::multiply_each(string &a, char b) {
	int temp = 0; b -= 48;
	for(string::iterator _begin = a.begin(), _end = a.end(); _begin < _end; ++_begin)
		*_begin = (temp  = (*_begin - 48) * b + temp / 10) % 10 + 48;
	if(temp > 9) a.push_back(temp / 10 + 48);
}

char numtool::divide_try(const string &a, const string &b) {
	char l = 48, len = 11, half, mid;
	while(len > 0) {
		mid = l + (half = len >> 1);
		string temp(b);
		multiply_each(temp, mid);
		if(less_equal(temp, a)) l = mid + 1, len -= half - 1;
		else len = half;
	}
	return l - 1;
}

pair<string::const_reverse_iterator, string::const_reverse_iterator>
    numtool::mismatch(
        string::const_reverse_iterator _begin,
        string::const_reverse_iterator _end,
        string::const_reverse_iterator _next) {
    while(_begin < _end)
        if(*_begin != *_next) break;
        else ++_begin, ++_next;
    return pair<string::const_reverse_iterator, string::const_reverse_iterator>(_begin, _next);
}

string numtool::tostring(unsigned long long a) {
	string ans;
	while(a) ans.push_back(a % 10 + 48), a /= 10;
	if(ans.empty()) ans.push_back(48);
	thin(ans);
	return ans;
}

string numtool::tostring(const char *a) {
	string ans;
	for(; *a > 47 && *a < 58; ++a) ans.push_back(*a);
	if(ans.empty()) ans.push_back(48);
	for(string::iterator _begin = ans.begin(), _end = --ans.end(); _begin < _end; ++_begin, --_end) {
		char t = *_begin; *_begin = *_end; *_end = t;
	}
	thin(ans);
	return ans;
}

string numtool::tostring(const char *_begin, const char *_end) {
	string ans; --_end;
	while(_begin <= _end) ans.push_back(*_end);
	if(ans.empty()) ans.push_back(48);
	thin(ans);
	return ans;
}

ubignum::ubignum() : str("0") { }
ubignum::ubignum(unsigned long long it) : str(tostring(it)) { }
ubignum::ubignum(const char *it) : str(tostring(it)) { }
ubignum::ubignum(const string &it) : str(tostring(it.c_str())) { }

ubignum& ubignum::operator= (const unsigned long long &it) { str = tostring(it); return *this; }
ubignum& ubignum::operator= (const char *it) { str = tostring(it); return *this; }
ubignum& ubignum::operator= (const string &it) { str = tostring(it.c_str()); return *this; }

ubignum ubignum::operator+ (const ubignum &it) const{ ubignum temp(*this); add(temp.str, it.str); return temp; }
template<class T> ubignum ubignum::operator+ (const T &it) const{ return *this + ubignum(it); }

ubignum ubignum::operator- (const ubignum &it) const{ ubignum temp(*this); subtract(temp.str, it.str); return temp; }
template<class T> ubignum ubignum::operator- (const T &it) const{ return *this - ubignum(it); }

ubignum ubignum::operator* (const ubignum &it) const{ ubignum temp(*this); multiply(temp.str, it.str); return temp; }
template<class T> ubignum ubignum::operator* (const T &it) const{ return *this * ubignum(it); }

ubignum ubignum::operator/ (const ubignum &it) const{ ubignum temp(*this); divide(temp.str, it.str); return temp; }
template<class T> ubignum ubignum::operator/ (const T &it) const{ return *this / ubignum(it); }

ubignum ubignum::operator% (const ubignum &it) const{ ubignum temp(*this); mod(temp.str, it.str); return temp; }
template<class T> ubignum ubignum::operator% (const T &it) const{ return *this % ubignum(it); }

ubignum& ubignum::operator+= (const ubignum &it) { add(str, it.str); return *this; }
template<class T> ubignum& ubignum::operator+= (const T &it) { return *this += ubignum(it); }

ubignum& ubignum::operator-= (const ubignum &it) { subtract(str, it.str); return *this; }
template<class T> ubignum& ubignum::operator-= (const T &it) { return *this -= ubignum(it); }

ubignum& ubignum::operator*= (const ubignum &it) { multiply(str, it.str); return *this; }
template<class T> ubignum& ubignum::operator*= (const T &it) { return *this *= ubignum(it); }

ubignum& ubignum::operator/= (const ubignum &it) { divide(str, it.str); return *this; }
template<class T> ubignum& ubignum::operator/= (const T &it) { return *this /= ubignum(it); }

ubignum& ubignum::operator%= (const ubignum &it) { mod(str, it.str); return *this; }
template<class T> ubignum& ubignum::operator%= (const T &it) { return *this %= ubignum(it); }

ubignum& ubignum::operator++() { inc(str); return *this; }
ubignum ubignum::operator++(int) { ubignum temp(*this); inc(temp.str); return temp; }

ubignum& ubignum::operator--() { dec(str); return *this; }
ubignum ubignum::operator--(int) { ubignum temp(*this); dec(temp.str); return temp; }

bool ubignum::operator< (const ubignum &it) const{ return less(str, it.str); }
template<class T> bool ubignum::operator< (const T &it) const{ return *this < ubignum(it); }

bool ubignum::operator> (const ubignum &it) const{ return greater(str, it.str); }
template<class T> bool ubignum::operator> (const T &it) const{ return *this > ubignum(it); }

bool ubignum::operator<= (const ubignum &it) const{ return less_equal(str, it.str); }
template<class T> bool ubignum::operator<= (const T &it) const{ return *this <= ubignum(it); }

bool ubignum::operator>= (const ubignum &it) const{ return greater_equal(str, it.str); }
template<class T> bool ubignum::operator>= (const T &it) const{ return *this >= ubignum(it); }

bool ubignum::operator== (const ubignum &it) const{ return equal(str, it.str); }
template<class T> bool ubignum::operator== (const T &it) const{ return *this == ubignum(it); }

bool ubignum::operator!= (const ubignum &it) const{ return not_equal(str, it.str); }
template<class T> bool ubignum::operator!= (const T &it) const{ return *this != ubignum(it); }

ubignum& ubignum::pow(const ubignum &index) { numtool::pow(str, index.str); return *this; }
template<class T> ubignum& ubignum::pow(const T &index) { return pow(ubignum(index)); }

ubignum pow(const ubignum &a, const ubignum &b) { ubignum temp(a); numtool::pow(temp.str, b.str); return temp; }
template<class T> ubignum pow(const ubignum &a, const T &b) { ubignum temp(a); return temp.pow(ubignum(b)); }

char ubignum::operator[] (unsigned int pos) const{ return str[pos]; }
char ubignum::at(unsigned int pos) const{ return str.at(pos); }

string ubignum::get() const{ return string(str.rbegin(), str.rend()); }

unsigned int ubignum::size() const{ return str.size(); }

bool ubignum::set(unsigned int pos, char it) {
	if(pos >= str.size()) return false;
	if(it < 48 || it > 57) return false;
	str[pos] = it;
	return true;
}
bool ubignum::set(unsigned int pos, int it) {
	if(pos >= str.size()) return false;
	str[pos] = it % 10 + 48;
	return true;
}
bool ubignum::isodd() const{ return str[0] & 1; }
bool ubignum::iseven() const{ return !isodd(); }

istream& operator>> (istream &in, ubignum &it) {
	it.str.clear();
	char ch = in.get();
	for(; ch > 47 && ch < 58; ch = in.get()) it.str.push_back(ch);
	in.unget();
	if(it.str.empty()) it.str.push_back(48);
	for(string::iterator _begin = it.str.begin(), _end = --it.str.end(); _begin < _end; ++_begin, --_end) {
		char t = *_begin; *_begin = *_end; *_end = t;
	}
	numtool::thin(it.str);
	return in;
}
ostream& operator<< (ostream &out, const ubignum &it) { return out << it.get(); }

void ubignum::read(FILE *fp) {
	str.clear();
	char ch = fgetc(fp);
	for(; ch > 47 && ch < 58; ch = fgetc(fp)) str.push_back(ch);
	ungetc(ch, fp);
	if(str.empty()) str.push_back(48);
	for(string::iterator _begin = str.begin(), _end = --str.end(); _begin < _end; ++_begin, --_end) {
		char t = *_begin; *_begin = *_end; *_end = t;
	}
	numtool::thin(str);
}
void ubignum::write(FILE *fp) { fprintf(fp, "%s", get().c_str()); }

const char* strdo(const char *a, ubignum &it) {
	it.str.clear();
	for(; *a > 47 && *a < 58; ++a) it.str.push_back(*a);
	if(it.str.empty()) it.str.push_back(48);
	for(string::iterator _begin = it.str.begin(), _end = --it.str.end(); _begin < _end; ++_begin, --_end) {
		char t = *_begin; *_begin = *_end; *_end = t;
	}
	numtool::thin(it.str);
	return a;
}

bignum::bignum() : ubignum("0"), negative(false) { }
bignum::bignum(const bignum &it) : negative(it.negative) { str = it.str; }
bignum::bignum(const ubignum &it) : ubignum(it), negative(false) { }
bignum::bignum(long long it) : negative(it < 0), ubignum(it < 0 ? -it : it) { }
bignum::bignum(const char *it) {
	switch(*it) {
	case '+': negative = false; ++it; break;
	case '-': negative = true; ++it; break;
	default: negative = false; break;
	}
	str = tostring(it);
	if(str == "0") negative = false;
}
bignum::bignum(const string &it) {
	const char *a = it.c_str();
	switch(*a) {
	case '+': negative = false; ++a; break;
	case '-': negative = true; ++a; break;
	default: negative = false; break;
	}
	str = tostring(a);
	if(str == "0") negative = false;
}

bignum bignum::operator= (const bignum &it) { str = it.str; negative = it.negative; return *this; }
bignum bignum::operator= (const ubignum &it) { str = tostring(it.get().c_str()); negative = false; return *this; }
bignum bignum::operator= (long long it) { negative = (it < 0); str = tostring(negative ? -it : it); return *this; }
bignum bignum::operator= (const char *it) {
	switch(*it) {
	case '+': negative = false; ++it; break;
	case '-': negative = true; ++it; break;
	default: negative = false; break;
	}
	str = tostring(it);
	if(str == "0") negative = false;
	return *this;
}
bignum bignum::operator= (const string &it) {
	const char *a = it.c_str();
	switch(*a) {
	case '+': negative = false; ++a; break;
	case '-': negative = true; ++a; break;
	default: negative = false; break;
	}
	str = tostring(a);
	if(str == "0") negative = false;
}

bignum bignum::operator+ (const bignum &it) const{ bignum temp(*this); return temp += it; }
template<class T> bignum bignum::operator+ (const T &it) const{ bignum temp(*this); return temp += bignum(it); }

bignum bignum::operator- (const bignum &it) const{ bignum temp(*this); return temp -= it; }
template<class T> bignum bignum::operator- (const T &it) const{ bignum temp(*this); return temp -= bignum(it); }

bignum bignum::operator* (const bignum &it) const{ bignum temp(*this); return temp *= it; }
template<class T> bignum bignum::operator* (const T &it) const{ bignum temp(*this); return temp *= bignum(it); }

bignum bignum::operator/ (const bignum &it) const{ bignum temp(*this); return temp /= it; }
template<class T> bignum bignum::operator/ (const T &it) const{ bignum temp(*this); return temp /= bignum(it); }

bignum bignum::operator% (const bignum &it) const{ bignum temp(*this); return temp %= it; }
template<class T> bignum bignum::operator% (const T &it) const{ bignum temp(*this); return temp %= bignum(it); }

bignum& bignum::operator+= (const bignum &it) {
	switch(negative) {
	case false:
		switch(it.negative) {
		case false: add(str, it.str); break;
		case true:
			if(less(str, it.str)) {
				bignum temp(it.str, true);
				subtract(temp.str, str);
				*this = temp;
			} else subtract(str, it.str); break;
		} break;
	case true:
		switch(it.negative) {
		case false:
			if(less(it.str, str)) subtract(str, it.str);
			else {
				bignum temp(it.str, false);
				subtract(temp.str, str);
				*this = temp;
			} break;
		case true: add(str, it.str); break;
		} break;
	}
	return *this;
}
template<class T> bignum& bignum::operator+= (const T &it) { return *this += bignum(it); }

bignum& bignum::operator-= (const bignum &it) {
	switch(negative) {
	case false:
		switch(it.negative) {
		case false:
			if(less(str, it.str)) {
				bignum temp(it.str, true);
				subtract(temp.str, str);
				*this = temp;
			} else subtract(str, it.str); break;
		case true: add(str, it.str); break;
		} break;
	case true:
		switch(it.negative) {
		case false: add(str, it.str); break;
		case true:
			if(less(it.str, str)) subtract(str, it.str);
			else {
				bignum temp(it.str, false);
				subtract(temp.str, str);
				*this = temp;
			} break;
		} break;
	}
	return *this;
}
template<class T> bignum& bignum::operator-= (const T &it) { return *this += bignum(it); }

bignum& bignum::operator*= (const bignum &it) {
	negative ^= it.negative;
	multiply(str, it.str);
	return *this;
}
template<class T> bignum& bignum::operator*= (const T &it) { return *this += bignum(it); }

bignum& bignum::operator/= (const bignum &it) {
	negative ^= it.negative;
	divide(str, it.str);
	return *this;
}
template<class T> bignum& bignum::operator/= (const T &it) { return *this += bignum(it); }

bignum& bignum::operator%= (const bignum &it) {
	negative ^= it.negative;
	mod(str, it.str);
	return *this;
}
template<class T> bignum& bignum::operator%= (const T &it) { return *this += bignum(it); }

bool bignum::operator< (const bignum &it) const{
	if(negative != it.negative) return negative;
	else return negative ? greater(str, it.str) : less(str, it.str);
}
template<class T> bool bignum::operator< (const T &it) const{ return *this < bignum(it); }

bool bignum::operator> (const bignum &it) const{
	if(negative != it.negative) return it.negative;
	else return negative ? less(str, it.str) : greater(str, it.str);
}
template<class T> bool bignum::operator> (const T &it) const{ return *this < bignum(it); }

bool bignum::operator<= (const bignum &it) const{ return !(*this > it); }
template<class T> bool bignum::operator<= (const T &it) const{ return *this < bignum(it); }

bool bignum::operator>= (const bignum &it) const{ return !(*this < it); }
template<class T> bool bignum::operator>= (const T &it) const{ return *this < bignum(it); }

bool bignum::operator== (const bignum &it) const{ return negative != it.negative ? false : equal(str, it.str); }
template<class T> bool bignum::operator== (const T &it) const{ return *this < bignum(it); }

bool bignum::operator!= (const bignum &it) const{ return negative != it.negative ? true : not_equal(str, it.str); }
template<class T> bool bignum::operator!= (const T &it) const{ return *this < bignum(it); }

bignum& bignum::opposite() { negative = !negative; return *this; }
bignum bignum::operator- () const{ return bignum(str, !negative); }

bignum& bignum::abs() { negative = false; return *this; }
bignum abs(const bignum &it) { bignum a(it); return a.abs(); }

bignum& bignum::operator++ () {
	if(negative)
		if(str == "1") str = "0", negative = false;
		else dec(str);
	else inc(str);
	return *this;
}
bignum bignum::operator++ (int) {
	bignum temp(*this);
	if(negative)
		if(str == "1") str = "0", negative = false;
		else dec(str);
	else inc(str);
	return temp;
}

bignum& bignum::operator-- () {
	if(negative) inc(str);
	else
		if(str == "0") str = "1", negative = true;
		else dec(str);
	return *this;
}
bignum bignum::operator-- (int) {
	bignum temp(*this);
	if(negative) inc(str);
	else
		if(str == "0") str = "1", negative = true;
		else dec(str);
	return temp;
}

bignum& bignum::pow(const bignum &index) {
	if(index.negative) str = "0", negative = false;
	else {
		negative &= index.isodd();
		numtool::pow(str, index.str);
	}
	return *this;
}
template<class T> bignum& bignum::pow(const T &index) { return pow(bignum(index)); }

bignum pow(const bignum &a, const bignum &b) { bignum temp(a); temp.pow(b); return temp; }
template<class T> bignum pow(const bignum &a, const T &b) { bignum _a(a), _b(b); _a.pow(_b); return _a; }

string bignum::get() const{
	string ans(negative ? "-" : "");
	ans.append(str.rbegin(), str.rend());
	return ans;
}

bool bignum::ispostive() const{ return !negative && str != "0"; }
bool bignum::isnegative() const{ return negative; }
bignum::bignum (const string &it, bool _negative) : negative(_negative) { str = it; }

istream& operator>> (istream &in, bignum &it) {
	it.str.clear();
	char ch = in.get();
	switch(ch) {
	case '+': it.negative = false; ch = in.get(); break;
	case '-': it.negative = true; ch = in.get(); break;
	default: it.negative = false; break;
	}
	for(; ch > 47 && ch < 58; ch = in.get()) it.str.push_back(ch);
	in.unget();
	if(it.str.empty()) it.str.push_back(48);
	for(string::iterator _begin = it.str.begin(), _end = --it.str.end(); _begin < _end; ++_begin, --_end) {
		char t = *_begin; *_begin = *_end; *_end = t;
	}
	numtool::thin(it.str);
	return in;
}
ostream& operator<< (ostream &out, const bignum &it) { return out << it.get(); }

void bignum::read(FILE *fp) {
	str.clear();
	char ch = fgetc(fp);
	switch(ch) {
	case '+': negative = false; ch = fgetc(fp); break;
	case '-': negative = true; ch = fgetc(fp); break;
	default: negative = false; break;
	}
	for(; ch > 47 && ch < 58; ch = fgetc(fp)) str.push_back(ch);
	ungetc(ch, fp);
	if(str.empty()) str.push_back(48);
	for(string::iterator _begin = str.begin(), _end = --str.end(); _begin < _end; ++_begin, --_end) {
		char t = *_begin; *_begin = *_end; *_end = t;
	}
	numtool::thin(str);
}
void bignum::write(FILE *fp) { fprintf(fp, "%s", get().c_str()); }

const char* strdo(const char *a, bignum &it) {
	it.str.clear();
	switch(*a) {
	case '+': it.negative = false; ++a; break;
	case '-': it.negative = true; ++a; break;
	default: it.negative = false; break;
	}
	for(; *a > 47 && *a < 58; ++a) it.str.push_back(*a);
	if(it.str.empty()) it.str.push_back(48);
	for(string::iterator _begin = it.str.begin(), _end = --it.str.end(); _begin < _end; ++_begin, --_end) {
		char t = *_begin; *_begin = *_end; *_end = t;
	}
	numtool::thin(it.str);
	return a;
}

#endif