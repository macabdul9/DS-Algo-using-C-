#include <iostream>
#include <cmath>
using namespace std;

void SieveOfEratosthenes(int m, int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n - m + 1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=m; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " "; 
} 
int main(int argc, char const *argv[])
{
	int test;
	int m, n;
	// bool b;
	// cin>>test;
	// while(test > 0){
	// 	cin >> m >> n;
	// 	/*
	// 		Since time compexity of this solution is O(nlogn) which cause time limit exceeded so we're going 
	// 		to movie onto  new solution
	// 	*/
	// 	// while(m <= n){
	// 	// 	if ( m == 0 or m == 1)
	// 	// 		continue;
	// 	// 	b = true;
	// 	// 	for(int j = 2; j <= sqrt(m); j++){
	// 	// 		if(m%j == 0){
	// 	// 			b = false;
	// 	// 			break;
	// 	// 		}
	// 	// 	}
	// 	// 	if (b)
	// 	// 	{
				
	// 	// 		cout << m << endl;
	// 	// 	}
	// 	// 	m++;
	// 	// }
	// 	test--;
	// }
	cin>>m>>n;
	int size = n - m + 1;
	int arr[size];
	for(int i = 0; i < size;i++){
		arr[i] =  m;
		m += 1;
	}
	int j = 2;
	while(j <= 10){
		for(int i = 0; i < size; i++){
			if(arr[i] < 2){
				arr[i] = 0;
				continue;
			}
			if(arr[i]%j == 0 and arr[i]/j > 1){
				arr[i] = 0;
			}
		}
		j++;
	}

	for(int i = 0; i < size; i++){
		if(arr[i]!= 0){
			cout << arr[i] << "  ";
		}
	}
	
	return 0;
}