// Room: /d/xingxiu/xxhb1.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "���޺�");
	set("long", @LONG
����������޺��ľ�ͷ�ˡ���Ŀң��, ��Χ���޼ʵĺ���������
���ǻ���, Ȼ������ʪ, ���深ֳ���������޵��ӳ����˲�׽����,��
������֮�á�
LONG );
	set("objects", ([
		__DIR__"npc/gushou"  : 1,
	]) );
	set("exits", ([
	     "southwest" : __DIR__"riyuedong1",
	     "northwest" : __DIR__"xxhb3",
	]));
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -49990);
	set("coor/y", 20400);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
