//Minimum Average of Smallest and Largest Elements
//Leetcode 3194

class Solution {
    public double minimumAverage(int[] nums) {
        
        
        int sum = 0;
        Stack<Double> stack = new Stack<>();
        int n = nums.length;

        Arrays.sort(nums);

        

        for(int i = 0; i< n/2; i++){


            int min = nums[i];
            int max = nums[n-1-i];
            
            double avg = (min+max)/2.0;
            stack.push(avg);
        }



        double minAvg = 100000;

        while(!stack.isEmpty()){
            double avgStack = stack.pop();
            if(avgStack<minAvg){
                minAvg = avgStack;
            }
        }
        

        


        return minAvg;
    }
}
