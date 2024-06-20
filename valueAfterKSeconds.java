//3179. Find the N-th Value After K Seconds
//Difficulty Medium

class Solution {
    public int valueAfterKSeconds(int n, int k) {
        
         final int MOD = 1000000007;

        int a[] = new int [n];
        int newA[] = new int [n];

        for(int i = 0 ; i< n; i++){
            a[i] = 1;
           newA[i] = 1;
        }

       

        for(int time = 0 ; time < k; time++){
           
                for(int j = 0; j < n; j++){

                    newA[j] = a[j];
                    if(j>0){
                        newA[j] = (newA[j]+newA[j-1])%MOD;
                    }

                }


                for(int i = 0; i < n; i++){
                    a[i] = newA[i];
                }

            }
     
        

  
        return a[n-1];
    }
}
