#include "BookDataStructures.hpp"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include<cstdio>

///////////////////1.28///////////////////////
///Pomysł jest taki aby użyć 2 pomocniczych struktur danych, vector jednowymiarowy do przechowywania
/// wartości oraz mapy do haszowania
///O(1) zapewniam stosując haszowanie i dostęp do danego elementu  mam w czasie O(1)
void DataStructure_1_28::Insert(int key, DataStructure_1_28 &DataStructure) {
    if (DataStructure.hashing.find(key) != DataStructure.hashing.end()) { return; }
    else {
        int temp = DataStructure.array.size();
        DataStructure.array.push_back(key);
        DataStructure.hashing.insert(std::pair<int, int>(key, temp));
    }
}

int DataStructure_1_28::Select(DataStructure_1_28 &DataStructure) {
    srand(time(nullptr));

    int size = DataStructure.array.size();
    int index = rand() % size;
    int key = DataStructure.array[index];
    int end = DataStructure.array.size() - 1;
    int finish = DataStructure.array.at(end);

    DataStructure.hashing.erase(key);
    auto it = DataStructure.hashing.find(finish);
    it->second = index;

    std::swap(DataStructure.array[end], DataStructure.array[index]);
    DataStructure.array.pop_back();
    return key;
}

int DataStructure_1_28::Search(int key, DataStructure_1_28 &DataStructure) {
    if (DataStructure.hashing.find(key) == DataStructure.hashing.end()) return -1;
    else return DataStructure.hashing.at(key);
}

void DataStructure_1_29::push(int key, DataStructure_1_29 &DataStructure) {
    DataStructure.linkedList.push_front(key);
    if (DataStructure.hashing.find(key) != DataStructure.hashing.end()) {
        int index = DataStructure.hashing.find(key)->second;
        DataStructure.listedArray[index].push_front(DataStructure.linkedList.begin());

    } else {
        int temp = DataStructure.array.size();
        DataStructure.array.push_back(key);
        DataStructure.hashing.insert(std::pair<int, int>(key, temp));
        std::list<std::list<int>::iterator> a;
        a.push_back(DataStructure.linkedList.begin());
        DataStructure.listedArray.push_back(a);
    }
}

int DataStructure_1_29::pop(DataStructure_1_29 &DataStructure) {
    int key=DataStructure.linkedList.front();
    return remove(key,DataStructure);
}

int DataStructure_1_29::search(int key, class DataStructure_1_29 &DataStructure) {
    auto iterator = DataStructure.hashing.find(key);
    if (iterator != DataStructure.hashing.end()) {
        return iterator->first;
    } else {
        return -1;
    }
}

int DataStructure_1_29::remove(int key, DataStructure_1_29 &DataStructure) {
    if(DataStructure.hashing.find(key)!=DataStructure.hashing.end()){
        int removal = key;
        int index = DataStructure.hashing.find(removal)->second;
        int end = DataStructure.array.size() - 1;
        int finish = DataStructure.array.at(end);

        for (auto i = DataStructure.listedArray[index].begin(); i != DataStructure.listedArray[index].end(); ++i) {
            DataStructure.linkedList.erase(*i);
        }

        DataStructure.hashing.erase(removal);
        auto it = DataStructure.hashing.find(finish);
        it->second = index;

        std::swap(DataStructure.listedArray[end], DataStructure.listedArray[index]);
        DataStructure.listedArray.pop_back();

        std::swap(DataStructure.array[end], DataStructure.array[index]);
        DataStructure.array.pop_back();

        return removal;
    } else {
        return -1;
    }

}

void DataStructure_1_29::display(DataStructure_1_29 &DataStructure) {
    for (auto i = DataStructure.linkedList.begin(); i != DataStructure.linkedList.end(); i++) {
        printf("%d ", *i);
    }
    printf("\n");
}

