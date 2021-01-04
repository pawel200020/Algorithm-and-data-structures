#include "Classes.h"
#include "Trees.hpp"
/*
 h - testowanie algorytmu HeapSort
 i - testowanie algorytmu InsertionSort
 m - testowanie algorytmu MergeSort
 w parametrach konstruktora klasy TEST_CLASS klasy t1 jako pierwszy argument nalezy podac ilosc testow a w drugim rozmiar tablicy do testowania
 */
/*int main() {
    TEST_CLASS t1(5, 50);
    t1.test('h');
}*/

/*
 main do testowania drzew BST.
 Dozwolone operacje:
 1. display(char) za paramter przyjmuje litere i <- porzadek inorder, o <-porzatek postorder, r <-porzadek preorder
 2. insert(int) liczba do wstawienia
 3. search(int) zwraca adres szukanego elementu o zawartosci pola data rownemu podanemu w argumencie
 4. remove(int) usuwa wezel o zadanej argumentem wartosci pola data
 */

/*int main() {
    BST_TREE_CLASS t;
    char orderWrite = 'r';
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display(orderWrite);
    t.remove(20);
    t.display(orderWrite);
    t.remove(25);
    t.display(orderWrite);
    t.remove(30);
    t.display(orderWrite);
}*/
/*
int main(){
    RED_BLACK_TREE_CLASS2 tree;
    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    tree.insert(2);
    tree.insert(6);
    tree.insert(13);
    tree.display('i');
    tree.deleteByVal(18);
    tree.deleteByVal(11);
    tree.deleteByVal(3);
    tree.deleteByVal(10);
    tree.deleteByVal(22);
    tree.display('i');

}
*/
int main(){
    AVL_TREE_CLASS tree;
    tree.insert(9);
    tree.insert(5);
    tree.insert(10);
    tree.insert(0);
    tree.insert(6);
    tree.insert(11);
    tree.insert(-1);
    tree.insert(1);
    tree.insert(2);
    tree.display('r');
    tree.remove(10);
    tree.display('r');

}

