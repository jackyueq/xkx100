//Room: sanbuguan.c
//Date: Feb.12 1998 By Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������Ĵ��������������Ľ��磬�׳������ܡ�С��·����������
�������ũ������ֻţ�����ڳԲݡ�·�����˺��٣����ҴҸ�·��
LONG);
	set("outdoors", "sanbuguan");
	set("exits", ([
            "east"      : __DIR__"wdroad8",
            "southeast" : __DIR__"wdroad9",
            "southwest" : "/d/emei/wdroad",
	]));
	set("objects", ([
		__DIR__"npc/cow": 1,
	]));
	set("coor/x", -3300);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
