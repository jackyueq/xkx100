//Room: /d/yangzhou/majiu1.c ���
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","���");
	set("long",@LONG
���ǿ�Ԣ�����ǣ����깩Ӧ���ʲ��ϡ�������紾�ӣ�����ǻ�
����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ��
�򵽿�����·����������µ���ľ���϶���һ����ľ��(paizi)��
    ����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
	set("outdoors", "yangzhouw");
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/zaohongma": 1,
		__DIR__"npc/huangbiaoma": 1,
		__DIR__"npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ������:  ridebj
          ���ݳ�:  ridesz
          ���ݳ�:  ridehz
          ���ݳ�:  ridefz
          ������:  ridewx
          �ɶ���:  ridecd
          ������:  rideca
          ������:  ridexy
          �����:  ridekf
          ��ƽ��:  rideyp
          ���ǳ�:  rideyd
          �����:  ridewc
          ��ɽ��:  ridefs
          ����ɽ:  rideem

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"west" : __DIR__"kedian",
		"up"   : SHOP_DIR"yangzhou_shop",
	]));
	set("coor/x", 21);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
