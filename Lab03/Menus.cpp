#include "Menus.h"
#include <sstream>
using namespace std;



Person Perr(Person x, Person y) {
	return x + y;
}

void Perstest() {

	BTree<string> a;
	a.add("bsd");
	a.add("asd");
	a.add("sad");
	a.add("yu");
	a.print();
	a.Map(Mch);
	a.print();
	BTree<Person> b;
	PersonID m;
	m.number = 123;
	m.series = 143;
	Person x(m, "asd", "ds", "dgf", 12);
	m.number = 89;
	m.series = 67;
	Person z(m, "llk", "op", "yt", 13);
	m.number = 12332;
	m.series = 8978;
	Person c(m, "iuo", "ytr", "etr", 321);
	b.add(x);
	b.add(z);
	b.add(c);
	b.print();
	Person asd = b.Reduce(Perr, c);
	cout << "\n" << asd;
}
void intmen() {
	srand(time(0));
	cout << "\nPrint Tree length\n";
	int x;
	cin >> x;
	BTree<int> f;
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int a = rand()%1000;
			f.add(a);
		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			int a;
			cin >> a;
			f.add(a);
		}
	}
	cout << "\n==================================\n";
	f.print();
	cout << "\n==================================\n";
	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Get subtree.\n9.Is there subtree?\n10.Exit\n";
	int us = -1;
	while (us != 10) {
		cout << "\n==================================\n";
		f.print();
		cout << "\n==================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			int x;
			cin >> x;
			f.add(x);
			break;
		}
		case 2: {
			int x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			int x;
			cin >> x;
			bool z = f.find(x);
			if (z == 1)
				cout << "\nYes\n";
			else {
				cout << "\nNo\n";
			}
			break;
		}
		case 4: {
			BTree<int> c = f.Map(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			int x = f.Reduce(ReduceCeck, 0);
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {
			BTree<int>* c = f.Where(Wherecheck);
			cout << "\n";
			c->print();
			break;
		}
		case 7: {
			f.print();
			break;
		}

		case 8: {
			cout << "Enter a value\n";
			int l;
			cin >> l;
			f.GetSubtree(l);
			//c.print();
			break;
		}
		case 9: {
			cout << "Enter length of subtree\n";
			int s;
			cin >> s;
			BTree<int> x;
			for (int i = 0; i < s; i++) {
				int y;
				cin >> y;
				x.add(y);
			}
			cout << f.search_Subtree(x);
			cout << endl;
			break;

		}
		case 10: {
			break;
		}
		default:
			break;
		}
	}
}
void domen() {
	srand(time(0));
	cout << "\nPrint Tree length\n";
	int x;
	cin >> x;
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	BTree<float> f;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int a = rand() % 1000;
			float b = (a + 0.0) / 100;
			f.add(b);
		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			float a;
			cin >> a;
			f.add(a);
		}
	}
	cout << "\n==================================\n";
	f.print();
	cout << "\n==================================\n";

	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Get subtree.\n9.Is there subtree?\n10.Exit\n";	
	int us = -1;
	while (us != 10) {
		cout << "\n==================================\n";
		f.print();
		cout << "\n==================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			float x;
			cin >> x;
			f.add(x);
			break;
		}
		case 2: {
			float x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			float x;
			cin >> x;
			bool z = f.find(x);
			cout << "\n" << z;
			break;
		}
		case 4: {
			BTree<float> c = f.Map(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			float x = f.Reduce(ReduceCeck, 0);
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {
			BTree<float>* c = f.Where(Wherecheck);
			cout << "\n";
			c->print();
			break;
		}
		case 7: {
			f.print();
			break; 
		}
		case 8: {
			cout << "Enter a value\n";
			float l;
			cin >> l;
			f.GetSubtree(l);
			
			break;
		}
		case 9: {
			cout << "Enter length of subtree\n";
			int s;
			cin >> s;
			BTree<float> x;
			for (int i = 0; i < s; i++) {
				float y;
				cin >> y;
				x.add(y);
			}
			cout << f.search_Subtree(x);
			break;

		}
		case 10: {
			break;
		}
		default:
			break;
		}
	}
}
void strimen() {
	srand(time(0));
	cout << "\nPrint Tree length\n";
	int x;
	cin >> x;
	cout << "\nPrint tree\n";
	BTree<string> f;
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int a = rand() % 1000;
			ostringstream ss;
			ss << a;
			string s =ss.str();
			f.add(s);
		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			string a;
			cin >> a;
			f.add(a);
		}
	}
	cout << "\n==================================\n";
	f.print();
	cout << "\n==================================\n";

	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Get subtree.\n9.Is there subtree?\n10.Exit\n";
	int us = -1;
	while (us != 10) {
		cout << "\n==================================\n";
		f.print();
		cout << "\n==================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			string x;
			cin >> x;
			f.add(x);
			break;
		}
		case 2: {
			string x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			string x;
			cin >> x;
			bool z = f.find(x);
			cout << "\n" << z;
			break;
		}
		case 4: {
			BTree<string> c = f.Map(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			string x = f.Reduce(ReduceCeck, "");
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {
			BTree<string>* c = f.Where(Wherecheck);
			cout << "\n";
			c->print();
			break;
		}
		case 7: {
			f.print();
			break;
		}

		case 8: {
			cout << "Enter a value\n";
			string l;
			cin >> l;
			f.GetSubtree(l);
			//c.print();
			break;
		}
		case 9: {
			cout << "Enter length of subtree\n";
			int s;
			cin >> s;
			BTree<string> x;
			for (int i = 0; i < s; i++) {
				string y;
				cin >> y;
				x.add(y);
			}
			cout << f.search_Subtree(x);
			break;

		}
		case 10: {
			break;
		}
		default:
			break;
		}
	}
}
void permen() {
	srand(time(0));

	cout << "\nPrint Tree length\n";
	int x;
	cin >> x;
	cout << "\nPrint tree\n";
	BTree<Person> f;
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int a = rand() % 1000;
			int b = rand() % 1000;
			int c = rand() % 1000;
			ostringstream ss;
			ostringstream ss1;
			ostringstream ss2;
			ss << a;
			string fin = ss.str();
			ss1 <<  b;
			string mn = ss1.str();
			ss2 << c;
			string ln = ss2.str();
			PersonID X;
			X.number = rand() % 100;
			X.series = rand() % 100;
			Person L(X,fin,mn,ln,rand()%100);
			f.add(L);

		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			Person a;
			cin >> a;
			f.add(a);
		}
	}
	cout << "\n==================================\n";
	f.print();
	cout << "\n==================================\n";
	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Get subtree.\n9.Is there subtree?\n10.Exit\n";
	int us = -1;
	while (us != 10) {
		cout << "\n==================================\n";
		f.print();
		cout << "\n==================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			Person x;
			cin >> x;
			f.add(x);
			break;
		}
		case 2: {
			Person x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			Person x;
			cin >> x;
			bool z = f.find(x);
			if (z) {
				cout << "\nYES\n";
			}
			else {
				cout << "\nNO\n";
			}
			break;
		}
		case 4: {
			BTree<Person> c = f.Map(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			PersonID z;
			z.number = 0;
			z.series = 0;
			Person m(z, "", "", "", 0);
			Person x = f.Reduce(ReduceCeck, m);
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {
			BTree<Person>* c = f.Where(Wherecheck);
			cout << "\n";
			c->print();
			break;
		}
		case 7: {
			f.print();
			break;
		}
		case 8: {
			cout << "Enter a value\n";
			Person l;
			cin >> l;
			f.GetSubtree(l);
			
			break;
		}
		case 9: {
			cout << "Enter length of subtree\n";
			int s;
			cin >> s;
			BTree<Person> x;
			for (int i = 0; i < s; i++) {
				Person y;
				cin >> y;
				x.add(y);
			}
			cout << f.search_Subtree(x);
			break;

		}
		case 10: {
			break;
		}
		default:
			break;
		}
	}
}
void commen() {
	srand(time(0));
	cout << "\nPrint Tree length\n";
	int x;
	cin >> x;
	cout << "\nPrint tree\n";
	BTree<Complex> f;
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int m = rand() % 1000;
			int n = rand() % 1000;
			float a = (m + 0.0) / 100;
			float b = (n + 0.0) / 100;
			Complex g(a, b);
			f.add(g);
		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			Complex a;
			cin >> a;
			f.add(a);
		}
	}
	cout << "\n==================================\n";
	f.print();
	cout << "\n==================================\n";
	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Get subtree.\n9.Is there subtree?\n10.Exit\n";
	int us = -1;
	while (us != 10) {
		cout << "\n==================================\n";
		f.print();
		cout << "\n==================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			Complex x;
			cin >> x;
			f.add(x);
			break;
		}
		case 2: {
			Complex x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			Complex x;
			cin >> x;
			bool z = f.find(x);
			cout << "\n" << z;
			break;
		}
		case 4: {
			BTree<Complex> c = f.Map(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			Complex x;
			x.imaginary = 0;
			x.real = 0;
			Complex z = f.Reduce(ReduceCeck, x);
			cout << z;
			break;
		}
		case 6: {
			BTree<Complex>* c = f.Where(Wherecheck);
			cout << "\n";
			c->print();
			break;
		}
		case 7: {
			f.print();
			break;
		}

		case 8: {
			cout << "Enter a value\n";
			Complex l;
			cin >> l;
			f.GetSubtree(l);
			
			break;
		}
		case 9: {
			cout << "Enter length of subtree\n";
			int s;
			cin >> s;
			BTree<Complex> x;
			for (int i = 0; i < s; i++) {
				Complex y;
				cin >> y;
				x.add(y);
			}
			cout << f.search_Subtree(x);
			break;

		}
		case 10: {
			break;
		}
		default:
			break;
		}
	}
}
void TreeMenu() {
	int usrch = -1;
	while (usrch != 6)
	{

		cout << "Enter type:\n1.Int\n2.Double\n3.String\n4.Person\n5.Complex\n6.Exit\n";
		cin >> usrch;
		cout << "\n";
		switch (usrch) {
		case 1: {
			intmen();
			break;
		}
		case 2: {
			domen();
			break;
		}
		case 3: {

			strimen();
			break;
		}
		case 4: {
			permen();
			break;

		}
		case 5: {
			commen();
			break;
		}
		default:
			break;
		}


	}

}

