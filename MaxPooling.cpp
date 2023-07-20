#include<bits/stdc++.h>
using namespace std;

int Maxling(vector< vector<int>> vec, int filtersize, int temp_hi, int temp_hj, int temp_vi, int temp_vj){
    
    
    int MAX = INT_MIN;
    for(int i =temp_hi; i<=temp_hj; i++){
        for(int j=temp_vi; j<=temp_vj; j++){
           MAX = max(MAX, vec[i][j]); 
          // cout<<MAX<<" ";
        }
    }
    
    
     //cout<<MAX;
      
    
   return MAX; 
    
    
}

void MaxPooling(vector<vector<int>>& vec, int filtersize, int stride){
int output =((vec.size()) - filtersize)/stride + 1;
vector<vector<int>> MaxpoolingMatrix(output, vector<int>(output, 0));    
    int start_Index = 0;
    int end_Index = vec.size() - 1;
    //filtersize=3 and stride=1
    int temp_hj = filtersize - 1;
    int temp_hi = start_Index;
    int temp_vi = start_Index;
    int temp_vj = filtersize - 1;
    int poolingmatrix_index_i=0;
    int poolingmatrix_index_j=0;
    int count =0;
    while(((temp_vj!=end_Index) or (temp_hj!=end_Index + 1) )){
        if(temp_hj>end_Index){
            temp_hj = filtersize -1;
            temp_vj = temp_vj + stride;
            temp_vi = temp_vi + stride;
            temp_hi = start_Index;
            poolingmatrix_index_i = 0;
            poolingmatrix_index_j++;

        }
        
        int mytemp_hi = temp_hi;
        int mytemp_hj = temp_hj;
        int mytemp_vi = temp_vi;
        int mytemp_vj = temp_vj;
        while(mytemp_hj!=(end_Index + 1)){
            
           MaxpoolingMatrix[poolingmatrix_index_j][poolingmatrix_index_i] = Maxling(vec, filtersize, mytemp_hi, mytemp_hj, mytemp_vi, mytemp_vj);
           poolingmatrix_index_i++;
                mytemp_hj = stride + mytemp_hj;
                mytemp_hi= stride  + mytemp_hi;
                temp_hj = stride + temp_hj;
                temp_hi= stride  + temp_hi;
                count++;
        }
       // cout<<"ans";
       
       // break;
    }
    for(int i =0; i<3; i++){
        for(int j =0; j<3; j++){
            cout<<MaxpoolingMatrix[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
    //return MaxpoolingMatrix;
    
}


int main(){
    
    
    vector<vector<int>> vec(5, vector<int>(5, 0));
    
    for(int i =0; i<5; i++){
        for(int j =0; j<5; j++){
            vec[i][j] =i + j;
           // cout<<vec[i][j];
        }
    }
    for(int i =0; i<5; i++){
        for(int j =0; j<5; j++){
     //       vec[i][j] =i + j;
            cout<<vec[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
    cout<<"                     MaxPooling Matrix                 "<<endl;
    MaxPooling(vec, 3, 1);
    
}
