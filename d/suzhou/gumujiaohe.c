// Room: /d/suzhou/gumujiaohe.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ľ��ڭ");
	set("long", @LONG
��ľ��ڭ�ںɻ��������棬һ�Ų�ͬͼ����©����ʹ��͸��©����
�������в���ˮ��ɽɫ�͸ߵʹ����¥�󣬴˴��;����С��Ʋ���Ӱ��
֮�������������ȥ������ң������������ɪ¥������һ�֡�ͥԺ��
������Ϳռ䲻��֮�С�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"hehuating",
		"southwest" : __DIR__"chitang",
	]));
	set("coor/x", 820);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
