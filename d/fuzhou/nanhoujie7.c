// Room: /d/fuzhou/nanhoujie7.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "�Ϻ��");
	set("long", @LONG
�ֵ�����������������������ϲ�����󡣽ֵ����Ե�������������
һ������ĺõط����ֱ߽������ӣ����а��������ˣ��������ߣ�����
������ζ�������������죬�������ڵ�����ʵʵ�ģ����ǲ������ųǡ�
֮��������ͨ�������
LONG );

	set("exits", ([
		"east"  : __DIR__"jibixiang",
		"north" : __DIR__"nanhoujie6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "fuzhou");
	set("coor/x", 1835);
	set("coor/y", -6370);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
