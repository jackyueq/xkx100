// Room: /d/fuzhou/biaojuzf.c
// Date: may.12 1998 Java

inherit ROOM;

void create()
{
	set("short", "�˷�");
	set("long", @LONG
�����Ǹ����ھֵ��˷����������Ŵ���̺�������ֻ�����������
һ�ź�ľ���Σ�����һ����������һ��ľ�鰸������ǰ����������Ķ�
��һ����ھ�Ѻ�ڵĻ�Ʊ��
LONG );
	set("no_fight", 1);
	set("exits", ([
		"west"   : __DIR__"biaojuzt",
		"south"  : __DIR__"biaojuhc",
	]));
	set("objects", ([
		__DIR__"npc/huang" : 1,
	]));
	set("coor/x", 1831);
	set("coor/y", -6297);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
