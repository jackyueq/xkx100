// Room: /d/yanping/majiu.c
// Date: May,31 1998 Java

inherit ROOM;

void create()
{
	set("short","���");
	set("long",@LONG
������ƽ�ǵ���ǣ����깩Ӧ���ʲ��ϡ���ƽ����紾�ӣ������
�����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ
�ź򵽿�����·����������µ���ľ���϶���һ����ľ��(paizi)��
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

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"mazhan",
		"up"    : SHOP_DIR"yanping_shop",
	]));
	set("coor/x", 1850);
	set("coor/y", -6280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
