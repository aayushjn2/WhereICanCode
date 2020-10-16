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
int getRangeSumLazyUtil(int segmentTree[], int lazy[], int array_start_index, int array_end_index, int query_start, int query_end, int segment_tree_index){ 
	/* if(array_start_index > array_end_index){
        return 0;
    } */
    
    if(lazy[segment_tree_index] != 0){
        segmentTree[segment_tree_index] += (array_end_index - array_start_index + 1)*lazy[segment_tree_index];
        if(array_start_index != array_end_index){
            lazy[2 * segment_tree_index + 1] += lazy[segment_tree_index];
            lazy[2 * segment_tree_index + 2] += lazy[segment_tree_index];
        }
        lazy[segment_tree_index] = 0;
    }

    if(query_start > array_end_index || query_end < array_start_index || array_end_index < array_start_index){
        return 0;
    }
    // If segment of this node is a part of given range, then return the sum of the segment 
	if (query_start <= array_start_index && query_end >= array_end_index) 
		return segmentTree[segment_tree_index];

    int mid = midValue(array_start_index, array_end_index); 
	return getRangeSumLazyUtil(segmentTree,lazy, array_start_index, mid, query_start, query_end, 2*segment_tree_index + 1) + 
		getRangeSumLazyUtil(segmentTree,lazy, mid+1, array_end_index, query_start, query_end, 2*segment_tree_index + 2); 
}

//check for invalid input and returns sum of array within given range
int getRangeSumLazy(int segmentTree[], int lazy[], int given_array_size, int query_start, int query_end){
	// Check for invalid input values 
	if (query_start < 0 || query_end > given_array_size-1 || query_start > query_end){ 
		cout<<"Invalid Input"; 
		return -1; 
	} 
	return getRangeSumLazyUtil(segmentTree,lazy, 0, given_array_size - 1, query_start, query_end, 0); 
} 

//Prints the segment Tree
void showSegmentTree(int segmentTree[],int max_size){
    for(int i=0;i<max_size;i++)
        cout<<segmentTree[i]<<" ";
    cout<<endl;
    return;
}
//Prints the lazy Tree
void showLazyTree(int lazy[],int max_size){
    for(int i=0;i<max_size;i++)
        cout<<lazy[i]<<" ";
    cout<<endl;
    return;
}

// this is a recursive function that updates segment tree recursively (top to down)
void updateValueRangeSumLazyUtil(int segmentTree[],int lazy[], int array_start_index, int array_end_index, int update_array_start_index, int update_array_end_index, int diff, int segment_tree_index){ 
	
    /*if(array_start_index > array_end_index){
        return;
    }*/
    //make sure all propagation is done at pos. If not update tree
    //at pos and mark its children for lazy propagation.
    if (lazy[segment_tree_index] != 0) {
        segmentTree[segment_tree_index] += (array_end_index - array_start_index + 1)*lazy[segment_tree_index];
        if (array_end_index != array_start_index) { //not a leaf node
            lazy[2 * segment_tree_index + 1] += lazy[segment_tree_index];
            lazy[2 * segment_tree_index + 2] += lazy[segment_tree_index];
        }
        lazy[segment_tree_index] = 0;
    }
    // Base Case: If the input index lies outside the range of this segment 
	if (update_array_start_index > array_end_index || update_array_end_index < array_start_index || array_start_index > array_end_index) 
		return;

    //Total Overlap
    if(update_array_start_index <= array_start_index && update_array_end_index >= array_end_index) {
        segmentTree[segment_tree_index] += (array_end_index - array_start_index +1)*diff;
        if(array_start_index != array_end_index) {
            lazy[2*segment_tree_index + 1] += diff;
            lazy[2*segment_tree_index + 2] += diff;
        }
        return;
    }

	// If the input index is in range of this node, then update the value of the node and its children
    int mid = midValue(array_start_index, array_end_index); 
    updateValueRangeSumLazyUtil(segmentTree, lazy, array_start_index, mid, update_array_start_index,update_array_end_index, diff, 2*segment_tree_index + 1); 
    updateValueRangeSumLazyUtil(segmentTree, lazy, mid+1, array_end_index, update_array_start_index,update_array_end_index, diff, 2*segment_tree_index + 2); 
    segmentTree[segment_tree_index] = segmentTree[2*segment_tree_index + 1] + segmentTree[2*segment_tree_index + 2];
}

// this function check validity of inputs and calls the recursive function updateValueUtil to update segment tree
void updateRangeSumLazyValue(int arr[], int segmentTree[],int lazy[], int given_array_size, int update_array_start_index, int update_array_end_index, int diff){
	// Check for invalid input index 
	if (update_array_start_index < 0 || update_array_start_index > given_array_size-1 ||
        update_array_end_index < 0 || update_array_end_index > given_array_size -1 ||
        update_array_end_index < update_array_start_index){ 
		cout<<"Invalid Input"; 
		return; 
	}

	// Update the values of nodes in segment tree 
	updateValueRangeSumLazyUtil(segmentTree, lazy, 0, given_array_size-1, update_array_start_index, update_array_end_index, diff, 0); 
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

    //Allocate memory to segment tree
    int segmentTree[max_size];
    //Allocate memory to lazy tree
    int lazy[max_size];

    memset(lazy, 0, sizeof(lazy));
    memset(segmentTree,0,sizeof(segmentTree));

    // Building Segment Tree
    buildSegmentTree(arr,0,0,n-1,segmentTree);

    // Printing segment Tree
    showSegmentTree(segmentTree,max_size);

    int queries;
    cout<<"Total number of queries : ";
    cin>>queries;
    for(int i = 0; i< queries ;i++){
        int start, end;
        cout<<"Enter start and end query range for (0 : n-1 ) : ";
        cin>>start>>end;
        int res = getRangeSumLazy(segmentTree, lazy, n, start, end);
        cout<<"Get Range Sum Lazy for "<<start<<" : "<<end<<" => "<<res<<endl;
        cout<<"Segment Tree after query range : ";
        showSegmentTree(segmentTree,max_size);
        cout<<"Lazy Tree after query : ";
        showLazyTree(lazy,max_size);
        int u_start, u_end, diff;
        cout<<"Enter start and end update range with updated value by x : ";
        cin>>u_start>>u_end>>diff;
        updateRangeSumLazyValue(arr,segmentTree, lazy, n, u_start, u_end, diff);
        cout<<"Segment Tree after update range : ";
        showSegmentTree(segmentTree,max_size);
        cout<<"Lazy Tree after update : ";
        showLazyTree(lazy,max_size);
    }
    return 0;
}