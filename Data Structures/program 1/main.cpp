// Example program
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Method prototypes, since we're doing this all in one file for now.
int main();
string sum(string a, string b);
void remlzero(string &s);
string mult(string a, string b);
string subtr(string a, string b);
string square_root(string a, string b);

int main()
{
    string number1 = "14231";
    string number2 = "10342";
    
    cout << subtr(number1, number2) << endl;
    return 0;
}

string subtr (string a, string b) {
    //Begin subtract method code.
    while(a.length() < b.length()) {
        a = '0' + a;
    }
    while (b.length() < a.length()) {
        b = '0' + b;
    }
    //cout << number1 << endl;
    //cout << number2 << endl;
    
    //get the 9's compliment for the top number;
    string tempString = "";
    for (int i = a.length()-1; i >= 0; i--) {
        int Compliment = 9 - (a[i] - '0');
        char ComplimentChar = Compliment + '0';
        tempString = ComplimentChar + tempString;
        //cout << ComplimentChar << endl;
    }
    cout << tempString << endl;
    tempString = sum(tempString, b);
    cout << tempString << endl;
    string difference = "";
    for (int i = tempString.length()-1; i >=0; i--) {
        int Compliment = 9 - (tempString[i] - '0');
        char ComplimentChar = Compliment + '0';
        difference = ComplimentChar + difference;
    }
    remlzero(difference);
    cout <<"Final Difference : " << difference << endl;
}

string sum (string a, string b) {

	string s = "";
	while (a.length() < b.length()) a = "0"+a;
	while (b.length() < a.length()) b = "0"+b;
	a = "0"+a;
	b = "0"+b;
	int carry = 0;
	for (int i=a.length()-1; i >= 0; i--) {
		int S = a[i]-'0' + b[i]-'0' + carry;
		carry = S/10;
		S %= 10;
		s = ((char)(S+'0')) + s;
	}
	remlzero (s);
	return s;
}

void remlzero (string &s) {

	while (s!="" && s[0]=='0') s = s.substr(1);
	if (s=="") s= "0";
}

string mult (string a, string b) {

	string s = "0";
	for (int i=0; i < (int)a.length(); i++)
		for (int j=0; j < (int)b.length(); j++) {
			int p = (a[i]-'0')*(b[j]-'0');
//			string pstr = to_string ((long long)p);
			string pstr = ((string)"")+(char)(p/10+'0')+(char)(p%10+'0');
			for (int k=0; k < (int)a.length()-i-1 + (int)b.length()-j-1; k++)
				pstr += "0";
			s = sum (s,pstr);
		}
	return s;
}

//HOW THIS WORKS:
//String A shoudl always be the larger number. If it isn't you could run into issues with this.
//The subtraction and everything must be done with number A. Since number A is our primary focus when doing this, a lot of the method will interact with it.
string square_root(string a, string b) {
    string answer = "";
}