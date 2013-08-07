// expell.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

	string *base_skill = ({
		"array",     	"axe",     	"blade",
		"claw",      	"club",    	"cuff", 
		"dagger",    	"dodge",   	"force",   
		"finger",    	"gambling" 	"hammer", 
		"hand",      	"hook",		  "leg",
	  "literate", 	"parry",     	"spear",   	
		"staff",	    "stick",     	"strike",  	
		"sword", 	    "throwing",  	"unarmed", 	
		"whip"
	});
int main(object me, string arg)
{
	object ob;
	string skill_name;
	int skill_level;
	mapping ob_skills,smap,pmap;
	mapping myfam;
	int i;
	
	myfam =(mapping)me->query("family");
	
	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("��Ҫ��˭���ʦ�ţ�\n");

	if( !ob->is_character() || !myfam)
		return notify_fail("���𲻶�����\n");

	if( !userp(ob) )
		return notify_fail("��ֻ�ܿ�����������ݵ����\n");
	
	if(
	ob->query("combat_exp")>10000
	&&(myfam["title"]!= "��ɽ��ʦ")
	&&(myfam["title"]!= "����")
	&&(myfam["title"]!= "�ܶ���")
	&&(me->query("id")!= "feng qingyang")
	&&(myfam["title"]!= "����")
	)
		return notify_fail("�Է�����̫�ߣ�����Ҫ��������ʦ��Ϊ�������ˣ�\n");

		if( ob->is_apprentice_of(me) )
		{
			message_vision("\n$N����$n˵�����ӽ���������ʦͽ������������߰ɣ�\n\n", me, ob);
			tell_object(ob, "\n�㱻ʦ�������ʦ���ˣ�\n\n");
		}
		else if( me->query("family/privs")==-1 &&
		(string)me->query("family/family_name") ==
		(string)ob->query("family/family_name") )
	{
		message_vision("\n$N����$n˵�����ӽ���������Ҳ������" + me->query("family/family_name") + "�ĵ����ˣ����߰ɣ�\n\n", me, ob);
		tell_object(ob, "\n�㱻" + me->query("family/title") + "�����ʦ���ˣ�\n\n");
	}  else
			return notify_fail("����˲�����ĵ��ӡ�\n");

	ob->add("detach/"+ob->query("family/family_name"),1);
	ob->delete("family");
//	ob->delete("title");
	ob->set("title","��ͨ����");
	ob->set("score", 0);
	ob->add("expell", 1);
	ob_skills = ob->query_skills();
	smap = (mapping)ob->query_skill_map();
        pmap = (mapping)ob->query_skill_prepare();
/*
	if( mapp(skills) )
	{
		skname = keys(skills);
		for(i=0; i<sizeof(skname); i++)
			skills[skname[i]] /= 2;
	}
*/
		for (i = 0; i < sizeof(ob_skills); )
		{
			skill_name = keys(ob_skills)[i];
			skill_level = ob_skills[skill_name];
			if (member_array(skill_name, base_skill) != -1)
			{
				skill_level = skill_level / 2;
				if (skill_level == 0)
					map_delete(ob_skills, skill_name);
				else
				{
					ob_skills[skill_name] = skill_level;
					i ++;
				}
			}
			else
			{
				map_delete(ob_skills, skill_name);
			}
			
		}
                for (i = sizeof(smap)-1; i >= 0; i --)
                        ob->map_skill(keys(smap)[i]);
                for (i = sizeof(pmap)-1; i >= 0; i -- )
                        ob->prepare_skill(keys(pmap)[i]);
                ob->reset_action();
		ob->set("jiali",0);
		ob->delete("perform");
		ob->delete("can_perform");
		if (!ob->is_busy()) ob->start_busy(5);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : expell|kaichu <ĳ��>
 
    ���ָ��������㿪�����ɲŵĵ��ӣ��������ĵ������л������ܶ���
����ԭ����һ�룬�书ȫ�ϣ��ۺ�����һ��Ҳ�����㣬�����һ�������
����һ�������������ء��Ĵ���������ڿ���һ������֮ǰ����������ǡ�
 
HELP
	);
	return 1;
}
