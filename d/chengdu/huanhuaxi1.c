// Room: huanhuaxi1.c
// Date: Feb.14 1998 by Java

inherit ROOM;

void create()
{
	set("short", "佻�Ϫ��");
	set("long",@LONG
������佻�Ϫ�ߣ���ˮ�峺���ӱ߲���Ů���ڴ�ϴ�£��Բˡ�����
���ѵ�СϪ��˳���Ǹ��Ϻ�������ˮ�������м��������չ��֦�⣬��
����ˮ����һ�ɵ�����ʫ�⡣�����ɪ��֦ҡӰб���ھ����У�����һ
˿������¶��� 
LONG	);

	set("outdoors", "chengdu");
	set("exits", ([
		"north"     : __DIR__"huanhuaxi",
		"southwest" : __DIR__"path2",
		"northeast" : __DIR__"huanhuaxi2",
	]));
	set("coor/x", -8050);
	set("coor/y", -2960);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


