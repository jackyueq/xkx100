// qianqiuting.c

inherit ROOM;

void create()
{
	set("short", "ǧ��ͤ");
	set("long", @LONG
ǰ���ξ�ʮ���깹���޽���ǧ��ͤ��Բ�·�, �����ĳ�, �ϲ�ɡ״
Բ�����²��ڶ�������ܽ�, ��֯�ü�������.
LONG
);
	set("outdoors", "huanggong");
	set("exits", ([
		"northeast" : __DIR__"yuhuayuan",
	]) );
	set("objects", ([
		__DIR__"npc/gongnv" : 1,
	]) );
	set("coor/x", -210);
	set("coor/y", 5320);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}