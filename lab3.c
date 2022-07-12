
#include <stdio.h>
int main()
{
    int fs,fe,an,pan=-1,n,m;
    printf("Enter the number of frames: ");
    scanf("%d",&n);
    printf("Enter the window size: ");
    scanf("%d",&m);
    fs=0;
    fe = fs+m;
    printf("Frames sent from %d to %d\n",fs,fe-1);
    while(fs!=n)
    {
        printf("Enter the Ack number: ");
        scanf("%d",&an);
        if(fe<=n-1)
        {
            if(an-1==pan)
            {
                fs++;
                fe++;
                pan = an;
                printf("Window is sliding\nFrames sent from %d to %d\n",fs,fe-1);
            }
            else
            {
                printf("frame lost : %d\nresending frames from %d to %d\n",pan+1,fs,fe-1);
            }
        }
        else
        {
            if(an-1!=pan)
            {
                printf("frame lost : %d\nresending frames from %d to %d\n",pan+1,fs,fe-1);
            }
            else
            {
                fs++;
                pan = an;
            }
        }
    }
    printf("Data sent successfull!!");

    return 0;
}