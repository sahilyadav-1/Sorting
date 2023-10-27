class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int s, int e)
    {
        // code here
        if(s >= e) return;

        int pivotIndex = partition(arr, s, e);
    
        quickSort(arr,s,pivotIndex-1);
        quickSort(arr,pivotIndex+1,e);
    }
    
    public:
    int partition (int arr[], int s, int e)
    {
       // Your code here
       int pivot = arr[s];

        int count = 0;
        for(int i=s+1; i<=e; i++){
            if(arr[i]<=pivot)
                count++;
        }
    
        int pivotIndex = s+count;
        swap(arr[s],arr[pivotIndex]);
    
        int i = s;
        int j = pivotIndex+1;
    
        while(i<pivotIndex && j<=e){
            if(arr[i]>pivot && arr[j]<=pivot){
                swap(arr[i],arr[j]);
            }
            else if(arr[i]<=pivot){
                i++;
            }
            else{
                j++;
            }
        }
    
        return pivotIndex;
    }
};
