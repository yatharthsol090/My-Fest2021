#include<iostream>
//used in creating random numbers
#include<ctime>
#include<chrono>
#include<random>

using namespace std;

// Function to find minimum in an array
int minimum(int a[], int n){
    int minm = a[0];
    for(int i=1; i<n; i++){
        if(a[i] < minm){
            minm = a[i];
        }
    }
    return minm;
}

// Function to find sum of all elements in array
int sumTotal(int a[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    return sum;
}

// KNAPSACK ALGORITHM FUNCTION 
int knapsack_dp(int n, int M, int w[], int p[]){
    int i,j;

    //create a matrix to memoize the values using dynamic programming
    int knapsack[n+1][M+1];

    //knapsack[i][j] denotes the maximum attainable value of items in knpasack with i available items and capacity of knapsack being j
    //initializing knapsack[0][j]=0 for 0<=j<=M because if there is no item, no value can be attained
    for(j=0;j<=M;j++)
        knapsack[0][j]=0;
    
    //initializing knapsack[i][0]=0 for 0<=i<=n,
    //because in a bag of zero capacity, no item can be placed
    for(i=0;i<=n;i++)
        knapsack[i][0]=0;
    
    //now, filling the matrix in bottom up manner
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(w[i-1]<=j)
            {
                knapsack[i][j]=max(knapsack[i-1][j],p[i-1]+knapsack[i-1][j-w[i-1]]);
            }
            else
            {
                knapsack[i][j]=knapsack[i-1][j];
            }
        }
    }

    // Forming 0/1 Set
    // i = n; 
    // j = M;
    // int resSet[n+1];
    // while(i > 0 && j > 0){
    //     if(knapsack[i][j] == knapsack[i-1][j]){
    //         resSet[i] = 0;
    //         i--;
    //     }else {
    //         resSet[i] = 1;
    //         i--;
    //         j = j-w[i];
    //     }
    // }
    // cout << "Items taken into the knapsack are: \n";
    // for(int k=1; k<=n; k++){
    //     cout << resSet[k] << " ";
    // }
    // cout << endl;

    return knapsack[n][M];
}

int main()
{
    cout << "\nKNAPSACK ALGORITHM: DYNAMIC PROGRAMMING :" << endl;
    cout << "========================================" << endl;
    // time_t start, end;

    // seeding the srand() with current time, so that random numbers will always be different
    srand((unsigned) time(0));

    int i,j;
    int n;  //number of items
    int M;  //capacity of knapsack

    cout<<"Enter the no. of items: ";
    cin>>n;
    int w[n];  //weight of items
    int p[n];  //value of items
    int input;

    cout << "Provide custom input (press 1) / Generate Random numbers (press 0) :  ";
    cin >> input;
    cout << endl;

    if(input == 1){
        cout<<"Enter the weight and price(or profit) of all items:"<<endl;
        for(i=0;i<n;i++)
        {
            cin >> w[i] >> p[i];
        }
        cout<<"Enter the capacity of knapsack: ";
        cin>>M;
        
    } else{
        //  Generating Random wt b/w 5 & 50
        cout << "Generated Weight: ";
        for(int i=0; i<n; i++){
            w[i] = 5 + (rand() % (50 - 5 + 1));
            cout << w[i] << " ";
        }
        cout << endl;

        //  Generating Random price b/w 50 & 300
        cout << "Generated price(or profit): ";
        for(int i=0; i<n; i++){
            p[i] = 50 + (rand() % (300 - 50 + 1));
            cout << p[i] << " ";
        }
        cout << endl;

        int minWt, totalWt;
        minWt = minimum(w, n);
        totalWt = sumTotal(w, n);

        //  Generating Random Capacity b/w min wt & total wt sum
        cout << "Generated Capacity: ";
            M = minWt + (rand() % (totalWt - minWt + 1));
            cout << M << endl;
    }
    cout << endl;     

    auto t1 = std::chrono::high_resolution_clock::now();
    int result=knapsack_dp(n,M,w,p);
    cout << "The maximum value of items that can be put into knapsack is: " << result << endl;
    auto t2 = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    cout << "Runtime: " << duration << " micro sec." << endl;
    
    return 0;
}