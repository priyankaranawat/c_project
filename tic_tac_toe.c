#include<stdio.h>
int main()
{
    int ch ;
   do
    {
        system("cls");
        printf("############################################################################ Tic Tac Toe ###############################################################################");
        printf("\n\n\t\t\t\t\t\t\t\t\tEnter your choice\n\n\t\t\t\t\t\t\t\t\t1.Want to play with smart computer \n\t\t\t\t\t\t\t\t\t2.Want to play with evil computer \n\t\t\t\t\t\t\t\t\t3.Want to play with player\n\t\t\t\t\t\t\t\t\t4.Exit \n");
        fflush(stdin);
        scanf("%d",&ch);
        system("cls");
        switch(ch)
        {
            case 1:smartcomp();
                    break;
            case 2:evilcomp();
                    break;
            case 3:player();
                    break;
            case 4:printf("\t\t\t\t\t\t\t\t\tThanks !");
                    break;
            default:printf("\n\t\t\t\t\t\t\t\t\tInvalid choice");getch();
        }
    }while(ch!=4);

    return 0;
}
void smartcomp()
{
    char p[50],arr[3][3];
    int i,j,x,k=1,count=1,move=1,flag,val_inserted=0;
    printf("############################################################################ Tic Tac Toe ###############################################################################");
    printf("\nEnter your name ");
    fflush(stdin);
    fgets(p,50,stdin);
    p[strlen(p)-1]='\0';
    for(i=0;i<3;i++)                                    //storing values in array
    {
        for(j=0;j<3;j++)
        {
            arr[i][j]=k;
            k++;
        }
    }
    while(count<=9)
    {
        system("cls");
        printf("############################################################################ Tic Tac Toe ###############################################################################");
        printf("\n\n%s -> X \nSmart computer -> 0",p);
        count++;
        printf("\n\n\n=========================\n|\t|\t|       |\n|\t|\t|\t|\n|");
        for(i=0;i<3;i++)                            //DISPLAYING THE ARRAY
        {
            for(j=0;j<3;j++)
            {
                if(arr[i][j]!='X')
                    printf("  %d    |",arr[i][j]);
                else
                    printf("  %c    |",arr[i][j]);

            }
            printf("\n|\t|\t|\t|\n|");
        }
        printf("=======================|\n");
        if(move==1)                                             ////FIRST PLAYER's chance
        {
             do
            {
                flag=0;
                printf("\n%s's turn ",p);           //FIRST PLAYER's chance
                scanf("%d",&x);
                for(i=0;i<3;i++)                     //check whether that place is already occupied or not,if not input value again
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]==x)
                         {
                            arr[i][j]='X';
                            flag=1;
                            break;
                         }
                    }
                    if(flag==1)
                        break;
                }
            }while(flag==0);

            if(arr[0][0]=='X'&&arr[0][1]=='X'&&arr[0][2]=='X'||arr[1][0]=='X'&&arr[1][1]=='X'&&arr[1][2]=='X'||arr[2][0]=='X'&&arr[2][1]=='X'&&arr[2][2]=='X'||arr[0][0]=='X'&&arr[1][0]=='X'&&arr[2][0]=='X'||arr[0][1]=='X'&&arr[1][1]=='X'&&arr[2][1]=='X'||arr[0][2]=='X'&&arr[1][2]=='X'&&arr[2][2]=='X'||arr[0][0]=='X'&&arr[1][1]=='X'&&arr[2][2]=='X'||arr[0][2]=='X'&&arr[1][1]=='X'&&arr[2][0]=='X')
            {
                system("cls");
                printf("\n\n\n=========================\n|\t|\t|       |\n|\t|\t|\t|\n|");
                for(i=0;i<3;i++)                            //DISPLAYING THE ARRAY
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]!='X')
                            printf("  %d    |",arr[i][j]);
                        else
                            printf("  %c    |",arr[i][j]);
                    }
                    printf("\n|\t|\t|\t|\n|");
                }
                printf("=======================|\n");
                printf("\n\n %s won!",p);getch();
                count--;                                    //if count==10,then count-- ,so that 'game draw' is not displayed
                break;
            }
            move=2;
            continue;
        }
        if(move==2)                                             //smart computer's chance
        {
            flag=0;
            val_inserted=0 ;                                                                      // smart comp chooses a move to win
            for(i=0;i<3;i++)                                                   //check rows and put 0 where required (making smart comp win)
            {
            flag=0;
                for(j=0;j<3;j++)
                {
                    if(arr[i][j]==0)
                    flag++;
                }
                if(flag==2)
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]!='X'&&arr[i][j]!=0)
                        {
                            arr[i][j]=0;
                            val_inserted=1;                      // indicator that 0 has been inserted
                            break;
                        }
                    }
                }
            }

            if(val_inserted==0)                                 //if 0 not entered in any row
            {
                for(j=0;j<3;j++)                                //check columns and put 0 where required (making smart comp win)
                {
                    flag=0;
                    for(i=0;i<3;i++)
                    {
                        if(arr[i][j]==0)
                        flag++;
                    }
                    if(flag==2)
                    {
                        for(i=0;i<3;i++)
                        {
                            if(arr[i][j]!='X'&&arr[i][j]!=0)
                            {
                                arr[i][j]=0;
                                val_inserted=1;break;
                            }

                        }
                    }
                    if(val_inserted==1)break;
                }
            }

             flag=0;
            if(val_inserted==0)
            {
                for(i=0;i<3;i++)                                        //check right diagonal and put 0 where required (making smart comp win)
                {
                    if(arr[i][i]==0)
                        flag++;
                }
                if(flag==2)
                {
                    for(i=0;i<3;i++)
                    {
                        if(arr[i][i]!='X'&&arr[i][j]!=0)
                         {
                            arr[i][i]=0;
                            val_inserted=1;
                            break;
                         }
                    }
                }
            }

             if(val_inserted==0)
           {
                if(arr[0][2]==0&&arr[1][1]==0)                          //check left diagonal and put 0 where required (making smart comp win)
                {
                    arr[2][0]=0; val_inserted=1;
                }
                if(arr[2][0]==0&&arr[1][1]==0)
                {
                    arr[0][2]=0; val_inserted=1;
                }
                if(arr[0][2]==0&&arr[2][0]==0)
                {
                    arr[1][1]=0; val_inserted=1;
                }
            }

            if(val_inserted==0)
            {                                                                       //if smart comp is not winning in any case ,stop opp player from wininning
                 for(i=0;i<3;i++)                                                   //check rows and put 0 where required (avoid letting opp player win)
                {
                flag=0;
                for(j=0;j<3;j++)
                {
                    if(arr[i][j]=='X')
                        flag++;
                }
                if(flag==2)
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]!='X'&&arr[i][j]!=0)
                         {
                            arr[i][j]=0;
                            val_inserted=1;                      // indicator that 0 has been inserted
                            break;
                         }
                    }
                }
                }

            }

            if(val_inserted==0)                                 //if 0 not entered in any row
            {
                for(j=0;j<3;j++)                                //check columns and put 0 where required (avoid letting opp player win)
                {
                    flag=0;
                    for(i=0;i<3;i++)
                    {
                        if(arr[i][j]=='X')
                        flag++;
                    }
                    if(flag==2)
                    {
                        for(i=0;i<3;i++)
                        {
                            if(arr[i][j]!='X'&&arr[i][j]!=0)
                            {
                                arr[i][j]=0;
                                val_inserted=1;break;
                            }

                        }
                    }
                    if(val_inserted==1)break;
                }
            }

            flag=0;
            if(val_inserted==0)
            {
                for(i=0;i<3;i++)                                        //check right diagonal and put 0 where required (avoid letting opp player win)
                {
                    if(arr[i][i]=='X')
                        flag++;
                }
                if(flag==2)
                {
                    for(i=0;i<3;i++)
                    {
                        if(arr[i][i]!='X'&&arr[i][i]!=0)
                         {
                            arr[i][i]=0;
                            val_inserted=1;
                            break;
                         }
                    }
                }
            }
           if(val_inserted==0)
           {
                if(arr[0][2]=='X'&&arr[1][1]=='X')                          //check left diagonal and put 0 where required (avoid letting opp player win)
                {
                    arr[2][0]=0; val_inserted=1;
                }
                if(arr[2][0]=='X'&&arr[1][1]=='X')
                {
                    arr[0][2]=0; val_inserted=1;
                }
                if(arr[0][2]=='X'&&arr[2][0]=='X')
                {
                    arr[1][1]=0; val_inserted=1;
                }
            }





                flag=0;
                if(val_inserted==0)                                            //if neither of them are in a position to win ,then insert 0 sequentially where there is none
                {
                for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]!='X'&&arr[i][j]!=0)
                        {
                            arr[i][j]=0;
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1)
                        break;
                }
            }

             if((arr[0][0]==0&&arr[0][1]==0&&arr[0][2]==0)||(arr[1][0]==0&&arr[1][1]==0&&arr[1][2]==0)||(arr[2][0]==0&&arr[2][1]==0&&arr[2][2]==0)||(arr[0][0]==0&&arr[1][0]==0&&arr[2][0]==0)||(arr[0][1]==0&&arr[1][1]==0&&arr[2][1]==0)||(arr[0][2]==0&&arr[1][2]==0&&arr[2][2]==0)||(arr[0][0]==0&&arr[1][1]==0&&arr[2][2]==0)||(arr[0][2]==0&&arr[1][1]==0&&arr[2][0]==0))
             {
                system("cls");
                 printf("\n\n\n=========================\n|\t|\t|       |\n|\t|\t|\t|\n|");
                 for(i=0;i<3;i++)                            //DISPLAYING THE ARRAY
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]!='X')
                            printf("  %d    |",arr[i][j]);
                        else
                            printf("  %c    |",arr[i][j]);
                    }
                    printf("\n|\t|\t|\t|\n|");
                }
                printf("=======================|\n");
                printf("\n\n Smart computer won!");getch();count--;                  //if count==10,then count-- ,so that 'game draw' is not displayed
                break;
            }
            move=1;                                                             //because next is player turn
        }
    }
    if(count==10)
    {
        printf("\nGame draw!");getch();
    }
     }

