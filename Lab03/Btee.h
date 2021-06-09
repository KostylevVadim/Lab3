#pragma once
#include "../../../Lab02/Lab02/ArraySequence.h"
#include <iostream>
#include <iomanip>

using namespace std;

template <class T> struct Tree
{
	Tree* left;
	Tree* right;
	T num;
	Tree(T n = 0, Tree* l = 0, Tree* r = 0) :num(n), left(l), right(r) {}

};
template <class T> class BTree
{
	Tree<T>* root;
	void adder(Tree<T>*& t, T n) {
		if (t == NULL) {
			t = new Tree<T>(n);

		}
		else {

			if (n < t->num) {
				adder(t->left, n);
				//cout << "\n";

			}
			else {
				if (n > t->num)
					adder(t->right, n);
				else {
					return;
				}
			}
		}

	}
	void printer(Tree<T>* t, int tab)
	{
		if (!t) {
			return;
		}
		tab += 5;
		//cout << t->num<<" ";
		printer(t->left, tab);
		for (int i = 0; i < tab; i++)
			cout << " ";
		cout << "|-";
		cout << t->num << " \n";
		printer(t->right, tab);
		tab -= 5;
	}
	bool finder(T value, Tree<T>* node) {
		while (node != NULL) {
			if (value == node->num) {
				return 1;
			}
			else {
				if (value < node->num) {
					return finder(value, node->left);
				}
				else {
					return finder(value, node->right);
				}
			}
			return 0;
		}
	}
	void remover(T data, Tree<T>* current, Tree<T>* prev) {
		//cout << "Current data " << current->num<<" Looking for"<<data<<endl;
		if (current == NULL)
			return;
		else
			if (data > current->num) {
				//cout << "Turn right\n";
				prev = current;
				remover(data, current->right, prev);
			}
			else
				if (data < current->num) {
					//cout << "Turn left\n";
					prev = current;
					remover(data, current->left, prev);
				}
				else {
					if (current->left == NULL && current->right == NULL) {
						//cout << "Iamwhtyoneed\n";
						bool wasleft = false;
						bool wasright = false;
						T x = current->num;
						T y;
						T z;

						if (prev->left) {
							wasleft = true;
							y = prev->left->num;
							//cout << y<<endl;
						}
						if (prev->right) {
							wasright = true;
							z = prev->right->num;
							//cout << z<<endl;
						}
						
						delete current;
						current = nullptr;
						if (wasleft) {
							//cout << "iaminwasleft\n"<<x;
							cout << y;
							if (y==x) {
								//cout << "iamherewasleft\n";
								prev->left = NULL;
							}
						}
						if (wasright) {
							//cout << "iaminwasleft\n" << x;
							//cout << z;
							if (z == x) {
								//cout << "iamherewasright\n";
								prev->right = NULL;
							}
						}
					}
					else
						if (current->right == NULL) {
							//cout << "I am without right\n";

							T x = current->num;
							T y = current->num;;
							T z = current->num;;
							bool wasright = false;
							bool wasleft = false;
							if (prev->left) {
								wasleft = true;
								y = prev->left->num;
							}
							if (prev->right) {
								wasright = true;
								z = prev->right->num;
							}
							if (wasleft && x == y) {
								prev->left = current->left;
							}
							if (wasright && x == z) {
								prev->right = current->left;
							}
							delete current;



						}
						else
							if (current->left == NULL) {
								//cout << "I am without left\n";

								//cout << "asd";
								T x = current->num;
								T y;
								T z;
								bool wasright = false;
								bool wasleft = false;
								if (prev->left) {
									wasleft = true;
									y = prev->left->num;
								}
								if (prev->right) {
									wasright = true;
									z = prev->right->num;
								}
								if (wasleft && x == y) {
									//cout << "Iamify\n";
									prev->left = current->right;
								}
								if (wasright && x == z) {
									//cout << "Iamifz\n";
									prev->right = current->right;
								}
								delete current;



							}
							else
								if (current->left != NULL && current->right != NULL) {
									//cout << "I am with all\n";
									Tree<T>* prevcur = current;
									Tree<T>* temp = current->right;
									while (temp->left != NULL) {
										prevcur = temp;
										temp = temp->left;
									}
									//cout << temp->num << endl;
									current->num = temp->num;
									remover(temp->num, current->right, current);
								}
				}

	};
	void Treefind(T data, Tree<T>* t) {
		if (t != NULL) {
			
			if (data == t->num) {
				
				BTree<T> x(t);
				x.print();
			}
			else
				if (data < t->num)
					Treefind(data, t->left);
				else
					if (data > t->num)
						Treefind(data, t->right);
		}
	}
	void Maper(T(*mapper)(T), Tree<T>* t) {
		t->num = mapper(t->num);
		if (t->left) Maper(mapper, t->left);

		if (t->right) Maper(mapper, t->right);
	}
	T Reducer(T(*reducer)(T, T), T c, Tree<T>* t) {
		if (t) {
			T res = reducer(t->num, c);
			res = Reducer(reducer, res, t->left);
			res = Reducer(reducer, res, t->right);
			return res;
		}
		return c;
	}
	void Wherer(bool(*wherer)(T), Tree<T>* t, BTree<T>* tre) {
		if (wherer(t->num))
			tre->add(t->num);
		if (t->left) Wherer(wherer, t->left, tre);
		if (t->right) Wherer(wherer, t->right, tre);
	}
	void Treetoar(Tree<T>* data, ArraySequence<T>* s1) {
		s1->Append(data->num);

		if (data->left)Treetoar(data->left, s1);
		if (data->right)Treetoar(data->right, s1);
	}
	bool Search_Subtreeer(Tree<T>* from, Tree<T>* with, bool x) {
		if (with == NULL) {
			return true;
		}
		else
			if (from == NULL && with != NULL) {
				return false;
			}
			else
				if (from != NULL) {
					if (from->num == with->num) {
						if (Search_Subtreeer(from->left, with->left, x) == 1 && Search_Subtreeer(from->right, with->right, x) == 1) {
							return true;
						}
					}
					bool m = Search_Subtreeer(from->left, with, x);
					bool d = Search_Subtreeer(from->right, with, x);
					x =x|| m || d;
				}
		return x;
	}
public:
	BTree<T>() {
		root = NULL;
	}
	BTree<T>(Tree<T>* data) {
		root = data;
	}
	Tree<T>* GetRoot() {
		return root;
	}
	void add(T n) {

		adder(root, n);
	}
	void print() {
		int tab = 0;
		printer(root, tab);
	}
	bool find(T t) {
		return finder(t, root);

	}
	void remove(T data) {
		if (root->left != NULL && root->right != NULL && data == root->num) {
			remover(data, root, NULL);
		}
		else {
			if (root->left != NULL && root->right != NULL && data != root->num) {
				remover(data, root, NULL);
			}
			else {
				if (root->left != NULL && root->right == NULL && data == root->num) {
					Tree<T>* temp = root;
					temp = temp->left;
					root = NULL;
					root = temp;

				}
				else {


					if (root->left == NULL && root->right != NULL && data == root->num) {
						Tree<T>* temp = root;
						temp = temp->right;
						root = NULL;
						root = temp;
					}
					if (root->left == NULL && root->right != NULL && data != root->num) {
						remover(data, root, root);
					}
				}
				if (root->left != NULL && root->right == NULL && data != root->num) {
					remover(data, root, NULL);
				}

			}
		}

	}
	void GetSubtree(T data) {
		Treefind(data, root);
	}
	bool search_Subtree(const BTree<T> tree) {
		bool x = false;
		bool t = Search_Subtreeer(root, tree.root, x);
		return t;
		
	}
	BTree<T> Map(T(*mapper)(T)) {
		assert(mapper != NULL);
		BTree<T> mapcopy = BTree<T>(*this);
		Maper(mapper, mapcopy.root);
		return mapcopy;

	}
	T Reduce(T(*reducer)(T, T), T c) {
		assert(reducer != NULL);
		T res = Reducer(reducer, c, root);
		return res;
	}
	BTree<T>* Where(bool(*wherer)(T)) {
		assert(wherer != NULL);
		BTree<T>* whercopy = new BTree<T>;
		Wherer(wherer, root, whercopy);
		return whercopy;
	}
	void TreetoSeq(ArraySequence<T>* s1) {
		Treetoar(this->GetRoot(), s1);
	}

};