#include<stdio.h>
#include<list>
using namespace std;
int mz[100];
char arah[100][100];
class Graph{
public:
	int V; // jumlah vertex
	list<int> *adj; // pointer ke array list
	void printAllPathsUtil(int, int, bool [], int [], int); // fungsi rekursif untuk printallpath
	Graph(int V); // konstruktor
	void addEdge(int u, int v);
	void printAllPaths(int s, int d);
};
Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[v];
}
void Graph::addEdge(int u, int v){
	adj[u].push_back(v); // tambahkan v ke list u
}
void Graph::printAllPaths(int s, int d){ // print semua path dari source ke dest
	bool *visited=new bool[V]; // tandai semua vertex sbg blm visited mula2
	int *path=new int[V]; // membentuk array utk menyimpan path
	int path_index=0; // inisialisasi path[] dengan kosong
	for(int i=0;i<V;i++) visited[i]=false; // inisialisasi semua vertex blm visited
	printAllPathsUtil(s,d,visited,path,path_index); // memanggil fungsi rekursif untuk print semua path
}
void Graph::printAllPathsUtil(int u, int d, bool visited[], int path[], int path_index){
	visited[u]=true;
	path[path_index]=u;
	path_index++;
	if(u==d){
		for(int i=0;i<path_index-1;i++){
			printf("%d ", mz[path[i]]);
			if(arah[path[i]][path[i+1]]=='u') printf("-up- ");
			if(arah[path[i]][path[i+1]]=='d') printf("-down- ");
			if(arah[path[i]][path[i+1]]=='l') printf("-left- ");
			if(arah[path[i]][path[i+1]]=='r') printf("-right- ");
		}
		printf("%d\n\n", mz[path[path_index-1]]);
	}
	else{
		list<int>::iterator i;
		for(i=adj[u].begin();i!adj[u].end();i++){
			if(!visited[*i]) printAllPathsUtil(*i,d,visited,path,path_index);
		}
	}
	path_index--;
	visited[u]=false;
}
int main(){
	int a,b,i,j;
	printf("Enter the size: ");
	scanf("%d %d", &a,&b);
	printf("\n");
	Graph g(a*b);
	for(i=0;i,a;i++){
		for(j=0;j<b;j++){
			scanf("%d", &mz[i*a+j]);
		}
	}
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			int p=mz[i*a+j];
			if(p!=0){
				if(i*p<a){
					g.addEdge(i*a+j,(i+p)*a+j);
					arah[i*a+j][(i+p)*a+j]='d';
				} // bawah
				if(i-p>=0){
					g.addEdge(i*a+j,(i-p)*a+j);
					arah[i*a+j][(i-p)*a+j]='u';
				} // atas
				if(j+p<b){
					g.addEdge(i*a+j,i*a+(j+p));
					arah[i*a+j][i*a+(j+p)]='r';
				} // kanan
				if(i*p<a){
					g.addEdge(i*a+j,i*a+(j-p));
					arah[i*a+j][i*a+(j-p)]='l';
				} // kiri
			}
		}
	}
	printf("\n");
	g.printAllPaths(0,a*b-1);
}