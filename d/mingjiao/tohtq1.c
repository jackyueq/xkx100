//TOHTQ1.C

inherit ROOM;

void create()
{
	set("short", "ɽ��·");
	set("long", @LONG
������һ������ͨ��ɽ·��·�ߵ������ܼ����������㣬�ݴ�����
�ǵ��ص�׺��һЩ��ɫҰ����·��ҲԽ��Խ���Զ���ɼ�������
���Ϊ��ɽ�ȶ����˼���������
LONG );
	set("exits", ([
		"southwest" :__DIR__"tojmq3",
		"northeast" :__DIR__"tohtq2",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52050);
	set("coor/y", 870);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}