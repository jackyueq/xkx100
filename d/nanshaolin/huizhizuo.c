// Room: /d/nanshaolin/huizhizuo.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIG"����ʥ��"NOR);
	set("long", @LONG
������ʦʥ��������֮��ԭ��һ��ʯ������ö���ֻ����ʯ�̵ؾ�
����Ϊ��������������ӧ���磬�������ϡ������϶�ͨ��������磻
�񴲱̼�����Ⱦ�˳�������ʯ���������Ż���Ȼ�������⻪���ã�Ŀ��
��ɫ��������ʦ���������׸���ѣĿ֮�������棬�������ġ��ıڸ���
��һ��ǧ������������̬������ͬ����������������֮���������ס�
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_ningwang",({"gaze","ningwang"}));
}
int do_ningwang(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("hand", 1), exp = me->query("combat_exp");
	if (arg!="foxiang") return notify_fail("��Ҫ����ʲô��\n");
	if (!living(me)) return 0;
	if (!random(5))
	message("vision", me->name()+"���ڶ���ǽ������ۿ�������ַ���\n", environment(me), ({me}) );
	if (lvl < 30)
	{
		write("���������񣬵���ǧ�ַ�����ʵ�ް�������Ѱ��\n");
		return 1;
	}
        if (lvl * lvl * lvl / 10 < exp)
        {
                write(HIR"���������������������򣬵��Ͼ�������ǳ��ʲôҲû���򵽡�\n"NOR);
                return 1;
        }
	if (lvl > 100)
	{
		write("���������䷱�����Ѿ����������ġ�\n");
		return 1;
	}
        me->receive_damage("jing", 30);
        me->improve_skill("hand", (me->query("int"))*3/2);
        write("�����ŷ���ǧ��ٹ�֮�ַ������жԻ����ַ���������\n");
	return 1;
}
