// Room: /d/huangshan/lianhua.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
��ɽ��һ�߷塣����Ȼ������Ⱥ���ӵ����һ���������������ŭ
�ţ�����ΰ������һ�壬�ǵ�֮�����ġ����̽�ܽ�ء������Ͼ�ɫ����
����Ϊ���������������������ȡ�ÿ���������ʣ�������Ŀ����հ��®��
�����Ż���������壬��Ұ��Ϊ��������ȥ���Ǻ�ɽ��
LONG
	);
	set("exits", ([ 
		"south"     : __DIR__"yuping",
		"northdown" : __DIR__"guangming",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
