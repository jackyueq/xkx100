// Room: /d/gumu/anhe1.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"����"NOR);
	set("long", @LONG
ԭ��������һ�����°��ӣ��˴�ˮ�����Ǻ�䣬���Ƽ�Ϊ���ˡ���
����һ��̤�գ�����ˮ��ֱ���ʺ���Ǳ����֪���Ժδ�������֪ͨ��
�η���
LONG	);

	set("exits", ([
		"northup"  : __DIR__"shishi6",
		"eastdown" : __DIR__"qianliu1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3000);
	set("coor/y", -50);
	set("coor/z", 30);
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

