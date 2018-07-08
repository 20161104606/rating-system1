
//
//  main.cpp
//  rating system
//
//  Created by qiuyu on 18/6/26.
//  Copyright © 2018年 qiuyu. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;
class result{
    private :
    int id;
    string name;
    float score[5];
    string category;
    string proname;
    string rname;
    string rsex;
    string rtel;
    float ave;
    public:
    result(int i,string n,float s[5])
    {
        float sum=0,max=s[0],min=s[0];
        int j;
        id=j;
        name.assign(n);
        for(j=0;j<5;j++)
        {
            score[j]=s[j];
            if(max<s[j])
                max=s[j];
            if(min>s[j])
                min=s[j];
            sum+=s[j];
        }
        ave=(sum-max-min)/3;
    }
    float get_ave()
    {
        return ave;
    }
    int get_id()
    {
        return id;
    }
    string get_name()
    {
        return name;
    }
    string get_category()
    {
        return category;
    }
    string get_proname()
    {
        return proname;
    }
    void display()
    {
        int i;
        cout<<"学号"<<id<<"参赛者"<<name<<"项目类别"<<category<<"项目名称"<<proname<<endl;
        cout<<"最终评分＝"<<ave<<endl;
        cout<<"评委打分：";
        for(i=0;i<5;i++)
            cout<<score[i]<<""<<endl;
    }
    
};
int main()
{
    int i,j;
    int m;
    int f=1;
    FILE* fp;
    FILE* fp1;
    int idsize;//参赛选手人数
    cout<<"请输入参赛者人数"<<endl;
    cin>>m;
    idsize=m;
    int *id;
    id=new int[idsize];
    vector<float>aver;//建立一个vector类
    vector<string>name;
    vector<string>category;
    vector<string>proname;
    vector<string>rname;
    vector<string>rsex;
    vector<string>rtel;
    vector<vector<float>>x(m,vector<float>(5));
    cout<<"请输入所有参赛者信息"<<endl;
    for(i=0;i<m;i++)
    {
        string na;
        string ca;
        string pro;
        cout<<"第"<<i+1<<"名参赛者编号"<<endl;
        cin>>id[i];
        cout<<"第"<<i+1<<"名参赛者"<<endl;
        cout<<"选手姓名\n";
        cin>>na;
        name.push_back(na);
        cout<<"节目类别\n";
        cin>>ca;
        category.push_back(ca);
        cout<<"节目名称\n";
        cin>>pro;
        proname.push_back(pro);
        
    }
    cout<<"请输入所有裁判信息"<<endl;
    for(i=0; i<5; i++)
    {
        string rna;
        string rse;
        string rte;
        cout<<"第"<<i+1<<"位裁判姓名"<<endl;
        cin>>rna;
        rname.push_back(rna);
        cout<<"第"<<i+1<<"位裁判性别"<<endl;
        cin>>rse;
        rsex.push_back(rse);
        cout<<"第"<<i+1<<"位裁判电话号"<<endl;
        cin>>rte;
        rtel.push_back(rte);
    }
    cout<<endl<<endl<<"=====比赛开始请裁判打分====="<<endl<<endl;
    for(i=0;i<m;i++)
    {
        cout<<"为第"<<i+1<<"名选手打分"<<endl;
        for(j=0;j<5;j++)
        {
            cout<<"第"<<j+1<<"位裁判打分"<<endl;
            cin>>x[i][j];
        }
            
    }
    cout<<endl<<endl<<"=====去掉一个最低分，去掉一个最高分的最终得分====="<<endl<<endl;
    for(i=0;i<m;i++)
    {
        float s[5];
        for(j=0;j<5;j++)
            s[j]=x[i][j];
        result a(id[i],name[i],s);
        a.display();
        aver.push_back(a.get_ave());
    
     }
for(i=1;i<m;i++)
    for(j=i;j>0;j--)
{
    if(aver[j]<aver[j-1])
    {
        float temp=aver[j];
        aver[j]=aver[j-1];
        aver[j-1]=temp;
        int sum=id[j];
        id[j]=id[j-1];
        id[j-1]=sum;
        string pname=name[j];
        name[j]=name[j-1];
        name[j-1]=pname;
    }
}
    cout<<endl<<endl<<"=====按名次显示得分====="<<endl<<endl;
    cout<<"名次"<<"  "<<"   编号"<<"    姓名"<<"     "<<"节目类型"<<"     "<<"节目名称"<<"       "<<"得分"<<"      "<<endl;
    for(i=m-1;i>=0;i--)
    {
        cout<<"第"<<f<<"名"<<"      "<<id[i]<<"      "<<name[i]<<"       "<<category[i]<<"       "<<proname[i]<<"        "<<aver[i]<<endl;
        f++;
    }
    cout<<endl<<endl<<"=====显示裁判信息====="<<endl<<endl;
    for(i=0; i<5 ;i++)
    {
        cout<<"第"<<i+1<<"位裁判姓名"<<rname[i]<<endl;
        cout<<"第"<<i+1<<"位裁判性别"<<rsex[i]<<endl;
        cout<<"第"<<i+1<<"位裁判电话号"<<rtel[i]<<endl;
    }
fp = fopen("//Users//qiuyu//Desktop//rating system//system.csv","w");
   if(fp==NULL)
        printf("文件不能打开！\n");
else
 {
    fprintf(fp,"名次,编号,成绩,姓名,节目类别,节目名称,\n");
    f=1;
    for(i=m-1;i>=0;i--)
    {
        fprintf(fp,"%d,%d,%f,%s,%s,%s\n",f,id[i],aver[i],name[i].c_str(),category[i].c_str(),
                proname[i].c_str());
        f++;
    }
    printf("信息保存成功！\n");
    fclose(fp);
  }
    fp1 = fopen("//Users//qiuyu//Desktop//rating system//re.csv","w");
    if(fp1==NULL)
        printf("文件不能打开！\n");
    else
    {
        fprintf(fp1,"姓名,性别,电话号,\n");
        f=1;
        for(i=0;i<5;i++)
        {
            fprintf(fp,"%s,%s,%s,裁判%d\n",rname[i].c_str(),rsex[i].c_str(),rtel[i].c_str(),i+1);
            f++;
        }
        printf("信息保存成功！\n");
        fclose(fp1);
    }

}