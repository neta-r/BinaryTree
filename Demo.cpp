/**
 * Demo file for the exercise on binary tree
 *
 * @author Erel Segal-Halevi
 * @since 2021-04
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/BinaryTree.hpp"
using namespace ariel;

int main() {
//  BinaryTree<int> tree_of_ints;
//  tree_of_ints.add_root(1)
//  .add_left(1, 9)      // Now 9 is the left child of 1
//  .add_left(9, 4)      // Now 4 is the left child of 9
//  .add_right(9, 5)     // Now 5 is the right child of 9
//  .add_right(1, 3)     // Now 3 is the right child of 1
//  .add_left(1, 2);     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
//
//  //cout << tree_of_ints << endl;  /* Prints the tree in a reasonable format. For example:
////        1
////        |--------|
////        2        3
////        |---|
////        4   5
////  */
////
//  for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
//    cout << (*it) << " " ;
//  }  // prints: 1 2 4 5 3
//    cout << endl;
//    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
//    cout << (*it) << " " ;
//  }  // prints: 4 2 5 1 3
//  cout << endl;
//  for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
//    cout << (*it) << " " ;
//  }  // prints: 4 5 2 3 1
//    cout << endl;
//  for (int element: tree_of_ints) {  // this should work like inorder
//    cout << element << " " ;
//  }  // prints: 4 2 5 1 3
//    cout << endl;
//
//
//  // The same should work with other types, e.g. with strings:
//
//  BinaryTree<string> tree_of_strings;
//  tree_of_strings.add_root("1")
//  .add_left("1", "9")      // Now 9 is the left child of 1
//  .add_left("9", "4")      // Now 4 is the left child of 9
//  .add_right("9", "5")     // Now 5 is the right child of 9
//  .add_right("1", "3")     // Now 3 is the right child of 1
//  .add_left("1", "2");     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
////  cout << tree_of_strings << endl;
//
//  for (auto it=tree_of_strings.begin_preorder(); it!=tree_of_strings.end_preorder(); ++it) {
//    cout << (*it) << " " ;
//  }  // prints: 1 2 4 5 3
//    cout << endl;
//    for (auto it=tree_of_strings.begin_inorder(); it!=tree_of_strings.end_inorder(); ++it) {
//    cout << (*it) << " " ;
//  }  // prints: 4 2 5 1 3
//  cout << endl;
//  for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
//    cout << (*it) << " " ;
//  }  // prints: 4 5 2 3 1
//    cout << endl;
//
//  // demonstrate the arrow operator:
//  for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
//    cout << it->size() << " " ;
//  }  // prints: 1 1 1 1 1
//    cout << endl;
//
//
//  for (const string& element: tree_of_strings) {  // this should work like inorder
//    cout << element << " " ;
//  }   // prints: 4 2 5 1 3
//    cout << endl;
    BinaryTree<double> t3;
            t3.add_root(5.6)
                    .add_left(5.6, 8.9)
                    .add_right(5.6, 10.2)
                    .add_left(8.9, -96.3)
                    .add_right(8.9, 4)
                    .add_left(10.2, 71.0)
                    .add_right(10.2, 55.3)
                    .add_left(4, 0)
                    .add_right(4, 19.7)
                    .add_right(55.3, -8.5);
    t3.add_root(7.4);
    stringstream in;
    stringstream pre;
    for (auto it = t3.begin_preorder(); it != t3.end_preorder(); ++it) {
        pre << (*it) << " ";
    }
    cout << pre.str();
}
