// /kaifeng/eroad0.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������ǿ��⸮�ڶ���������Ҫͨ������·�����˵��̸��ڲ��ϡ�
�������ƣ��۹�ģ�������ģ��ʽ���ģ��������׷��ѵģ������ޱȡ�
�ϱ�һ��С�������ƺ��Ǹ�С��԰�ӡ�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"jiaomen",
		"north" : __DIR__"eroad1",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
