#include <bits/stdc++.h>
using namespace std;

//returns middle value 
int midValue(int s, int e){
    return s + (e - s)/2;
}

//Recursive function that contructs Segment Tree for A[s] : A[e]
void buildSegmentTree(int arr[],int segment_tree_index,int array_start_index, int array_end_index, int st[]){
    if (array_start_index==array_end_index){
        st[segment_tree_index] = arr[array_start_index];
        return;
    }
    int mid = midValue(array_start_index,array_end_index); //  midValue returns the mid value in the range
    buildSegmentTree(arr, 2 * segment_tree_index + 1, array_start_index, mid, st);
    buildSegmentTree(arr, 2 * segment_tree_index + 2, mid + 1, array_end_index, st);
    st[segment_tree_index] = st[2 * segment_tree_index + 1] + st[2 * segment_tree_index + 2];
    return;
}

// this is recursive function returns sum of array within given range
int getSumUtil(int segmentTree[], int array_start_index, int array_end_index, int query_start, int query_end, int segment_tree_index){ 
	// If segment of this node is a part of given range, then return the sum of the segment 
	if (query_start <= array_start_index && query_end >= array_end_index) 
		return segmentTree[segment_tree_index];

	// If segment of this node is outside the given range
	if (array_end_index < query_start || array_start_index > query_end) 
		return 0; 

	// If a part of this segment overlaps with the given range 
	int mid = midValue(array_start_index, array_end_index); 
	return getSumUtil(segmentTree, array_start_index, mid, query_start, query_end, 2*segment_tree_index + 1) + 
		getSumUtil(segmentTree, mid+1, array_end_index, query_start, query_end, 2*segment_tree_index + 2); 
}

//check for invalid input and returns sum of array within given range
int getSum(int segmentTree[], int given_array_size, int query_start, int query_end) 
{ 
	// Check for invalid input values 
	if (query_start < 0 || query_end > given_array_size-1 || query_start > query_end){ 
		cout<<"Invalid Input"; 
		return -1; 
	} 
	return getSumUtil(segmentTree, 0, given_array_size - 1, query_start, query_end, 0); 
} 

//Prints the segment Tree
void showSegmentTree(int segmentTree[],int max_size){
    for(int i=0;i<max_size;i++)
        cout<<segmentTree[i]<<" ";
    cout<<endl;
    return;
}

// this is a recursive function that updates segment tree recursively (top to down)
void updateValueUtil(int segmentTree[], int array_start_index, int array_end_index, int update_array_on_index, int diff, int segment_tree_index){ 
	// Base Case: If the input index lies outside the range of this segment 
	if (update_array_on_index < array_start_index || update_array_on_index > array_end_index) 
		return; 
	// If the input index is in range of this node, then update the value of the node and its children 
	segmentTree[segment_tree_index] = segmentTree[segment_tree_index] + diff; 
	if (array_end_index != array_start_index){ 
		int mid = midValue(array_start_index, array_end_index); 
		updateValueUtil(segmentTree, array_start_index, mid, update_array_on_index, diff, 2*segment_tree_index + 1); 
		updateValueUtil(segmentTree, mid+1, array_end_index, update_array_on_index, diff, 2*segment_tree_index + 2); 
	} 
}

// this function check validity of inputs and calls the recursive function updateValueUtil to update segment tree
void updateValue(int arr[], int segmentTree[], int given_array_size, int update_array_on_index, int new_val){
	// Check for invalid input index 
	if (update_array_on_index < 0 || update_array_on_index > given_array_size-1){ 
		cout<<"Invalid Input"; 
		return; 
	} 
	// Get the difference between new value and old value 
	int diff = new_val - arr[update_array_on_index]; 

	// Update the value in array 
	arr[update_array_on_index] = new_val; 

	// Update the values of nodes in segment tree 
	updateValueUtil(segmentTree, 0, given_array_size-1, update_array_on_index, diff, 0); 
}

int main(){
    int n;cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    //Height of Segment Tree
    int x = (int)(ceil(log2(n)));

    // Maximum Size of Segment Tree
    int max_size = 2*(int)pow(2, x) - 1;
    cout<<max_size<<endl;

    //Allocate memory
    int segmentTree[max_size];
    memset(segmentTree,0,sizeof(segmentTree));

    // Building Segment Tree
    buildSegmentTree(arr,0,0,n-1,segmentTree);

    //Print Segement Tree
    showSegmentTree(segmentTree,max_size);

    // sum range queries 
    cout<<"Total Number of Queries ";
    int queries; cin>>queries;
    for(int i = 0; i<queries; i++){
        int start, end;
        cin>>start>>end;
        int res = getSum(segmentTree, n, start, end);
        cout<<"Sum of values in the range "<<start<<" : "<<end<<" is "<<res<<endl;
    }
    //update array value at index 2 with value 11
    updateValue(arr,segmentTree,n,2,11);
    showSegmentTree(segmentTree,max_size);
    return 0;
}