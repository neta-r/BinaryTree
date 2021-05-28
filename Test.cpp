#include "doctest.h"
#include "BinaryTree.hpp"
#include <string>
#include <limits>


using namespace std;
using namespace ariel;

template<typename T>
void check_pre(BinaryTree <T> t, string outcome) {
    string pre;
    for (auto it = t.begin_preorder(); it != t.end_preorder(); ++it) {
        pre = pre + to_string(*it) + " ";
    }
            CHECK(pre == outcome);
}

template<typename T>
void check_post(BinaryTree <T> t, string outcome) {
    string post;
    for (auto it = t.begin_postorder(); it != t.end_postorder(); ++it) {
        post = post + to_string(*it) + " ";
    }
            CHECK(post == outcome);
}

template<typename T>
void check_in(BinaryTree <T> t, string outcome) {
    string in;
    for (auto it = t.begin_inorder(); it != t.end_inorder(); ++it) {
        in = in + to_string(*it) + " ";
    }
            CHECK(in == outcome);
}

TEST_CASE ("char tree") {
    BinaryTree<char> t;
    // add root + add left + add right + concatenation tests (existing vertices)
    CHECK_NOTHROW(
            t.add_root('a')
                    .add_left('a', 'B')
                    .add_left('B', 'D')
                    .add_right('B', 'E')
                    .add_right('a', 'C')
                    .add_left('C', 'F')
                    .add_left('C', 'G'));
    // add left + add right tests (non existing vertices)
    CHECK_THROWS(t.add_left('Z', 'G'));
    CHECK_THROWS(t.add_right('Z', 'G'));
    // able to change the root
    CHECK_NOTHROW(t.add_root('A'));
    // unable to change the root (type is not T-char)
    CHECK_THROWS(t.add_root(5));
    CHECK_THROWS(t.add_root("a"));
    /* this is the tree:
     *      A
     *     / \
     *    B   C
     *   / \ / \
     *  D  E F  G
     */
    check_pre(t, "A B D E C F G ");
    check_post(t, "D E B F G C A ");
    check_in(t, "D B E A F C G ");
    // let's change some vertices and see the iterators changes - it should change
    CHECK_NOTHROW(t.add_root('a'));
    CHECK_THROWS(t.add_left('a', 'b'));
    CHECK_NOTHROW(t.add_left('B', 'd'));
    /* this is the tree:
    *      a
    *     / \
    *    B   c
    *   / \ / \
    *  d  E F  G
    */
    check_pre(t, "a B d E c F G ");
    check_post(t, "d E B F G c a ");
    check_in(t, "d B E a F c G ");
}
TEST_CASE ("int tree") {
    BinaryTree<int> t2;
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
    // unable to change the root (type is not T-int)
    CHECK_THROWS(t2.add_root('5'));
    CHECK_THROWS(t2.add_root("a"));
    /* this is the tree:
     *               25
     *          /          \
     *        15           50
     *     /     \       /     \
     *    10     22     35     70
     *   /  \   /  \   /  \   /  \
     *  4   12 18  24 31  44 66  90
     */
    check_pre(t2, "25 15 10 4 12 22 18 24 50 35 31 44 70 66 90 ");
    check_post(t2, "4 12 10 18 24 22 15 31 44 35 66 90 70 50 25 ");
    check_in(t2, "4 10 12 15 18 22 24 25 31 35 44 50 66 70 99 ");
    // let's change some vertices and see the iterators changes - it should change
    CHECK_NOTHROW(t2.add_root(-100));
    CHECK_THROWS(t2.add_left(10, std::numeric_limits<int>::max()));
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
    check_pre(t2, "-100 15 10 2147483647 12 22 18 24 50 35 31 -9 70 66 90 ");
    check_post(t2, "2147483647 12 10 18 24 22 15 31 -9 35 66 90 70 50 -100 ");
    check_in(t2, "2147483647 10 12 15 18 22 24 -100 31 35 -9 50 66 70 99 ");
}