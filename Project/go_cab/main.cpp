/* Author: Akshat Agarwal */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include<time.h>
#include <malloc.h>

FILE *fp;
char user[50],pass[50];

struct node
{
    char source[25];
    char destination[25];
    int day,month;
    struct node *link;

};
typedef struct node *NODE;
NODE insert(NODE first);
NODE display(NODE first);
NODE del(NODE first);
void signup(void);
int login(void);
void ridenow();
void ridelater();

int main(void)
{
    int choice1,choice2,ilogin;
    FILE *fp2;
    printf("---------------------------------------------------------------");
    printf("\n                          GO CAB                        \n");
    printf("---------------------------------------------------------------");
    printf("\nW");Sleep(100);printf("E");Sleep(100);
    printf("L");Sleep(100);printf("C");Sleep(100);
    printf("O");Sleep(100);printf("M");Sleep(100);
    printf("E");Sleep(100);printf(" ");Sleep(100);
    printf("T");Sleep(100);printf("O");Sleep(100);
    printf(" ");Sleep(100);printf("G");Sleep(100);
    printf("O");Sleep(100);printf(" ");Sleep(100);
    printf("C");Sleep(100);printf("A");Sleep(100);
    printf("B");Sleep(100);printf(" ");Sleep(100);
    printf("T");Sleep(100);printf("A");Sleep(100);
    printf("X");Sleep(100);printf("I");Sleep(100);
    printf(" ");Sleep(100);printf("S");Sleep(100);
    printf("E");Sleep(100);printf("R");Sleep(100);
    printf("V");Sleep(100);printf("I");Sleep(100);
    printf("C");Sleep(100);printf("E");Sleep(100);
    printf(".");Sleep(100);printf(".");Sleep(100);
    Sleep(500);
    while(1)
    {
        printf("\n\n\nPlease select your choice\n\t1.LOG IN\n\t2.SIGN UP\n\t3.EXIT\n");
        scanf("%d",&choice1);
        switch(choice1)
        {

            case 1: ilogin=login();
                    if(ilogin==-1)
                    {
                        continue;
                    }
                    break;

            case 2: signup();
                    break;

            case 3: printf("\nThank you for using GO CAB");
                    exit(0);

            default: printf("\nInvalid choice!");
                     break;
        }

        while(1)
        {
            printf("\nEnter your choice\n");
            printf("1.RIDE NOW\n2.RIDE LATER\n3.LOGOUT\n");
            scanf("%d",&choice2);
            switch(choice2)
            {
                case 1: ridenow();
                        break;

                case 2: ridelater();
                        break;

                case 3: printf("\nThank you for riding with GO CAB   :]\n\n\n\n");
                        exit(0);

                default:printf("\nINVALID CHOICE");
                        break;
            }
        }
    }
}


