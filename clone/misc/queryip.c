#include <ansi.h>

static string dest_addr;
void icheck(string address);
void report(string address,int middle);
string compare(string address,int middle);
mapping before, after;
int usertime;
object me=previous_object(1);

int connect_to(string arg)
{
      	dest_addr=arg;
        if (sscanf(dest_addr, "%*d.%*d.%*d.%*d") == 4)
          icheck(arg);
        else
         {
         	write("���Խ�����ַ...�糤ʱ��û�л�������ָ��ip��ѯ\n");
          resolve(dest_addr, "resolve_callback");
          return 1;
        }
}

void resolve_callback(string address, string resolved, int key)
{
        int ret;
        if (! resolved)
           {
           	//������ ��ô������ʾ
           	write("ʧ��\n");
             	tell_object(previous_object(2),"�޷�������ַ "+address+" ��\n");
              if (sscanf(dest_addr, "%*d.%*d.%*d.%*d") == 4)
                  resolved = dest_addr;
              else if (sscanf(dest_addr, "%*d.%*d.%*d") == 3)
                  resolved = dest_addr+".0";
              else if (sscanf(dest_addr, "%*d.%*d") == 2)
                  resolved = dest_addr+".0.0";
              else return;
           }
        icheck(resolved);
}

void icheck(string address)
{
  int add1,add2,add3,add4;
  int read_from=0;
  int read_to=167379; //Ŀǰ�ܹ�167380�� �����ô�ú������Զ���ֵ��
  int middle;
  before = rusage();
  sscanf(address,"%d.%d.%d.%d",add1,add2,add3,add4);
  if (add1 > 255 || add1 < 0 
    ||add2 > 255 || add2 < 0 
    ||add3 > 255 || add3 < 0
    ||add4 > 255 || add4 < 0)
    { tell_object(me,"�����ַ�������ʵ\n"); return;}
  while ( read_from <= read_to )
  {
  	middle = (read_from + read_to) /2;
    switch(compare(address,middle))
    {
    	case "����":
    		 report(address,middle);
    		 return;
      case "����":  
      	 read_from = middle+1;
         break;
      case "С��": 
         read_to   = middle-1;
         break;
    }
  }
  tell_object(me,"�޷��ҵ�ƥ�����ݡ�\n");
  return ;
}

string compare(string address,int middle)
{
	  string line;
 	  string from,to;
    int  add1, add2, add3, add4;
 	  int from1,from2,from3,from4;
 	  int   to1,  to2,  to3,  to4;

 	  line=read_file("/data/ipdata.o",middle,1);
    from = line[0..15];
    to   = line[16..31];
    sscanf(address,"%d.%d.%d.%d", add1, add2, add3, add4);
    sscanf(from   ,"%d.%d.%d.%d",from1,from2,from3,from4);
    sscanf(to     ,"%d.%d.%d.%d",  to1,  to2,  to3,  to4);
    if (add1 < from1 )   return "С��";
    else if (add1 > to1) return "����";
    else if (add1 < to1) return "����";
    else //   add1 == to1
    if (add2 < from2)    return "С��";
    else if (add2 > to2) return "����";
    else if (add2 < to2) return "����";
    else // add1 == to1  && add2 == to2
    if (add3 < from3)    return "С��";
    else if (add3 > to3) return "����";
    else if (add3 < to3) return "����";
    else // add1 == to1 && add2 == to2 && add3 == to3
    if (add4 < from4)    return "С��";
    else if (add4 > to4) return "����";
    else if (add4 < to4) return "����";
    else //add1 == to1 && add2 == to2 && add3 == to3 && add4 == to4
       return "����";
}

void report(string address,int middle)
{
	string line=read_file("/data/ipdata.o",middle,1);
	if (!stringp(address)) tell_object(me,"û���ҵ���Ӧ����a\n");
	if (!stringp(line))    tell_object(me,"û���ҵ���Ӧ����b\n");
  tell_object(me,sprintf(HIC"��ѯ��ַ%s��\n��Ӧ�����ַΪ��"YEL"%s\n"NOR,address,line[32..sizeof(line)]));
  after = rusage();
  usertime = after["utime"] - before["utime"];
  tell_object(me,sprintf("�˴β��һ���ʱ��Ϊ%d ΢��\n",usertime ));
}
