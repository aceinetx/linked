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
#include <stdlib.h>
#include <cstring>

namespace aceinetzxx
{

  class LinkedError : public std::exception
  {
  public:
    std::string message;

    char *what()
    {
      return (char *)message.c_str();
    }

    LinkedError(std::string x)
    {
      message = x;
    }
  };

  struct linked_entry
  {
    char *element_bytes;
    linked_entry *next;
    linked_entry *previous;
  };

  template <class T>
  class linked
  {
  public:
    size_t element_size;
    linked_entry *begin;

  public:
    // (de)constructors
    linked()
    {
      this->element_size = sizeof(T);
      this->begin = nullptr;
    }

    ~linked()
    {
      linked_entry *current_entry = this->begin;

      while (true)
      {
        if (current_entry == NULL)
          return;

        linked_entry *old_entry = current_entry;
        current_entry = current_entry->next;
        delete old_entry->element_bytes;
        delete old_entry;
      }
    }

    // operators
    T &operator[](size_t i)
    {
      return at(i);
    }

    aceinetzxx::linked<T> operator*(int times)
    {
      aceinetzxx::linked<T> result;

      for (int i = 0; i < times; i++)
      {
        for (int j = 0; j < size(); j++)
        {
          result.push_back(this->operator[](j));
        }
      }

      return result;
    }

    void operator*=(int times)
    {
      size_t old_size = size();

      for (int i = 1; i < times; i++)
      {
        for (int j = 0; j < old_size; j++)
        {
          push_back(this->operator[](j));
        }
      }
    }

    // functions
    void push_back(T arg)
    {
      if (this->begin == nullptr)
      {
        this->begin = new aceinetzxx::linked_entry();
        this->begin->element_bytes = new char[this->element_size];
        memcpy(this->begin->element_bytes, &arg, this->element_size);
        this->begin->next = nullptr;
        this->begin->previous = nullptr;
      }
      else
      {
        linked_entry *current_entry = this->begin;
        while (true)
        {
          if (current_entry->next == nullptr)
            break;
          current_entry = current_entry->next;
        }
        current_entry->next = new aceinetzxx::linked_entry();
        current_entry->next->next = nullptr;
        current_entry->next->element_bytes = new char[this->element_size];
        memcpy(current_entry->next->element_bytes, &arg, this->element_size);
        current_entry->next->previous = current_entry;
      }
    }

    T pop_back()
    {
      linked_entry *current_entry = this->begin;
      while (true)
      {
        if (current_entry->next == nullptr)
        {
          T element = *(int *)current_entry->element_bytes;
          current_entry->previous->next = nullptr;
          delete current_entry->element_bytes;
          delete current_entry;
          return element;
        }
        else
        {
          current_entry = current_entry->next;
        }
      }
    }

    T &back()
    {
      linked_entry *current_entry = this->begin;
      while (true)
      {
        if (current_entry->next == nullptr)
        {
          return *(int *)current_entry->element_bytes;
        }
        else
        {
          current_entry = current_entry->next;
        }
      }
      throw aceinetzxx::LinkedError("back() failed");
    }

    T &at(size_t idx)
    {
      linked_entry *current_entry = this->begin;
      size_t pos = 0;
      while (true)
      {
        if (pos == idx)
        {
          // T element;
          // memcpy(&element, current_entry->element_bytes, this->element_size);
          // return element;
          return *(int *)current_entry->element_bytes;
        }

        if (current_entry->next == nullptr)
        {
          throw aceinetzxx::LinkedError("at() failed");
        }

        current_entry = current_entry->next;
        pos++;
      }
    }

    size_t size()
    {
      size_t result = 0;

      linked_entry *current_entry = this->begin;
      while (true)
      {
        result++;

        if (current_entry->next == nullptr)
          break;

        current_entry = current_entry->next;
      }

      return result;
    }
  };
}

#endif
