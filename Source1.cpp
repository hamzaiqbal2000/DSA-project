//DSA project ::: movie archive
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

//creating node for binary tree
struct node { //this node is for binary tree that will store all the details about a film
	string title; //placment in binary tree basis on title
	node* left;//pointer pointing to left child
	node* right;//pointer pointing to right child
	string genres;//the variables in each node for storing the details about the movie
	string budget;
	string popularity;
	string imdb_id;
	string release_date;
	string revenue;
	string runtime;
	string vote_average;
	string overview;
};

class btree {//class for binary tree structure which stores the movie names and their details
public:
	btree();//constructor
	//insert function for inserting data into the binary tree
	void insert(string title, string genres, string budget, string popularity, string imdb_id, string release_date, string revenue, string runtime, string vote_average, string overview);
	node* root = NULL;// the root node of the tree
	void inorder(node* t);//function for the inorder traversal of the binary search tree
	node* Rsearch(node* t, string title);//function for recursively searching the binary tree
	node* Isearch(node* t, string title);//function for iteratively searching the binary tree
private:
	void insert_into(string title, node* leaf, string genres, string budget, string popularity, string imdb_id, string release_date, string revenue, string runtime, string vote_average, string overview);

};
//constructor
btree::btree() {

}
//insert-into function for inserting data into the binary tree
void btree::insert_into(string title, node* leaf, string genres, string budget, string popularity, string imdb_id, string release_date, string revenue, string runtime, string vote_average, string overview) {
	if (title < leaf->title) {//checks if the title of the movie is smaller than the already present title in the node
		if (leaf->left != NULL) {//checks if node's left pointer is NULL or not
			insert_into(title, leaf->left, genres, budget, popularity, imdb_id, release_date, revenue, runtime,
				vote_average, overview);//recursively call the function to reach the leaf node
		}

		else {//creates a new node and insert the data into the variables
			leaf->left = new node;//creates new node
			leaf->left->title = title;
			leaf->left->genres = genres;
			leaf->left->budget = budget;
			leaf->left->popularity = popularity;
			leaf->left->imdb_id = imdb_id;
			leaf->left->release_date = release_date;
			leaf->left->revenue = revenue;
			leaf->left->runtime = runtime;
			leaf->left->vote_average = vote_average;
			leaf->left->overview = overview;
			leaf->left->left = NULL;//assigns NULL to left pointer
			leaf->left->right = NULL;//assigns NULL to right pointer
		}
	}
	else if (title >= leaf->title) {//checks if node's right pointer is NULL or not
		if (leaf->right != NULL) {
			insert_into(title, leaf->right, genres, budget, popularity, imdb_id, release_date, revenue, runtime,
				vote_average, overview);//recursively calls the function to reach the leaf node
		}
		else {//creates a new node and insert the data into the variables
			leaf->right = new node;//creates new node
			leaf->right->title = title;
			leaf->right->genres = genres;
			leaf->right->budget = budget;
			leaf->right->popularity = popularity;
			leaf->right->imdb_id = imdb_id;
			leaf->right->release_date = release_date;
			leaf->right->revenue = revenue;
			leaf->right->runtime = runtime;
			leaf->right->vote_average = vote_average;
			leaf->right->overview = overview;
			leaf->right->left = NULL;//assigns NULL to left pointer
			leaf->right->right = NULL;//assigns NULL to right pointer
		}
	}
}

