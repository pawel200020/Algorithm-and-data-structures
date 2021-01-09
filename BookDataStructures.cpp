#include "BookDataStructures.hpp"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include<cstdio>
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
    int key = DataStructure.linkedList.front();
    return remove(key, DataStructure);
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
    if (DataStructure.hashing.find(key) != DataStructure.hashing.end()) {
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

void DataStructure_1_30::push(int key, DataStructure_1_30 &DataStructure) {
    DataStructure.linkedList.push_front(key);
    if (DataStructure.vectorOfMinValues.empty()) {

        std::vector<int> vector1;
        std::vector<std::list<int>::iterator> vectorIter1;
        vector1.push_back(key);
        vectorIter1.push_back(DataStructure.linkedList.begin());
        DataStructure.vectorOfMinValues.push_back(vector1);
        DataStructure.vectorOfAddresses.push_back(vectorIter1);
    } else {
        int last = DataStructure.vectorOfMinValues.at(DataStructure.vectorCounter).size() - 1;
        if (DataStructure.vectorOfMinValues.at(DataStructure.vectorCounter).at(last) > key) {
            DataStructure.vectorOfMinValues.at(DataStructure.vectorCounter).push_back(key);
            DataStructure.vectorOfAddresses.at(DataStructure.vectorCounter).push_back(DataStructure.linkedList.begin());
        } else {
            DataStructure.vectorCounter++;
            std::vector<int> vector1;
            std::vector<std::list<int>::iterator> vectorIter1;
            vector1.push_back(key);
            vectorIter1.push_back(DataStructure.linkedList.begin());
            DataStructure.vectorOfMinValues.push_back(vector1);
            DataStructure.vectorOfAddresses.push_back(vectorIter1);
        }
    }
}

void DataStructure_1_30::pop(DataStructure_1_30 &DataStructure) {
    int sizeOfLastElem = DataStructure.vectorOfMinValues.at(DataStructure.vectorOfMinValues.size() - 1).size();
    if (sizeOfLastElem > 1) {
        auto iteratorToRm = DataStructure.vectorOfMinValues.at(DataStructure.vectorOfMinValues.size() - 1).end() - 1;
        DataStructure.vectorOfMinValues.at(DataStructure.vectorOfMinValues.size() - 1).erase(iteratorToRm);
        auto iteratorToRm2 = DataStructure.vectorOfAddresses.at(DataStructure.vectorOfAddresses.size() - 1).end() - 1;
        DataStructure.vectorOfAddresses.at(DataStructure.vectorOfAddresses.size() - 1).erase(iteratorToRm2);

        auto listedIterator = *(DataStructure.vectorOfAddresses.at(DataStructure.vectorOfAddresses.size() - 1).end() -
                                1);
        DataStructure.linkedList.erase(DataStructure.linkedList.begin());
    } else {
        auto iteratorToRm = DataStructure.vectorOfMinValues.at(DataStructure.vectorOfMinValues.size() - 1).end() - 1;
        DataStructure.vectorOfMinValues.at(DataStructure.vectorOfMinValues.size() - 1).erase(iteratorToRm);
        auto iteratorToRmVector = DataStructure.vectorOfMinValues.end() - 1;
        DataStructure.vectorOfMinValues.erase(iteratorToRmVector);

        auto iteratorToRm2 = DataStructure.vectorOfAddresses.at(DataStructure.vectorOfAddresses.size() - 1).end() - 1;
        DataStructure.vectorOfAddresses.at(DataStructure.vectorOfAddresses.size() - 1).erase(iteratorToRm2);
        auto iteratorToRmVector2 = DataStructure.vectorOfAddresses.end() - 1;
        DataStructure.vectorOfAddresses.erase(iteratorToRmVector2);


        DataStructure.vectorCounter--;
        DataStructure.linkedList.erase(DataStructure.linkedList.begin());
    }
}

void DataStructure_1_30::uptomin(class DataStructure_1_30 &DataStructure) {
    int minVal = DataStructure.vectorOfMinValues.at(DataStructure.currMin).at(
            DataStructure.vectorOfMinValues.at(DataStructure.currMin).size() - 1);
    auto minIterator = DataStructure.vectorOfAddresses.at(DataStructure.currMin).at(
            DataStructure.vectorOfAddresses.at(DataStructure.currMin).size() - 1);

    int size =  DataStructure.linkedList.size();
    int _size=DataStructure.vectorOfMinValues.at(0).size();
    DataStructure.linkedList.resize(size-_size);
    DataStructure.vectorOfMinValues.erase(DataStructure.vectorOfMinValues.begin());
    DataStructure.vectorOfAddresses.erase(DataStructure.vectorOfAddresses.begin());
}

void DataStructure_1_30::display(class DataStructure_1_30 &DataStructure) {
    printf("---------------linked list-----------------\n");
    for (auto i = DataStructure.linkedList.begin(); i != DataStructure.linkedList.end(); i++) {
        printf("%d ", *i);
    }
    printf("\n------------------------------------------\n");
    printf("\n---------------array of min values---------\n");
    for (int i = DataStructure.currMin; i < DataStructure.vectorOfMinValues.size(); i++) {
        printf("level %d\n", i);
        for (auto j = DataStructure.vectorOfMinValues.at(i).begin();
             j != DataStructure.vectorOfMinValues.at(i).end(); j++) {
            printf("%d ", *j);
        }
        printf("\n");
    }
    printf("\n------------------------------------------\n");
    printf("\n---------------array of addresses---------\n");
    for (int i = DataStructure.currMin; i < DataStructure.vectorOfMinValues.size(); i++) {
        printf("level %d\n", i);
        for (auto j = DataStructure.vectorOfAddresses.at(i).begin();
             j != DataStructure.vectorOfAddresses.at(i).end(); j++) {
            printf("%p ", *j);
        }
        printf("\n");
    }
}
