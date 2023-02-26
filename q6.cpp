#include <iostream>
#include <string>

using namespace std;

const int MAX_QUEUE_SIZE = 100;

template<typename T>
class Queue {
 public:
  Queue() {
    front_ = -1;
    rear_ = -1;
  }
  
  void Insert(T data) {
    if (rear_ < MAX_QUEUE_SIZE - 1) {
      rear_++;
      items_[rear_] = data;
      if (front_ == -1) {
        front_ = 0;
      }
    }
  }
  
  T Delete() {
    T data = T();
    if (front_ != -1 && front_ <= rear_) {
      data = items_[front_];
      front_++;
    }
    return data;
  }
  
  void Display() {
    for (int i = front_; i <= rear_; i++) {
      cout << items_[i] << " ";
    }
    cout << endl;
  }
  
 private:
  int front_, rear_;
  T items_[MAX_QUEUE_SIZE];
};

int main() {
  Queue<int> int_queue;
  int_queue.Insert(10);
  int_queue.Insert(20);
  int_queue.Insert(30);
  int_queue.Display();
  int_queue.Delete();
  int_queue.Display();
  
  Queue<double> double_queue;
  double_queue.Insert(1.1);
  double_queue.Insert(2.2);
  double_queue.Insert(3.3);
  double_queue.Display();
  double_queue.Delete();
  double_queue.Display();
  
  Queue<string> string_queue;
  string_queue.Insert("item1");
  string_queue.Insert("item2");
  string_queue.Insert("item3");
  string_queue.Display();
  string_queue.Delete();
  string_queue.Display();
  
  return 0;
}
