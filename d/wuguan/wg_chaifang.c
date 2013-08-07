// wg_chaifang.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
������ﶣ�����ѵģ�����ϸһ����������������������ر��
����һ�߶������Ѿ���̵�ľͷ��������һ�����õĲ��ȴû�ж��١�
LONG);
	set("exits", ([
		"north" : __DIR__"wg_houyuan",
	]) );
	set("objects", ([
		__DIR__"npc/wg_guanjia1" : 1,
		__DIR__"npc/wg_qingchengdizi" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_pi", "pi");
	add_action("do_pi", "��");	
}
int do_pi(string arg)
{	 
	object me,weapon;
	int costj, costq,c_skill,c_exp;
	me = this_player();

	if(me->query_temp("job_name")!="����") 
		return notify_fail("���������������⹤�������������! \n");
	if (me->is_busy()) return notify_fail("��������æ���أ�\n");
	if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר�ĸɻ\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "chaidao")
		return notify_fail("������ʲô������������\n");

	if ( !arg || arg != "��" )
		return notify_fail("��Ҫ��ʲô��������\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N��һ�ᣬ��С�������Լ�������\n",me);
		me->receive_wound("qi", 20);
		me->set_temp("last_damage_from", "��С�ı��Լ���");
		me->unconcious();
		return 1;
	}

	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);	   

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/��") > 10 + random(10) &&
		present("chaifang guanshi", environment(me)))
	{
		me->set_temp("mark/������",1);
		message_vision(RED"�񷿹��¶�$N˵���ɵĲ������ˣ�����Ի�ȥ����(job ok)�ˡ�"NOR, me);
		return 1;
	}  
	message_vision("$N����һ��ľͷ��һ��������ȥ�����ѡ���һ����ľͷ����Ϊ��Ƭ��\n", me);
	me->start_busy(3);
	me->add_temp("mark/��",1);

	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("blade",1);
	if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
		(int)me->query_skill("blade", 1) < 30 && random(10)>5 )
	{
		write(HIM"���������ж��ڵ����÷���Щ��ᣡ\n"NOR);
		me->improve_skill("blade", (int)(me->query("str") / 10));
	}
	return 1;
}

