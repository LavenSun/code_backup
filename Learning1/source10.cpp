#if 0
//ÔËËã·ûÖØÔØ
#include<iostream>
using namespace std;
class Complex
{
public:
	Complex(int i = 0, int j = 0)
		:real(i), image(j){}
	//friend Complex operator + (Complex& a, Complex& b);
	Complex operator + (Complex& another);
	Complex& operator++();
	const Complex operator++(int);
	void display()
	{
		cout << real << "+" << image << "j" << endl;
	}
	Complex& operator+=(const Complex& another);
	Complex operator-();
	friend ostream& operator<<(ostream& os, const Complex& c)
	{
		return os << c.real << "+" << c.image << "j" << endl;
	}
	friend istream& operator>>(istream& is, Complex& t);
private:
	int real, image;
};
//Complex operator+(Complex& a, Complex& b)
//{
//	Complex ans(0, 0);
//	ans.real = a.real + b.real;
//	ans.image = a.image + b.image;
//	return ans;
//}
Complex Complex::operator + (Complex& another)
{
	Complex ans;
	ans.real = this->real + another.real;
	ans.image = this->image + another.image;
	return ans;
}
Complex& Complex::operator+=(const Complex& another)
{
	this->real += another.real;
	this->image += another.image;
	return *this;
}
Complex Complex::operator-()
{
	return Complex(-this->real, -this->image);
}
istream& operator>>(istream& is, Complex& t)
{
	is >> t.real >> t.image;
	return is;
}
Complex& Complex::operator++()
{
	this->real++;
	this->image++;
	return *this;
}
const Complex Complex::operator++(int)
{
	Complex t(this->real, this->image);
	this->real++;
	this->image++;
	return t;
}
class Mail;
class Send
{
public:
	Send(string s)
		:_address(s){}
	Send& operator<<(Mail& m);
private:
	string _address;
};
class Mail
{
public:
	Mail(string t1, string c, string t2)
		:_title(t1), _contents(c), _time(t2){}
	friend Send& Send::operator<<(Mail& m);
private:
	string _title;
	string _contents;
	string _time;
};
Send& Send::operator<<(Mail& m)
{
	cout << _address << endl;
	cout << m._title << endl;
	cout << m._contents << endl;
	cout << m._time << endl;
	return *this;
}
void SendTheEmail()
{
	Send s("570350003@qq.com");
	Mail m1("meeting", "AddSalary", "10.01"), m2("CancelMeeting", "joke", "9.30");
	s << m1 << m2;
}
class Pow
{
public:
	int operator()(int i)
	{
		return i * i;
	}
};
void PowOnYourOwn(int i)
{
	Pow p;
	cout << p(i) << endl;
}
int main()
{
	//Complex p;
	//cin >> p; //operator>>(cin, p);
	//cout << p;
	Complex x(1, 2), y(3, 4);
	Complex z = x + y;
	z.display();
	Complex w(3, 5);
	w += x;
	w.display();
	w += x += y;
	w.display();
	(w += x) += y;
	w.display();
	Complex c(1, 1);
	c = -w;
	c.display();
	c = -(-c);
	c.display();
	cout << c;
	SendTheEmail();
	PowOnYourOwn(2);
	return 0;
}
#endif