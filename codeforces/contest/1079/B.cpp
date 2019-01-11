#include<bits/stdc++.h>

using namespace std;

int main()  {
  char str[105];
  cin>>str;
  int len = strlen(str);
  if(len <= 20)  {
    cout<<"1 "<<len<<endl;
    cout<<str;
  }
  else  if(len>20 && len <=40)  {
    int line1 = len/2;
    if(line1 * 2 == len)  {
      cout<<"2 "<<line1<<endl;
      int i;
      for(i=0;i<line1;i++) cout<<str[i];
      cout<<endl;
      for(;i<len;i++) cout<<str[i];
    }
    else  {
      cout<<"2 "<<line1+1<<endl;
      int i=0;
      cout<<"*";
      for(;i<line1;i++) cout<<str[i];
      cout<<endl;
      for(;i<len;i++) cout<<str[i];
    }
  }
  else if(len>40 && len<=60)  {
    int line1 = len/3;
    int rem = len - line1 * 3;
    if(rem == 0)  {
      cout<<"3 "<<line1<<endl;
      int i = 0;
      for(;i<line1;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*2;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*3;i++) cout<<str[i];
    }
    else if(rem == 1) {
      cout<<"3 "<<line1 + 1<<endl;
      int i = 0;
      cout<<"*";
      for(;i<line1;i++) cout<<str[i];
      cout<<endl<<"*";
      for(;i<line1*2;i++) cout<<str[i];
      cout<<endl;
      for(;i<len;i++) cout<<str[i];
    }
    else if(rem == 2) {
      cout<<"3 "<<line1 + 1<<endl;
      int i = 0;
      cout<<"*";
      for(;i<line1;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*2+1;i++) cout<<str[i];
      cout<<endl;
      for(;i<len;i++) cout<<str[i];
    }
  }
  else if(len>60 && len<=80)  {
    int line1 = len/4;
    int rem = len - line1*4;
    if(rem == 0)  {
      cout<<"4 "<<line1<<endl;
      int i=0;
      for(;i<line1;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*2;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*3;i++) cout<<str[i];
      cout<<endl;
      for(;i<len;i++) cout<<str[i];
    }
    else if(rem == 1) {
      cout<<"4 "<<line1+1<<endl;
      int i=0;
      cout<<"*";
      for(;i<line1;i++) cout<<str[i];
      cout<<endl<<"*";
      for(;i<line1*2;i++) cout<<str[i];
      cout<<endl<<"*";
      for(;i<line1*3;i++) cout<<str[i];
      cout<<endl;
      for(;i<len;i++) cout<<str[i];
    }
    else if(rem == 2) {
      cout<<"4 "<<line1+1<<endl;
      int i=0;
      cout<<"*";
      for(;i<line1;i++) cout<<str[i];
      cout<<endl<<"*";
      for(;i<line1*2;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*3+1;i++) cout<<str[i];
      cout<<endl;
      for(;i<len;i++) cout<<str[i];
    }
    else if(rem == 3) {
      cout<<"4 "<<line1+1<<endl;
      int i=0;
      cout<<"*";
      for(;i<line1;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*2+1;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*3+2;i++) cout<<str[i];
      cout<<endl;
      for(;i<len;i++) cout<<str[i];
    }
  }
  else if(len>80 && len<=100) {
    int line1 = len/5;
    int rem = len - line1*5;
    if(rem == 0)  {
      cout<<"5 "<<line1<<endl;
      int i=0;
      for(;i<line1;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*2;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*3;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*4;i++) cout<<str[i];
      cout<<endl;
      for(;i<len;i++) cout<<str[i];
    }
    else if(rem == 1) {
      cout<<"5 "<<line1+1<<endl;
      int i=0;
      cout<<"*";
      for(;i<line1;i++) cout<<str[i];
      cout<<endl<<"*";
      for(;i<line1*2;i++) cout<<str[i];
      cout<<endl<<"*";
      for(;i<line1*3;i++) cout<<str[i];
      cout<<endl<<"*";
      for(;i<line1*4;i++) cout<<str[i];
      cout<<endl;
      for(;i<len;i++) cout<<str[i];
    }
    else if(rem == 2) {
      cout<<"5 "<<line1+1<<endl;
      int i=0;
      cout<<"*";
      for(;i<line1;i++) cout<<str[i];
      cout<<endl<<"*";
      for(;i<line1*2;i++) cout<<str[i];
      cout<<endl<<"*";
      for(;i<line1*3;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*4+1;i++) cout<<str[i];
      cout<<endl;
      for(;i<len;i++) cout<<str[i];
    }
    else if(rem == 3) {
      cout<<"5 "<<line1+1<<endl;
      int i=0;
      cout<<"*";
      for(;i<line1;i++) cout<<str[i];
      cout<<endl<<"*";
      for(;i<line1*2;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*3+1;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*4+2;i++) cout<<str[i];
      cout<<endl;
      for(;i<len;i++) cout<<str[i];
    }
    else if(rem == 4) {
      cout<<"5 "<<line1+1<<endl;
      int i=0;
      cout<<"*";
      for(;i<line1;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*2+1;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*3+2;i++) cout<<str[i];
      cout<<endl;
      for(;i<line1*4+3;i++) cout<<str[i];
      cout<<endl;
      for(;i<len;i++) cout<<str[i];
    }
  }
}
