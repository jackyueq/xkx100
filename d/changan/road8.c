//  Room:  /d/changan/road8.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�ٵ�");
	set("long",  @LONG
һ����ʯ�̾͵Ĺٵ���������ͨ�����ݣ��������򵽴ﳤ������·
������һƬï�ܵ����֡�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"northwest" :  __DIR__"road9",
		"southeast" :  __DIR__"road7",
	]));
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("coor/x", -5090);
	set("coor/y", 1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
