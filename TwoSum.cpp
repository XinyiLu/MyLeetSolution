/*
 * TwoSum.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: agnes
 */
#include <stdio.h>
#include <vector>
#include <map>


using namespace std;
class TwoSum {
public:
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
};


