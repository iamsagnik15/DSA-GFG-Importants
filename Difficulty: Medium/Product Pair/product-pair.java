class Solution {
    public boolean isProduct(int[] arr, long target) {
        
        Set<Long> vis = new HashSet<>();
        for (int num: arr) {
            if (num == 0) {
                if (target == 0 && !vis.isEmpty()) return true;
            }
            else if (target % num == 0) {
                long comp = target / num;
                if (vis.contains(comp)) return true;
            }
            vis.add((long)num);
        }
        return false;
    }
}