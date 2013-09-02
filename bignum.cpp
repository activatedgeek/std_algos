#include<iostream>
#include<string>
using namespace std;

class bignum{
private:
	string s;
public:
	bignum(){}
	bignum(string s){
		this->s = s;
	}
	bignum operator+(bignum& add){
		string res="";
		int diff = s.length()- add.s.length();
		if(diff>0){
			string temp = "";
			for(int i=0;i<diff;i++)
				temp+='0';
			add.s = temp + add.s;
		}
		else if(diff<0){
			string temp = "";
			diff=-diff;
			for(int i=0;i<diff;i++)
				temp+='0';
			s = temp+s;
		}
		int k=s.length()-1,carry=0,temp;
		while(k>=0){
			temp=0;
			temp+= carry + int(s[k])-int('0') + int(add.s[k])-int('0');
			carry = temp/10;
			res+= char( int('0') + temp%10);
			k--;
		}
		if(carry!=0)
			res+= char( int('0') + carry);
			
		int len = res.length();
		for(k=0;k<len/2;k++){
			char temp = res[k];
			res[k] = res[len-k-1];
			res[len-k-1] = temp;
		}
		return bignum(res);
	}
	friend ostream &operator<<(ostream& out,bignum& num){
		out<<num.s;
		return out;
	}
	friend istream &operator>>(istream& in,bignum& num){
		in>>num.s;
		return in;
	}
	bignum operator-(bignum& sub){
		bool negate=false;
		if(s<sub.s){
			string temp=s;
			s=sub.s;
			sub.s=temp;
			negate=true;
		}
		string res="";
		int diff = s.length()- sub.s.length();
		if(diff>0){
			string temp = "";
			for(int i=0;i<diff;i++)
				temp+='0';
			sub.s = temp + sub.s;
		}
		else if(diff<0){
			string temp = "";
			diff=-diff;
			for(int i=0;i<diff;i++)
				temp+='0';
			s = temp+s;
		}
		int k=s.length()-1,temp;
		while(k>=0){
			temp = 0;
			if(s[k]<sub.s[k]){
				if(s[k]=='0')
					temp=10-sub.s[k];
				else if(s[k]>'0')
					temp = int(s[k]) - int(sub.s[k])+10;
				s[k-1]--;
			}
			else{
				temp = int(s[k])- int(sub.s[k]);
			}
			res+= char(int('0') +temp);
			k--;
		}
		int len = res.length();
		for(k=0;k<len/2;k++){
			char temp = res[k];
			res[k] = res[len-k-1];
			res[len-k-1] = temp;
		}
		if(negate){
			res='-'+res;
		}
		return bignum(res);
	}
	bignum operator=(bignum& in){
		string res=in.s;
		return bignum(res);
	}
	bignum operator*(bignum& in){
		string res="";
		return bignum(res);
	}
};
