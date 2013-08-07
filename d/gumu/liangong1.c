// Room: /d/gumu/lianggong1.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ʯ��"NOR);
	set("long", @LONG
����һ���ܱյ�ʯ�ң����е��ŵƻ�ʯ����С������һ����ת��
ǽ�Ͽ���һЩͼ�ף�����Ĺ�������������Ṧʱ�ο���
LONG	);

	set("exits", ([
		"north" : __DIR__"mudao08",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", -10);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_cankan", "cankan");
	add_action("do_cankan", "watch");
}

int do_cankan(string arg)
{
	object me=this_player();
	int c_exp, c_skill;

	c_skill=(int)me->query_skill("dodge", 1);
	c_exp=me->query("combat_exp");
	if( !arg ) return notify_fail("�㶫���������ҿ�ʲô��\n");
	if( arg != "picture" || arg != "tu" )
		return notify_fail("����û�����뿴�Ķ�����\n");
	if( me->query("jing") < 30 )
		return notify_fail("�����̫���ˣ�����Ъ��ɣ�\n");
	me->receive_damage("jing", random(10));
	if( random((int)c_skill/10) + 1 < 2)
	{
		message_vision("$N����ؿ�ǽ�ϵ�ͼ�ף����ǹ���ʵ��̫�����۾���ʹ������Ҳû����ʲô�ر�Ķ�����\n", me);
		return 1;
	}
	message_vision("$N������ϸ�쿴ǽ�ϵ�ͼ�ס�\n", me);
	if ((random(10)>3) && c_skill*c_skill*c_skill/10<c_exp && c_skill<101)
	{
		me->improve_skill("dodge", random(me->query("int")));
		tell_object(me,"��Ļ����Ṧ�����ˣ�\n");
	}
	return 1;
}
