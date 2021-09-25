#include "mythread.h"
#include <QDebug>
#include <QBuffer>
#include<QString>
#include<QSharedMemory>

#include "curl/curl.h"
#include "iostream"
#include <vector>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/video.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/ml.hpp"

#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<cstring>

#define FLAG IPC_CREAT|0777
#ifndef 	SHM_FAILED					//定义方法调用出错常量符号
#define 	SHM_FAILED -1
#endif



int First_loop=1;
using namespace std;
using namespace cv;
QSharedMemory* sharedMemory=NULL;
struct Image_src{
    int state=0;//0 ready to copy 1 copying
    int length=0;
    uchar data_save[1000000]={};
    uchar data[1000000]={};
    float res[20];
    int pointer=0;
};

struct FtpFile {

  const char *filename;

  FILE *stream;

};

Image_src *memoryAddr;
int shmid;


void init()
{
shmid = shmget(0x00000018,5000*1024,FLAG);
cout << shmid << endl;
        if(shmid == SHM_FAILED)					//判断创建工作是否成功
    {
        cout<<"share memory create fail!"<<endl;	//不成功则打印输出提示信息
        exit(1);					//退出进程
    }
    memoryAddr = (Image_src*)shmat(shmid,NULL,0);
}



void copy(int start, int end, char* a)
{
        for(int _j=start; _j<=end ;_j++)
        {
            (*(memoryAddr)).data[(*(memoryAddr)).pointer]=a[_j];
            (*(memoryAddr)).pointer++;
        }
}

void decode()
{
int res;
static int time=0;
time++;
        cout << "decoding:" << time << endl;
        vector<uchar> buff((*(memoryAddr)).data,(*(memoryAddr)).data+(*(memoryAddr)).pointer);
int size;
        (*(memoryAddr)).state=1;
        for(int _k=0; _k<(*(memoryAddr)).pointer; _k++)
        {
            (*(memoryAddr)).data_save[_k]=(*(memoryAddr)).data[_k];
        }
        (*(memoryAddr)).length=(*(memoryAddr)).pointer;
        (*(memoryAddr)).state=0;
        //cout << "res:" <<(*(memoryAddr)).res[1];
        //cout << "res:" <<(*(memoryAddr)).res[2];
        //cout << "res:" <<(*(memoryAddr)).res[3];
        //cout << "res:" <<(*(memoryAddr)).res[4];
size=buff.size();
        Mat jpegimage = imdecode(Mat(buff),CV_LOAD_IMAGE_COLOR);
res=jpegimage.empty();
       // cout << res << endl;
        if(!jpegimage.empty())
        {

            unsigned char *from;
            sharedMemory->lock();
            char *to = (char*)sharedMemory->data();
            from = jpegimage.data;
            memcpy(to, from, 640*480*3);
            sharedMemory->unlock();
            qDebug() << "\n rec coping ";
        }


}


static size_t my_fwrite(void *buffer, size_t size, size_t nmemb, void *stream)

