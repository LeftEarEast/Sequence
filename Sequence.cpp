#include "Sequence.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int mycmp(const void *p1, const void *p2)  
{  
    return strcmp(*(char**)p1, *(char**)p2);  
}  
  
int getLen(char *p, char *q)  
{  
    int ret = 0;  
    while ( *p && *p++ == *q++)  
        ++ret;  
    return ret;  
}

Sequence::Sequence(string filename)
{
	ifstream fin("dna.txt");
	string temp;
	getline(fin,DNA,'\n');
	while(getline(fin,temp,'\n'))
	{
	
	  DNA+=temp;
}
}

int Sequence::length()
{
	int len;
	len=DNA.length();
	return len;
}

int Sequence::numberOf(char base)
{
   int amount=0;
   for(int i=0;i<DNA.length();i++)
   {
   	  if(DNA[i]==base)
   	    amount++;
   }
  return amount;
}

string Sequence::longestConsecutive()
{
        int max=1;
	int left=0;
	int right=0;
	for(int i=0;i<length();i++)
	{
	  if(DNA[i]==DNA[i+1]&&i!=length()-1)
	  {
	    int  tempMax=1;
	   int j=i;char la=DNA[i];	 
	     j++;
	   while(DNA[j]==la)
	   {
	   	 tempMax++;
                  j++;
	   }	
	  if(tempMax>max)
	  {
	  	left=i;
	  	right=j-1;
                max=tempMax;
	  }
          	
	  }
    }
	string ans=DNA.substr(left,right-left+1);
        
        return ans;

	;
	
}

string Sequence::longestRepeated()
{

 char *s = new char[length()+1];  
    for (int i = 0; i<length(); i++)  
        s[i] = DNA[i];  
    s[length()] = '\0';  
  
    int len = DNA.length();  
    char **suffix = new char*[len];  
    for (int i = 0; i < len; i++)  
        suffix[i] = s + i;  
    qsort(suffix, len, sizeof(char*), mycmp);  
    int maxlen = 0;
	int ans=0;
    for ( int i = 0; i < len - 1; i++)  
    {  
        int tmp = getLen(suffix[i], suffix[i + 1]);  
        if (tmp>maxlen)  
		{maxlen = tmp; ans=i;}
    }  
    
    return string( suffix[ans], maxlen );
	delete s;  
    delete suffix;  

}



