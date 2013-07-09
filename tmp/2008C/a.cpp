#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<utility>
#include<bitset>
#include<climits>
#include<cstdio>
#include<cassert>
using namespace std;

char CtoN[3];
char in[128];
char cp[128];

bool input() {
  if(scanf("%s", in) == EOF)
    return false;
  if(in[0]=='.')return false; 
  return true;
}

char Not(char c) {
  if(c == '0')
    return '2';
  else if(c == '1')
    return '1';
  else
    return '0';
}

char Lpro(char c1, char c2) {
  return min(c1, c2);
}
char Lsum(char c1, char c2) {
  return max(c1, c2);
}

char Clac(char str[]) {
  int count;
  char str1[128], str2[128];
  char *ptr;
  int i, j;
  char op;

  ptr = str1;
  if(str[0] == '(') {
    count = 1;
    i = 1, j = 0;
    while(count > 0) {
      if(str[i] == '(')
        count++;

      else if(count==1&&(str[i] == '*' || str[i] == '+')) {
        op = str[i];
        ptr[j] = '\0';
        j = -1;
        ptr = str2;
      }

      else if(str[i] == ')')
        count--;
      
      if(count==0){
        ptr[j] = '\0';
        break;
      } 
      if(j > -1)
        ptr[j] = str[i];
      j++; i++;
    }

    if(op == '*')
      return Lpro(Clac(str1), Clac(str2));
    else
      return Lsum(Clac(str1), Clac(str2));
  }

  else if(str[0] == '-') {
    i = 1; j = 0;
    while(str[i]){
      str1[j] = str[i];
      i++; j++;
    }
    str1[j] = '\0';
    return Not(Clac(str1));
  }
  else
    return str[0];
}

void mkcp() {
  int i = 0;
  while(in[i]) {
    switch (in[i]) {
      case 'P':
        cp[i] = CtoN[0];
        break;
      case 'Q':
        cp[i] = CtoN[1];
        break;
      case 'R':
        cp[i] = CtoN[2];
        break;
      default :
        cp[i] = in[i];
        break;
    }
    i++;
  }
}

int solve() {
  int ans = 0;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < 3; k++) {
        CtoN[0] = i + '0'; CtoN[1] = j + '0'; CtoN[2] = k + '0';
        mkcp();
        if(Clac(cp) == '2')
          ans++;
      }
    }
  }

  return ans;
}

int main() {
  while(input())
    cout << solve() << endl;
}

