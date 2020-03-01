//DSA project ::: search engine optimization

#include <iostream>
using namespace std;

//creating node for binary tree
struct node {
	string movie_title;
	string tagline;
	string status;
	int runtime;
	int revenue;
	string release_date;

	node* left;
	node* right;
};

class btree {
public:
	btree();
	void insert(string key);
	node* root;
	void inorder(node* t);
	node* search(node* t,string key);
private:
	void insert(string key, node* leaf);

};

btree::btree(){}

void btree::insert(string key, node* leaf) {
	if (key < leaf->movie_title) {
		if (leaf->left != NULL) {
			insert(key, leaf->left);
		}

		else {
			leaf->left = new node;
			leaf->left->movie_title = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->movie_title) {
		if (leaf->right != NULL) {
			insert(key, leaf->right);
		}
		else {
			leaf->right = new node;
			leaf->right->movie_title = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}


void btree::insert(string key) {
	if (root != NULL) {
		insert(key, root);
	}
	else {
		root = new node;
		root->movie_title = key;
		root->left = NULL;
		root->right = NULL;
	}
}

void btree::inorder(node* t) {
	if (t != NULL) {
		inorder(t->left);
		cout << t->movie_title << " ";
		inorder(t->right);
	}
}

//for searching

node* btree::search(node* t,string key) {
	if (t == NULL) {
		return NULL;
	}
	else if (t->movie_title == key) {
		return t;
	}
	else if (key < t->movie_title) {
		return search(t->left, key);
	}
	else if (key > t->movie_title) {
		return search(t->right, key);
	}
}
int main() {
	string str[] = { "Hamza","Abdullah","Taha","Ali" };
	int n = 4;
	btree* bt = new btree();

	for (int i = 0; i < n; i++) {
		bt->insert(str[i]);
	}
	bt->inorder(bt->root);
	node* t = bt->root;
	t = bt->search(t, "Ali");
	cout <<endl<< t->movie_title;
}
