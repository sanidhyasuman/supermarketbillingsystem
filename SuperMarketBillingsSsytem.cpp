#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

        public:
            void menu();
            void administrator();
            void buyer();
            void add();
            void edit();
            void rem();
            void list();
            void receipt();
};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;
    system("CLS");
    cout<<"\t\t\t\t....................................\n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t        Supermarket Main Menu       \n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t....................................\n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t|    1) Administrator       |\n";
    cout<<"\t\t\t\t|                           |\n";
    cout<<"\t\t\t\t|    2) Buyer               |\n";
    cout<<"\t\t\t\t|                           |\n";
    cout<<"\t\t\t\t|    3) Exit                |\n";
    cout<<"\t\t\t\t|                           |\n";
    cout<<"\n\t\t\t Please select:- ";
    cin>>choice;

    switch(choice)
    {
            
        case 1:
        { 
            cout<<"\t\t\t Please login \n";
            cout<<" Enter Email \n";
            cin>>email;
            cout<<" Password    \n";
            cin>> password;
            if(email == "sns@gmail.com" && password == "123")
            {
                administrator();
            }
            else
            {
                cout<<"Invalid email/password";

            }
            break;
        }
        case 2:
        {
            buyer();
        }         

        case 3:
        {
            exit(0);    
        }
        default:
        {
            cout<<"please select from the given option";
        }        
        
    }

    goto m;
}

void shopping::administrator()
{
    while(1)
    {
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu";
    cout<<"\n\t\t\t|______1)Add the product____|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|______2)Modify the product_|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|______3)Delete the product_|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|______4)View Products______|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|______5)Back to main menu__|";
    
    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            list();
            break;
        case 5:
            menu();
            break;
        default:
        cout<<"invalid choice";

    }
}

}


void shopping::buyer()
{
    m:
    int choice;
    
    cout<<"\t\t\t Buyer \n";
    cout<<"\t\t\t________________\n";
    cout<<"                      \n";
    cout<<"\t\t\t1) Buy Product  \n";
    cout<<"                      \n";
    cout<<"\t\t\t2) Go back      \n";
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            receipt();
            break;         
        case 2:
            menu();
            break;
        default:
            cout<<"invalid choice"; 
    }
    goto m;
    
}
void shopping::add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
        cout<< "\n\t\t\t Add new product";
        cout<<"\n\n\t Product code of the product:- ";
        cin>>pcode;
        cout<<"\n\n\t Name of the product:- ";
        cin>>pname;
        cout<<"\n\n\t Price of the product:- ";
        cin>>price;
        cout<<"\n\n\t Discount on product:- ";
        cin>>dis;

    
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();

        cout<< "\n\n\t\t record inserted !";
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t product code:- ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile doesn't exist: ";
    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price:- ";
                cin>>p;
                cout<<"\n\t\t Discount:- ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited ";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");
        
        if(token == 0)
        {
            cout<<"\n\n Record not found sorry!";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout <<"\n\n\t Delete product";
    cout <<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"file doesn't exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted succesfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token == 0)
        {
            cout<<"\n\n Record not found";
        }
        list();
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|___________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|___________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;
    float amount;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float dis = 0;
    float total = 0;

    cout<<"\n\t\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database ";
    }
    else{
        data.close();
        list();
        cout<<"\n______________________________________\n";
        cout<<"\n                                      \n";
        cout<<"\n         Please place the order       \n";
        cout<<"\n                                      \n";
        cout<<"\n______________________________________\n";
        do{
            m:
            cout<<"\nEnter Product code:- ";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity:- ";
            cin>>arrq[c];
            int i;
            for( i=0; i<c; i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code: please try again! ";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product if yes then press y else no";
            cin>>choice;
        }
        while(choice == 'y');
        
        cout<<"\n\n\t\t\t\t_____________________RECEIPT_____________________\n";
        cout<<"\nProduct No.\t Product Name\t Product quantity\tprice\tAmount\tAmount with discount\n";
        for(int i=0; i<c; i++)
        {
            data.open("database.txt",ios::in);
            
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t  "<<pname<<"\t\t "<<arrq[i]<<"\t\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
        
    }
    cout<<"\n\n_____________________________________________";
    cout<<"\n Total Amount : "<<total<<endl;

}

int main()
{
    shopping s1;
    s1.menu();
    return 0; 
}


