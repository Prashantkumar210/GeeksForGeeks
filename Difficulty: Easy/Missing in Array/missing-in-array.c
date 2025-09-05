int missingNum(int *arr, int size) {
    
    long long num = size+1;
    long long realsum = num*(num+1)/2;
    long long sum = 0;
    
    for(long long i=0; i<size; i++){
        sum += arr[i];
    }
    return (int)(realsum-sum);
}
