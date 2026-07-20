class Solution {

    int encode(int prev, int d) {
        return (prev << 5) + d;
    }

    public ArrayList<String> findPrefixes(ArrayList<String> arr) {

        Map<Integer, Integer> prefixCount = new HashMap<>();

        for (String word : arr) {
            int enc = 0;
            for (int i = 0; i < word.length(); i++) {
                enc = encode(enc, word.charAt(i));
                prefixCount.put(enc, prefixCount.getOrDefault(enc, 0) + 1);
            }
        }

        ArrayList<String> res = new ArrayList<>(arr.size());

        for (String word : arr) {
            int enc = 0;
            StringBuilder prefix = new StringBuilder();

            for (int i = 0; i < word.length(); i++) {
                enc = encode(enc, word.charAt(i));
                prefix.append(word.charAt(i));

                if (prefixCount.get(enc) == 1 || i == word.length() - 1) {
                    res.add(prefix.toString());
                    break;
                }
            }
        }

        return res;
    }
}