// Room: /d/quanzhou/majiu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���ǿ�ջ���ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ���
��ֻҪס�꣬����Ǿͻ����ǣ����Ǻ����տ���������ι�����㣬��
ϴˢ�ø�Ǭ������һֱ�ź򵽿��������·������жѷ������Ѳ��ϣ�
������һ����ۡ���������µ���ľ���϶���һ����ľ��(paizi)��
LONG );
	set("outdoors", "quanzhou");
	set("item_desc", ([
		"paizi" :
"������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ���ݳ�:  ridefz
"
	]));
	set("exits", ([
		"south" : __DIR__"kedian",
		"up"    : SHOP_DIR"quanzhou_shop",
	]));
	set("objects", ([
		"/clone/misc/mafu" : 1,
		"/d/city/npc/ziliuma" : 1,
		"/d/city/npc/zaohongma" : 1,
		"/d/city/npc/huangbiaoma" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
