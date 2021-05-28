#include "doctest.h"
#include "sources/BinaryTree.hpp"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
using namespace ariel;

TEST_CASE ("char tree") {
    BinaryTree<char> t;
    // root doesn't exists - throw exception
            CHECK_THROWS(t.add_left('Z', 'G'));
    // add root + add left + add right + concatenation tests (existing vertices)
            CHECK_NOTHROW(
            t.add_root('a')
                    .add_left('a', 'B')
                    .add_left('B', 'D')
                    .add_right('B', 'E')
                    .add_right('a', 'C')
                    .add_left('C', 'F')
                    .add_right('C', 'G'));
    // add left + add right tests (non existing vertices)
            CHECK_THROWS(t.add_left('Z', 'G'));
            CHECK_THROWS(t.add_right('Z', 'G'));
    // able to change the root
            CHECK_NOTHROW(t.add_root('A'));
    /* this is the tree:
     *      A
     *     / \
     *    B   C
     *   / \ / \
     *  D  E F  G
     */
    stringstream pre;
    for (auto it = t.begin_preorder(); it != t.end_preorder(); ++it) {
        pre << (*it) << " ";
    }
            CHECK(pre.str() == "A B D E C F G ");
    stringstream post;
    for (auto it = t.begin_postorder(); it != t.end_postorder(); ++it) {
        post << (*it) << " ";
    }
            CHECK(post.str() == "D E B F G C A ");
    stringstream in;
    for (auto it = t.begin_inorder(); it != t.end_inorder(); ++it) {
        in << (*it) << " ";
    }
            CHECK(in.str() == "D B E A F C G ");
    // let's change some vertices and see the iterators changes - it should change
            CHECK_NOTHROW(t.add_root('a'));
            CHECK_NOTHROW(t.add_right('a', 'c'));
            CHECK_NOTHROW(t.add_left('B', 'd'));
    /* this is the tree:
    *      a
    *     / \
    *    B   c
    *   / \ / \
    *  d  E F  G
    */
    stringstream pre2;
    for (auto it = t.begin_preorder(); it != t.end_preorder(); ++it) {
        pre2 << (*it) << " ";
    }
            CHECK(pre2.str() == "a B d E c F G ");
    stringstream post2;
    for (auto it = t.begin_postorder(); it != t.end_postorder(); ++it) {
        post2 << (*it) << " ";
    }
            CHECK(post2.str() == "d E B F G c a ");
    stringstream in2;
    for (auto it = t.begin_inorder(); it != t.end_inorder(); ++it) {
        in2 << (*it) << " ";
    }
            CHECK(in2.str() == "d B E a F c G ");
}

TEST_CASE ("int tree") {
    BinaryTree<int> t2;
    // root doesn't exists - throw exception
            CHECK_THROWS(t2.add_left(5, 700));
    // add root + add left + add right + concatenation tests (existing vertices)
            CHECK_NOTHROW(
            t2.add_root(26)
                    .add_left(26, 15)
                    .add_right(26, 50)
                    .add_left(15, 10)
                    .add_right(15, 22)
                    .add_left(50, 35)
                    .add_right(50, 70)
                    .add_left(10, 4)
                    .add_right(10, 12)
                    .add_left(22, 18)
                    .add_right(22, 24)
                    .add_left(35, 31)
                    .add_right(35, 44)
                    .add_left(70, 66)
                    .add_right(70, 90));
    // add left + add right tests (non existing vertices)
            CHECK_THROWS(t2.add_left(36, 2));
            CHECK_THROWS(t2.add_right(36, 2));
    // able to change the root
            CHECK_NOTHROW(t2.add_root(25));
    /* this is the tree:
     *               25
     *          /          \
     *        15           50
     *     /     \       /     \
     *    10     22     35     70
     *   /  \   /  \   /  \   /  \
     *  4   12 18  24 31  44 66  90
     */
    stringstream pre;
    for (auto it = t2.begin_preorder(); it != t2.end_preorder(); ++it) {
        pre << (*it) << " ";
    }
            CHECK(pre.str() == "25 15 10 4 12 22 18 24 50 35 31 44 70 66 90 ");
    stringstream post;
    for (auto it = t2.begin_postorder(); it != t2.end_postorder(); ++it) {
        post << (*it) << " ";
    }
            CHECK(post.str() == "4 12 10 18 24 22 15 31 44 35 66 90 70 50 25 ");
    stringstream in;
    for (auto it = t2.begin_inorder(); it != t2.end_inorder(); ++it) {
        in << (*it) << " ";
    }
            CHECK(in.str() == "4 10 12 15 18 22 24 25 31 35 44 50 66 70 90 ");
    // let's change some vertices and see the iterators changes - it should change
            CHECK_NOTHROW(t2.add_root(-100));
            CHECK_NOTHROW(t2.add_left(10, std::numeric_limits<int>::max()));
            CHECK_NOTHROW(t2.add_left(35, -9));
    /* this is the tree:
     *              -100
     *          /          \
     *        15           50
     *     /     \       /     \
     *    10     22     35     70
     *   /  \   /  \   /  \   /  \
     *  ∞   12 18  24 -9  44 66  90
     */
    stringstream pre2;
    for (auto it = t2.begin_preorder(); it != t2.end_preorder(); ++it) {
        pre2 << (*it) << " ";
    }
            CHECK(pre2.str() == "-100 15 10 2147483647 12 22 18 24 50 35 -9 44 70 66 90 ");
    stringstream post2;
    for (auto it = t2.begin_postorder(); it != t2.end_postorder(); ++it) {
        post2 << (*it) << " ";
    }
            CHECK(post2.str() == "2147483647 12 10 18 24 22 15 -9 44 35 66 90 70 50 -100 ");
    stringstream in2;
    for (auto it = t2.begin_inorder(); it != t2.end_inorder(); ++it) {
        in2 << (*it) << " ";
    }
            CHECK(in2.str() == "2147483647 10 12 15 18 22 24 -100 -9 35 44 50 66 70 90 ");
}
