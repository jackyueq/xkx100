// Room: /d/quanzhou/chenghuangmiao.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�������Զ��С�����湩���Ź�������������ү����Ȫ��
��������Եĳ�������˵�����ǩ�����顣�Ա�����С�š�
LONG );
	set("objects", ([
		__DIR__"npc/miaozhu" : 1,
	]));
	set("exits", ([
		"southeast" : __DIR__"chenghuangxiang",
		"southwest" : __DIR__"houshanmen",
	]));
	set("coor/x", 1840);
	set("coor/y", -6450);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
