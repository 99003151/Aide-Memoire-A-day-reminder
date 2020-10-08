#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct event
{
    int date[3];
    char eve[50];    
};
int a=2,b=0;
int z=0;
int leap_year (struct event m)
{
    a=2;
    if(m.date[2]>=2020 && m.date[2]<=2030)
    {
        if(m.date[2] % 400==0) a=1;
        else if(m.date[2] % 100==0) a=0;
        else if(m.date[2] % 4==0) a=1;
        else a=0;
    }
    return a;       
}
void month(struct event e)
{
    if(e.date[1]==1||e.date[1]==3||e.date[1]==5||e.date[1]==7||e.date[1]==8||e.date[1]==10||e.date[1]==12) b=31;
    else if(e.date[1]==4||e.date[1]==6||e.date[1]==9||e.date[1]==11) b=30;
    else if(e.date[1]==2) 
        {
            if(a==1) b=29;
            if(a==0) b=28;
        } 
        else b=100;   
}
int Leap_Year(int l)
    {
        int x=2;
        if(l>=2020&& l<=2030)
        {
            if(l % 400==0) x=1;
            else if(l % 100==0) x=0;
            else if(l % 4==0) x=1;
            else x=0;
        }
        return x;       
}  
void Month(int cc)
{   
    if(cc==1||cc==3||cc==5||cc==7||cc==8||cc==10||cc==12) z=31;
    else if(cc==4||cc==6||cc==9||cc==11) z=30;
    else if(cc==2) 
    {
        if(a==1) z=29;
        if(a==0) z=28;
    } 
    else
        z=100;
}
void menu();
void got();
void start();
void back();
void add_record();
void list_record();
void modify_record();
void delete_record();
void search_record();


int main()
{
    start();
    return 0;
}

void menu()
{
    system("cls");
    printf("\n\n\t\t AIDE-MEMOIRE: A day reminder \n \t\t\t (2020-2030)");
    printf("\n\n\t Menu\n\n");
    printf("\t 1. Add New Event \n\t 2. List the events \n\t 3. Modify an event \n\t 4. Search for an event\n\t 5. Delete an event \n\t 6. Exit\n ");
    switch(getch())
    {
        case '1': add_record();
        break;
        case '2': list_record();
        break;
        case '3': modify_record();
        break;
        case '4': search_record();
        break;
        case '5': delete_record();
        break;
        case '6': exit(0);
        break;
        default:
                system("cls");
                printf("\n\t Enter 1 to 6 only");
                printf("\n\n\n\n\n\t Press any key");
                getch();
                menu();
    }
}
///////////////////////////////////////////////////////////////
void got(char *name)
{
    int i=0,j;
    char c,ch;
    do
    {
        c=getch();
        if(c!=8 && c!=13)
        {
            *(name+i)=c;
            putch(c);
            i++;
        }
        if(c==8)
        {
            if(i>0)
                i--;
            system("cls");
            for(j=0;j<i;j++)
            {
                ch=*(name+j);
                putch(ch);
            }
        }
    }
    while(c!=13);
        *(name+i)='\0';
}
///////////////////////////////////////////////////////////////
void start()
{
    menu();
}
///////////////////////////////////////////////////////////////
void back()
{
    start();
}
///////////////////////////////////////////////////////////////
void add_record()
{
    system("cls");
    FILE *f;
    struct event e;
    f=fopen("AideMemoire","ab+");
    Year: printf("\n\n\t Enter year: ");
    scanf("%d",&e.date[2]);
    int h=leap_year (e);  
    if(h!=0 && h!=1)
    {
        h=2;
        printf("\n\t Enter a valid year.");
        printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
        A1: switch(getch())
            {
                case '0': system("cls"); goto Year;
                break;
                case '1': system("cls"); menu();
                break;
                default: 
                    system("cls");
                    printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
                    goto A1;
            }                     
    }
    Month: printf("\n\t Enter month: ");
    scanf("%d",&e.date[1]);
    month(e);
    if(b==100)  
    {
        b=0;   
        printf("\n\t Enter a valid month.");
        printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
        A2: switch(getch())
            {
                case '0': system("cls"); goto Month;
                break;
                case '1': system("cls"); menu();
                break;
                default: 
                    system("cls");
                    printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
                    goto A2;
            }            
    }    
    Day: printf("\n\t Enter day: ");
    scanf("%d",&e.date[0]);
    if(e.date[0]<1||e.date[0]>b)
    {
        printf("\n\t Enter a valid day.");
        printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
        A3: switch(getch())
            {
                case '0': system("cls"); goto Day;
                break;
                case '1': system("cls"); menu();
                break;
                default: 
                    system("cls");
                    printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
                    goto A3;
            }          
    }    
    printf("\n\t Enter the event: ");
    got(e.eve);
    fwrite(&e,sizeof(e),1,f);
    fflush(stdin);
        printf("\n\n\t Record Saved !");
fclose(f);
printf("\n\n\n\n\n\t Press any key");
getch();
system("cls");
menu();
}
//////////////////////////////////////////////////////////
void list_record()
{
    system("cls");
    struct event e;
    FILE *f;
    f=fopen("AideMemoire","rb");
    if(f==NULL)
    {
        printf("\n\t File opening error in listing.");
        exit(1);
    }
    printf("\n\n\n\t\t RECORDED EVENTS: \n\n");
    while(fread(&e,sizeof(e),1,f)==1)
    {
        printf("\n\n\n\t Date: %d %d %d\n\t Event: %s",e.date[0],e.date[1],e.date[2],e.eve);
    }
    fclose(f);
    printf("\n\n\n\n\n\t Press any key");
    getch();
    system("cls");
    menu();
}

