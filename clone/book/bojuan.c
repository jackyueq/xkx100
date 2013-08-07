// bojuan.c

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
int do_study(string arg);

void init()
{
	add_action("do_study", "yanxi");	
}
void create()
{
	set_name("����", ({ "bo juan", "bo", "juan" }));
	set_weight(50);
	set("no_drop", "�������������뿪�㡣\n");
        set("unit", "��");
        set("long", "����һ��������д�� ��\nׯ�ӡ���ң�Ρ����ƣ��֮����ڤ���ߣ����Ҳ�������ɣ������ǧ�������\n�ƺ���ͨ��(yanxi)����������.\n");
	set("value", 500);
	set("material", "silk");
	setup();
}


int do_study(string arg)
{
	object me = this_player();
	int cost=10,myskill;	

	if ( arg != "bo" && arg != "juan" && arg !="bo juan" )
		return notify_fail("��Ҫ��ʲô��\n");
	if( (int)me->query("jing") < 25 )
	{
		write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
		return 1;
	}
	if (me->is_busy()) return notify_fail("��������æ���ء�\n");
	if (me->query("family")==0||me->query("family")["family_name"]!="��ң��") 
		return notify_fail("��ѧ������ı�ڤ�񹦣������������ң�ɡ�\n");
	if ( me->is_fighter()) return notify_fail("ս�����޷��Ķ���֪��\n");

	if ( (int)me->query_skill("beiming-shengong",1) >= 20 &&
		(int)me->query_skill("beiming-shengong",1) <= 100 )
	{
	    if ((int)me->query("jing")>cost)
	       	{ myskill=(int)me->query_skill("beiming-shengong",1);
               	  if (myskill*myskill*myskill/10>(int)me->query("combat_exp") )
                   {  return notify_fail("Ҳ����ȱ��ʵս���飬��Բ�������˵�Ķ��������޷����!\n");
                    }
              	  else  
                      { me->receive_damage("jing", 20);
			me->improve_skill("beiming-shengong", (me->query_skill("beiming-shengong",1)+me->query("int")));
			message_vision("$N����ר���ж���ڤ���ķ���\n", me);
			return 1;
                       }
		}
	    else
		{
			cost=me->query("jing");
			write("�����ڹ���ƣ�룬�޷�ר�������ж���ڤ���ķ���\n");
		}
	}
	if ((int)me->query_skill("beiming-shengong",1) > 100 )
	{
		return notify_fail("����Ų�������ȥ���޷����������������ĵ���\n");
	}
	return notify_fail("����Ų�������ȥ��û����ʲô���������\n");
}


