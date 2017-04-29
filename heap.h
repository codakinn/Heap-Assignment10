#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
using namespace std;

template <class T>
class heap {
 private:
  vector<T> buffer;
  void insertHelper(int value, int current){
   while(buffer[current] != buffer.front())
    if(buffer[current] > buffer[(current-1)/2]){
      T temp = buffer[current];
      buffer[current] = buffer[(current-1)/2];
      buffer[(current-1)/2] = temp;
      insertHelper(value, (current-1)/2);
    }
  }

 void removeHelper(int current){
     int temp;
      T *c1 = buffer[2*current +1];
      T *c2 = buffer[2*(current+1)];
      T *parent = buffer[current];
      if(parent < c1 && parent < c2){
       if(c1 < c2){
        temp = parent;
        parent = c2;
        c2 = temp;
        removeHelper(2*(current+1));
       }
       else if (c2 <= c1){
        temp = parent;
        parent = c1;
        c1 = temp;
        removeHelper(2*current+1);
       }
      }
      else if(parent < c1 || parent < c2){
       if(parent < c1){
        temp = parent;
        parent = c1;
        c1 = temp;
        removeHelper(2*current+1);
       }
       else if (parent < c2) {
        temp = parent;
        parent = c2;
        c2 = temp;
        removeHelper(2*(current+1));
       }
      }
 }

 public:
  heap(){
    buffer.clear();
  }

  int size(){
    return buffer.size();
  }

  void insert(T value){
   if(buffer.empty())
     buffer.push_back(value);
   else{
     buffer.insert(value);
     insertHelper(value, size - 1);
   }
  }

  void remove_max(){
     if(!buffer.empty()){
      int current = 0;
      T temp = buffer.back();
      buffer[current] = temp;
      buffer.pop_back();
      removeHelper(0);
     }
  }
  T max(){
    return buffer.front();
  }
  void print(){
    int i;
    vector<T>::const_iterator = i;
    for(i = 0; i < buffer.size(); i++)
     cout << i << " - " << buffer[i] << endl;

  }
};

#endif
