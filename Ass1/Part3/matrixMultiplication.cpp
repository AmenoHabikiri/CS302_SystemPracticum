#include <iostream>
#include<bits/stdc++.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>
#include <unistd.h>
#include <unordered_map>
using namespace std;
int n;
int** Matrix1;
int** Matrix2;
int** MatrixNormal;
int** MatrixThread;

void InitializeMatrix(int **Matrix)
{
    for (int i=0; i<n;i++)
    {
        Matrix[i] = new int[n];
    }
    for (int i=0; i<n ;i++)
    {
        for (int j=0; j<n; j++)
        {
            int val = rand()%100;
            Matrix[i][j] = val;
        }
    }
}
void PrintMatrix(int ** Matrix)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n ; j++)
        {
            cout << Matrix[i][j] <<" ";
        }
        cout<<endl;
    }
    cout << endl;
}
void thread_Multiplication(int row1, int row2)
{
    for(int i=row1; i<row2; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                MatrixThread[i][j]+= (Matrix1[i][k]*Matrix2[k][j]);
            }
        }
    }
}