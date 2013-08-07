//Map here����  By JackyBoy 1999/11/19
//��������Ӱ���ٶȣ��ݹ���õ��£��������Խ��д������ʹ��Ӧ�ü�����ҵľ���������Ϣ
#include <ansi.h>
#define MaxX 7
#define MaxY 30
inherit F_CLEAN_UP;
int X=7,Y=10;
static mixed m;
static string *rfile;
int draw_room(int,int,object);
string clean_color(string arg)
{
	if(!arg)
		return "";
	arg = replace_string(arg, BLK, "");
	arg = replace_string(arg, RED, "");
	arg = replace_string(arg, GRN, "");
	arg = replace_string(arg, YEL, "");
	arg = replace_string(arg, BLU, "");
	arg = replace_string(arg, MAG, "");
	arg = replace_string(arg, CYN, "");
	arg = replace_string(arg, WHT, "");
	arg = replace_string(arg, HIR, "");
	arg = replace_string(arg, HIG, "");
	arg = replace_string(arg, HIY, "");
	arg = replace_string(arg, HIB, "");
	arg = replace_string(arg, HIM, "");
	arg = replace_string(arg, HIC, "");
	arg = replace_string(arg, HIW, "");
	arg = replace_string(arg, NOR, "");
	arg = replace_string(arg, BLINK,"");
	return arg;
}
int main(object me, string arg)
{
	object where;
	int i,j;
	string tmp;
	if(me->query("qi")<40)
		return notify_fail("���������̫���ˣ�����Ϣһ�°ɣ�\n");
	me->add("qi",-20);
	if(arg)
	{
		//������ָ����Χ���Զ��巿��������Χ��
		arg=lower_case(arg);
		sscanf(arg,"%*sx=%d%*s",X);
		sscanf(arg,"%*sy=%d%*s",Y);
		if(X>MaxX||X==0) X=MaxX;
		if(Y>MaxY||Y==0) Y=MaxY;
	}
	tmp="��ʱ��ͼv1.0(By JackyBoy) 99/11/20 ��ͼ��С��"+X+"/"+Y+"\n";
	m=allocate(2*X+1);
	rfile=({});
	for(i=0;i<2*X+1;i++)
	{
		m[i]=allocate(2*Y+1);
		for(j=0;j<2*Y+1;j++)
			m[i][j]=" ";
	}
	where=environment(me);
	if(!objectp(where))
		return notify_fail("�Բ��𣬲�֪���㵽��������ѽ������ʦ�ɣ�\n");
	draw_room((2*X+1)/2,(2*Y+1)/2,where);
	for(i=0;i<2*Y+1;i++)
	{
		for(j=0;j<2*X+1;j++)
		{
			if(m[j][i]==" "&&i%2&&j%2)
				tmp+="        ";
			else
			{
				//�������Ϊ�գ����Ҵ�ʱjΪż���У�������ո�
				if(m[j][i]==" "&&!(j%2))
					tmp+="  ";
				else
				if(m[j][i]==" ")
					tmp+="        ";
				else
				{
					tmp+=m[j][i];
					//if(!(i%2)&&!(j%2))
					if(m[j][i]!="��")
						for(int d=8-sizeof(clean_color(m[j][i]));d>0;d--)
							tmp+=" ";
				}
			}
		}
		tmp+="\n";
	}
	me->start_more(tmp);
	return 1;
}

object find_room(string path)
{
	object ob;
	if(objectp(ob=find_object(path))||objectp(ob=load_object(path)))
		return ob;
	return 0;
}

