//  Room:  /d/lanzhou/road1.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�ٵ�");
	set("long",  @LONG
һ����ʯ�̾͵Ĺٵ�����ͨ�����ݣ������򵽴ﳤ������·����
��һƬï�ܵ����֡�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" : __DIR__"southgate",
		"east"  : __DIR__"caoyuan5",
		"west"  : __DIR__"yizhan",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9290);
	set("coor/y", 2660);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}