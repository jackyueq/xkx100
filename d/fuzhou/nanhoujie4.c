// Room: /d/fuzhou/nanhoujie4.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "�Ϻ��");
	set("long", @LONG
�ֵ�����������������������ϲ�����󡣽ֵ����Ե�������������
һ������ĺõط����ֱ߽������ӣ����а��������ˣ��������ߣ�����
������ζ�������������죬�������ڵ�����ʵʵ�ģ����ǲ������ųǡ�
֮��������ͨ�����
LONG );

	set("exits", ([
		"east"  : __DIR__"huangxiang",
		"south" : __DIR__"nanhoujie5",
		"north" : __DIR__"nanhoujie3",
	]));
	set("objects", ([
		__DIR__"npc/kid" : 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 1835);
	set("coor/y", -6340);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
