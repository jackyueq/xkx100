// Room: /d/xingxiu/xxhb3.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "���޺�");
	set("long", @LONG
���������޺��ľ�ͷ����Ϊ������Ұ���û�����������ɵ��ӳ���
�ڴ˿����⴮�ԡ����򲻵�Ұ��ʱ�����Ǿ���ɽ�����˵���
LONG );
	set("exits", ([
		"southeast" : __DIR__"xxhb1",
		"southwest" : __DIR__"xxhb2",
	]));
	set("objects", ([
		__DIR__"npc/boshou"  : 1,
		__DIR__"npc/obj/yangrou" : 2
	]));
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -50000);
	set("coor/y", 20500);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
