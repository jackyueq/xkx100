// /guanwai/huandi1.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
�����ǳǶ���һ����·��·�����ҵس�����ϥ�ĻĲݣ�Զ������һ
�ˡ����Ըɿݵ������������˳�Ⱥ����ѻ���������������ڻ�Ұ��ԶԶ
��ȥ��һ�������ľ���
LONG );
	set("exits", ([
		"southwest" : __DIR__"dongcheng",
		"northeast" : __DIR__"huandi2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6070);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}