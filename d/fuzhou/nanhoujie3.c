// Room: /d/fuzhou/nanhoujie3.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "�Ϻ��");
	set("long", @LONG
�ֵ�����������������������ϲ�����󡣽ֵ����Ե�������������
һ������ĺõط����ֱ߽������ӣ����а��������ˣ��������ߣ�����
������ζ�������������죬�������ڵ�����ʵʵ�ģ����ǲ������ųǡ�
֮��������ͨ��������߾��Ǵ������������巻�ˡ�
LONG );

	set("exits", ([
		"west"  : __DIR__"wenrufang",
		"east"  : __DIR__"taxiang",
		"south" : __DIR__"nanhoujie4",
		"north" : __DIR__"nanhoujie2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "fuzhou");
	set("coor/x", 1835);
	set("coor/y", -6330);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
