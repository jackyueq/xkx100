// Room: /d/nanshaolin/tianming.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",CYN"������̨"NOR);
	set("long", @LONG
һ����տ���ʯ�ң�����ֻ��һ��ʯ�����ı����ء�̧ͷ��ȥ��
���ϵ���һֻʯӥ��������ɡ�ӥצ�䴹�¼���������۵Ĵ�������ʦ
����ɫ����ȵ�ʦ�塣ǰ����ɮ����ִ�����ַ�Ԩ��������¡���
����ʦ������Ϊ��Ϊ������Ϊ�����޶�����צ��(claw)�������ڴ�ʯ��
�ڱչؾ��꣬�����ڴˡ�������书��û�ڿ���֮�С�
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",	 
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_claw","claw");
}
int do_claw(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("claw", 1), exp = me->query("combat_exp");
	if (arg!="sheng") return 0;
	if (!living(me)) return 0;
	message("vision", me->name()+"����Ʈ��һʽ���ӭ�磬�������ץȥ��\n", environment(me), ({me}) );
	if (lvl<30)
	{
		write(HIR"�����Ϸ�������Ȼץס�����������������æ�ſ���\n"NOR);
		return 1;
	}
	if (lvl * lvl * lvl / 10 < exp)
	{
		write(HIR"�㾭��̫ǳ��û�����Ŵ�����\n"NOR);
		return 1;
	}
	if (lvl>100)
	{
		write(HIR"���������ͣ��������жϾ���\n"NOR);
		return 1;
	}
	if (lvl >= 30 && lvl <= 100 && arg=="sheng" )
	{
		if ((int)me->query("jing")<30)
		{
			me->unconcious();     
			return 0;
		}
		me->receive_damage("jing", 30);
		me->improve_skill("claw", (me->query("int"))*3/2);
		write(HIR"����ס��������צ��ʹ�����ϣ�ֱ��ӥ�£���������ӥ��̬��ֻ����צ����������\n"NOR);
		return 1;
	}
}

