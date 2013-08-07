// Room: /d/nanshaolin/xjchu.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
int do_pi(string arg);
void create()
{
	set("short", "�����");
	set("long", @LONG
һ�䲻���С�ݣ����а���һ�ڴ���������ð�����ڵ�������һ��
�������������ڡ�����������æ�żӲ�ɿ��ȫ�µ���������ζ�
Ҫ���ࡣһλ����ɮ�����ų��صĴ����ף����ڳ����Ľ�����������
LONG );
	set("exits", ([
		"south"  : __DIR__"zhaitang",
	]) );
	set("objects", ([
		__DIR__"npc/szseng" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6260);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_ao", "ao");
	add_action("do_ao", "��");
}
int do_ao(string arg)
{
	object ob, me = this_player();
	int costj, costq,times,lvl1,lvl2,exp;

	exp = me->query("combat_exp");
	lvl1 = me->query_skill("hand",1);
	lvl2 = me->query_skill("finger",1);
	if(me->query_temp("job_name")!="����") 
		return notify_fail("�����ɲ���������ĵط����㻹���߿��ɣ�\n");
	if (me->is_busy())
	{
		write("��������æ���أ�\n");
		return 1;
	}
	if (me->is_fighting())
	{
		write("������ս����,�޷�ר�ĸɻ\n");
		return 1;
	}
	if ( !arg || arg != "��" )
	{   
		message_vision("$NҪ��ʲô��\n",me);
		return 1;
	}
	costj = random((int)me->query("con")/3);
	costq = random((int)me->query("str")/3);
	times=20+random(10);
	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N��һ�ɣ��������\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);	
	if (((int)me->query_temp("mark/��")>times) &&
		(present("shizhou seng", environment(me))))
	{
		me->add("potential",(int)(me->query_skill("buddhism",1)/5)+30);
		me->add("combat_exp",(int)(me->query_skill("buddhism",1)/5)+60);
		me->delete_temp("job_name");
		me->delete_temp("mark");
		return notify_fail(RED "����ɮ˵������л�������ҵ�æ�����ǿ��ȥ�ɣ�����\n"NOR);
	}
	me->start_busy(1);
	message_vision("$N����һ����˫�Ź�ס�����������ڿ��У��ӹ������������������\n", me);
	me->add_temp("mark/��",1);
	if ( (int)me->query_skill("hand", 1) < 20 && random(10)>6 )
	{
		if(lvl1 * lvl1 * lvl1 / 10 < exp)
		{
			write(HIM"���ڻ��������У������Ϲ�����Щ����\n"NOR);
			me->improve_skill("hand", (int)(me->query_skill("buddhism",1) / 5));
		}
		if(lvl2 * lvl2 * lvl2 / 10 < exp)
		{
			write(HIM"���ڻ��������У���ָ�Ϲ�����Щ����\n"NOR);
			me->improve_skill("finger", (int)(me->query_skill("buddhism",1) / 5));
		}
	}
	return 1;
}
