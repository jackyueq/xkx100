// Room: /yixing/shulin3.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï
�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�������Ұ
�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���
LONG );
	set("outdoors", "yixing");
	set("exits", ([
		"east"      : __DIR__"shulin4",
		"northwest" : __DIR__"shulin2",
	]));
	set("objects", ([
		__DIR__"npc/fanyifei" : 1,
		__DIR__"npc/luzhengping" : 1,
	]));
	set("coor/x", 229);
	set("coor/y", -170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
