// Room: /yangzhou/pailou.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","��¥");
	set("long",@LONG
������ɽ��ǰ����¥��������麣�ľ����ģ�������׭�塰������
ַ�������⡰������������������ΰ����¥�����ж�������ɡ�ǣ�����
����ʯ������¥ǰ��һ����ʯ��ͷ����ʯʨ��
    ��������ʼ�����ϳ����δ�����������������������幬���࣬
���������¡����������ڽ��Ų������������������¡�
LONG );
	set("outdoors", "shouxihu");
	set("objects", ([
		"/d/village/npc/boy" : 3,
	]));
	set("exits", ([
		"northup"   : __DIR__"shanmen",
		"southdown" : __DIR__"pingshanwu",
	]));
	set("coor/x", -30);
	set("coor/y", 130);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}