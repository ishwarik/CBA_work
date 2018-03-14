#include<iostream>
using namespace std;
int speed=90;
int head=1;
int tail=1;
int beam=0;
int low=55;
class vehicle
{

  public:
      void breaking(int i)
    {
        if(i==2)
        {
            if(speed<120 && speed>0)
              speed=speed-5;
               speed=speed;
               cout<<"speed="<<speed<<endl;
        }
        else if(i==4)
        {
            if(speed<180 && speed>0)
            speed=speed-10;
            speed=speed;
             cout<<"speed="<<speed<<endl;
        }
    }
      void acceleration(int j)
    {
        if(j==2)
        {
             if(speed<120 && speed>0)
              speed=speed+5;
               speed=speed;
                cout<<"speed="<<speed<<endl;
        }

        else if(j==4)
        {
            if(speed<180 && speed>0)
              speed=speed+10;
              speed=speed;
               cout<<"speed="<<speed<<endl;
        }
    }
    void lighting(int k,int status,int low)
    {
         if(k==2)
        {
             if(status==0)
             {
              head=1;
              tail=1;
             }
              head=0;
              tail=0;
               cout<<"tail light="<<tail<<" head light="<<head<<endl;
        }

        else if(k==4)
        {

            if(status==0)
             {
              head=1;
              tail=1;
               beam=low;
             }
              head=0;
              tail=0;
              beam=low;
                cout<<"tail light="<<tail<<" head light="<<head<<"beam="<<beam<<endl;

        }
    }


};
int main()
{
    int x,y,z=1;
    vehicle v;
    while(z==1)
    {
    cout<<"enter 2 wheelers or 4 wheelers"<<endl;
    cin>>x;
    cout<<"enter"<<endl<<" 1)breaking "<<endl<<"2)acceleration" <<endl<<"3) lighting"<<endl;
    cin>>y;
    if(y==1)
    v.breaking(x);
    if(y==2)
    v.acceleration(x);
    if(y==3)
    v.lighting(x,0,55);
    cout<<"enter 1 to continue 0 to end"<<endl;
    cin>>z;
    }
    return 0;
}
