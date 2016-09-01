#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void SortUsingIndex(vector<string>& objs, vector<size_t>& indexes)
{
    if (objs.size() != indexes.size())
        throw out_of_range("index size does not match object's size");

    for (size_t i = 0; i < indexes.size(); ++i)
    {
        int idx = i;
        while (indexes[idx] != idx)
        {
            swap(objs[idx], objs[indexes[idx]]);
            swap(indexes[idx], indexes[indexes[idx]]);
        }
    }
}

int main()
{
    vector<string> objs = {"K", "L", "P", "A", "C", "E", "W", "T"};
    vector<size_t> indexes = { 5, 3, 1, 0, 6, 7, 4, 2};

    assert(objs.size() == indexes.size());

    SortUsingIndex(objs, indexes);

    copy(indexes.begin(), indexes.end(), ostream_iterator<size_t>(cout, " "));
    cout << endl;

    copy(objs.begin(), objs.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}
