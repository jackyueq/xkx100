// /kaifeng/zhulin1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "Сé��");
	set("long", @LONG
���߽������е�Сé�ݣ�������һ�£���é�ݽ�����é�ݸ�������
�ߵ�ǽ������һ������ë�������¶��ɵģ����е�����Ҳ���Ǵ�����
�ƣ����ϷŵĲ���������������ɵġ�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"out" : __DIR__"zhulin0",
	]));

	setup();
	replace_program(ROOM);
}
