#include <iostream>
#include <iomanip>

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
  float q1=0.0;
  float q3=0.0;
  
  Node* ptr1 = head;
  Node* ptr2 = ptr1->next;
  Node* ptr3 = ptr2->next;
  Node* ptr4 = ptr3->next;
  while(ptr4 != nullptr && ptr4->next != nullptr && ptr4->next->next != nullptr && ptr4->next->next->next != nullptr && ptr4->next->next->next->next!=nullptr){
    ptr1=ptr1->next;
    ptr2=ptr2->next->next;
    ptr3=ptr3->next->next->next;
    ptr4=ptr4->next->next->next->next;
  }
  if(ptr4->next==nullptr){
    q1 = ((long long)ptr1->value + (long long)ptr1->next->value)/2.0f;
    q3 = ((long long)ptr3->value + (long long)ptr3->next->value)/2.0f;
  }
  else if(ptr4->next->next==nullptr){
    q1 = ((long long)ptr1->value + (long long)ptr1->next->value)/2.0f;
     q3 = ((long long)ptr3->next->next->value + (long long)ptr3->next->value)/2.0f;
  }
  else if(ptr4->next->next->next==nullptr){
   q1=ptr1->next->value;
    q3=ptr3->next->next->value;
  }
  else{
    q1=ptr1->next->value;
    q3=ptr3->next->next->next->value;
    
    
  }

  return q3-q1;
  
     
}
