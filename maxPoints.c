/*
  Leetcode 1937. Maximum number of points with cost
*/


#define max(a, b) ((a) > (b) ? (a) : (b))


long long maxPoints(int** points, int pointsSize, int* pointsColSize) {
    int m = pointsSize;
    int n = *pointsColSize;

   long long *dp = (long long*)malloc(n * sizeof(long long));
    long long *left_max = (long long*)malloc(n * sizeof(long long));
    long long *right_max = (long long*)malloc(n * sizeof(long long));

    for(int i = 0; i < n; ++i){
        dp[i]= points[0][i];

    }


    for(int r = 1; r < m; ++r){
        left_max[0] = dp[0];
        for(int c = 1; c < n; ++c){
            left_max[c] = max(left_max[c-1]-1,dp[c]);
        }
        right_max[n-1] = dp[n-1];
        for(int c = n - 2; c >= 0; --c){
            right_max[c] = max(right_max[c+1]-1, dp[c]);
        }

        for(int c = 0; c < n; ++c){
            dp[c] = points[r][c] + max(left_max[c],right_max[c]);
        }
    }

    long long result = dp[0];
    for(int i = 1; i < n; i++){
        result = max(result,dp[i]);
    }

    free(dp);
    free(left_max);
    free(right_max);

    return result;
}
