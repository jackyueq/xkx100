// Room: /d/huijiang/zoulang.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long",@LONG
������һ�������������ϣ����ܾ����ĵģ���ĽŲ������ú�Զ��
���Գ�����Ĳк���ͣ�˼�ֻ�����ҽе����ܣ�������紵����������
��
LONG );
	set("outdoors", "huijiang");	
        set("objects", ([
                __DIR__"npc/xinyan" : 1,
        ]));
	set("exits", ([
		"westup" : __DIR__"zoulang2",
		"eastup" : __DIR__"zoulang3",
		"out"    : __DIR__"damen",
	]));
	set("coor/x", -50060);
	set("coor/y", 9140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
