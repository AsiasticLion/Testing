#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//for a given array of integers, display the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array
int main() {
	int t;
	cin >>t;
	for(int i=0; i<t; i++) {
	    int n;
	    cin >> n;
	    int A[n], B[n+2], C[n], c=0, d=n-1;
	    int count=0, tempn=0, temp0=0;
	    B[0]=0;
	    for(int j=0; j<n; j++) {
	        cin >> A[j];
	        C[j]=0;
	        if(A[j]<0) {
	            B[j+1]=0;
	            tempn ++;
	        }
	        else if(A[j]==0) {
	            B[j+1]=0;
	            temp0 ++;
	        }
	        else 
	            B[j+1]=A[j];
	    }
	    B[n+1]=0;
	    //for(int j=0; j<n+2; j++) {
	    //    cout << B[j] << " ";
	    //}
	    //cout << "\n";
	    int sum=0;
	    if(tempn == n) {
	        for(int j=0; j<n-1; j++) {
	            if(A[j]>A[j+1]) {
	                int tempr=A[j];
	                A[j]=A[j+1];
	                A[j+1]=tempr;
	            }
	        }
	        cout << A[n-1];
	    }
	    else if (tempn+temp0==n) {
	        sort(A, A+n);
	        cout << A[n-1-temp0];
	    }
	    else {    
	    for(int j=0; j<n+2; j++) {
	        if(B[j]==0)
	            count=0;
	        if(B[j]!=0) {
	            count ++;
	        }
	        if(B[j+1]==0 && B[j]!=0) {
	            int incl = B[j-count+1]; 
                int excl = 0; 
                int excl_new; 
                int k; 
                int up[count], dn[count], z[count];
                up[0]=incl;
                dn[0]=excl;
                for (k = 1; k < count; k++) { 
                    excl_new = (incl > excl)? incl: excl; 
                    incl = excl + B[j-count+1+k]; 
                    excl = excl_new; 
                    up[k]=incl;
                    dn[k]=excl;
                }
                sum+= ((incl > excl)? incl : excl);
                z[0]=up[0];
                for (k = count-1; k > 0; k--) {
                    if(up[k]>dn[k]) {
                        z[k]=up[k];
                        z[k-1]=dn[k-1];
                        k--;
                    }
                    else {
                        z[k]=dn[k];
                    }
                }
                for(k=count-1; k>=0; k--) {
                    if(k>0)
                        z[k]=z[k]-z[k-1];
                    if(z[k]!=0) {
                        C[c]=z[k];
                        c++;
                    }
                }
                for(k=c-1; k>=0; k--) {
                    C[d] = C[k];
                    C[k]=0;
                    d--;
                    
                }
	        }
	    }
	    }
	cout << "sum=" << sum << "\n";
	for(int j=0; j<n; j++) {
	    if(C[j]!=0)
	        cout << C[j];
	}
	cout << "\n";
	}
    return 0; 
} 