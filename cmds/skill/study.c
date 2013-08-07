// study.c
// ������û�п���learn_bonus��practice_bonus�������ǡ�

#include <skill.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object where = environment(me);
	object ob;
	string zhao_name, book_name;
	string *args;
	mapping skill;
	int my_skill, cost, times, i, success=0;
	int j;

	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
	if (where->is_chat_room())
    return notify_fail("�����ֹ������\n");
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() )
		return notify_fail("���޷���ս����ר�������ж���֪��\n");
//	if(sscanf(arg, "%s %d", book_name, times)!=2 )
//		return notify_fail("ָ���ʽ��study|du <����> <����>\n");
//ȡ����
	if (! arg || (i = sizeof(args = explode(arg, " "))) < 1)
         return notify_fail("ָ���ʽ��study|du <����> <����>\n");
        i--;
        if (i >= 1 && sscanf(args[i], "%d", times) && times)
                i--;
        else
                times = 1;
        if (args[i] == "with" && i >= 1)
                i--;
        book_name = implode(args[0..i], " ");


	if (times < 1 || times > 100)
		return notify_fail("�����������һ�Σ���಻�ܳ���һ�ٴΡ�\n");
	if(!objectp(ob = present(book_name, me)) )
		return notify_fail("û�Ȿ��ɶ�����\n");
	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("���޷�����������ѧ���κζ�����\n");
	if( !me->query_skill("literate", 1) )
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	message("vision", me->name() + "��ר�ĵ��ж�" + ob->name() + "��\n", environment(me), me);
	if( (int)me->query("combat_exp") < skill["exp_required"] )
	{
		write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
		return 1;
	}
	notify_fail("����Ŀǰ����������û�а취ѧ������ܡ�\n");
	if( !SKILL_D(skill["name"])->valid_learn(me) ) 
	return 0;
	cost = skill["jing_cost"] + skill["jing_cost"] 
		* (skill["difficulty"] - (int)me->query("int"))/20;
	if (cost < 10) cost = 10; // minimum cost
	if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
	{
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
	}
	if( me->query_skill(skill["name"], 1) < skill["min_skill"] )
	{
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫����ˣ������ջ�\n");
	}
	if( !me->query_skill(skill["name"], 1)) me->set_skill(skill["name"], 0);
	my_skill = me->query_skill(skill["name"], 1);
	if( (string)SKILL_D(skill["name"])->type()=="martial" &&
			my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
		{
			return notify_fail("Ҳ����ȱ��ʵս���飬���"+ob->name()+"������˵�Ķ��������޷���ᡣ\n");
		}
		if (!me->query("env/auto_regenerate") && 
        				me->query("jing")< cost * times)
							return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
	for (i = 0; i < times; i++)
			{        	

			if ((int)me->query("jing") > cost)
            me->receive_damage("jing", cost );
      else if (me->query("env/auto_regenerate") &&
                SKILL_D("force/regenerate")->exert(me, me))
              {
                        // try to regenerate & learn again
                        write("����þ������һЩ���������顣\n");
                        i--;
                        continue;
              } else
              {
                        me->set("jing", 0);
                        break;
              }
			}
	if (!i) 
		return notify_fail("������̫���ˣ����һ��Ҳû�п���ȥ��\n");
	if(zhao_name = SKILL_D(skill["name"])->query_skill_name(my_skill))
				printf("���ж���"+chinese_number(i)+"���й�%s�ļ��ɣ��ԡ�%s����һ���ƺ���Щ�ĵá�\n", to_chinese(skill["name"]), zhao_name);
			else
				printf("���ж���"+chinese_number(i)+"���й�%s�ļ��ɣ��ƺ��е��ĵá�\n", to_chinese(skill["name"]));

	for (j=0;j<i;j++)
	{
//ԭ�����ٶ�			me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/5+1);   
     me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/3+1);
	}
//	if (i < times)
//	return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
	return 1;
}

int help(object me)
{
	write( @HELP
ָ���ʽ: study | du <��Ʒ����> <����>

    ���ָ��ʹ�����ͨ���Ķ����Ż�������Ʒ��ѧĳЩ���ɣ���ǰ
����: �㲻���Ǹ�����ä����������ä��ȥѧ�Ļ�����

see also : learn
HELP
	);
	return 1;
}
