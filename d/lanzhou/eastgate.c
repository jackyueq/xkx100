//  Room:  /d/lanzhou/eastgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "����");
	set("long",  @LONG
���������ݶ��š�������һƬï�ܵ����֣���������Ǳ��ΰ���̫
�ã���˼������Źٱ������Ž����ر��ˡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" : __DIR__"street1",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/bing": 4,
	]));
	set("outdoors", "lanzhou");
	set("coor/x", -9270);
	set("coor/y", 2700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}