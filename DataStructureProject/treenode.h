#pragma once

template<class T>
class treenode {
private:
	T data;
	treenode<T>* left;
	treenode<T>* right;
public:
	void setdata(T d) {
		data = d;
	}
	void setleft(treenode<T>* l) {
		left = l;
	}
	void setright(treenode<T>* r) {
		right = r;
	}
	T getdata() {
		return data;
	}
	treenode<T>* getleft() {
		return left;
	}
	treenode<T>* getright() {
		return right;
	}
};