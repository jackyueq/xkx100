// Room: /yangzhou/changdi3.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���̱�ֲ�����������һ����̲���ӯӯ����ˮ���ݳ�ݺ��ʱ�ڣ���
����Ů����Լ��䣬������˿��ˮ���������֡���ȥ��ƽɽ�룬�ϱ���
����¥��
LONG );
	set("outdoors", "shouxihu");
	set("objects", ([
		"/d/village/npc/girl" : 2,
	]));
	set("exits", ([
		"north" : __DIR__"pingshanwu",
		"south" : __DIR__"wangchunlou",
	]));
	set("coor/x", -30);
	set("coor/y", 110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}