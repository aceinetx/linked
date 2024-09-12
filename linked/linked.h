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

namespace aceinetzxx {

  class LinkedError : public std::exception {
    public:
      std::string message;

      char *what();
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
      linked();
      ~linked();

      // array functions
      void push_back(T*);
      T* pop_back();
      T* back();
      size_t size();
  };
}

#endif