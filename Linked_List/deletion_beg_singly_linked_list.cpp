#include<iostream>
using namespace std;
struct node{
int data;
struct node *next;
};
int main(){
	struct node *head,*newnode,*temp;
	head=0;
	int choice=1;
	while(choice){
		newnode=new node;
		cout<<"enter data:"<<" ";
		cin>>newnode->data;
		newnode->next=0;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=temp->next;
		}
		cout<<"do you want to continue(0,1)?"<<" ";
		cin>>choice;
	}
	temp=head;
	while(temp!=0){
		cout<<" ";
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<endl;
	struct node *ptr;
	if(head==NULL){
		cout<<" list is already empty:";
	}
	else{
		ptr=head;
		head=head->next;
		delete ptr;
	}
	
	
	
	cout<<"the linked list after deletion:"<<endl;
	temp=head;
	while(temp!=0){
		cout<<" ";
		cout<<temp->data;
		temp=temp->next;
	}
	return 0;
}
