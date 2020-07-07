//in Indonesian and in Indonesian
//linked list tail
#include <iostream>
using namespace std;

class node//class untuk membuat node
{
    public:
      int value;//untuk nilai dalam node 
      node *next;//objek untuk menuju node berikutnya

   node(int  va, node *n)//mengisi nilai dan pointer
   {
   	value=va;
      next=n;
   }

   node(int a)//mengisi nilai
   {
   	value=a;
   }
};


class dlistx
{
      public:
      void inserthead(int val);//membuat nilai node pada bagian head/depan 
      void removehead();//menghapus node pada bagian head/depan   
      void insertlast(int val);//membuat node di tail/belakang
      void removelast();//menghapus node pada bagian tail/belakang
      void print();//menampilkan semua node
      int isempty();//mengembalikan 1 jika node kosong mengembalikan 0 jika node berisi

      dlistx()//mengisi head dan tail null
      {
         head=NULL;
         tail=NULL;
      }

      private:
         node *head;//membuat objek head dan tail private 
         node *tail;
};

static int list=0;//menghitung jumlah nilai node

int dlistx::isempty()//mengembalikan nilai 1 jika node kosong dan 0 jika node berisi
{
	if(this->head==NULL || this->tail==NULL)
   	return 1;
   else
   	return 0;
}

void dlistx::inserthead(int value)//membuat nilai node di bagian head
{
   if(isempty()==1)//jika node masih kosong
   {
      node *temp;
      temp=new node(value);//membuat objek temp
      this->head=temp;//menjadikan objek temp head
      this->tail=temp;//menjadikan objek temp tail
      this->tail->next=NULL;//menjadikan node tail berikutnya null
      cout<<"Nilai "<<value<<" masuk ke head"<<endl;//memasukkan nilai ke head
      cout<<endl;
   }else//jika node sudah berisi
   {
      node *temp;//membuat objek temp
      temp=new node(value,this->head);//temp menyimpan nilai dan objek head
      this->head=temp;//temp dijadikan head
      cout<<"Nilai "<<value<<" masuk ke head"<<endl;//nilai masuk ke head
      cout<<endl;
   }
   list++;//jumlah data bertambah 
}


void dlistx::insertlast(int value)//membuat node pada bagian tail
{
   if(isempty()==1)//jika node masih kosong
   {
      node *temp;
      temp=new node(value);//mengisi objek temp value/nilai
      this->head=temp;//menjadikan temp head
      this->tail=temp;//menjadikan temp tail
      this->tail->next=NULL;//node tail berikutnya null
      cout<<"Nilai "<<value<<" masuk ke tail"<<endl;//nilai masuk ke tail
      cout<<endl;
   }else//jika node berisi
   {
      this->tail->next=new node(value);//node baru berikutnya diberi nilai
      this->tail=this->tail->next;//node baru diletak di depan tail
      this->tail->next=NULL;//node tail berikutnya null
      cout<<"Nilai "<<value<<" masuk ke tail"<<endl;//nilai dimasukkan ke tail
      cout<<endl;
    }
list++;//jumlah data bertambah
}


void dlistx::removehead()//menghapus node pada bagian head/depan
{
   if(isempty()==1)//jika node kosong
        cout<<"Maaf, linked list kosong"<<endl;
   else
        this->head=this->head->next;//head di ganti ke node didepannya
   list--;//jumlah data berkurang
}


void dlistx::removelast()//menghapus node pada bagian tail/belakang
{
   if(isempty()==1)//jika node masih kosong
   {
        cout<<"Maaf, linked list kosong"<<endl;
   }else//jika node berisi
   {
        int x=tail->value;//mengisi nilai node tail ke variabel x
        if(list==1)//jika jumlah node masih 1
        {
     	    cout<<"nilai "<<x<<" Telah dihapus"<<endl;//nilai dihapus
     	    tail=NULL;//objek tail 0
      	    head=NULL;//objek head 0
           list--;//jumlah data berkurang
        }else//jika data lebih dari 1
        {
      	    node *temp;//membuat objek temp
      	    temp=this->head;//menjadikan objek temp head
      	    for(int i=1;i<list-1;i++)//berulang sampai tail
      	    {
      	       temp=temp->next;//dari node head menuju ke node berikutnya sampai node tail
      	    }
      temp->next=temp->next->next;//hapus nilai pada bagian tail
	    this->tail=temp;//nilai tail sebelumnya menjadi yang baru
      	    cout<<"nilai "<<x<<" Telah dihapus"<<endl;
      	    list--;//jumlah data berkurang
       }
    }
}


