// Room: /d/fuzhou/nanhoujie2.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "�Ϻ��");
	set("long", @LONG
�ֵ�����������������������ϲ�����󡣽ֵ����Ե�������������
һ������ĺõط����ֱ߽������ӣ����а��������ˣ��������ߣ�����
������ζ�������������죬�������ڵ�����ʵʵ�ģ����ǲ������ųǡ�
֮�����������ɹ��
LONG );

	set("exits", ([
		"east"  : __DIR__"langguanxiang",
		"south" : __DIR__"nanhoujie3",
		"north" : __DIR__"nanhoujie1",
	]));
	set("objects", ([
		"/d/city/npc/liumang" : 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 1835);
	set("coor/y", -6320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
