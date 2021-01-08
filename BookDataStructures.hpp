#ifndef INC_2020_10_13_HOMEWORK_BOOKDATASTRUCTURES_HPP
#define INC_2020_10_13_HOMEWORK_BOOKDATASTRUCTURES_HPP

#include <vector>
#include <map>
#include <list>
#include <stack>

class DataStructure_1_28 {
    std::vector<int> array;
    std::map<int, int> hashing;
public:
    static int Select(DataStructure_1_28 &);

    static int Search(int, DataStructure_1_28 &);

    static void Insert(int, DataStructure_1_28 &);


};

class DataStructure_1_29 {
    std::list<int> linkedList;
    std::vector<int> array;
    std::vector<std::list<std::list<int>::iterator> > listedArray;
    std::map<int, int> hashing;
public:
    static void push(int, DataStructure_1_29 &);

    static int pop(DataStructure_1_29 &);

    static void display(DataStructure_1_29 &DataStructure);

    static int search(int, DataStructure_1_29 &);

    static int remove(int, DataStructure_1_29 &);
};

#endif //INC_2020_10_13_HOMEWORK_BOOKDATASTRUCTURES_HPP
