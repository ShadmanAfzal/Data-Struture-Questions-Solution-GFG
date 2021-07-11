#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

void findMajority(int arr[],int size){
    unordered_map<int,int> cache;

    for(int i=0;i<size;i++){
        cache[arr[i]]++;
    }

    int m = size/2;

    unordered_map<int,int>::iterator it = cache.begin();

    int count = 0;
    for(;it != cache.end(); ++it){
        if((*it).second>m){
            count = 1;
            cout<<(*it).first<<" ";
        }
    }

    if(count==0){
        cout<<"No majority found";
    }


}

int main()
{
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    findMajority(arr,size);

}