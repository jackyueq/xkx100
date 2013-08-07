// Room: /d/yueyang/zhongxin.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "���Ĳ���");
	set("long", @LONG
�����������ǵ����Ĳ��С�ÿ�����ϣ���������ʱ�ˣ��������Ļ�
�㣬�׵��������ĳ��ף�����������������ȫ���������һƬߺ��
��ֹ����ɢ�˿պ����ص����ȷ�����������������ڱǼ��С�
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"dongjie",
		"west"  : __DIR__"xijie",
		"north" : __DIR__"beijie",
		"south" : __DIR__"nanjie",
	]));
	set("objects", ([
		__DIR__"npc/xingren" : 1,
		__DIR__"npc/liumang" : 1,
		__DIR__"npc/xiaofan" : 1,
		CLASS_D("gaibang")+"/bangzhong" : 1,
		CLASS_D("gaibang")+"/wu-changfeng" : 1,
	]));
	set("coor/x", -1410);
	set("coor/y", -2270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
