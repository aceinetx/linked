/*
*
* Linked:
*   A double-linked array library
*
* Aceinet (2022-2024)
*
*/

#include "linked.h"

char* aceinetzxx::LinkedError::what(){
  return (char*)this->message.c_str();
}

template<class T>
aceinetzxx::linked<T>::linked(){
  this->element_size = sizeof(T);
  this->begin = nullptr;
}

template<class T>
aceinetzxx::linked<T>::~linked(){
  linked_entry *current_entry = this->begin;
  while(true){
    if(current_entry == NULL)
      return;

    linked_entry *old_entry = current_entry;
    current_entry = current_entry->next;
    delete old_entry;
  }
}

template<class T>
void aceinetzxx::linked<T>::push_back(T* arg){
  if(this->begin == nullptr){
    this->begin = new aceinetzxx::linked_entry();
    this->begin->element = arg;
    this->begin->next = nullptr;
    this->begin->previous = nullptr;
  } else {
    linked_entry *current_entry = this->begin;
    while(true){
      if(current_entry->next == nullptr) break;
      current_entry = current_entry->next;
    }
    current_entry->next = new aceinetzxx::linked_entry();
    current_entry->next->element = arg;
    current_entry->next->next = nullptr;
    current_entry->next->previous = current_entry;
  }
}

template<class T>
T* aceinetzxx::linked<T>::pop_back(){
  linked_entry *current_entry = this->begin;
  while(true){
    if (current_entry->next == nullptr)
    {
      T *element = (T*)current_entry->element;
      if(current_entry->previous != nullptr) current_entry->previous->next = nullptr;
      delete current_entry;
      return element;
    }
    else
    {
      current_entry = current_entry->next;
    }
  }
}



template<class T>
T* aceinetzxx::linked<T>::back(){
  linked_entry *current_entry = this->begin;
  while(true){
    if (current_entry->next == nullptr)
    {
      return (T*)current_entry->element;
    }
    else
    {
      current_entry = current_entry->next;
    }
  }
}

template<class T>
size_t aceinetzxx::linked<T>::size(){
  size_t result = 0;

  linked_entry *current_entry = this->begin;
  while(true){

    result++;

    if(current_entry->next == nullptr)
      break;

    current_entry = current_entry->next;
  }

  return result;
}

// avoid link errors
// probably a bad idea I just don't want to research how to fix it now
void FixLinkErrors(){
  aceinetzxx::linked<int> linked;
  linked.push_back(nullptr);
  linked.pop_back();
  linked.back();
  linked.size();
}
