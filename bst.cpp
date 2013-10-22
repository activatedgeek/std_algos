#include <iostream>
using namespace std;

class Node{
public:
	int val;
	Node *parent,*left,*right;
	Node(){
		parent=NULL;
		left=NULL;
		right=NULL;
		val=0;
	}
};

class BST{
public:
	Node* root;
	void insert(int);
	void inOrderWalk(Node*);
	void delTree(Node*);
	bool delNode(int);
	bool delNode(Node*);
	void transplant(Node*,Node*);
	Node* search(int);
	Node* successor(Node*);
	Node* predecessor(Node*);
	Node* treeMinimum(Node*);
	Node* treeMaximum(Node*);
	BST(){
		root=NULL;
	}
	~BST(){
		delTree(this->root);
	}
};

void BST::insert(int k){
	Node *iter=this->root;
	Node *iterprev=NULL;
	while(iter!=NULL){
		iterprev=iter;
		if(k<=iter->val)
			iter=iter->left;
		else
			iter=iter->right;
	}
	if(iterprev==NULL){
		this->root=new Node;
		this->root->val=k;
	}
	else if(k<=iterprev->val){
		iterprev->left=new Node;
		iterprev->left->val=k;
		iterprev->left->parent=iterprev;
	}
	else if(k>iterprev->val){
		iterprev->right=new Node;
		iterprev->right->val=k;
		iterprev->right->parent=iterprev;
	}
}
Node* BST::treeMinimum(Node* node){
	Node *iter=node;
	while(iter->left!=NULL)
		iter=iter->left;
	return iter;
}

Node* BST::treeMaximum(Node* node){
	Node *iter=node;
	while(iter->right!=NULL)
		iter=iter->right;
	return iter;
}

Node* BST::successor(Node* node){
	if(node->right!=NULL)
		return this->treeMinimum(node->right);
	Node *iter = node;
	Node *iterp = iter->parent;
	while(iterp!=NULL && iterp->right==iter){
		iter = iterp;
		iterp = iter->parent;
	}
	return iterp;
}

Node* BST::predecessor(Node* node){
	if(node->left!=NULL)
		return this->treeMaximum(node->left);
	Node *iter = node;
	Node *iterp = iter->parent;
	while(iterp!=NULL && iterp->left==iter){
		iter = iterp;
		iterp = iter->parent;
	}
	return iterp;
}

Node* BST::search(int k){
	Node *iter=this->root;
	while(iter!=NULL){
		if(iter->val==k)
			return iter;
		else if(k<=iter->val)
			iter=iter->left;
		else if(k>iter->val)
			iter=iter->right;
	}
	return NULL;
}

void BST::inOrderWalk(Node* start){
	if(start!=NULL){
		if(start->left!=NULL)
			this->inOrderWalk(start->left);
		std::cout<<start->val<<" ";
		if(start->right!=NULL)
			this->inOrderWalk(start->right);
	}
}

void BST::delTree(Node *node){
	if(node!=NULL){
		if(node->left!=NULL)
			delTree(node->left);
		if(node->right!=NULL)
			delTree(node->right);
		delete node;
	}
}

bool BST::delNode(int k){
	Node *point = this->search(k);
	if(point==NULL)
		return false;

	//leaf
	if(point->left==NULL && point->right==NULL){
		if(point==this->root){
			delete point;
			this->root=NULL;
			return true;
		}
		if(point->parent->left==point)
			point->parent->left=NULL;
		else if(point->parent->right==point)
			point->parent->right=NULL;
		delete point;
		return true;
	}
	//only left subtree exists
	else if(point->left!=NULL && point->right==NULL){
		if(point==this->root){
			point->left->parent=NULL;
			this->root = point->left;
			return true;
		}
		else if(point->parent->left==point)      //point is left child
			point->parent->left = point->left;
	
		else if(point->parent->right==point)  //point is right child
			point->parent->right= point->left;

		delete point;
		return true;
	}
	//only right subtree exists
	else if(point->left==NULL && point->right!=NULL){
		if(point==this->root){
			point->right->parent=NULL;
			this->root = point->right;
			return true;
		}
		if(point->parent->left==point)        //point is left child
			point->parent->left = point->right;

		else if(point->parent->right==point)  //point is right child
			point->parent->right= point->right;

		delete point;
		return true;
	}
	//both subtrees exist
	else if(point->left!=NULL && point->right!=NULL){
		Node *replace = predecessor(point);
		point->val=replace->val;
		if(replace->left==NULL){
			if(replace->parent->left==replace)
				replace->parent->left=NULL;
			else if(replace->parent->right==replace)
				replace->parent->right=NULL;
		}
		else if(replace->left!=NULL){
			if(replace->parent->right==replace)
				replace->parent->right=replace->left;
			else if(replace->parent->left==replace)
				replace->parent->left=replace->left;
		}
		delete replace;
		return true;
	}
	return true;
}

bool BST::delNode(Node *point){
	if(point==NULL)
		return false;

	//leaf
	if(point->left==NULL && point->right==NULL){
		if(point==this->root){
			delete point;
			this->root=NULL;
			return true;
		}
		if(point->parent->left==point)
			point->parent->left=NULL;
		else if(point->parent->right==point)
			point->parent->right=NULL;
		delete point;
		return true;
	}
	//only left subtree exists
	else if(point->left!=NULL && point->right==NULL){
		if(point==this->root){
			point->left->parent=NULL;
			this->root = point->left;
			return true;
		}
		else if(point->parent->left==point)      //point is left child
			point->parent->left = point->left;
	
		else if(point->parent->right==point)  //point is right child
			point->parent->right= point->left;

		delete point;
		return true;
	}
	//only right subtree exists
	else if(point->left==NULL && point->right!=NULL){
		if(point==this->root){
			point->right->parent=NULL;
			this->root = point->right;
			return true;
		}
		if(point->parent->left==point)        //point is left child
			point->parent->left = point->right;

		else if(point->parent->right==point)  //point is right child
			point->parent->right= point->right;

		delete point;
		return true;
	}
	//both subtrees exist
	else if(point->left!=NULL && point->right!=NULL){
		Node *replace = predecessor(point);
		point->val=replace->val;
		if(replace->left==NULL){
			if(replace->parent->left==replace)
				replace->parent->left=NULL;
			else if(replace->parent->right==replace)
				replace->parent->right=NULL;
		}
		else if(replace->left!=NULL){
			if(replace->parent->right==replace)
				replace->parent->right=replace->left;
			else if(replace->parent->left==replace)
				replace->parent->left=replace->left;
		}
		delete replace;
		return true;
	}
	return true;
}


int main(){
	BST T;
	return 0;
}
