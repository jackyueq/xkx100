// Room: /d/huijiang/zoulang.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long",@LONG
������һ�������������ϣ����Գ�����Ĳк���ͣ�˼�ֻ�����ҽ�
�����ܣ�������紵�����������������Ǹ��������һ����ķ�����
ζƮ�������ȡ�
LONG );
	set("outdoors", "huijiang");	
        set("objects", ([
		CLASS_D("honghua")+"/first" : 1,
        ]));
	set("exits", ([
		"east"     : __DIR__"wuchang",
		"north"    : __DIR__"chufang",
		"south"    : __DIR__"qiufang",
		"westdown" : __DIR__"zoulang1",
	]));
	set("coor/x", -50050);
	set("coor/y", 9140);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
