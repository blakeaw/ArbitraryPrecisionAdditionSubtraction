#include <stdlib.h>
#include <string>
#include <fstream>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>


using namespace std;

// Define Classes

// Prototype Functions
string itos( int Number );
int stoi( string input);
string ctos(char a);
string dtos(long double a);

// Main Function
int main(int argc, char *argv[])
{
//long double n1 =81238.9802809;
//long double n2 =84738.4394;
string num1 = "512345654321456789743254560089879867855675.068768765675343323268968670987099809775454987987985";
string num2 = "657688686444664462211353555455687867967799.146547356587888764433222222543547587908098";
//string num1 = dtos(n1);
//string num2 = dtos(n2);
cout << "num1: " << num1.c_str() << endl;
cout << "num2: " << num2.c_str() << endl;
//add
//first get sizes
int size1= num1.size();
int size2= num2.size();
//equalize the number of digits
int trackb1 = 0;
int tracka1 = 0;
int tag= 0;
for(int i =0;i<size1;++i){
	string current;
	current = ctos(num1[i]);
	if(current == "."){
		tag = 1;
	}
	if(tag==0){
		++trackb1;
	}
	if(tag==2){
		++tracka1;
	}
	if(tag==1){
		++tag;
	}
}
int trackb2=0;
int tracka2=0;
tag=0;
for(int i =0;i<size2;++i){
	string current = ctos(num2[i]);
	if(current == "."){
		tag = 1;
	}
	if(tag==0){
		++trackb2;
	}
	if(tag==2){
		++tracka2;
	}
	if(tag==1){
		++tag;
	}
}

if(trackb1>trackb2){
	int diff = trackb1-trackb2;
	string bar;
	for(int i=0;i<diff;++i){
		bar = "0";
		bar += num2;
		num2=bar;
	}
}
if(trackb2>trackb1){
	int diff = trackb2-trackb1;
	string bar;
	for(int i=0;i<diff;++i){
		bar = "0";
		bar += num1;
		num1=bar;
	}
}
if(tracka1>tracka2){
	int diff = tracka1-tracka2;
	for(int i=0;i<diff;++i){
		num2 += "0";
	}
}
if(tracka2>tracka1){
	int diff = tracka2-tracka1;
	for(int i=0;i<diff;++i){
		num1 += "0";
	}
}
cout << "After size matching: " << endl;
cout << " num1: " << num1.c_str() << endl;
cout << " num2: " << num2.c_str() << endl;

//now do addition of elements
string num3pre;
string num3;
int size = num1.size();
bool btag = 0;
for ( int i = size-1; i >= 0; --i)
{
	int c1 = stoi(ctos(num1[i]));
	int c2 = stoi(ctos(num2[i]));
	//cout << "c1: " << c1 << " c2: " << c2 << endl;
	if (c1>c2)
	{
		btag = 0;
	}
	else{
		btag = 1;
	}
	//cout << "btag: " << btag << endl; 
}
string bigger;
string smaller;
if (btag == 0)
{
	bigger = num1;
	smaller = num2;
}
if (btag==1)
{
	bigger = num2;
	smaller = num1;
}

int modtag = 0;
for(int i = size-1;i>=0;--i){
	//cout << "Value at current position " << i << " is " << ctos(num1[i]).c_str() << endl;
	if(ctos(bigger[i]) != "."){
		
		int c1 = stoi(ctos(bigger[i]));
		int c2 = stoi(ctos(smaller[i]));
	//	cout << "c1: " << c1 << " c2: " << c2 << endl;
		int diff = c1-c2;
	//	cout << "diff: " << diff << endl;
		if(modtag ==1){
			diff-=1;
			modtag=0;
		}
		if(diff<0){
			
			int mod = 10+diff;
			num3pre += itos(mod);
			modtag=1;
			
			
		}
		else{
			int adiff = abs(diff);
			num3pre+=itos(adiff);
			
		}	
	//	cout << "num3pre" << num3pre.c_str() << endl;
	}
	if(ctos(bigger[i]) == "."){
		//cout << "Going to add \".\" to num3pre" << endl;
		num3pre += ".";
	}
	if (i==0 && btag == 1)
	{
		num3pre += "-";
		++size;
	}
}

for(int i = size-1;i>=0;--i){
	//cout << "Current num3pre value at position " << i << " is " << ctos(num3pre[i]).c_str() << endl;
	num3+=ctos(num3pre[i]);
}
cout << "The difference of num1 and num2 is: " << num3.c_str() << endl;
return EXIT_SUCCESS;

}

// Define Functions

string itos( int Number ){
     ostringstream ss;
     ss << Number;
     return ss.str();
 }

int stoi( string input){
	
	int numb;
	istringstream ( input ) >> numb;
	return(numb);
}

string ctos(char a){
	ostringstream ss;
	ss << a;
	return ss.str();
}

string dtos(long double a){
	ostringstream ss;
	ss << setiosflags(ios::fixed) << setprecision(15) << a;
	return ss.str();
}



