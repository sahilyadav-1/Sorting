class Solution
{
    public:
    void merge(int arr[], int s, int m, int e)
    {
        // Your code here
        int leftLength = m - s + 1;
        int rightLength = e - m;
    
        int *left = new int[leftLength];
        int *right = new int[rightLength];
    
        int originalIndex = s;

        for(int i = 0; i<leftLength; i++){
            left[i] = arr[originalIndex++];
        }
        
        originalIndex = m + 1;
    
        for(int i = 0; i<rightLength; i++){
            right[i] = arr[originalIndex++];
        }
    
        int leftIndex = 0;
        int rightIndex  = 0;
        originalIndex = s;

        while(leftIndex < leftLength && rightIndex < rightLength){
            if(left[leftIndex] < right[rightIndex]){
                arr[originalIndex++] = left[leftIndex++];
            }
            else{
                arr[originalIndex++] = right[rightIndex++];
            }
        }
    
        while(leftIndex < leftLength){
            arr[originalIndex++] = left[leftIndex++];
        }
    
        while(rightIndex < rightLength){
            arr[originalIndex++] = right[rightIndex++];
        }
        delete []left;
        delete []right;
    }
    public:
    void mergeSort(int arr[], int s, int e)
    {
        //code here
        if(s >= e){
            return;
        }
    
        int m = (s+e)/2;
    
        mergeSort(arr, s, m);
    
        mergeSort(arr, m+1, e);
    
        merge(arr, s, m, e);
        
    }
};
