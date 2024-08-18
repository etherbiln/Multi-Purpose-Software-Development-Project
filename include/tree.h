#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

#include "./student.h";

struct node {
    Student student;
    struct node* right;
    struct node* left;
};

struct node* new_node(Student student) {
    struct node* newnode = new struct node; // new ile bellek tahsisi
    newnode->student = student;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

 struct node* insert(struct node* root, Student student) {
    if (root != NULL) {
        if (student.getNote() < root->student.getNote()) {
            root->left = insert(root->left, student);
        }
        else {
            root->right = insert(root->right, student);
        }
    }
    else {
        root = new_node(student);
    }
    return root;
}


void displayPre(struct node* root) {
    if (root != NULL) {
        std::cout << root->student.getName() << " ";
        std::cout << root->student.getSurname()<<std::endl;
        std::cout << root->student.getNote();

        displayPre(root->left);
        displayPre(root->right);
    }
}
#endif