// /kaifeng/majiu.c
// Last modified by winder 2003.10.20

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���ǵ���Ӻ����ǣ����깩Ӧ���ʲ��ϡ����⸮�Թ��˾����صأ�
��ʷ�ƾã���紾�ӡ�����ǻ����ǣ����Ǻ����տ���������ι����
�㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿�����·����������µ���ľ����
����һ����ľ�� (paizi)������жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
	set("outdoors", "kaifeng");
	set("no_fight", "1");
	set("no_beg", "1");
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
	]));
	set("exits",([
		"west" : __DIR__"daoxiang1",
		"up"   : SHOP_DIR"kaifeng_shop",
	]));
	set("item_desc", ([
		"paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ���ݳ�:  rideyz
TEXT]));
	setup();
	replace_program(ROOM);
}
