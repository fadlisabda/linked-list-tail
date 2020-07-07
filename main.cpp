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