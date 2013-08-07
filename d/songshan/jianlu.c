// Room: /d/songshan/jianlu.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
int do_zong(string arg);

void create()
{
	set("short", "��®");
	set("long", @LONG
����һ�侻�ң�����һ�ﲻ�衣����ż������б�룬ӳ����������
�ƺ������һЩ���¡�
LONG );
	set("sword_count", 1);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"eastting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 900);
	set("coor/z", 90);
	setup();
}
void init()
{
	add_action("do_zong", "zong");
	add_action("do_zong", "tiao");
	add_action("do_zong", "jump");
}
int do_zong(string arg)
{
	object ob, me= this_player();
	if (arg != "sword" && arg != "liang") return 0;
	if( (int)me->query_dex() < 38 )
		return notify_fail("���������Σ�һ�Ӷ��𣬾Ͳ�һ��Ϳ��Թ������ˣ����ǿ�ϧ��\n");
	if (query("sword_count") < 1)
		return notify_fail("���������Σ�һ�Ӷ�������������һ����ȴ��������һ���ա�\n");
	add("sword_count", -1);
	ob = new(WEAPON_DIR"treasure/zhanlu-jian");
	if ( ob->violate_unique() )
	{
		destruct( ob );
		return notify_fail("���������Σ�һ�Ӷ�������������һ����ȴ��������һ���ա�\n");
	}
	ob->move(me);
	message_vision("$N�������Σ�һ�Ӷ�������������һ����һ�����ӷ���������أ����϶���һ�����ι��ӵĳ�����\n", me);
	return 1;
}
