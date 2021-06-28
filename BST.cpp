#include<exception>

#include "BST.h"

BST::Node* BST::getNode(ValueType value) {
    Node* cur = _root;
    while (cur) {
        if (value == cur->value) {
            return cur;
        }
        else if (value < cur->value) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    throw std::invalid_argument("Incorrect value");
}

BST::Node* BST::getPrevNode(ValueType value) {
    if (_root->value == value) {
        throw std::invalid_argument("The root has no previous node");
    }
    Node* cur = _root;
    Node* prev;
    while (cur) {
        if (value == cur->value) {
            return prev;
        }
        else if (value < cur->value) {
            prev = cur;
            cur = cur->left;
        }
        else {
            prev = cur;
            cur = cur->right;
        }
    }
    throw std::invalid_argument("Incorrect value");
}

void BST::replaceCur(Node* prev, Node* cur, Node* newCur) {
    if (cur == _root) {
        _root = newCur;
    }
    else if (prev->left == cur) {
        prev->left = newCur;
    }
    else {
        prev->right = newCur;
    }
    delete cur;
}

BST::BST() {
    _root = nullptr;
    _size = 0;
}

BST::BST(const BST& other) {

}

BST::BST(BST&& other) {

}

BST& BST::operator=(const BST& other) {

}

BST& BST::operator=(BST&& other) {

}

BST::~BST() {

}

void BST::add(ValueType value) {
    if (!_root) {
        _root = new Node(value);
    }
    else {
        Node* cur = _root;
        while (true) {
            if (value <= cur->value) {
                if (!cur->left) {
                    cur->left = new Node(value);
                    break;
                }
                else {
                    cur = cur->left;
                }
            }
            else {
                if (!cur->right) {
                    cur->right = new Node(value);
                    break;
                }
                else {
                    cur = cur->right;
                }
            }
        }
    }
    ++_size;
}

void BST::remove(ValueType value) {
    Node* cur = getNode(value);
    Node* prev = nullptr;
    if (_root != cur) {
        prev = getPrevNode(value);
    }

    if (!cur->left && !cur->right) {
        replaceCur(prev, cur, nullptr);
    }
    else if (!cur->left && cur->right) {
        replaceCur(prev, cur, cur->right);
    }
    else if (cur->left && !cur->right) {
        replaceCur(prev, cur, cur->left);
    }
    else {
        if (cur->right->left == nullptr) {
            cur->right->left = cur->left;
            replaceCur(prev, cur, cur->right);
        }
        else {
            Node* prev_ = cur;
            Node* cur_ = cur->right;
            while (cur->left) {
                prev_ = cur_;
                cur_ = cur_->left;
            }
            prev_->left = cur_->right;
            cur_->left = cur->left;
            cur_->right = cur->right;
            replaceCur(prev, cur, cur_);
        }
    }
    --_size;
}

ValueType & BST::find(ValueType value) {
    return (getNode(value))->value;
}