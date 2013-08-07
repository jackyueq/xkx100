// Room: /d/fuzhou/xidajie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��ֱ��棬һ���ṹ��ΰ�Ľ���ǰ������ʯ̳�ϸ�����һ�����ɶ�
�ߵ���ˣ���������Ʈ����������ý�������һͷ������צ��ʨ�ӣ�
�����չ��������������ʨ��ͷ��һ�Ժ�˿���������չ����衣����
������д�š������ھ֡��ĸ����֣������������վ��Ƿ���
LONG );

	set("exits", ([
		"north"   : __DIR__"biaoju",
		"east"    : __DIR__"xidajie1",
		"west"    : __DIR__"xixiaojie",
		"southup" : __DIR__"wushan",
	]));
	set("objects", ([
		__DIR__"npc/ji" : 1,
		__DIR__"npc/di" : 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 1830);
	set("coor/y", -6300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
