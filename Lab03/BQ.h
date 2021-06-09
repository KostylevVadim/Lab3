#pragma once
#include <iomanip>
#include <iostream>
#include "../../../Lab02/Lab02/ArraySequence.h"

template <class T> struct Qnode {
	Qnode<T>* left;
	Qnode<T>* right;
	size_t key;
	T num;
	Qnode(T n = 0, size_t k = 0, Qnode* l = 0, Qnode* r = 0) :num(n), key(k), left(l), right(r) {}


};

template <class T> struct BQ {
private:
	Qnode<T>* root;
	void adder(Qnode<T>*& t, T n, size_t key) {
		if (t == NULL) {
			//cout << "asd ";
			t = new Qnode<T>(n, key);
			//cout << t->num << t->key;

		}
		else {
			//cout << "rrr";

			if (key < t->key) {
				adder(t->left, n, key);
				//cout << "\n";

			}
			else {
				//cout << "lll";
				if (key > t->key)
					adder(t->right, n, key);
				else {
					return;
				}
			}
		}
	}
	void printer(Qnode<T>* t, int tabm)
	{
		//cout << "I am here";
		if (!t) {
			//cout << "I am here";
			return;
		}
		tabm += 5;
		printer(t->left,tabm);
		for (int i = 0; i < tabm; i++)
			cout << " ";
		cout << "|-";
		cout << "" << t->num << " " << t->key << " \n";
		printer(t->right,tabm);
		tabm -= 5;
	}
	void SubQer(size_t start, size_t end, Qnode<T>* t, BQ<T>* sub) {
		if (!t) {
			return;
		}
		if (start <= t->key && t->key <= end)
			sub->add(t->num, t->key);
		SubQer(start, end, t->left, sub);

		SubQer(start, end, t->right, sub);

	};
	bool finder(Qnode<T>* t, T data, bool x) {
		if (t) {
			//cout << t->num<<" "<< data<<endl;
			if (t->num == data) {
				cout << "\nI found it\n";
				return true;
			}
			bool m = finder(t->left, data, x);
			bool b = finder(t->right, data, x);
			x = x||m||b;
			return x;
		}
		if (!t) {
			return false;
		}
	}
	void remover(BQ<T>* extra,T data, Qnode<T>* t) {
		if (t) {
			if (t->num != data) {
				extra->add(t->num,t->key);
			}
			remover(extra, data, t->left);
			remover(extra, data, t->right);
		}
	}


public:
	BQ() {
		root = NULL;
	}

	BQ(Qnode<T>* n) {
		root = n;
	}
	void add(T n, size_t key) {
		adder(root, n, key);
	}
	Qnode<T>* GetRoot() {
		return root;
	}
	void print() {
		int tabm = 0;
		printer(root, tabm);
	};
	BQ<T>* SubQfromto(size_t start, size_t end) {
		BQ<T>* sub = new BQ<T>;
		SubQer(start, end, root, sub);
		return sub;
	}
	void Settoseqkey(ArraySequence<size_t>* s1) {
		BQ_to_arr_key(root, s1);
	}
	void remove(T data) {
		BQ<T>* temp= new BQ<T>;
		remover(temp, data, root);
		root = NULL;
		root = temp->GetRoot();
	}
	void BQ_to_arr_key(Qnode<T>* data, ArraySequence<size_t>* s1) {
		s1->Append(data->key);
		if (data->left)BQ_to_arr_key(data->left, s1);
		if (data->right)BQ_to_arr_key(data->right, s1);
	}
	void BQ_to_arr(Qnode<T>* data, ArraySequence<T>* s1) {
		s1->Append(data->num);
		if (data->left)BQ_to_arr(data->left, s1);
		if (data->right)BQ_to_arr(data->right, s1);
	}

	bool find(T data) {

		bool z = 0;
		z = finder(root,data,z);
		return z;
	}
	void SettoSeq(ArraySequence<T>* s1) {
		BQ_to_arr(root, s1);
	}
	BQ<T> Map(T(*mapper)(T)) {
		assert(mapper != NULL);
		BQ<T> mapcopy = BQ<T>(*this);
		Maper(mapper, mapcopy.root);
		return mapcopy;

	}
	void Maper(T(*mapper)(T), Qnode<T>* t) {
		t->num = mapper(t->num);
		if (t->left) Maper(mapper, t->left);

		if (t->right) Maper(mapper, t->right);
	}
	T Reducer(T(*reducer)(T, T), T c, Qnode<T>* t) {
		if (t) {
			T res = reducer(t->num, c);
			res = Reducer(reducer, res, t->left);
			res = Reducer(reducer, res, t->right);
			return res;
		}
		return c;
	}

	T Reduce(T(*reducer)(T, T), T c) {
		assert(reducer != NULL);
		T res = Reducer(reducer, c, root);
		return res;
	}

	void Wherer(bool(*wherer)(T), Qnode<T>* t, BQ<T>* tre) {
		if (wherer(t->num))
			tre->add(t->num, t->key);
		if (t->left) Wherer(wherer, t->left, tre);
		if (t->right) Wherer(wherer, t->right, tre);
	}
	BQ<T>* Where(bool(*wherer)(T)) {
		assert(wherer != NULL);
		BQ<T>* whercopy = new BQ<T>;
		Wherer(wherer, root, whercopy);
		return whercopy;
	}

};