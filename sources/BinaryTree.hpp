#include <iostream>
#include <string>

namespace ariel {
    template<typename T>class BinaryTree{

        private:
        class Node {
            public:
            T key;
            Node *left= nullptr;
            Node *right=nullptr;
            Node(const T &key) : key(key), right(nullptr), left(nullptr) {}
            ~Node(){
            delete right;
            delete left;
            }
        };
        Node* root;

        public:
        BinaryTree() : root(nullptr){}
        ~BinaryTree() { delete root; }
        //Node *found(Node *n, T key);
        BinaryTree &add_root(T k) {//get a key, and put it as a root (if there already a root- change it)
            root = new Node(k);
            return *this;
        }   
        BinaryTree &add_left(const T &k, const T & new_k) {//should get an exist key, and a new key. add the new on the left of the exist (change if there already son)
            return *this;
        }
        BinaryTree &add_right(const T &k, const T & new_k) {//should get an exist key, and a new key. add the new on the right of the exist (change if there already root)
             return *this;
        }

        class iterator {
            Node* pNode;
            public:
            iterator(Node* p = nullptr) : pNode(p){}
            T &operator*()const { 
                return pNode->key;
            }
            T *operator->()const {
                return &(pNode->key);
            }
            iterator& operator++() { return *this; } 
            iterator operator++(int t) { return *this; }
            bool operator==(const iterator& it)const { return false; }
            bool operator!=(const iterator& it)const { return false; }
            };  
                  
           iterator begin_preorder() {
               return iterator(root);
           } 
           iterator end_preorder() {
               return iterator{};
           }
           iterator begin_inorder() {
               return iterator(root);
           }
           iterator end_inorder() {
               return iterator{};
               }
           iterator begin_postorder() {
               return iterator(root);
           }
           iterator end_postorder() {
               return iterator{};
            }
           iterator begin() {
               return iterator{};
            }
           iterator end() {
               return iterator{};
            }
           
           friend std::ostream &operator<<(std::ostream &out, const BinaryTree<T> &tree) {
            out<<"tree"; 
            return out;
           }
    };
    /*
    template<typename T>
    typename BinaryTree<T>::Node *BinaryTree<T>::found(BinaryTree::Node *node, T key) {
        if (node == nullptr || node->key == key) { return node; }
        Node *find_left = found(node->left, key);
        Node *find_right = found(node->right, key);
        if (find_left == nullptr) { return find_right; } 
        else { return find_left; }
    } */
}
