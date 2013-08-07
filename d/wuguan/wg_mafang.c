// wg_mafang.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "��");
	set("long", @LONG
������������������ģ����˼�ʮƥ���㿴��ȥ�������϶�
�����ˣ���ϴϴ�ˣ��Ա��и�ˮ�أ�������Щ��ˮ��
LONG);
	set("exits", ([
		"south" : __DIR__"wg_houyuan2",
	]) );
	set("objects", ([
		__DIR__"npc/wg_guanjia3" : 1,
	]));
	setup();
}
void init()
{
	add_action("do_sao", "clean");
	add_action("do_sao", "sao");	
}
int do_sao(string arg)
{	 
	object me, weapon;
	int costj, costq,c_skill,c_exp;
	me = this_player();

	if(me->query_temp("job_name")!="��ɨ��") 
		return notify_fail("���������������⹤�������������! \n");
	if(me->query_temp("mark/ɨ����")) 
		 return notify_fail("���Ѿ�������ˣ���ȥ����(job ok)�ɣ�\n");
	if (me->is_busy()) return notify_fail("��������æ���أ�\n");
	if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר�ĸɻ\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "saozhou")
		return notify_fail("������ʲô����ɨ������ɨ��\n");

	if ( !arg || arg != "��" ) return notify_fail("��Ҫ��ɨʲô��\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N��һ������С�Ļ����ڷ�������һ�����࣡\n",me);
		me->add("food", 10);
		me->unconcious();
		return 1;
	}
	
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/ɨ") > 10 + random(10) &&
		present("mafang guanshi", environment(me)))
	{
		me->set_temp("mark/ɨ����",1);
		message_vision(RED"�����¶�$N˵���ɵĲ������ˣ�����Ի�ȥ����(task ok)�ˡ�\n"NOR, me);
		return 1;
	}
	message_vision("$N���˸��ط���ʼɨ���������湻���ģ��㲻�ɱս��˺�����\n", me);
	me->start_busy(3);
	me->add_temp("mark/ɨ",1);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("club",1);
	if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
		(int)me->query_skill("club", 1) < 30 && random(10)>5 )
	{
		write(HIM"����ɨ���ж��ڹ����÷���Щ��ᣡ\n"NOR);
		me->improve_skill("club", (int)(me->query("int") / 10));
	}
	return 1;
}



