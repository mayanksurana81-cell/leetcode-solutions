/*
Category: Merge Sort, Divide and Conquer, Counting Inversions

Approach:
- Recursively divide the array into two halves using merge sort.
- Count inversions within the left and right halves through recursive calls.
- During merging, when an element from the right half is smaller than the current element in the left half, all remaining elements in the left half form inversions with it.
- Add the left, right, and merge inversion counts and return the total.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/
//Hackerrank - Merge Sort: Counting Inversions
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 long merge(vector<int>& arr, int st, int mid,int en){
    vector<int> temp;
    int i = st, j = mid+1;
    long count = 0;
    while(i <= mid && j <= en){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            count += mid - i + 1;
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
            i++;
    }
    while(j <= en){
        temp.push_back(arr[j]);
            j++;
    }
    for(int idx = 0; idx < temp.size(); idx++){
        arr[st+idx] = temp[idx];
    }
    return count;
 }
long mergesort(vector<int>& arr, int st, int en){
    if(st < en){
        int mid = st + (en - st)/2;
        long left_inversion = mergesort(arr, st, mid);
        long right_inversion = mergesort(arr, mid+1, en);
        long inversion = merge(arr, st, mid, en);
        return left_inversion + right_inversion + inversion;
    }
    return 0;
}
long countInversions(vector<int> arr) {
    long ans = mergesort(arr, 0, arr.size()-1);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
