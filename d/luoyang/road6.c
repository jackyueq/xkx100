//  Room:  /d/luoyang/road5.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����С·");
	set("long",  @LONG
���������ǽ���һ��é��С·��������·���ͨ���ɿڵ�С·����
���������������š�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"northeast" :  __DIR__"dukou",
		"northup"   :  __DIR__"mangshan",
		"south"     :  __DIR__"northgate",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/taishan/npc/tiao-fu" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
