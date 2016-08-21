// Copyright (c) 2016 Johnson9009. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files(the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and / or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "c/single_list.h"
#include <stdlib.h>
#include <assert.h>

typedef struct SingleListNode {
  void *content;
  struct SingleListNode *next;
}Sl_Node;

typedef enum SingleListStatus {
  Sl_kCreated = 1,
  Sl_kDestroyed
}Sl_Status;

typedef struct SingleList {
  Sl_Node *head;
  Sl_Node *tail;
  int length;
  Sl_Status status;
}Sl_List;

Sl_Result Sl_ListCreate(Sl_ListPtr *list_ptr) {
  assert(list_ptr != NULL);

  Sl_List *new_list = malloc(sizeof(Sl_List));
  if (NULL == new_list) {
    return Sl_kBadAlloc;
  } else {
    Sl_Node * header_node = malloc(sizeof(Sl_Node));
    if (NULL == header_node) {
      free(new_list);
      return Sl_kBadAlloc;
    }

    header_node->content = NULL;
    header_node->next = NULL;
    new_list->head = new_list->tail = header_node;
    new_list->length = 0;
    new_list->status = Sl_kCreated;
    *list_ptr = new_list;
    return Sl_kSuccess;
  }
}

Sl_Result Sl_PushBack(Sl_ListPtr list_ptr, void *content) {
  assert(list_ptr != NULL);
  assert(list_ptr->status == Sl_kCreated);
  assert(list_ptr->length >= 0);
  assert(list_ptr->head != NULL);
  assert(list_ptr->tail != NULL);

  Sl_Node * new_node = malloc(sizeof(Sl_Node));
  if (NULL == new_node) {
    return Sl_kBadAlloc;
  }

  new_node->content = content;
  new_node->next = NULL;
  list_ptr->tail->next = new_node;
  list_ptr->tail = new_node;
  ++(list_ptr->length);
  return Sl_kSuccess;
}

Sl_Iterator Sl_Begin(const Sl_ListPtr list_ptr) {
  assert(list_ptr != NULL);
  assert(list_ptr->status == Sl_kCreated);
  assert(list_ptr->length >= 0);
  assert(list_ptr->head != NULL);
  assert(list_ptr->tail != NULL);

  return list_ptr->head->next;
}

Sl_Iterator Sl_End(const Sl_ListPtr list_ptr) {
  assert(list_ptr != NULL);
  assert(list_ptr->status == Sl_kCreated);
  assert(list_ptr->length >= 0);
  assert(list_ptr->head != NULL);
  assert(list_ptr->tail != NULL);

  return list_ptr->tail->next;
}

void Sl_Forward(Sl_Iterator *iterator) {
  assert(iterator != NULL);
  assert((*iterator) != NULL);

  *iterator = (*iterator)->next;      
  return;
}

void * Sl_GetContent(Sl_Iterator iterator) {
   assert(iterator != NULL);
   return iterator->content;
}

void Sl_ListDestroy(Sl_ListPtr *list_ptr) {
  assert(list_ptr != NULL);
  assert(*list_ptr != NULL);
  assert((*list_ptr)->status == Sl_kCreated);
  assert((*list_ptr)->length >= 0);
  assert((*list_ptr)->head != NULL);
  assert((*list_ptr)->tail != NULL);

  for (Sl_Iterator iterator = Sl_Begin(*list_ptr); iterator != Sl_End(*list_ptr); ) {
    Sl_Iterator release_node = iterator;
    Sl_Forward(&iterator);
    release_node->content = NULL;
    release_node->next = NULL;
    free(release_node);
    release_node = NULL;
  }

  (*list_ptr)->tail = NULL;
  free((*list_ptr)->head);
  (*list_ptr)->head = NULL;
  free(*list_ptr);
  *list_ptr = NULL;
  return;
}
