//Room: /d/dali/majiu.c
//Date: June. 29 1998 by Java

inherit ROOM;

void create()
{
	set("short","���");
	set("long",@LONG
���Ǿ�Ӫ���ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�
����ֻҪ������������Ǿͻ����ǣ����Ǻ����տ���������ι����
�㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿��������·����������µ���
ľ���϶���һ����ľ��(paizi)��
    ����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
	set("outdoors", "dali");
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

ǰ��      �ɶ���:  ridecd

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"bingying",
		"up"   : SHOP_DIR"dali_shop",
	]));
	set("coor/x", -41010);
	set("coor/y", -71040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
