#include "tree.h"
int student::operator<(const student&b) const
{
    /*int i=strcmp(name,b.name);

    if(i>0) return -1;
    if(i==0) return 0;
    return 1;*/
    if(value<b.value) return 1;
    if(value==b.value) return 0;
    return -1;
}
int student::init(const char*in,int iv)
{
    value=iv;
    if(in)
    {
        name = new char[strlen(in)+1];
        if(name) strcpy(name,in);
        else return 1;
    }
    return 0;
}

student::student(const char*in,int iv)
{
    init(in,iv);
}

student::student(const student&rhs)
{
    init(rhs.name,rhs.value);
}

student::~student()
{
    if(name) delete [] name;
    name=0;value=0;
}

student& student::operator=(const student&rhs)
{
    this->student::~student();
    init(rhs.name,rhs.value);
    return *this;
}



void student::swaps(student&b)
{
    char*n;int v;
    n=b.name;b.name=name;name=n;
    v=b.value;b.value=value;value=v;
}

int main()
{
   tree my_tree;
   FILE *fp;
   int n1,n2,n3;
   printf("Input n1,n2,n3:\n");
   if(scanf("%d%d%d",&n1,&n2,&n3)!=3)
   {
        printf("Cannot read\n");
        return -1;
   }
   fp=fopen("students.txt","r");
   if(!fp)
    return -2;
   if(!my_tree.read(fp,n1,n2,n3))
    return -1;
   //my_tree.print();
   //my_list.~student_list();
   my_tree.menu();
   return 0;
}
