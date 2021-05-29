#pragma once

#include <map>
#include <algorithm>
#include <stack>
#include <queue>

namespace ariel {
    template<typename T>
    class BinaryTree {
    private:
        class node {
        public:
            T info;
            node *left;
            node *right;
            node *father;

            node() = default;

            node(T info) : info(info) {
                this->father = nullptr;
                this->left = nullptr;
                this->right = nullptr;
            }

            void setFather(node *father) {
                this->father = father;
            }

            bool operator==(node other) {
                return this->info == other->other && this->left == other->left &&
                       this->right == other.right && this->father == other.father;
            }

            bool operator!=(node other) {
                return this->info != other->other || this->left != other->left ||
                       this->right != other.right || this->father != other.father;
            }
        };
        //end class node//
    public:
        //class BinaryTree//
        std::multimap<T, node *> map;
        node *root;

        BinaryTree() {
            root = nullptr;
        }

        void copy_ctor(node *nd, const node *other_nd) {
            if (other_nd->left != nullptr) {
                nd->left = new node(other_nd->left->info);
                copy_ctor(nd->left, other_nd->left);
            }
            if (other_nd->right != nullptr) {
                nd->right = new node(other_nd->right->info);
                copy_ctor(nd->right, other_nd->right);
            }
        }

        BinaryTree &operator=(const BinaryTree<T> &bt) {
            if (this == &bt) {
                return *this;
            }
            if (root != nullptr) {
                delete root;
            }
            if (bt.root != nullptr) {
                root = new node{bt.root->info};
                copy_ctor(root, bt.root);
            }
            return *this;
        }

        BinaryTree(const BinaryTree &bt) { //copy ctor
            if (bt.root != nullptr) {
                this->root = new node(bt.root->info);
                copy_ctor(root, bt.root);
            }
        }


        //class BinaryTree//

        void remove(T data, node *ptr) {
            typedef typename std::multimap<T, node *>::iterator iterator;
            std::pair <iterator, iterator> iterpair = map.equal_range(data);
            iterator it = iterpair.first;
            for (; it != iterpair.second; ++it) {
                if (it->second == ptr) {
                    map.erase(it);
                    break;
                }
            }
        }

        BinaryTree<T> &add_root(T data) {
            if (root == nullptr) { //root doesn't exits
                root = new node(data);
                map.insert({data, root});
            } else { //root exists
                T old_data = root->info;
                root->info = data;
                map.insert({data, root});
                remove(old_data, root);
            }
            return *this;
        }

        BinaryTree<T> &add_left(T father, T son) {
            if (root == nullptr) {
                std::string message = "There is no root";
                throw std::invalid_argument(message);
            }
            auto f = map.find(father);
            if (f != map.end()) {
                if (f->second->left == nullptr) { //left son doesn't exists
                    node *nd = new node(son);
                    nd->father = f->second;
                    f->second->left = nd;
                    map.insert({son, nd});
                } else { //son exists
                    f->second->left->info = son;
                    remove(son, f->second->left);
                    map.insert({son, f->second->left});
                }
            } else {
                std::string message = "The first argument is not in the tree";
                throw std::invalid_argument(message);
            }
            return *this;
        }

        BinaryTree<T> &add_right(T father, T son) {
            if (root == nullptr) {
                std::string message = "There is no root";
                throw std::invalid_argument(message);
            }
            auto f = map.find(father);
            if (f != map.end()) {
                if (f->second->right == nullptr) { //left son doesn't exists
                    node *nd = new node(son);
                    nd->father = f->second;
                    f->second->right = nd;
                    map.insert({son, nd});
                } else { //son exists
                    f->second->right->info = son;
                    remove(son, f->second->right);
                    map.insert({son, f->second->right});
                }
            } else {
                std::string message = "The first argument is not in the tree";
                throw std::invalid_argument(message);
            }
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree &BinaryTree) { return os; }

        class PreorderIterator {
        private:
            std::stack<node *> s;
            std::queue<node *> queue;
            node *p_curr;

        public:
            PreorderIterator() : p_curr(nullptr) {}

            PreorderIterator(node *root) {
                s.push(root);
                node *curr;
                while (!s.empty()) {
                    curr = s.top();
                    s.pop();
                    queue.push(curr);
                    if (curr->right != nullptr)
                        s.push(curr->right);
                    if (curr->left != nullptr)
                        s.push(curr->left);
                }
                p_curr = queue.front();
            }


            T &operator*() const {
                return p_curr->info;
            }

            T *operator->() const {
                return &(p_curr);
            }

