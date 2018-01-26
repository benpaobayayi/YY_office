//大数加法、减法、乘法 （正数） 
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string Translate(string str)
{
	char temp;
	int len,i;
	len=str.size();
	for(i=0;i<len/2;i++)
	{
		temp=str[i];
		str[i]=str[len-1-i];
		str[len-1-i]=temp;
	}
	return str;
}
int Compare(string a, string b)
{
	int f=0;
	int lenA,lenB,i;
	lenA=a.size();
	lenB=b.size();
	if(lenA>lenB) return 1;
	if(lenB>lenA) return -1;
	else{
		for(i=0;i<lenA;i++)
		{
			if(a[i]==b[i]) f=0;
			else if(a[i]>b[i]) return 1;
			else if(b[i]>a[i]) return -1;
		}
		if(f==0) return f;
	}
	return f;
}
string Delete_zero(string a)
{
	int n=0,i=a.size()-1;
	while(a[i]=='0')
	{
		n++;
		i--;
	}
	a=a.substr(0,a.length()-n);
	return a;
}

string Add(string a, int lenA, string b, int lenB)
{
	string c;
	int i,j,r,p,q;
	i=lenA-1;
	j=lenB-1;
	r=0;
	while(i>=0 || j>=0)
	{
		i>=0?p=a[i]-'0':p=0;
		j>=0?q=b[j]-'0':q=0;
		c+=(p+q+r)%10+'0';
		r=(p+q+r)/10;
		i--;j--;
	}
	if(r) c+=r%10+'0';
	c=Translate(c);
	return c;
}
string Multip_10(string s, int n)
{
	int i;
	string zero="";
	if(!n) return "0";
	for(i=0;i<n;i++)
		zero+="0";
	s+=zero;
	return s;
}
string Mul(string a, char b)
{
	string s="";
	int i,r,p,q,lenA;
	char c;
	lenA=a.size();
	r=0;
	q=b-'0';
	for(i=lenA-1;i>=0;i--)
	{
		p=(a[i]-'0');
		c=(p*q+r)%10+'0';
		r=(p*q+r)/10;
		s+=c;
	}
	if(r) s+=(r+'0');
	s=Translate(s);
	return s;
}
string Multip(string a, int lenA, string b, int lenB)
{
	if(a=="0" || b=="0")
		return "0";
	int i,j=0;
	string strA,strZ,strC,c="0";
	for(i=lenB-1;i>=0;i--)
	{
		strA=Mul(a,b[i]);
		strZ=Multip_10(strA,j);
		if(!j) c=Add(c,c.size(),strA,strA.size());
		else c=Add(c,c.size(),strZ,strZ.size());
		j++;
	}
	return c;
}
string Sub_M(string a, int lenA, string b, int lenB)
{
	string c;
	int i,j,p,q,r;
	i=lenA-1;
	j=lenB-1;
	r=0;
	while(i>=0)
	{
		i<0?p=0:p=a[i]-'0';
		j<0?q=0:q=b[j]-'0';
		if(r>0)
			p-=r;
		if(p<q) 
			r=1;
		else r=0;
		c+=(p+r*10-q)+'0';
		i--;
		j--;
	}
	return c;
}
string Subtra(string a, int lenA, string b, int lenB)
{
	string c;
	int f=Compare(a,b);
	if(f==0)
		c="0";
	else if(f==1)
	{
		c=Sub_M(a,lenA,b,lenB);
		c=Delete_zero(c);
	}
	else if(f==-1)
	{
		c=Sub_M(b,lenB,a,lenA);
		c=Delete_zero(c);
		c+="-";
	}
	c=Translate(c);
	return c;
}
int main()
{
	string a,b;
	string c;
	char m;
	cin>>a>>m>>b;
	int len_a,len_b;
	len_a=a.size();
	len_b=b.size();
	cout<<"a+b= "<<Add(a,len_a,b,len_b)<<endl;
	cout<<"a-b= "<<Subtra(a,len_a,b,len_b)<<endl;
	cout<<"a*b= "<<Multip(a,len_a,b,len_b)<<endl;
	return 0;
}
