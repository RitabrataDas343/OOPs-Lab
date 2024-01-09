#include<iostream>
using namespace std;
#include<conio.h>
template<class T>
class Matrix
{
    T **a;
    int r,c,t;
    static Matrix<T> Mtemp;
    public:
    Matrix<T>();
    Matrix<T>(int R,int C);
    Matrix<T>(const Matrix<T> &M);
    bool checkEqualOrder(const Matrix<T> &M);
    Matrix<T>& Add(const Matrix<T> &M);
    Matrix<T>& Subtract(const Matrix<T> &M);
    bool checkMulOrder(const Matrix<T> &M);
    Matrix<T> Multiply(const Matrix<T> &M);
    Matrix<T>& Divide(float k);
    void Copy(const Matrix<T> &M);
    bool Compare(const Matrix<T> &M);
    Matrix<T>& Invert();
    Matrix<T> operator!();
    T* operator[](int x);
    T operator[](long x);
    bool operator==(const Matrix<T> &M);
    bool operator!=(const Matrix<T> &M);
    void operator=(const Matrix<T> &M);
    Matrix<T>& operator+(Matrix<T> &M2);
    Matrix<T>& operator-(Matrix<T> &M2);
    Matrix<T>& operator*(Matrix<T> &M2);
    Matrix<T>& operator/(float k);
    template<class U>
    friend ostream& operator<<(ostream &x,const Matrix<U>&M);
    template<class U>
    friend istream& operator>>(istream &x,Matrix<U>&M);
    
};
template<class T>
Matrix<T>::Matrix()
{
    r=0;
    c=0;
    t=-1;
    a=new T*[r];
}
template<class T>
Matrix<T>::Matrix(int R,int C)
{
    r=R;
    c=C;
    t=-1;
    a=new T*[r];
    for(int i=0;i<r;i++)
    {
        a[i]=new T[c];
    }
}
template<class T>
Matrix<T>::Matrix(const Matrix<T> &M)
{
    r=M.r;
    c=M.c;
    t=-1;
    a=new T*[r];
    for(int i=0;i<r;i++)
    {
        a[i]=new T[c];
        for(int j=0;j<c;j++)
        {
            a[i][j]=M.a[i][j];
        }
    }
}
template<class T>
bool Matrix<T>::checkEqualOrder(const Matrix<T> &M)
{
    if(M.c==c && M.r==r)
    return true;
    return false;
}
template<class T>
Matrix<T>& Matrix<T>::Add(const Matrix<T> &M)
{
    if(checkEqualOrder(M))
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                a[i][j]+=M.a[i][j];
            }
        }
    }
    return *this;
}
template<class T>
Matrix<T>& Matrix<T>::Subtract(const Matrix<T> &M)
{
    if(checkEqualOrder(M))
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                a[i][j]-=M.a[i][j];
            }
        }
    }
    return *this;
}
template<class T>bool 
Matrix<T>::checkMulOrder(const Matrix<T> &M)
{
    return c==M.r;
}
template<class T>
Matrix<T> Matrix<T>::Multiply(const Matrix &M)
{
    if(checkMulOrder(M))
    {
        Matrix M2(r,M.c);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<M.c;j++)
            {
                M2.a[i][j]=0;
                for(int k=0;k<c;k++)
                {
                    M2.a[i][j]+=a[i][k]*M.a[k][j];
                }
            }
        }
        return M2;
    }
    return *this;
}
template<class T>
Matrix<T>& Matrix<T>::Divide(float k)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            a[i][j]/=k;
        }
    }
    return *this;
}
template<class T>void 
Matrix<T>::Copy(const Matrix<T> &M)
{
    delete[] a;
    a=new T*[M.r];
    r=M.r;
    c=M.c;
    for(int i=0;i<r;i++)
    {
        a[i]=new T[c];
        for(int j=0;j<c;j++)
        {
            a[i][j]=M.a[i][j];
        }
    }
    
}
template<class T>
bool Matrix<T>::Compare(const Matrix<T> &M)
{
    if(r==M.r && c==M.c)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(a[i][j]!=M.a[i][j])
                return false;
            }
        }
        return true;
    }
    else 
    return false;
}
template<class T>
Matrix<T>& Matrix<T>::Invert()
{
    for(int i=0;i<r;i++)
    {
        for(int j=i;j<c;j++)
        {
            T t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
    }
    return *this;
}
template<class T>
Matrix<T> Matrix<T>::operator!()
{
    Invert();
    return *this;
}
template<class T>
T* Matrix<T>::operator[](int x)
{
    int e=0;
    cout<<"Row func:"<<endl;
    try
    {
        if(x>=r)
        {
            t=-1;
            throw e;
            return NULL;
        }
        t=x;
        return a[x];
    }
    catch(int e)
    {
        cout<<"Out of Bounds access!"<<endl;
    }
}
template<class T>
T Matrix<T>::operator[](long x)
{
    int e=0;
    cout<<"Col func:"<<endl;
    try
    {
        if(x>=c || t==-1)
        {
            throw e;
        }
        return a[t][x];
    }
    catch(int e)
    {
        cout<<"Out of Bounds access!"<<endl;
    }
    
}
template<class T>
bool Matrix<T>::operator==(const Matrix<T> &M)
{
    return Compare(M);
}
template<class T>
bool Matrix<T>::operator!=(const Matrix<T> &M)
{
    return !Compare(M);
}
template<class T>
void Matrix<T>::operator=(const Matrix<T> &M)
{
    Copy(M);
}
template<class T>
Matrix<T>& Matrix<T>::operator+(Matrix<T> &M2)
{
    Mtemp=(*this);
    Mtemp.Add(M2);
    return Mtemp;
}
template<class T>
Matrix<T>& Matrix<T>::operator-(Matrix<T> &M2)
{
    Mtemp=(*this);
    Mtemp.Subtract(M2);
    return Mtemp;
}
template<class T>
Matrix<T>& Matrix<T>::operator*(Matrix<T> &M2)
{
    Mtemp=(*this);
    Mtemp=Mtemp.Multiply(M2);
    return Mtemp;
}
template<class T>
Matrix<T>& Matrix<T>::operator/(float k)
{
    Mtemp=(*this);
    Mtemp.Divide(k);
    return Mtemp;
}
template<class T>
ostream& operator<<(ostream &x,const Matrix<T> &M)
{
    for(int i=0;i<M.r;i++)
    {
        for(int j=0;j<M.c;j++)
        {
            x<<M.a[i][j]<<" ";
        }
        x<<endl;
    }
    return x;
}
template <class T>
istream& operator>>(istream &x,Matrix<T> &M)
{
    for(int i=0;i<M.r;i++)
    {
        for(int j=0;j<M.c;j++)
        {
            x>>M.a[i][j];
        }
    }
    return x;
}
template<class T>
Matrix<T> Matrix<T>::Mtemp(1,1);
int main()
{
    while(1)
    {
        system("cls");
        cout<<"Press 1 to perform Addition on two Matrices:"<<endl;
        cout<<"Press 2 to perform Subtraction on two Matrices:"<<endl;
        cout<<"Press 3 to perform Multiplication on two Matrices:"<<endl;
        cout<<"Press 4 to Divide a Matrix by a scalar:"<<endl;
        cout<<"Press 5 to Invert a Matrix:"<<endl;
        cout<<"Press 6 to Compare two Matrices:"<<endl;
        cout<<"Press 7 to Copy a Matrix:"<<endl;
        cout<<"Press 8 to use Subscript operation on a Matrix:"<<endl;
        cout<<"Press any other key to exit:"<<endl;
        int c;
        cin>>c;
        if(c==1)
        {
            int r1,r2,c1,c2;
            cout<<"Enter order of first matrix:";
            cin>>r1>>c1;
            cout<<"Enter order of second matrix:";
            cin>>r2>>c2;
            Matrix<float> M1(r1,c1),M2(r2,c2);
            cout<<"Enter first Matrix:\n";
            cin>>M1;
            cout<<"Enter second Matrix:\n";
            cin>>M2;
            cout<<"Addition result:\n"<<M1+M2<<endl;
        }
        else if(c==2)
        {
            int r1,r2,c1,c2;
            cout<<"Enter order of first matrix:";
            cin>>r1>>c1;
            cout<<"Enter order of second matrix:";
            cin>>r2>>c2;
            Matrix<float> M1(r1,c1),M2(r2,c2);
            cout<<"Enter first Matrix:\n";
            cin>>M1;
            cout<<"Enter second Matrix:\n";
            cin>>M2;
            cout<<"Subtraction result:\n"<<M1-M2<<endl;
        }
        else if(c==3)
        {
            int r1,r2,c1,c2;
            cout<<"Enter order of first matrix:";
            cin>>r1>>c1;
            cout<<"Enter order of second matrix:";
            cin>>r2>>c2;
            Matrix<float> M1(r1,c1),M2(r2,c2);
            cout<<"Enter first Matrix:\n";
            cin>>M1;
            cout<<"Enter second Matrix:\n";
            cin>>M2;
            cout<<"Multiplication result:\n"<<M1*M2<<endl;
        }
        else if(c==4)
        {
            int r,c;
            cout<<"Enter order of first matrix:";
            cin>>r>>c;
            Matrix<float> M(r,c);
            cout<<"Enter a Matrix:\n";
            cin>>M;
            int k;
            cout<<"Enter scalar value: "<<endl;
            cin>>k;
            cout<<"Division Result:\n";
            cout<<M/k<<endl;;
            
        }
        else if(c==5)
        {
            int r1,c1;
            cout<<"Enter order of first matrix:";
            cin>>r1>>c1;
            Matrix<float> M1(r1,c1);
            cout<<"Enter a Matrix:\n";
            cin>>M1;
            cout<<"Inverted Form :\n"<<(!M1)<<endl;
        }
        else if(c==6)
        {
            int r1,r2,c1,c2;
            cout<<"Enter order of first matrix:";
            cin>>r1>>c1;
            cout<<"Enter order of second matrix:";
            cin>>r2>>c2;
            Matrix<float> M1(r1,c1),M2(r2,c2);
            cout<<"Enter first Matrix:\n";
            cin>>M1;
            cout<<"Enter second Matrix:\n";
            cin>>M2;
            if(M1==M2)
            {
                cout<<"The Matrices are equal!"<<endl;
            }
            else
            {                
                cout<<"The Matrices are not equal!"<<endl;
            }
        }
        else if(c==7)
        {
            int r1,c1;
            cout<<"Enter order of first matrix:";
            cin>>r1>>c1;
            Matrix<float> M1(r1,c1),M2(r1,c1);
            cout<<"Enter Matrix:\n";
            cin>>M1;
            cout<<"Copying M1 to M2:\n";
            M2=M1;
            cout<<"M2: \n"<<M2<<endl;;
        }
        else if(c==8)
        {
            int r1,c1;
            cout<<"Enter order of first matrix:";
            cin>>r1>>c1;
            Matrix<float> M1(r1,c1);
            cout<<"Enter Matrix:\n";
            cin>>M1;
            cout<<"Enter subscript as row followed by column :\n";
            int x,y;
            cin>>x>>y;
            cout<<"Output: "<<(M1[x])[y]<<endl;;
        }
        else
        break;
        getch();
    }
    return 0;
}