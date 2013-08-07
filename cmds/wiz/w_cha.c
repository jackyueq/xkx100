// skills.c
// ������ʦ�쿴��������Ҽ��ܵĹ��ܡ�
// Added by Spacenet@FXLT 1.18.2000

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
	BLU"����һ��",BLU"��������",BLU"����ҳ�",BLU"��ѧէ��",BLU"����ǿǿ",
	HIB"�����ž�",HIB"����é®",HIB"��֪һ��",HIB"����ͨͨ",HIB"ƽƽ����",
	CYN"ƽ������",CYN"��ͨƤë",CYN"��������",CYN"������",CYN"����С��",
	HIC"����С��",HIC"������Ⱥ",HIC"�������",HIC"�������",HIC"�ڻ��ͨ",
	HIG"�������",HIG"¯����",HIG"��Ȼ����",HIG"���д��",HIG"���д��",
	YEL"��Ȼ��ͨ",YEL"�������",YEL"�޿�ƥ��",YEL"����Ⱥ��",YEL"����似",
	HIY"�����뻯",HIY"��ͬ����",HIY"����Ⱥ��",HIY"�Ƿ��켫",HIY"�����ױ�",
	RED"��������",RED"һ����ʦ",RED"�������",RED"�񹦸���",RED"������˫",
	WHT"��������",WHT"���춯��",WHT"������",WHT"������ʥ",WHT"�������",
	HIW"��ǰ����",HIW"���˺�һ",MAG"��ز�¶",HIM"��ɲ�",HIR"��豹���" 
});

string *knowledge_level_desc = ({
	BLU"��ѧէ��",BLU"�����ž�",HIB"��֪һ��",HIB"��������",
	CYN"������",CYN"����С��",HIC"�ڻ��ͨ",HIC"�������",
	GRN"��Ȼ���",GRN"��Ȼ��ͨ",YEL"��ͬ����",YEL"������˫",
	HIY"������",RED"�����ױ�",WHT"������ʥ",HIW"��ǰ����",
});

string skill_level(string, int);

int main(object me, string arg)
{
	object ob;
	mapping skl, lrn, map;
	string *sname, *mapped, str, skill1;
	int i, flag = 0, parents = 0;

	seteuid(getuid());

	if(!arg || arg == me->query("id"))
		ob = me;
	else
	{
		if( sscanf(arg, "%s %s", arg, skill1) >= 3 )
			return notify_fail("��Ҫ�쿴ʲô��\n");
		ob = present(arg, environment(me));
//		if ( ob->query("SPSKILLS", 1)  ) return ob->skills();
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (wizardp(me))
		{
			if (!ob)
			{
				ob = new(USER_OB);
				seteuid(arg);
				export_uid(ob);
				flag = 1;
				if (!ob->restore())
					return notify_fail("û�������ҡ�\n");
			}
		}else
		{
			if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
		       	if( ob->query("parents"))
		       		if (member_array(me->query("id"), ob->query("parents")) >=0 )
		       			parents = 1;
		       		else return notify_fail("ֻ�е����ܲ쿴�����ļ��ܡ�\n");

		}
	}

	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
	&& !me->is_apprentice_of(ob) && parents!=1 )
		return notify_fail("ֻ����ʦ����ʦͽ�������ϵ�����ܲ쿴���˵ļ��ܡ�\n");

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( (ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
		return 1;
	}
	write( (ob==me ? "��" : ob->name()) +"Ŀǰ��ѧ���ļ��ܣ�\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	str = "\n";
	str += HIC"��"HIY"������������������������������������������������������������������"HIC"��\n"NOR;
	if (!skill1)
	{
		for(i=0; i<sizeof(skl); i++)
		{
			str += sprintf("%s%s%-40s"NOR" - %-10s "NOR"%3d/%5d  "HIM"%s\n"NOR, 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "��"),
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
			(wizardp(me) ? chinese_number((60-SKILL_D(sname[i])->learn_bonus()-SKILL_D(sname[i])->practice_bonus())/6) : ""));
		}
	}
	else
	{
		for(i=0; i<sizeof(skl); i++)
		{
			if (sname[i] == skill1)
			{
			str += sprintf("%s%s%-40s"NOR" - %-10s "NOR"%3d/%5d  "HIM"%d\n"NOR, 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "��"),
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
			(wizardp(me) ? chinese_number((60-SKILL_D(sname[i])->learn_bonus()-SKILL_D(sname[i])->practice_bonus())/6) : ""));
			}
		}
	}
//	write("\n");
	str += HIC"��"HIY"������������������������������������������������������������������"HIC"��\n"NOR;
	str += sprintf("%s\n", flag?"�����Ŀǰ�������ϡ�":"");
	me->start_more(str);
	if (flag)
		destruct(ob);
	return 1;
}

string skill_level(string type, int level)
{
	int grade;


	switch(type) {
		case "knowledge":
			grade = level / 30;
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			grade = level / 10;
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}
// ����ļ��ܡ���������á���pet���������á�
string pet_skill(object ob)
{
	string desc;
	object  *list, couple_ob;
	mapping skl, lrn, map;
	string *sname, *mapped,target,cardname;
	int i, marry_flag;

	seteuid(getuid());
	skl = ob->query_skills();
	if(!sizeof(skl)) {
		desc =  ob->name() + "Ŀǰ��û��ѧ���κμ��ܡ�\n";
		return desc;
	}
		desc =  ob->name() +"Ŀǰ��ѧ���ļ��ܣ�\n\n";
	sname  = sort_array( keys(skl), (: strcmp :) );

	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);

	for(i=0; i<sizeof(skl); i++)
	{
		desc += sprintf("%s%s%-40s" NOR " - %-10s "NOR"%3d/%5d\n",
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "��"),
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],);
	}
	return desc +"\n";
}

int help(object me)
{
	write(@HELP
ָ���ʽ : skills|cha [<ĳ��>] [<������>]

���ָ���������(��)��ѯ��ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills ���Բ�֪�Է��ļ���״����

��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����

HELP
    );
    return 1;
}
