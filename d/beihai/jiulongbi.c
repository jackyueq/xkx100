// /d/beihai/jiulongbi.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������С������֮�����ڣ�������̨������������������������
ǰ����о�����̬���죬�������������е��������񡣱ڶ���Ϊ����
��ˮ�����ն����������Σ�����Ϊ���º�ˮ�����µ����������Ρ�Ӱ��
���İٶ�ʮ�Ŀ���ɫ����ש�������ɡ�ɫ��Ѥ�������Ӵ󷽡�
LONG
	);
	set("exits", ([
		"east"  : __DIR__"xitian",
		"south" : __DIR__"dukou1",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