void intmens() {
	srand(time(0));
	cout << "\nPrint Set length\n";
	int x;
	cin >> x;
	cout << "\nPrint set\n";
	Set<int> f;
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int a = rand() % 1000;
			f.add(a);
		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			int a;
			cin >> a;
			f.add(a);
		}
	}
	cout << "\n==================================\n";
	f.print();
	cout << "\n==================================\n";
	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Unit with a new set.\n9.Mult on a new set.\n10.Minus a set.\n11.Subset.\n12.Is set equel.\n14.Exit";
	int us = -1;
	while (us != 14) {
		cout << "\n==================================\n";
		f.print();
		cout << "\n==================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			int x;
			cin >> x;
			f.add(x);
			break;
		}
		case 2: {
			int x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			int x;
			cin >> x;
			bool z = f.find(x);
			cout << "\n" << z;
			break;
		}
		case 4: {
			Set<int> c = f.Mapset(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			int x = f.Reduceset(ReduceCeck, 0);
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {
			Set<int> c = f.Whereset(Wherecheck);
			cout << "\n";
			c.print();
			break;
		}
		case 7: {
			f.print();
			break;
		}

		case 8: {
			Set<int> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				int a;
				cin >> a;
				x.add(a);
			}
			Set<int> z = x + f;
			z.print();
			break;
		}
		case 9: {
			Set<int> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				int a;
				cin >> a;
				x.add(a);
			}
			Set<int> z = f*x;
			z.print();
			break;
		}
		case 10: {
			Set<int> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				int a;
				cin >> a;
				x.add(a);
			}
			Set<int> z = f - x;
			z.print();
			break;
		}
		case 11: {

			Set<int> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				int a;
				cin >> a;
				x.add(a);
			}
			bool z = f.search_subset(x);
			cout << z << endl;
			break;
		}
		case 12: {
			Set<int> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				int a;
				cin >> a;
				x.add(a);
			}
			bool n = f.Is_Equel(x,y);
			if (n == true)
				cout << "\nYes\n";
			else {
				cout << "\nNo\n";
			}

			break;
		}
		case 13: {
			Set<int> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				int a;
				cin >> a;
				x.add(a);
			}
			bool s = f == x;
			cout<< s<<endl;
		}
		default:
			break;
		}
	}
}
void domens() {
	srand(time(0));
	cout << "\nPrint Set length\n";
	int x;
	cin >> x;
	cout << "\nPrint set\n";
	
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	Set<float> f;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int a = rand() % 1000;
			float b = (a + 0.0) / 100;
			f.add(b);
		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			float a;
			cin >> a;
			f.add(a);
		}
	}
	cout << "\n==================================\n";
	f.print(); 
	cout << "\n==================================\n";

	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Unit with a new set.\n9.Mult on a new set.\n10.Minus a set.\n11.Subset.\n12.Is set equel.\n13.Exit";
	int us = -1;
	while (us != 14) {
		cout << "\n==================================\n";
		f.print();
		cout << "\n==================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			float x;
			cin >> x;
			f.add(x);
			break;
		}
		case 2: {
			float x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			float x;
			cin >> x;
			bool z = f.find(x);
			cout << "\n" << z;
			break;
		}
		case 4: {
			Set<float> c = f.Mapset(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			float x = f.Reduceset(ReduceCeck, 0);
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {

			Set<float> c = f.Whereset(Wherecheck);
			cout << "\n";
			c.print();
			break;
		}
		case 7: {
			f.print();
			break;
		}

		case 8: {
			Set<float> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				float a;
				cin >> a;
				x.add(a);
			}
			Set<float> z =x.Union(f,x);
			z.print();
			break;
		}
		case 9: {
			Set<float> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				float a;
				cin >> a;
				x.add(a);
			}
			Set<float> z = f.Intersection(f,x);
			z.print();
			break;
		}
		case 10: {
			Set<float> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				float a;
				cin >> a;
				x.add(a);
			}
			Set<float> z = f.Substraction(f,x);
			z.print();
			break;
		}
		case 11: {

			Set<float> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				float a;
				cin >> a;
				x.add(a);
			}
			bool z = f.search_subset(x);
			cout << z << endl;
			break;
		}
		case 12: {
			Set<float> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				float a;
				cin >> a;
				x.add(a);
			}
			bool n = f.Is_Equel(x,y);
			if (n == true)
				cout << "\nYes\n";
			else {
				cout << "\nNo\n";
			}
		}
		default:
			break;
		}
	}
}
void strimens() {
	cout << "\nPrint Set length\n";
	int x;
	cin >> x;
	cout << "\nPrint set\n";
	Set<string> f;
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int a = rand() % 1000;
			ostringstream ss;
			ss << a;
			string s = ss.str();
			f.add(s);
		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			string a;
			cin >> a;
			f.add(a);
		}
	}
	cout << "\n==================================\n";
	f.print();
	cout << "\n==================================\n";
	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Unit with a new set.\n9.Mult on a new set.\n10.Minus a set.\n11.Subset.\n12.Is set equel.\n14.Exit";
	int us = -1;
	while (us != 14) {
		cout << "\n==================================\n";
		f.print();
		cout << "\n==================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			string x;
			cin >> x;
			f.add(x);
			break;
		}
		case 2: {
			string x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			string x;
			cin >> x;
			bool z = f.find(x);
			cout << "\n" << z;
			break;
		}
		case 4: {
			Set<string> c = f.Map(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			string x = f.Reduceset(ReduceCeck, 0);
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {
			Set<string> c = f.Whereset(Wherecheck);
			cout << "\n";
			c.print();
			break;
		}
		case 7: {
			f.print();
			break;
		}

		case 8: {
			Set<string> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				string a;
				cin >> a;
				x.add(a);
			}
			Set<string> z = x + f;
			z.print();
			break;
		}
		case 9: {
			Set<string> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				string a;
				cin >> a;
				x.add(a);
			}
			Set<string> z = f*x;
			z.print();
			break;
		}
		case 10: {
			Set<string> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				string a;
				cin >> a;
				x.add(a);
			}
			Set<string> z = f - x;
			z.print();
			break;
		}
		case 11: {

			Set<string> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				string a;
				cin >> a;
				x.add(a);
			}
			bool z = f.search_subset(x);
			cout << z << endl;
			break;
		}
		case 12: {
			Set<string> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				string a;
				cin >> a;
				x.add(a);
			}

			bool n = f.Is_Equel(x,y);
			if (n == true)
				cout << "\nYes\n";
			else {
				cout << "\nNo\n";
			}
		}
		default:
			break;
		}
	}
}
void permens() {
	cout << "\nPrint Set length\n";
	int x;
	cin >> x;
	cout << "\nPrint set\n";
	Set<Person> f;
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int a = rand() % 1000;
			int b = rand() % 1000;
			int c = rand() % 1000;
			ostringstream ss; ostringstream ss1; ostringstream ss2;
			ss << a;
			string fin = ss.str();
			ss1 << b;
			string mn = ss1.str();
			ss2 << c;
			string ln = ss2.str();
			PersonID X;
			X.number = rand() % 100;
			X.series = rand() % 100;
			Person L(X, fin, mn, ln, rand() % 100);
			f.add(L);

		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			Person a;
			cin >> a;
			f.add(a);
		}
	}
	cout << "\n==================================\n";
	f.print();
	cout << "\n==================================\n";
	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Unit with a new set.\n9.Mult on a new set.\n10.Minus a set.\n11.Subset.\n12.Is set equel.\n14.Exit";
	int us = -1;
	while (us != 14) {
		cout << "\n==================================\n";
		f.print();
		cout << "\n==================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			Person x;
			cin >> x;
			f.add(x);
			break;
		}
		case 2: {
			Person x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			Person x;
			cin >> x;
			bool z = f.find(x);
			cout << "\n" << z;
			break;
		}
		case 4: {
			Set<Person> c = f.Mapset(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			PersonID z;
			z.number = 0;
			z.series = 0;
			Person m(z, "", "", "", 0);
			Person x = f.Reduceset(ReduceCeck, m);
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {
			Set<Person> c = f.Whereset(Wherecheck);
			cout << "\n";
			c.print();
			break;
		}
		case 7: {
			f.print();
			break;
		}

		case 8: {
			Set<Person> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				Person a;
				cin >> a;
				x.add(a);
			}
			Set<Person> z = x + f;
			z.print();
			break;
		}
		case 9: {
			Set<Person> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				Person a;
				cin >> a;
				x.add(a);
			}
			Set<Person> z = f*x;
			z.print();
			break;
		}
		case 10: {
			Set<Person> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				Person a;
				cin >> a;
				x.add(a);
			}
			Set<Person> z = f - x;
			z.print();
			break;
		}
		case 11: {

			Set<Person> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				Person a;
				cin >> a;
				x.add(a);
			}
			bool z = f.search_subset(x);
			cout << z << endl;
			break;
		}
		case 12: {
			Set<Person> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				Person a;
				cin >> a;
				x.add(a);
			}

			bool n = f.Is_Equel(x,y);
			if (n == true)
				cout << "\nYes\n";
			else {
				cout << "\nNo\n";
			}
		}
		default:
			break;
		}
	}
}
void commens() {
	srand(time(0));
	cout << "\nPrint Set length\n";
	int x;
	cin >> x;
	cout << "\nPrint set\n";
	Set<Complex> f;
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int m = rand() % 1000;
			int n = rand() % 1000;
			float a = (m + 0.0) / 100;
			float b = (n + 0.0) / 100;
			Complex g(a, b);
			f.add(g);
		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			Complex a;
			cin >> a;
			f.add(a);
		}
	}
	cout << "\n==================================\n";
	f.print();
	cout << "\n==================================\n";
	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Unit with a new set.\n9.Mult on a new set.\n10.Minus a set.\n11.Subset.\n12.Is set equel.\n14.Exit\n";
	int us = -1;
	while (us != 14) {
		cout << "\n==================================\n";
		f.print();
		cout << "\n==================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			Complex x;
			cin >> x;
			f.add(x);
			break;
		}
		case 2: {
			Complex x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			Complex x;
			cin >> x;
			bool z = f.find(x);
			cout << "\n" << z;
			break;
		}
		case 4: {
			Set<Complex> c = f.Mapset(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			Complex m;
			m.imaginary = 0;
			m.real = 0;
			Complex x = f.Reduceset(ReduceCeck, m);
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {

			Set<Complex> c = f.Whereset(Wherecheck);
			cout << "\n";
			c.print();
			break;
		}
		case 7: {
			f.print();
			break;
		}

		case 8: {
			Set<Complex> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				Complex a;
				cin >> a;
				x.add(a);
			}
			Set<Complex> z = x + f;
			z.print();
			break;
		}
		case 9: {
			Set<Complex> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				Complex a;
				cin >> a;
				x.add(a);
			}
			Set<Complex> z = x * f;
			z.print();
			break;
		}
		case 10: {
			Set<Complex> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				Complex a;
				cin >> a;
				x.add(a);
			}
			Set<Complex> z = f - x;
			z.print();
			break;
		}
		case 11: {

			Set<Complex> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				Complex a;
				cin >> a;
				x.add(a);
			}
			bool z = f.search_subset(x);
			cout << z << endl;
			break;
		}
		case 12: {
			Set<Complex> x;
			cout << "Enter a new length\n";
			int y;
			cin >> y;
			for (int i = 0; i < y; i++) {
				Complex a;
				cin >> a;
				x.add(a);
			}
			bool n = f.Is_Equel(x,y);
			if (n == true)
				cout << "\nYes\n";
			else {
				cout << "\nNo\n";
			}
		}
		default:
			break;
		}
	}
}
void SetMenu() {
	int usrch = -1;
	while (usrch != 6)
	{

		cout << "Enter type:\n1.Int\n2.Double\n3.String\n4.Person\n5.Complex\n6.Exit\n";
		cin >> usrch;
		cout << "\n";
		switch (usrch) {
		case 1: {
			intmens();
			break;
		}
		case 2: {
			domens();
			break;
		}
		case 3: {

			strimens();
			break;
		}
		case 4: {
			permens();
			break;

		}
		case 5: {
			commens();
		}
		default:
			break;
		}
	}
}

