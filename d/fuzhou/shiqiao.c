// Room: /d/fuzhou/shiqiao.c
// Date: May 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���ǳ���һ������ͨͨ��ʯ�š�������м�������ʷ�ˣ��Ų�����
��̦��������С��Ϸˮ������ϴ�µ�ĸ�״����ǳ����Լ��ĺ��ӡ�
LONG );

	set("exits", ([
		"west"  : __DIR__"xiangyang",
		"east"  : __DIR__"nanmendou",
	]));
	set("no_clean_up", 0);
	set("outdoors", "fuzhou");
	set("coor/x", 1830);
	set("coor/y", -6320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