//insert-into function for inserting data into the binary tree by using insert-into function
void btree::insert(string title, string genres, string budget, string popularity, string imdb_id, string release_date, string revenue, string runtime, string vote_average, string overview) {
	if (root != NULL) {//check if the rrot node is present or not
		insert_into(title, root, genres, budget, popularity, imdb_id, release_date, revenue, runtime, vote_average,
			overview);
	}
	else {//if root node is not present it creates the root node and inserts the data into it
		root = new node;//creates new node
		root->title = title;
		root->genres = genres;
		root->budget = budget;
		root->popularity = popularity;
		root->imdb_id = imdb_id;
		root->release_date = release_date;
		root->revenue = revenue;
		root->runtime = runtime;
		root->vote_average = vote_average;
		root->overview = overview;
		root->left = NULL;//assigns NULL to left pointer
		root->right = NULL;//assigns NULL to right pointer
	}
}
//function for recursively searching the binary tree
node* btree::Rsearch(node* t, string title) {
	if (t == NULL) {//checks if the binary seach tree is empty or traversal has reached leaf node
		return NULL;
	}
	else if (t->title == title) {//if the the key data is matching the data in node
		return t;
	}
	else if (title < t->title) {//checks if data to find is less than data in the present node
		return Rsearch(t->left, title);//recursively calls the left child
	}
	else if (title > t->title) {//checks if data to find is more than data in the present node
		return Rsearch(t->right, title);//recursively calls the right child
	}
}
node* btree::Isearch(node* t, string title) {
	while (t != NULL) {//loop until the pointer reaches end of the binary tree
		if (title == t->title) {//checks if data to find is less than data in the present node
			return t;
		}
		else if (title < t->title) {//checks if data to find is less than data in the present node
			t = t->left;
		}
		else {//moves to the right child
		}
		t = t->right;
	}
}
//function for the inorder traversal of the binary search tree
void btree::inorder(node* t) {
	if (t != NULL) {
		inorder(t->left);//recursively calling the left child
		std::cout << "title: " << t->title << " " << '\n';//printing the details about the movie
		std::cout << "genre: " << t->genres << '\n';
		std::cout << "budget: " << t->budget << '\n';
		std::cout << "popularity: " << t->popularity << '\n';
		std::cout << "imdb_id: " << t->imdb_id << '\n';
		std::cout << "release_date: " << t->release_date << '\n';
		std::cout << "revenue: " << t->revenue << '\n';
		std::cout << "runtime: " << t->runtime << '\n';
		std::cout << "vote_average: " << t->vote_average << '\n';
		std::cout << "overview: " << t->overview << '\n';
		std::cout << "-------------------" << '\n';
		inorder(t->right);//recursively calling the right child
	}
}
class Node {
public:
	string data = ""; //basic node of the link list used in the node of the binary tree that would be storing the genres
	Node* next = NULL;
};
class Linked_Node { //linked list to store the names of the movies according to their genres
public:
	bool flag = false; //flag is used to identify whether the node is the first node to be entered or not
	Node* head = new Node; //creates the first node
	void Insert(string data) {
		Node* temp = new Node(); //creates node for storing the data of the newest elemet to be inserted
		temp->data = data;
		temp->next = NULL;
		if (flag == false) { // empty list
			head = temp;
			flag = true;
			return;
		}

		Node* temp2 = new Node();
		temp2 = head;
		while (temp2->next != NULL) { //finds the end of the linked list
			temp2 = temp2->next;
		}

		temp2->next = temp; //inserts the new node to the last of the linked list
	}

	void Print() {
		Node* temp = head;
		while (temp != NULL) {
			std::cout << temp->data << endl;
			temp = temp->next;
		}
		std::cout << "\n";
	} //prints all the elements of the linked list
};

class node2 { //node for genre binary tree, stores the genre and the linked list of the titles of the movies of that genre
public:
	string genre = "";
	Linked_Node* list = new Linked_Node;
	node2* leftptr = NULL;
	node2* rightptr = NULL;
};
class btgenre {
public:
	node2* head = new node2; //head node of the binary search tree
	void push(string title, string genre) {
		node2* traverse = search(genre); //first searches if there exists a node with the genre of the node about to be inserted
		if (traverse == nullptr) { //if there exists no such genre already in the tree then the program proceeds to insert the new node appropriately
			node2* temp = new node2; //node to be inserted
			traverse = new node2; //node for traversing through the tree
			temp->genre = genre;
			temp->list->Insert(title);
			if (head == NULL) { //if empty tree
				head = temp;
				return;
			}
			traverse = head;
			while (1) { //finds the appropriate end of the tree to insert the data at, traversing while comparing the titles in the tree
				if (temp->genre < traverse->genre && traverse->leftptr == NULL) {
					traverse->leftptr = temp;
					break;
				}
				else if (temp->genre >= traverse->genre && traverse->rightptr == NULL) {
					traverse->rightptr = temp;
					break;
				}
				else if (temp->genre < traverse->genre) {
					traverse = traverse->leftptr;
				}
				else {
					traverse = traverse->rightptr;
				}
			}
		}
		else {
			traverse->list->Insert(title); //if there exists a genre node already in the tree then it adds the title to the linked list of that pre-existing node
		}
	}
	node2* search(string a) {
		node2* traverse = head;
		while (1) {
			if (traverse == nullptr or traverse->genre == a) {
				break;
			}
			if (a < traverse->genre) {
				traverse = traverse->leftptr;
				continue;
			}
			else if (a > traverse->genre) {
				traverse = traverse->rightptr;
				continue;
			}
		}
		return traverse;
	}
};

