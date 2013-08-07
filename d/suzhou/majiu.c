// Room: /d/suzhou/majiu.c
// Date: May,31 1998 Java

inherit ROOM;

void create()
{
	set("short","���");
	set("long",@LONG
���Ǳ���ֵ���ǣ����깩Ӧ���ʲ��ϡ�������紾�ӣ�����ǻ�
����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ��
�򵽿�����·����������µ���ľ���϶���һ����ľ��(paizi)��
    ����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
	set("outdoors", "suzhou");
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_clean_up", 0);
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ���ݳ�:  rideyz

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"east"  : __DIR__"beidajie1",
		"south" : __DIR__"xiyuan",
		"up"    : SHOP_DIR"suzhou_shop",
	]));
	set("coor/x", 840);
	set("coor/y", -990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
