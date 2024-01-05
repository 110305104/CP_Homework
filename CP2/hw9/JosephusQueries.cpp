#include <iostream>
using namespace std;


int findKthChild(int n, int k) {

    if (n == 1) // Only one child left, so it will be the kth child.
        return 1;
    if (k <= (n+1)/2)
    // The kth child to be removed in a circle of n children is equivalent to the kth child
    // to be removed in a circle of (n-1) children, with the position shifted by k-1.
    {
        if (2*k > n) return 2*k%n;
        else return 2*k;
    }
    
    int c = findKthChild(n>>1, k - (n+1)/2);
    //cout<<"c="<<c<<endl;
    if (n%2!=0) return 2*c + 1;
    else return 2*c - 1;
}
int Josephus(int N, int k)
{
 
    // Initialize variables i and ans with 1 and 0
    // respectively.
 
    int i = 1, ans = 0;
 
    // Run a while loop till i <= N
 
    while (i <= N) {
 
        // Update the Value of ans and Increment i by 1
        ans = (ans + k) % i;
        i++;
    }
 
    // Return required answer
    return ans + 1;
}
 
int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, k;
        cin >> n >> k;

        int kthChild = findKthChild(n, k);
        //int try2 = Josephus(n,k);
        cout << kthChild << endl;
        //cout << try2 << endl;
    }

    return 0;
}