void intmenp() {
	srand(time(0));
	cout << "\nPrint BQ length\n";
	int x;
	cin >> x;
	cout << "\nPrint BQ\n";
	BQ<int> f;
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int a = rand() % 1000;
			int b = rand() % 1000;
			f.add(a,b);
		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			int a,b;
			cin >> a>>b;
			f.add(a,b);
		}
	}
	cout << "\n==================================\n";
	f.print();
	cout << "\n==================================\n";
	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Get Subseq from i to j.\n";
	int us = -1;
	while (us != 9) {
		cout << "\n=======================================\n";
		f.print();
		cout << "\n=======================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			int x;
			cin >> x;

			size_t m;
			cin >> m;
			f.add(x, m);
			break;
		}
		case 2: {
			int x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			int x;
			cin >> x;
			bool z = 0;
			z = f.find(x);
			if (z == 1)
				cout << "Yes";
			else
				cout << "No";
			break;
		}
		case 4: {
			BQ<int> c = f.Map(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			int x = f.Reduce(ReduceCeck, 0);
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {
			BQ<int>* c = f.Where(Wherecheck);
			cout << "\n";
			c->print();
			break;
		}
		case 7: {
			f.print();
			break;
		}

		case 8: {
			cout << "Enter start and end\n";
			size_t s;
			cin >> s;
			size_t e;
			cin >> e;
			while (s >= e) {
				cout << "\nEnter other end\n";
				cin >> e;
			}
			BQ<int>* m = f.SubQfromto(s, e);
			m->print();
			break;
		}
		case 10: {
			break;
		}
		default:
			break;
		}
	}

}
void domenp() {
	srand(time(0));
	cout << "\nPrint BQ length\n";
	int x;
	cin >> x;
	cout << "\nPrint BQ\n";
	int u1;
	cin >> u1;
	BQ<float> f;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int a = rand() % 1000;
			float b = (a + 0.0) / 100;
			int c = rand() % 1000;
			f.add(b,c);
		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			float a;
			int b;
			cin >> a>>b;
			f.add(a,b);
		}
	}
	f.print();
	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Get Subseq from i to j.\n";
	int us = -1;
	while (us != 9) {
		cout << "\n=======================================\n";
		f.print();
		cout << "\n=======================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			float x;
			cin >> x;

			size_t m;
			cin >> m;
			f.add(x, m);
			break;
		}
		case 2: {
			float x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			float x;
			cin >> x;
			bool z = f.find(x);
			if (z == true) {
				cout << "Yes";
			}
			else {
				cout << "NO";
			}
			break;
		}
		case 4: {
			BQ<float> c = f.Map(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			float x = f.Reduce(ReduceCeck, 0);
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {
			BQ<float>* c = f.Where(Wherecheck);
			cout << "\n";
			c->print();
			break;
		}
		case 7: {
			f.print();
			break;
		}

		case 8: {
			cout << "Enter start and end\n";
			size_t s;
			cin >> s;
			size_t e;
			cin >> e;
			while (s >= e) {
				cout << "\nEnter other end\n";
				cin >> e;
			}
			BQ<float>* m = f.SubQfromto(s, e);
			m->print();
			break;
		}
		case 9: {
			break;
		}
		default:
			break;
		}
	}

}
void strtmenp() {
	srand(time(0));
	cout << "\nPrint BQ length\n";
	int x;
	cin >> x;
	cout << "\nPrint BQ\n";
	BQ<string> f;
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int a = rand() % 1000;
			ostringstream ss;
			ss << a;
			string s = ss.str();
			int b = rand() % 1000;
			f.add(s,b);
		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			string a;
			int b;
			cin >> a>>b;
			f.add(a,b);
		}
	}
	f.print();
	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Get Subseq from i to j.\n";
	int us = -1;
	while (us != 9) {
		cout << "\n=======================================\n";
		f.print();
		cout << "\n=======================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			string x;
			cin >> x;

			size_t m;
			cin >> m;
			f.add(x, m);
			break;
		}
		case 2: {
			string x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			string x;
			cin >> x;
			bool z = f.find(x);
			if (z == true) {
				cout << "Yes";
			}
			else {
				cout << "NO";
			}
			break;
		}
		case 4: {
			BQ<string> c = f.Map(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			string x = f.Reduce(ReduceCeck, "");
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {
			BQ<string>* c = f.Where(Wherecheck);
			cout << "\n";
			c->print();
			break;
		}
		case 7: {
			f.print();
			break;
		}

		case 8: {
			cout << "Enter start and end\n";
			size_t s;
			cin >> s;
			size_t e;
			cin >> e;
			while (s >= e) {
				cout << "\nEnter other end\n";
				cin >> e;
			}
			BQ<string>* m = f.SubQfromto(s, e);
			m->print();
			break;
		}
		case 9: {
			break;
		}
		default:
			break;
		}
	}
}
void persmenp() {
	srand(time(0));
	cout << "\nPrint BQ length\n";
	int x;
	cin >> x;
	cout << "\nPrint BQ\n";
	BQ<Person> f;
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int a = rand() % 1000;
			int b = rand() % 1000;
			int c = rand() % 1000;
			ostringstream ss; ostringstream ss1; ostringstream ss2;
			ss << a;
			string fin = ss.str();
			ss1 << b;
			string mn = ss1.str();
			ss2 << c;
			string ln = ss2.str();
			PersonID X;
			X.number = rand() % 100;
			X.series = rand() % 100;
			Person L(X, fin, mn, ln, rand() % 100);
			int x = rand() % 100;
			f.add(L,x);

		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			Person a;
			int x;
			cin >> a>>x;
			f.add(a,x);
		}
	}
	f.print();
	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Get Subseq from i to j.\n";
	int us = -1;
	while (us != 9) {
		cout << "\n=======================================\n";
		f.print();
		cout << "\n=======================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			Person x;
			cin >> x;

			size_t m;
			cin >> m;
			f.add(x, m);
			break;
		}
		case 2: {
			Person x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			Person x;
			cin >> x;
			bool z = f.find(x);
			if (z == true) {
				cout << "Yes";
			}
			else {
				cout << "NO";
			}
			break;
		}
		case 4: {
			BQ<Person> c = f.Map(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {

			PersonID z;
			z.number = 0;
			z.series = 0;
			Person m(z, "", "", "", 0);
			Person x = f.Reduce(ReduceCeck, m);
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {
			BQ<Person>* c = f.Where(Wherecheck);
			cout << "\n";
			c->print();
			break;
		}
		case 7: {
			f.print();
			break;
		}

		case 8: {
			cout << "Enter start and end\n";
			size_t s;
			cin >> s;
			size_t e;
			cin >> e;
			while (s >= e) {
				cout << "\nEnter other end\n";
				cin >> e;
			}
			BQ<Person>* m = f.SubQfromto(s, e);
			m->print();
			break;
		}
		case 9: {
			break;
		}
		default:
			break;
		}
	}
}
void complmenp() {
	srand(time(0));
	cout << "\nPrint BQ length\n";
	int x;
	cin >> x;
	cout << "\nPrint BQ\n";
	BQ<Complex> f;
	cout << "Do yo want random generation?\n1.Yes\n2.No\n";
	int u1;
	cin >> u1;
	if (u1 == 1) {
		for (int i = 0; i < x; i++) {
			int m = rand() % 1000;
			int n = rand() % 1000;
			float a = (m + 0.0) / 100;
			float b = (n + 0.0) / 100;
			Complex g(a, b);
			int z = rand() % 100;
			f.add(g,z);
		}
		cout << "Generated\n";
	}
	else {
		cout << "\nPrint tree\n";
		for (int i = 0; i < x; i++) {
			Complex a;
			int z;
			cin >> a>>z;
			f.add(a,z);
		}
	}
	f.print();
	cout << "\nWaht to do: \n1.Add value.\n2.Remove value.\n3.Find value.\n4.Map.\n5.Reduce.\n6.Where.\n7.Print.\n8.Get Subseq from i to j.\n";
	int us = -1;
	while (us != 9) {
		cout << "\n=======================================\n";
		f.print();
		cout << "\n=======================================\n";
		cin >> us;
		switch (us)
		{
		case 1: {
			Complex x;
			cin >> x;

			size_t m;
			cin >> m;
			f.add(x, m);
			break;
		}
		case 2: {
			Complex x;
			cin >> x;
			f.remove(x);
			break;
		}
		case 3: {
			Complex x;
			cin >> x;
			bool z = f.find(x);
			cout << "\n" << z;
			break;
		}
		case 4: {
			BQ<Complex> c = f.Map(Mapcheck);
			cout << "\n";
			c.print();
			cout << "\n";
			break;
		}
		case 5: {
			Complex y;
			y.imaginary = 0;
			y.real = 0;
			Complex x = f.Reduce(ReduceCeck, y);
			cout << "\n" << x << "\n";
			break;
		}
		case 6: {
			BQ<Complex>* c = f.Where(Wherecheck);
			cout << "\n";
			c->print();
			break;
		}
		case 7: {
			f.print();
			break;
		}

		case 8: {
			cout << "Enter start and end\n";
			size_t s;
			cin >> s;
			size_t e;
			cin >> e;
			while (s >= e) {
				cout << "\nEnter other end\n";
				cin >> e;
			}
			BQ<Complex>* m = f.SubQfromto(s, e);
			m->print();
			break;
		}
		case 9: {
			break;
		}
		default:
			break;
		}
	}
}

