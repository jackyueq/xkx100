//  Room:  /d/luoyang/wanghuating.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
���߽����һ���������ᵽ�������������Ž�����̺죬ʲô����
�д�ɫ�ޱߡ������У�СС�����ݺ����ѣ���ɫ���ڡ����������Ǹ�ʯ
ͤ�������������������������֮����
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"  :  __DIR__"wangdatang",
		"north"  :  __DIR__"wanglianwu",
		"west"   :  __DIR__"wangxiangfang",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/wangzhongqiang" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -600);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}