// /kaifeng/jieyin.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
������������ǿ�����������ֵĵط���˭���뱻�������������
�ء����ڹ���������񣬷���ǰ������һյ�����ĵ�������ţ����ճ�
�����Ӵ˵��ȥ�����ܿ������������ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"road6",
		"east" : __DIR__"tieta",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
