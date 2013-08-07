// Room: /d/gumu/jianshi.c
// Last Modifyed by Winder on Jan. 14 2002

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIC"����"NOR);
	set("long", @LONG
һ�����������ʯ�ң��ܶ��ֽ�������ضѷ��ڵ��ϡ���Χ�Ļ��
�յ�����ʯ�ҵƻ�ͨ����������Ĺ������վ��������ϸ��ѡ�Լ����ֵ�
���С�ǽ�Ƿ���һ��ľ�ƵĻ��߼ܣ��������Щ��Ĺ����ƽʱ�����õ�
���ߡ�
LONG	);
	set("exits", ([
		"south" : __DIR__"mudao07",
	]));

	set("objects", ([
		WEAPON_DIR"changjian" : 2,
		WEAPON_DIR"sword/zhujian" : 2,
		__DIR__"obj/huju-jia" : 1,
	]));
	set("coor/x", -3180);
	set("coor/y", 30);
	set("coor/z", 90);
	setup();
}

int valid_leave(object ob, string dir)
{
	string* jian = keys(query("objects"));
	object* sword = deep_inventory(ob);

	int i = sizeof(sword), count = 0;
	while (i--)
		if (member_array(base_name(sword[i]), jian) != -1) count++;
	if (count > 1)
		return notify_fail("��һ��������ô�ལ�����˲�Ҫ������\n");
	return ::valid_leave(ob, dir);
}