void dlistx::print()//menampilkan seluruh node
{
   node *newnode=head;//menjadikan objek newnode head
   while(newnode!=NULL)//berulang sampai ditemukan null
   {
      cout<<"Isi list :"<<newnode->value<<endl;//menampilkan nilai node
      newnode=newnode->next;//menuju ke node berikutnya dari node head 
   }
}

int main()
{
   int n;
   dlistx *st;//objek untuk memanggil fungsi
   st=new dlistx();

   char pilih;
   cout<<"Operasi linkedlist "<<endl;
   cout<<"1. insert"<<endl;
   cout<<"2. remove"<<endl;
   cout<<"3. insert last"<<endl;
   cout<<"4. remove last"<<endl;
   cout<<"5. Exit"<<endl;

   do{
   	 cout<<endl;
   	 cout<<"Pilihan :";
        cin>>pilih;

            switch(pilih)
            {
    	           case '1':
                  	cout<<"masukkan data :";
                  	cin>>n;
                  	st->inserthead(n);
                  	st->print();
          	break;

                  case '2':
         	char n;
         	cout<<"Anda yakin untuk menghapus ? y/n ";
                  	cin>>n;
                  	if(n=='y')
                  	{
                  	    st->removehead();
                  	    st->print();
                    }else
                    {
                  	   cout<<"Thanks";
                    }
                  	break;

                  case '3':
         	int pos;
                  	cout<<"masukkan data :";
                  	cin>>pos;
                  	st->insertlast(pos);
                  	st->print();
          	break;

          case '4':
         	char k;
         	cout<<"Anda yakin untuk menghapus ? y/n ";
                  	cin>>k;
                  	if(k=='y')
                  	{
                  	    st->removelast();
                        st->print();
                     }else
                     {
                  	    cout<<"Thanks";
                     }
                       break;

           case '5':
         	cout<<"terima kasih :";
                    break;
                 default:
         	cout<<"salah pilih";
               	break;
      	        }
   	} while(pilih!='5');
}

//in English
// #include <iostream>
// using namespace std;

// class node // class to create a node
// {
//     public:
//       int value; // for values ​​in the node
//       node * next; // object to go to the next node

//    node (int va, node * n) // fill in the value and pointer
//    {
//    value = va;
//       next = n;
//    }

//    node (int a) // fill in the value
//    {
//    value = a;
//    }
// };

// dlistx class
// {
//       public:
//       void inserthead (int val); // creates a node value at the head / front
//       void removehead (); // delete the node on the head / front
//       void insertlast (int val); // creates a node in the tail / back
//       void removelast (); // removes the node on the tail / back
//       void print (); // displays all nodes
//       int isempty (); // returns 1 if an empty node returns 0 if the node contains

//       dlistx () // fills null head and tail
//       {
//          head = NULL;
//          tail = NULL;
//       }

//       private:
//          node * head; // creates a private head and tail object
//          node * tail;
// };

// static int list = 0; // counts the number of node values

// int dlistx :: isempty () // returns the value 1 if the node is empty and 0 if the node contains
// {
// if (this-> head == NULL || this-> tail == NULL)
//    return 1;
//    else
//    return 0;
// }

// void dlistx :: inserthead (int value) // creates a node value in the head section
// {
//    if (isempty () == 1) // if the node is still empty
//    {
//       node * temp;
//       temp = new node (value); // creates a temp object
//       this-> head = temp; // makes the object temp head
//       this-> tail = temp; // makes the temp tail object
//       this-> tail-> next = NULL; // makes the next tail node null
//       cout << "Value" << value << "goes to head" << endl; // enters value to head
//       cout << endl;
//    } else // if the node already contains
//    {
//       node * temp; // creates a temp object
//       temp = new node (value, this-> head); // temp stores the value and head object
//       this-> head = temp; // temp is made head
//       cout << "value" << value << "goes to head" << endl; // value goes to head
//       cout << endl;
//    }
//    list ++; // the amount of data increases
// }

