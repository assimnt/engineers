#include<stdio.h>
#include<conio.h>
#define V 5

void printSolution(int path[]);
 // bool is used to take decision true and false result  and its method is used for v added in index position and it is stored in path []

bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
	// its condition  is used to check previosly added adjacent vertex 
	 if (graph [ path[pos-1] ][ v ] == 0)
        return false;
 
    // it is used to the vertex has an already included or not it give true and false  so create an array to save the value of vertices 
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
    
}
 // Its recursively utility function to solve hamiltanion problem 

bool hamCycleIQRAAROOMA(bool graph[V][V], int path[], int pos)
{
    // its condition is used to check out all the vertices are included in hamiltanion cycle 
    if (pos == V)
    {
        // its condition is used to check out from the last vertex included from the first vertex 
        if ( graph[ path[pos-1] ][ path[0] ] == 1 )
           return true;
        else
          return false;
    }
 // it is used to try next vertices dont try o because it is also included 0 from starting point 
    
    for (int v = 1; v < V; v++)
    {
       // its used to check the vertex can  be added to the hamiltanion cycle
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
 
           // recursion to construct a path 
            if (hamCycleIQRAAROOMA (graph, path, pos+1) == true)
                return true;
 
          // its used to add vertex  but does not  lead a  solution 
            path[pos] = -1;
        }
    }
 
   // if it is not added vertex so it give return false 
    return false;
}
 // its function  mainly used to solve the function of to solve the problem. It returns false
  //if there is no Hamiltonian Cycle possible, otherwise return true and printh the path
  

bool hamCycle(bool graph[V][V])
{
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
        //  in first we used  vertex 0  if there is an hamiltanion cycle
		// then the path can be started from any point of the cycle as 
		//the graph is undirected 
 
    
    path[0] = 0;
    if ( hamCycleIQRAAROOMA(graph, path, 1) == false )
    {
        printf("\nSolution does not exist");
        return false;
    }
 
    printSolution(path);
    return true;
}
 // its function is used to print solution 
void printSolution(int path[])
{
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);
       
   // it print show the first vertex again 
    printf(" %d ", path[0]);
    printf("\n");
}
 

int main()
{
	int path[0],i;

    FILE *fptr;
   fptr = (fopen("C:\\muznah.txt", "w"));
   if(fptr == NULL)
   {
       printf("Error!");
     
 
 
       
   }
   
  
fprintf(fptr, "%d", &path[i]);
fprintf( fptr," %d ",& path[0]);
   
	
   // create a graph 1
   bool graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
 
  
    hamCycle(graph1);
 
  

 
 
    
 fclose(fptr);
    return 0;
}
