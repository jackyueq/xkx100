// wg_caidi1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�˵�");
	set("long", @LONG
�����ǿ�˵أ����ڳ��ڵò������õ��չˣ��˵����Ӳݴ�������
�Ĳ˶����Ʋ��ã�����ģ��ض����ˡ�
LONG);
	set("exits", ([
		"north" : __DIR__"wg_houyuan3",
	]) );
	set("objects", ([
		__DIR__"npc/wg_guanjia5" : 1,
		__DIR__"npc/wg_nsldizi":1,
	]));
	set("outdoors", "wuguan");
 	setup();
}

void init()
{
	add_action("do_chu", "chu");
	add_action("do_chu", "��");	
}
int do_chu(string arg)
{
	object me,weapon;
	int costj, costq,c_exp,c_skill;
	me = this_player();

	if(me->query_temp("job_name")!="����") 
		return notify_fail("���������������⹤������������ɻ\n");
	if (me->is_busy()) return notify_fail("��������æ���أ�\n");
	if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר�ĸɻ\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "chutou")
		return notify_fail("������ʲô�����ݣ�������\n");
	if ( !arg || arg != "��" ) return notify_fail("��Ҫ��ʲô��\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;
	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N��һ�ɣ���С�ĳ������Լ��Ľ��ϣ�\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/��") > 10+(random(10)) &&
		present("caiyuan guanshi", environment(me)))
	{
		me->set_temp("mark/������",1);
		message_vision(RED"��԰���¶�$N˵���ɵĲ������ˣ�����Ի�ȥ����(job ok)�ˡ�"NOR, me);
		return 1;
	}
	message_vision("$N�����ͷ�����ŵ��ϵ��Ӳݳ���������\n", me);
	me->start_busy(3);
	me->add_temp("mark/��",1);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("staff",1);
	if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
		(int)me->query_skill("staff", 1) < 30 && random(10)>5 )
	{
		write(HIM"���ڳ����ж����ȵ��÷���Щ��ᣡ\n"NOR);
		me->improve_skill("staff", (int)(me->query("int") / 10));
	}
	return 1;
}

