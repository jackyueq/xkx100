// Room: zhugeliang.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "�������");
	set("long", @LONG
�������������������������������ڽ�һ����ǰ���������հ
������и�������Ҳ�������������ڵ������ڵģ���ʫʥ�Ÿ�������¶��
ǧ��������������ƵƵ�����£����������ϳ��ġ������������ǧ�ŷ緶
��һ�����¡�
LONG );
	set("exits", ([
		"southdown" : __DIR__"liubeidian",
	]));
	set("objects", ([
		__DIR__"npc/youke" : random(3),
	]));
	set("coor/x", -8070);
	set("coor/y", -3000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
