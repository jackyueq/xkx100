//  Room:  /d/luoyang/xiaojie1.c

inherit  ROOM;

void  create  ()
{
	set("short",  "ʯ��");
	set("long",  @LONG
�����������ʵ�֮������ģ��ΰ������ȴ�������������Ų��߽���
��С�֣������̵�������ֺ��ְ����������еģ�����������ڣ��Լ�
�����Ǻܴ��ڻ��Ľ��С������Ǹ�С�ƹݡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"xiaojie2",
		"south" :  __DIR__"eastroad",
		"north" :  __DIR__"xiaojiudian",
	]));
	set("objects",  ([
		"/d/city/npc/liumang" : 3,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -400);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