//////////////////////////////////////////////////////////
void modify_record()
{
    int c;
    FILE *f;
    int flag=0;
    struct event e,v;
    char Eve[50];
    f=fopen("AideMemoire","rb+");
    if(f==NULL)
    {
        printf("\n\t Data not added yet.");
        exit(1);
    }   
    else
    {
        system("cls");
        printf("\n\t Enter the event: ");
        got(Eve);
        while(fread(&e,sizeof(e),1,f)==1)
        {
            
            if(strcmp(Eve,e.eve)==0)
            {  
                YR: printf("\n\n\t Enter year to modify: ");
                scanf("%d",&v.date[2]);
                int g=leap_year(v);
                if(g!=0 && g!=1)
                {
                    g=2;
                    printf("\n\t Enter a valid year.");
                    printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
                    M1: switch(getch())
                    {
                        case '0': system("cls"); goto YR;
                        break;
                        case '1': system("cls"); menu();
                        break;
                        default: 
                            system("cls");
                            printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
                            goto M1;
                    }         
                }                
                MH: printf("\n\t Enter the month to modify: ");
                scanf("%d",&v.date[1]);
                month(v);
                if(b==100)  
                {
                    b=0;   
                    printf("\n\t Enter a valid month.");
                    printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
                    M2: switch(getch())
                    {
                        case '0': system("cls"); goto MH;
                        break;
                        case '1': system("cls"); menu();
                        break;
                        default: 
                            system("cls");
                            printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
                            goto M2;
                    }         
                }
                DY: printf("\n\t Enter the day to modify: ");
                scanf("%d",&v.date[0]);
                if(v.date[0]<1||v.date[0]>b)
                {
                    printf("\n\t Enter a valid day.");
                    printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' to exit ");
                    M3: switch(getch())
                    {
                        case '0': system("cls"); goto DY;
                        break;
                        case '1': system("cls"); menu();
                        break;
                        default: 
                            system("cls");
                            printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
                            goto M3;
                    }          
                }  
                printf("\n\t Enter the event: ");
                got(v.eve);        
                fseek(f,-sizeof(e),SEEK_CUR);
                fwrite(&v,sizeof(e),1,f);
                flag=1;
                break;   
            }
            fflush(stdin);
        }
        if(flag==1)
            printf("\n\n\t Your event data is modified.");
        else
            printf("\n\n\t Data not found.");
    fclose(f);
    }
    printf("\n\n\n\n\n\t Press any key");
    getch();
    system("cls");
    menu();       
}
//////////////////////////////////////////////////////////
void delete_record()
{
    struct event c;
    FILE *f ,*ft;
    int flag;
    char Event[50];
    f=fopen("AideMemoire","rb");
    if(f==NULL)
        printf("\n\t Event data not added yet.");
    else
    {
        ft=fopen("Temp.txt","wb+");
        if(ft==NULL)
            printf("\n\t File opening error");
        else
        {
            system("cls");
            printf("\n\t Enter the event: ");
            got(Event);
            fflush(stdin);
            while(fread(&c,sizeof(c),1,f)==1)
            {
                if(strcmp(c.eve,Event)!=0)
                    fwrite(&c,sizeof(c),1,ft);
                if(strcmp(c.eve,Event)==0)
                    flag=1;
            }
            fclose(f);
            fclose(ft);
            if(flag!=1)
            {
                printf("\n\t No record to delete.");
                remove("Temp.txt");
            }
            else
            {
                remove("AideMemoire");
                rename("Temp.txt","AideMemoire");
                printf("\n\t Record deleted successfully.");
            }
        }        
    }
    printf("\n\n\n\n\n\t Press any key");
    getch();
    system("cls");
    menu();
}
//////////////////////////////////////////////////////////
void search_record()
{
    int p=0,q=1,r=0,s=2;
    struct event e;
    FILE *f;
    int day[3];
    f=fopen("AideMemoire","rb");
    if(f==NULL)
    {
        printf("\n\t Error in Opening");
        exit(1);
    }
    system("cls");
    YEAR: printf("\n\t Enter year to search: ");
    scanf("%d",&day[2]);
    s=Leap_Year(day[2]);
    if(s!=0 && s!=1)
    {
        s=2;
        printf("\n\t Enter a valid year.");
        printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' to exit ");
        S1: switch(getch())
            {
                case '0': system("cls"); goto YEAR;
                break;
                case '1': system("cls"); menu();
                break;
                default: 
                    system("cls");
                    printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
                    goto S1;
            }            
    }
    MONTH: printf("\n\t Enter month to search: ");
    scanf("%d",&day[1]);
    Month(day[1]); 
    if(z==100)
    {
        z=1;
        printf("\n\t Enter a valid month.");
        printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
        S2: switch(getch())
        {
            case '0': system("cls"); goto MONTH;
            break;
            case '1': system("cls"); menu();
            break;
            default: 
                system("cls");
                printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
                goto S2;
        }       
    }   
    DAY: printf("\n\t Enter day to search: ");
    scanf("%d",&day[0]);
    if(day[0]<1||day[0]>z)
    {
        printf("\n\t Enter a valid day.");
        printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
        S3: switch(getch())
            {
                case '0': system("cls"); goto DAY;
                break;
                case '1': system("cls"); menu();
                break;
                default: 
                    system("cls");
                    printf("\n\n\n\n\n\t Press '0' to continue\n\t Press '1' for menu ");
                    goto S3;
            }          
    }  
    system("cls");
    while(fread(&e,sizeof(e),1,f)==1)
    {
        if(q>0)
        {
            system("cls");
            printf("\n\n\n\t EVENTS ON DATE %d-%d-%d: ",day[0],day[1],day[2]);
            q--;
        }
        if(e.date[2]==day[2] && e.date[1]==day[1] && e.date[0]==day[0] )
        {
            r++;
            p=1;
            printf("\n\t\t %d. %s",r,e.eve);
        }
    }
    fclose(f);
    if(p==0)
        printf("\n\n\n\n\t No records.");
    else p=0;
    printf("\n\n\n\n\n\t Press any key");
    getch();
    menu();
}
//////////////////////////////////////////////////////////
