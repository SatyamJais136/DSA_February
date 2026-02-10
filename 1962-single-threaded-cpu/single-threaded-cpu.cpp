class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        int n = tasks.size();
        for(int i = 0; i < n; i++){
            tasks[i].push_back(i);
        }
        
        //sort all the tasks on the basis of enqueue time
        sort(tasks.begin(), tasks.end());
        long long timer = tasks[0][0];
        int i = 0;

        //processing time, index
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        while(!pq.empty() || i < n){

            //put all the tasks into min heap whose enqueue time is less than or equal to timer
            while(i < n && timer >= tasks[i][0]){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            //if min heap is empty
            if(pq.empty()){
                timer = tasks[i][0];
            }

            //not empty
            else{
                ans.push_back(pq.top().second);
                timer += pq.top().first;
                pq.pop();
            }
        }
        return ans;
    }
};