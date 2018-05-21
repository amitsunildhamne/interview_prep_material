#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    unordered_map <int, int> map;
    vector<vector<int>> res;
    for(int i=0; i<nums.size();++i)
    {
        map[nums[i]]=i;
    }
    for(int i=0; i<nums.size();++i)
    {
        for(int j=i;j<nums.size()-1;++j)
        {
            int x = (nums[i]+nums[j])*-1;
            if(map.count(x)>0)
            {
                int k = map[x];
                if(k>i && k>j && i!=j)
                {
                    int size = res.size();
                    res.resize(size+1);
                    cout<<"new size"<<res.size()<<" old size "<<size<<" Col size "<<res[size].size()<<endl;
                    res[size].push_back(nums[i]);
                    res[size].push_back(nums[j]);
                    res[size].push_back(nums[k]);
                }
            }
        }
    }
    return res;
}

int main()
{
  vector <int> compute = {-1,0,1,2,-1,-4};
  vector <vector<int>> res = threeSum(compute);
  for(int i=0; i<res.size();++i)
  {
    for(int j=0; j<res[i].size();++j)
    {
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
