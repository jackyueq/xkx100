#include <ansi.h>

object load_data(object user,object ob);         //��login ob�ж�ȡdata
object load_skill(object user);                  //��data�ж�ȡskill
object check_user(object user,object ob);        //��logind.c����
int valid_scborn(object ob);                     //�Ƿ����ת�� ���ⲿ����
int save_data(object user,string arg);           //����ָ�����ݵ�loginob
varargs int save_skill(object user,string arg,int lvl);//����ָ��skill��login
int save_force(object user);                     //���������ڹ���login
int save_knowledge(object user);                 //��������֪ʶ���ܵ�login
varargs int save_perform(object user,string skill,string pfm);//����һ�����ܵ�pfm��login
int valid_perform(object me,string base_skill,string pfm);//�ⲿ���� �Ƿ��Ǳ����pfm
int query_scborn_times(object me);               //�ⲿ���� ת������
varargs int reborn(object user,string skill,string etc1,string etc2);//����ת����������

void create()
{
	seteuid(ROOT_UID);
}

object check_user(object user,object ob)
{
	log_file("scborn",sprintf("scborn login ob %8s first login from %15s on [%s]\n",ob->query("id"),query_ip_number(ob),ctime(time())));
	user = load_data(user,ob);
	user = load_skill(user);
	return user;
}
object load_data(object user,object ob)
{
	mapping ob_data;
	string *obd;
	int i;
	
	ob_data = ob->query("scborn/data");
	if (!mapp(ob_data)) return user;
	obd = keys(ob_data);
	for (i=0;i<sizeof(obd);i++)
		user->set(obd[i],ob_data[obd[i]]);
	ob->delete("scborn/data");
	user->set("combat_exp",100000);
	user->set("potential",50000);
	return user;
}

object load_skill(object user)
{
	int i;
	mapping skl;
	string *skname;
	
	skl = user->query("scborn/skill");
	if (!mapp(skl)) return user;
	skname = keys(skl);
	for (i=0;i<sizeof(skl);i++)
		user->set_skill(skname[i],skl[skname[i]]);
	return user;
}

//string *bid=({"jolin","waiter","solar","dugu"});
int valid_scborn(object ob)
{
	int times;
	int count,i;
	mapping skl;
	string *sklname;
	int needexp,needskill;
	
	times = this_object()->query_scborn_times(ob);
	switch(times)
	{
		case 0: //��δת����
			needexp = 5000000;
			needskill = 350;
			break;
		case 1:
			needexp = 10000000;
			needskill = 400;
			break;
		case 2:
			needexp = 20000000;
			needskill = 500;
			break;
		case 3:
			needexp = 40000000;
			needskill = 600;
			break;
		case 4:
			needexp = 80000000;
			needskill = 800;
			break;
		case 5:
			needexp = 160000000;
			needskill = 1000;
			break;
		default: 
		return notify_fail("���Ѿ�����Բ���ˣ�����Ҫת���ˡ�\n");
	}
	
	if (ob->query("combat_exp")<needexp)
	return notify_fail("��ľ�����ǳ���޷�ת����\n");
	skl = ob->query_skills();
	if (!mapp(skl)) return notify_fail("����书��û���ң��������ɡ�\n");
	sklname = keys(skl);
	for (i=0;i<sizeof(skl);i++)
		if (skl[sklname[i]]>=needskill)	count++;
	if (count < 5) return notify_fail("����书��û���ң��������ɡ�\n");
	if (!ob->query("guangming_winner")) return notify_fail("��δ��ʶ�����̹���ʥ����û�ʸ�ת����\n");
	if (!ob->query("luohan_winner")) return notify_fail("��δ��ʶ������ʮ���޺���û�ʸ�ת����\n");
	if (!ob->query("qixing")) return notify_fail("��δ��ʶ��ȫ���������û�ʸ�ת����\n");
	if (!ob->query("KILLER")) return notify_fail("��֪������ʦ��ʲô����\n");
	if (ob->query("KILLER") < needskill*(times+1)*(times+1)/10) return notify_fail("��ʦ���������̫���ˣ���Ŭ��һ�Ѱɡ�\n");
//	if ((int)ob->query("gift/qingyun")< 500 * (times+1) ) return notify_fail("����������������̫�٣�����ת����\n");
//	if (member_array(getuid(ob),bid)>=0)
//  return notify_fail("���ת������������û��ת����\n");

	return 1;
}

