#include <iostream>
using namespace std;

class TreeNode{
public:
	int data;
	TreeNode *parent, *left, *right;
	TreeNode(){
		parent = NULL;
		left = NULL;
		right = NULL;
	}
	TreeNode(int k){
		data = k;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
	TreeNode operator=(const TreeNode& equate){
		this->data = equate.data;
		delete parent, left, right;
		this->parent = equate.parent;
		this->left = equate.left;
		this->right = equate.right;
	}
	bool operator==(const TreeNode& right){
		return this->data == right.data;
	}
	bool operator<(const TreeNode& right){
		return this->data < right.data;
	}
	bool operator<=(const TreeNode& right){
		return this->data <= right.data;
	}
	bool operator>(const TreeNode& right){
		return this->data > right.data;
	}
	bool operator>=(const TreeNode& right){
		return this->data >= right.data;
	}
};

template<class T>
class BST{
public:
	T* root;
	T* insert(T*);
	void delTree(T*);
	bool delNode(T*);
	T* leftRotate(T*);
	T* rightRotate(T*);
	T* search(T*);
	T* successor(T*);
	T* predecessor(T*);
	T* treeMinimum(T*);
	T* treeMaximum(T*);
	int height();
	void inOrderWalk(T*);
	void preOrderWalk(T*);
	void postOrderWalk(T*);
	BST(){
		root = NULL;
	}
	~BST(){
		delTree(this->root);
	}
};

template<class T>
T* BST<T>::insert(T* node){
	T *iter = this->root;
	T *iterprev = NULL;
	bool match = false;
	while (iter != NULL){
		iterprev = iter;
		if (*node == *iter){
			//iter->data;
			return iter;
		}
		else if (*node < *iter)
			iter = iter->left;
		else if (*node > *iter)
			iter = iter->right;
	}

	if (iterprev == NULL){
		this->root = new T;
		this->root = node;
		return this->root;
	}
	else if (*node < *iterprev){
		iterprev->left = new T;
		iterprev->left = node;
		iterprev->left->parent = iterprev;
		return iterprev->left;
	}
	else if (*node > *iterprev){
		iterprev->right = new T;
		iterprev->right = node;
		iterprev->right->parent = iterprev;
		return iterprev->right;
	}
	return NULL;
}

template<class T>
bool BST<T>::delNode(T *point){
	if (point == NULL)
		return false;

	//leaf
	if (point->left == NULL && point->right == NULL){
		if (point == this->root){
			delete point;
			this->root = NULL;
			return true;
		}
		if (point->parent->left == point)
			point->parent->left = NULL;
		else if (point->parent->right == point)
			point->parent->right = NULL;
		delete point;
		return true;
	}
	//only left subtree exists
	else if (point->left != NULL && point->right == NULL){
		if (point == this->root){
			point->left->parent = NULL;
			this->root = point->left;
			return true;
		}
		else if (point->parent->left == point)      //point is left child
			point->parent->left = point->left;

		else if (point->parent->right == point)  //point is right child
			point->parent->right = point->left;

		delete point;
		return true;
	}
	//only right subtree exists
	else if (point->left == NULL && point->right != NULL){
		if (point == this->root){
			point->right->parent = NULL;
			this->root = point->right;
			return true;
		}
		if (point->parent->left == point)        //point is left child
			point->parent->left = point->right;

		else if (point->parent->right == point)  //point is right child
			point->parent->right = point->right;

		delete point;
		return true;
	}
	//both subtrees exist
	else if (point->left != NULL && point->right != NULL){
		Node *replace = predecessor(point);
		point->val = replace->val;
		if (replace->left == NULL){
			if (replace->parent->left == replace)
				replace->parent->left = NULL;
			else if (replace->parent->right == replace)
				replace->parent->right = NULL;
		}
		else if (replace->left != NULL){
			if (replace->parent->right == replace)
				replace->parent->right = replace->left;
			else if (replace->parent->left == replace)
				replace->parent->left = replace->left;
		}
		delete replace;
		return true;
	}
	return true;
}

template<class T>
void BST<T>::delTree(T *t){
	if (t != NULL){
		if (t->left != NULL)
			delTree(t->left);
		if (t->right != NULL)
			delTree(t->right);
		delete t;
	}
}

template<class T>
T* BST<T>::search(T* node){
	T *iter = this->root;
	while (iter != NULL){
		if (*iter == *node)
			return iter;
		else if (*node < *iter)
			iter = iter->left;
		else if (*node > *iter)
			iter = iter->right;
	}
	return NULL;
}

template<class T>
T* BST<T>::treeMinimum(T* t){
	T *iter = node;
	while (iter->left != NULL)
		iter = iter->left;
	return iter;
}

template<class T>
T* BST<T>::treeMaximum(T* t){
	T *iter = node;
	while (iter->right != NULL)
		iter = iter->right;
	return iter;
}

template<class T>
T* BST<T>::successor(T* t){
	if (t->right != NULL)
		return this->treeMinimum(t->right);
	T *iter = t;
	T *iterp = iter->parent;
	while (iterp != NULL && iterp->right == iter){
		iter = iterp;
		iterp = iter->parent;
	}
	return iterp;
}

template<class T>
T* BST<T>::predecessor(T* t){
	if (t->left != NULL)
		return this->treeMaximum(t->left);
	T *iter = t;
	T *iterp = iter->parent;
	while (iterp != NULL && iterp->left == iter){
		iter = iterp;
		iterp = iter->parent;
	}
	return iterp;
}

template<class T>
void BST<T>::inOrderWalk(T* start){
	if (start != NULL){
		if (start->left != NULL)
			this->inOrderWalk(start->left);
		std::cout << start->data << " ";
		if (start->right != NULL)
			this->inOrderWalk(start->right);
	}
}

template<class T>
void BST<T>::preOrderWalk(T* start){
	if (start != NULL){
		std::cout << start->data << " ";
		if (start->left != NULL)
			this->inOrderWalk(start->left);
		if (start->right != NULL)
			this->inOrderWalk(start->right);
	}
}

template<class T>
void BST<T>::postOrderWalk(T* start){
	if (start != NULL){
		if (start->left != NULL)
			this->inOrderWalk(start->left);
		if (start->right != NULL)
			this->inOrderWalk(start->right);
		std::cout << start->data << " ";
	}
}


int main(){
	BST<TreeNode> T;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; ++i)
		T.insert(new TreeNode(rand() % 100 + 1));
	T.inOrderWalk(T.root);
	return 0;
}
