#include <stdio.h>
#include<string.h>

char findClass(char str[])
{
    int ip=0,i=0;
    while(str[i]!='.')
    {
        ip = ip*10 + (str[i]-'0');
        i++;
    }
    if(ip>=1 && ip<=126)
    return 'A';
    else if(ip>=127 && ip<=191)
    return 'B';
    else if(ip>=192 && ip<=223)
    return 'C';
    else if(ip>=224 && ip<=239)
    return 'D';
    else
    return 'E';
}

void seperate(char str[], char ipClass)
{
    char netId[12]="",hostId[12]="";
    if(ipClass=='A')
    {
        int i=0;
        int j=0;
        while(str[i]!='.')
        {
            netId[i++] = str[j++];
        }
        i=0;
        j++;
        while(j<strlen(str))
        {
            hostId[i++] = str[j++];
        }
        printf("Network ID is %s and ", netId); 
        printf("Host ID is %s", hostId); 
    }
    else if(ipClass=='B')
    {
        int i=0;
        int j=0,dotCnt = 0;
        while(dotCnt<2)
        {
            netId[i++] = str[j++];
            if(str[j]=='.')
            dotCnt++;
        }
        i=0;
        j++;
        while(j<strlen(str))
        {
            hostId[i++] = str[j++];
        }
        printf("Network ID is %s and ", netId); 
        printf("Host ID is %s", hostId); 
    } 
    else if(ipClass=='C')
    {
        int i=0;
        int j=0,dotCnt = 0;
        while(dotCnt<3)
        {
            netId[i++] = str[j++];
            if(str[j]=='.')
            dotCnt++;
        }
        i=0;
        j++;
        while(j<strlen(str))
        {
            hostId[i++] = str[j++];
        }
        printf("Network ID is %s and ", netId); 
        printf("Host ID is %s", hostId); 
    }
    else
    {
        printf("In this Class, IP address is not divided into Network and Host ID"); 
    }
}

int main()
{
    char str[] = "192.226.12.11";
    char ipClass = findClass(str);
    printf("Given IP address belong to Class %c\n",ipClass);
    seperate(str,ipClass);
    return 0;
}
