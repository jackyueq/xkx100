//  Room:  /d/lanzhou/road4.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�ٵ�");
	set("long",  @LONG
һ����ʯ�̾͵Ĺٵ�������ͨ�����ݣ�������ʮ����ǽ�ǡ���·
������һƬï�ܵ����֡�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"northgate",
		"north" : __DIR__"jincheng",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9290);
	set("coor/y", 2730);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}