//���������I�J�K�L
int draw_path(int x,int y,string direc)
{
	string str;
	int xx=0,yy=0;
	switch(direc)
	{
		case "south":
		case "north":str="   ��   ";break;
		case "southdown":
		case "northup":str="   ��   ";break;
		case "southup":
		case "northdown":str="   ��   ";break;
		case "east":
		case "west":str="��";break;
		case "eastup":
		case "westdown":str="��";break;
		case "westup":
		case "eastdown":str="��";break;
		case "southeast":
		case "northwest":str="�J";break;
		case "shothwest":
		case "northeast":str="�I";break;
		default:
			return 0;
	}
	if(sscanf(direc,"%*ssouth%*s"))
		yy++;
	if(sscanf(direc,"%*snorth%*s"))
		yy--;
	if(sscanf(direc,"%*seast%*s"))
		xx++;
	if(sscanf(direc,"%*swest%*s"))
		xx--;
	if(x+xx<0||y+yy<0||x+xx>2*X||y+yy>2*Y)
		return 0;
	//write("���õ� "+(x+xx)+ " "+(y+yy)+" ��\n");
	m[x+xx][y+yy]=str;
	return 1;
}
	
int draw_room(int x,int y,object room)
{
	int i,nst=0,xx,yy;
	string name,*dirs;
	object nroom;
	mapping dir;
	reset_eval_cost();
	if(x<0||y<0||!objectp(room)||x>2*X||y>2*Y)
		return 0;
	name=clean_color(room->query("short"));//��ȡ����ɫ�ķ���short����
	//write("���꣺"+x+" / "+ y+ "���� "+name+" �ļ�����"+base_name(room)+"\n");
	rfile=rfile + ({ base_name(room) });
	dir=room->query("exits");
	if(!mapp(dir)||sizeof(dir)<1)
		return 0;
	dirs=keys(dir);
	for (i=0;i<sizeof(dirs);i++)
	{
		xx=0;yy=0;
		if(sscanf(dirs[i],"%*ssouth%*s"))
			yy+=2;
		if(sscanf(dirs[i],"%*snorth%*s"))
			yy-=2;
		if(sscanf(dirs[i],"%*seast%*s"))
			xx+=2;
		if(sscanf(dirs[i],"%*swest%*s"))
			xx-=2;
		if(!draw_path(x,y,dirs[i])||(xx==0&&yy==0))
			nst=1;
		nroom=find_room(dir[dirs[i]]);
		//�����ظ�����
		if(!objectp(nroom)||nst)
			continue;
		if(member_array(base_name(nroom),rfile)==-1)
			draw_room(x+xx,y+yy,nroom);
	}
	if(strlen(name)>8)
		name=name[0..7];
	if(strlen(name)<7)//�Բ���4�����ֵķ��������о��д���
	{
		int d=8-strlen(name);
		if(d%2)
		{
			name+=" ";
			d--;
		}
		for(i=0;i<d/2;i++)
			name=" "+name+" ";
	}
	if(nst)
		name=HIY+name;
	if((x==(2*X+1)/2)&&(y==(2*Y+1)/2))
		name=BLINK+name;
	name+=NOR;
	m[x][y]=name;
	return 1;
}

int help()
{
	write(@HELP
	��ʱ��ͼ v1.0 (Write By JackyBoy 99/11/20)
	�����÷���map [x=1-7] [y=1-30]
�������������˽���Χ�ķ����ͼ�ķֲ�״��������־������֮������������
�����Ͻ���������Ӧ������ȫ��ȷ�ط�Ӧ��ͼ������������ʦ��Ƶ�ͼ���淶�ȶ�
��ԭ�򣨱����Թ����в��淶���ڱ���enter֮��ģ�����֮���޷�˫������ȣ���
���µ�ͼ��������ʾʱ�����߷�������һ�����������������һ��·����ͼ����
ȫ��������������磬����A���Դ�south�ߵ�B���䣬����B������northȴ�ߵ�C��
�䣬��ʱ��A�ø���������B�ø�����Ч����ȫ��һ����
���⣬���ӱ�־�м�ͷ��ָ������Ƹ��ߣ��в��淶���ڵķ����Ի�ɫ��־������
���ķ�������˸����־��
������Ĭ����x=7,y=10 �ĵ�ͼ��С��ʾ����������������ֶ�ָ����ͼ��С��
HELP);
	return 1;
}

