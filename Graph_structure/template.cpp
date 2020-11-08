#include<bits/stdc++.h>
#define MAX_VERTEX_NUM  10 //The most node's number now
using namespace std;

typedef enum{DG,DN,UDG,UDN} GraphKind; //The kind of the graph
//DG(Directed graph) UDG(Undirected graph) DN(Direct net) UDN(Undirect net)
typedef char VectexData; //Assuming vertex data is char
typedef int ArcNode;//To save 1 or 0

class AdjMarix{
public:
	int vexnum, arcnum; //Graph's node number and radian number
	VectexData vexs[MAX_VERTEX_NUM];//The array to save every node
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//The Two-dimensional array to save the line
	GraphKind kind;
};

//if node V in the G, return the V'index in G , else return  NULL
int LocateVertex(AdjMarix &g, VectexData v){
	for(int i = 0; i < g.vexnum; ++i){
		if(g.vexs[i]==v){
			return i;
		}
	}
	return -1;
}
void createAdjMarixGraph(AdjMarix &g, GraphKind kind){
	int n;
	char v;
	int vi, vw; 
	g.kind = kind;
	cout << "请输入图的顶点个数：";
	cin >> n;
	g.vexnum = n;
	for(int i = 0; i < n; ++i){
		cout << "输入第" << i+1 << "个顶点的信息：" ;
		cin >> v;
		g.vexs[i] = v;
		for(int j = 0; j < n; ++j)g.arcs[i][j] = 0;//initialize arcs to 0
	}
	cout << "请输入图的边数：";
	
	int l;
	char V,W;
	cin >> l;
	g.arcnum = l;

	for(int i = 0; i < n; ++i){
		cout << "输入第" << i+1 << "条边的信息：" ;
		scanf(" %c,%c",&V,&W);
		vi = LocateVertex(g,V);// To find v'index
		vw = LocateVertex(g,W);//To find w'index
		if(vi==-1 || vw==-1)continue;
		g.arcs[vi][vw] = 1;
		if(g.kind == UDG)g.arcs[vw][vi] = 1;
		
	}
	
}
int main(){
	AdjMarix g;
	createAdjMarixGraph(g,UDG);
	cout << endl;
	for(int i = 0; i < g.vexnum ;++i){
		for(int j = 0; j < g.vexnum; ++j){
			printf("%2d",g.arcs[i][j]);
		}
		cout <<endl;
	}
	return 0;
}
