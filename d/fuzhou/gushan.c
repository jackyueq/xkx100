// Room: /d/fuzhou/gushan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
��ɽ��ɽ����ʯ����ģ���֮���޹Ķ���������ֻɽ����ĸ��ء�
ɽ�ϲ��ɵδ䣬������ģ��羰�������ļ��紺���н���������Ϊ����
��������֮һ��
LONG );
	set("exits", ([
		"north"    : __DIR__"yongquan",
		"westdown" : __DIR__"shulin",
		"southdown": __DIR__"luoxingta",
	]));
	set("objects", ([
		"/d/wudang/npc/monkey": 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 1890);
	set("coor/y", -6300);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
