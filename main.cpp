#include "Classes.h"
#include "Trees.hpp"
#include "BookDataStructures.hpp"
/*
 i - testowanie algorytmu InsertionSort //zadanie 1
 m - testowanie algorytmu MergeSort  //zadanie 2
 h - testowanie algorytmu HeapSort //zadanie 3
 w parametrach konstruktora klasy TEST_CLASS klasy t1 jako pierwszy argument nalezy podac ilosc testow a w drugim rozmiar tablicy do testowania
 */
/*int main() {
    TEST_CLASS t1(5, 50);
    t1.test('h');
}*/
/*
 //////////////////////zadanie 4///////////////////////////
 main do testowania drzew BST.
 Dozwolone operacje:
 1. display(char) za paramter przyjmuje litere i <- porzadek inorder, o <-porzatek postorder, r <-porzadek preorder
 2. insert(int) liczba do wstawienia
 3. search(int) zwraca adres szukanego elementu o zawartosci pola data rownemu podanemu w argumencie
 4. remove(int) usuwa wezel o zadanej argumentem wartosci pola data
 */
/*
 Do nadklasy dałem 2 kluczowe funkcje które w każdym przypadku wyglądają tak samo tzn display() oraz search().
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
/*main do testowania drzew RBT.
 Dozwolone operacje:
 1. display(char) za paramter przyjmuje litere i <- porzadek inorder, o <-porzatek postorder, r <-porzadek preorder
 2. insert(int) liczba do wstawienia
 3. search(int) zwraca adres szukanego elementu o zawartosci pola data rownemu podanemu w argumencie
 4. remove(int) usuwa wezel o zadanej argumentem wartosci pola data
 */

/*int main(){
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
    tree.remove(18);
    tree.search(22);
    tree.remove(11);
    tree.remove(3);
    tree.remove(10);
    tree.remove(22);
    tree.display('i');

}*/
/*main do testowania drzew AVL.
 Dozwolone operacje:
 1. display(char) za paramter przyjmuje litere i <- porzadek inorder, o <-porzatek postorder, r <-porzadek preorder
 2. insert(int) liczba do wstawienia
 3. search(int) zwraca adres szukanego elementu o zawartosci pola data rownemu podanemu w argumencie
 4. remove(int) usuwa wezel o zadanej argumentem wartosci pola data
 */
/*int main(){
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

}*/
/* ////////////////////Zadanie 5//////////////////////////
 /////////////////////////////////////1.28//////////////////////////////////////////
/// w zadaniu korzystam z tablicy haszującej i vektora, dzięki tablicy haszującej mam O(1) dostęp do każdego elementu ze zbioru dzięki czemu
/// zachowuję dodawanie i usuwanie w O(1)
 using S= DataStructure_1_28;
int main(){
 DataStructure_1_28 structure;
    S::Insert(5,structure);
    S::Insert(6,structure);
    S::Insert(7,structure);
    S::Insert(66,structure);
    S::Insert(48,structure);
    S::Insert(21,structure);
    printf("find not exist in set (22): %d\n",S::Search(22,structure));
    printf("find exist in set (66), returns index in array: %d\n",S::Search(66,structure));
    printf("Select returns what was removed : %d\n",S::Select(structure));
    printf("Insert is a void type function, it returns nothing\n ");
    S::Insert(99,structure);
    S::Insert(99,structure);
    S::Insert(59,structure);
    S::Select(structure);
    S::Select(structure);
    S::Select(structure);
    S::Select(structure);
    S::Select(structure);
}*/
/*///////////////////////////1.29//////////////////////////////////////////////
#include <iostream>
///1.29 w tym zadaniu korzystam z tablicy haszującej, listy oraz dwóch vektorów,
///w tablicy haszującej trzymam indeksy z wektora i odpowiadające wartości , do listy zgodnie z treścią zadania dodaję elementy na początek
///w 1 wektorze przechowuję unikalne wartości a w drugim listy ze wskaźnikiami do miejsca gdzie występują w liście te elementy aby
///mieć w O(1) dostęp do tych elementów.
int main() {
    DataStructure_1_29 struc;
    DataStructure_1_29::push(23, struc);
    DataStructure_1_29::push(23, struc);
    DataStructure_1_29::push(23, struc);
    DataStructure_1_29::push(23, struc);
    DataStructure_1_29::push(22, struc);
    DataStructure_1_29::push(22, struc);
    DataStructure_1_29::push(27, struc);
    DataStructure_1_29::push(22, struc);
    DataStructure_1_29::push(23, struc);
    printf("%d\n", DataStructure_1_29::search(99, struc));
    printf("%d\n", DataStructure_1_29::search(22, struc));
    DataStructure_1_29::remove(99, struc);
    DataStructure_1_29::pop(struc);
    DataStructure_1_29::pop(struc);
}*/
/*////////////////////////////////1.29/////////////////////////////
///w zadaniu wykorzystuję listę, i dwa vektory. lista, przechowuje elementy dodawane a jeden z vektorów, vektory najmniejszych wartości,
///do kolejnego vektora w vektorze przechodzimy gdy liczba wpisania w niego ostatnio jest mniejsza od tej którą teraz badamy,
///ponadto w tabeli adresy przechowuję adresy najmniejszych pól aby uzyskać do nich szybki dostęp w O(1). W językach programowania wykorzystujących garbage colletor,
///wystaczy tylko odciąć elementy od rodzica najmniejeszego elementu, w c++ należałoby również posprzątać pamięć, ja w zadaniu skorzystałem z wbudowanej struktury ale
/// można łatwo przerobić tak aby na własnej liście operować.
/// O(1) zapewniane oczywiście dzięki pamiętaniu adresów, mamy szybki dostęp do danego miejsca w pamięci i szybko tylko odcinamy zbędny koniec, następnie usuwamy poziom
/// w wektorze który skasowaliśmy. te vektory są w zasadzie takimi przedziałami dla kolejnych warości min. choć pamięciochłonny działa w O(1)
/// metoda display także nieco tłumaczy zamysł i zarys struktury.
int main(){
    DataStructure_1_30 struc;
    DataStructure_1_30::push(7,struc);
    DataStructure_1_30::push(6,struc);
    DataStructure_1_30::push(3,struc);
    DataStructure_1_30::push(9,struc);
    DataStructure_1_30::push(4,struc);
    DataStructure_1_30::push(11,struc);
    DataStructure_1_30::push(19,struc);
    DataStructure_1_30::push(82,struc);
    DataStructure_1_30::push(22,struc);
    DataStructure_1_30::display(struc);
    DataStructure_1_30::pop(struc);
    DataStructure_1_30::display(struc);
    DataStructure_1_30::pop(struc);
    DataStructure_1_30::display(struc);
    DataStructure_1_30::uptomin(struc);
    DataStructure_1_30::display(struc);
    DataStructure_1_30::uptomin(struc);
    DataStructure_1_30::display(struc);
}*/
