#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

class LinkedListNode{
public:
    int val;
    LinkedListNode *next;

    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, int val){
    if(head == NULL) {
        head = new LinkedListNode(val);
    }
    else {
        LinkedListNode *end = head;
        while (end->next != NULL) {
            end = end->next;
        }
        LinkedListNode *node = new LinkedListNode(val);
        end->next = node;
    }
    return head;
}
/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/
string Check(LinkedListNode* L)
{
    bool flag = false;
    if (L==NULL || L->next==NULL) return "NO";
    LinkedListNode* fast_ptr = L;
    LinkedListNode* slow_ptr = L;
    while(fast_ptr!=NULL || fast_ptr->next!=NULL)
    {
        if(fast_ptr==slow_ptr)
        {
            flag = true;
            break;
        }
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    if (flag) return "YES";
    else return "NO";

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    string res;

    int _L_size;
    LinkedListNode* _L = NULL;
    cin >> _L_size;
    int _L_i;
    for(_L_i = 0; _L_i < _L_size; _L_i++) {
        _L = _insert_node_into_singlylinkedlist(_L, 0);
    }
    int a;
    cin >> a;
    LinkedListNode* head = _L;
    LinkedListNode* end = _L;
    if(a!=-1){
        while(a--)
            head = head->next;
        while (end->next != NULL)
            end = end->next;
        end->next = head;
    }
    res = Check(_L);
    fout << res << endl;
    fout.close();
    return 0;
}
