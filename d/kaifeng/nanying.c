// /kaifeng/nanying.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "��ӯ��");
	set("long", @LONG
��ӯ���ǿ���ǵ����ţ����ڿ��⸮�������з������⾳�ں���ƽ
�������ǲ�Զ��������̨��
LONG);
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
		__DIR__"npc/walker" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"jiedao2",
		"south" : __DIR__"dadao0",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
