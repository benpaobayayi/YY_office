//100-200������ 
#include <iostream>
using namespace std;
int main( )
{
	int i,j;
	bool flag;
	for(i=101;i<200;i++) //��100-200�ڵ����� 
	{
		flag=true;
		j=2;
		while(flag && j<i)
		{
			if(i%j==0)
				flag=false;
			else j++;
		}
		if(flag)
			cout<<i<<" ";
	}
	return 0;
}

