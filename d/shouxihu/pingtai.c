// Room: /yangzhou/pingtai.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ƽ̨ʯ��");
	set("long",@LONG
ƽ̨�ж������죬��̫��ʯΪ������ֲ�ɻ������ڣ���Ϊ�����辰��
����ֱ�����߳ߣ�����磬�����˼��룬�ഫΪ����ʱ��ˮ֮�����
�����ء�����ǡ���ʯ������ࡣ
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"northup" : __DIR__"taohuawu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 39);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}