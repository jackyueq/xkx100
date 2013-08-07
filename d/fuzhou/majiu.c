// Room: /d/fuzhou/majiu.c
// Date: May,31 1998 Java

inherit ROOM;

void create()
{
	set("short","���");
	set("long",@LONG
�����ų������ǣ����깩Ӧ���ʲ��ϡ�������紾�ӣ�����ǻ�
����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ��
�򵽿�����·����������µ���ľ���϶���һ����ľ��(paizi)��
    ����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
	set("outdoors", "fuzhou");
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
          Ȫ�ݳ�:  rideqz

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"rongcheng",
		"up"    : SHOP_DIR"fuzhou_shop",
	]));
	set("coor/x", 1550);
	set("coor/y", -6180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
