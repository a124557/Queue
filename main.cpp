#include <iostream>
#include <string>

using namespace std;

struct Node{
  string data;
  Node* next;
};

class Queue{
Node* first = new Node;
Node* last = new Node;
int length;
public:
  Queue(){
    first->data = "";
    last->data = "";
    length = 0;
  }

void peek() {
  cout << "First: " << first->data << endl;
  cout << "Length: " << length << endl;
  }

void enqueue(string value) {
  if(length == 0) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = last;
    first = temp;
    last->data = "";
  }
    else if(length == 1) {
      last->data = value;
      
    }
  else {
    Node* temp = new Node;
    temp->data = value;
    last->next = temp;
    last = temp;
  }
  length++;
}

void dequeue() {
  if(first == last){
    first->data = "";
    last->data = "";
    length = 0;
  }
  else if(first->data != "") {
    Node* temp;
    temp = first->next;
    delete first;
    first = temp;
    length--;
  }
}

};

int main() {
  Queue obj;
  obj.enqueue("item1");
  obj.enqueue("item2");
  obj.dequeue();
  obj.dequeue();
  obj.dequeue();
  obj.enqueue("item4");
  obj.enqueue("item5");
  obj.enqueue("item6");
  obj.enqueue("item7");
  obj.enqueue("item8");
  obj.dequeue();
  obj.dequeue();
  obj.enqueue("item4");
  obj.enqueue("item5");
  obj.enqueue("item6");
  obj.peek();
  return 0;
}