void evilcomp()
{
    char p[50],arr[3][3];
    int i,j,x,k=1,count=1,move=1,flag,val_inserted=0,mark=0;
    printf("############################################################################ Tic Tac Toe ###############################################################################");
    printf("\nEnter your name ");
    fflush(stdin);
    fgets(p,50,stdin);
    p[strlen(p)-1]='\0';
    for(i=0;i<3;i++)                                    //storing values in array
    {
        for(j=0;j<3;j++)
        {
            arr[i][j]=k;
            k++;
        }
    }
    while(count<=9)
    {
        system("cls");
        printf("############################################################################ Tic Tac Toe ###############################################################################");
        printf("\n\n%s -> X \nEvil computer -> 0",p);
        count++;
        printf("\n\n\n=========================\n|\t|\t|       |\n|\t|\t|\t|\n|");
        for(i=0;i<3;i++)                            //DISPLAYING THE ARRAY
        {
            for(j=0;j<3;j++)
            {
                if(arr[i][j]!='X')
                    printf("  %d    |",arr[i][j]);
                else
                    printf("  %c    |",arr[i][j]);

            }
            printf("\n|\t|\t|\t|\n|");
        }
        printf("=======================|\n");
        if(move==1)                                             ////FIRST PLAYER's chance
        {
             do
            {
                flag=0;
                printf("\n%s's turn ",p);           //FIRST PLAYER's chance
                scanf("%d",&x);
                for(i=0;i<3;i++)                     //check whether that place is already occupied or not,if not input value again
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]==x)
                         {
                            arr[i][j]='X';
                            flag=1;
                            break;
                         }
                    }
                    if(flag==1)
                        break;
                }
            }while(flag==0);

            if(arr[0][0]=='X'&&arr[0][1]=='X'&&arr[0][2]=='X'||arr[1][0]=='X'&&arr[1][1]=='X'&&arr[1][2]=='X'||arr[2][0]=='X'&&arr[2][1]=='X'&&arr[2][2]=='X'||arr[0][0]=='X'&&arr[1][0]=='X'&&arr[2][0]=='X'||arr[0][1]=='X'&&arr[1][1]=='X'&&arr[2][1]=='X'||arr[0][2]=='X'&&arr[1][2]=='X'&&arr[2][2]=='X'||arr[0][0]=='X'&&arr[1][1]=='X'&&arr[2][2]=='X'||arr[0][2]=='X'&&arr[1][1]=='X'&&arr[2][0]=='X')
            {
                system("cls");
                printf("\n\n\n=========================\n|\t|\t|       |\n|\t|\t|\t|\n|");
                for(i=0;i<3;i++)                            //DISPLAYING THE ARRAY
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]!='X')
                            printf("  %d    |",arr[i][j]);
                        else
                            printf("  %c    |",arr[i][j]);
                    }
                    printf("\n|\t|\t|\t|\n|");
                }
                printf("=======================|\n");
                printf("\n\n %s won!",p);getch();
                count--;                                    //if count==10,then count-- ,so that 'game draw' is not displayed
                break;
            }
            move=2;
            continue;
        }

        if(move==2)                                             //smart computer's chance
        {
            flag=0;                                                              // smart comp chooses a move to win
            for(i=0;i<3;i++)                                                   //check rows and put 0 where required (making smart comp win)
            {
            flag=0;
                for(j=0;j<3;j++)
                {
                    if(arr[i][j]==0)
                    flag++;
                }
                if(flag==2)
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]!='X'&&arr[i][j]!=0)
                        {
                            arr[i][j]=0;val_inserted=1;
                            break;
                        }
                    }
                }
            }

                mark=0;                                 //indicator only
                for(j=0;j<3;j++)                                //check columns and put 0 where required (making smart comp win)
                {
                    flag=0;
                    for(i=0;i<3;i++)
                    {
                        if(arr[i][j]==0)
                        flag++;
                    }
                    if(flag==2)
                    {
                        for(i=0;i<3;i++)
                        {
                            if(arr[i][j]!='X'&&arr[i][j]!=0)
                            {
                                arr[i][j]=0; val_inserted=1;
                                mark=1;
                                break;
                            }

                        }
                    }
                    if(mark==1)break;
                }

             flag=0;
                for(i=0;i<3;i++)                                        //check right diagonal and put 0 where required (making smart comp win)
                {
                    if(arr[i][i]==0)
                        flag++;
                }
                if(flag==2)
                {
                    for(i=0;i<3;i++)
                    {
                        if(arr[i][i]!='X'&&arr[i][j]!=0)
                         {
                            arr[i][i]=0; val_inserted=1;
                            break;
                         }
                    }
                }



                if(arr[0][2]==0&&arr[1][1]==0)                          //check left diagonal and put 0 where required (making smart comp win)
                {
                    arr[2][0]=0; val_inserted=1;
                }
                if(arr[2][0]==0&&arr[1][1]==0)
                {
                    arr[0][2]=0; val_inserted=1;
                }
                if(arr[0][2]==0&&arr[2][0]==0)
                {
                    arr[1][1]=0; val_inserted=1;
                }



                                                                                //if smart comp is not winning in any case ,stop opp player from winning
                for(i=0;i<3;i++)                                                   //check rows and put 0 where required (avoid letting opp player win)
                {
                    flag=0;
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]=='X')
                            flag++;
                    }
                    if(flag==2)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(arr[i][j]!='X'&&arr[i][j]!=0)
                            {
                                arr[i][j]=0; val_inserted=1;
                                break;
                            }
                        }
                    }
                }



            mark=0;                                 //indicator only
            for(j=0;j<3;j++)                                //check columns and put 0 where required (avoid letting opp player win)
            {
                flag=0;
                for(i=0;i<3;i++)
                {
                    if(arr[i][j]=='X')
                    flag++;
                }
                if(flag==2)
                {
                    for(i=0;i<3;i++)
                    {
                        if(arr[i][j]!='X'&&arr[i][j]!=0)
                        {
                            arr[i][j]=0; val_inserted=1;
                            mark=1;break;
                        }
                    }
                }
                    if(mark==1)break;
            }


            flag=0;
            for(i=0;i<3;i++)                                        //check right diagonal and put 0 where required (avoid letting opp player win)
            {
                if(arr[i][i]=='X')
                    flag++;
            }
            if(flag==2)
            {
                for(i=0;i<3;i++)
                {
                    if(arr[i][i]!='X'&&arr[i][j]!=0)
                        {
                        arr[i][i]=0; val_inserted=1;
                        break;
                        }
                }
            }


                if(arr[0][2]=='X'&&arr[1][1]=='X')                          //check left diagonal and put 0 where required (avoid letting opp player win)
                {
                    arr[2][0]=0; val_inserted=1;
                }
                if(arr[2][0]=='X'&&arr[1][1]=='X')
                {
                    arr[0][2]=0; val_inserted=1;
                }
                if(arr[0][2]=='X'&&arr[2][0]=='X')
                {
                    arr[1][1]=0; val_inserted=1;
                }


                flag=0;
                if(val_inserted==0)                                            //if neither of them are in a position to win ,then insert 0 sequentially where there is none
                {
                    for(i=0;i<3;i++)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(arr[i][j]!='X'&&arr[i][j]!=0)
                            {
                                arr[i][j]=0;
                                flag=1;
                                break;
                            }
                        }
                        if(flag==1)
                            break;
                    }
                }

             if((arr[0][0]==0&&arr[0][1]==0&&arr[0][2]==0)||(arr[1][0]==0&&arr[1][1]==0&&arr[1][2]==0)||(arr[2][0]==0&&arr[2][1]==0&&arr[2][2]==0)||(arr[0][0]==0&&arr[1][0]==0&&arr[2][0]==0)||(arr[0][1]==0&&arr[1][1]==0&&arr[2][1]==0)||(arr[0][2]==0&&arr[1][2]==0&&arr[2][2]==0)||(arr[0][0]==0&&arr[1][1]==0&&arr[2][2]==0)||(arr[0][2]==0&&arr[1][1]==0&&arr[2][0]==0))
             {
                system("cls");
                 printf("\n\n\n=========================\n|\t|\t|       |\n|\t|\t|\t|\n|");
                 for(i=0;i<3;i++)                            //DISPLAYING THE ARRAY
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]!='X')
                            printf("  %d    |",arr[i][j]);
                        else
                            printf("  %c    |",arr[i][j]);
                    }
                    printf("\n|\t|\t|\t|\n|");
                }
                printf("=======================|\n");
                printf("\n\n Evil computer won!");getch();count--;                  //if count==10,then count-- ,so that 'game draw' is not displayed
                break;
            }
            move=1;                                                             //because next is player turn
        }                                                                        //end of if(move==2)
    }                                                                           //end of while loop
    if(count==10)
     {
          printf("\nGame draw!");getch();
     }
}                                                                                //end of evil computer function

