//  Room:  /d/changan/road9.c

inherit  ROOM;

void  create  ()
{
	set("short",  "�ٵ�");
	set("long",  @LONG
һ����ʯ�̾͵Ĺٵ�����ͨ�����ݣ��������򵽴ﳤ������·��
����һƬï�ܵ����֡�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"     :  "/d/lanzhou/caoyuan1",
		"southeast" :  __DIR__"road8",
	]));
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("coor/x", -5100);
	set("coor/y", 1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
