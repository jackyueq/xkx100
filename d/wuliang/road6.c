// Room: /wuliang/road6.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
�߳�ʮ����Ѿ�������ɽ��ĺ�ɽ��ֻ����ˮ�����ȣ�ǰ����
��ɽϪ��Ѱ������Ϫ�ԣ�Ϫˮ�峺�쳣��Զ������������֦���Ų���
����������졣
LONG );
        set("outdoors", "wuliang");
	set("exits", ([
		"south"   : __DIR__"road5",
		"northup" : "/d/xiaoyao/pubu",
	]));
	set("objects", ([
		__DIR__"npc/gan" : 1,
		__DIR__"npc/ge"  : 1,
	]));
	set("coor/x", -71020);
	set("coor/y", -79880);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}