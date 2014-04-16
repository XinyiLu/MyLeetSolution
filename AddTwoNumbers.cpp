/*
 * AddTwoNumbers.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: agnes
 */
#include <stdio.h>

using namespace std;
 struct ListNode {
	  int val;
	  ListNode *next;
	  ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	 if(l1==NULL||l2==NULL){
		 return (l1==NULL)?l2:l1;
	 }

	 ListNode *pointer=new ListNode(0);
	 ListNode *pp=pointer;
	 int advance=0;
	 while(l1!=NULL&&l2!=NULL){
		 int sum=l1->val+l2->val+advance;
		 pp->next=new ListNode(sum%10);
		 advance=sum/10;
		 pp=pp->next;
		 l1=l1->next;
		 l2=l2->next;
	 }

	 if(l1!=NULL||l2!=NULL){
		 ListNode *pl3=(l1==NULL)?l2:l1;
		 while(pl3!=NULL){
			 int sum=pl3->val+advance;
			 pp->next=new ListNode(sum%10);
			 advance=sum/10;
			 pl3=pl3->next;
			 pp=pp->next;
		 }
	 }

	 if(advance>0){
		 pp->next=new ListNode(advance);
	 }
	 return pointer->next;
 }