/*int main() {
	head = NULL;
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);
	Print();//2 4 6 5
	int n;
	std::cout << "Enter a positon Number";
	std::cin >> n;
	Delete(n);
	Print();
}*/

class GenreSort { //class dedicated to the creation and handling of the genre tree
public:
	btgenre* GTree = new btgenre; //tree that will store the genres
	node2* result = new node2; //will save the result after searching through the genre binary tree
	void create() {
		string title;
		string genre;
		string temp;
		ifstream ip("movies_metadata.csv"); //opens the excel file to be read
		if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';
		getline(ip, temp, ','); //takes the first line containing the headings to discard them
		getline(ip, temp, ',');
		getline(ip, temp, '\n');
		while (ip.good()) {
			getline(ip, title, ','); //reads the title and the genre
			getline(ip, genre, ',');
			getline(ip, temp, '\n');
			GTree->push(title, genre); //stores them in the tree
		}
		ip.close();
	}
	void suggestion(string genre) { //takes in the genre and returns the node of that genre after searching through the tree
		result = GTree->search(genre);
		result->list->Print(); //prints all the titles of the linked list in that genre
	}
};
//GLOBAL VARIABLES
btree* bt = new btree; //made it global so multiple classes can use it
GenreSort GS; //made it global so prompting class and a few others can use the same copy of tree once created
class prompting {
public:
	void main_prompt() { //main prompt for the basic search function
		string input;
		creation();
		while (1) {
			cout << "Enter the name of the movie you wish to search:" << endl;
			getline(std::cin, input); //takes title of movie as input
			OUTPUT(input); //calls output method to show the results found in the tree regarding the movie
			cout << "Would you like to search another movie?(Y/N)" << endl; //prompts the user to search for another movie
			cin >> input;
			cin.ignore();
			if (input == "N" || input == "n") //loops until n or N is pressed
				break;
		}
	}
	void OUTPUT(string input) {
		node* t = bt->root; //node created to get the searched results
		//bt->inorder(bt->root);
		clock_t startTime = clock(); //starts clock
		t = bt->Rsearch(bt->root, input); //calls the search function with the title to be searched
		cout << "Total Time in searching a database of 45000 records: " << double(clock() - startTime) / CLOCKS_PER_SEC << endl; //shows the time taken to search through the database
		std::cout << "title: " << t->title << " " << '\n'; //shows the info
		std::cout << "genre: " << t->genres << '\n';
		std::cout << "budget: " << t->budget << '\n';
		std::cout << "popularity: " << t->popularity << '\n';
		std::cout << "imdb_id: " << t->imdb_id << '\n';
		std::cout << "release_date: " << t->release_date << '\n';
		std::cout << "revenue: " << t->revenue << '\n';
		std::cout << "runtime: " << t->runtime << '\n';
		std::cout << "vote_average: " << t->vote_average << '\n';
		std::cout << "overview: " << t->overview << '\n';
		std::cout << "-------------------" << '\n';
		cout << "would you like to know the suggestions of movies with similar genre? (Y/N)" << endl;
		cin >> input;
		if (input == "Y" || input == "y") { //prompts if the user wishes to see the suggestions of movies similar to the searched movie
			cout << "These are movies with similar Genre:" << endl;
			GS.suggestion(t->genres); //calls the suggestion method of the genre tree to show the titles with similar genre
			return;
		}
		else
			return;
	}
	void creation() { //creates the binary tree of movie information and the genre
		string title; //placment in binary tree basis on title
		string genres;
		string budget;
		string popularity;
		string imdb_id;
		string release_date;
		string revenue;
		string runtime;
		string vote_average;
		string overview;
		ifstream ip("movies_metadata.csv");

		if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

		while (ip.good()) {

			getline(ip, title, ','); //reads a single cell from excel spreadsheet, stores it in a variable and continues
			getline(ip, genres, ',');
			getline(ip, budget, ',');
			getline(ip, popularity, ',');
			getline(ip, imdb_id, ',');
			getline(ip, release_date, ',');
			getline(ip, revenue, ',');
			getline(ip, runtime, ',');
			getline(ip, vote_average, ',');
			getline(ip, overview, '\n');

			bt->insert(title, genres, budget, popularity, imdb_id, release_date, revenue, runtime, vote_average, overview); //inserts the data into the tree


		}
		ip.close(); //closes the file
		GS.create(); //calls the method to create the binary tree for genres
	}
};
int main() {
	prompting P1;
	P1.main_prompt(); //calling the main prompt method of the prompting class to initialize the program
}
