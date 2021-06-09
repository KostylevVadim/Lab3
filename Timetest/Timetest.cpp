#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include "../Lab03/BQ.h"
#include "../Lab03/Set.h"
#include "../Lab03/Btee.h"
using namespace std;
int main()
{
	ofstream fout("Data.txt");
	fout << "Start\n";
	fout << "ADD\n";
	fout << "TREE\n";
	cout << "ADD\n";
	for (int i = 0; i < 15; i++) {
		int start = clock();
		BTree<int> t1;
		
		for (int j = 0; j < 100*i; j++)
			t1.add(j);

		int end = clock();
		int x = end - start;
		fout << x << "-" << 100*i << "\n";
	}
	cout << 1;
	fout << "SET\n";
	for (int i = 0; i < 15; i++) {

		Set<int> t2;
		int start = clock();
		for (int j = 0; j < 100 * i; j++)
			t2.add(j);

		int end = clock();
		int x = end - start;
		fout << x << "-" << 100 * i << "\n";
	}
	cout << 2;
	fout << "BQ\n";
	for (int i = 0; i < 15; i++) {
		BQ<int> t3;
		int start = clock();
		for (int j = 0; j < 100 * i; j++)
			t3.add(1,j);

		int end = clock();
		int x = end - start;
		fout << x << "-" << 100 * i << "\n";
	}
	fout << "\n========================================================\n";
	cout << "\nFIND\n";
	fout << "FIND\n";
	fout << "TREE\n";
	for (int i = 0; i < 15; i++) {
		
		BTree<int> t1;

		for (int j = 0; j < 100 * i; j++)
			t1.add(j);
		bool y = 0;
		
		int start = clock();
		for (int j = 0; j < 100 * i; j++)
			y = t1.find(j);
		int end = clock();
		int x = end - start;
		fout << x << "->" << pow(2, i) << "\n";
	}
	cout << 1;
	fout << "SET\n";
	for (int i = 0; i < 15; i++) {

		Set<int> t2;
		for (int j = 0; j < 100 * i; j++)
			t2.add(j);
		bool y = 0;
		
		int start = clock();
		for (int j = 0; j < 100 * i; j++)
			y = t2.find(j);
		int end = clock();
		int x = end - start;
		fout << x << "-" << 100 * i << "\n";
	}
	cout << 2;
	fout << "BQ\n";
	for (int i = 0; i < 15; i++) {
		//cout << "a";
		BQ<int> t3;
		
		for (int j = 0; j < 100 * i; j++)
			t3.add(j, j);
		bool y = 0;
		
		int start = clock();
		for (int j = 0; j < 100 * i; j++)
			y = t3.find(j);
		int end = clock();
		int x = end - start;
		fout << x << "-" << 100 * i << "\n";
	}
	fout << "\n========================================================\n";
	cout << "REMOVE\n";
	fout << "REMOVE\n";
	fout << "TREE\n";
	for (int i = 0; i < 15; i++) {

		BTree<int> t1;

		for (int j = 0; j < 100 * i; j++)
			t1.add(j);
		bool y = 0;

		int start = clock();
		for (int j = 0; j < 100 * i-1; j++)
			t1.remove(j);
		int end = clock();
		int x = end - start;
		fout << x << "-" << 100 * i << "\n";
	}
	cout << 1;
	fout << "SET\n";
	for (int i = 0; i < 15; i++) {

		Set<int> t2;
		for (int j = 0; j < 100 * i; j++)
			t2.add(j);
		bool y = 0;

		int start = clock();
		for (int j = 0; j < 100 * i-1; j++)
			t2.remove(j);
		int end = clock();
		int x = end - start;
		fout << x << "-" << 100 * i << "\n";
	}
	cout << 2;
	fout << "BQ\n";
	for (int i = 0; i < 15; i++) {
		//cout << "a";
		BQ<int> t3;

		for (int j = 0; j < 100 * i; j++)
			t3.add(j, j);
		bool y = 0;

		int start = clock();
		for (int j = 0; j < 100 * i-1; j++)
			t3.remove(j);
		int end = clock();
		int x = end - start;
		fout << x << "-" << 100 * i << "\n";
	}


}
