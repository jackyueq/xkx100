// Room: /d/gumu/anhe2.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"����"NOR);
	set("long", @LONG
ԭ��������һ�����°��ӣ��˴�ˮ�����Ǻ�䣬���Ƽ�Ϊ���ˡ���
����һ��̤�գ�����ˮ��ֱ���ʺ���Ǳ����֪���Ժδ�������֪ͨ��
�η����������Ѹо�ˮ�ƽ��������ƽ��ߡ�
LONG	);

	set("exits", ([
		"northup"  : "/d/quanzhen/shandong1",
		"westdown" : __DIR__"qianliu2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -2970);
	set("coor/y", -50);
	set("coor/z", -20);
	setup();
}

void init()
{
	object me = this_player();

	me->receive_damage("qi", 50 );
	me->receive_damage("jing", 50 ); 
	message_vision(HIB"$N������������ʧ������ʮ�����ѡ�\n"NOR, me);
	if ( me->query("qi") < 10 || (int)me->query("jing") < 10)
	{
		me->set_temp("last_damage_from","�ڰ����б���");
		me->unconcious();
		me->die();
		return;
	}
}

int valid_leave(object me, string dir)
{
	if (dir == "northup")
	{
		write(HIW"\n����ö�����ǿ����ҫ��һʱ֮�侹Ȼ�������ۡ�\n"NOR);
	}
	return ::valid_leave(me, dir);
}
