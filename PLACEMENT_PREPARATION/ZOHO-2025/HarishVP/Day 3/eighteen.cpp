#include <iostream>
#include <map>
using namespace std;

int totalElements(int N, vector<int>& arr)
{
    map<int, int> map;
    int i = 0, j = 0, n = arr.size();
    int size = 0;

    while (j < n) {
        map[arr[j]]++;
        while (map.size() > 2) {
            map[arr[i]]--;
            if (map[arr[i]] == 0) {
                map.erase(arr[i]);
            }
            i++;
        }
        size = max(size, j - i + 1);
        j++;
    }

    return size;
}


int main()
{
    int N = 6;
    vector<int> arr = { 0, 1, 2, 2, 2, 2 };
    int ans = totalElements(N, arr);
    cout << ans;
    return 0;
}
