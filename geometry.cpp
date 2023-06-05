#include <iostream>
#include <cmath>
using namespace std;

class TwoD
{
    public:
        float x,y;
        int choice;
        TwoD()
        {
            x=0;
            y=0;
        }
        virtual void init()
        {
            cout<<"Enter x coordinate of the point"<<endl;
            cin>>x;
            cout<<"Enter y coordinate of the point"<<endl;
            cin>>y;
        }
        virtual void switch_st()
        {
            TwoD obj;
            int a=0;
            obj.init();
            while(a!=-1)
            {
                cout<<"Enter 1: Distance from the origin \n2: Distance from a point \n3: Angle made with the x axis \nX: EXIT\n\n"<<endl;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        cout<<"Distance from the origin ="<<obj.distance()<<"\n\n"<<endl;
                        break;
                    case 3:
                        cout<<"Angle made with the x axis = "<<obj.angle()<<"radians\n\n"<<endl;
                        break;
                    default:
                        a=-1;
                        cout<<"Exiting 2D point"<<endl;
                        break;
                    case 2:
                        TwoD obj2;
                        cout<<"For the second point"<<endl;
                        obj2.init();
                        cout<<"Distance between 2 points ="<<obj.distance_between(obj2)<<"\n\n"<<endl;
                        break;
                    
                }
            }
        }
        virtual float distance()
        {
            return hypot(x,y);
        }
        float distance_between(const TwoD& a)
        {
            return hypot(x-a.x,y-a.y);
        }
        virtual float angle()
        {
            return abs(atan(y/x));
        }
};

class ThreeD: virtual public TwoD
{
    float z;
    public:
        ThreeD()
        {
            x=0;
            y=0;
            z=0;
        }
        void init() override
        {
            cout<<"Enter x coordinate of the point"<<endl;
            cin>>x;
            cout<<"Enter y coordinate of the point"<<endl;
            cin>>y;
            cout<<"Enter z coordinate of the point"<<endl;
            cin>>z;
        }
        void switch_st() override
        {
            ThreeD obj,obj2;
            int a =0;
            TwoD *p,*p2;
            p=&obj;
            p2=&obj2;
            cout<<"For a 3D point"<<endl;
            p->init();
            while(a!=-1)
            {
                cout<<"Enter 1: Distance from origin \n2: Distance from a point \nX: EXIT"<<endl;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        cout<<"Distance from the origin = "<<p->distance()<<"\n\n";
                        break;
                    
                    case 2:
                        cout<<"Enter the coordinates of the second point"<<endl;
                        p2->init();
                        cout<<"Distamce between the points are "<<p->distance_between(obj2)<<"\n\n";
                        break;
                    default:
                        a=-1;
                        cout<<"Exiting 3D point"<<endl;
                        break;

                }

            }
        }
        float distance() override
        {
            return sqrt(x*x+y*y+z*z);
        }
        float distance_between(const ThreeD& a)
        {
            return hypot(hypot(x-a.x,y-a.y),z-a.z);
        }
};


class Complex: virtual public TwoD
{
    public:
        friend ostream& operator << (ostream &out, const Complex &a);
        Complex()
        {
            int x=0;y=0;
        }
        Complex(int a,int b)
        {
            x=a;
            y=b;
        }
        void init() override
        {
            cout<<"Enter real part of complex number"<<endl;
            cin>>x;
            cout<<"Enter imaginary part of the complex number"<<endl;
            cin>>y;
        }
        void switch_st() override
        {
            Complex c,c1,c2;
            int a=0;
            TwoD *p,*p2;
            p = &c;
            p2=&c1;
            cout<<"For a complex number"<<endl;
            p->init();
            while(true)
            {
                cout<<"Enter 1: Add 2 complex numbers \n2:Subtract complex number from another \n3:Multiply 2 complex numbers \n4:Show Polar form \n5:Show complement of complex number \nX: EXIT ";
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        cout<<"For the second complex number"<<endl;
                        p2->init();
                        c2=c+c1;
                        c2.print();
                        cout<<"\n\n";
                        break;
                    case 2:
                        cout<<"For the second complex number"<<endl;
                        p2->init();
                        c2=c-c1;
                        c2.print();
                        cout<<"\n\n";
                        break;
                    case 3:
                        cout<<"For the second complex number"<<endl;
                        p2->init();
                        c2=c*c1;
                        c2.print();
                        cout<<"\n\n";
                        break;
                    case 4:
                        c.print_polar();
                        cout<<"\n\n";
                        break;
                    case 5:
                        c2=!c;
                        c2.print();
                        cout<<"\n\n";
                        break;
                    default:
                        a=-1;
                        cout<<"Exiting complex numbers"<<endl;
                        break;
                }
            if(a==-1)
            {
                break;
            }
        }
        
            
        }
        Complex operator+ (const Complex& a)
        {
            Complex temp;
            temp.x=x+a.x;
            temp.y=y+a.y;
            return temp;
        }
        Complex operator- (const Complex& a)
        {
            Complex temp;
            temp.x=x-a.x;
            temp.y=y-a.y;
            return temp;
        }
        Complex operator* (const Complex& a)
        {
            Complex temp;
            temp.x=this->x*a.x - this->y*a.y;
            temp.y=this->y*a.x + this->x*a.y;
            return temp;
        }
        Complex operator=(const Complex& a)
        {
            x=a.x;
            y=a.y;
            return *this;
        }
        Complex operator!()
        {
            y=-y;
            return *this;
        }
        void print()
        {
            if(y>=0)
                cout<<"The complex number is "<<x<<" + "<<y<<"i"<<endl;
            else{
                cout<<"The complex number is "<<x<<" - "<<-y<<"i"<<endl;
            }
        }
        void print(const Complex& a)
        {
            cout<<"The complex number is "<< a;
        }
        void print_polar()
        {
            cout<<distance()<<"e^i("<<angle()<<")"<<endl;
        }
};

ostream& operator<< ( ostream &out,const Complex& a)
{
    out << a.x;
    if(a.y>=0)
        out << " + " << a.y <<"i"<< endl;
    else{
        out << " - "<< -a.y <<"i"<<endl;
    }
    return out;
    
}
int main()
{
    TwoD *pt=nullptr,twoobj;
    ThreeD tobj;
    Complex c1,c2;
    int x1=0;
    cout<<"Choose among the following"<<endl;
    cout<<"1. 2Dimensional Point"<<endl;
    cout<<"2. 3Dimensional Point"<<endl;
    cout<<"3. Complex number\n\n"<<endl;
    cin>>x1;
        switch(x1)
        {
            case 1: 
                pt = &twoobj;
                break;
            case 2:
                pt = &tobj;
                break;
            case 3: 
                pt = &c1;
                break;
            default:
                cout<<"Enter a number from 1 to 4"<<endl;
                break;
        }
        pt->switch_st();
        delete pt;
    }