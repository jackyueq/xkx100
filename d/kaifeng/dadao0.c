// /kaifeng/dadao0.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set ("short", "���");
	set ("long", @LONG
��ƽԭ֮�ϵ�һ����·�������˺ܶ࣬·�������Զ���и�Сͤ��
������Ъ�ţ���ȥ���ǿ���ǡ����治Զ�Ǹ�����·�ڡ�
LONG);
	set("outdoors", "kaifeng");

	set("exits", ([
		"south" : __DIR__"dadao1",
		"north" : __DIR__"nanying",
	]));

	setup();
	replace_program(ROOM);
}
