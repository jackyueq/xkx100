//Room: majiu.c ���
// Winder 2000.3.10

inherit ROOM;

void create()
{
	set("short","���");
	set("long",@LONG
���ǿ͵�ߵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ����
�ǻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һ
ֱ�ź򵽿�����·������жѷ������Ѳ��ϣ�������һ����ۡ�
    ��������µ���ľ���϶���һ����ľ��(paizi)��
LONG);
	set("outdoors", "wuxi");
	set("no_fight", "1");
	set("no_beg", "1");
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ���ݳ�:   rideyz

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"kedian",
		"up"    : SHOP_DIR"wuxi_shop",
	]));
	set("coor/x", 350);
	set("coor/y", -780);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
