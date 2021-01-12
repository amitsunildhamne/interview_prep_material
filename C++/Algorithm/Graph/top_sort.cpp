#include <bits/stdc++.h>

using namespace std;

void CreateAdjList(auto *Map, auto *PreReqList, auto *UniqueCourses)
{
	int i;
	int PreReqListSize = PreReqList->size();
	int Course;
	int PreReq;

	for (i = 0; i < PreReqListSize; ++i) {
		Course = PreReqList->at(i)[0];
		PreReq = PreReqList->at(i)[1];
		if (Map->end() == Map->find(Course)) {
			Map->insert(make_pair(Course, vector<int>()));
		}
		Map->at(Course).push_back(PreReq);
		UniqueCourses->insert(Course);
		UniqueCourses->insert(PreReq);
	}
}

bool DFS(int node, auto *Map, auto *VisitedNodes, auto *V)
{
	int DepListSize;
	int i;
	int Dep;
	bool ret = false;

	if (VisitedNodes->end() != VisitedNodes->find(node)) {
		ret = true;
		goto done;
	}

	VisitedNodes->insert(node);

	if (V->end() != V->find(node)) {
		goto done;
	}

	
	V->insert(node);

	if (Map->end() == Map->find(node)) {
		VisitedNodes->insert(node);
		goto done;
	}

	DepListSize = Map->at(node).size();

	for (i = 0; i < DepListSize; ++i) {
		Dep = Map->at(node)[i];
		ret = DFS(Dep, Map, VisitedNodes, V);
		if (true == ret) {
			goto done;
		}
	}

done:
	return ret;
}

bool TopSort(auto *PreReqList, auto *Map, auto *Order, auto *UniqueCourses)
{
	unordered_set <int> V;
	int i = 0;
	int VecSize;
	bool ret = false;

	for (auto itr = UniqueCourses->begin(); itr != UniqueCourses->end(); ++itr) {
		if (V.end() != V.find(*itr)) {
			continue;
		}
		unordered_set <int> VisitedNodes;
		ret = DFS(*itr, Map, &VisitedNodes, &V);
		if (true == ret) {
			ret = true;
			goto done;
		}
	}

done:
	return ret;
}

void PrintVec(auto *OrderList)
{
	int i;
	int OrderListSize = OrderList->size();

	for (i = 0; i < OrderListSize; ++i) {
		cout<<OrderList->at(i)<<"\t";
	}
	cout<<endl;
}

int main(void)
{
	bool Val = false;
	unordered_map <int, vector <int>> Map;
	vector<vector<int>> PreReqList
	{
		{0, 1},
		{1, 2},
		{2, 0},
	};
	vector <int> Order;
	unordered_set <int> UniqueCourses;

	CreateAdjList(&Map, &PreReqList, &UniqueCourses);
	Val = TopSort(&PreReqList, &Map, &Order, &UniqueCourses);
//	PrintVec(&Order);
	cout<<"Ans: "<< Val<<endl;
	return 0;
}
