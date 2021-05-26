#pragma once
#include <map>
#include <algorithm>


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

            node() {
                this->father = nullptr;
                this->left = nullptr;
                this->right = nullptr;
            }

            node(T info) {
                this->info = info;
                this->father = nullptr;
                this->left = nullptr;
                this->right = nullptr;
            }

            ~node() {
                if (this->left != nullptr) delete (this->left);
                if (this->right != nullptr) delete (this->right);
            }

            void setFather(node *father) {
                this->father = father;
            }
        };
        //end class node//
    public:
        //class BinaryTree//
        multimap <T, node*> map;
        node *root;

        BinaryTree() {
            root = nullptr;
        }

        //class BinaryTree//
        ~BinaryTree() {
            //TODO: delete all tree from last to first
            delete (root);
        }

        void remove(T data, node* ptr){
            typedef typename multimap<T, node*>::iterator iterator;
            std::pair<iterator, iterator> iterpair = map.equal_range(data);
            iterator it = iterpair.first;
            for (; it != iterpair.second; ++it) {
                if (it->second == ptr) {
                    map.erase(it);
                    break;
                }
            }
        }

        BinaryTree<T> &add_root(T data) {
            if (root== nullptr) { //root doesn't exits
                root = new node();
                root->info = data;
                map.insert({data, root});
            }
            else{ //root exists
                root->info = data;
                map.insert({data, root});
                remove(data, root);
            }
            return *this;
        }

        BinaryTree<T> &add_left(T father, T son) {
            auto f = map.find(father);
            if (f!=map.end()){
                if (f->second->left== nullptr){ //left son doesn't exists
                    node* nd = new node(son);
                    nd->father=f->second;
                    f->second->left=nd;
                    map.insert({son,nd});
                }
                else{ //son exists
                    f->second->left->info = son;
                    remove(son, f->second->left);
                    map.insert({son,f->second->left});
                }
            }
            else{
                string message = "The first argument is not in the tree";
                throw std::invalid_argument(message);
            }
            return *this;
        }

        BinaryTree<T> &add_right(T father, T son) {
            auto f = map.find(father);
            if (f!=map.end()){
                if (f->second->right== nullptr){ //left son doesn't exists
                    node* nd = new node(son);
                    nd->father=f->second;
                    f->second->right=nd;
                    map.insert({son,nd});
                }
                else{ //son exists
                    f->second->right->info = son;
                    remove(son, f->second->right);
                    map.insert({son,f->second->right});
                }
            }
            else{
                string message = "The first argument is not in the tree";
                throw std::invalid_argument(message);
            }
            return *this;
        }

//        friend std::ostream &operator<<(std::ostream &os, const BinaryTree &BinaryTree) {}

        typedef class InorderIterator {
            friend class node;

        private:
            node *p_curr;
        public:
            InorderIterator(node *curr) {
                this->p_curr = curr;
            }

            T &operator*() const {
                return p_curr->info;
            }

            T *operator->() const {
                return &(p_curr);
//                return &(p_curr->info);
            }

            InorderIterator &operator++() {
                if (p_curr->right == nullptr && p_curr->left == nullptr){ // no sons
                    p_curr = p_curr->father;
                }
                else { //one or two sons
                    if (p_curr->right!= nullptr){ // has a right son
                        p_curr = p_curr->right;
                    }
                    else{ //has no right son- but left son
                        p_curr = p_curr->left;
                    }
                }
                return *this;
            }

            const InorderIterator operator++(int) {
                InorderIterator tmp = *this;
                if (p_curr->right == nullptr && p_curr->left == nullptr){ // no sons
                    p_curr = p_curr->father;
                }
                else { //one or two sons
                    if (p_curr->right!= nullptr){ // has a right son
                        p_curr = p_curr->right;
                    }
                    else{ //has no right son- but left son
                        p_curr = p_curr->left;
                    }
                }
                return tmp;
            }

            bool operator==(const InorderIterator &rhs) const {
                return p_curr == rhs.p_curr;
            }

            bool operator!=(const InorderIterator &rhs) const {
                return p_curr != rhs.p_curr;
            }
        } iterator;
        //end class InorderIterator//

        InorderIterator begin_inorder() {
            node* curr = root;
            while (curr->right!= nullptr){
                curr = curr->right;
            }
            return InorderIterator{curr};
        }

        InorderIterator end_inorder() {
            return InorderIterator{nullptr};
        }

        InorderIterator begin(){
            return begin_inorder();
        }

        InorderIterator end(){
            return end_inorder();
        }

        class PreorderIterator {
            friend class node;

        private:
            node *p_curr;
        public:
            PreorderIterator(node *curr) {
                this->p_curr = curr;
            }

            T &operator*() const {
                return p_curr->info;
            }

            T *operator->() const {
                return &(p_curr);
            }

            PreorderIterator &operator++() {
                if (p_curr->left != nullptr){
                    p_curr= p_curr->left;
                } else if (p_curr->left != nullptr) {
                    p_curr = p_curr->right;
                }
//                } else {
//                    p_curr; //TODO:CHANGE
//                }
                p_curr = p_curr->right;
                return *this;
            }

            const PreorderIterator operator++(int) {
                //TODO: CHANGE
                PreorderIterator tmp = *this;
                p_curr = p_curr->right;
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
            return PreorderIterator{nullptr};
        }

        class PostorderIterator {
            friend class node;

        private:
            node *p_curr;
        public:
            PostorderIterator(node *curr) {
                this->p_curr = curr;
            }

            T &operator*() const {
                return p_curr->info;
            }

            T *operator->() const {
                return &(p_curr->info);
            }

            PostorderIterator &operator++() {
                //TODO: CHANGE
                p_curr = p_curr->right;
                return *this;
            }

            const PostorderIterator operator++(int) {
                //TODO: CHANGE
                PostorderIterator tmp = *this;
                p_curr = p_curr->right;
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
            return PostorderIterator{nullptr};
        }

    };
}