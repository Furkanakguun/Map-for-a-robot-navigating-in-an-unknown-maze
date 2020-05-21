#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int SIZE = 9;

int splitToken(char const *input, char const delim, char *Commands[]);


int main()
{
    int west,east,north,south;
    //Construct Maze
    char* maze[SIZE][SIZE];
    int i, j;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            maze[i][j] = "u";
        }
    }
    //Put robot into the middle
    int currentXindex = SIZE/2;
    int currentYindex = SIZE/2;
    maze[currentXindex][currentYindex] = ".";
    int cikis = 0;
    char command[100];

    while(fgets(command, sizeof(command), stdin))
    {
        char *pos;



        char * commandSplitted[4];




        if(strcmp(command,"\n") == 0){
           break;
        }

        if ((pos=strchr(command, '\n')) != NULL) *pos = '\0';



        if(strcmp(command,"gowest") == 0){

            currentYindex = currentYindex - 1;
            maze[currentXindex][currentYindex] = ".";

        }else  if(strcmp(command,"goeast") == 0){

            currentYindex = currentYindex + 1;
            maze[currentXindex][currentYindex] = ".";

        }else  if(strcmp(command,"gonorth") == 0){

            currentXindex = currentXindex - 1;
            maze[currentXindex][currentYindex] = ".";

        }else if(strcmp(command,"gosouth") == 0){

            currentXindex = currentXindex + 1;
            maze[currentXindex][currentYindex] = ".";

        }else{

        splitToken(command,' ',commandSplitted);

        printf("");
        maze[currentXindex][currentYindex-1] = commandSplitted[0];
        maze[currentXindex-1][currentYindex] = commandSplitted[1];
        maze[currentXindex][currentYindex+1] = commandSplitted[2];
        maze[currentXindex+1][currentYindex] = commandSplitted[3];


        }


        //Displaying array elements
    }
    //End of While loop
    //-------------------------------------------------------------------------\\
    //Displaying array elements
    for(i=0; i<SIZE; i++)
    {
        int flag = 0;
        for(j=0; j<SIZE; j++)
        {
           if(strcmp(maze[i][j],"w")== 0 || strcmp(maze[i][j],"o")== 0){

             north = i;
             flag = 1;
             break;
           }
        }
        if(flag == 1) break;
    }

    for(j=0; j<SIZE; j++)
    {
         int flag = 0;
        for(i=0; i<SIZE; i++)
        {
           if(strcmp(maze[i][j],"w")==0 || strcmp(maze[i][j],"o")==0){

            west = j;
            flag = 1;
            break;
           }
        }
        if(flag == 1) break;
    }
    for(i=SIZE-1; i>0; i--)
    {
        int flag = 0;
        for(j=SIZE-1; j>0; j--)
        {
           if(strcmp(maze[i][j],"w")== 0 || strcmp(maze[i][j],"o")== 0){

             south = i;
             flag = 1;
             break;
           }
        }
        if(flag == 1) break;
    }
    for(j=SIZE-1; j>0; j--)
    {
         int flag = 0;
        for(i=SIZE-1; i>0; i--)
        {
           if(strcmp(maze[i][j],"w")==0 || strcmp(maze[i][j],"o")==0){

            east = j;
            flag = 1;
            break;
           }
        }
        if(flag == 1) break;
    }





    int ust = 0;
    int yan = 0;

    if(west>east) yan = west;
    else yan = east;

    if(north>south) ust = north;
    else ust =south;

    //Displaying Maze
        for(i=north; i<= south; i++)
        {
            for(j=west; j<= east; j++)
            {
                if(strcmp(maze[i][j],"o") == 0)
                {
                printf(" ");
                }else{
                    printf("%s", maze[i][j]);
                }
                if(j==east)
                {
                    printf("\n");
                }

            }
        }

    return 0;
}









int splitToken(char const *input, char const delim, char *Commands[])
{

    char *tofree = malloc(sizeof(char) * strlen(input));

    if (input != NULL)
    {
        char *token;

        strcpy(tofree, input);
        token = strtok(tofree, &delim);
        if (token == NULL)
        {
            printf("%s is not a valid command. Try again\n", input);
            return 0;
        }
        Commands[0] = malloc(sizeof(char) * strlen(token));
        strcpy(Commands[0], token);

        int i = 1;
        while (token != NULL)
        {
            token = strtok(NULL, &delim);
            if (token == NULL)
            {
                break;
            }
            Commands[i] = malloc(sizeof(char) * strlen(token));
            strcpy(Commands[i], token);
            i++;
        }
        return i;
    }
}

