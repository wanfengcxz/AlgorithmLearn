// dijkstra 80ms 99%
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n, 999999);
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for(int i = 0;i<times.size();i++)
            matrix[times[i][0]-1][times[i][1]-1] =  times[i][2];
        
        return dijkstra(matrix, k, dis, n);
    }

    int dijkstra(vector<vector<int>> &matrix, int start, vector<int> &dis, int n){
        vector<bool> visited(n, false);
        visited[start-1] = true;
        dis[start-1] = 0;
        for(int i = 0;i<n;i++){
            if (matrix[start-1][i] != -1)
                dis[i] = matrix[start-1][i];
        }
        for(int i = 1;i<n;i++){
            int min_dis = min(dis, visited);
            if (min_dis == -1)
                return -1;
            visited[min_dis] = true;
            for(int j = 0;j<n;j++){
                if (!visited[j] && matrix[min_dis][j]!=-1 &&  dis[j]>dis[min_dis]+matrix[min_dis][j])
                    dis[j] = dis[min_dis]+matrix[min_dis][j];
            }
        }
        
        return max(dis);
    }

    int min(vector<int> &dis, vector<bool> &visited){
        int min_index = -1;
        int min_value = 999999;
        for(int i = 0;i<dis.size();i++){
            if (!visited[i] && dis[i] < min_value){
                min_index = i;
                min_value = dis[i];
            }
        }
        return min_index;
    }

    int max(vector<int> &dis){
        int max_value = -1;
        for(auto v:dis){
            if (max_value < v)
                max_value = v;
        }
        return max_value;
    }

};


// dijkstra 堆优化版 116ms 30%
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        vector<int> dis(n, 999999);
        // 构造邻接表
        for(auto v:times){
            int x = v[0]-1;
            int y = v[1]-1;
            adjList[x].push_back({y, v[2]});
        }
        dijkstra(adjList, k, n, dis);
        int res = max(dis);
        return res == 999999?-1:res;
    }

    void dijkstra(vector<vector<pair<int,int>>> &adjList, int start, int n,   vector<int> &dis){
        // first time second y
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        dis[start-1] = 0;
        pq.emplace(0, start-1);
        while(!pq.empty()){
            pair<int, int> curr = pq.top();
            int time = curr.first;
            int y = curr.second;
            pq.pop();
            if (dis[y] < time)
                continue;
            for(auto &e: adjList[y]){
                // 此处使用time和dis[y]都可以
                int new_dis = time + e.second;
                if (dis[e.first]>new_dis){
                    dis[e.first] = new_dis;
                    pq.emplace(new_dis, e.first);
                }
            }
        }
       
    }


    int max(vector<int> &dis){
        int max_value = -1;
        for(auto v:dis){
            if (max_value < v)
                max_value = v;
        }
        return max_value;
    }

};