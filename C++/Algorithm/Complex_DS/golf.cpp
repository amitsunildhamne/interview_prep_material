/*You are asked to cut off trees in a forest for a golf event. The forest is
represented as a non-negative 2D map, in this map:

0 represents the obstacle can't be reached.
1 represents the ground can be walked through.
The place with number bigger than 1 represents a tree can be walked through, and
this positive number represents the tree's height.
You are asked to cut off all the trees in this forest in the order of tree's
height - always cut off the tree with lowest height first. And after cutting,
the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you
need to walk to cut off all the trees. If you can't cut off all the trees, output
-1 in that situation.

You are guaranteed that no two trees have the same height and there is at least
one tree needs to be cut off.*/

struct tree{
int x,y;
int h;
tree(int vx,int vy, int vh):x(vx),y(vy),h(vh){};
};
static bool cmp(const tree&a, const tree&b){ return a.h>b.h;}
int cutOffTree(vector<vector>& forest) {
int m = forest.size();
int n = (m)? forest[0].size():0;
if(!m||!n) return 0;
priority_queue<tree,vector, decltype(&cmp)> pq(cmp);
for(int i =0; i < m; i++){
for(int j = 0; j < n; j++){
if(forest[i][j] >1)
pq.emplace(tree{i,j,forest[i][j]});
}
}

    int res = 0;
    vector<pair<int,int>> dirs= {{-1,0},{1,0},{0,-1},{0,1}};
    queue<pair<int,int>> start;
    start.push(make_pair(0,0));
    while(!pq.empty()){
        auto endTree = pq.top();
        pq.pop();
        int x = endTree.x;
        int y = endTree.y;
        auto end = make_pair(x,y);
        forest[x][y]=1;
        int path = 0;
        bool find = false;
        vector<vector<int>> visited(m, vector<int>(n,0));

        while(!start.empty()){
            int sn = start.size();
            for(int i = 0; i < sn; i++){
                auto cur = start.front();
                start.pop();
                if(cur == end) {
                    find = true;
                    break;
                }else {
                    for(auto d:dirs){
                        int x1 = cur.first+d.first;
                        int y1 = cur.second+d.second;
                        if(x1>=m || y1 >=n ||x1 <0 || y1 <0|| !forest[x1][y1]||visited[x1][y1]) continue;
                        start.push(make_pair(x1,y1));
                        visited[x1][y1]=1;
                    }
                }
            }
            if(find) break;
            path++;
        }
        if(find) res += path;
        else return -1;
        start= queue<pair<int,int>> {};
        start.push(end);
    }
    return res;
}
