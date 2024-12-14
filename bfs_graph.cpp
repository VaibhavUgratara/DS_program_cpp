#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class GraphNode{

    public:
        char val;
        vector <GraphNode*> edges;
        GraphNode(char c):val(c){}

};


class Graph{

    private:
        vector<GraphNode*> nodes;

    public:
        ~Graph(){
            for(auto i: nodes) delete i;
        }

        void addNode(char c){
            nodes.push_back(new GraphNode(c));
        }

        void addEdge(int from, int to){

            if(from < 0 || from >= nodes.size() || to < 0 || to >= nodes.size()){
                cout<<"Invalid parameters"<<endl;
                return;
            }

            else if( find(nodes[from]->edges.begin(), nodes[from]->edges.end(), nodes[to]) != nodes[from]->edges.end() ){
                cout<<"Edge already present"<<endl;
                return;
            }

            nodes[from]->edges.push_back(nodes[to]);

        }

        void bfs (){

            vector <GraphNode*> visited;
            vector <GraphNode*> queue;
            
            for (auto crrNode : nodes){
                if(find(visited.begin(),visited.end(),crrNode)!=visited.end()) continue;

                queue.push_back(crrNode);

                while(!queue.empty()){
                    
                    GraphNode *activeNode = queue[0];

                    queue.erase(queue.begin());

                    if(find(visited.begin(),visited.end(),activeNode)==visited.end()){
                        visited.push_back(activeNode);
                    }

                    for(auto adjNode : activeNode->edges){
                        if(find(visited.begin(),visited.end(),adjNode)==visited.end()){

                            queue.push_back(adjNode);

                        }
                    }
                }

            }

            for(auto i: visited){
                cout<<i->val<<" ";
            }
            cout<<endl;

        }




};



int main(){

    Graph g;

    g.addNode('A');//0
    g.addNode('B');//1
    g.addNode('C');//2
    g.addNode('D');//3
    g.addNode('E');//4
    g.addNode('F');//5
    g.addNode('G');//6
    g.addNode('H');//7

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(0, 6);

    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(1, 6);
    g.addEdge(1, 7);

    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 7);

    g.addEdge(3,2);
    g.addEdge(3,4);

    g.addEdge(4,0);
    g.addEdge(4,3);
    g.addEdge(4,5);

    g.addEdge(5,1);
    g.addEdge(5,4);

    g.addEdge(6,0);
    g.addEdge(6,1);

    g.addEdge(7,1);
    g.addEdge(7,2);


    g.bfs();

    return 0;
}