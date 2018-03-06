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

#ifndef C_SINGLE_LIST_H_
#define C_SINGLE_LIST_H_

typedef struct SingleListNode * Sl_Iterator;
typedef struct SingleList * Sl_ListPtr;

typedef enum SingleListResult {
  Sl_kSuccess,
  Sl_kBadAlloc
}Sl_Result;

Sl_Result Sl_ListCreate(Sl_ListPtr *list_ptr);
Sl_Result Sl_PushBack(Sl_ListPtr list_ptr, void *content);
Sl_Iterator Sl_Begin(const Sl_ListPtr list_ptr);
Sl_Iterator Sl_End(const Sl_ListPtr list_ptr);
void Sl_Forward(Sl_Iterator *iterator);
void * Sl_GetContent(Sl_Iterator iterator);
void Sl_ListDestroy(Sl_ListPtr *list_ptr);

#endif  // C_SINGLE_LIST_H_
