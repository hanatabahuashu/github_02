#include<iostream>
using namespace std;
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
void fun(int x) {
	int s=0;
	int op=1;
	while(true) {
		if(x-op>=0) {
			s++;
			op*=2;
		} else break;
	}
	//cout<<"????: "<<s;
	cout<<s;
}
int kp;
string str;
void zhong(int arr[],int ki) {
	if(arr[ki*2+1]!=0) {
		zhong(arr,ki*2+1);
		arr[ki*2+1]=0;
	}
	str+=to_string(arr[ki])+" ";
	
	if(arr[ki*2+2]!=0) {
		zhong(arr,ki*2+2);
		arr[ki*2+2]=0;
	}
}
int main() {
	int n;
	freopen("1.txt","r",stdin);
	cin>>n;
	int x;
	int arr[1005]= {0};
	int op;
	int skp=0;
	while(n--) {
		deque<int>sop= {0};
		cin>>x>>arr[0];
		kp=x;
		skp=0;
		x--;
		while(true) {
			if(x>0) {
				x--;
				sop.push_back(sop.front()*2+1);
				cin>>arr[sop.front()*2+1];
				if(arr[sop.front()*2+1]==0) {
					skp++;
				} else skp=0;
			} else break;
			if(x>0) {
				x--;
				sop.push_back(sop.front()*2+2);
				cin>>arr[sop.front()*2+2];
				if(arr[sop.front()*2+1]==0) {
					skp++;
				} else skp=0;
			} else break;
			sop.pop_front();
		}
		str="";
		zhong(arr,0);
		str.erase(str.size()-1,1);
		cout<<str;
		arr[0]=0;
		cout<<endl;
		fun(kp-skp);
		if(n!=0)
			cout<<endl;
	}
}
