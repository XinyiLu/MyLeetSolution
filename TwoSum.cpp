/*
 * TwoSum.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: agnes
 */
#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
double findMedianFromOneArray(int A[],int m);
double findMedianHelper(int A[],int m,int B[],int n,int left,int right);

    vector<int> twoSum(vector<int> &numbers, int target) {

    	vector<int> indices(2,0);
		map<int,vector<int> > positionMap;
		for(int i=0;i<numbers.size();i++){
			if(positionMap.end()==positionMap.find(numbers[i])){
				vector<int> newSet;
				positionMap.insert(std::pair<int,vector<int>>(numbers[i],newSet));
			}

			positionMap.find(numbers[i])->second.push_back(i+1);
		}

		for(std::pair<int,vector<int>> p:positionMap){
			int left=target-p.first;
			if(positionMap.end()==positionMap.find(left)||(left==p.first&&p.second.size()==1))
				continue;
			int leftIndex=p.second[0],rightIndex=(left==p.first?p.second[1]:positionMap.find(left)->second[0]);

			indices[0]=(min(leftIndex,rightIndex));
			indices[1]=(max(leftIndex,rightIndex));
			break;
		}

		return indices;
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	if(m==0||n==0){
    		return (n==0)?findMedianFromOneArray(A,m):findMedianFromOneArray(B,n);
    	}
    	int mid=(m+n)/2;

    	return findMedianHelper(A,m,B,n,max(0,m-mid-1),min(m-1,mid));
    }

    double findMedianHelper(int A[],int m,int B[],int n,int left,int right){
    	int midA=(left+right)/2;
    	int mid=(m+n)/2;
    	int bindex=mid-midA-1;

    	if(left>right){
    		return findMedianHelper(B,n,A,m,max(0,n-mid-1),min(n-1,mid));
    	}
    	else if((bindex==-1&&A[midA]<=B[0])||(A[midA]>=B[bindex]&&(bindex==n-1||B[bindex+1]>=A[midA]))){
    		if((m+n)%2==1){
				return A[midA];
			}else{
				int bindex=mid-midA-1;
				if(bindex<0||(midA>0&&A[midA-1]>=B[bindex])){
					return (A[midA]+A[midA-1])/2.0;
				}else{
					return (A[midA]+B[bindex])/2.0;
				}
			}
    	}
    	else if((bindex==-1&&A[midA]>B[0])||(A[midA]>=B[bindex]&&B[bindex+1]<A[midA])){
    		return findMedianHelper(A,m,B,n,left,midA-1);
    	}else{
    		return findMedianHelper(A,m,B,n,midA+1,right);
    	}

    }

    double findMedianFromOneArray(int A[],int m){
    	int mid=m/2;
    	if(m%2==1){
    		return A[mid];
    	}else{
    		return (A[mid-1]+A[mid])/2.0;
    	}
    }

    int lengthOfLongestSubstring(string s) {
    	map<char,int> recordMap;
		int len=0;
		int index=0,start=0;
		while(index<s.length()){
			map<char,int>::iterator iter=recordMap.find(s[index]);
			if(iter==recordMap.end()){
				recordMap.insert(std::pair<char,int>(s[index],index));
			}else if(iter->second<start){
				iter->second=index;
			}else{
				int firstIndex=iter->second;
				int tempLen=index-start;
				iter->second=index;
				len=max(len,tempLen);
				start=firstIndex+1;
			}
			index++;
		}


		return max(len,index-start);
    }



int main(){

    	int array1[]={3},array2[]={1,2};
    	cout<<findMedianSortedArrays(array1,1,array2,2)<<endl;

}
