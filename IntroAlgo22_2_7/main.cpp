#include <deque>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> graphHalfTable(const vector<pair<int,int>>& rivalPairs, int playerCount){
    vector<vector<int>> result(playerCount, vector<int>(playerCount,0));
    for(auto p : rivalPairs){
        int player1=min(p.first, p.second), player2=max(p.first, p.second);
        result[player1][player2]=1;
    }
    return result;
}

// this solution uses BFS to traverse all nodes in graph
vector<int> solve(const vector<vector<int>>& graph){
    vector<int> result;
    vector<int> color(graph.size(), 0); // color[i]=0/1/2/4, 0=unvisited, 1=red, 2=blue

    // note: the graph may contains several sub-graphs that are not connecting each other
    // so we must use a complete for-loop
    for(int node=0;node<(int)graph.size();node++){
        // skip colored node
        if(color[node]){
            assert(color[node]);
            continue;
        }
        // visit a sub-graph
        // for the queue: we push from its front side, pop from back
        deque<int> q;
        q.push_front(node);
        color[node]=1;
        while(q.size()){
            // pop the back node as parent
            int parent=q.back();
            q.pop_back();
            // the parent must be colored
            assert(color[parent]);
            // now, go over its children
            for(int child=0;child<(int)graph[parent].size();child++){
                // skip unconnected child
                if(!graph[parent][child])
                    continue;
                // visit connected children
                if(!color[child]){
                    // if the child is not colored, color it and push it for future use
                    color[child]=(color[parent]==1?2:1);
                    q.push_front(child);
                }else{
                    // if there's a color conflict, then return an empty vector (failure status)
                    if(color[child]==color[parent]){
                        return vector<int>();
                    }
                }
            }
            // after visiting all its children, we darken its color to finalize it
            if(color[parent]==1){
                result.push_back(parent);
            }
        }
    }

    // since the failure state was returned previously, here's the successful state
    return result;
}

// this solution uses DFS to traverse all nodes in graph
vector<int> solve2(const vector<vector<int>>& graph){
    vector<int> result;
    vector<int> color(graph.size(), 0); // color[i]=0/1/2/4, 0=unvisited, 1=red, 2=blue

    for(int node=0;node<(int)graph.size();node++){
        // skip colored node
        if(color[node])
            continue;
        // visit uncolored node
        stack<int> s;
        s.push(node);
        color[node]=1;
        while(s.size()){
            int parent=s.top();
            s.pop();;
            assert(color[parent]);
            for(int child=0;child<(int)graph[parent].size();child++){
                // skip unconnected child
                if(!graph[parent][child])
                    continue;
                // deal with connected child
                if(!color[child]){
                    // paint a color
                    color[child]=(color[parent]==1?2:1);
                    s.push(child);
                }else{
                    // check color conflict
                    if(color[child]==color[parent]){
                        return vector<int>();
                    }
                }
            }
            // after traversing parent's children, push it if it's red
            if(color[parent]==1){
                result.push_back(parent);
            }
        } // end of while
    } // end of for

    return result;
}

void printResult(const vector<int>& result){
    // print the result
    if(result.size()){
        cout<<"Solution is: [";
        std::copy(result.begin(), result.end(), ostream_iterator<int>(std::cout,","));
        cout<<"\b], and all other players are in the other side."<<endl;
    }else{
        cout<<"*** no solution ***"<<endl;
    }
    cout<<endl;
}

int main()
{
    cout<<endl;

    printResult(solve(graphHalfTable({{0,0}}, 1))); // no solution

    printResult(solve(graphHalfTable({{0,1}}, 2))); // [0] or [1]

    printResult(solve(graphHalfTable({{0,1},{1,2}}, 3))); // [0,2] or [1]

    printResult(solve(graphHalfTable({{0,1},{1,2},{2,0}}, 3))); // no solution

    printResult(solve(graphHalfTable({{0,1},{0,2},{1,4},{2,3},{3,4}}, 5))); // no solution

    printResult(solve(graphHalfTable({{0,1},{1,4},{2,3},{3,4}}, 5))); // [0,4,2]

    cout<<"============================================="<<endl<<endl;

    printResult(solve2(graphHalfTable({{0,0}}, 1))); // no solution

    printResult(solve2(graphHalfTable({{0,1}}, 2))); // [0] or [1]

    printResult(solve2(graphHalfTable({{0,1},{1,2}}, 3))); // [0,2] or [1]

    printResult(solve2(graphHalfTable({{0,1},{1,2},{2,0}}, 3))); // no solution

    printResult(solve2(graphHalfTable({{0,1},{0,2},{1,4},{2,3},{3,4}}, 5))); // no solution

    printResult(solve2(graphHalfTable({{0,1},{1,4},{2,3},{3,4}}, 5))); // [0,4,2]

    return 0;
}
