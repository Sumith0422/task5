#include <iostream>
#include <cstring>
using namespace std;

int lcsAlgo(string X, string Y, int m, int n) {
  int LCS_t[m + 1][n + 1];


  // matrix in bottom-up
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS_t[i][j] = 0;
      else if (X[i - 1] == Y[j - 1])
        LCS_t[i][j] = LCS_t[i - 1][j - 1] + 1;
      else
        LCS_t[i][j] = max(LCS_t[i - 1][j], LCS_t[i][j - 1]);
    }
  }

  int index = LCS_t[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (X[i - 1] == Y[j - 1]) {
      lcsAlgo[index - 1] = X[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_t[i - 1][j] > LCS_t[i][j - 1])
      i--;
    else
      j--;
  }
  cout << "S1 : " << X << "\nS2 : " << Y << "\nLogest Common Substring is: " << lcsAlgo << "\n";
  cout <<"With a length of:"<< LCS_t[m][n] <<"\n";
}

int main() {
   string X;
   string Y;
 std::cout <<"Enter S1:";
 std::cin >> X;
 std::cout<<"Enter S2:";
 std::cin >> Y;
  
  int n=X.length();
  int m=Y.length();
 

  lcsAlgo(X, Y, m, n);
      int arr[5][5] = {
        { 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 1 },
        { 0, 1, 0, 2, 0 },
        { 0, 0, 2, 0, 3 },
        { 0, 1, 0, 3, 0 },
        } ;
        
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            cout<<"\t"<<arr[i][j];
        }
        cout<<endl;
    }

}
