#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
class INSERTION_SORT_CLASS;
class TEST_CLASS;

class INSERTION_SORT_CLASS {
    const int *array;
    int elem;
    int *arrayMOD;

    void copyArray() { for (int i = 0; i < elem; i++) { arrayMOD[i] = array[i]; }}
public:
    INSERTION_SORT_CLASS(int *array, int elem) {
        this->array = array;
        this->elem = elem;
        this->arrayMOD = new int[elem];
        copyArray();
    }


    void displayArray() {
        for (int i = 0; i < elem; i++) {
            printf("%d"" ", arrayMOD[i]);
        }
        printf("\n");
    }

    void sort() {
        for (int j = 1; j < elem; j++) {
            int i = j - 1;
            int elem = arrayMOD[j];
            while (i >= 0 && arrayMOD[i] > elem) {
                arrayMOD[i + 1] = arrayMOD[i];
                i--;
            }
            arrayMOD[i + 1] = elem;
        }
    }
    friend TEST_CLASS;
};
class TEST_CLASS{
    INSERTION_SORT_CLASS* testObj;
    TEST_CLASS(INSERTION_SORT_CLASS* testObj){
        this->testObj=testObj;
    }
    ~TEST_CLASS(){
        delete testObj;
        delete [] array;
    }
    int *array=new int [testObj->elem];
    void copy(){
        for(int i = 0; i < testObj->elem; i++){
            array[i]=testObj->array[i];
        }
    }
    void extraBubbleSort(){
        int i, j;
        int n = testObj->elem;
        for (i = 0; i < n-1; i++)
            for (j = 0; j < n-i-1; j++)
                if (array[j] > array[j+1])
                    std::swap(array[j], array[j+1]);
    }





};
int main() {
    int array[50];
    for(int i = 0; i<50; i++){ array[i]=rand() %1000;}
  INSERTION_SORT_CLASS* obj1 = new INSERTION_SORT_CLASS (array,50);
    obj1->displayArray();
    delete obj1;
}
