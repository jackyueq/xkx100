// /d/changan/majiu.c ���

inherit ROOM;

void create()
{
	set("short","���");
	set("long",@LONG
���ǿ͵�����ǣ����깩Ӧ���ʲ��ϡ�������紾�ӣ�����ǻ�
����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ��
�򵽿�����·����������µ���ľ���϶���һ����ľ��(paizi)��
    ����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
	set("outdoors", "changan");
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
          ������:  rideyl
TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"kedian",
		"up"    : SHOP_DIR"changan_shop",
	]));
	set("coor/x", -5060);
	set("coor/y", 1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
