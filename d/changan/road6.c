//  Room:  /d/changan/road6.c

inherit  ROOM;

void  create  ()
{
	set("short",  "��ٵ�");
	set("long",  @LONG
����һ����ʯ�̾͵Ŀ�����ֱ�Ĺٵ�������������·��������ݵ�
��ʮ���ۡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"     :  __DIR__"northgate",
	]));
	set("outdoors", "guanzhong");
	set("no_clean_up", 0);
	set("coor/x", -5040);
	set("coor/y", 1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