void ridenow()
{
    char pick[50],drop[50],z[5],con[5],y[5];
    int i,choice,no,k=1,r;

    printf("\nEnter pickup location:\t");
    scanf("%s",pick);
    Sleep(1000);
    printf("\nEnter drop location  :\t");
    scanf("%s",drop);
    while(k!=2)
    {
        printf("\nselect your ride\n");
        Sleep(400);
        printf("1. Mini\n");
        Sleep(250);
        printf("2. Micro\n");
        Sleep(250);
        printf("3. ultra\n");
        Sleep(250);
        printf("4. prime\n");
        Sleep(500);
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\nEnter number of passengers(1/2): ");
            scanf("%d",&no);
            if(no<=2&&no>0)
            {
                k=2;
            }
            else
            {
                printf("\ninvalid input");
                printf("(max 2 passengers allowed)\n");
                Sleep(1000);
            }
        }
        else if(choice==2||choice==3||choice==4)
        {
            printf("\nEnter number of passengers(max.4): ");
            scanf("%d",&no);
            if(no<=4&&no>0)
            {
                k=2;
            }
            else
            {
                printf("\ninvalid input");
                printf("(max 4 passengers allowed)\n");
                Sleep(1000);
            }
        }
        else
        {
            printf("\nInvalid choice!");
        }
    }
    getchar();
    printf("\n           press enter to continue\r");
    gets(y);
    printf("\rcreating itinerary");
    Sleep(250);
    printf(".");
    Sleep(250);
    printf(".");
    Sleep(250);
    printf(".");
    Sleep(250);
    printf("\rcreating itinerary   ");
    Sleep(250);
    printf("\b\b\b.");
    Sleep(250);
    printf(".");
    Sleep(250);
    printf(".");
    Sleep(250);
    printf("\r---------------------------------------------------------------");
    printf("\n                          GO CAB                        \n");
    printf("---------------------------------------------------------------");
    printf("\n\n Pickup location:\t");
    puts(pick);
    printf("\n\n Drop location  :\t");
    puts(drop);
    printf("\n\n Ride           :\t");
    if(choice==1)
    {
        printf("Mini");
    }
    if(choice==2)
    {
        printf("Micro");
    }
    if(choice==3)
    {
        printf("Ultra");
    }
    if(choice==4)
    {
        printf("Prime");
    }
    printf("\n\n\n No of passengers :\t%d",no);
    printf("\n---------------------------------------------------------------\n");
    Sleep(1000);
    printf("\n\n        press enter for confirm booking");
    gets(z);
    printf("\r\rplease wait");
        Sleep(250);
        printf(".");
        Sleep(250);
        printf(".");
        Sleep(250);
        printf(".");
        Sleep(250);
        printf("\rplease wait   ");
        Sleep(250);
        printf("\b\b\b.");
        Sleep(250);
        printf(".");
        Sleep(250);
        printf(".");
        Sleep(250);
    srand(time(NULL));
    printf(" ");
    printf("\ryour booking has been confirmed.\n");
    Sleep(1000);
    printf("\nyour driver ");
    r=rand()%10;
    switch(r)
    {
        case 1: printf("Ashish");
        break;
        case 2: printf("Channaswami");
        break;
        case 3: printf("Akarsh");
        break;
        case 4: printf("Abhishek");
        break;
        case 5: printf("Durgesh");
        break;
        case 6: printf("Manoj");
        break;
        case 7: printf("Amar");
        break;
        case 8: printf("Akshay");
        break;
        case 9: printf("Narasimha");
        break;
        case 10: printf("Kundan");
        break;
    }
    printf(" will pick you up in %d minutes.\n",rand()%10+1);
    Sleep(1000);
    printf("\n\n");
    return;
}


/*void ridelater()
{
    NODE Micro=NULL,Mini=NULL,Prime=NULL,Ultra=NULL;
    int choice,ch;
    while(1)
    {
    printf("\nEnter Type of Car for Ride Later\n");
    Sleep(250);
    printf("1.  Micro\t( 2 Seater : Rs.8/km)\n");
    Sleep(250);
    printf("2.  Mini \t( 2 Seater : Rs.10/km)\n");
    Sleep(250);
    printf("3.  Prime\t( 4 Seater : Rs.12/km)\n");
    Sleep(250);
    printf("4.  Ultra\t( 4 Seater : Rs.15/km)\n");
    Sleep(250);
    printf("5.  Exit\n");
    Sleep(250);
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: while(1)
                {

                    printf("\nEnter choice\n1.New Booking\n2.Delete Booking\n3.Display Booked Dates\n4.Return Back\n");
                    scanf("%d",&ch);
                    switch(ch)
                    {
                    case 1:Micro=insert(Micro);break;
                    case 2:Micro=del(Micro);break;
                    case 3:display(Micro);break;
                    case 4:return;
                    default :printf("INVALID RESPONSE");break;
                    }
                }
                break;

        case 2: while (1)
                {
                    printf("\nEnter choice\n1.New Booking\n2.Delete Booking\n3.Display Booked Dates\n4.Return Back\n");
                    scanf("%d",&ch);
                    switch(ch)
                    {
                    case 1:Mini=insert(Mini);break;
                    case 2:Mini=del(Mini);break;
                    case 3:display(Mini);break;
                    case 4:return;
                    default :printf("INVALID RESPONSE");break;
                    }
                }
                break;

        case 3: while(1)
                {
                    printf("\nEnter choice\n1.New Booking\n2.Delete Booking\n3.Display Booked Dates\n4.Return Back\n");
                    scanf("%d",&ch);
                    switch(ch)
                    {
                    case 1:Prime=insert(Prime);break;
                    case 2:Prime=del(Prime);break;
                    case 3:display(Prime);break;
                    case 4:return;
                    default :printf("INVALID RESPONSE");break;
                    }
                }
                break;

        case 4: while(1)
                {
                printf("\nEnter choice\n1.New Booking\n2.Delete Booking\n3.Display Booked Dates\n4.Return Back\n");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:Ultra=insert(Ultra);break;
                    case 2:Ultra=del(Ultra);break;
                    case 3:display(Ultra);break;
                    case 4:return;
                    default :printf("INVALID RESPONSE");break;
                }
                }break;

        case 5:return;

        default: printf("\nINVALID INPUT");
                 return;
    }
    }
    return;
}

*/

