// Room: /d/5lt/mianbaowu.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�����");
	set  ("long",  @LONG
����һ������ݡ�
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"east"  :  __DIR__"nroad1",
	]));
	set("objects",  ([
	]));
	set("coor/x", -160);
	set("coor/y", 15);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
