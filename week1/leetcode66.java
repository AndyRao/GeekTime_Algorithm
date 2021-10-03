class Solution {
    public int[] plusOne(int[] digits) {
        boolean needPlusOne = true;
        for(int i= digits.length - 1; i>=0; i--) {
            if(!needPlusOne) break;      
            digits[i] += 1;
            if(digits[i] >= 10) {
                digits[i] -= 10;
            } else {
                needPlusOne = false;
            }
               

        }
        //如果最高位是9， 那么加1之后其他位必然都是0
        if (needPlusOne) {
            int[] d = new int[digits.length + 1];
            d[0] = 1;
            return d;
        }
        return digits;
    }
}
