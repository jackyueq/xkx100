// Room: /d/gumu/qianliu2.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"Ǳ��"NOR);
	set("long", @LONG
��û��ˮ�У�ֻ��ˮ��������������޷����㡣�������쳣��ֻ��������
��Ǳ�У������ǽ���ά�ȡ�
LONG	);

	set("exits", ([
		"west"   : __DIR__"qianliu1",
		"eastup" : __DIR__"anhe2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -2980);
	set("coor/y", -50);
	set("coor/z", -30);
	setup();
}

void init()
{
	object me = this_player();

	me->receive_damage("qi", 50 );
	me->receive_damage("jing", 50 ); 
	message_vision(HIB"$N������������ʧ������ʮ�����ѡ�\n"NOR, me);
	if ((int)me->query("qi") < 10 || (int)me->query("jing") < 10)
	{
		me->set_temp("last_damage_from","��Ǳ���б���");
		me->unconcious();
		me->die();
		return;
	}
}
