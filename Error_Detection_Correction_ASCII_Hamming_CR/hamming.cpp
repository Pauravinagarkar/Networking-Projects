// Write a program for error detection and correction for 7/8 bits ASCII codes using Hamming
// Codes or CRC. Demonstrate the packets captured traces using Wireshark Packet Analyzer
// Tool for peer to peer mode.( 50% students will perform Hamming Code and others will
// perform CRC) 

using namespace std;
int main()
{
    int data[7],rec[7];
    cout<<"Enter data Bits ";
    cin>>data[0]>>data[1]>>data[2]>>data[4];
    data[6]=data[4]^data[2]^data[0];
    data[5]=data[4]^data[1]^data[0];
    data[3]=data[2]^data[1]^data[0];
    cout<<"\n Data : ";
    for(int i=0;i<7;i++)
    {
        cout<<" "<<data[i];
    }  
    cout<<"\n Enter received array : ";
    for(int i=0;i<7;i++)
    {
        cin>>rec[i];
    }   
    int c1=rec[6]^rec[4]^rec[2]^rec[0];
    int c2=rec[5]^rec[4]^rec[1]^rec[0];
    int c4=rec[3]^rec[2]^rec[1]^rec[0];
   
    int c=c4*4+c2*2+c1;
    if(c==0)
        cout<<"\n No Error ";
    else
        cout<<"Error found at position "<<c;
   
    if(rec[7-c]==0)
        rec[7-c]=1;
    else
        rec[7-c]=0;
   
    cout<<"\n Corrected Data : ";
    for(int i=0;i<7;i++)
    {
        cout<<" "<<rec[i];
    }
return 0;
}
