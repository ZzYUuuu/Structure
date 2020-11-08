#include<bits/stdc++.h>
#define MAX_VERTEX_NUM  10 //The most node's number now
using namespace std;

typedef enum{DG,DN,UDG,UDN} GraphKind; //The kind of the graph
//DG(Directed graph) UDG(Undirected graph) DN(Direct net) UDN(Undirect net)
typedef char VertexData; //Assuming vertex data is char

//This is the head of the LinkeNode
class ArcNode{
public:
    int adjvex;
    ArcNode *nextarc;
    int weight;
};
//node
class VertexNode{
public:
    VertexData data;
    ArcNode *firstarc;
};

//This is the graph
class AdjList{
public:
    VertexNode vexs[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;
};

int LocateVertex(AdjList &g, VertexData v){
	for(int i = 0; i < g.vexnum; ++i){
		if(g.vexs[i].data==v){
			return i;
		}
	}
	return -1;
}
//return 
VertexData GetVertex(const AdjList &g, int i){
    return g.vexs[i].data;
}


void createAdjLinkGraph(AdjList &g, GraphKind kind){
	int n;
	char v;
	int vi, vw;
    ArcNode *p;

	g.kind = kind;
	cout << "输入结点数";
	cin >> n;
	g.vexnum = n;
	for(int i = 0; i < n; ++i){
		cout << "输入第" << i+1 << "个结点" ;
		cin >> v;
		g.vexs[i].data = v;
        g.vexs[i].firstarc = NULL;
	}

    int l;
    char V,W;
	cout << "输入连线数:";
	cin >> l;
	for(int i = 0; i < l; ++i){
		cout << "输入第" << i+1 << "个数据" ;
		scanf(" %c,%c",&V,&W);
		vi = LocateVertex(g,V);// To find v'index
		vw = LocateVertex(g,W);//To find w'index
		if(vi==-1 || vw==-1)continue;
		p = new ArcNode;
        p->adjvex = vw;
		p->nextarc = g.vexs[vi].firstarc;
        g.vexs[vi].firstarc = p;
        if(g.kind == UDG)//Undirect graph
        {
            p = new ArcNode;
            p->adjvex = vi;
            p->nextarc = g.vexs[vw].firstarc;
            g.vexs[vw].firstarc = p;
        }
	}
}
int main(){
    AdjList g;
	createAdjLinkGraph(g,UDG);
    ArcNode *p;
	cout << endl;
	for(int i = 0; i < g.vexnum ;++i){
        //output vertex data
        cout << g.vexs[i].data;
        p = g.vexs[i].firstarc;
        while(p!=NULL){
            cout << "->" <<GetVertex(g,p->adjvex) ;
            p = p->nextarc;
        }
		cout <<endl;
	}
	return 0;
}
