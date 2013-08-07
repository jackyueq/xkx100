// Room: /d/nanshaolin/caidi.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;

int do_pi(string arg);

void create()
{
	set("short", "�˵�");
	set("long", @LONG
һ�������͵Ĳ˵أ����˲����߲ˣ�������׳�ɳ������ڲ�����ʳ��
��˾���ɮ���ǾͲ���õ�ʳ���ˡ��˵ر�����һ����أ�������ֻ��Ͱ��
LONG );
	set("exits", ([
		"east" : __DIR__"cyzi-1",
	]) );
	set("no_fight",1);
	set("outdoors","nanshaolin");
	set("objects", ([
		CLASS_D("nanshaolin")+"/fanghui" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6320);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_jiao", "jiao");
	add_action("do_jiao", "��");
}

int do_jiao(string arg)
{   
	object me = this_player();
	int costj, costq,times;

	if(me->query_temp("job_name")!="�˵��ֲ�") 
		return notify_fail("˭�������ģ�����\n");
	if (me->is_busy())
	{
		write("��������æ���أ�\n");
		return 1;
	}
	if (me->is_fighting())
	{
		write("������ս���У��޷�ר�ĸɻ\n");
		return 1;
	}
	if ( !arg || arg != "��" )
	{
		message_vision("$NҪ��ʲô��\n",me);
		return 1;
	}
	costj = random((int)me->query("con")/3);
	costq = random((int)me->query("str")/3);
	times=20+random(50);
	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N����һ�������������\n",me);
		me->unconcious();
		return 1;
	}
	me->start_busy(1);
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);       
	if (((int)me->query_temp("mark/��") > times) &&
		(present("fang hui", environment(me))))
	{
		me->set_temp("mark/����",1);
		message_vision(RED "���ض�$N���������ģ���ξ��������´��ٽ�ѵ�㣬����ȥ�¼����︴����(zhongcai ok)����\n"NOR, me);
		return 1;
	}  
	message_vision("$N�����Ͱ�˾���Ͱ�еĳ�����ȵ�����ÿ����ߵĸ��������ѽ��\n", me);
	me->add_temp("mark/��",1);
	if ( (int)me->query_skill("staff", 1) < 20 && random(10)>6 )
	{
		write(HIM"���ڽ����ж����ȵ��÷���Щ��ᡣ\n"NOR);
		me->improve_skill("staff", (int)(me->query_skill("buddhism",1) / 5));
	}
	return 1;
}
