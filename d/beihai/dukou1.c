// /d/beihai/dukou1.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "�ɿ�");
	set("long", @LONG
������һ���ɿڣ�ר�Ÿ���ڶ��ο�ȥ�����ĵ����ġ��ɿ�����
��ʵ��ľ�Ͻ���ģ���������һ����ӡ��ɴ�Ҳ�Ǻ��µ�˫���δ�����
�������ȵ����ġ��������ҷֱ����ڴ�ͷ�ܴ�β����ʱ׼�������ˡ�
LONG
	);
	set("exits", ([
		"north"     : __DIR__"jiulongbi",
		"southwest" : __DIR__"xiaolu2",
		"northeast" : __DIR__"xitian",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
