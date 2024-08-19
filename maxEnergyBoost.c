/*
  Leetcode 3259. Maximum energy Boost From Two Drinks. In Leetcode contest weekly 411
*/


long long max(long long a, long long b) { return (a > b) ? a : b; }

long long maxEnergyBoost(int* energyDrinkA, int energyDrinkASize, int* energyDrinkB, int energyDrinkBSize) {
    int n = energyDrinkASize;
    if (energyDrinkBSize != n) {
        printf("Error: Sizes of energyDrinkA and energyDrinkB must be the same.\n");
        return -1; //Error case
    }

    long long dpA[n], dpB[n];
    dpA[0] = energyDrinkA[0];
    dpB[0] = energyDrinkB[0];

  

  for (int i = 1; i < n; i++) {
        long long continueA = dpA[i-1] + energyDrinkA[i];
        long long switchToA = (i > 1 ? dpB[i-2] + energyDrinkA[i] : energyDrinkA[i]);
        long long continueB = dpB[i-1] + energyDrinkB[i];
        long long switchToB = (i > 1 ? dpA[i-2] + energyDrinkB[i] : energyDrinkB[i]);

        dpA[i] = max(continueA, switchToA);
        dpB[i] = max(continueB, switchToB);

        
    }

    return max(dpA[n-1], dpB[n-1]);
}
