// /kaifeng/eroad3.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������ǿ��⸮�ڶ���������Ҫͨ������·�����˵��̸��ڲ��ϡ�
�������ƣ��۹�ģ�������ģ��ʽ���ģ��������׷��ѵģ��ϱ߲�Զ
����ɽ�¸ʻ�ݡ������ǿ���������
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"eroad2",
		"west" : __DIR__"tieta",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
