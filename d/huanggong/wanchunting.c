// wanchunting.c

inherit ROOM;

void create()
{
	set("short", "��ͤ");
	set("long", @LONG
��ͤ, ʼ���ڼξ�ʮ����. ͤ��Բ�·�, �����ĳ�, �ϲ�ɡ״Բ
�����²��ڶ�������ܽ�, ��֯�ü�������. 
LONG
);
	set("outdoors", "huanggong");
	set("exits", ([
		"northwest" : __DIR__"yuhuayuan",
	]) );
	set("objects", ([
		__DIR__"npc/gongnv" : 1,
	]) );
	set("coor/x", -190);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}