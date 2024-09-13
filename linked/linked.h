/*
*
* Linked:
*   A double-linked array library
*
* Aceinet (2022-2024)
*
*/

#ifndef _LINKED_H_
#define _LINKED_H_

#include <stddef.h>
#include <stdexcept>
#include <string>

namespace aceinetzxx {

  class LinkedError : public std::exception {
    public:
      std::string message;

      char *what(){
        return (char*)message.c_str();
      }
  };

  struct linked_entry {
		void* element;
		linked_entry* next;
		linked_entry* previous;
	};

	template<class T>
	class linked {
    public:
		  size_t element_size;
		  linked_entry* begin;

    public:
      // (de)constructors
      linked(){
        this->element_size = sizeof(T);
        this->begin = nullptr;
      }
       
      ~linked(){
        linked_entry *current_entry = this->begin;

        while(true){
          if(current_entry == NULL)
            return;

          linked_entry *old_entry = current_entry;
          current_entry = current_entry->next;
          delete old_entry;
        }
      }

      // array functions
      void push_back(T* arg){
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
      T* pop_back(){
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
      T* back(){
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
      size_t size(){
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
  };
}

#endif
