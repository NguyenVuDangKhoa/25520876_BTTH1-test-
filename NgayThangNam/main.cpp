#include <iostream>

using namespace std;
struct PhanSo
{
    int x;
    int y;
};
void Nhap(PhanSo &a)
{
    cin>>a.x;
    cin>>a.y;
    while(a.y==0)
    {
        cin>>a.x;
        cin>>a.y;
    }
}
int UCLN(int a, int b)
{
    a=abs(a);
    b=abs(b);
    if (b==0 )
        return a;
    return UCLN(b,a%b);

}
void in(PhanSo a)
{
    cout<<a.x;
    cout<<"/";
    cout<<a.y;
    cout<<" ";
}
void rutgon(PhanSo& a)
{
    int kq;
    if (a.x<0 &&a.y<0)
    {
        a.x=abs(a.x);
        a.y=abs(a.y);
        kq=UCLN(a.x,a.y);
        a.x=a.x/kq;
        a.y=a.y/kq;
    }

    else if(a.x<0)
    {
        a.x=abs(a.x);
        kq=UCLN(a.x,a.y);
        a.x=-a.x/kq;
        a.y=a.y/kq;

    }
    else if(a.y<0)
    {
        a.y=abs(a.y);
        kq=UCLN(a.x,a.y);
        a.x=-a.x/kq;
        a.y=a.y/kq;

    }
    else
    {
        kq=UCLN(a.x,a.y);
        a.x=a.x/kq;
        a.y=a.y/kq;
    }

}
PhanSo Cong(PhanSo a, PhanSo b)
{
    PhanSo kq;
    kq.y=a.y*b.y;
    kq.x=(a.x*b.y)+(b.x*a.y);
    rutgon(kq);
    return kq;
}
PhanSo Tru(PhanSo a, PhanSo b)
{
    PhanSo kq;
    kq.y=a.y*b.y;
    kq.x=(a.x*b.y)-(b.x*a.y);
    rutgon(kq);

    return kq;
}
PhanSo Nhan(PhanSo a, PhanSo b)
{
    PhanSo kq;
    kq.y=a.y*b.y;
    kq.x=a.x*b.x;
    rutgon(kq);
    return kq;

}
PhanSo Chia (PhanSo a, PhanSo b)
{
    PhanSo kq;
    kq.y=a.y*b.x;
    kq.x=a.x*b.y;
    rutgon(kq);
    return kq;

}
PhanSo Max( PhanSo a,PhanSo b)
{
    PhanSo kq=Tru(a,b);
    if(kq.x<0)
        return b;
    else if(kq.x==0)
        cout<<"bằng nhau"<<endl;
    else
        return a;


}
int main()
{
    PhanSo a,b;
    Nhap(a);
    Nhap(b);

    in(Cong(a,b));
    in(Tru(a,b));
    in(Nhan(a,b));
    in(Chia(a,b));
    in(Max(a,b));
    return 0;
}
