//Edited by fandog, 02/15/2000
inherit ROOM;

void create()
{
      set("short","���");
      set("long",@LONG
���ǿ͵�����ǣ����깩Ӧ���ʲ��ϡ��������ڴ�ЪϢ������
����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�øɸɾ�����һֱ��
�򵽿�����·����������µ���ľ���϶���һ����ľ��(paizi)��
    ����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
	set("outdoors", "jiangling");
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
		"west" : __DIR__"kedian",
		"up"   : SHOP_DIR"wuchang_shop",
	]));
	set("coor/x", -1480);
	set("coor/y", -2130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
