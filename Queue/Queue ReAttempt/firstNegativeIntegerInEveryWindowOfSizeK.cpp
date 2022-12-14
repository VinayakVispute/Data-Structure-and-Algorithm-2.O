#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N,
                                            long long int K) {

  deque<long long int> dq;
  vector<long long> ans;

  // Process First Windows of K Size
  for (int i = 0; i < K; i++) {
    if (A[i] < 0) {
      dq.push_back(i);
    }
  }

  // Store Answers for First Window Of  K Size
  if (dq.size() > 0) {
    ans.push_back(A[dq.front()]);
  } else {
    ans.push_back(0);
  }
 
  // Process for Remaining Windows
  for (int i = K; i < N; i++) {
    // removal
    if (!dq.empty() && i - dq.front() >= K) {
      dq.pop_front();
    }

    if (A[i] < 0) {
      dq.push_back(i);
    }
    // Store Answers
    if (dq.size() > 0) {
      ans.push_back(A[dq.front()]);
    } else {
      ans.push_back(0);
    }
  }
  return ans;
}

int main() {
  long long int N;
  cout << endl << "Enter the Size  : ";
  cin >> N;
  long long int K;
  cout << endl << "Enter the Size of Window : ";
  cin >> K;
  long long int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<long long> ans = printFirstNegativeInteger(A,N,K);

  for(int i = 0; i < ans.size() ; i++){
    cout<<ans[i]<<" ";
  }
}