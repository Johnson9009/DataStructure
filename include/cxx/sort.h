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

#ifndef CXX_SORT_H_
#define CXX_SORT_H_

#include <cstdint>
#include <utility>
#include "cxx/sort-inl.h"

template <typename RandomAccessIterator>
void quick_sort(RandomAccessIterator first, std::uint64_t count) {
  if (count <= 1) return;

  std::uint64_t pivot = count / 2;
  std::swap(first[pivot], first[count - 1]);

  pivot = partition(first, count);

  quick_sort(first, pivot);
  quick_sort(first + pivot + 1, count - pivot - 1);
}

#endif  // CXX_SORT_H_
