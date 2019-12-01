#include<iostream>
using namespace std;

class fraction
{
private:
	int a,b;
   public:
	fraction()
	{
		a=0;
		b=1;
	}
	void getdata()
	{
		cout<<"Enter the fraction\n";
		cin>>a>>b;
		simplify();
	}
	void simplify()
	{
		int c;
		if(a>b)
			c=b;
		else
			c=a;
		for(int i=c;i>0;i--)
		{
			if(a%i==0)
			{
				if(b%i==0)
				{
					a=a/i;
					b=b/i;
					return;
				}
			}
		}
	}
	fraction operator +(fraction op);
	bool operator ==(fraction op);
	friend ostream &operator <<(ostream &output , const fraction &s);
	friend istream &operator >>(istream &input , fraction &s);
};

fraction fraction::operator +(fraction op)
{
	fraction temp;
	temp.a=(a*op.b)+(op.a*b);
	temp.b=b*op.b;
	temp.simplify();
	return temp;
}
bool fraction::operator ==(fraction op)
{
	if(a==op.a&&b==op.b)
		return true;
	else
		return false;
}
ostream& operator <<(ostream &output ,const fraction &s)
{
	output<<s.a<<"/"<<s.b<<endl;
	return output;
}
istream& operator>>(istream &input ,fraction &s)
{
	input>>s.a>>s.b;
	return input;
}

int main()
{
	fraction x,y;
	x.getdata();
	cout<<"enter fraction:"<<endl;
	cin>>y;
	if(x==y)
		cout<<"Fractions are equal\n";
	else
		cout<<"They are not equal\n";
	cout<<x;
	cout<<y;
	cout<<"SUM:";
	x=x+y;
	cout<<x;
}
