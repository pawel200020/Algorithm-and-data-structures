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

    ~INSERTION_SORT_CLASS() {
        delete[] array;
        delete[] arrayMOD;
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

    int *ResortArray() {
        return arrayMOD;
    }

    friend TEST_CLASS;
};

class TEST_CLASS {

    int testNumber;
public:
    TEST_CLASS(int testNumber) {

        this->testNumber = testNumber;
        TesterMaster(testNumber);
    }

private:
    void DisplayMessage(char *message) {
        printf("%s\n", message);
    }

    void DisplayArray(int *array, int size) {
        for (int i = 0; i < size; i++) { printf("%d " "", array[i]); }
        printf("\n");
    }

    bool compare(int *array1, int *array2, int size) {
        for (int i = 0; i < size; i++) {
            if (array1[i] != array2[i]) {
                return false;
            }
        }
        return true;
    }

    void extraBubbleSort(int *array, int n) {
        int i, j;
        for (i = 0; i < n - 1; i++)
            for (j = 0; j < n - i - 1; j++)
                if (array[j] > array[j + 1])
                    std::swap(array[j], array[j + 1]);
    }

    void Test() {
        srand(time(NULL));
        int size = rand() % 10 + 200;
        int *array = new int[size];
        int *arrayrecived;
        for (int i = 0; i < size; i++) { array[i] = rand() % 1000; }
        INSERTION_SORT_CLASS *testObj = new INSERTION_SORT_CLASS(array, size);
        testObj->sort();
        arrayrecived = testObj->ResortArray();
        extraBubbleSort(array, size);
        if (compare(arrayrecived, array, size)) {
            printf("%s", "Array derived:\n");
            DisplayArray(arrayrecived, size);
            printf("%s", "Array poprerty sorted:\n");
            DisplayArray(array, size);
            DisplayMessage("PASS");

        } else {
            printf("%s", "Array derived:\n");
            DisplayArray(arrayrecived, size);
            printf("%s", "Array poprerty sorted:\n");
            DisplayArray(array, size);
            DisplayMessage("FAIL");
        }
        delete[] array;
        delete[] arrayrecived;
        delete testObj;

    }

    void TesterMaster(int testNumbers) {
        for (int i = 0; i < testNumbers; i++) {
            printf("\n%s%d%s\n\n", "--------------------------------TEST ID: ", i,"--------------------------------");
            Test();
        }
    }

};

int main() {
    TEST_CLASS s(4);
}
