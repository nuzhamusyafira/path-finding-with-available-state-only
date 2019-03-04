#include<stdio.h>
int c,b;
int mz[100];
char arah[100][100];
struct gr{
	int a;
	int list[100];
};
struct gr adj[100];
void addEdge(int u, int v){
	adj[u].list[adj[u].a]=v;
	adj[u].a++;
}
void printall(int u, int d, int *vis, int *pth, int ind){
	vis[u]=1;
	pth[ind]=u;
	ind++;
	int i;
	if(u==d){
		for(i=0;i<ind-1;i++){
			printf("%d ", mz[pth[i]]);
			if(arah[pth[i]][pth[i+1]]=='u') printf("-up- ");
			if(arah[pth[i]][pth[i+1]]=='d') printf("-down- ");
			if(arah[pth[i]][pth[i+1]]=='l') printf("-left- ");
			if(arah[pth[i]][pth[i+1]]=='r') printf("-right- ");
		}
		printf("%d\n\n", mz[pth[ind-1]]);
	}
	else{
		for(i=0;i<adj[u].a;i++){
			if(vis[adj[u].list[i]]!=1) printall(adj[u].list[i],d,vis,pth,ind);
		}
	}
	ind--;
	vis[u]=0;
}
void print(int s, int d){
	int visited[100];
	int path[100];
	int index=0;
	int i;
	for(i=0;i<c*b;i++) visited[i]=0;
	printall(s,d,visited,path,index);
}
int main(){
	int i,j;
	printf("Enter the size: ");
	scanf("%d %d", &c,&b);
	printf("\n");
	for(i=0;i<c;i++){
		for(j=0;j<b;j++) scanf("%d", &mz[i*c+j]);
	}
	for(i=0;i<c;i++){
		for(j=0;j<b;j++){
			int p=mz[i*c+j];
			if(p!=0){
				if(i+p<c){
					addEdge(i*c+j,(i+p)*c+j);
					arah[i*c+j][(i+p)*c+j]='d';
				} // bawah
				if(i-p>=0){
					addEdge(i*c+j,(i-p)*c+j);
					arah[i*c+j][(i-p)*c+j]='u';
				} // atas
				if(j+p<b){
					addEdge(i*c+j,i*c+(j+p));
					arah[i*c+j][i*c+(j+p)]='r';
				} // kanan
				if(j-p>=0){
					addEdge(i*c+j,i*c+(j-p));
					arah[i*c+j][i*c+(j-p)]='l';
				} // kiri
			}
		}
	}
	printf("\n");
	print(0,c*b-1);
	return 0;
}