// Room: /d/baituo/changlang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
�����Ƿǳ����ɵĳ��ȡ������Ǽ���Ϣ�ҡ��ϱ��м�ҩ�������洫
��һ�������������������������ȹ�����С���š���������������
LONG	);

	set("exits",([
		"west"  : __DIR__"ximen",
		"north" : __DIR__"restroom",
		"east"  : __DIR__"liangong",
		"south" : __DIR__"yaofang",
	]));
	set("outdoors","baituo");
	set("no_clean_up", 0);
	set("coor/x", -50020);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
