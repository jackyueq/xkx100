// Room: qingyang.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���������µ�һ����ۡ�������ľ��涣��ڸ�ͤͤ�����е�ʿ��
����ȥ��û�˵ÿ����㣬��û�˽Ӵ��㡣����õ�һ�ֿ��ɵ�ʧ�䡣
LONG );
	set("exits", ([
		"southeast" : __DIR__"nanjie2",
	]));
	set("objects", ([
		__DIR__"npc/dao-ren" : 1,
	]));
	set("coor/x", -8060);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