int save_data(object user,string arg)
{
	object ob;
		
	ob = user->query_temp("link_ob");
	if (user->query(arg))
		ob->set("scborn/data/"+arg,user->query(arg));
	return 1;
}

varargs int ssave(object user,string arg,int lvl)
{
	object ob;
	int i;
	
	ob = user->query_temp("link_ob");
	if (!file_size(SKILL_D(arg))) return 0;
	
	if ( intp(lvl) && lvl > 0)  lvl = user->query_skill(arg,1);
	else lvl = 10;
	ob->set("scborn/data/scborn/skill/"+arg,lvl);
	return 1;
}

varargs int save_skill(object user,string arg,int lvl)
{
	object ob;
	int i;
	mapping skl;
	string *sname;
		
	if (arg == "all")
	{
		skl = user->query_skills();
		if (sizeof(skl))
		{
			sname = keys (skl);
			for (i=0;i<sizeof(skl);i++)
			{
				if (SKILL_D(sname[i])->type() == "knowledge")
					ssave(user,sname[i],1);
				else 
					ssave(user,sname[i]);
			}
		}
	}
	else if (intp(lvl) && lvl > 0)
		ssave(user,arg,lvl);
	else
		ssave(user,arg);
	return 1;
}

int save_force(object user)
{
	mapping skl;
	string *sname;
	int i;
	
	skl = user->query_skills();
	if (!skl) return 1;
	sname = keys(skl);
	for (i=0;i<sizeof(sname);i++)
	{
		if (SKILL_D(sname[i])->valid_enable("force"))
			save_skill(user,sname[i]);
	}
	return 1;
}

int save_knowledge(object user)
{
	mapping skl;
	string *sname;
	int i;
	
	skl = user->query_skills();
	if (!skl) return 1;
	sname = keys(skl);
	for (i=0;i<sizeof(sname);i++)
	{
		if ((SKILL_D(sname[i])->type())=="knowledge")
			save_skill(user,sname[i],1);
	}
	return 1;
}

varargs int save_perform(object user,string skill,string pfm)
{
	object ob;
	int i;
	mixed dir;
	
	ob = user->query_temp("link_ob");
	if (!stringp(skill)) return 0;
	if (!file_size(SKILL_D(skill))) return 0;
	if (skill == "all")	{
		ob->set("scborn/data/scborn/perform/all",1);
		return 1;
	}
	if (stringp(pfm))	{
		if (!file_size(SKILL_D(skill+"/"+pfm))) return 0;
		if (!user->query("perform/"+pfm)
		&& !SCBORN_D->valid_perform(user,skill,pfm)) return 1;
		ob->set("scborn/data/scborn/perform/"+skill+"."+pfm,1);
		return 1;
	}
	dir = get_dir("kungfu/skill/"+skill+"/");
	for(i=0;i<sizeof(dir);i++)
	{
		pfm = dir[i];
		if (pfm[<2..<1]==".c") pfm = pfm[0..<3];
		if (user->query("perform/"+pfm)==1 || 
		  this_object()->valid_perform(user,skill,pfm))
			ob->set("scborn/data/scborn/perform/"+skill+"."+pfm,1);
	}
	return 1;
}

int valid_perform(object me,string special_skill,string pfm)
{
	if (!special_skill) return 0;
	if (me->query("scborn/perform/all")==1)
		return 1;
	if (me->query("scborn/perform/"+special_skill+"."+pfm)==1)
		return 1;
	return 0;
}
int valid_learn(object me,string skill)
{
	if (me->query("scborn/skill/all")==1)
	return 1;
	if (me->query("scborn/skill/"+skill)>0)
	return 1;
	return 0;
}

