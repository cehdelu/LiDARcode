#include <QCoreApplication>
#include <stdio.h>
#include <iostream>
#include <QVector>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FILE *stream;
    //int ch = fgetc(stream);
    stream = fopen("D:/LiDAR/road.las","r");
    fseek(stream,96,SEEK_SET);
    int OffsetToPointData;
    fread(&OffsetToPointData,sizeof(int),1,stream);

    double ScaleOffset[6] = {0};

    double y = 0;

    fseek(stream,131,SEEK_SET);

    for(int i = 0; i  < 6; ++i)
    {
        fread(ScaleOffset+i,sizeof(double),1,stream);
    }

    fseek(stream,OffsetToPointData,SEEK_SET);

    int i  =  0;//i default 0
    //cin>>i;//i can get 0,1,3

    struct Point
    {
        int PointData[3];
    }pdata;

    while(stream->eof())

        if(i == 0)
        {
           QVector<Point>PointInf;
           for(int j = 0; j < 3+i; ++j)
           {
             fread(&pdata.PointData[j],sizeof(int),1,stream);
           }
           PointInf.push_back(pdata);
        }
        else if(i == 1)
        {
           QVector<Point>PointInf;
           for(int j = 0; j < 3+i; ++j)
           {
             fread(&pdata.PointData[j],sizeof(int),1,stream);
           }
           PointInf.push_back(pdata);
        }
        else if(i == 3)
        {
           QVector<Point>PointInf;
           for(int j = 0; j < 3+i; ++j)
           {
             fread(&pdata.PointData[j],sizeof(int),1,stream);
           }
           PointInf.push_back(pdata);
        }







    cout<<OffsetToPointData;
    return a.exec();
}
