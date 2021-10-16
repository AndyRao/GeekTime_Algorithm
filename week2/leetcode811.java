class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> h = new HashMap();
        for(String domain: cpdomains) {
            String[] countDomain = domain.split("\\s+");
            Integer count = Integer.valueOf(countDomain[0]);
            String[] domainParts = countDomain[1].split("\\.");
            String d = "";
            int len = domainParts.length;
            for(int i = len - 1; i >= 0; i--) {
                if(i < len - 1) {
                    d = domainParts[i] + "." + d;
                } else {
                    d = domainParts[i] + d;
                }
                h.put(d, h.getOrDefault(d, 0) + count);
            }

         }
         List<String> ans = new ArrayList();
         for(String key: h.keySet()) {
             ans.add(h.get(key) + " " + key);
         }
         return ans;
         
    }
}