int query_scborn_times(object me)
{
	if (!objectp(me)) return 0;
	if (!userp(me)) return 0;
	if (!me->query("scborn/times")) return 0;
	return me->query("scborn/times");
}
int sixborn(object me)
{
	return me->query("scborn/times")==6;
}
varargs int reborn(object user,string skill,string etc1,string etc2)
{
	object ob,couple;
	int i,j,times;
	int flag;
	
	ob = user->query_temp("link_ob");
	times = this_object()->query_scborn_times(user);
	
	save_data(user,"board_last_read");   //�������԰��ȡ��Ϣ
	save_data(user,"bug");               //����bug����
	save_data(user,"bug_count");         //����bug�����ܺ�
	save_data(user,"home");              //���淿��
	save_data(user,"weapon");            //��������
// һת Ӧ���� reborn(user,"taiji-quan","zhen"); ����taiji-quan��pfm zhen
// ��ת Ӧ���� reborn(user,"taiji-quan","literate"); ���� ��������
// ��ת Ӧ���� reborn(user,"taiji-quan","taiji-shengong"); ����
// ��ת Ӧ���� reborn(user,"taiji-quan","taiji-jian");
// ��ת Ӧ���� reborn(user,"taiji-quan","taiji-jian","huifeng-jian");
// ��ת Ӧ���� reborn(user);
	switch(times)
	{
		case 0:
			save_skill(user,skill);           //����һ������100��
			if (stringp(etc1))
				save_perform(user,skill,etc1);  //���漼�ܵ�һ��pfm
			ob->set("scborn/times",1);        //��¼�Ѿ�ת������
			break;
		case 1:
			save_skill(user,skill);          //����һ������100��
			save_perform(user,skill);	       //�Լ�������ܵ�����pfm
			save_skill(user,etc1,1);           //��������һ��֪ʶ����
			ob->set("scborn/times",2);       //��¼�Ѿ�ת������
			break;
		case 2:
			save_skill(user,skill);          //����һ������
			save_perform(user,skill);	       //�Լ�������ܵ�����pfm
			save_knowledge(user);            //��������֪ʶ����
			save_skill(user,etc1);         //����һ���ڹ�
			ob->set("scborn/times",3);       //��¼�Ѿ�ת������
			break;
		case 3:
			save_skill(user,skill);          //����һ������
			save_perform(user,skill);	       //�Լ�������ܵ�����pfm
			save_skill(user,etc1);           //����һ������
			save_perform(user,etc1);         //�Լ�������ܵ�����pfm
			save_force(user);                //���������ڹ�
			save_knowledge(user);            //��������֪ʶ����
			ob->set("scborn/times",4);       //��¼�Ѿ�ת������
			break;
		case 4:
			save_skill(user,skill);          //����һ������
			save_perform(user,skill);	       //�Լ�������ܵ�����pfm
			save_skill(user,etc1);           //����һ������
			save_perform(user,etc1);         //�Լ�������ܵ�����pfm
			save_skill(user,etc2);           //����һ������
			save_perform(user,etc2);         //�Լ�������ܵ�����pfm
			save_force(user);                //���������ڹ�
			save_knowledge(user);            //��������֪ʶ����
			ob->set("scborn/times",5);       //��¼�Ѿ�ת������
		  break;
		case 5:
			save_skill(user,"all");          //�������м���
			save_perform(user,"all");        //��������pfm
			ob->set("scborn/times",6);       //��¼�Ѿ�ת������
		  break;
		default: return notify_fail("����ת����Χ��\n");
	}
	ob->set("scborn/reset_gift",1);
	if (ob->query("couple/have_couple"))
	{
		if (!couple = find_player(ob->query("couple/couple_id")))
		{
			flag = 1;
			couple = NPC_D->create_player(ob->query("couple/couple_id"));
		}
		if (objectp(couple))
		{
			couple->delete("couple");
			couple->save();
			tell_object(couple,"���"+couple->query("couple/couple_gender")+"��ɱ�ˣ����ǵĻ�����ϵ����ˡ�\n");
			if(flag == 1) destruct(couple);
		}
		ob->delete("couple");
	}
	return ob->save();
}
