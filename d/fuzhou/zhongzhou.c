// Room: /d/fuzhou/zhongzhou.c
// Date: May 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ź�Խ����������ƽ��������ˮ�����֡�����ΪһС��������
ˮ���˼ҡ�������һ����ͷ��
LONG );
	set("exits", ([
		"west"  : __DIR__"matou",
		"north" : __DIR__"nanmen",
		"south" : __DIR__"puxian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "fuzhou");
	set("coor/x", 1840);
	set("coor/y", -6340);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