// void dlistx :: insertlast (int value) // creates a node in the tail
// {
//    if (isempty () == 1) // if the node is still empty
//    {
//       node * temp;
//       temp = new node (value); // populates the temp value / value object
//       this-> head = temp; // makes temp head
//       this-> tail = temp; // makes temp tail
//       this-> tail-> next = NULL; // the next tail node is null
//       cout << "value" << value << "enter tail" << endl; // value enter tail
//       cout << endl;
//    } else // if the node contains
//    {
//       this-> tail-> next = new node (value); // the next new node is given a value
//       this-> tail = this-> tail-> next; // new node is placed in front of the tail
//       this-> tail-> next = NULL; // the next tail node is null
//       cout << "value" << value << "enter tail" << endl; // value entered into tail
//       cout << endl;
//     }
// list ++; // the amount of data increases
// }


// void dlistx :: removehead () // delete the node on the head / front
// {
//    if (isempty () == 1) // if the node is empty
//         cout << "Sorry, the linked list is empty" << endl;
//    else
//         this-> head = this-> head-> next; // head is replaced by the node in front of it
//    list --; // amount of data reduced
// }


// void dlistx :: removelast () // removes the node on the tail / back
// {
//    if (isempty () == 1) // if the node is still empty
//    {
//         cout << "Sorry, the linked list is empty" << endl;
//    } else // if the node contains
//    {
//         int x = tail-> value; // populates the value of the tail node to variable x
//         if (list == 1) // if the number of nodes is still 1
//         {
//      cout << "value" << x << "Has been deleted" << endl; // value has been deleted
//      tail = NULL; // tail object 0
//       head = NULL; // object head 0
//            list --; // amount of data reduced
//         } else // if the data is more than 1
//         {
//       node * temp; // creates a temp object
//       temp = this-> head; // makes the object temp head
//       for (int i = 1; i <list-1; i ++) // repeats until the tail
//       {
//       temp = temp-> next; // from the head node to the next node until the tail node
//       }
//       temp-> next = temp-> next-> next; // delete the value in the tail
// this-> tail = temp; // previous tail value becomes a new one
//       cout << "value" << x << "Has been deleted" << endl;
//       list --; // amount of data reduced
//        }
//     }
// }

// void dlistx :: print () // displays all nodes
// {
//    node * newnode = head; // makes the newnode head object
//    while (newnode! = NULL) // repeats until it is found null
//    {
//       cout << "Fill list:" <<newnode-> value << endl; // displays the node value
//       newnode = newnode-> next; // goes to the next node from the head node
//    }
// }

// int main ()
// {
//    int n;
//    dlistx * st; // object to call the function
//    st = new dlistx ();

//    char choose;
//    cout << "Linkedlist operation" << endl;
//    cout << "1. insert" << endl;
//    cout << "2. remove" << endl;
//    cout << "3. insert last" << endl;
//    cout << "4. remove last" << endl;
//    cout << "5. Exit" << endl;
   
//    do {
//    cout << endl;
//    cout << "Options:";
//         cin >> select;

//             switch (select)
//             {
//     case '1':
//                   cout << "enter data:";
//                   cin >> n;
//                   st-> inserthead (n);
//                   st-> print ();
//           break;

//                   case '2':
//          char n;
//          cout << "Are you sure you want to delete? y / n";
//                   cin >> n;
//                   if (n == 'y')
//                   {
//                   st-> removehead ();
//                   st-> print ();
//                     } else
//                     {
//                   cout << "Thanks";
//                     }
//                   break;

//                   case '3':
//          int post;
//                   cout << "enter data:";
//                   cin >> post;
//                   st-> insertlast (pos);
//                   st-> print ();
//           break;

//           case '4':
//          char k;
//          cout << "Are you sure you want to delete? y / n";
//                   cin >> k;
//                   if (k == 'y')
//                   {
//                   st-> removelast ();
//                         st-> print ();
//                      } else
//                      {
//                   cout << "Thanks";
//                      }
//                        break;

//            case '5':
//          cout << "thank you:";
//                     break;
//                  default:
//          cout << "wrong choice";
//                break;
//       }
//    } while (select! = '5');
// }
