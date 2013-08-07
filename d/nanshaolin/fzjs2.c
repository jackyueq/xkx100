// Room: /d/nanshaolin/fzjs2.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�����ҳ����࣬����һ����һ���ţ�һ����������ǽ��д�Ŵ��
��һ���������֡�һλ��ü��Ŀ�Ļ�����ɮ�������������ϴ�����
LONG );
	set("exits", ([
		 "south" : __DIR__"fzjs1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/tianhong" : 1,
	]));
	set("coor/x", 1780);
	set("coor/y", -6140);
	set("coor/z", 30);
	setup();
}
void init()
{
	add_action("do_massage", "massage");
	add_action("do_massage", "��Ħ");
}
int do_massage(string arg)
{      
	object me = this_player();
	int costj, costq, times;

	if(me->query_temp("job_name")!="���̷���") 
		return notify_fail("��ʲô�ң����⵱��ĦԺ������\n");
	if(!present("tianhong", environment(me)))
		return notify_fail("���ɲ��ڣ����ʲô�����\n");
	if(query("massage") > 10)
		return notify_fail("��緽��˵����ȥ˯�ɡ������������̡�\n");
	if(me->is_busy())
	{
		write("��������æ���أ�\n");
		return 1;
	}
	if (me->is_fighting())
	{
		write("������ս���У��޷�ר�ĸɻ\n");
		return 1;
	}
	if ( !arg || arg != "����" )
	{   
		message_vision("$NҪ��˭��Ħ��\n",me);
		return 1;
	}
	costj = random((int)me->query("con")/3);
	costq = random((int)me->query("str")/3);
	times=20+random(50);
	if((int)me->query("jing")<costj || (int)me->query("qi")<costq)
	{
		message_vision("$N��æ���ң�����һ��ˤ���ڵء�\n",me);
		me->unconcious();
		return 1;
	}
	if(!wizardp(me))
	{
		me->receive_damage("jing", costj);
		me->receive_damage("qi", costq);	
		me->start_busy(1);
	}
	if (((int)me->query_temp("mark/��Ħ")>times) &&
		(present("tianhong", environment(me))))
	{
		me->set_temp("mark/��Ħ��", 1);
		add("massage", 1);
		return notify_fail(RED "��緽��˵����лл���������ң����ȥ��Ϣ��(massage ok)��\n"NOR);
	}  
	message_vision("$N��ϥ���£�������Ħ����ȫ������緽��Ū��ˬˬ�ġ�\n", me);
	me->add_temp("mark/��Ħ",1);
	if ( (int)me->query_skill("buddhism", 1) < 50 && random(10)>6 )
	{
		write(HIM"�㾲�����������о����������ķ���Щ����\n"NOR);
		me->improve_skill("buddhism", (me->query_skill("force",1) / 5));
	}
	return 1;
}
