//
// Created by tal on 18/05/2021.
//

#pragma once

#include <iostream>
#include <string>

namespace ariel {
    template<typename T>
    class BinaryTree {
    private:
        struct Node {
            Node *left, *right, *father;
            T value;

            explicit Node(const T &val = 0, Node *dad = nullptr,
                          Node *lef = nullptr, Node *righ = nullptr) : father(dad), value(val), left(lef),
                                                                       right(righ) {};

        };

        Node *root;
    public:
        BinaryTree() : root(nullptr) {}

        BinaryTree &add_root(const T &val) {
            if(root!= nullptr){
                delete root;
            }
            root=new Node(val);
            return *this;
        };

        BinaryTree &add_left(const T &father, const T &son) { return *this; };

        BinaryTree &add_right(const T &father, const T &son) { return *this; };

        class iterator {
        private:
            Node *curr;

            void (*func)();

        public:
            explicit iterator(Node *ptr = nullptr, void (*ord)() = nullptr) : curr(ptr), func(ord) {};

            static void pre_order() {};

            static void in_order() {};

            static void post_order() {};

            T &operator*() const {
                //return (int)0;
                return curr->value;
            };

            T *operator->() const {
                return &(curr->value);
            };

            // ++i;
            iterator &operator++() { return *this; };
//        {
//            //++pointer_to_current_node;
//            pointer_to_current_node = pointer_to_current_node;
//            return *this;
//        }

            // i++;
            // Usually iterators are passed by value and not by const& as they are small.
            //const

            iterator operator++(int) { return *this; };
//        {
//            iterator tmp= *this;
//            pointer_to_current_node= pointer_to_current_node->m_next;
//            return tmp;
//        }

            bool operator==(const iterator &rhs) const { return false; };
//        {
//            return pointer_to_current_node == rhs.pointer_to_current_node;
//        }

            bool operator!=(const iterator &rhs) const { return false; };
//        {
//            return pointer_to_current_node != rhs.pointer_to_current_node;
//        }

        };

        iterator begin_preorder() {
            // return &(m_first->m_value);
            return iterator{root, &iterator::pre_order};
        };

        iterator end_preorder() { return iterator(); };

        iterator begin_inorder() {
            return iterator{root, &iterator::in_order};
            //a.func = iterator::in_order();

        };

        iterator end_inorder() { return iterator(); };

        iterator begin_postorder() {
            return iterator{root, &iterator::post_order};
        };

        iterator end_postorder() { return iterator(); };

        iterator begin() { return begin_inorder(); };

        iterator end() { return iterator(); };

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &tree) {
            return os;
        };
//        void *pre_order();
//        void  *in_order();
//        void *post_order();
    ~BinaryTree() {
        delete root;
      };
    };


}