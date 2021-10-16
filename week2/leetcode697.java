class Solution {
    public int findShortestSubArray(int[] nums) {
        //int[0] 保存count， int[1]保存开始位置， int[2]保存结束位置
        Map<Integer, int[]> map = new HashMap();
        int len = nums.length;
        for(int i = 0; i < len; i++) {
            if(!map.containsKey(nums[i])) {
                int[] st = new int[]{1, i, i};
                map.put(nums[i], st);
            }
            int[] stat = map.get(nums[i]);
            stat[0]++;
            stat[2] = i;
        }
        int maxFrequency = 0;
        int shortestLen = 50000;
        for(Map.Entry<Integer, int[]> entry : map.entrySet()) {
            int[] stat = entry.getValue();
            int fre = stat[0];
            int intervalLength = stat[2] - stat[1] + 1;
            if(stat[0] > maxFrequency) {
                maxFrequency = stat[0];
                shortestLen = intervalLength;
            } else if(stat[0] == maxFrequency && intervalLength < shortestLen) {
                shortestLen = intervalLength;
            }
        }
        return shortestLen;     
         

    }
}
