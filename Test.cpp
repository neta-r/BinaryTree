#include "doctest.h"
#include "BinaryTree.hpp"
#include <string>

using namespace std;
using namespace ariel;

template<typename T>
void check_pre(BinaryTree<T> t, string outcome){
    string pre;
    for (auto it = t.begin_preorder(); it != t.end_preorder(); ++it) {
        pre = pre+to_string(*it)+" ";
    }
            CHECK(pre == outcome);
}

template<typename T>
void check_post(BinaryTree<T> t,string outcome){
    string post;
    for (auto it = t.begin_postorder(); it != t.end_postorder(); ++it) {
        post = post+to_string(*it)+" ";
    }
            CHECK(post == outcome);
}

template<typename T>
void check_in(BinaryTree<T> t,string outcome){
    string in;
    for (auto it = t.begin_inorder(); it != t.end_inorder(); ++it) {
        in = in+to_string(*it)+" ";
    }
            CHECK(in == outcome);
}

TEST_CASE ("char tree") {
    BinaryTree<char> t;
    CHECK_NOTHROW(
            t.add_root('A')
                    .add_left('A', 'B')
                    .add_left('B', 'D')
                    .add_right('B', 'E')
                    .add_right('A', 'C')
                    .add_left('C', 'F')
                    .add_left('C', 'G'));
  //  CHECK_THROWS(t.add_left('Z','G'));
   // CHECK_THROWS(t.add_root(5));
//    check_pre(t, "A B D E E C F G ");
//    check_post(t, "D E B F G C A ");
//    check_in(t,  "D B E A F C G ");
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('b'));
    CHECK_NOTHROW(t.add_root('c'));
    CHECK_NOTHROW(t.add_root('e'));
    CHECK_NOTHROW(t.add_root('f'));
    CHECK_NOTHROW(t.add_root('g'));
    CHECK_NOTHROW(t.add_root('h'));
    CHECK_NOTHROW(t.add_root('i'));
    CHECK_NOTHROW(t.add_root('j'));
    CHECK_NOTHROW(t.add_root('k'));
    CHECK_NOTHROW(t.add_root('l'));
    CHECK_NOTHROW(t.add_root('m'));
    CHECK_NOTHROW(t.add_root('n'));
    CHECK_NOTHROW(t.add_root('o'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_NOTHROW(t.add_root('a'));

    //   CHECK_THROWS(t.add_left('A','b'));
    CHECK_NOTHROW(t.add_left('B','d'));
//    check_pre(t, "a B d E E C F G ");
//    check_post(t, "d E B F G C a ");
//    check_in(t,  "d B E a F C G ");
}

TEST_CASE ("int tree") {
    BinaryTree<int> t2;
    CHECK_NOTHROW(
            t2.add_root(25)
                    .add_left(25, 15)
                    .add_right(25,50)
                    .add_left(15,10)
                    .add_right(15,22)
                    .add_left(50,35)
                    .add_right(50,70)
                    .add_left(10,4)
                    .add_right(10,12)
                    .add_left(22,18)
                    .add_right(22,24)
                    .add_left(35,31)
                    .add_right(35,44)
                    .add_left(70,66)
                    .add_right(70,90));
//    CHECK_THROWS(t2.add_left(36,2));
//    CHECK_THROWS(t2.add_root('g'));
//    check_pre(t2, "25 15 10 4 12 22 18 24 50 35 31 44 70 66 90 ");
//    check_post(t2, "4 12 10 18 24 22 15 31 44 35 66 90 70 50 25 ");
//    check_in(t2,  "4 10 12 15 18 22 24 25 31 35 44 50 66 70 99 ");
    CHECK_NOTHROW(t2.add_root(100));
//  CHECK_THROWS(t2.add_left(10,87));
    CHECK_NOTHROW(t2.add_left(35,9));
//    check_pre(t2, "100 15 10 87 12 22 18 24 50 35 31 9 70 66 90 ");
//    check_post(t2, "87 12 10 18 24 22 15 31 9 35 66 90 70 50 100 ");
//    check_in(t2,  "87 10 12 15 18 22 24 100 31 35 9 50 66 70 99 ");
}