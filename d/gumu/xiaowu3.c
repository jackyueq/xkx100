// xiaowu3.c ������С��
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
������Զ��������һ��С�ݣ���ʰ���������һ����Ⱦ���������
��ͨ�˼�һ�㣬��ľ�����Σ�ϸ�ŵı���������Ĵ󴲡����ֱ����
��������Ĺ�Ĺ֮�л�����Ȱ��衣
LONG	);
	set("exits", ([
		"west" : __DIR__"mudao13",
	]));
	set("objects", ([
		CLASS_D("gumu")+"/sun" : 1,
		__DIR__"obj/ping" : 1,
	]));
	set("coor/x", -3170);
	set("coor/y", -30);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
