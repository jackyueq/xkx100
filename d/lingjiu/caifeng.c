//ROOM: caifeng.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long",@LONG
���ǡ����չ����Ĳ÷��ҡ�����Ů��Χ����һ�飬�������ߣ�����
Ů�죬�ѵ�������Ϊ���Ժ���һ�����ż��� 
LONG );
	set("exits", ([
		"south" : __DIR__"changl10",
	]));
	set("objects",([
		__DIR__"npc/fumy" : 1,
	]));
	set("coor/x", -50980);
	set("coor/y", 30170);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}