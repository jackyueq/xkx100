// Room: /d/huanggong/fengxiandian.c

inherit ROOM;

void create()
{
	set("short", "���ȵ�");
	set("long", @LONG
���ȵ��ǻʹ�����Ҫ֮��. ���﹩���������ʵ۵�ͼ��. һ���к�
�ش����, �ʵ۶�����������, �����������. ���ð���֮�߾�������
�ﶨ�µ�.
LONG
	);
	set("exits", ([
		"south"     : __DIR__"fengxianmen",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 5182);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}