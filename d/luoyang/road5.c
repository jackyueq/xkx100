//  Room:  /d/luoyang/road5.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����С·");
	set("long",  @LONG
���������ǽ���һ��é��С·���ݴ���ʱ��С�޳�û��С·����
��ֱ��ƺӰ��ߡ�������ͨ��ĵ��԰���������ңң�����������š�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"     : __DIR__"road6",
		"south"     : __DIR__"northgate",
		"northeast" : __DIR__"mudan",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
