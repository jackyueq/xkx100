// Room: /yangzhou/qingkongge.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","��ո�");
	set("long",@LONG
��ո���������¥����ȡŷ���ޡ�ң֪Ϊ�������͡����塣����
����Ա���ɿ����θ��⡰��ո󡱣�ȡŷ���ޡ�ƽɽ��������ա��䡣
��ǰ��һСԺ�䣬�������ȣ�Ժ����������ɰأ�����������ľ�����
�塣���б���һ�ţ����������ɡ��ҶԺ��Ϊ���ɲ��á�
LONG );
	set("exits", ([
		"west"  : __DIR__"daxiongbaodian",
		"south" : __DIR__"pingyuanlou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 170);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}