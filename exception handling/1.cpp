#include <iostream>
using namespace std;

int main(){
  int x = -1;

  cout << "Before try\n";
  try{
    cout << "Inside try\n";
    if(x < 0){
      throw x;
      cout << "After throw (Never executed)\n";
    }
  }
  catch(int x){
    cout <<"Exception caught \n";
  }
  
  cout << "After catch (will be executed)\n";
}