class Solution {
    public boolean isPalindrome(String s) {
        
        StringBuilder str = new StringBuilder();
        for(Character c: s.toLowerCase().toCharArray()){
            if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
                str.append(c);
            }
        }
        int start =0, end = str.length()-1;
        while(start < end){
            if(str.charAt(start) != str.charAt(end)){
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }
}