void player()
{
    char p1[50],p2[50],arr[3][3];
    int i,j,k=1,x,count=1,move=1,flag;
    printf("############################################################################ Tic Tac Toe ###############################################################################");
    printf("\nEnter name of first player ");
    fflush(stdin);
    fgets(p1,50,stdin);
    printf("\nEnter name of second player ");
    fgets(p2,50,stdin);
    p1[strlen(p1)-1]='\0';
    p2[strlen(p2)-1]='\0';
    for(i=0;i<3;i++)                        //STORING VALUES IN ARRAY
    {
        for(j=0;j<3;j++)
        {
            arr[i][j]=k;
            k++;
        }
    }

    while(count<=9)
    {
        system("cls");
        printf("############################################################################ Tic Tac Toe ###############################################################################");
        printf("\n\n%s -> X \n%s -> 0",p1,p2);
        count++;
         printf("\n\n\n=========================\n|\t|\t|       |\n|\t|\t|\t|\n|");
        for(i=0;i<3;i++)                            //DISPLAYING THE ARRAY
        {
            for(j=0;j<3;j++)
            {
                if(arr[i][j]!='X')
                    printf("  %d    |",arr[i][j]);
                else
                    printf("  %c    |",arr[i][j]);

            }
            printf("\n|\t|\t|\t|\n|");
        }
        printf("=======================|\n");
        if(move==1)
        {
            do                                                //check whether entered move is valid or not
            {
                flag=0;
                printf("\n%s's turn ",p1);           //FIRST PLAYER's chance
                scanf("%d",&x);
                for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]==x)
                         {
                             flag=1;
                             break;
                         }
                    }
                    if(flag==1)
                        break;
                }
            }while(flag==0);
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    if(arr[i][j]==x)
                        arr[i][j]='X';
                }
            }
            if(arr[0][0]=='X'&&arr[0][1]=='X'&&arr[0][2]=='X'||arr[1][0]=='X'&&arr[1][1]=='X'&&arr[1][2]=='X'||arr[2][0]=='X'&&arr[2][1]=='X'&&arr[2][2]=='X'||arr[0][0]=='X'&&arr[1][0]=='X'&&arr[2][0]=='X'||arr[0][1]=='X'&&arr[1][1]=='X'&&arr[2][1]=='X'||arr[0][2]=='X'&&arr[1][2]=='X'&&arr[2][2]=='X'||arr[0][0]=='X'&&arr[1][1]=='X'&&arr[2][2]=='X'||arr[0][2]=='X'&&arr[1][1]=='X'&&arr[2][0]=='X')
            {
                system("cls");
                printf("\n\n\n=========================\n|\t|\t|       |\n|\t|\t|\t|\n|");
                for(i=0;i<3;i++)                            //DISPLAYING THE ARRAY
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]!='X')
                            printf("  %d    |",arr[i][j]);
                        else
                            printf("  %c    |",arr[i][j]);
                    }
                    printf("\n|\t|\t|\t|\n|");
                }
                printf("=======================|\n");
                printf("\n\n %s won!",p1);getch();
                count--;                                    //if count==10,then count-- ,so that 'game draw' is not displayed
                break;
            }
            move=2;
            continue;
        }                                                   //if move==1 end
        if(move==2)                                          //Second player's chance
        {
            do                                             //check if entered number is valid or not
             {
                flag=0;
                printf("\n%s's turn ",p2);
                scanf("%d",&x);
                for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]==x)
                         {
                             flag=1;
                             break;
                         }
                    }
                    if(flag==1)
                        break;
                }
            }while(flag==0);
            for(i=0;i<3;i++)                            //MARK 0 AT THE entered place
            {
                for(j=0;j<3;j++)
                {
                    if(arr[i][j]==x)
                        arr[i][j]=0;
                }
            }
            if((arr[0][0]==0&&arr[0][1]==0&&arr[0][2]==0)||(arr[1][0]==0&&arr[1][1]==0&&arr[1][2]==0)||(arr[2][0]==0&&arr[2][1]==0&&arr[2][2]==0)||(arr[0][0]==0&&arr[1][0]==0&&arr[2][0]==0)||(arr[0][1]==0&&arr[1][1]==0&&arr[2][1]==0)||(arr[0][2]==0&&arr[1][2]==0&&arr[2][2]==0)||(arr[0][0]==0&&arr[1][1]==0&&arr[2][2]==0)||(arr[0][2]==0&&arr[1][1]==0&&arr[2][0]==0))
            {
                system("cls");
                 printf("\n\n\n=========================\n|\t|\t|       |\n|\t|\t|\t|\n|");
                 for(i=0;i<3;i++)                            //DISPLAYING THE ARRAY
                {
                    for(j=0;j<3;j++)
                    {
                        if(arr[i][j]!='X')
                            printf("  %d    |",arr[i][j]);
                        else
                            printf("  %c    |",arr[i][j]);
                    }
                    printf("\n|\t|\t|\t|\n|");
                }
                printf("=======================|\n");
                printf("\n\n %s won!",p2);getch();
                break;
            }
            move=1;
        }                                           //If (move==2)end
    }                                                //while end
    if(count==10)
       {
           printf("Game draw!");getch();
       }
}                                                                        //func end

