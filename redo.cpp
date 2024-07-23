#include<iostream>
#include<string>
using namespace std;
struct Product
{
	string name;
	string juice;
	int price;
	int quantity;
	
	friend istream& operator>>(istream &is, Product &product)
	{
		cout<<"Please give us more information!" <<endl;
		is.ignore();
	
		cout<<"Enter a name: ";
		getline(is, product.name);
		
		cout<<"Enter a juice: ";
		getline(is,product.juice);	
		
		cout<<"Enter a quantity: ";
		is>> product.quantity;

		cout<<"Enter a price: ";
		is>> product.price;
		
		return is;		
	}
	friend ostream& operator<<(ostream &os, Product product)
	{
		cout<<"Name: ";
		os<<product.name << " | ";
		
		cout<<"Hobby: ";
		os<<product.juice<< " | ";
		
		cout<<"Price: ";
		os<<product.price<< " | ";
		
		cout<<"Quantity: ";
		os<<product.quantity<< " . ";
		return os;	
	}
};
void add(Product* &cart, int &size);
int show_menu();
void review(Product* &cart, int &size);
void remove(Product* &cart, int &size);
int main()
{
	int size = 0;
	Product *cart = new Product[size];
	while(true)
	{
		system("cls");
		int choose = show_menu();
		switch(choose)
		{
			case 1:
				review(cart,size);
				break;
			case 2:
				add(cart,size);
				break;
			case 3:
				remove(cart,size);
				break;
			case 0:
				cout<<"THANKS FOR USING OUR SERVICE! HAVE A GOOD DAY!";
				delete [] cart;
			default:
				return 0;	
				cout<<"Your choice was invalid\n";	
		}
		cout<<"WOULD YOU LIKE TO CONTINUE?(1/0)\n";	
		bool ok;
		cin>> ok;
		if (ok == 0)
		{
			printf("Bye Bye!");
			return 0;
		}	
	}	
}
int show_menu()
{
	int choice;
	system("cls");
	cout<<"_____________________________CUPEE VAPE SHOP__________________________________"<< endl;
	cout<<"	1. View your cart" << endl;
	cout<<"	2. Add a new product"<< endl;
	cout<<"	3. Remove a product"<< endl;
	cout<<"	0. Exit"<< endl;
	cout<<"	Enter your choice: "<< endl;	
	cin >> choice;
	return choice;
}
void remove(Product* &cart, int &size)
{

	if(size == 0)
	{
		cout<<"There isn't any product yet! Please add a new product!";
		return;	
	}
	cout<<"Enter a name and juice of the product which needs to be removed: ";
	
	string delete_name;
	cin.ignore();
	getline(cin, delete_name);
	
	string delete_juice;
	getline(cin, delete_juice);
	
	int index = -1;
	for(int i = 0; i < size; i++)
	{
		if(delete_name.compare(cart[i].name) == 0  )
		
			if (delete_juice.compare(cart[i].juice) == 0)
			{
				index = i;
				break;	
			}
	}
	if (index == -1)
	{
		cout<<"We didn't detect your product, please try again!\n";
		return;	
	}
		
	Product *res = new Product[size];
	for(int i = index; i < size-1; i++)
	{
		cart[i] = cart[i+1] ;
	}
	for(int i = 0; i < size; i++)
	{
		res[i] = cart[i];
	}

	delete[] cart;
	cart = res;
	cout <<"DELETE SUCCESSFULLY!\n";
}
	void add(Product* &cart, int &size)
{
	Product new_product;
	cin>> new_product;
	int new_size = size + 1;
	Product *res = new Product[new_size];
	for(int i = 0; i < size; i++)
	{
		res[i] = cart[i];
	}
	res[size] = new_product;
	delete [] cart;
	cart = res;
	size++;
	cout<<"ADD YOUR NEW PRODUCT SUCCESSFULLY!\n";
}
void review(Product* &cart, int &size)
{
	if(size == 0)
		cout<<"YOUR CART IS EMPTY! PLEASE ADD A NEW PRODUCT!\n";
	else
	{
		for(int i = 0; i < size; i++)
			cout << cart[i] << endl;
	}
}