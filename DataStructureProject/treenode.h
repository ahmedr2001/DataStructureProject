#pragma once

template<class T>
class treenode {
private:
	T data; // data of tree node
	treenode<T>* left; // pointer to left tree node
	treenode<T>* right; // pointer to right tree node
public:
	void setdata(T d) { // set data of the tree node
		data = d;
	}
	void setleft(treenode<T>* l) { //set left branch
		left = l;
	}
	void setright(treenode<T>* r) { //set right branch
		right = r;
	}
	T getdata() { // get data of the tree node
		return data;
	}
	treenode<T>* getleft() { // get pointer to left branch
		return left;
	}
	treenode<T>* getright() { // get pointer to right branch
		return right;
	}
};