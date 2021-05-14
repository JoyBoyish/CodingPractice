#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

// n 个整数的无序数组，找到每个元素后面比它大的第一个数，要求时间复杂度为 O(N)
using namespace std;

vector<int> findMax(vector<int>num) {
    if(num.size()==0) {
        return num;
    }
    vector<int>res(num.size());

    int i=0;
    stack<int>s;

    // s stores position which does not find a larger one
    while(i < num.size()) {
        // if s is empty() or still not find a larger one
        if(s.empty()||num[s.top()]>=num[i]) {
            s.push(i++); // push the position to s and increment i
        }
        else {// find a larger one
            // store this value at corresponding position, pop the position out of the stack
            res[s.top()]=num[i];
            s.pop();

            // then continue comparing num[i] with stack top
        }
    }

    // for who don;t have solution
    while(!s.empty()) {
        res[s.top()]=INT_MAX;
        s.pop();
    }

    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<endl;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> res(n, -1);

    int last = 0;
    int i = 1;
    while(last < n && i < n) { // not reach the end
        // how to increment i?
        if (arr[last] < arr[i]) {
            int r = arr[i];
            res[last++] = r;
        }
        else {
            i++;
        }
    }

    return 0;
}
