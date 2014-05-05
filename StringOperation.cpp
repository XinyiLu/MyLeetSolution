/*
 * StringOperation.cpp
 *
 *  Created on: May 5, 2014
 *      Author: agnes
 */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <map>
using namespace std;

class StringOperation{
public:

	bool isScramble(string s1, string s2) {

		if(s1.length()!=s2.length())
			return false;

		if(s1.length()<2){
			return s1==s2;
		}

		if(!isScrambleHelper(s1,s2))
			return false;
		for(int i=0;i<s1.length()-1;i++){
			if(isScramble(s1.substr(0,i+1),s2.substr(0,i+1))&&isScramble(s1.substr(i+1,s1.length()),s2.substr(i+1,s2.length()))){
				return true;
			}

			if(isScramble(s1.substr(0,i+1),s2.substr(s2.length()-i-1,s2.length()))&&isScramble(s1.substr(i+1,s1.length()),s2.substr(0,s1.length()-i-1)))
				return true;
		}

		return false;
	}

	bool isScrambleHelper(string s1,string s2){
		map<char,int> hash;
		for(int i=0;i<s1.length();i++){
			map<char,int>::iterator iter=hash.find(s1[i]);
			if(iter==hash.end()){
				hash.insert(std::pair<char,int>(s1[i],1));
			}else{
				iter->second++;
			}
		}

		for(int j=0;j<s2.length();j++){
			map<char,int>::iterator iter=hash.find(s2[j]);
			if(iter==hash.end()||iter->second==0)
				return false;
			iter->second--;
		}
		return true;
	}

};

int main(){

	StringOperation oper;
	cout<<oper.isScramble("abcdefghijklmnopq","efghijklmnopqcadb")<<endl;
	return 1;
}











