// /kaifeng/shulin.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ�����֣���Ҷ�������أ��߲���֦Ҷ��¶����������
�顣��ɫ��С�ݾʹ���֮��Ŀ�϶�����������е��Ķ�����
ɫ��С·�������ֲ�Զ��������̨�����������ݷ���
LONG);
	set("no_clean_up", 0);

	set("exits", ([
		"southeast":__DIR__"guandao1",
		"northwest" : __DIR__"dadao1",
		"east" : __DIR__"yuwang",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