            PreorderIterator &operator++() {
                if (queue.empty()) {
                    p_curr = nullptr;
                }
                else{
                    queue.pop();
                    p_curr = queue.front();
                }
                return *this;
            }

            const PreorderIterator operator++(int) {
                PreorderIterator tmp = *this;
                if (queue.empty()) {
                    p_curr = nullptr;
                }
                else{
                    queue.pop();
                    p_curr = queue.front();
                }
                return tmp;
            }

            bool operator==(const PreorderIterator &rhs) const {
                return p_curr == rhs.p_curr;
            }

            bool operator!=(const PreorderIterator &rhs) const {
                return p_curr != rhs.p_curr;
            }
        };
        //end class PreorderIterator//

        PreorderIterator begin_preorder() {
            return PreorderIterator{root};
        }

        PreorderIterator end_preorder() {
            return PreorderIterator{};
        }


        typedef class InorderIterator {
        private:
            node *p_curr;
            std::queue<node *> queue;
            std::stack<node *> s;
        public:
            InorderIterator() : p_curr(nullptr) {}

            InorderIterator(node *root) {
                node *curr = root;
                //pushing all left nodes
                while(curr!= nullptr){
                    s.push(curr);
                    curr = curr->left;
                }
                if(s.empty()){ //no nodes in the tree
                    p_curr= nullptr;
                }else{ //taking the most left node as the first one
                    p_curr = s.top();
                }
            }

            T &operator*() const {
                return p_curr->info;
            }

            T *operator->() const {
                return &(p_curr->info);
            }

            InorderIterator &operator++() {
                if(!s.empty()) {
                    node* temp = s.top();
                    s.pop();
                    if (temp->right != nullptr) {
                        s.push(temp->right);
                        temp = temp->right->left;
                        while (temp != nullptr) { //pushing the left tree of the curr's right son
                            s.push(temp);
                            temp = temp->left;
                        }
                    }
                    if(s.empty()){
                        this->p_curr = nullptr;
                    }else{
                        this->p_curr = s.top();
                    }
                }else{ //we finished all the stack- end of the tree
                    this->p_curr = nullptr;
                }
                return *this;
            }

//            const InorderIterator operator++(int) {
//                InorderIterator tmp = *this;
//                queue.pop();
//                p_curr = queue.front();
//                return tmp;
//            }

            bool operator==(const InorderIterator &rhs) const {
                return p_curr == rhs.p_curr;
            }

            bool operator!=(const InorderIterator &rhs) const {
                return p_curr != rhs.p_curr;
            }
        } iterator;
        //end class InorderIterator//

        InorderIterator begin_inorder() {
            return InorderIterator{root};
        }

        InorderIterator end_inorder() {
            return InorderIterator();
        }

        InorderIterator begin() {
            return begin_inorder();
        }

        InorderIterator end() {
            return end_inorder();
        }

        class PostorderIterator {
            friend class node;

        private:
            std::stack<node *> s1;
            std::stack<node *> s2;
            node *p_curr;
        public:
            PostorderIterator() : p_curr(nullptr) {}

            PostorderIterator(node *root) {
                s1.push(root);
                node *curr = root;
                while (!s1.empty()) {
                    curr = s1.top();
                    s1.pop();
                    s2.push(curr);
                    if (curr->left)
                        s1.push(curr->left);
                    if (curr->right)
                        s1.push(curr->right);
                }
                p_curr = s2.top();
            }

            node *curr_node() {
                return p_curr;
            }

            T &operator*() const {
                return p_curr->info;
            }

            T *operator->() const {
                return &(p_curr->info);
            }

            PostorderIterator &operator++() {
                s2.pop();
                if (!s2.empty()) {
                    p_curr = s2.top();
                } else {
                    p_curr = nullptr;
                }
                return *this;
            }

            PostorderIterator operator++(int) {
                PostorderIterator tmp = *this;
                s2.pop();
                if (!s2.empty()) {
                    p_curr = s2.top();
                }
                return tmp;
            }

            bool operator==(const PostorderIterator &rhs) const {
                return p_curr == rhs.p_curr;
            }

            bool operator!=(const PostorderIterator &rhs) const {
                return p_curr != rhs.p_curr;
            }
        };
        //end class PostorderIterator//

        PostorderIterator begin_postorder() {
            return PostorderIterator{root};
        }

        PostorderIterator end_postorder() {
            return PostorderIterator{};
        }

        ~BinaryTree() {
            for (auto it = (*this).begin_postorder(); it != (*this).end_postorder(); ++it) {
                delete it.curr_node();
            }
        }
    };
}