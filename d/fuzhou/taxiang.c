// Room: /d/fuzhou/taxiang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ԭ��������δ��ĳ�����������������ʱ�����������ﱱ
���Ľ�������ϵľ������֪���ں�ʱ������������������С������
Ϊ�ż����
LONG );

	set("exits", ([
		"west"    : __DIR__"nanhoujie3",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1837);
	set("coor/y", -6330);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
