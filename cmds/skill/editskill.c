// /cmds/skill/editskill.c
// Last modified by winder 2004.3.24

#include <ansi.h>
inherit F_CLEAN_UP;
#define SHUANGYIN_HAO "\""
string *valid_types = ({
	"unarmed",
	"sword",
	"blade",
});
string *banned_name=({ "  ",});
mapping spe_skill = ([
	"action" : ({" "}),
	"damage" : ({"10"}),
	"dodge" : ({"10"}),
	"parry": ({"10"}),
	"damage_type" : ({"����"}),
	"lvl" : ({"10"}),
	"skill_name" : ({"��ճ���"}),
	"skill_total_num" : ({"0"}),
	"skill_en_name" : ({" "}),
	"skill_ch_name" : ({" "}),
]);
int spe_skillnum;
string spe_skill_name;
string spe_skill_basename;
string spe_skill_help;
string oldfile;
//����Ƿ���3��12λ��Ӣ��id
int check_legal_id(string id);
//����Ƿ���1��5��������
int check_legal_name(string name);
// ����Ƿ�������Ļ����书
int check_legal_basename(string name);
void skill_init_header(string skill_en_name,string skill_ch_name);
// ��ʾ�û����뵱ǰ��ʽ������
void get_zhaoshi_ch_name(string yn, object ob);
// ��ʾ�û����뵱ǰ��ʽ����
void get_zhaoshi_ch_action(string yn, object ob);
// ��ʾ�û�������书�İ����ļ�
void get_skill_help(string yn,object ob);
// �������Ƿ���Դ�����skill_num�� ����skill_num
int check_skillnum_exist(object me,string skill_en_name,int skill_num);
void finish_write_skill(object ob);
// �������Ƿ���ԸĶ�skill_en_name����ļ�
int check_owner_skill(object me,string skill_en_name);
// ���ļ��ж�ȡ����书��������
string get_header_skillchname(string file);
// ���ļ��ж�ȡ����书�Ļ����书�� 
string get_header_skillbasename(string file);
int main(object me, string arg)
{
	int skill_num,skill_num_result;
	string skill_en_name,skill_ch_name,myskill;
	string skill_base_name;
	
	spe_skill_basename="";
	spe_skill_name="";
	spe_skill_help="";
	spe_skillnum=0;
	oldfile="";
	
	seteuid(getuid());
	if(!arg)
		return notify_fail(WHT"ָ���ʽ��editskill �������� �书Ӣ������ �书�������� �ڼ���\n"NOR);
	if( sscanf(arg, "%s %s %s %d", skill_base_name,skill_en_name,skill_ch_name,skill_num)!=4)
		return notify_fail(WHT"ָ���ʽ��editskill �������� �书Ӣ������ �书�������� �ڼ���\n"NOR);
	skill_en_name=lower_case(skill_en_name);
	spe_skill_basename=skill_base_name;
	if(check_legal_basename(skill_base_name)==0)
		return notify_fail(RED"������Ļ������ܲ����ڡ�\n"NOR);
	if(check_legal_id(skill_en_name)==0)
		return 1;
	spe_skill["skill_en_name"]=skill_en_name+"-"+skill_base_name+".c";
	spe_skill_name=skill_en_name+"-"+skill_base_name;
	if(check_legal_name(skill_ch_name)==0) return 1;             
	spe_skill["skill_ch_name"]=skill_ch_name;
	if( skill_num!=1 && get_header_skillchname(spe_skill["skill_en_name"])!=skill_ch_name)
		return notify_fail( HIR"������������书���ƺ���ѡ��Ӣ���书������ì�ܡ�\n"NOR);
	if( skill_num!=1 && get_header_skillbasename(spe_skill["skill_en_name"])!=skill_base_name)
		return notify_fail( HIR"������Ļ�������������ѡ��Ӣ���书������ì�ܡ�\n"NOR);
	if(mapp(me->query("skillmaxim")) &&
		sizeof(me->query("skillmaxim")) >3 )
		return notify_fail(HIR"�����ֻ���Դ������书��\n"NOR);
	switch(check_owner_skill(me,spe_skill["skill_en_name"]))
	{
		case 2:
			return notify_fail( HIR"�˹����Ѵ��ڣ��޷����¡�\n"NOR);
			break;
		case 0: 
			break;
		case 1:
			return notify_fail( HIR"��Ŀǰֻ���������������ܴ���һ������\n"NOR);
		default:
			return notify_fail( HIR"�������򲻶ԣ��뿴������\n"NOR);
	}
	if(skill_num < 1)
		return notify_fail(HIR"����Ҫ�ӵ�һ�п�ʼ������\n"NOR);
	if((int)me->query("combat_exp") < (skill_num)*1000000+9000000)
		return notify_fail(HIR"��ľ��黹�����������Դ��书�ˡ�\n"NOR);
	if((int)me->query("score") < 20000)
		return notify_fail(HIR"��Ľ��������������������Դ��书�ˡ�\n"NOR);
	if(//(int)me->query_skill(spe_skill_name,1)!=0  &&
		(int)me->query_skill(spe_skill_name,1) < (skill_num-1)*20)
		return notify_fail( HIR"�����ʽ�����������������һ�£�Ȼ���������аɡ�\n"NOR);
	spe_skillnum=skill_num;
	skill_num_result=(check_skillnum_exist(me,spe_skill["skill_en_name"],skill_num));
	if (file_size(SKILL_D(spe_skill["skill_en_name"])))
		oldfile = read_file(SKILL_D(spe_skill["skill_en_name"]));
	switch(skill_num_result)
	{
		case -1 :
			//�޷�ȡ���Ѿ�������ʽ����
			return notify_fail(HIR"�����Ҫ�������书�д���֪ͨ��ʦ�����\n"NOR);
		case 0 :
			return notify_fail( HIR"��ֻ�ܴ������л����޸������������ʽ�������³��ԡ�\n"NOR);
		case 1 :
			// �������ĵ�һ�еĻ� ��ôһ������
//			rm(SKILL_D(spe_skill["skill_en_name"]));
			skill_init_header(spe_skill["skill_en_name"],skill_ch_name);
			write( HIG"�����ڿ�ʼ����"+skill_ch_name+"("+spe_skill_name+")"HIG"��\n"NOR);
			write( HIW"������书дһ����飬�Ժ���ڰ����ĵ������֣�������$���档\n"NOR);
			input_to( (: get_skill_help :) ,this_player());
			return 1;
		default:
		//�����ԭ����ʽ�������µ���ʽ
			write(HIW"\r����ʽ������֣���Ҫ��ʱ���ߣ�������Զ�޷�����ȷ��������"NOR);
			input_to( (: get_zhaoshi_ch_name :), this_player() );
			return 1;
	}
	return 0;
}
void get_skill_help(string yn,object ob)
{
	if (yn=="")
	{
		write( HIW"������书дһ����飬�����ڰ����ĵ������֡�\n"NOR);
		write( HIW"���п�����$����\n"NOR);
		input_to( (:get_skill_help:) ,ob);
		return;
	}
	spe_skill_help = "\n\t"+yn;
	write(HIW"\r����ʽ������֣���Ҫ��ʱ���ߣ�������Զ�޷�����ȷ��������"NOR);
	input_to( (: get_zhaoshi_ch_name :), this_player() );
	return;
}
string get_header_skillchname(string file)
{
	string result;
	string content,*list;

	content=read_file(SKILL_D(file));
	if((int)content==0) return 0;
	list = explode(content, "\n");
	if(sizeof(list) < 8) return 0;
	else
	{
		if(sscanf(list[7],"// %s",result)!=1) return 0;
		else return result;
	}
	return 0;
}
string get_header_skillbasename(string file)
{
	string result;
	string content,*list;

	content=read_file(SKILL_D(file));
	if((int)content==0) return 0;
	list = explode(content, "\n");
	if(sizeof(list) < 7) return 0;
	else
	{
		if(sscanf(list[6],"// %s",result)!=1) return 0;
		else return result;
	}
	return 0;
}
void skill_init_header(string skill_en_name,string skill_ch_name)
{
	string header, result;
	object me = this_player();
	int i;
	string str;

	result="";
	header="";

	header="// ��������Դ��书����\n";		//list[0]
	header+="// "+geteuid(me)+"\n";			//list[1]
	header+="// "+me->query("name")+"\n";		//list[2]
	header+="// "+me->query("title")+"\n";		//list[3]
	header+="// "+me->query("combat_exp")+"\n";	//list[4]
	header+="// "+me->query("gender")+"\n";		//list[5]
	header+="// "+spe_skill_basename+"\n";		//list[6]
	header+="// "+spe_skill["skill_ch_name"]+"\n";	//list[7]
	header+="#include <ansi.h>\n";
	header+="inherit SKILL;\n";			
	header+="string type() { return \"martial\"; }\n";
	header+="string martialtype() { return \"skill\"; }\n";
	header+="string owner() {return \""+geteuid(me)+"\";}\n";
	header+="\nmapping *action = ({\n});\n";		
	header+="// ZHAOSHI :0";			//ע�⣺���û����\n
	write_file(SKILL_D(skill_en_name),header,1);
}
void get_zhaoshi_ch_name(string yn, object ob)
{
	if( yn=="" )
	{
		write(HIW"\r�����ʽ������֣���Ҫ��ʱ���ߣ�������Զ�޷�����ȷ��������"NOR);
		input_to( (: get_zhaoshi_ch_name :), ob );
		return;
	}
	if( !check_legal_name(yn) )
	{
		write(HIW"\r�����ʽ������֣���Ҫ��ʱ���ߣ�������Զ�޷�����ȷ��������"NOR);
		input_to( (: get_zhaoshi_ch_name :), ob );
		return;
	}
	spe_skill["skill_name"]=yn;
	write(WHT"\n����һ�����ĳ�˵�ս����ָ�ϣ�����Ҫ��["+HIR+"�㡢ĳ�ˡ�ĳ��λ"NOR+WHT"]���������֣�");
	write("\n�����sword��blade�����["HIR"����"NOR+WHT"]�����������Ǿ�����");
	write( HIG"\nȭ��ʾ����"NOR+WHT"��ǰ���߳������Ƚż��أ�һʽ��������������ֱ��������ĳ�˵�ĳ��λ\n");
	write( HIG"����������"NOR+WHT"������һԾ����������һ�С����к�ء���׼��ĳ��λбб�̳�һ��\n"NOR);
	input_to( (: get_zhaoshi_ch_action :), ob);
}
void get_zhaoshi_ch_action(string yn, object ob)
{
	string err;
	string file;

	if( yn=="" )
	{
		write(WHT"\n����һ�����ĳ�˵�ս����ָ�ϣ����Ҫ��["+HIR+"�㡢ĳ�ˡ�ĳ��λ"NOR+WHT"]����������!");
		write( "\n�����sword��blade�����["HIR"����"NOR+WHT"]�����������Ǿ�����");
		write( HIG"\nȭ��ʾ����"NOR+WHT"��ǰ���߳������Ƚż��أ�һʽ��������������ֱ��������ĳ�˵�ĳ��λ\n");
		write( HIG"����������"NOR+WHT"������һԾ����������һ�С����к�ء���׼��ĳ��λбб�̳�һ��\n"NOR);
		input_to( (: get_zhaoshi_ch_action :), ob );
		return;
	}
	spe_skill["action"]=yn;
	finish_write_skill(ob);
	if(spe_skillnum==1)
	{
		ob->set("skillmaxim/"+spe_skill_basename,spe_skill_name);
		ob->set_skill(spe_skill_name,1);
		ob->add("score",-20000);
		CHINESE_D->add_translate(spe_skill_name,spe_skill["skill_ch_name"]);
	}
	log_file( "CREATESKILL", sprintf("%s(%s) %s(%s): %d (%s)\n", ob->query("name"), ob->query("id"), spe_skill["skill_ch_name"], spe_skill_name, spe_skillnum, ctime(time()) ) );
	file = SKILL_D(spe_skill["skill_en_name"]);
	if (file_size(file))
	{
		if (find_object(file)) destruct(find_object(file));
		err = catch(call_other(file,"???"));
		if (stringp(err))
		{
			log_file("CREATESKILL","ʧ�ܣ�����������"+err);
			message("channel:sys",HIR"��ϵͳ���Դ��书�༭����\n"NOR,users());
			write("�����书ʧ�ܣ�����ϵ��ֵ��ʦ�����\n");
			if (stringp(oldfile))
			{
				write_file(file,oldfile,1);
				call_other(file,"???");
			}
		}
	}
}
void finish_write_skill(object ob)
{
	string action, file, *list, content, *list2, header2, result;
	int before_skillnum,i;
	int flag,x,y;
	int d_e1,d_e2;//dodge������
	int p_e1,p_e2;//parry������
	int f_e1,f_e2;//force������
	int m_e1,m_e2;//damage������
	object me = this_player();

	header2="";
	result="";
	content="";
	action="";
	spe_skill["lvl"]  =20 * (spe_skillnum-1);
	spe_skill["action"]= replace_string(spe_skill["action"],"$BLK$", BLK);
	spe_skill["action"]= replace_string(spe_skill["action"],"$RED$", RED);
	spe_skill["action"]= replace_string(spe_skill["action"],"$GRN$", GRN);
	spe_skill["action"]= replace_string(spe_skill["action"],"$YEL$", YEL);
	spe_skill["action"]= replace_string(spe_skill["action"],"$BLU$", BLU);
	spe_skill["action"]= replace_string(spe_skill["action"],"$MAG$", MAG);
	spe_skill["action"]= replace_string(spe_skill["action"],"$CYN$", CYN);
	spe_skill["action"]= replace_string(spe_skill["action"],"$WHT$", WHT);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIR$", HIR);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIG$", HIG);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIY$", HIY);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIB$", HIB);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIM$", HIM);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIC$", HIC);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIW$", HIW);
	spe_skill["action"]= replace_string(spe_skill["action"],"$NOR$", NOR);
	spe_skill["action"]= replace_string(spe_skill["action"],"\"", "");
	spe_skill["action"]= replace_string(spe_skill["action"],"$","\n");
	spe_skill["action"]= replace_string(spe_skill["action"],"��","$N");
	spe_skill["action"]= replace_string(spe_skill["action"],"ĳ��","$n");
	spe_skill["action"]= replace_string(spe_skill["action"],"ĳ��λ","$l");
	spe_skill["action"]= replace_string(spe_skill["action"],"����","$w");
	spe_skill["action"] += NOR;
	action  = "\n([\n";
	action += "\t"+SHUANGYIN_HAO+"action"+SHUANGYIN_HAO+" : "
	        + SHUANGYIN_HAO+spe_skill["action"]+SHUANGYIN_HAO
	        + ",\n";
	action += "\t"+SHUANGYIN_HAO+"lvl"+SHUANGYIN_HAO+" : "
		+ spe_skill["lvl"]+",\n";
	action += "\t"+SHUANGYIN_HAO+"skill_name"+SHUANGYIN_HAO+" : "
		+ SHUANGYIN_HAO + spe_skill["skill_name"] + SHUANGYIN_HAO
		+ ",\n";
	action += "]),\n";
	action += "});\n";
	action += "// ZHAOSHI :"+spe_skillnum;


	file=read_file(SKILL_D(spe_skill["skill_en_name"]));
	if ((int)file==0)
	{
		write(HIR"���ܳ����쳣�ˣ�����ϵ��ʦ�����\n"NOR);
		return;
	}
	list = explode(file, "\n");
