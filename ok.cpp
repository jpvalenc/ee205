#include <iostream>
using namespace std;
class CDummy
{
    public:
int var1;
    int isitme (CDummy& param);
};
int CDummy::isitme (CDummy& param)
{
    if (&param == this)
        return true;
    else
        return false;
}
int main ()
{
    CDummy a,c;
    CDummy *b = &a;

a.var1 = 1;
b->var1 = 2;
c.var1 = 2;

    if (b->isitme(a)) 
    {
        cout << "Start Action 1 \n";

  if(c.var1==a.var1){
    cout << "Repeat Action 1 \n";
  }else{
      cout << "End Action 1 \n";
  }
    }
    else
    {
        cout<<"Start Action 2";

  if(c.var1==a.var1){
    cout << "Continue Action 2 \n";
  }else{
      cout << "End Action 2 \n";
  }
    }
    return 0;
}

