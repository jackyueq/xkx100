// Room: /wuliang/huayuan.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
����һ��԰�ӣ�ͥԺ���ģ��軨���ţ�ɽʯ��׾�����ɴ��񣬾�
��ɷ�����ˡ�����ͨ��һ��С�ݣ�������һ����������ͨ��������
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"xiaowu",
		"west"  : __DIR__"road2",
	]));
	set("objects", ([
		"/clone/medicine/nostrum/mangguzhuha": random(2),
	]));
	set("coor/x", -70980);
	set("coor/y", -79890);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}