#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

vector<int> insertSort(const vector<int>& array){
    vector<int> res(array);
    for(int i=0;i<(int)res.size()-1;i++){
        for(int j=i+1;j>0;j--){
            if(res[j]>res[j-1]){
                break;
            }else{
                std::swap(res[j],res[j-1]);
            }
        }
    }
    return res;
}

vector<int> quickSort(const vector<int>& array){
    vector<int> res(array);

    return res;
}

vector<int> bubbleSort(const vector<int>& array){
    vector<int> res(array);
    for(int i=res.size()-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(res[j]>res[j+1]){
                std::swap(res[j],res[j+1]);
            }
        }
    }
    return res;
}

vector<int> mergeSort(const vector<int>& array){
    vector<int> res(array);

    return res;
}

vector<int> countingSort(const vector<int>& array){    
    // get max and min value, to determine the size of the result array and counter array
    int min=array[0], max=array[0];
    std::for_each(array.begin(), array.end(), [&min,&max](int a){
        min=std::min(min,a);
        max=std::max(max,a);
    });
    // create 2 arrays: res and counter
    vector<int> res, counter;
    counter.resize(max-min+1); // [0,0,...,0]
    // count the occurrences of each element
    for(int i=0;i<(int)array.size();i++){
        int key=array[i];
        counter[key-min]++;
    }
    // write each element according to its occurrences
    for(int i=0;i<(int)counter.size();i++){
        for(int j=0;j<counter[i];j++){
            res.push_back(i+min);
        }
    }
    return res;
}

vector<int> heapSort(const vector<int>& array){
    vector<int> res(array);

    return res;
}

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    if (v.size()) {
        out << '[';
        std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

int main()
{
    vector<int> array={5,4,3,1,2,9,8,7,6};

    cout<<"insert sort:"<<endl<<insertSort(array)<<endl<<endl;

    cout<<"quick sort:"<<endl<<quickSort(array)<<endl<<endl;

    cout<<"bubble sort:"<<endl<<bubbleSort(array)<<endl<<endl;

    cout<<"merge sort:"<<endl<<mergeSort(array)<<endl<<endl;

    cout<<"counting sort:"<<endl<<countingSort(array)<<endl<<endl;

    cout<<"heap sort:"<<endl<<heapSort(array)<<endl<<endl;

    return 0;
}

