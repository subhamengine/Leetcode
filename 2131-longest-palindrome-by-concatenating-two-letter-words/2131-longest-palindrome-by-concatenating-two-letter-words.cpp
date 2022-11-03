class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        /* There are a number of matching digraphs and its reversal */
        /* There are an even number of matching squares */
        /* Among the squares, select one square that has odd number */
        int count = 0;
        map<string, int> freq; // Noticed an unordered map breaks the program for larger inputs
        int var;
        int odd = 0;
        for (string word : words) {
            freq[word]++;
        }
        for (const auto& [key, value] : freq ) {
            if (key[0] == key[1]) {
                if (!odd && freq[key] % 2 == 1) {
                    odd++;
                }
                count += 2*(freq[key] / 2);
            }
            else {
                var = min(freq[key], freq[{key[1],key[0]}]);
                count += 2*var;
                freq[key] = 0;
                freq[{key[1],key[0]}] = 0;
            }
        }
        return 2*(count + odd);
    }
};