//  Room:  /d/5lt/zhulin.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
һƬ���װ�����ְ����ȵ�����Ұ֮�⣬������һƬ�������硣
LONG);
	set("exits",  ([  /*  sizeof()  ==  1  */
		"southwest"  :  __DIR__"eroad2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -125);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}