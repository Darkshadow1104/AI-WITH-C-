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

vector<vector<int>> mulMat(vector<vector<int>> patch_matrix, vector<vector<int>> kernal_matrix)
{
    vector<vector<int>> result(kernal_matrix.size(), vector<int>(kernal_matrix.size(), 0));
  
    printf("Multiplication of given two matrices is:\n");
     int R1 = kernal_matrix.size();
     int C1 = kernal_matrix[0].size();
     int R2 = patch_matrix.size();
     int C2 = patch_matrix[0].size();
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            result[i][j] = 0;
  
            for (int k = 0; k < R2; k++) {
                result[i][j] += kernal_matrix[i][k] * patch_matrix[k][j];
            }
  
            //printf("%d\t", rslt[i][j]);
        }
  
        //printf("\n");
    }
   
    return result;
}

vector<vector<int>> Multiply(vector<vector<int>> vec, vector<vector<int>> kernal,  int filtersize, int temp_hi, int temp_hj, int temp_vi, int temp_vj){
    vector<vector<int>> output_matrix(filtersize, vector<int>(filtersize, 0));
    vector<vector<int>> input_patch_matrix(filtersize, vector<int>(filtersize, 0));
    int l=0;
    
   // cout<<temp_hi<<" "<<temp_hj<<" "<<temp_vi<<" "<<temp_vj<<endl;
    for(int i =temp_hi; i<=temp_hj; i++){
        int m=0;
        for(int j=temp_vi; j<=temp_vj; j++){
           //MAX = max(MAX, vec[i][j]); 
          // cout<<MAX<<" ";
          input_patch_matrix[l][m] = vec[i][j];
          cout<<input_patch_matrix[l][m]<<" ";
          //cout<<input_patch_matrix[l][m]<<" ";
          m++;
        }
        l++;
        cout<<endl;
    }
    output_matrix = mulMat(input_patch_matrix,kernal);
     for(int i=0; i<3; i++){
        for(int j =0; j<3; j++){
            cout<<output_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return output_matrix;
}


void conv(vector<vector<int>> vec, vector<vector<int>> kernal , int filtersize, int stride){
int output =((vec.size()) - filtersize)/stride + 1;
vector<vector<int>> MultiplyMatrix(output, vector<int>(output, 0));
vector<vector<vector<int>>> kernal_output;

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
           // poolingmatrix_index_i = 0;
            //poolingmatrix_index_j++;

        }
        
        int mytemp_hi = temp_hi;
        int mytemp_hj = temp_hj;
        int mytemp_vi = temp_vi;
        int mytemp_vj = temp_vj;
       // cout<<"yes"<<endl;
        while(mytemp_hj!=(end_Index + 1)){
            
          // kernal_output.push_back(Multiply(vec, kernal, filtersize, mytemp_hi,mytemp_hj, mytemp_vi, mytemp_vj));
           cout<<"yes"<<endl;
          // cout<<"yes"<<endl;
           //poolingmatrix_index_i++;
           vector<vector<int>> ans = Multiply(vec, kernal, filtersize, mytemp_hi,mytemp_hj, mytemp_vi, mytemp_vj);
          /* cout<<mytemp_hj<<endl;
           cout<<end_Index + 1<<endl;*/
          kernal_output.push_back(ans);
                mytemp_hj = stride + mytemp_hj;
                mytemp_hi= stride  + mytemp_hi;
                temp_hj = stride + temp_hj;
                temp_hi= stride  + temp_hi;
                //count++;
              //  cout<<"yes"<<endl;
        }
       // cout<<"ans";
       
       // break;
    }
    /*for(int i =0; i<3; i++){
        for(int j =0; j<3; j++){
            cout<<MultiplyMatrix[i][j]<<" ";
        }
        cout<<" "<<endl;
    }*/
    //return MaxpoolingMatrix;
    
}

int main(){
    
    
    vector<vector<int>> vec(5, vector<int>(5, 0));
    vector<vector<int>> kernal(3, vector<int>(3, 0));
    
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
    for(int i=0; i<3; i++){
        for(int j =0; j<3; j++){
            kernal[i][j] = i*j;
        }
    }
    conv(vec,kernal, 3, 1);
    
}
