// Room: /d/kunlun/xschongling.c
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
		"northup"  : __DIR__"xschongling1",
		"eastdown" : __DIR__"shanxi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "hongmei");
	set("coor/x", -90050);
	set("coor/y", 10010);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
