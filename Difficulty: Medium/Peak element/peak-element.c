//  Function to find the peak element
int peakElement(int *arr, int n) {
    
    if(n==1) return 0;
    int s = 0;
    int e = n-1;
    
    int mid = s+(e-s)/2;
    
    while(s<=e){
        if(s==e) return e;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid]<=arr[mid+1]) s = mid+1;
        else e = mid;
        
        mid = s+(e-s)/2;
    }
    
    return -1;
}