class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int cnt = 0;

        // Calculate the frequency of each character
        for(int i = 0; i < tasks.size(); i++){
            freq[tasks[i] - 'A']++;
            cnt = max(cnt, freq[tasks[i] - 'A']);
        }

        int ans =(cnt-1) * (n+1);

        for(int i = 0; i < 26; i++){
            if(freq[i] == cnt) ans++;
        }
        return ans > tasks.size() ? ans:tasks.size();
    }
};