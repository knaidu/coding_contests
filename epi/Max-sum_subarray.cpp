#include <iostream>
#include <limits>
#include <ctime>
#include <cassert>
#include <vector>
#include <cstdlib>

using namespace std;

// @include
template <typename T>
pair<int, int> find_maximum_subarray(const vector<T> &A) {
  // A[range.first : range.second - 1] will be the maximum subarray
  pair<int, int> range(0, 0);
  int min_idx = -1;
  T min_sum = 0, sum = 0, max_sum = numeric_limits<T>::min();
  for (int i = 0; i < A.size(); ++i) {
    sum += A[i];
    if (sum < min_sum) {
      min_sum = sum, min_idx = i;
    }
    if (sum - min_sum > max_sum) {
      max_sum = sum - min_sum, range = {min_idx + 1, i + 1};
    }
  }
  return range;
}
// @exclude

/*
pair<int, int> find_maximum_subarray(vector<int> &A) {
  int maximum_till = A[0], maximum = A[0];
  pair<int, int> range_max_till(0, 0), range_max(0, 0);
  for (int i = 1; i < A.size(); ++i) {
    if (A[i] > A[i] + maximum_till) {
      maximum_till = A[i], range_max_till = pair<int, int>(i, i);
    } else {
      maximum_till = A[i] + maximum_till, range_max_till.second = i;
    }
    if (maximum_till > maximum) {
      maximum = maximum_till, range_max = range_max_till;
    }
  }
  return range_max;
}
*/

template <typename T>
vector<T> rand_vector(int len) {
  vector<T> ret;
  while (len--) {
    ret.push_back(((rand() & 1) ? -1 : 1) * rand() % 1000);
  }
  return ret;
}

template <typename T>
void check_max_sum(vector<T> &A, pair<int, int> &range) {
  T max_sum = 0;
  for (int i = range.first; i < range.second; ++i) {
    max_sum += A[i];
  }
  for (int i = 0; i < A.size(); ++i) {
    T sum = 0;
    for (int j = i; j < A.size(); ++j) {
      sum += A[j];
      assert(sum <= max_sum);
    }
  }
}

int main(int argc, char *argv[]) {
  srand(time(nullptr));
  for (int times = 0; times < 1000; ++times) {
    vector<int> A;
    if (argc == 1) {
      A = rand_vector<int>(1 + rand() % 10000);
    } else if (argc == 2) {
      int n = atoi(argv[1]);
      A = rand_vector<int>(n);
    } else {
      for (int i = 1; i < argc; ++i) {
        A.push_back(atoi(argv[i]));
      }
    }
    pair<int, int> range = find_maximum_subarray(A);
    cout << range.first << " " << range.second << endl;
    check_max_sum(A, range);
  }
  return 0;
}
