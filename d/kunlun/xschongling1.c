// Room: /d/kunlun/xschongling1.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "ѩɽ����");
	set("long", @LONG
����һ���ܴ�Ĵ��֣���ľ֦Ҷ�Ϲ����˱�ѩ��ѩ�׵�һ��Ƭ����
���ޱȡ�������ɽ�����죬ֱ��ɽ�����ڴ�����΢¶��һ��С������ϡ
���ϣ�������С���ϣ�ѩ��������һ�г�������ӡ��
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"westup"    : __DIR__"xuanya",
		"southdown" : __DIR__"xschongling",
	]));
	set("no_clean_up", 0);
	set("outdoors", "hongmei");
	set("coor/x", -90050);
	set("coor/y", 20010);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
