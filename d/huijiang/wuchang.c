// Room: /d/huijiang/wuchang.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long",@LONG
�����Ǻ컨������䳡�����ٺ컨��Ļ�����������������������
�ż���ľ�ˣ�������Χ����Щɳ������������������帴�����ָ���
���¹�Ҳʵ�ڲ���һ�����׵��¡�
LONG );
	set("outdoors", "huijiang");	
        set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
        ]));
	set("exits", ([
		"east"     : __DIR__"bingqi",
		"north"    : __DIR__"fangju",
		"south"    : __DIR__"xingtang",
		"west"     : __DIR__"zoulang3",
	]));
	set("coor/x", -50040);
	set("coor/y", 9140);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
