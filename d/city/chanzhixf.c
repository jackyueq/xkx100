// Room: /city/chanzhixf.c

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
����һ��С�᷿��������Ļ𹤺��е�����Ϣ�ĵط������������
������˼���ϯ�ӣ������϶����˲�͸���ֽ���᷿��Ĺ��߰��ò���
�ˣ�����������ϵ��о������ǲ�ʱ�ش�����
LONG );
	set("exits", ([
		"west"  : __DIR__"chanzhidadian",
	]));
	set("objects", ([
		__DIR__"npc/huogongseng": 1,
	]));
	set("coor/x", -19);
	set("coor/y", -8);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}