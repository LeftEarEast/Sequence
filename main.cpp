#include "Sequence.h"
#include <iostream>
using namespace std;

int main()
{
	Sequence test("dna.txt");
   	int l=test.length();
	int A=test.numberOf('A');
	int T=test.numberOf('T');
	int C=test.numberOf('C');
    int G=test.numberOf('G');
    string haha=test.longestConsecutive();
   cout<<haha<<endl;
    cout<<l<<endl;
    cout<<A<<endl;
    cout<<T<<endl;
    cout<<C<<endl;
    cout<<G<<endl;
    string lala=test.longestRepeated();
	cout<<lala<<endl;
	return 0;
	
}
