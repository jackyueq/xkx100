// Room: /d/fuzhou/nanhoujie1.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "�Ϻ��");
	set("long", @LONG
�ֵ�����������������������ϲ�����󡣽ֵ����Ե�������������
һ������ĺõط����ֱ߽������ӣ����а��������ˣ��������ߣ�����
������ζ�������������죬�������ڵ�����ʵʵ�ģ����ǲ������ųǡ�
֮�����������½���������ͨ�������
LONG );

	set("exits", ([
		"east"  : __DIR__"yangqiaoxiang",
		"west"  : __DIR__"yijinfang",
		"south" : __DIR__"nanhoujie2",
		"north" : __DIR__"xidajie1",
	]));
	set("objects", ([
		"/d/village/npc/seller" : 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 1835);
	set("coor/y", -6310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
