// Room: /d/5lt/youju.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "�ʾ�");
	set  ("long",  @LONG
������һ���ʾ֡�ʱ���ƻ裬������Ա��æ��������ϵ�����׼���°ࡣ
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"east"  :  __DIR__"sroad2",
	]));
	set("objects",  ([
	]));
	set("coor/x", -160);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