void PriorityqueMenu() {
	int usrch = -1;
	while (usrch != 6)
	{

		cout << "Enter type:\n1.Int\n2.Double\n3.String\n4.Person\n5.Complex\n6.Exit\n";
		cin >> usrch;
		cout << "\n";
		switch (usrch) {
		case 1: {
			intmenp();
			break;
		}
		case 2: {
			domenp();
			break;
		}
		case 3: {

			strtmenp();
			break;
		}
		case 4: {
			persmenp();
			break;

		}
		case 5: {
			complmenp();
		}
		default:
			break;
		}
	}
}
void TypeMenu() {
	int usrch = -1;
	while (usrch != 4) {

		cout << "What do you want?\n1.Tree\n2.Set\n3.Priority Qeue\n4.Exit\n";
		cin >> usrch;
		switch (usrch)
		{
		case 1: {
			TreeMenu();
			break;
		}
		case 2: {
			SetMenu();
			break;
		}
		case 3: {
			PriorityqueMenu();
			break;
		}
		case 4: {
			break;
		}


		default:
			break;
		}
	}
}


int Mapcheck(int a) {
	return a * 3;
}
float Mapcheck(float a) {
	return a * 3;
}
string Mapcheck(string a) {
	return a + "fddd";
}
Person Mapcheck(Person a) {
	Person x(a.GetID(), a.GetFirstName() + "new", a.GetMiddleName() + "new", a.GetLastName() + "new", a.GetBirthDate() + 123);
	return x;
}
Complex Mapcheck(Complex a) {
	Complex z = a;
	z = a + z;
	return z;
}
int Mapcheck1(int a) {
	return a * 2;
}
int Mapcheck3(int a) {
	return a * 7;
}
size_t Map(size_t s) {
	return s;
}
int ReduceCeck(int a, int b) {
	return a + b;
}
float ReduceCeck(float a, float b) {

	return a + b;
}
string ReduceCeck(string a, string b) {
	return a + b;
}
Person ReduceCeck(Person a, Person b) {
	return a + b;
}
Complex ReduceCeck(Complex a, Complex b) {
	return a + b;
}
bool Wherecheck(int x) {
	if (x % 2 == 0)
		return 1;
	else {
		return 0;
	}
}
bool Wherecheck(float x) {
	if (x > 10)
		return 1;
	else
		return 0;
}
bool Wherecheck(string x) {
	if (x == "10")
		return 1;
	else
		return 0;
}
bool Wherecheck(Person x) {
	if (x.GetBirthDate() >= 10)
		return 1;
	else
		return 0;
}
bool Wherecheck(Complex x) {
	if (x.imaginary > x.real)
		return 1;
	else
		return 0;
}
string Mch(string c) {
	return c + "ggg";
}
