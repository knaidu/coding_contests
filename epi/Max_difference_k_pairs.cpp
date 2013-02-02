#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cassert>

using namespace std;

// @include
template <typename T>
T max_k_pairs_profits(const vector<T>& A, const int &k) {
  // @exclude
  /*
  copy(A.begin(), A.end(), ostream_iterator<T>(cout, " "));
  cout << endl;
  //*/
  // @include
  vector<T> k_sum(k << 1, numeric_limits<T>::min());
  for (int i = 0; i < A.size(); ++i) {
    vector<T> pre_k_sum(k_sum);
    for (int j = 0, sign = -1; j < k_sum.size() && j <= i; ++j, sign *= -1) {
      T diff = sign * A[i] + (j == 0 ? 0 : pre_k_sum[j - 1]);
      k_sum[j] = max(diff, pre_k_sum[j]);
    }
    // @exclude
    /*
    cout << "i = " << i << endl;
    copy(k_sum.begin(), k_sum.end(), ostream_iterator<T>(cout, " "));
    cout << endl;
    //*/
    // @include
  }
  return k_sum.back();  // return the last selling profits as the answer
}
// @exclude

// O(n^k) checking answer
template <typename T>
void check_ans_helper(const vector<T> &A, int l, int k, int pre, T ans, T &max_ans) {
  if (l == k) {
    max_ans = max(max_ans, ans);
  } else {
    for (int i = pre; i < A.size(); ++i) {
      check_ans_helper(A, l + 1, k, i + 1, ans + ((l & 1) ? A[i] : -A[i]), max_ans);
    }
  }
}

template <typename T>
T check_ans(const vector<T> &A, const int &k) {
  T ans = 0, max_ans = numeric_limits<T>::min();

  check_ans_helper(A, 0, k << 1, 0, ans, max_ans);
  cout << "max_ans = " << max_ans << endl;
  return max_ans;
}

int main(int argc, char *argv[]) {
  srand(time(nullptr));
  int n = 40, k = 4;
  //*
  // random tests for n = 40, k = 4 for 100 times
  for (int times = 0; times < 100; ++times) {
    vector<int> A;
    for (int i = 0; i < n; ++i) {
      A.emplace_back(rand() % 100);
    }
    cout << "n = " << n << ", k = " << k << endl;
    cout << max_k_pairs_profits(A, k) << endl;
    assert(check_ans(A, k) == max_k_pairs_profits(A, k));
  }
  //*/
  
  // For input
  //*/
  if (argc == 2) {
    n = atoi(argv[1]);
    k = (1 + rand() % (n >> 1));
  } else if (argc == 3) {
    n = atoi(argv[1]);
    k = atoi(argv[2]);
  } else {
    n = 1 + rand() % 10000;
    k = (1 + rand() % (n >> 1));
  }
  vector<int> A;
  for (int i = 0; i < n; ++i) {
    A.emplace_back(rand() % 100);
  }
  cout << "n = " << n << ", k = " << k << endl;
  cout << max_k_pairs_profits(A, k) << endl;
  //*/
  return 0;
}
