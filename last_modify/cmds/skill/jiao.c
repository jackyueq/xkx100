// /cmds/skill/jiao.c

// Modified by Constant Jan 11 2001
// Modified by Zeratul Jan 11 2001 teach������ʱ�����ƣ��Ǻ�

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, student, skill_name;
	object ob;
	int student_skill, my_skill, gin_cost, grade, student_combat_exp;
	int improve_points;

	if (me->is_busy()) return notify_fail("��������æ���ء�\n");

	if(!arg || (sscanf(arg, "%s %s", student, skill)!=2 ))
		return notify_fail("ָ���ʽ��teach <ĳ��> <����>\n");

	if( me->is_fighting() ) return notify_fail("����ĥǹ������������\n");

	if(!me->query("couple/have_couple")) 
		return notify_fail("�㻹û�а����أ�\n");

	if( !(ob = present(student, environment(me))) || !ob->is_character())
		return notify_fail("��Ҫ��˭��\n");

	if( student != me->query("couple/couple_id") ||
		me->query("id") != ob->query("couple/couple_id") )
	{
		if ((string)me->query("gender") == "Ů��") 
			return notify_fail("����������ɷ�\n");
		else return notify_fail("������������ӡ�\n"); }
	
	if ( time() - me->query("last_sleep_couple") > 259200
	  || time() - ob->query("last_sleep_couple") > 259200 )
	  	return notify_fail("���Ƿ���̫��ʱ��û�н��������������ˣ���ʲôҲѧ���ᡣ\n");

	if( !living(ob) )
		return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");

	if (ob->is_busy())
		return notify_fail(ob->name() + "������æ���ء�\n");

	if( ob->is_fighting() ) return notify_fail("����ĥǹ������������\n");

	if( !my_skill = me->query_skill(skill, 1) )
		return notify_fail("������㻹�����أ�\n");

	if( ob->prevent_learn(me, skill) ) return 0;

	student_skill = ob->query_skill(skill, 1);

	if( my_skill <= student_skill )
		return notify_fail("�����" + ob->name() + "�ĳ̶��Ѿ����������ˡ�\n");

	if( !SKILL_D(skill)->valid_learn(ob) ) 
		return notify_fail("��" + ob->name() + "Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");

	gin_cost = 300 / ((int)me->query("int") + (int)ob->query("int"));

	if( !student_skill )
	{
		gin_cost *= 2;
		ob->set_skill(skill,0);
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٽ��ˡ�\n");

	if( (int)ob->query("learned_points") >= (int)ob->query("potential") )
		return notify_fail(ob->name() + "��Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");

	printf("����%s�����йء�%s�������ʡ�\n", ob->name(),
		to_chinese(skill));

	if( ob->query("env/no_learn") )
		return notify_fail("����" + ob->name() + "���ڲ���׼������������⡣\n");

	tell_object(ob, sprintf("%s��������йء�%s�������⡣\n",
		me->name(), to_chinese(skill)));

	if( (int)me->query("jing") > gin_cost ) {
		if( userp(me) ) me->receive_damage("jing", gin_cost );
	} else {
		write("������̫���ˣ�û�а취�ٽ�" + ob->name() + "��\n");
		tell_object(ob, "����" + me->name() + "��Ȼ̫���ˣ�û�а취����ʲ�ᡣ\n");
		return 1;
	}
		
	student_combat_exp = (int)ob->query("combat_exp");

	if(student_combat_exp < 1000000)
		grade = 1;
	else if(student_combat_exp < 8000000)
		grade = 2;
	else if(student_combat_exp < 30000000)
		grade = 3;
	else
		grade = 4;

	if((int)ob->query("jing") > gin_cost )
	{
		if( (string)SKILL_D(skill)->type()=="martial"
		&& student_skill * student_skill * student_skill / 10 > student_combat_exp)
		{
			tell_object(ob, "Ҳ����ȱ��ʵս���飬���" + me->name() + "�Ľ��������޷���ᡣ\n");
		}
		else
		{
		if(skill_name = SKILL_D(skill)->query_skill_name(student_skill))
			tell_object(ob, "������" + me->name() + "��ָ������" + skill_name + "��һ���ƺ���Щ�ĵá�\n");
		else
			tell_object(ob, "������" + me->name() + "��ָ�����ƺ���Щ�ĵá�\n");
             
   			me->add("learned_points", 1);
			ob->add("learned_points", 1);
			
			// �������޼�ѧϰ���ܵ��ٶȣ����ض����ĳͷ���
			// Added by Constant Jan 11 2001
			improve_points = (me->query("int") + ob->query("int")) / 2;
			improve_points = improve_points * grade / 
					  (me->query("divorce") + 
					   ob->query("divorce") + 1);
			if (improve_points < 10)
				improve_points = 10;
			improve_points = random(improve_points);

			ob->improve_skill(skill, improve_points);
		}
	}
	else
	{
		gin_cost = ob->query("jing");
		tell_object(ob, "�����̫���ˣ����ʲôҲû��ѧ����\n");
	}

	ob->receive_damage("jing", gin_cost );

	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : teach | jiao <ĳ��> <����>
 
���ָ�������������İ��½����й�ĳһ�ּ��ܵ��������⣬��Ȼ����İ�������
����ϵ�����������ͣ�����İ��¾������ַ�ʽѧϰ�����ļ���Ҳ�����ܸ��
�㣬Ȼ����Ϊ���ִ��ڷ�ʽ�൱�һ�֡�����Ĵ��С�����������˵����Ϥһ����
���ܽϿ�ķ�����

����ѧϰҲ��Ҫ����һЩ�����������ĵľ��������Լ�������İ��µ����ԣ��Լ���
�˵Ķ����̶��йء�

�������ָ�� : apprentice, practice, skills, study, learn
HELP
        );
        return 1;
}

