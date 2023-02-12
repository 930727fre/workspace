#include <iostream>

using namespace std;
int main(){
    struct node{
        int data;
        node* next;
    };
    node* head=nullptr;
    node* tempNode=new node;
    node* prevNode=new node;
    int tempData;
    prevNode=head;
    while(cin>>tempData){
        if(head==nullptr){
            head=new node;
            prevNode=head;
            head->data=tempData;
        }
        else{
            tempNode = new node;
            prevNode->next=tempNode;
            tempNode->data=tempData;
            prevNode=tempNode;
        }
    }
    tempNode=head;
    while(tempNode){
        cout<<tempNode->data;
        tempNode=tempNode->next;
    }

}
