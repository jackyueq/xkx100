// Room: /wuliang/road5.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
������ͨ����ɽ����С·��������������Ҳ�������ˡ�����ɽ
��ï�ܣ��˼�������С�����첻���ڶ���
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"road6",
		"east"   : __DIR__"road3",
	]));
	set("objects", ([
		__DIR__"obj/cao" : 2,
	]));
	set("coor/x", -71020);
	set("coor/y", -79890);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}