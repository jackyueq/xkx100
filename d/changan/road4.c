//  Room:  /d/changan/road4.c

inherit  ROOM;

void  create  ()
{
	set("short",  "��ٵ�");
	set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�������ͨ�򺯹�
�أ�������ֱ�ﳤ���ǡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"      :  __DIR__"baqiao",
		"southeast" :  __DIR__"road3",
	]));
	set("outdoors", "guanzhong");
	set("no_clean_up", 0);
	set("coor/x", -4000);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