int login()
{
    int found=0;
    int x=0,y,retry;
    char temp;
    char c[50],b[50];
    while(x<3)
    {
        printf("\n\tuser id:\t");
        scanf("%s",user);
        Sleep(1000);
        printf("\n\tpassword:\t");
        scanf("%s",pass);
        Sleep(1000);
        printf("\nplease wait");
        Sleep(250);
        printf(".");
        Sleep(250);
        printf(".");
        Sleep(250);
        printf(".");
        Sleep(250);
        printf("\rplease wait   ");
        Sleep(250);
        printf("\b\b\b.");
        Sleep(250);
        printf(".");
        Sleep(250);
        printf(".");
        Sleep(250);
        fp=fopen("gocab.txt","r");

        while((fscanf(fp,"%c",&temp))!=EOF)
        {
            fscanf(fp,"\n%s\t%s",c,b);
            if((strcmp(user,c)==0)&&(strcmp(pass,b)==0))
            {
                printf("\ryou have successfully logged in");
                Sleep(1000);
                found=1;
                fclose(fp);
                return;
            }
        }
        if(!found)
        {
            printf("\rInvalid user id or password!\n");
            x++;
            y=3-x;
            printf("\rDo u want to go back or retry..\n1.Go Back\n2.Retry\n");
            scanf("%d",&retry);
            if(retry==1)
            {
                fclose(fp);
                return -1;
            }
            else
            {
                printf("\n%d attempt left",y);
            }
        }
    }
    fclose(fp);
    printf("\nThankyou for using GO CAB.......\n\n");
    exit(0);

}
void signup()
{
    char user[50],pass1[50],pass2[50];
    Sleep(1000);
    printf("\nEnter details..");
    Sleep(200);
    while(1)
    {
        printf("\n\n\tuser id           :  ");
        scanf("%s",user);
        Sleep(500);
        printf("\n\tnew password      :  ");
        scanf("%s",pass1);
        Sleep(500);
        printf("\n\tretype password   :  ");
        scanf("%s",pass2);
        if(strcmp(pass1,pass2)==0)
        {
            fp=fopen("gocab.txt","a");
            fprintf(fp,"\n%s\t%s",user,pass1);
            fclose(fp);
            printf("\nThankyou for signup..... ");
            Sleep(1000);
            printf("\nNow login and book your ride....\n\n");
            Sleep(1000);
            login();
            break;
        }
        else
        {
            printf("\n\tThe password didn't match!!\n\tRetype Password");
        }
}
}

NODE insert(NODE first)
{
    NODE temp,prev,cur;
    int flag=0;
    char sour[20],dest[20];
    prev=NULL;
    cur=first;
    int dd,mm;
    if((temp=(NODE)malloc(sizeof(struct node)))==NULL)
    {
        printf("\nNO Memory allocated");
        exit(0);
    }
    while(flag==0)
    {
        printf("\nEnter date and month of journey\n");
        scanf("%2d%2d",&dd,&mm);
        if(dd<=31&&mm<=12)
        {
            printf("\nEnter the source      : ");
            scanf("%s",sour);
            Sleep(1000);
            printf("\nEnter the destination : ");
            scanf("%s",dest);
            printf("\nYour Booking has been confirmed\n");
            temp->day=dd;
            temp->month=mm;
            if(dd>31&&dd<1||mm>12&&mm<1)
            {
                printf("\nINVALID DATE OF JOURNEY");
                printf("\nPLEASE TRY AGAIN");
                return;
            }
            strcpy(temp->source,sour);
            strcpy(temp->destination,dest);
            temp->link=NULL;
            if(first==NULL)
                return temp;
            if(mm<=first->month)
            {
                if(dd<=first->day)
                {
                    temp->link=first;
                    return temp;
                }
            }
            while(cur!=NULL&&mm>=cur->month)
            {
                if(mm==cur->month&&dd<=cur->day)
                {
                   break;
                }
                else
                {
                    prev=cur;
                    cur=cur->link;
                }
            }
            prev->link=temp;
            temp->link=cur;
            flag==1;
            return first;
        }
        else
        {
            printf("\nEnter Valid Date and Month\n");
            flag=0;
        }
        return first;
}
}


NODE display(NODE first)
{
    NODE temp=first;
    if(first==NULL)
        {
            printf("No Bookings Yet!!\n");return;
        }