{
char* a;
int _=size;
char Tag[12]={'a','r','f','l','e','b','a','r','f','l','e','\n'};
char head[4]={(char)0xff,(char)0xD8,(char)0xff,(char)0xE0};
char tail[2]={(char)0xff,(char)0xD9};
int Tag_pos=0;
int head_pos=0;
int tail_pos=0;
int start_pos=-1;
int end_pos=-1;
//cout << "seg len:" << nmemb << endl;

  struct FtpFile *out=(struct FtpFile *)stream;

  if(out && !out->stream) {

    out->stream=fopen(out->filename, "wb");//打开文件进行写入

    if(!out->stream)

      return -1;

  }

//if(First_loop==1)
//{
//a = (char *)buffer;
//cout << "save" << endl;
a = (char *)buffer;
for(int _i=0;_i<nmemb;_i++)
{
    if(Tag[Tag_pos]==a[_i])
    {
        Tag_pos++;
    }
    else Tag_pos=0;
    if(Tag_pos==12)
    {
        //cout << "Tag!:" <<_i<< endl;
        Tag_pos=0;
    }

    if(head[head_pos]==a[_i])
    {
        //cout << a[_i] << endl;
        head_pos++;
    }
    else head_pos=0;
    if(head_pos==4)
    {
    //cout << "head" <<endl;
    start_pos=_i-3;
    head_pos=0;
    }

    if(tail[tail_pos]==a[_i])
    {
    //cout << a[_i] << endl;
    tail_pos++;
    }
    else tail_pos=0;
    if(tail_pos==2)
    {
    //cout << "tail" <<endl;
    end_pos=_i;
    tail_pos=0;
    }

}
//fwrite(buffer, size, nmemb, out->stream);
//fclose(out->stream);
//cout << "start_pos" << start_pos << "end_pos" << end_pos << endl;

First_loop++;

if(end_pos!=-1)
{
        if(start_pos==-1)
        {
            //copy(0,end_pos,a);
            //cout << "final-len:" << (*(memoryAddr)).pointer << endl;
            //cout << "copy finished!" <<endl;
            decode();
        }
        else
        {
            //cout << "head and tail are both in a same frag" <<endl;
            if(end_pos<start_pos)
            {
                copy(0,end_pos,a);
                //cout << "copy finished!" <<endl;
                decode();
                //cout << "final-len:" << (*(memoryAddr)).pointer << endl;
                //cout << "start is :" << (*(memoryAddr)).data[0] << endl;
                //cout << "end   is :" << (*(memoryAddr)).data[(*(memoryAddr)).pointer-1] << endl;
                //cout << "find a head start to copy!" <<endl;
                (*(memoryAddr)).pointer=0;
                copy(start_pos,nmemb-1,a);
            }
            else
            {
                //cout << "find a head start to copy!" <<endl;
                (*(memoryAddr)).pointer=0;
                copy(start_pos,end_pos,a);
                decode();
                //cout << "copy finished!" <<endl;
            }
        }

}
else if(start_pos!=-1)
{
    //cout << "find a head start to copy:" <<endl;
        (*(memoryAddr)).pointer=0;
        copy(start_pos,nmemb-1,a);
}

else if(start_pos==-1&&end_pos==-1)
{
    //cout << "copying" <<endl;
        copy(0,nmemb-1,a);
        //cout << "mid-len:" << (*(memoryAddr)).pointer << endl;
}
else
{
//cout << "error!"<<endl;
while(1);
}

  return nmemb;

}



static int download()

{

     CURL *curl;

     CURLcode res;

     struct FtpFile ftpfile={

         "./a.txt", //定义下载到本地的文件位置和路径

         NULL

     };





     curl_global_init(CURL_GLOBAL_DEFAULT);



     curl = curl_easy_init();  //初始化一个curl指针



     if(curl) { //curl对象存在的情况下执行的操作



         //设置远端地址

         curl_easy_setopt(curl, CURLOPT_URL,"http://205u5g0887.iask.in/");



         //执行写入文件流操作

         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_fwrite);//当有数据被写入，回调函数被调用，

         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ftpfile); //设置结构体的指针传递给回调函数



         //启用时会汇报所有的信息，存放在STDERR或指定的CURLOPT_STDERR中

         curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);



         curl_easy_setopt(curl, CURLOPT_USERPWD, "SUREN:SUREN");



         //写入文件

//cout << "rec" << endl;

         res = curl_easy_perform(curl);



         //释放curl对象

         curl_easy_cleanup(curl);



         if(res != CURLE_OK)

         {

              //cout<<stderr<<res<<endl;

         }

     }



     if(ftpfile.stream)

     {

         //关闭文件流

         fclose(ftpfile.stream);

     }



      //释放全局curl对象

     curl_global_cleanup();



     return 0;



 }


myThread::myThread()
{

}
void myThread::run()
{
    init();
     Mat A;

     A=imread("/0.jpg", 1);
    int size = A.cols * A.rows * A.channels();
    if (NULL == sharedMemory)
    {
        sharedMemory = new QSharedMemory();
        QString qstrNativeKey = QString("RkWebViewModelSM44");
        sharedMemory->setNativeKey(qstrNativeKey);
    }
    if (sharedMemory->isAttached())
    {
        sharedMemory->detach();
    }
    if (!sharedMemory->create(size))
    {
        //sharedMemory->attach();
        qDebug() << sharedMemory->errorString() << "\n Unable to create shared memory segment.";
        return;
    }
    else qDebug() << "\n create success";


     //cout << "1 2 3 4" << endl;
     //cout << A.size() << endl;
     //cout << A.type() << endl;

     qDebug() <<  "hello world22!"; //复写QThread类的 run()函数
     //imshow("newpic", A);
     //waitKey(1);
     qDebug() <<  "hello world!"; //复写QThread类的 run()函数
     download();
}
