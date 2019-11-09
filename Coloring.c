#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // malloc

//Kiem tra xem dinh u co mau c, thi co cung voi 1 dinh ke voi no khong
int kiemTra(int **a, int V, int u, int color[], int c){
	int i;
	for(i = 1; i < V; i++){
		if(a[u][i] && c == color[i])
			return 0;
	}
	return 1;
}


int toMau(int **a,int V, int color[], int u){
	
	// neu u la dinh cuoi cung thi xong
	if(u == V) return 1;
	
	int c = 1; // c la mau 1
	
	while(1){
		if(kiemTra(a, V, u, color, c)){
			color[u] = c;
			
			if(toMau(a, V, color, u+1))
				return 1;
		}
		c++;
	}
	
	return 0;
}

int thucHien(int **a, int V){
	int color[V];
	int i, j;
	
	for(i = 1; i < V; i++)
		color[i] = 0;
		
	if(toMau(a, V, color, 0))
		printf("Da thuc hien xong!");
	
	FILE *ra;
	ra = fopen("E:\\dothitomau.dot", "w");
	fprintf(ra,"graph dothi \n{\n");
	
	for(i = 1; i < V; i++){
		fprintf(ra, "\t");
		if(color[i] == 1)
			fprintf(ra, "%d [fillcolor=red, style=filled];\n", i);
		if(color[i] == 2)
			fprintf(ra, "%d [fillcolor=green, style=filled];\n", i);
		if(color[i] == 3)
			fprintf(ra, "%d [fillcolor=blue, style=filled];\n", i);
		if(color[i] == 4)
			fprintf(ra, "%d [fillcolor=yellow, style=filled];\n", i);
		if(color[i] == 5)
			fprintf(ra, "%d [fillcolor=gray, style=filled];\n", i);
		if(color[i] == 6)
			fprintf(ra, "%d [fillcolor=brown, style=filled];\n", i);
		if(color[i] == 7)
			fprintf(ra, "%d [fillcolor=violet, style=filled];\n", i);
		if(color[i] == 8)
			fprintf(ra, "%d [fillcolor=white, style=filled];\n", i);
		if(color[i] == 9)
			fprintf(ra, "%d [fillcolor=linen, style=filled];\n", i);
		if(color[i] == 10)
			fprintf(ra, "%d [fillcolor=honeydew, style=filled];\n", i);
		if(color[i] == 11)
			fprintf(ra, "%d [fillcolor=dark slate gray, style=filled];\n", i);
		if(color[i] == 12)
			fprintf(ra, "%d [fillcolor=SlateBlue, style=filled];\n", i);
		if(color[i] == 13)
			fprintf(ra, "%d [fillcolor=cyan, style=filled];\n", i);
		if(color[i] == 14)
			fprintf(ra, "%d [fillcolor=khaki, style=filled];\n", i);
		if(color[i] == 15)
			fprintf(ra, "%d [fillcolor=firebrick, style=filled];\n", i);
	}
	
	for(i = 1; i < V; i++)
		for(j = i+1; j < V; j++)
		{	
			if(a[i][j] == 1 )
				fprintf(ra, "\t%d -- %d;\n",i, j);
		}
	fprintf(ra, "}");
	fclose(ra);
	return 0;
}

int main()
{
	int **a = NULL;
	int V , E;
	FILE *vao, *ra;
	vao = fopen("C:\\Users\\Do Kien\\Desktop\\dothi.txt", "r");
	fscanf(vao,"%d", &V);
	fscanf(vao,"%d", &E);
	
	// Vi cac dinh tu 1->V chu ko phai tu 0-> V-1
	V = V+1;
	
	int i;
	a = (int **) malloc(V*sizeof(int *));
	for(i = 0; i < V; i++)
		a[i] = (int *) malloc(V*sizeof(int));
		
	// gan tat ca he so cua mang a = 0
	int j, x, y;
	for(i = 0; i < V; i++)
		for(j = 0; j < V; j++)
			a[i][j] = 0;
	
	// lay du lieu tu file dothi.txt
	for(i = 0; i < E; i++)
	{
		fscanf(vao, "%d", &x);
		fscanf(vao, "%d", &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	fclose(vao);

	thucHien(a, V);

	for(i = 0; i < V; i++)
		free(a[i]);
	free(a);
	
	getch();
 	return 0;
}

