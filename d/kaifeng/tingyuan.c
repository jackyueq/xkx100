// /kaifeng/tinyuan.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "��ͤ԰");
	set("long", @LONG
������һƬ��ľ������԰�֡�԰�ֵ��ϱ����߷ֱ�����Һ����˼�
�������б̲����������ߴ����������������𡣴Ӵ�������ͤ��
����������ֵ���
LONG
	);
	set("exits", ([
		"east" : __DIR__"road5",
		"west" : __DIR__"wroad3",
		"north" : __DIR__"longting",
	]));

	set("no_clean_up", 0);
	set("outdoors", "kaifeng");
	setup();
	replace_program(ROOM);
}
