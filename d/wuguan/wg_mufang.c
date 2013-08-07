#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ľ��");
	set("long", @LONG
һ���ݣ���ͱ��޴�ĺ�������ס�ˣ�������˺ö೤��ľͷ��׼
��Ҫ������õģ���������ȥ��ǰ�ȵðѳ�ľͷ��̳�һ�ؽصģ���
���ø�ͷ�������㿴���������ڷ����ľ��š�
LONG);
	set("exits", ([
		"north" : __DIR__"wg_houyuan2",
	]) );
	set("objects", ([
		__DIR__"npc/wg_guanjia2" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_pi", "ju");
	add_action("do_pi", "��");	
}

int do_pi(string arg)
{ 
	object me,weapon;
	int costj, costq,i,c_exp,c_skill;
	i=0;
	me = this_player();

	if(me->query_temp("job_name")!="��ľͷ") 
		return notify_fail("���������������⹤�������������! \n");
	if (me->is_busy()) return notify_fail("��������æ���أ�\n");
	if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר�ĸɻ\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("id")!= "juzi")
		return notify_fail("������ʲô����ľͷ����������\n");

	if ( !arg || arg != "ľͷ" ) return notify_fail("��Ҫ��ʲô��\n");

	costj = random((int)me->query("con")/3)+1;
	costq = random((int)me->query("str")/3)+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("ľͷͻȻ���ˣ�$Nһû�����õ�������ľͷ������ͷ�ϣ�\n",me);
		me->unconcious();
		return 1;
	}
	
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);

	if (!(int)me->query_condition("wuguan_job") &&
		(int)me->query_temp("mark/��") > 10 + random(10) &&
		present("mufang guanshi", environment(me)))
	{
		me->set_temp("mark/������",1);
		message_vision(RED"ľ�����¶�$N˵���ɵĲ������ˣ������ȥ���ܹ��Ǹ���(job ok)�ˡ�"NOR, me);
		return 1;
	}
	message_vision("$N����һ��ľͷ����������������\n", me);
	me->start_busy(3);
	me->add_temp("mark/��",1);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("hand",1);
	if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
		(int)me->query_skill("hand", 1) < 30 && random(10)>5 )
	{
		write(HIM"���ھ�ľͷ�������жԻ����ַ���Щ��ᣡ\n"NOR);
		me->improve_skill("hand", (int)(me->query("int") / 10));
	}
	return 1;
}
