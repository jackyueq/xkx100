// /guanwai/xuedi1.c

inherit ROOM;

void create()
{
	set("short", "ѩ��");
	set("long", @LONG
������һƬ��ãã��ѩ�أ�һ���������߼ʡ�����һ����ӰҲû�У�
���Ļ�ѩ������������֨�����������������һ���¶��Ľ�ӡ������
�ı����Х��������������ʹ��������̫����������ߣ��Ե���ô�԰ס�
LONG );
	set("exits", ([
		"west"       : __DIR__"dongcheng",
		"northeast"  : __DIR__"xuedi2",
		"southeast"  : "/d/yubifeng/songlin1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6060);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	me->receive_damage("qi",30);
	me->receive_wound("qi",30);
	tell_object(me,"һ�ɴ̹ǵĺ��紵������ֻ���û����ѪҺ���챻��ס�ˣ�\n");
	return 1;
}