// �����ĵ�
	for(i=0;i<sizeof(list);i++)
	{
		if (list[i]=="	write\(\@HELP")	x=i;
		if (list[i]=="HELP")		y=i;
	}
	if (!stringp(spe_skill_help))
	{
		if (intp(x) && intp(y))
		spe_skill_help = implode(list[x+1..y-1],"\n");
		else
		spe_skill_help = this_player()->query("name")+"���Դ��书��\n";
	}
	spe_skill_help = replace_string(spe_skill_help,"\"","");
	spe_skill_help = replace_string(spe_skill_help,"$","\n");
// �����ĵ�����
/*
�ο�
string *spe_skill_lvl=({ "0","12","20","30","40","50","60","80","100",});
string *spe_skill_force=({ "50","80","100","130","150","180","200","220", });
string *spe_skill_unarmeddodge=({ "10","-10","-20","-30","-50","-60","-80","-90","-100", });
string *spe_skill_unarmedparry=({ "10","-10","-20","-30","-40","-50","-60","-70","-80", });
string *spe_skill_weapondodge=({ "20","10","10","5","-5","-5","-10","-10","-10", });
string *spe_skill_weaponparry=({ "20","20","10","10","5","5","5","5","5", });
*/
	if(spe_skill_basename=="unarmed")
	{
		header2=read_file(SKILL_MODEL_UNARMED);
		d_e1 = 50 - me->query("dex")/2 - 5*spe_skillnum;
		d_e2 = 50 - me->query_dex()/2  - 5*spe_skillnum;
		p_e1 = 70 - me->query("sta")/2 - 5*spe_skillnum;
		p_e2 = 70 - me->query_sta()/2  - 5*spe_skillnum;
		f_e1 = 50 + me->query("con")*3 + 10*spe_skillnum;
		f_e2 = 50 + me->query_con()*3  + 10*spe_skillnum;
		m_e1 = 0;
		m_e2 = 0;
		if (d_e1>100) d_e1=100;if (d_e1<-100) d_e1 = -100;
		if (d_e2>100) d_e2=100;if (d_e2<-100) d_e2 = -100;
		if (p_e1>100) p_e1=100;if (p_e1<-100) p_e1 = -100;
		if (p_e2>100) p_e2=100;if (p_e2<-100) p_e2 = -100;
	}
	else
	{
		d_e1 = 50 - me->query("dex")/2 - 5*spe_skillnum;
		d_e2 = 50 - me->query_dex()/2  - 5*spe_skillnum;
		p_e1 = 70 - me->query("sta")/2 - 5*spe_skillnum;
		p_e2 = 70 - me->query_sta()/2  - 5*spe_skillnum;
		f_e1 = 10 + me->query("con")*3 + 10*spe_skillnum;
		f_e2 = 10 + me->query_con()*3  + 10*spe_skillnum;
		m_e1 = 50 + me->query("str")*3 + 6*spe_skillnum;
		m_e2 = 50 + me->query_str()*3  + 6*spe_skillnum;
		if (d_e1>100) d_e1=100;if (d_e1<-100) d_e1 = -100;
		if (d_e2>100) d_e2=100;if (d_e2<-100) d_e2 = -100;
		if (p_e1>100) p_e1=100;if (p_e1<-100) p_e1 = -100;
		if (p_e2>100) p_e2=100;if (p_e2<-100) p_e2 = -100;
		if(spe_skill_basename=="sword" || spe_skill_basename=="blade")
			header2=read_file(SKILL_MODEL_WEAPON);
		else header2=read_file(SKILL_MODEL_DEFAULT);
	}

	list2 = explode(header2, "\n");
	for(i=0;i < sizeof(list2);i++)
	{
		list2[i]= replace_string(list2[i], "SKILL_EN_NAME", 
			SHUANGYIN_HAO+spe_skill_name+SHUANGYIN_HAO );
		list2[i]= replace_string(list2[i], "SKILL_CH_NAME", 
			SHUANGYIN_HAO+spe_skill["skill_ch_name"]+SHUANGYIN_HAO );
		list2[i]= replace_string(list2[i], "SKILL_BASE_NAME", 
			SHUANGYIN_HAO+spe_skill_basename+SHUANGYIN_HAO );
		list2[i]= replace_string(list2[i], "SKILL_HELP",
			spe_skill_help);
		list2[i]= replace_string(list2[i], "D_E1",sprintf("%d",d_e1));
		list2[i]= replace_string(list2[i], "D_E2",sprintf("%d",d_e2));
		list2[i]= replace_string(list2[i], "P_E1",sprintf("%d",p_e1));
		list2[i]= replace_string(list2[i], "P_E2",sprintf("%d",p_e2));
		list2[i]= replace_string(list2[i], "F_E1",sprintf("%d",f_e1));
		list2[i]= replace_string(list2[i], "F_E2",sprintf("%d",f_e2));
		list2[i]= replace_string(list2[i], "M_E1",sprintf("%d",m_e1));
		list2[i]= replace_string(list2[i], "M_E2",sprintf("%d",m_e2));
	}
	result += implode(list2,"\n");
	for (i=sizeof(list)-1;i>0;i--)
	{
		if (!stringp(list[i])) continue;
		if (sscanf(list[i],"// ZHAOSHI :%d",before_skillnum)==1)
		{
			flag = 1;
			break;
		}
	}
	if (!flag)
	{
		write(HIR"���ܳ����쳣�ˣ��뿴���������\n"NOR);
		return;
	}
	if( before_skillnum==spe_skillnum)
	{
		flag = 0;
		for(i=i-6;i>0;i--)
		{
			if (sscanf(list[i],"// ZHAOSHI :%*d")==1)
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			write(HIR"���ܳ����쳣����ˣ�����ϵ��ʦ�����\n"NOR);
			return;
		}
		content = implode(list[0..i],"\n");
		content += action;
		write_file(SKILL_D(spe_skill["skill_en_name"]),content,1);
	}
	else
	{
			content = implode(list[0..i-2],"\n");
			content+="\n// ZHAOSHI :"+(string)before_skillnum;
			content+=action;
			write_file(SKILL_D(spe_skill["skill_en_name"]),content,1);
	}
	write_file(SKILL_D(spe_skill["skill_en_name"]),"\n"+result);
}
int check_legal_basename(string name)
{
	int i;
	for(i=0;i<sizeof(valid_types);i++) 
		if(valid_types[i]==name) return 1;
	return 0;
}
int check_legal_id(string id)
{
	int i;
	i = strlen(id);
	if( (strlen(id) < 3) || (strlen(id) > 12 ) )
	{
		write("����书���ű����� 3 �� 12 ��Ӣ����ĸ��\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' )
		{
			write("����书����ֻ����Ӣ����ĸ��\n");
			return 0;
		}
        return 1;
}
int check_legal_name(string name)
{
	int i;
	i = strlen(name);
	if( (strlen(name) < 2) || (strlen(name) > 12 ) )
	{
		write("�书���������Ʊ����� 1 �� 6 �������֡�\n");
		return 0;
	}
	while(i--)
	{
		if( name[i]<=' ' )
		{
			write("����书�������ǲ����ÿ�����Ԫ��\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) )
		{
			write("����书������Ҫ�á����ġ�!\n");
			return 0;
		}
	}
	if( member_array(name,banned_name)!=-1 )
	{
		write("����书�������ƻ���������˵����š�\n");
		return 0;
	}
	return 1;
}
int check_skillnum_exist(object me,string skill_en_name,int skill_num)
{
	string file,*list;
	string playername;
	int total_zhaoshi_num;
	int flag,i;

	file=read_file(SKILL_D(spe_skill["skill_en_name"]));
	if(!file)
	{
		if(me->query("skillmaxim/"+spe_skill_basename)!=0) return 0;
		else return 1;
	}
	else list = explode(file, "\n");

	playername=geteuid(me);
	if(list[0]!="// ��������Դ��书����")
		return 0;
	if(list[1]!="// "+playername)
		return 0;
//	if(sscanf(list[sizeof(list)-1-SPE_PRA_LINES],"// ZHAOSHI :%d",total_zhaoshi_num)!=1)
//		return 0;
	for (i=sizeof(list)-1;i>0;i--)
	{
		if (!stringp(list[i])) continue;
		if (sscanf(list[i],"// ZHAOSHI :%d",total_zhaoshi_num)==1)
		{
			flag = 1;
			break;
		}
	}
	if (!flag) return -1;
	if(total_zhaoshi_num==0) return 0;
	if(total_zhaoshi_num==skill_num) return skill_num;
	if(total_zhaoshi_num+1 == skill_num) return skill_num;
	return 0;
}
int check_owner_skill(object me,string skill_en_name)
{
	string file,*list;
	string playername;

	file=read_file(SKILL_D(skill_en_name));
	if(!file)
	{
		if(me->query("skillmaxim/"+spe_skill_basename)!=0)
			return 1;
		else 
			return 0;
	}
	else list = explode(file, "\n");
	playername=geteuid(me);
	if(list[1]!="// "+playername) return 2;
	if(list[0]!="// ��������Դ��书����") return 2;
	else return 0;
}

int help (object me)
{
	write(@HELP
ָ���ʽ��editskill �书�������� �书Ӣ������ �书�������� �ڼ���
���磺editskill unarmed jueqin ����ȭ 1 
 
    �������������Լ�����书��ָ����ž���ֵ������������ʵ�ֵ���ʽ
Խ��Խ�࣬��ʽ������ҲԽ��Խ��ÿ����һ���书������Ҫ������㽭����
����
    ���������ʽ�������̶ȵķ�ʽ��ʹ�ø�ר��ָ�
    mylian����practiceҲ���ԣ������ѶȻ�Ӵ�

    �������Լ�������ʽ�������Ѷ�Ҫ��Щ�����ֻ���޸ĵ�ǰ����ʽ������
ǰ����ʽ�޷��Ķ����������Ҫ���ȹ滮���ܹ�Ҫ�����У��������޸ģ�����
��ʱ���޷��Ķ���ǰ�Ļ�����ʽ��

    �������õĻ��������У�
	unarmed,
	sword,
	blade,
ע��:
    ��ʽ��Ӣ�����ƺ��潫�����ϻ������ܵļ�����ʶ�����Ҫ������ã�һ
����ʼ�������޷�����Ķ�Ӣ�����ƣ�����������õ���Ϊjueqin-unarmed��
һ���书����ʽ�����в�Ҫ��������ַ���������ֻ�ܴ������ָ߼�����
    ��ʽ�����еģ�
    ĳ�ˣ��㣬ĳ��λ�����������ձ��ԣ��������������Ը����ֲ�ͬ���ˡ�

    ��ʽ��������Ҫ���ж��Լ������״̬����д����Ҫ���������д����ʦ
���������������Ĺ����粻���Ϲ涨������ɾ����
HELP);
	return 1;
}
