// muwu2.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
        set("short", "Сľ��");
        set("long", @LONG
����һ�䲻�Ǻܴ��ľͷ���ӣ����￴�������ҩ�ң����аڷ���
���ֲ�ͬ����ҩ���þߺ�һЩ�Ѿ�����˵�ҩ��
LONG );
	set("exits", ([
		"south" : __DIR__"xiaodao3",
	]));
	set("objects", ([
		CLASS_D("xiaoyao")+"/xuemuhua" : 1,
//		__DIR__"npc/yaotong": 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 80);
	set("coor/y", -480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}